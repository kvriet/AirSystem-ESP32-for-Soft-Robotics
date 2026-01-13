/*
   AirSystem Demo Sketch
   ---------------------

   Author:  C.M. van Riet
   Library: AirSystem-ESP
   Date:    January 2026

  Objects can be called in 2 ways:
     - pumpA, valveB, sensorA (named)
     - M1, M2, M3, M4 (named)
     - pumps[0], valves[1], sensors[0] (array-based)

   Functions available in this library:
     - Initialize the system with AirSystem_begin()
     - Control pumps with .set(percentage), on(), and .off()
     - Control valves with .open() and .close()
     - Read pressure from sensors with .read()

   Hardware:
   - Designed for a maximum of 4 pumps or 4 valves, and 2 sensors
   - Pin mappings are fixed in the library (see AirSystem-ESP.h)

   Notes:
   - Make sure to include the AirSystem-ESP.h library at the top of your sketch (#include <AirSystem-ESP.h>)
   - This example can be found under File > Examples > AirSystem-ESP > 1_First_demo.
*/

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
  // This loop is empty
  // You can turn the pump and valve on by pressing
  // the buttons on the Air System board
}
