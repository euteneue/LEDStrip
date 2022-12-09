#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <WiFi.h>
#include <WebServer.h>

int LED = 13;
uint counter = 0;

const char *SSID="venkman_kids";
const char *PWD="Th1sI$f0RK1dS!";

//WebServer server(80);

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

  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(counter++);
  digitalWrite(LED, ((counter++) % 2) ? HIGH : LOW);
  delay(1000);
}