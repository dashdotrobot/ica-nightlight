#include <Arduino.h>

// light_sensor.ino - reads the photoresistor on LIGHT_SENSOR_PIN
// Returns 0 (dark) up to 1023 (bright).
const int LIGHT_SENSOR_PIN = A0;  // pin for the light sensor

const int SENSOR_SAMPLES = 10;  // number of readings to average


int readLight() {
  // TODO Task 1 (Developer A): average SENSOR_SAMPLES readings.

long sum = 0;
for (int i = 0; i < SENSOR_SAMPLES; i++) {
    sum += analogRead(LIGHT_SENSOR_PIN);
  }
  sum /= SENSOR_SAMPLES;

  return sum;
}

// TODO Task 8 (Project Manager): add lightLabel() below this line.
