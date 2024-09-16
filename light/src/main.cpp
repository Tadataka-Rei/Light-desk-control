#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPmDNS.h>
#include <ESPAsyncWebServer.h>
#include <FastLED.h>
#include "Error_404.h"
#include "Error_405.h"
#include "index.h"
#include "Setting.h"


#define DATA_PIN 5 //change the data pin as you like
#define MIN_LED 0

//IF YOU WANT TO CHANGE THE MAXIMUN LED then you have to change 2 55 bellow
#define MAX_LED 55
CRGB leds[55];

int NUM_LEDS =0;
String POS[]= {"",""};

String Colors="#000000";
int red=255, green=255, blue=255;
String Brightness = "0";

const char* ssid = "REPLACE_WITH_YOURS";
const char* password = "REPLACE_WITH_YOURS";

AsyncWebServer server(80);



//---Process the placeholder--- //
String processor(const String& var){
  if(var == "LEDNUM")
  {
    return String(MAX_LED);
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

//     -------------- LOGIC FUNCTONS ----   ///////
void decode_color(String hexCode)
{
    for (int i = 0; i < 6; i += 2) {
        char highNibble = toupper(hexCode[i]);
        char lowNibble = toupper(hexCode[i + 1]);

        // Convert hexadecimal characters to decimal values
        int value = (highNibble >= 'A' ? highNibble - 'A' + 10 : highNibble - '0') * 16 +
                   (lowNibble >= 'A' ? lowNibble - 'A' + 10 : lowNibble - '0');
        if (i == 0) {
            red = value;
        } else if (i == 2) {
            green = value;
        }
            blue = value;
    }
}


void Static_color()
{
  fill_solid(leds,MAX_LED, CRGB(green,red,blue));

  FastLED.show();
}
// ---------SETUP-------//
void setup(){
  Serial.begin(115200);
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, MAX_LED);


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
        decode_color(Colors);
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
