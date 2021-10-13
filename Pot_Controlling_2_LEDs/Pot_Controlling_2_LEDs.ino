// ASSIGN GLOBAL VARIABLES
int redLEDPin = 10;     // Assign pin 13 to Red LED.
int yellowLEDPin = 11;  // Assign pin 12 to Yellow LED.
int delayOn = 500;      // Hold On for half a second.
int delayOff = 500;     // Hold Off for half a second.

int potPin = A0;        // Assign Analog 0 pin to Potentiometer's signal pin.
int potValue = 0;       // Assign 0 as initial value of Potentiometer's signal.

// START AND ONE-TIME FUNCTIONS
void setup(){
  pinMode(redLEDPin, OUTPUT);     // Declare the mode of Red LED's pin as Output.
  pinMode(yellowLEDPin, OUTPUT);  // Declare the mode of Yellow LED's pin also as Output.
  Serial.begin(9600);             // Start Serial communication with computer at the baud rate of 9600Hz.
}

// START THE REPEATING FUNCTIONS
void loop(){

    potValue = analogRead(potPin);// Read the signal value of Pot and assign it to potValue.
    
    if(potValue < 500) {
    digitalWrite(redLEDPin, HIGH); // If potentiometer's signal is less than 500, turn Red LED On.
    delay(potValue);               // Then hold it On for the length read from Pot's signal pin.
    digitalWrite(redLEDPin, LOW);  // Then, the Red LED Off.
    delay(potValue);               // And holt it Off for the length read from Pot's signal pin.
    
    } else {
    digitalWrite(yellowLEDPin, HIGH); // Otherwise, (if potentiometer's signal is NOT less than 500, turn Yellow LED On.
    delay(delayOn);                   // Then hold it On for half a second (500 milliseconds).
    digitalWrite(yellowLEDPin, LOW);  // Then, the Yellow LED Off.
    delay(delayOff);                  // And holt it Off for half a second (500 milliseconds).
    }
    Serial.println(potValue);         // Print the Potentiometer's value to the computer screen one line at a time.
   }
