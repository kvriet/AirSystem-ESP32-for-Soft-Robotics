// The code below turns the pump on and off.

// - Try to change the delay values. How does the pump turning on and off change? 
// - Try to change the value in the set() function. How does it change the pump behaviour? 
// - If you connect the pump to your pneumatic button, will it only inflate? Or also deflate?

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
  pumpA.set(50);
  Serial.println("Pump set to 50% intensity");

  delay(2000);

  pumpA.off();
  Serial.println("Pump turned off");

  delay(2000);
}
