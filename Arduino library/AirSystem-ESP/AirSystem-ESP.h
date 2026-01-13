#ifndef AIRSYSTEM_ESP_H
#define AIRSYSTEM_ESP_H

#include <Arduino.h>

#define CHANNEL_COUNT 2

#define PUMP_PINS    {6, 8}
#define VALVE_PINS   {7, 9}
#define SENSOR_PINS  {0, 1}
#define MOTOR_PINS   {6, 7, 8, 9}

#define LED_BUILTIN 10

// ---- Pump ---- //
class Pump {
  int pin;
public:
  Pump() {}
  void begin(int pumpPin);
  void set(float percentage);
  void on();
  void off();
};

// ---- Valve ---- //
class Valve {
  int pin;
public:
  Valve() {}
  void begin(int valvePin);
  void open();
  void close();
};

// ---- Sensor ---- //
class Sensor {
  int pin;
public:
  Sensor() {}
  void begin(int sensorPin);
  float read();
};

// ---- Motor ---- //
class Motor {
  int pin;
public:
  Motor() {}
  void begin(int motorPin);
  void set(float percentage);
  void on();
  void off();
};

// ---- Named Pump objects ---- //
extern Pump pumpA;
extern Pump pumpB;

// ---- Named Valve objects ---- //
extern Valve valveA;
extern Valve valveB;

// ---- Named Sensor objects ---- //
extern Sensor sensorA;
extern Sensor sensorB;

// ---- Named Motor objects ---- //
extern Motor M1;
extern Motor M2;
extern Motor M3;
extern Motor M4;

class MotorArray {
  Motor* list[4];
public:
  MotorArray(Motor& m1, Motor& m2, Motor& m3, Motor& m4) {
    list[0] = &m1;
    list[1] = &m2;
    list[2] = &m3;
    list[3] = &m4;
  }

  Motor& operator[](int index) {
    return *list[index];
  }
};

extern MotorArray motors;

// ---- Init function ---- //
void AirSystem_begin();

#endif
