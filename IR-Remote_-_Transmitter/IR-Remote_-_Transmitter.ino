// Project: RGB LED Changing Colors
// Developer: Chidi Usanga
// Date: March 2, 2020

//An IR LED must be connected to Arduino PWM pin 3.
  #include<IRremote.h>
  IRsend irsend;
  
  void setup()
  {}
  
 void loop() 
 {
  irsend.sendRC5(0x0, 8); //send 0x0 code (8 bits)
     delay(200);
  irsend.sendRC5(0x1, 8); 
     delay(200); 
  }
