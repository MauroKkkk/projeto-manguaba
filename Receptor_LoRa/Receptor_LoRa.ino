#include <WiFi.h>
#include <HTTPClient.h>
#include "Arduino.h"


#define RX_LoRa   16                                                          // Vai no TXD do módulo
#define TX_LoRa    4                                                         // Vai no RXD do módulo


short int httpResponseCode;
const char* ssid = "ifal-adm";
const char* password =  "ifal-adm";
String url;
String httpRequestData,payload;




void Conectar(){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("IP: " + (String)WiFi.localIP());  
};
void setup() {
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);

  Serial2.begin(9600, SERIAL_8N1, RX_LoRa, TX_LoRa);
  Serial.begin(9600);
  digitalWrite(26,LOW);
  digitalWrite(27,LOW);
  Conectar();
}
void Enviar(String number){
  HTTPClient http;
  http.addHeader("Content-Type", "text/plain");
  url = "http://192.168.7.226/Enviar?Dado="+number;//IP NodeJS
  http.begin(url.c_str());
  httpResponseCode = http.POST("");
  delay(300);
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}




void loop() {
  if(Serial2.available()>0){
    String input = Serial2.readString();
    Serial.println(input);
    Enviar(input);  
    } 

}
