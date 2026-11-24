// logger.ino - prints status messages to the Serial Monitor (9600 baud)

// TODO Task 4 (Tim Grant): add modeName() here.
const char* modeName(currentMode()) {
  switch (mode) {
    case MODE_OFF:
      return "OFF";
    case MODE_AUTO:
      return "AUTO";
    case MODE_ON:
      return "ON";
  }
}


void logStatus(int light) {
  unsigned long delay=500;
  unsigned long last=millis()
  if (millis()>last+delay){
    Serial.print("Mode=");
    Serial.print(modeName());
    Serial.print("Light=");
    Serial.print(light);
    Serial.print("led=");
    Serial.print(ledBrightness);
      }
  
}

// TODO Task 6 (Developer B): add logBanner() below this line.
