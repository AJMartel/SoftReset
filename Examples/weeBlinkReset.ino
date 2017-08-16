/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.

  Added as example to SoftReset.Todo: cleanup + tidy up readme, etc.
 */

#include <SoftReset.h>

int inc = 10;

void setup() {

  wdt_init();	// Must call this first to disable WDT

  // initialize the digital pin as an output.
  // Pin PORTD2 has an LED connected on most Arduino boards:
  pinMode(PORTD2, OUTPUT);     
  /*
    This is a weird comment
  //*/

  Serial.begin(57600);

  Serial.println("reboot + setup ok, going to coutdown loop");

}

void loop() {
  digitalWrite(PORTD2, HIGH);   // set the LED on
  delay(500);              // wait for a second
  digitalWrite(PORTD2, LOW);    // set the LED off
  delay(500);              // wait for a second

  Serial.print("Hello... ready to reboot in ");
  Serial.println(inc);

  if (inc == 0)
  {
    Serial.println("Ready reboot now! Press any key to reboot!");	//This message displays

    while (!Serial.available());

    Serial.println("Key press detected, rebooting now!");		//This message does bot display completely

    soft_restart();

    Serial.println("Oooopps! something went wrong, this message should never display!");
  }

  inc--;
}
