const int redPin = 7;
const int greenPin = 6;
const int bluePin = 5;

enum States{
  RG, GB, BR
};

struct Color{
  int redValue;
  int greenValue;
  int blueValue;
  States state;

  Color(States p_st): redValue(0), greenValue(0), blueValue(0), state(p_st)
  {
    switch(state) {
      case RG: redValue = 255;break;
      case GB: greenValue = 255;break;
      case BR: blueValue = 255;break;
    }
  }

  void step() {
    switch(state) {
      case RG:
        if(greenValue >= 254) state = GB;
        redValue--;
        greenValue++; break;
      case GB:
        if(blueValue >= 254) state = BR;
        greenValue--;
        blueValue++; break;
      case BR:
        if(redValue >= 254) state = RG;
        blueValue--;
        redValue++; break;
    }
  }
};

Color color(RG);

void setup() {
  Serial.begin(9600);

  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  analogWrite(redPin, color.redValue);
  analogWrite(greenPin, color.greenValue);
  analogWrite(bluePin, color.blueValue);
  color.step();
  Serial.print("red: ");
  Serial.print(color.redValue);
  Serial.print(" green: ");
  Serial.print(color.greenValue);
  Serial.print(" blue: ");
  Serial.print(color.blueValue);
  Serial.print('\n');
  delay(10);
}