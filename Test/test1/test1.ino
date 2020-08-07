#include <IRremote.h>
#include <Servo.h>
#include <SoftwareSerial.h> 

SoftwareSerial BTSerial(4, 5); // 소프트웨어 시리얼 (TX,RX) 
Servo servo1;
Servo servo2;
int DigitalPin = 7;
IRrecv irrecv(DigitalPin);
decode_results results;

void setup(){
Serial.begin(9600);
irrecv.enableIRIn();
Serial.println("Hello!");
BTSerial.begin(9600);
servo1.attach(11);
servo2.attach(12);
servo1.write(0);
servo2.write(0);
}
 
void loop(){
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
  if(BTSerial.available()){ 
    char data;
    data = BTSerial.read();
    Serial.write(data);
    int charToInt = data - '0';
    servo2.write(charToInt);
  }

  if(irrecv.decode(&results)){
    Serial.print("Code      : 0x");
    Serial.print(results.value, HEX);
    Serial.println("");
    
    switch(results.value){
        case 0x33848A00:            //5
            servo1.write(0);  
            break;
        case 0x33848600:            //6
            servo1.write(10);
            break;
        case 0x33848E00:            //7
            servo1.write(20);
            break;
        case 0x33848100:            //8
            servo1.write(30);  
            break;
        case 0x33848900:            //9
            servo1.write(40);
            break;
        case 0x33848080:            //10
            servo1.write(50);
            break;
        case 0x33848880:            //11
            servo1.write(60);  
            break;
        case 0x33848480:            //12
            servo1.write(70);
            break;
        case 0x33848C80:            //13
            servo1.write(80);
            break;
        case 0x33848280:            //14
            servo1.write(90);  
            break;
        case 0x33848A80:            //15
            servo1.write(100);
            break;
        case 0x33848680:            //16
            servo1.write(110);
            break;
        case 0x33848E80:            //17
            servo1.write(120);  
            break;
        case 0x33848180:            //18
            servo1.write(130);
            break;
        case 0x33848980:            //19
            servo1.write(140);
            break;
        case 0x33848040:            //20
            servo1.write(150);  
            break;
        case 0x33848840:            //21
            servo1.write(160);
            break;
        case 0x33848440:            //22
            servo1.write(170);
            break;
        case 0x33848C40:            //23
            servo1.write(180);  
            break;

    }
    irrecv.resume();
  }
 
}
