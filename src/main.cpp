#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>

const int LED = 13;
const int NUMPIXEL = (8*32);
uint counter = 0;

const char *SSID="venkman_kids";
const char *PWD="Th1sI$f0RK1dS!";

WebServer server(80);
Adafruit_NeoPixel pixels(NUMPIXEL, LED, NEO_GRB + NEO_KHZ800);
Adafruit_NeoMatrix matrix(32, 8, LED, NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG, NEO_GRB + NEO_KHZ800);

void handleMode()
{
  StaticJsonDocument<512> modeDoc;

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Starting up, connecting to WiFI...");

  WiFi.begin(SSID, PWD);

  
  while (WiFi.status() != WL_CONNECTED) {
    if (WiFi.status() == WL_CONNECT_FAILED)
    {
      Serial.println("Connect failed - terminating!");
      break;
    }

    Serial.print(".");
    delay(500);
    // we can even make the ESP32 to sleep
  }
  
 
  Serial.print("Connected. IP: ");
  Serial.println(WiFi.localIP());

  server.on("/mode", handleMode);

  //pinMode(LED, OUTPUT);
  pixels.begin();
  matrix.begin();  
}

void solidColorWarp()
{
  pixels.clear();
  pixels.setBrightness(32);

  for (int i=0; i < NUMPIXEL; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0,0,255));
    
    pixels.show();
    delay(50);
  }

  for (int i=NUMPIXEL-1; i >= 0; i--)
  {
    pixels.setPixelColor(i, pixels.Color(255,0,0));
    pixels.show();
  }

  delay(500);
}

void rainbowNotworking()
{
  int i = 0;
  
  // put your main code here, to run repeatedly:
  pixels.clear();

  delay(1000);

  pixels.setBrightness(32);

  for (int r=0; r < 256; r+=32)
  {
    for (int g=0; g < 256; g+=32)
    {
      for (int b=0; b < 256; b+=32)
      {
          if (i < NUMPIXEL)
          {
            pixels.setPixelColor(i++, pixels.Color(r,g,b));
            pixels.show();
            delay(50);
          }
            
      }
    }
  }

  //pixels.show();

  //delay(1000);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return matrix.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return matrix.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return matrix.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void anotherRainbow()
{
  int x = 0;
  int y = 0;

  matrix.fillScreen(matrix.Color(255,0,0));
  matrix.setBrightness(32);
  
  for (int r=0; r < 256; r++)
  {
    for(int x = 0; x < matrix.width(); x++) {
      for(int y = 0; y < matrix.height(); y++) {
        matrix.drawPixel(x, y, Wheel((((x+y) * 256 / (8*32) + r) & 255)));
      }
    }
    matrix.show();
    delay(3);
  }
}

void marquee()
{

  matrix.setTextWrap(false);
  matrix.setBrightness(32);
  matrix.setTextColor(matrix.Color(0,255,0));

  matrix.fillScreen(0);
  matrix.setCursor(0, 0);
  matrix.print("Hello!");

  matrix.show();
  delay(1000);
}

void loop() 
{
  anotherRainbow();
}