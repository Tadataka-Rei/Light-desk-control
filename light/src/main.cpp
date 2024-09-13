#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPmDNS.h>
#include <ESPAsyncWebServer.h>
#include <FastLED.h>
#include "Error_404.h"
#include "Error_405.h"
#include "index.h"
#include "control_panel.h"
#include "Setting.h"


#define DATA_PIN 5

int NUM_LEDS =55;

CRGB leds[55];

const char* PARAM_INPUT = "value";

String Brightness = "0";

const char* ssid = "Trung Hieu";
const char* password = "23011992";

AsyncWebServer server(80);

//Turn int to string
String intToStr(int N) {
    int i = 0;
    char *str;
    // Save the copy of the number for sign
    int sign = N;

    // Extract digits from the number and add to string
    while (N > 0) {
      
        // Convert integer digit to character and store in str
        str[i++] = N % 10 + '0';
          N /= 10;
    } 

    // Null-terminate the string
    str[i] = '\0';

    // Reverse the string to get the correct order
    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }
    return str;
}


//Process the placeholder 
String processor(const String& var){
  if(var == "LEDNUM")
    return "<h4>" + intToStr(NUM_LEDS) + "</h4>";
    
    if (var == "SLIDERVALUE"){
    return PARAM_INPUT;
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
    request->send(200, "text/html", index_html);
  });
    server.on("/index.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", index_html);
  });


//------ SETTING-----//
  server.on("/setting", HTTP_GET, [] (AsyncWebServerRequest *request) {
    // String inputMessage;
    //   if (request->hasParam(PARAM_INPUT)) {
    //     inputMessage = request->getParam(PARAM_INPUT)->value();
    //     Brightness = inputMessage;
    //   }

    //   Serial.println(inputMessage);
      request->send(200, "text/html", SETTING);
  });


  server.on("/ControlPanel.html", HTTP_GET, [] (AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", Control_panel_html, processor);
  });


  server.onNotFound([](AsyncWebServerRequest *request) {
    if (request->method() == HTTP_GET) {
      request->send(404, "text/html", HTML_CONTENT_404);
      Serial.println("not found");
    } else {
      request->send(405, "text/html", HTML_CONTENT_405);
    }
  });
  server.begin();
}

void loop() {

}
