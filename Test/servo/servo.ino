#include <Servo.h>

Servo rightServo;
Servo leftServo;
int pos = 0; // 영점
int leftButton = 2;
int rightButton = 7;


void setup() {
  leftServo.attach(12);
  rightServo.attach(9);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  leftServo.write(0);
  rightServo.write(0);
}

void loop() {
  if(digitalRead(leftButton) == HIGH){
    leftServo.write(90);
  }else{
    leftServo.write(0);
   }
   
  if(digitalRead(rightButton) == HIGH){
    rightServo.write(90);
  }else{
    rightServo.write(0);
   }
}
