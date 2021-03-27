#ifndef H_GLOBALS
    #define H_GLOBALS

    #include <Arduino.h>
    #include <tempo.h>
    #include <ESP8266WiFi.h>
    #include <ESP8266HTTPClient.h>
    #include <ESP8266WebServer.h>
    #include <OneWire.h>
    #include <DallasTemperature.h>

    #define ONE_WIRE_BUS 14
    #define ONE_WIRE_BUS2 2 // TBD

    // #define TEMPERATURE_PRECISION 9
    // #define HISTERESIS 0.3

    extern const char* ssid;
    extern const char* password;

    extern float tempsensada1;
    extern float tempsensada2;

    extern OneWire oneWire;
    extern OneWire oneWire2;
    extern DallasTemperature sensors;
    extern DallasTemperature sensors2;

    extern Tempo t_temp; // temporizador para la lectura de temperatura
    extern Tempo tempo_wifi_retry; // resilient connection retry to WIFI each minute
    // extern Tempo tempo_step_change; 
    extern ESP8266WebServer server;
#endif