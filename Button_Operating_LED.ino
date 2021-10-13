int ledPin = 13;
int buttonPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if(buttonState == 0) {
    digitalWrite(ledPin, HIGH);
    } else {
    digitalWrite(ledPin, LOW);  
    }
}
