

#include <GyverOLED.h>

GyverOLED<SSH1106_128x64> oled;
  const int analogInPin = A1;  
const int analogInPin1 = A0;
const int analogInPin2 = A2;
int sensorFwd = 0;       
int  sensorRew = 1;
float Ufwd ;
float Urew ;
float (SWR);
float (PFWD);
float (PREV);
float (PWR);
float (Utap);

void setup() { 
   pinMode(analogInPin, INPUT);
   pinMode(analogInPin1, INPUT);
  
   oled.init();
}

void loop() { 
// read the analog in value:
  sensorFwd = analogRead(analogInPin);
  sensorRew = analogRead(analogInPin1);
  Utap = analogRead(analogInPin2);
  Utap=(Utap*15/1024);
  if (sensorFwd<1){(sensorFwd=1);
 } ;
  if (sensorRew<1){(sensorRew=1);
 } ;
 Ufwd=(sensorFwd/12+1) ;
  Urew=(sensorRew/12) ; 
 PWR=0;
  PFWD=sq(Ufwd)/ 50; 
 PREV=sq(Urew)/ 50 ; 
  SWR = (1+sqrt(PREV/PFWD)) / (1-sqrt(PREV/PFWD));
  PWR=PFWD;
 if (PFWD<1) {(PWR=0.000);
 } ;
 if (PFWD<50  && PFWD>6) {  ;
  (PWR=PWR*1.2) ;
 };
 if (PFWD<6  && PFWD>1) {  ;
  (PWR=PWR*1.4) ;
 };
  //oled.init();
  oled.update(); 
  oled.setContrast(0);
  oled.setCursor(0, 0);  
  oled.setScale(2);
  oled.print("SWR:");
  oled.print(SWR);
  oled.update();
  oled.setScale(2);
  oled.setCursorXY(0, 18);
  oled.print("PWR:");
  oled.print(PWR);
  oled.setCursorXY(0, 36);
  oled.setScale(2);
   oled.print("UIn:");
   oled.print (Utap);
   oled.setScale(0);
   oled.setCursorXY(0,56 );
   oled.setScale(0);
   oled.print(" made by HA7AT");
  PWR=0;
  oled.update();
  delay (800) ;
  oled.clear(); 
  
}
