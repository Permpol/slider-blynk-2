#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int sensorValue = 0;        
int outputValue = 0;        
const int analogInPin = A0;
char auth[] = " vrUsz_PiEoHTQN3nfrY6gZI9jJBpXnis";
char ssid[] = "iPhone";
char pass[] = "12345678";
BLYNK_WRITE(V23) 
{ 
 if(outputValue = param.asInt()){
  digitalWrite(D4, HIGH);}
}



BLYNK_WRITE(V5)
{
  if(param.asInt() == 0)
  {
    digitalWrite(D4, HIGH);
  }
  if(param.asInt() == 1)
  {
    digitalWrite(D4, LOW);
  }
}

BLYNK_CONNECTED() {
  Blynk.syncAll();
}

void setup()
{
      pinMode(D4,OUTPUT);
  digitalWrite(D4, HIGH);
    Blynk.begin(auth, ssid, pass);
}

void loop()
{

  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023,100,0);
  Blynk.virtualWrite(V0,outputValue); 
  Blynk.run();
  
}