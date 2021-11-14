#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int relay = 12;
int state = 2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  pinMode(state,INPUT);
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Hello");
  display.display();
  delay(2000);
}
void loop() {
  if(digitalRead(2) == HIGH)
  {
    digitalWrite(relay, HIGH);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.cp437(true);
    display.write("Switch ON");
    delay(100);
    display.display();
    delay(100);
  }
  if(digitalRead(2) == LOW)
  {
    digitalWrite(relay, LOW);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.cp437(true);
    display.write("Switch ON");
    delay(100);
    display.display();
    delay(100);
  }
}
