#include <LiquidCrystal.h>

#include<Servo.h>

const int trigPin = 19;
const int echoPin = 18;

Servo myServo;

long duration;
int distance;
int delayTime(15);

int position = 0;

LiquidCrystal lcd(12, 10, 5, 4, 3, 2);  // Define the pins used in LCD
int i = 0;              // Loop variables
int j = 0;
int k = 0;
int delayTime2 = 350;   // Delay time for LCD

String firstline;       // LCD's First Line
String secondline;      // LCD's Second line


// Function for Right to Left Scrolling
void scrollInFromRight (int line, char str1[]) {
  i = strlen(str1);
  for (j = 16; j >= 0; j--) {
    lcd.setCursor(0, line);
    for ( k = 0; k <= 15; k++) {
      lcd.print ("");
    }
    lcd.setCursor (j, line);
    lcd.print(str1);
    delay(delayTime2);
  }
}

// Function for Left to Right Scrolling
void scrollInFromLeft (int line, char str1[]) {
  i = 40 - strlen(str1);
  line = line - 1;
  for (j = i; j <= i + 16; j++) {
    for (k = 0; k <= 15; k++) {
      lcd.print("");
    }
    lcd.setCursor(j, line);
    lcd.print(str1);
    delay(delayTime2);
  }
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(9);
  // put your setup code here, to run once:
  Serial.begin(9600);
  
   // Initialization
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);


delay(10);

  unsigned long startTime = millis(); // takes the time before the loop on the library begins
//  int dis = SharpIR.getDistance(); // this returns the distance to the object you're measuring


  unsigned long calcTime = millis() - startTime; // the following gives you the time taken to get the measurement
  //Serial.print("Time taken (ms): ");
  //Serial.println(calcTime);
  
  distance = duration*0.034/2;
  if(distance < 40){
     // put your main code here, to run repeatedly:
    myServo.write(90);
    delay(delayTime);
    digitalWrite(trigPin, LOW);
    delay(5000);
    
    lcd.clear();
    scrollInFromRight(0, "Thanks 4 Saving ");
    scrollInFromRight(1, "the Environment.");
    delay(1000);
    lcd.clear();
    
  }else{
    myServo.write(0);
    delay(delayTime);
    }
  
 

}
