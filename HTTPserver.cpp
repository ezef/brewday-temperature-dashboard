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

  char temp_1_char[10];
  dtostrf(tempsensada1, 4, 3, temp_1_char);

  char temp_2_char[10];
  dtostrf(tempsensada2, 4, 3, temp_2_char);

  response.replace("{{temperature1}}", (char *) temp_1_char);
  response.replace("{{temperature2}}", (char *) temp_2_char);

  server.send(200, "text/html", response);
}