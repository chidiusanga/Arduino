
const int trigPin = 19;  // Define Pin 9 as the Trigger
const int echoPin = 18;  // Define Pin 8 as the Echo

long duration;          // Variable to hold the duration of the rays
int dis;                // Variable to hold Distance

#include <LiquidCrystal.h>

#define ir A1
#define model 1080


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
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialization
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Initializing.");
  delay(1000);
  lcd.clear();
  lcd.print("Initializing..");
  delay(1000);
  lcd.clear();
  lcd.print("Initializing...");
  delay(1000);
  lcd.clear();
  lcd.print("By Chidi Usanga");
  delay(2000);
  lcd.clear();
}


void loop() {

// US Emmissions and Calculations
  digitalWrite(trigPin, LOW);     // Turn off Trigger
  delayMicroseconds(2);           // Delay 2 Microseconds

  digitalWrite(trigPin, HIGH);    // Emit Trigger
  delayMicroseconds(10);          // Delay 10 Microseconds
  digitalWrite(trigPin, LOW);     // Turn it off.

  duration = pulseIn(echoPin, HIGH);  // Receive signal from Echo and assign it to variable duration
  dis = duration*0.034/2;             // Multiply the signal by half the speed of light.

  Serial.print("Distance: ");         // Print the values to screen.
  Serial.println(dis);
  
 
 // DISPLAY MESSAGES IF THE SENSOR VALUE IS LESS THAN 40cm

  delay(10);

  unsigned long startTime = millis(); // takes the time before the loop on the library begins
//  int dis = SharpIR.getDistance(); // this returns the distance to the object you're measuring


  Serial.print("Mean distance: ");  // returns it to the serial monitor
  Serial.println(dis);

  unsigned long calcTime = millis() - startTime; // the following gives you the time taken to get the measurement
  //Serial.print("Time taken (ms): ");
  //Serial.println(calcTime);

  if(dis < 40) {
    lcd.clear();
  scrollInFromRight(0, "Covid-19 Citizens");
  scrollInFromRight(1, "Information Desk");
  delay(1000);
  lcd.clear();
  }

  dis = duration*0.034/2;
//  dis = SharpIR.getDistance();
  if(dis < 40) {
  lcd.clear();
  scrollInFromRight(0, "The best way to ");
  scrollInFromRight(1, "avoid contracting");
  delay(1000);
  lcd.clear();
  }

  dis = duration*0.034/2;
//  dis = SharpIR.getDistance();
  if(dis < 40) {
  lcd.clear();
  scrollInFromRight(0, "Coronavirus is  ");
  scrollInFromRight(1, "to stay at home ");
  delay(1000);
  lcd.clear();
  }

  dis = duration*0.034/2;
//  dis = SharpIR.getDistance();
  if(dis < 40) {
  lcd.clear();
  scrollInFromRight(0, "and wash your 2 ");
  scrollInFromRight(1, "hands frequently.");
  delay(1000);
  lcd.clear();
  }

  dis = duration*0.034/2;
//  dis = SharpIR.getDistance();
  if(dis < 40) {
  scrollInFromRight(0, "Social Distance- ");
  scrollInFromRight(1, "very important. ");
  delay(1000);
  lcd.clear();
  }
  
  dis = duration*0.034/2;
//  dis = SharpIR.getDistance();
  if(dis < 40) {
  scrollInFromRight(0, "Be wise, people.");
  scrollInFromRight(1, "Stay alive!!");
  delay(1000);
  lcd.clear();
  }
  
}
