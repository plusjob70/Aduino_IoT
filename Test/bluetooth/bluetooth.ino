#include <Servo.h>
#include <SoftwareSerial.h> 

SoftwareSerial BTSerial(4, 5); // 소프트웨어 시리얼 (TX,RX) 
Servo servo;

void setup(){
Serial.begin(9600);
Serial.println("Hello!");
BTSerial.begin(9600);
servo.attach(11);
servo.write(90);
}
 
void loop(){
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
  if(BTSerial.available()){ 
    char data;
    data = BTSerial.read();
    Serial.write(data);
    if(data == 'a'){
      servo.write(130);
      delay(500);
      servo.write(90);
      }
    else if(data == 'b'){
      servo.write(50);
      delay(500);
      servo.write(90);
      }
  }  
 
}
