#ifndef DIAWAN_H
#define DIAWAN_H
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>


class Parameter {
  public:
    Parameter();
    Parameter(char* name, float value, float offsite);
    Parameter(char* name, float offsite);
    char* getName() const;
    float getValue() const; 
    float getMin() const;
    float getMax() const; 
    void setVar(char* name, float offsite, float correction);
    void setValue(float value);
    float getOffsite() const; 
    void setOffsite(float offsite);
    void setMin(float min);
    void setMax(float max);
    
     float getCorrection() const; 
    char* _name ; 
    float _value ;
    float _offsite ; 
    float _min ; 
    float _max ; 
    float _correction ; 
      
};

void geturlDiawanTrial(String idDevice, String *link,String *name, float *offsite1, float *koreksi1);
void geturlDiawan(String idDevice, String *link,String *name, Parameter **parameter);
void connectDiawanWifi( String link, String email, String pass, String userId, String idDevice,int wifi, String *name,int *restart ,int *reset, Parameter **parameter);
void connectDiawan( String link, String email, String pass, String userId, String idDevice, String *name,int *restart ,int *reset, Parameter **parameter);
void connectDiawanTrial( String link, String email, String pass, String userId, String idDevice,float tempC, String *name, float *offsite1,int *restart ,int *reset );
#endif