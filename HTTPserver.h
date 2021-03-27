#ifndef H_HTTPSERVER
#define H_HTTPSERVER
    #include <Arduino.h>

    void initHTTPserver();
    void handleNotFound();
    void handleRoot();
    void handleTemperaturesResponse();
#endif