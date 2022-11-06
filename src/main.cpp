#include <Arduino.h>

uint8_t ENA = 15;
uint8_t IN1 = 13;
uint8_t IN2 = 12;

uint8_t ENB = 5;
uint8_t IN3 = 4;
uint8_t IN4 = 0;

long distanceTraveledToMsRatio = 1.0;
float distance = 0.0;

String currentStatusInfo();

void runProcedure();

void forward();

void stop();

void backward();

void left();

void right();

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

//function move, takes in a d in cm and direction
void move(long d, const String& direction) {
    //calculate the time to move the d
    long time = d * distanceTraveledToMsRatio;
    //move the d
    if (direction == "forward") {
        forward();
    } else if (direction == "backward") {
        backward();
    } else if (direction == "left") {
        left();
    } else if (direction == "right") {
        right();
    } else {
        Serial.println("Invalid direction");
    }
    //wait for the time
    delay(time);
    //stop the motors
    stop();
}

void right() {
    digitalWrite(ENA, HIGH);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(ENB, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void left() {
    digitalWrite(ENA, HIGH);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(ENB, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void backward() {
    digitalWrite(ENA, HIGH);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(ENB, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void stop() {
    digitalWrite(ENA, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(ENB, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void forward() {
    digitalWrite(ENA, HIGH);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(ENB, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void loop() {
// write your code here


}

//send forward signal to l298n module


//send backward signal to l298n module

//send left signal to l298n module

//send right signal to l298n module


//send stop signal to l298n module

