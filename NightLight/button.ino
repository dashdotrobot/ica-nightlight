// button.ino - reads the pushbutton on BUTTON_PIN
// The button connects the pin to GND, so a press reads LOW.

// Should return true once for each press of the button.
bool buttonPressed() {
  
  static int lastReading = HIGH;
  static int buttonState = HIGH;
  static unsigned long lastDebounceTime = 0;

  int currentReading = digitalRead(BUTTON_PIN);

 
  if (currentReading != lastReading) {
    lastDebounceTime = millis();
  }
  lastReading = currentReading;

 
  if ((millis() - lastDebounceTime) > BUTTON_DEBOUNCE_MS) {
    // Check if the stable button state has actually changed
    if (currentReading != buttonState) {
      buttonState = currentReading;

      
      if (buttonState == LOW) {
        return true;
      }
    }
  }

  return false;
}
