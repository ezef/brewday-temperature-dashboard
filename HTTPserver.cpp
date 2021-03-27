#include <Arduino.h>
#include "Globals.h"
#include "HTTPserver.h"
#include "HTML.h"
#include "TemperatureControlFunctions.h"

void initHTTPserver(){
  server.on("/", handleRoot);
  server.on("/get-temperatures", handleTemperaturesResponse);
  server.on("/bootstrap.min.css", bootstrap);
  server.on("bootstrap.min.css", bootstrap);

  server.onNotFound(handleNotFound);
  server.begin();
}

void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void handleRoot(){
  server.send(200, "text/html", indexHTML());
}

void handleTemperaturesResponse(){
  String response = R"=====(
  {
    "temperature1":{{temperature1}},
    "temperature2":{{temperature2}},
  }
)=====";
  response.replace("{{temperature1}}", "123");
  response.replace("{{temperature2}}", "434");

  server.send(200, "text/html", response);
}