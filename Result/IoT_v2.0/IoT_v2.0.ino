#include <Servo.h>
#include <SoftwareSerial.h> 
#include <IRremote.h>

SoftwareSerial BTSerial(4, 5); // 소프트웨어 시리얼 (TX,RX) 
Servo servo;
IRsend irsend;
int pos = 90;   // 서보모터 영점

void setup(){
    BTSerial.begin(9600);
    servo.attach(11);
    servo.write(pos);
}
 
void loop(){
  if(BTSerial.available()){ 
    char data;
    data = BTSerial.read();
    switch(data){
        case 'a':               // 전등 스위치 ON
            servo.write(127);
            delay(400);
            servo.write(pos);
            break;
        case 'b':               // 전등 스위치 OFF
            servo.write(50);
            delay(400);
            servo.write(pos);
            break;
        case '1':               // 에어컨 운전/정지
            irsend.sendLG(0x8166817E, 32);
            delay(40);
            break;
        case '2':               // 에어컨 제습모드
            irsend.sendLG(0x8166D926, 32);
            delay(40);
            break;
        case '3':               // 에어컨 온도 높힘
            irsend.sendLG(0x8166A15E, 32);
            delay(40);
            break;
        case '4':               // 에어컨 온도 낮춤
            irsend.sendLG(0x816651AE, 32);
            delay(40);
            break;

    }
  }
 
}
