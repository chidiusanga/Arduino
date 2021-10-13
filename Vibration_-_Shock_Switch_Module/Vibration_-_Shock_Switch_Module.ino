// Project: RGB LED Changing Colors
// Developer: Chidi Usanga
// Date: March 31, 2020

int led = 13;                 //  Assign LED to pin 13.
int sensorPin = 3;            //  Assign Sensor's Signal to pin 3.
int sensorValue;              //  A name for Sensor's value.

// INITIALIZATION
void  setup()
{
pinMode(led,OUTPUT);          //  Designate led (pin 13) as an Output.
pinMode(sensorPin,INPUT);     //  Designate sensorPin (pin 3) as an Input.
Serial.begin(9600);           //  Start Serial Monitor at the baudrate of 9600 bits/s.
}

// RUNNING THE PROGRAM
void loop()

{
  sensorValue = digitalRead(sensorPin);//read the value of the digital interface 3 assigned to val 
  if(sensorValue==HIGH)//when the switch sensor have signal, LED blink
    {
    digitalWrite(led,HIGH);
    }
  else
    {
    digitalWrite(led,LOW);
    }
  Serial.println(sensorValue);
}
