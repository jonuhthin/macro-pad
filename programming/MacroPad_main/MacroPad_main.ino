//Display Stuff
//#include <SPI.h>
//#include <Wire.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>

//Rotary Encoder Stuff
#include <SimpleRotary.h>
#include <HID-Project.h>
#include <HID-Settings.h>
#define SW 7
#define DT 6
#define CLK 8

//Key Stuff
#define K1 2
#define K2 3
#define K3 4
#define K4 5

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
//#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
//#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SimpleRotary rotary(CLK, DT, SW);

int ctr = 0;
byte lastDir = 0;
unsigned long prevTime = 0;

void setup(){
//  Serial.begin(9600);
//    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
//  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
//    Serial.println(F("SSD1306 allocation failed"));
//    for(;;); // Don't proceed, loop forever
//  }
//  display.setRotation(2);
//  display.display();
//  delay(2000);
//  display.clearDisplay();
//  display.drawPixel(10, 10, SSD1306_WHITE);
//  display.display();
//  delay(2000);
  
  Consumer.begin();
  delay(1000);
  
  pinMode(SW, INPUT_PULLUP);
  pinMode(DT, INPUT);
  pinMode(CLK, INPUT);
  
  pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  pinMode(K4, INPUT_PULLUP);
//
//  bitClear(DDRD,5);
//  bitClear(DDRB,0);

  
}

void loop(){
//  display.setTextSize(2);             // Normal 1:1 pixel scale
//  display.setTextColor(SSD1306_WHITE);        // Draw white text
//  display.setCursor(0,0);             // Start at top-left corner
      
  int rDir = rotary.rotate();
  int rBtn = rotary.push();
  int rLBtn = rotary.pushLong(1000);

  if (digitalRead(K1) == 0){
    Consumer.write(MEDIA_VOLUME_MUTE);
    delay(500);
    //display.println(F("Mute"));
    //refreshDisplay();
  }


// MUTE MIC
  if (digitalRead(K2) == 0){
    Keyboard.write(KEY_ESC);
    delay(500);
  }
  
// 
  if (digitalRead(K3) == 0){
    Keyboard.write('f');
    delay(500);
  }

// Play/P ause media
  if (digitalRead(K4) == 0){
    Consumer.write(MEDIA_PLAY_PAUSE);
    delay(100);
  }


  // Check direction
  if ( rDir == 1  ) {
      // CW
      ctr++;
      Consumer.write(MEDIA_VOLUME_UP);
      
      //display.println(F("Volume +"));,, //refreshDisplay();
      lastDir = rDir;
  }
  if ( rDir == 2 ) {
      // CCW
      ctr--;
      Consumer.write(MEDIA_VOLUME_DOWN);
      
      //display.println(F("Volume -"));
      //refreshDisplay();
      lastDir = rDir;
  }


  if ( rLBtn == 1 ) {
    System.write(SYSTEM_SLEEP);
  }

  
  // Only Serial.print when there is user input.
  // Constant serial printing without delay can introduce lag where rotary encoder rotation pulses can be missed.
  if ( rDir == 1 || rDir == 2 || rBtn == 1 || rLBtn == 1 ){
    Serial.print("Counter = ");
    Serial.print(ctr);
    Serial.println();
  }
}


//void refreshDisplay(){
//  unsigned long currentTime = millis();
//  display.display();
//  if (currentTime - prevTime >= 50){
//    display.clearDisplay();
//    prevTime = currentTime;
//  }
//}
