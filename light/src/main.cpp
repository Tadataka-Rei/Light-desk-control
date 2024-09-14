#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPmDNS.h>
#include <ESPAsyncWebServer.h>
#include <FastLED.h>
#include "Error_404.h"
#include "Error_405.h"
#include "index.h"
#include "Setting.h"


#define DATA_PIN 5
#define MIN_LED 0

//IF YOU WANT TO CHANGE THE MAXIMUN LED then you have to change 2 70 bellow
#define MAX_LED "70"
CRGB leds[70];

int NUM_LEDS =0;
String POS[]= {"",""};

String Colors="#000000";
String Brightness = "0";

const char* ssid = "Trung Hieu";
const char* password = "23011992";

AsyncWebServer server(80);

//Turn int to string
String intToStr(int N) {
    int i = 0;
    char *str;
    int sign = N;

    // Extract digits from the number and add to string
    while (N > 0) {
        // Convert integer digit to character and store in str
        str[i++] = N % 10 + '0';
          N /= 10;
    } 

    str[i] = '\0';
    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }
    return str;
}


//---Process the placeholder--- //
String processor(const String& var){
  if(var == "LEDNUM")
  {
    return MAX_LED;
  }
  if(var == "Spos")
  {
    return POS[0];
  }

  if(var == "Epos")
  {
    return POS[1];
  }
    if (var == "BRIGHTVALUE"){
    return Brightness;
  }

  if (var == "COLORS")
  {
    return "#"+Colors;
  }
  return String();
}

void setup(){
  Serial.begin(115200);

  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);


  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }
  
  if(!MDNS.begin("lightcontrol"))
  {
   Serial.print("Error setting up MDNS responder!"); 
  }

  // Route for root
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });
    server.on("/index.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html,processor);
  });


//------ SETTING-----//
  server.on("/setting", HTTP_GET, [] (AsyncWebServerRequest *request) {
      request->send_P(200, "text/html", SETTING, processor);
  });


// -----------LOGIC------------//
//BRIGHTNESS
  server.on("/ChangeBright", HTTP_GET, [] (AsyncWebServerRequest *request) {
      if (request->hasParam("value")) {
        Brightness =  request->getParam("value")->value();
      }

      request->send(200, "text/plain", Brightness);
  });
//COLOR
    server.on("/changecolor", HTTP_GET, [] (AsyncWebServerRequest *request) {
      if (request->hasParam("color")) {
        Colors = request->getParam("color")->value();
        Serial.print("Have color and is:");
        Serial.print(Colors);
      }

      request->send(200, "text/plain", Colors);
  });
//POS

   server.on("/changepos", HTTP_GET, [] (AsyncWebServerRequest *request) {
        int paramsNr = request->params();

    for (int i = 0; i < paramsNr; i++)
    {
      AsyncWebParameter* p = request->getParam(i);
      if(i<2)
      POS[i] = p->value();

    }

    request->send(200, "text/plain", "message received");

  });


//--------- ERROR----------//
  server.onNotFound([](AsyncWebServerRequest *request) {
    if (request->method() == HTTP_GET) {
      request->send(404, "text/html", HTML_CONTENT_404);
    } else {
      request->send(405, "text/html", HTML_CONTENT_405);
    }
  });


  server.begin();
}

void loop() {

}
