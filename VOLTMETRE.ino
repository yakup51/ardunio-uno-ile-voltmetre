#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0; // 100K ohm direnç
float R2 = 10000.0; // 10K ohm direnç
int value = 0;
void setup(){
   pinMode(analogInput, INPUT);
   lcd.begin(16, 2);
   lcd.print("DC VOLTMETRE-YAKUPTURKAN");
}
void loop(){
   
   value = analogRead(analogInput);
   vout = (value * 5.0) / 1024.0; 
   vin = vout / (R2/(R1+R2)); 
   if (vin<0.09) {
   vin=0.0;
} 
lcd.setCursor(0, 1);
lcd.print("VOLTAJ V= ");
lcd.print(vin);
delay(500);
} 
