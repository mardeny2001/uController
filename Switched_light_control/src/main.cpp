#include <Arduino.h>

#define light 13
#define sw_in 3

bool sw_mode=LOW;

// put function declarations here:
void sw_isr();
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sw_in,INPUT);
  pinMode(light,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(3),sw_isr,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}

// put function definitions here:
void sw_isr(){
  sw_mode=!sw_mode;
  digitalWrite(light,sw_mode);
  Serial.println(sw_mode);
}
