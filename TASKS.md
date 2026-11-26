# NightLight Tasks

Each task gives a goal, where to work and some hints, not the code. Write your own solution. Keep it inside the file and function named in your task, so that your edits and your teammates' edits do not overlap. The `TODO` comment with your task number marks where to work, and you can delete it when you are done. Your code does not need to match anyone else's. It only needs to do the job described.

Make sure your code compiles successfully before committing your code.

## Round 1 (Activity 3)

| Task | Owner | Branch | Where you work |
| --- | --- | --- | --- |
| 1 | Developer A | `task1-sensor` | `light_sensor.ino` |
| 2 | Developer B | `task2-led` | `led.ino` |
| 3 | Developer C | `task3-button` | `button.ino` |
| 4 | Project Manager | `task4-logger` | `logger.ino` |

### Task 1: Smooth the light sensor

Branch: `task1-sensor`.

**Goal:** `readLight()` returns a steadier value instead of one jumpy reading. It still returns a number from 0 to 1023.

**Where:** `light_sensor.ino`, inside `readLight()`. Put any new setting in the light sensor section of `config.h`.

**Hints:**

- Taking several readings and averaging them is the usual approach.
- Keep the number of readings in a constant in `config.h` instead of typing it into the function. Declare it as `const int`, with a name such as `SENSOR_SAMPLES`.
- `analogRead(LIGHT_SENSOR_PIN)` takes one reading.
- A total of many readings can be too big for an `int`. Think about which type to use for the total.

### Task 2: Fade the LED smoothly

Branch: `task2-led`.

**Goal:** `fadeTowards(target)` moves the LED a small step toward `target` each time it is called, so the LED fades instead of jumping. It is called once on every pass through `loop()`.

**Where:** `led.ino`, inside `fadeTowards()`. Put any new setting in the LED section of `config.h`.
**Hints:**

- `ledBrightness` holds the current brightness. `setLed(value)` changes it and updates the pin.
- Step up when the brightness is below the target, step down when it is above, and do nothing when it is equal. Never step past the target.
- Keep the step size in a `const int` such as `FADE_STEP`.
- `min()` and `max()` help you avoid overshooting.

### Task 3: Debounce the button

Branch: `task3-button`.

**Goal:** `buttonPressed()` returns `true` exactly once for each press, even if the button is held down or its contacts bounce.

**Where:** `button.ino`, inside `buttonPressed()`. Put any new setting in the button section of `config.h`.

**Hints:**

- The button uses the built-in pull-up resistor, so the pin reads `LOW` while the button is pressed and `HIGH` when it is not.
- You need to remember the previous state between calls. A `static` variable inside the function keeps its value.
- Look for the moment the state changes from `HIGH` to `LOW`, not for the state itself.
- `millis()` gives the time in milliseconds. Ignore changes that come too soon after the last one, within a few tens of milliseconds. Keep that time in a constant such as `BUTTON_DEBOUNCE_MS`. Times from `millis()` are `unsigned long`, so declare it as `const unsigned long`.

### Task 4: Tidy the status line

Branch: `task4-logger`.

**Goal:** `logStatus(light)` prints one readable line about twice a second, for example `mode=AUTO light=512 led=120`. A helper function `modeName()` turns a `Mode` into text such as `AUTO`.

**Where:** `logger.ino`. Write `modeName()` where its TODO comment is, and fill in `logStatus()`. Put any new setting in the logger section of `config.h`.

**Hints:**

- `Serial.print()` writes without ending the line, and `Serial.println()` ends it.
- `currentMode` and `ledBrightness` are global variables you can use directly.
- To print only twice a second, remember when you last printed (a `static` variable works) and compare with `millis()`. Keep the interval in a constant such as `LOG_INTERVAL_MS`, declared as `const unsigned long`.
- `modeName()` can use a `switch` on `MODE_OFF`, `MODE_AUTO` and `MODE_ON`. Its return type is `const char*`.

## Round 2 (Activity 5)

| Task | Owner | Branch | Where you work |
| --- | --- | --- | --- |
| 5 | Developer A | `task5-auto` | `NightLight.ino`, `config.h` |
| 6 | Developer B | `task6-banner` | `logger.ino`, `NightLight.ino`, `config.h` |
| 7 | Developer C | `task7-blink` | `led.ino`, `NightLight.ino` |
| 8 | Project Manager | `task8-label` | `light_sensor.ino`, `logger.ino` |

The same rules as Round 1 apply: a goal, hints, your own solution, and edits kept inside the function the task names. Two numbers are fixed on purpose in Tasks 5 and 6, so that the planned conflict happens.

### Task 5: Turn the LED on when it is dark

Branch: `task5-auto`.

**Goal:** In AUTO mode the LED fades up to a night brightness when the room is dark, and fades off when the room is bright.

**Where:** `NightLight.ino`, inside `applyAuto()`, and the `DARK_THRESHOLD` line in `config.h`.

**Required:** On the `DARK_THRESHOLD` line in `config.h`, change the number from `500` to `300` (your room is dim). Leave the rest of the line alone.

**Hints:**

- `applyAuto(light)` is called on every pass through `loop()` with the latest sensor reading.
- A reading below `DARK_THRESHOLD` means dark. `NIGHT_BRIGHTNESS` is the brightness to use in the dark.
- `fadeTowards(target)` does the fading. It is the function Developer B wrote in Round 1.

### Task 6: Add a startup banner

Branch: `task6-banner`.

**Goal:** When the board starts, it prints a short banner in the Serial Monitor: the project name and a one-line hint about the button.

**Where:** `logger.ino`, a new function `logBanner()` with no parameters, written where its TODO comment is. Call it from `setup()` in `NightLight.ino`. Also the `DARK_THRESHOLD` line in `config.h`.

**Required:** On the `DARK_THRESHOLD` line in `config.h`, change the number from `500` to `400` (your room is brighter). Leave the rest of the line alone.

**Hints:**

- `setup()` runs once at startup, and `Serial.begin(9600)` has already been called by the time it reaches your line.
- `Serial.println()` prints a line of text.
- All the `.ino` files in the folder are one sketch, so a function in `logger.ino` can be called from `NightLight.ino` with no extra setup.

### Task 7: Blink when the mode changes

Branch: `task7-blink`.

**Goal:** When the mode changes, the LED blinks to confirm it: once for OFF, twice for AUTO, three times for ON.

**Where:** `led.ino`, a new function `blinkLed(int times)` written where its TODO comment is. Call it from `handleButton()` in `NightLight.ino`, right after the mode changes.

**Hints:**

- `setLed()` sets the brightness and `delay()` pauses for a number of milliseconds.
- A `for` loop that runs `times` times does the repeating.
- `currentMode` is a number behind the scenes: `MODE_OFF` is 0, `MODE_AUTO` is 1 and `MODE_ON` is 2. A little arithmetic turns it into a blink count.

### Task 8: Report whether the room is dark

Branch: `task8-label`.

**Goal:** The status line in the Serial Monitor also says whether the room is dark or bright.

**Where:** `light_sensor.ino`, a new function `lightLabel(int light)` that returns a word such as `dark` or `bright`, written where its TODO comment is. Use it in `logStatus()` in `logger.ino`.

**Hints:**

- Compare `light` with `DARK_THRESHOLD`, as Task 5 does.
- The return type is `const char*`, like `modeName()` from Task 4.
- In `logStatus()`, add one more print next to the ones you wrote in Task 4.
