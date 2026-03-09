/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
uint8_t counter = 0;
uint8_t progress[16];

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  // lcd.write(0xFF);
  // lcd.write(0xA6);
  //lcd.write(0xA7); // ア
  // lcd.write(0xA8); // イ
  // lcd.print("_-XO|hello, world!");

  lcd.write(0xCA); // ハ
  lcd.write(0xDB); // ロ
  lcd.write(0xB0); // ー
  
  lcd.write(' ');
  
  lcd.write(0xDC); // ワ
  lcd.write(0xB0); // ー
  lcd.write(0xD9); // ル
  lcd.write(0xC4); // ド

  lcd.setCursor(0, 1);

  for(int i=0; i<16; i++){
    progress[i] = ' ';
  }
  
  for(int i=0; i<counter; i++){
    progress[i] = 0xFF;
  }

  for(int i=0; i<16; i++){
    lcd.write(progress[i]);
  }

  counter = (counter + 1) % 17;
  delay(100);
}
