#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <Servo.h>
Servo myServo;

//LCD constants
int ServoState;

//servo constants
int const potPin = A0;
int potVal;
int angle;
int OldAngle = 0;

void setup() {
  
lcd.begin(16,2);
  
  myServo.attach(9);
Serial.begin(9600);

}

void loop() {
  
potVal = analogRead(potPin);
Serial.print("potVal: ");
Serial.print(potVal);

angle = map(potVal, 0, 1023, 1, 177);
Serial.print(", angle: ");
Serial.print(angle);

myServo.write(angle);
delay(15);

if (angle != OldAngle) {

OldAngle = angle;
ServoState = map(potVal, 0, 1023, 0, 100);
Serial.print(", ServoState: ");
Serial.println(ServoState);

lcd.clear();
lcd.setCursor(0,0);
if (ServoState == 0){
  lcd.print("Baffle closed");
}
else{
    if (ServoState == 100){
      lcd.print("Baffle open");
}
else{
lcd.print("Baffle ");
lcd.print(ServoState);
lcd.setCursor(9, 0);
lcd.print("% open");
  }
}
}
}

