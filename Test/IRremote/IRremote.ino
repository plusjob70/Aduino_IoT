#include <IRremote.h>
int input_pin = 4;
IRrecv irrecv(input_pin); 
decode_results signals;
 
void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn();
}
 
void loop() {
if (irrecv.decode(&signals)) {
        Serial.println(signals.value, HEX);       
        Serial.println(signals.bits, DEC);
        irrecv.resume();
    }
    
}
