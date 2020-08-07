#include <IRremote.h>
int DigitalPin = 7;  // Input 핀 설정
IRrecv irrecv (DigitalPin);
decode_results results;
void setup ()
{
    Serial.begin (9600); //시리얼 모니터의 보드레이트 값과 동일하게 설정
    irrecv.enableIRIn (); 
}
void loop () {
    if (irrecv.decode (&results)) {
        Serial.println (results.value, HEX);
        irrecv.resume (); 
    }
}
