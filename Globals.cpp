#include "Globals.h"

float tempsensada1;
float tempsensada2;

const char* ssid = "THESSID";
const char* password = "THEPASSWORD";

OneWire oneWire(ONE_WIRE_BUS);
OneWire oneWire2(ONE_WIRE_BUS2);
DallasTemperature sensors(&oneWire);
DallasTemperature sensors2(&oneWire2);

Tempo t_temp(1*1000); // 1 sec between reads
Tempo tempo_wifi_retry(30*1000);
ESP8266WebServer server(80);