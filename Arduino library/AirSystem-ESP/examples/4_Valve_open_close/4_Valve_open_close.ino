// The code below is similar to the code in step 3, but it adds valve control. 
// Now you can inflate and deflate your pouch.

// - Play with the pump power percentage and the timing (delay) 
// to get an aesthetically pleasing inflation and deflation of your pouch.

#include <AirSystem-ESP.h>

void setup() {
  Serial.begin(9600);
  AirSystem_begin();  // Initialise the pins
  pumpA.off();        // Pump off
  valveA.close();     // Close valve
  pumpB.off();        // Pump off
  valveB.close();     // Close valve
}

void loop() {
  valveA.close();
  pumpA.set(25);
  Serial.println("Valve closed and pump set to 25%");

  delay(1000);

  valveA.open();
  pumpA.off();
  Serial.println("Valve opened and pump off");

  delay(2000);
}
