
// Project: RGB LED Changing Colors
// Developer: Chidi Usanga
// Date: March 31, 2020

//#include <pitches.h>

int buzzer = 8;
int potPin = A0;
int potVal;
int toneVal;

int redLED = 10;
int yellowLED = 11;
int greenLED = 12;
int blueLED = 13;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
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

  if(potVal < 10)
  {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);  
  }

   if(potVal >= 10 && potVal <= 99)
  {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);  
  }

   if(potVal >= 100 && potVal <=499)
  {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);  
  }
   if(potVal >= 500)
  {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, HIGH);  
  }
}
