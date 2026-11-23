// logger.ino - prints status messages to the Serial Monitor (9600 baud)

// TODO Task 4 (Project Manager): add modeName() here.
const char* modeName(Mode M) {
  switch (M) {
    case MODE_OFF:
      return "OFF";
    case MODE_ON:
      return "ON";
    case AUTO:
      return "AUTO";
    default:
      return "UNKNOWN MODE";
  }
}
void logStatus(int light) {
  static unsigned long lastTime = 0;
  unsigned long currentTime = millis();
  if (currentTime - lastTime >= Log_interval) {
    lastTime = currentTime;
    Serial.print("Mode=");
    Serial.print(modeName(currentMode));
    Serial.print("light =");
    Serial.print(light);
    Serial.print("led brightness =");
    Serial.println(ledBrightness);
    
  }
}

// TODO Task 6 (Developer B): add logBanner() below this line.
