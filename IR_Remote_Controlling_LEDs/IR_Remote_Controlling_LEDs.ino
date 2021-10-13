#include<IRremote.h>
#define RECV_PIN 7    // Pin receiving the IR signal


#define button1_ON 1
#define button1_OFF 2049
#define button2_ON 2
#define button2_OFF 2050
#define button3_ON 3
#define button3_OFF 2051
#define button4_ON 4
#define button4_OFF 2052
#define buttonOK_ON 53
#define buttonOK_OFF 2101

#define buttonPlay_ON 50
#define buttonPlay_OFF 2098
#define buttonReleaseTime 100

IRrecv irrecv(RECV_PIN);
decode_results results;

// Define pins used
const int LED1 = 10;
const int LED2 = 11;
const int LED3 = 12;
const int LED4 = 13;
int togglestate = 0;
int pinsCount=4;                        // declaring the integer variable pinsCount
int pins[] = {10,11,12,13};          // declaring the array pins[]
int potPin = A0;
int potValue;
int whatLED = 0;
boolean direction = false;
int speed = 0;
int downcount = 0;  // for my timer function checkTime() to do non-blocked timing

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  irrecv.enableIRIn();    // Turn on IR Receiver
  Serial.begin(9600);
  for (int i=0; i<pinsCount; i=i+1)
  {    // counting the variable i from 0 to 9
    pinMode(pins[i], OUTPUT);            // initialising the pin at index i of the array of pins as OUTPUT
    pinMode(potPin, INPUT);
  }
}

void loop() {
  static unsigned long previousTime = 0;
  if(irrecv.decode(&results)){
  Serial.println(results.value);
  irrecv.resume();
  unsigned long code = results.value;

  /* TURN ON AND OFF INDIVIDUAL LEDS*/

        if(code == button1_ON || code == button1_OFF)
        {
            if(togglestate == 0)
            {
              digitalWrite(LED1, HIGH);
              togglestate = 1;
            }
           else
             {
              digitalWrite(LED1, LOW);
              togglestate = 0;
             }
        }

        else if(code == button2_ON || code == button2_OFF)
        {
            if(togglestate == 0)
            {
              digitalWrite(LED2, HIGH);
              togglestate = 1;
            }
           else
             {
              digitalWrite(LED2, LOW);
              togglestate = 0;
             }
        }

        else if(code == button3_ON || code == button3_OFF)
        {
            if(togglestate == 0)
            {
              digitalWrite(LED3, HIGH);
              togglestate = 1;
            }
           else
           {
            digitalWrite(LED3, LOW);
            togglestate = 0;
           }
        }

         else if(code == button4_ON || code == button4_OFF)
            {
            if(togglestate == 0)
              {
              digitalWrite(LED4, HIGH);
              togglestate = 1;
              }
           else
             {
              digitalWrite(LED4, LOW);
              togglestate = 0;
             }
        }
        
        else if(code == buttonOK_ON || code == buttonOK_OFF)
        {
            // Continuously update last on time while button is held
            previousTime = millis();

        potValue = analogRead(potPin);
        for (int i=pinsCount-1; i>0; i--)
          {   // chasing left (except the outer leds)
            digitalWrite(pins[i], HIGH);         // switching the LED at index i on
            delay(potValue);                          // stopping the program for 100 milliseconds
            digitalWrite(pins[i], LOW);          // switching the LED at index i off
          }
      for (int i=0; i<pinsCount; i++)
          {    // chasing right
            digitalWrite(pins[i], HIGH);         // switching the LED at index i on
            delay(potValue);                          // stopping the program for 100 milliseconds
            digitalWrite(pins[i], LOW);          // switching the LED at index i off
          }  
        }

        else if(code == buttonPlay_ON || code == buttonPlay_OFF)
        {
          digitalWrite(LED1, HIGH);
          digitalWrite(LED2, HIGH);
          digitalWrite(LED3, HIGH);
          digitalWrite(LED4, HIGH);
          delay(potValue);

          digitalWrite(LED1, LOW);
          digitalWrite(LED2, LOW);
          digitalWrite(LED3, LOW);
          digitalWrite(LED4, LOW);
          delay(potValue);


          Serial.print("Pot Value: ");
          Serial.println(potValue);
          
        }
      }    
  }
