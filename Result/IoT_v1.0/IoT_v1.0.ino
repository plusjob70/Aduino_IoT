#include <Servo.h>
#include <SoftwareSerial.h> 
#include <IRremote.h>

SoftwareSerial BTSerial(4, 5); // 소프트웨어 시리얼 (TX,RX) 
Servo servo;
IRsend irsend;

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
    if(data == 'a'){  // 전원 ON
      servo.write(130);
      delay(500);
      servo.write(90);
      }
    else if(data == 'b'){ // 전원 OFF
      servo.write(50);
      delay(500);
      servo.write(90);
      }
    else if (data == '1'){ // 운전 / 정지
      for(int i = 0; i<3; i++){
        irsend.sendLG(0x8166817E, 32); 
        delay(40); 
      }
    }
    else if (data == '2') { // 운전 선택
      for(int i = 0; i<3; i++){
        irsend.sendLG(0x8166D926, 32); 
        delay(40); 
      }
    }
    else if (data == '3') { // 온도 낮춤
      for(int i = 0; i<3; i++){
        irsend.sendLG(0x816651AE, 32); 
        delay(40); 
      } 
  }  
    else if (data == '4') { // 온도 높힘
       for(int i = 0; i<3; i++){
        irsend.sendLG(0x8166A15E, 32); 
        delay(40); 
      } 
    }
  }
 
}
