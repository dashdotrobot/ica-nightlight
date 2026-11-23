// led.ino - controls the LED brightness (0 = off, 255 = full brightness)

int ledBrightness = 0;   // remembers the current brightness

void setLed(int brightness) {
  ledBrightness = constrain(brightness, 0, 255);
  analogWrite(LED_PIN, ledBrightness);
}

// Moves the LED one small step toward the target brightness.
void fadeTowards(int target) {
  if (ledBrightness < target) {
    setLed(min(ledBrightness + FADE_STEP, target));   // step up, stop at target
  } else if (ledBrightness > target) {
    setLed(max(ledBrightness - FADE_STEP, target));   // step down, stop at target
  }
  // equal: do nothing
}

// TODO Task 7 (Developer C): add blinkLed() below this line.
