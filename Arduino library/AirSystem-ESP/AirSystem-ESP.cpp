#include "AirSystem-ESP.h"

// ------------------- Pump -------------------
void Pump::begin(int pumpPin) {
  pin = pumpPin;
  pinMode(pin, OUTPUT);
  off();
}

void Pump::set(float percentage) {
  percentage = constrain(percentage, 0, 100);
  analogWrite(pin, map((int)percentage, 0, 100, 0, 255));
}

void Pump::on() {
  analogWrite(pin, 255);
}

void Pump::off() {
  analogWrite(pin, 0);
}

// ------------------- Valve -------------------
void Valve::begin(int valvePin) {
  pin = valvePin;
  pinMode(pin, OUTPUT);
  close();
}

void Valve::open() {
  analogWrite(pin, 255);
}

void Valve::close() {
  analogWrite(pin, 0);
}

// ------------------- Sensor -------------------
void Sensor::begin(int sensorPin) {
  pin = sensorPin;
  pinMode(pin, INPUT);
}

float Sensor::read() {
  return 0.05459 * analogRead(pin) - 10; // kPa
}

// ------------------- Motor -------------------
void Motor::begin(int motorPin) {
  pin = motorPin;
  pinMode(pin, OUTPUT);
  off();
}

void Motor::set(float percentage) {
  percentage = constrain(percentage, 0, 100);
  analogWrite(pin, map((int)percentage, 0, 100, 0, 255));
}

void Motor::on() {
  analogWrite(pin, 255);
}

void Motor::off() {
  analogWrite(pin, 0);
}

// ------------------- Named object definitions -------------------
Pump pumpA;
Pump pumpB;

Valve valveA;
Valve valveB;

Sensor sensorA;
Sensor sensorB;

// ---- Named motor object definitions ---- //
Motor M1;
Motor M2;
Motor M3;
Motor M4;

// ---- Motor array (references to named objects) ---- //
MotorArray motors(M1, M2, M3, M4);

// ------------------- Init function -------------------
void AirSystem_begin() {
  int pumpPins[]   = PUMP_PINS;
  int valvePins[]  = VALVE_PINS;
  int sensorPins[] = SENSOR_PINS;
  int motorPins[]  = MOTOR_PINS;

  pumpA.begin(pumpPins[0]);
  pumpB.begin(pumpPins[1]);

  valveA.begin(valvePins[0]);
  valveB.begin(valvePins[1]);

  sensorA.begin(sensorPins[0]);
  sensorB.begin(sensorPins[1]);

  M1.begin(motorPins[0]);
  M2.begin(motorPins[1]);
  M3.begin(motorPins[2]);
  M4.begin(motorPins[3]);
}
