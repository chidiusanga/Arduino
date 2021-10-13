// Project: Passive Buzzer with Tones
// Maker: Chidi Usanga
// Date: April 11, 2020

//In this project, we are building a device that sings Twinkle Twinkle Little Star, We Wish
//You a Merry Christmas and the Irish National Anthem.

#include <pitches.h>           // Include the Tones Library

// Twinkle Twinkle Little Star Notes
int twinkle[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, 0,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4, 0,
  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, 0,
  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, 0,
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, 0,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4, 0
};

// Twinkle Twinkle Little Star Durations
// Durations: 1 = Semibreve, 2 = Minim, 4 = Crotchet.
int twinkleDurations[] = {
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
};

// We Wish You a Merry Christmas Notes
int merry[] = {
  NOTE_G3, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_A3,
  NOTE_A3, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_B3, NOTE_G3,
  NOTE_G3, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_A3,
  NOTE_G3, NOTE_G3, NOTE_A3, NOTE_D4, NOTE_B3, NOTE_C4,
  NOTE_G3, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_A3,
  NOTE_A3, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_B3, NOTE_G3,
  NOTE_G3, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_A3,
  NOTE_G3, NOTE_G3, NOTE_A3, NOTE_D4, NOTE_B3, NOTE_C4,

  NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_B3, NOTE_B3, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_G3,
  NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_G3,
  NOTE_G3, NOTE_G3, NOTE_A3, NOTE_D4, NOTE_B3, NOTE_C4,
};

// We Wish You a Merry Christmas Durations
// Durations: 1 = Semibreve, 2 = Minim, 4 = Crotchet.
int merryDurations[] = {
  2, 2, 4, 4, 4, 4, 2, 2, 2, 2, 4, 4, 4, 4, 2, 2,
  2, 2, 4, 4, 4, 4, 2, 2, 4, 4, 2, 2, 2, 1,
  2, 2, 4, 4, 4, 4, 2, 2, 2, 2, 4, 4, 4, 4, 2, 2,
  2, 2, 4, 4, 4, 4, 2, 2, 4, 4, 2, 2, 2, 1,

  2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2,
  4, 4, 2, 2, 2, 1
};

// Irish National Anthem Notes
int anthem[] = {
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_F4, NOTE_C4, 0,
  NOTE_C4, NOTE_D4, NOTE_D4, NOTE_AS3, NOTE_D4, NOTE_C4, 0,
  NOTE_F4, NOTE_E4, NOTE_D4, 0,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_E4, 0,
  NOTE_F4, NOTE_G4, NOTE_A4, NOTE_F4, NOTE_C4, 0,
  NOTE_C4, NOTE_D4, NOTE_D4, NOTE_AS3, NOTE_D4, NOTE_C4, 0,
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4, 0, NOTE_C4,
  NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_G3, NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4,
  NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_G3, NOTE_C4,
  NOTE_A3, NOTE_F3, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4,
  NOTE_F4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4
  
};

// Irish National Anthem Durations
// // Durations: 1 = Semibreve, 1.3 = Dotted Semibreve, 2 = Minim, 4 = Crotchet.
float anthemDurations[] = {
  1.3, 4, 2, 2, 1, 2,
  2, 1.3, 4, 2, 2, 1, 1,
  1, 1, 1, 2, 4, 4, 1.3, 4, 2, 2, 1, 1,
  1.3, 4, 2, 2, 1, 2,
  2, 1.3, 4, 2, 2, 1, 1,
  1, 1, 2, 2, 1.3, 4, 1, 2, 2,
  1.3, 4, 4, 4, 4, 4, 1.3, 4, 2, 2,
  1.3, 4, 2, 2, 2, 2, 2, 2,
  2, 4, 4, 1.3, 4, 4, 4, 4, 4, 2, 4, 4, 4, 2, 4, 1.3, 4, 0.5,
};

// Global Variables

// Define the pins used for musical notes
const int LED_s1 = 13;       // LED for G3
const int LED_l1 = 12;       // LED for A3
const int LED_t1 = 11;       // LED for B3
const int LED_d = 10;        // LED for C4
const int LED_r = 9;         // LED for D4
const int LED_m = 6;         // LED for E4
const int LED_f = 5;         // LED for F4
const int LED_s = 4;         // LED for G4
const int LED_l = 3;         // LED for A4

const int potPin = 0;         // Input pin for potentiometer
int potVal = 0;               // Value of the potentiometer analog reading
const int soundPin = 8;       // Output pin for buzzer

int thisNote;                 // The current note playing at a particular time.

void setup()
{
  // Set each LED pin as an output
  pinMode(LED_s1, OUTPUT);
  pinMode(LED_l1, OUTPUT);
  pinMode(LED_t1, OUTPUT);
  pinMode(LED_d, OUTPUT);
  pinMode(LED_r, OUTPUT);
  pinMode(LED_m, OUTPUT);
  pinMode(LED_f, OUTPUT);
  pinMode(LED_s, OUTPUT);
  pinMode(LED_l, OUTPUT);
  pinMode(soundPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  if(Serial.available()){
      char val = Serial.read();

      if(val == '1'){
          playTwinkle();              // Call the playTwinkle function
        }

      if(val =='2'){
          playMerry();                // Call the playMerry function
        }

      if(val == '3'){
          playAnthem();               // Call the playAnthem function
        }
    }
  
}


void playTwinkle()
{
  potVal = analogRead(potPin);
  // Play each note in the twinkle array
 for (int thisNote = 0; thisNote < sizeof(twinkle)/2; thisNote++)
 {
   switch(twinkle[thisNote])          // Decide which note is playing in this iteration and turn on the appropriate LED for it.
   {
    case NOTE_C4:                     // If it's C4, turn on LED_d and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, HIGH);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;

    case NOTE_D4:                     // If it's D4, turn on LED_r and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, HIGH);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;

    case NOTE_E4:                     // If it's E4, turn on LED_m and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, HIGH);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;
      
    case NOTE_F4:                     // If it's F4, turn on LED_f and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, HIGH);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;

    case NOTE_G4:                     // If it's G4, turn on LED_s and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, HIGH);
      digitalWrite(LED_l, LOW);
      break;

     case NOTE_A4:                    // If it's A4, turn on LED_l and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, HIGH);
      break;
      default:
      break;
  }

    // Calculate the note duration by dividing the potentiometer's value by the note value.
    // I adapted this from 1000/2 (minim), 1000/4 (crotchet), 1000/8 (quaver), etc., given on Arduino website.
    // The 1000 stands for 1 second but I replaced the 1000 with potVal and replaced the
    // individual note values with their values in the "twinkleDurations" array above.
    int twinkleDuration = potVal / twinkleDurations[thisNote];
    tone(soundPin, twinkle[thisNote], twinkleDuration);

    // Set a minimum pause time between the notes to separate them from each other.
    int pauseBetweenNotesTwinkle = twinkleDuration * 1.2;
    delay(pauseBetweenNotesTwinkle);            // Delay the playing note by the min. pause time.
    noTone(soundPin);                           // Stop the note.

 // Debugging   
//    Serial.print("Melody Maximum: ");
//    Serial.println(sizeof(twinkleDurations));
//    Serial.print("Pot Value: ");
//    Serial.println(potVal);
  }
}


void playMerry()
{
  potVal = analogRead(potPin);
  // iterate over the notes of the melody:
 for (int thisNote = 0; thisNote < sizeof(merry)/2; thisNote++)  
 {
   switch(merry[thisNote])            // Decide which note is playing in this iteration and turn on the appropriate LED for it.
   {  
      case NOTE_G3:                   // If it's G3, turn on LED_s1 and turn the rest off.
      digitalWrite(LED_s1, HIGH);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;

      case NOTE_A3:                   // If it's A3, turn on LED_l1 and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, HIGH);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;
      
      case NOTE_B3:                   // If it's B3, turn on LED_t1 and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, HIGH);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;
    
    case NOTE_C4:                     // If it's G3, turn on LED_d and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, HIGH);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;

    case NOTE_D4:                     // If it's D4, turn on LED_r and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, HIGH);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;

    case NOTE_E4:                     // If it's E4, turn on LED_m and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, HIGH);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;
      
    case NOTE_F4:                     // If it's F4, turn on LED_f and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, HIGH);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;

    case NOTE_G4:                     // If it's G4, turn on LED_s and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, HIGH);
      digitalWrite(LED_l, LOW);
      break;

     case NOTE_A4:                    // If it's A4, turn on LED_l and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, HIGH);
      break;
      default:
      break;
  }

    // Calculate the note duration by dividing the potentiometer's value by the note value.
    // I adapted this from 1000/2 (minim), 1000/4 (crotchet), 1000/8 (quaver), etc., given on Arduino website.
    // The 1000 stands for 1 second but I replaced the 1000 with potVal (for speed control) and replaced the
    // individual note values with their values in the "merryDurations" array above.
    int merryDuration = potVal / merryDurations[thisNote];
    tone(soundPin, merry[thisNote], merryDuration);

    // Set a minimum pause time between the notes to separate them from each other.
    int pauseBetweenNotesMerry = merryDuration * 1.2;
    delay(pauseBetweenNotesMerry);        // Delay by the minimum pause time.
    noTone(soundPin);                     // Stop the note
    
// Debugging
//    Serial.print("Melody Maximum: ");
//    Serial.println(sizeof(merryDurations));
//    Serial.print("Pot Value: ");
//    Serial.println(potVal);
  }
}



void playAnthem()
{
  potVal = analogRead(potPin);
  // iterate over the notes of the melody:
 for (int thisNote = 0; thisNote < sizeof(anthem)/2; thisNote++)
 {
   switch(anthem[thisNote])               // Decide which note is playing in this iteration and turn on the appropriate LED for it.
   {  
      case NOTE_G3:                       // If it's G3, turn on LED_s1 and turn the rest off.
      digitalWrite(LED_s1, HIGH);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;

      case NOTE_A3:                       // If it's A3, turn on LED_l1 and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, HIGH);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;
      
      case NOTE_AS3:                      // If it's AS3, turn on LED_t1 and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, HIGH);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;
    
    case NOTE_C4:                         // If it's c4, turn on LED_d and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, HIGH);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;

    case NOTE_D4:                         // If it's D4, turn on LED_r and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, HIGH);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;

    case NOTE_E4:                         // If it's E4, turn on LED_m and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, HIGH);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;
      
    case NOTE_F4:                         // If it's F4, turn on LED_f and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, HIGH);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, LOW);
      break;

    case NOTE_G4:                         // If it's G4, turn on LED_s and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, HIGH);
      digitalWrite(LED_l, LOW);
      break;

     case NOTE_A4:                        // If it's A4, turn on LED_l and turn the rest off.
      digitalWrite(LED_s1, LOW);
      digitalWrite(LED_l1, LOW);
      digitalWrite(LED_t1, LOW);
      digitalWrite(LED_d, LOW);
      digitalWrite(LED_r, LOW);
      digitalWrite(LED_m, LOW);
      digitalWrite(LED_f, LOW);
      digitalWrite(LED_s, LOW);
      digitalWrite(LED_l, HIGH);
      break;
      default:
      break;
  }

    // Calculate the note duration by dividing the potentiometer's value by the note value.
    // I adapted this from 1000/2 (minim), 1000/4 (crotchet), 1000/8 (quaver), etc., given on Arduino website.
    // The 1000 stands for 1 second but I replaced the 1000 with potVal and replaced the
    // individual note values with their values in the "anthemDurations" array above.
    int anthemDuration = potVal / anthemDurations[thisNote];
    tone(soundPin, anthem[thisNote], anthemDuration);

    // Set a minimum pause time between the notes to separate them from each other.
    int pauseBetweenNotesAnthem = anthemDuration * 1.1;
    delay(pauseBetweenNotesAnthem);               // Delay the playing tone by the min pause time.
    noTone(soundPin);                             // Stop the playing tone.
    
//    Debugging
//    Serial.print("Melody Maximum: ");
//    Serial.println(sizeof(anthemDurations));
//    Serial.print("Pot Value: ");
//    Serial.println(potVal);
  }
}
