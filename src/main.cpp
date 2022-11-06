#include <Arduino.h>

uint8_t ENA = 15;
uint8_t IN1 = 13;
uint8_t IN2 = 12;

uint8_t ENB = 5;
uint8_t IN3 = 4;
uint8_t IN4 = 0;


String currentStatusInfo();

void runProcedure();

void setup() {
// write your initialization code here
//Using ESP8266
    double counter = 0;
    Serial.println("Waiting for 5 seconds");

//while waiting for 5 seconds, log the wait time in microseconds
    do {
        //print the number of microseconds since the program started
        Serial.println(micros());
        delay(100);
        counter++;
    } while (counter < 50);

    //run procedure
    Serial.println("Starting procedure");
    //runProcedure();
}

void runProcedure() {

}

void loop() {
// write your code here


}

//send forward signal to l298n module
void forward() {
    digitalWrite(ENA, HIGH);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(ENB, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

//send backward signal to l298n module
void backward() {
    digitalWrite(ENA, HIGH);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(ENB, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

//send left signal to l298n module
void left() {
    digitalWrite(ENA, HIGH);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(ENB, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

//send right signal to l298n module
void right() {
    digitalWrite(ENA, HIGH);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(ENB, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

//send stop signal to l298n module
void stop() {
    digitalWrite(ENA, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(ENB, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

