#include <IRremote.h>
IRsend irsend;
void setup ()
{
  irsend.sendSony(0x90,12);
  //Serial.begin (9600);
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop () {
  for (int i = 0; i < 100 ; i++) {
    irsend.sendSony(0xa90, 12); // Sony TV power code
    digitalWrite(LED_BUILTIN, HIGH);
    delay (1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay (1000);
  }
}
