#include <Servo.h>
#include <SoftwareSerial.h> 
#include <IRremote.h>
#include <DHT11.h>

SoftwareSerial BTSerial(4, 5); // 소프트웨어 시리얼 (TX,RX) 
Servo servo;
IRsend irsend;
int cdsPin = A0;    // 조도센서 핀
int servoPin = 11;  // 서보모터 핀
int dhtPin = 12;    // 온습도센서 핀
DHT11 dht11(dhtPin);
int pos = 90;       // 서보모터 영점

void setup(){
    BTSerial.begin(9600);
    servo.attach(servoPin);
    servo.write(pos);
}

void autoAcFunc(){
    float humi, temp;
    dht11.read(humi, temp);
    if(temp < 25.00 || temp > 28.50 && humi > 75.00){
        irsend.sendLG(0x8166817E, 32);
      }
}

void loop(){
  if(BTSerial.available()){ 
    char data;
    data = BTSerial.read();
    switch(data){
        case 'l':               // 전등 스위치 ON|OFF
            int cdsValue = map(analogRead(cdsPin), 0, 1024, 0, 100);
            if(cdsValue <= 25){ // 스위치 ON
              servo.write(127);
              delay(400);
              servo.write(pos);
              }
            else{               // 스위치 OFF
              servo.write(50);
              delay(400);
              servo.write(pos);              
              }
            break;
        case 'o':               // 에어컨 운전/정지
            irsend.sendLG(0x8166817E, 32);
            break;
        case 'm':               // 에어컨 제습모드
            irsend.sendLG(0x8166D926, 32);
            break;
        case 'h':               // 에어컨 온도 높힘
            irsend.sendLG(0x8166A15E, 32);
            break;
        case 'c':               // 에어컨 온도 낮춤
            irsend.sendLG(0x816651AE, 32);
            break;

    }
  }
  else{autoAcFunc();}
 
}
