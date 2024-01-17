#include <SoftwareSerial.h>
#include <Servo.h>
#define BT_RXD 5
#define BT_TXD 4
SoftwareSerial bluetooth(BT_RXD, BT_TXD);
char rec_data;
bool rec_chk = false;
int FAN = 11;

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel RGB_LED = Adafruit_NeoPixel(3, 6, NEO_GRB);
int rand1, rand2, rand3 = 0;

Servo servo;

void setup() {
  bluetooth.begin(9600);                          // 스마트폰 블루투스 통신속도

  servo.attach(13);
  pinMode(FAN,OUTPUT);
  RGB_LED.begin();
  RGB_LED.setBrightness(100);                    //RGB_LED 밝기조절
  RGB_LED.clear();
}
void loop() {
  if (bluetooth.available()) {                   // 블루투스 명령 수신
    rec_data = bluetooth.read();
    rec_chk = true;
  }
  if (rec_data == 'm') { 
    servo.write(90);
  }
  if (rec_data == 'n') { 
    servo.write(180);
  }
  if (rec_data == 'p') { 
    analogWrite(FAN, 255);
  }
  if (rec_data == 'q') { 
    analogWrite(FAN, 0);
  }
  if (rec_data == 'r') {
    RGB_Color(RGB_LED.Color(255,0,0),10);
  }
  if (rec_data == 'o') { 
    RGB_Color(RGB_LED.Color(255,140,0),10);
  }
  if (rec_data == 'b') { 
    RGB_Color(RGB_LED.Color(0,102,255),10);
  }
  if (rec_data == 'y') { 
    RGB_Color(RGB_LED.Color(255,255,0),10);
  }
  if (rec_data == 'g') { 
    RGB_Color(RGB_LED.Color(0,255,0),10);
  }
  if (rec_data == 'v') { 
    RGB_Color(RGB_LED.Color(102,51,255),10);
  }
  if (rec_data == 'w') { 
    RGB_Color(RGB_LED.Color(255,255,255),10);
  }
  if (rec_data == 'x') { 
    RGB_Color(RGB_LED.Color(0,0,0),10);
  }
}

void RGB_Color(float c, int wait) {                
  for (int i = 0; i < RGB_LED.numPixels(); i++) 
  {  
     RGB_LED.setPixelColor(i, c);
     RGB_LED.show();
     delay(wait);
  }
}
