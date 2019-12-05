#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int sensorValue = 0;  //ตัวแปรค่า Analog      
int outputValue = 0;   // ตัวแปรสำหรับ Map เพื่อคิด %      
const int analogInPin = A0;
char auth[] = " vrUsz_PiEoHTQN3nfrY6gZI9jJBpXnis";
char ssid[] = "iPhone";
char pass[] = "12345678";
int t_slider = 0;
int Value_slider;
int led = D0;
BLYNK_WRITE(V1){ //ควบคุมความชื้น 

t_slider = param.asInt();
 Blynk.virtualWrite(V7,t_slider); 
 delay(100);

}
 


BLYNK_WRITE(V5)// ตั้งเวลาติดปัญหาควบคุมหลอดเดียวกับหลอดเซ็นเซอร์ไม่ได้
{
  if(param.asInt() == 0)
  {
    digitalWrite(led, HIGH); // เปิด
   
  }
  if(param.asInt() == 1)
  {
    digitalWrite(led, LOW); //ปิด
  
  }
}

BLYNK_CONNECTED() {
  Blynk.syncAll();
}

void setup()
{
pinMode(led,OUTPUT);
Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023,100,0); //คิดเป็นเปอร์เซ็น
  Blynk.virtualWrite(V0,outputValue); 
  
if(outputValue >= t_slider ){ //ถ้าค่าที่อ่านได้จาก เซ็นเซอร์ มากกว่าหรือเท่ากับ slider ให้ D4 ทำงาน

digitalWrite(led, HIGH);
 Serial.print('ON');
 
 }else{
     
digitalWrite(led,LOW);
Serial.print('OFF');

 }
  
  
}