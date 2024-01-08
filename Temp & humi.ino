#include <dht.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (A0,A1,A2,A3,A4,A5);// rs , e ,d4, d5 ,d6, d7)
dht DHT;

#define DHT11_PIN 8

byte customchar[8] = {
  0b00110,
  0b01001,
  0b01001,
  0b00110,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.createChar(0, customchar);
  lcd.setCursor(1,0);
  lcd.print("Temp and Humi");
  lcd.setCursor(4,1);
  lcd.print("Monitor");
  delay(2000);
}


void loop(){
  float chk = DHT.read11(DHT11_PIN);
  float t =  DHT.temperature;
  float h =  DHT.humidity;

  String tdata = "Temp : " + String(t) + " C ";
  String hdata = "Humi : " + String(h) + " % ";

   Serial.println(tdata);
   Serial.println(hdata);

  lcd.setCursor(0, 0);
  lcd.print(tdata);
  lcd.setCursor(12, 0);
  lcd.write(int(0));
  lcd.setCursor(0, 1);
  lcd.print(hdata);
  delay(500);
}
  
  
 
