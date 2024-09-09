#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPmDNS.h>
#include <ESPAsyncWebServer.h>
#include <FastLED.h>
#include "Error_404.h"
#include "Error_405.h"
#include "index.h"
#include "login.h"
#include "control_panel.h"
#include "Setting.h"

#define NUM_LEDS 55

#define DATA_PIN 5

CRGB leds[NUM_LEDS];

const char* PARAM_INPUT = "value";

String Brightness = "0";

const char* ssid = "Change_this_to_your_ssid";
const char* password = "Change_this_to_your_ss_password";

AsyncWebServer server(80);
int myFunction(int, int);


String btos(bool x) 
{ 
    if (x) 
        return "True"; 
    return "False"; 
} 

String processor(const String& var){
  if(var == "PLACEHOLDER")
    return "<h4><tr><th>esp1</th><th>no ida</th><th>" +btos(1)+ "</th></tr></h4>";
  else return "";

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
  
  if(!MDNS.begin("smarttrash"))
  {
   Serial.print("Error setting up MDNS responder!"); 
  }
  // Print ESP Local IP
  Serial.println(WiFi.localIP());

  // Route for root
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", index_html);
  });
    server.on("/index.html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", index_html);
  });

  // Send a GET request to <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
  server.on("/login.html", HTTP_GET, [] (AsyncWebServerRequest *request) {
    request->send(200, "text/html", login_html);

  });

  server.on("/setting", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
        // GET input1 value on <ESP_IP>/slider?value=<inputMessage>
      if (request->hasParam(PARAM_INPUT)) {
        inputMessage = request->getParam(PARAM_INPUT)->value();
        Brightness = inputMessage;
      }
      else {
        inputMessage = "No message sent";
      }
      Serial.println(inputMessage);
      request->send(200, "text/plain", "OK");
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
