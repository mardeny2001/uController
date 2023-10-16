#include <Arduino.h>
#define onboard_blink 13
// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  pinMode(onboard_blink,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(onboard_blink,HIGH);
  delay(500);
  Serial.println("led is high!");
  digitalWrite(onboard_blink,LOW);
  Serial.println("led is low!");
  delay(500);
}

// put function definitions here:
