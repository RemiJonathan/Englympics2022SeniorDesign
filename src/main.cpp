#include <Arduino.h>
#include <ESP8266WiFi.h>

String ssid = "Rémi Jonathan’s iPhone";
String password = "ubuntuthecat";

void setup() {
// write your initialization code here
//connect ESP8266 to Wi-Fi
    Serial.begin(115200);
    Serial.println("Connecting to WiFi");
    WiFi.begin(ssid, password);
//wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
//if connection fails, stop program
        if (WiFi.status() == WL_CONNECT_FAILED) {
            Serial.println("Connection failed");
            break;
        }
    }
    Serial.println("Connected to the WiFi network");

}

void loop() {
// write your code here
}