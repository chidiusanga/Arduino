
// Project: RGB LED Changing Colors
// Developer: Chidi Usanga
// Date: March 31, 2020

//#include <pitches.h>

int buzzer = 8;
int potPin = A0;
int potVal;
int toneVal;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  potVal = analogRead(potPin);
  toneVal = (9400./1023.)*potVal+60;

  digitalWrite(buzzer, HIGH);
  delayMicroseconds(toneVal);
  digitalWrite(buzzer, LOW);
  delayMicroseconds(toneVal);
  Serial.println(potVal);
}
