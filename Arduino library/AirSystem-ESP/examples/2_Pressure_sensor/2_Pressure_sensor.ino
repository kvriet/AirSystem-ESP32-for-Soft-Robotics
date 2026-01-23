// To get the pressure sensor value, use the read() function.

// Upload the following code. 
// Use the push buttons to inflate and deflate your pneumatic button 
// and use the Serial Monitor and Serial Plotter to watch the pressure value fluctuate.

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
  float pressure = sensorA.read();
  Serial.print(0);     // Lower limit in Serial Plotter
  Serial.print("\t");  // Print a tab
  Serial.print(200);   // Upper limit in Serial Plotter
  Serial.print("\t");  // Print a tab
  Serial.println(pressure);

  delay(10);
}
