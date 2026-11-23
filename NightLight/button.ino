// button.ino - reads the pushbutton on BUTTON_PIN
// The button connects the pin to GND, so a press reads LOW.

// Should return true once for each press of the button.
// Returns true once for each press of the button.
bool buttonPressed() {
  static int lastState = HIGH;               // HIGH = not pressed (pull up)
  static unsigned long lastChangeTime = 0;   // when lastState last changed

  int state = digitalRead(BUTTON_PIN);

  // Accept a change only if enough time has passed since the last one.
  if (state != lastState && millis() - lastChangeTime >= BUTTON_DEBOUNCE_MS) {
    lastState = state;
    lastChangeTime = millis();
    return state == LOW;   // true only on the HIGH to LOW edge (a new press)
  }

  return false;
}
