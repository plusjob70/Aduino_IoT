int cdsPin = A0;

void setup() 
{
    Serial.begin(9600);
}
  
void loop() 
{
    int cdsValue =analogRead(cdsPin); 
    cdsValue = map(cdsValue , 0, 1024, 0,100);
    
    Serial.print("cdsValue :");
    Serial.print(cdsValue);
    Serial.println("%");
    
    delay(1000);
}

