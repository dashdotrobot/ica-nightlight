// light_sensor.ino - reads the photoresistor on LIGHT_SENSOR_PIN
// Averages SENSOR_SAMPLES readings to smooth out short fluctuations.
// Returns 0 (dark) up to 1023 (bright).

int readLight() {
  long total = 0;
  for (int sample = 0; sample < SENSOR_SAMPLES; ++sample) {
    total += analogRead(LIGHT_SENSOR_PIN);
  }
  return total / SENSOR_SAMPLES;
}

// TODO Task 8 (Project Manager): add lightLabel() below this line.
