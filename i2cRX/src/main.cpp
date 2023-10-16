#include <Arduino.h>
#include <Wire.h>
// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(8,6);
  while(Wire.available()){
    char x=Wire.read();
    Serial.println(x);
  }
  delay(500);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}