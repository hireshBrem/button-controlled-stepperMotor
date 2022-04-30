#include <Stepper.h>

int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
int motorSpeed = 15;
int dt = 100;
int buttonVal;
int buttonPin = 2;
bool clockwise;

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motorSpeed);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop() {
  buttonVal = digitalRead(buttonPin);
  delay(dt);
  Serial.println(buttonVal);
  
  if(buttonVal == 1 && clockwise==true){
    myStepper.step(stepsPerRevolution/50);
  }
  if(buttonVal == 1 && clockwise==false){
    myStepper.step(-stepsPerRevolution/50);
  }
  
  if(buttonVal == 0){
    if(clockwise==true){
      clockwise=false;
    }
    else{
      clockwise=true;
    }
  }


} 
