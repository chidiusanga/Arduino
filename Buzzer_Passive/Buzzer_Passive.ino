// Project: Passive Buzzer
// Developer: Chidi Usanga
// Date: March 31, 2020

#include <pitches.h>

int buzzer = 8;           // Assign buzzer to pin 8.
int buzzFreq = 1;         // Set the frequency of the buzz (in ms);
int buzzFreqMicro = 405;    // Set the frequency of the buzz (in Microsec.)


void setup() {
  pinMode(buzzer, OUTPUT);  // Set the buzzer as an Output.

}

void loop() {
  digitalWrite(buzzer, HIGH);
  delayMicroseconds(buzzFreqMicro);
  digitalWrite(buzzer, LOW);
  delayMicroseconds(buzzFreqMicro);
}
