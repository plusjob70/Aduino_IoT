int cdsPin = A0;

void setup() 
{
      Serial.begin(9600);
}
  
void loop() 
{
      Serial.println(analogRead(cdsPin)); 
      
      delay(1000);
}
