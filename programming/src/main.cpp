

#include "Arduino.h"
#include "HID.h"
// screen
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// rotary encoder
#include <RotaryEncoder.h>
RotaryEncoder encoder(5, 6, RotaryEncoder::LatchMode::TWO03);

// hid input
#include <HID-Project.h>
#include <HID-Settings.h>

// matrix keypad
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 6;
// define the cymbols on the buttons of the keypad
KeyboardKeycode hexaKeys[ROWS][COLS] = {
    {KEY_LEFT_ALT, KEY_COPY, KEY_7, KEY_4, KEY_1, KEY_LEFT_WINDOWS},
    {KEY_TAB, KEY_F11, KEY_8, KEY_5, KEY_2, KEY_0},
    {KEY_LEFT_CTRL, KEY_F, KEY_9, KEY_6, KEY_3, KEY_PERIOD},
    {KEY_LEFT_WINDOWS, KEY_DELETE, KEYPAD_PLUS_MINUS, KEY_MINUS, KEY_SLASH, KEY_ENTER}};

// char hexaKeys[COLS][ROWS] = {
//   {'0','1','2','3'},
//   {'4','5','6','7'},
//   {'8','9','C','D'},
//   {'E','F','G','H'},
//   {'I','J','K','L'},
//   {'M','N','O','P'}
// };

byte colPins[COLS] = {A10, 16, 14, 15, 18, 19}; // connect to the row pinouts of the keypad
byte rowPins[ROWS] = {7, 8, 9, 20};             // connect to the column pinouts of the keypad

// initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

#define SW 4

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET 4        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int ctr = 50;
int lastPos = -1;
unsigned long prevTime = 0;
unsigned long prevTimeHeld = 0;

void refreshDisplay()
{
  unsigned long currentTime = millis();
  display.display();
  if (currentTime - prevTime >= 50)
  {
    display.clearDisplay();
    prevTime = currentTime;
  }
}

String msg;
bool keyPressed = false;

void setup()
{
  Serial.begin(9600);
  pinMode(TXLED0, INPUT);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  display.setRotation(3);
  display.clearDisplay();
  display.display();

  Consumer.begin();
  NKROKeyboard.begin();
  pinMode(SW, INPUT_PULLUP);

  msg = "";
}

void updateVolumeBar(bool up)
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
  display.println(up ? "+" : "-");
  display.display();
}

void printKeys(Key key[])
{

  Serial.print("[");
  for (int i = 0; i < LIST_MAX; i++)
  {
    Serial.print(key[i].kstate);
    if (i < LIST_MAX - 1)
    {
      Serial.print(", ");
    }
  }
  Serial.println("]");
}

void loop()
{

  // clear display every 2 seconds
  if (millis() - prevTime > 2000)
  {
    display.clearDisplay();
    display.display();
    prevTime = millis();
  }

  if (millis() - prevTimeHeld > 10 && keyPressed)
  {
    // Serial.print("holding: [");
    // for (int i = 0; i < heldLength; i++)
    // {
    // Serial.print(held[i]);
    // Serial.print(", ");
    // Keyboard.write(held[i]);
    // }4445
    // Serial.println("]");
    NKROKeyboard.send();
    keyPressed = false;
    prevTimeHeld = millis();
  }

  encoder.tick();
  int newPos = encoder.getPosition();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  // Check direction
  if (newPos > lastPos)
  {
    // CW
    if (ctr < 100)
    {
      ctr++;
    }

    Consumer.write(MEDIA_VOLUME_UP);
    updateVolumeBar(true);
  }
  if (newPos < lastPos)
  {
    // CCW

    if (ctr > 0)
    {
      ctr--;
    }
    Consumer.write(MEDIA_VOLUME_DOWN);
    updateVolumeBar(false);
  }

  if (digitalRead(SW) == 0)
  {
    Serial.println("pressed rbtn");
    System.write(SYSTEM_SLEEP);
  }

  if (customKeypad.getKeys())
  {
    printKeys(customKeypad.key);
    for (int i = 0; i < LIST_MAX; i++) // Scan the whole key list.
    {
      int idx = customKeypad.key[i].kcode;
      int r = idx / COLS;
      int c = idx % COLS;
      KeyboardKeycode key = hexaKeys[r][c];
      if (customKeypad.key[i].kstate == HOLD)
      {
        Serial.println(key);
      }
      if (customKeypad.key[i].stateChanged) // Only find keys that have changed state.
      {

        switch (customKeypad.key[i].kstate)
        { // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
        case PRESSED:
        {
          msg = " PRESSED.";
          NKROKeyboard.add(key);
          keyPressed = true;
          display.clearDisplay();
          display.print("i: ");
          display.println(idx);
          display.println();

          display.print("r: ");
          display.println(r);
          display.println();

          display.print("c: ");
          display.println(c);
          display.println();

          display.print("k: ");
          display.println();

          display.println(key);
          display.println();
          refreshDisplay();
          break;
        }
        case HOLD:
        {
          msg = " HOLD.";
          NKROKeyboard.add(key);
          keyPressed = true;
          break;
        }
        case RELEASED:
        {
          msg = " RELEASED.";
          NKROKeyboard.release(key);
          break;
        }
        case IDLE:
        {
          msg = " IDLE.";
        }
        }
      }
    }
  }

  // Only Serial.print when there is user input.
  // Constant serial printing without delay can introduce lag where rotary encoder rotation pulses can be missed.
  if (lastPos != newPos)
  {
    refreshDisplay();
    lastPos = newPos;
  }
}
