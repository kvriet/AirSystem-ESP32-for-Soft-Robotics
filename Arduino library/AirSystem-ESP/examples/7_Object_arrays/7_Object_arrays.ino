#include <AirSystem-ESP.h>

int motorPercentage = 0;

void setup() {
  Serial.begin(9600);
  AirSystem_begin();  // Initialise the pins
  for (int i = 0; i < 4; i++) {
    // Turn off all components
    motors[i].off();
  }
}

void loop() {
  motors[0].set(motorPercentage); // pump A
  motors[1].set(motorPercentage); // valve A

  motorPercentage++; // Add 1 to the motorPercentage variable

  if (motorPercentage > 100){
    motorPercentage = 0; // If motorPercentage becomes larger than 100, make it 0 again
  }

  delay(100);
}
