#include <AirSystem-ESP.h>

void setup() {
  Serial.begin(9600);
  AirSystem_begin();  // Initialise the pins
  M1.off();      // Component 1 off
  M2.off();      // Component 2 off
  M3.off();      // Component 3 off
  M4.off();      // Component 4 off
}

void loop() {
  // Set component 3 to 25% (this is pump B) and component 4 to 10% (this is valve B)
  M3.set(25);
  M4.set(10);   // Notice that at 10%, valve B does not open!
  delay(1000);

  // Set component 3 to 0% and component 4 to 50%
  M3.set(0);
  M4.set(50);   // Notice that at 50%, valve B does open!
  delay(1000);

  float pressure = sensorA.read();  // Calling sensors remains unaffected
  Serial.println(pressure);
}
