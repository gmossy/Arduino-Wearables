/*
  USBPlusRGBBlink.ino

  Simple wearable light-show demo for the SparkFun LilyPad USB Plus.

  Author: Glenn Mossy
  Board:  SparkFun LilyPad USB Plus (SparkFun:avr:LilyPadProtoUSB)

  Description:
    - Drives the built-in RGB LED (pins 12, 13, 14) and the row of
      six white LEDs (pins 15–20) on the LilyPad USB Plus.
    - Starts with a slow fade-in / fade-out effect across the white
      LED bar using PWM (where supported).
    - Follows with a sequence of “evergreen” green + whites, classic
      red + whites, warm candlelight tones, a green-background chase
      across the white LEDs, a full sparkle burst, and a calm pause
      with all LEDs off.

  Intended use:
    - Quick visual test to confirm a LilyPad USB Plus is wired and
      configured correctly.
    - Portfolio / interview demo to show basic embedded sequencing
      and LED control.
    - Makerspace or classroom example for introducing Arduino-based
      wearables and non-blocking animation patterns.
*/

#include <Arduino.h>

// LilyPad USB Plus built-in RGB LED pins
// R = 12, G = 13, B = 14 (per SparkFun hookup guide)
const int PIN_R = 12;
const int PIN_G = 13;
const int PIN_B = 14;

// Six built-in white LEDs on pins: 15–20 (per README)
const int WHITE_LEDS[] = {15, 16, 17, 18, 19, 20};
const int WHITE_COUNT = sizeof(WHITE_LEDS) / sizeof(WHITE_LEDS[0]);

// Optional inputs to showcase more of the board's capabilities
// Momentary button between D2 and GND (internal pull-up enabled)
const int PIN_BUTTON = 2;
// Example analog sew tab (e.g., light sensor, fabric pressure sensor)
// Wire one side of the sensor to A3 and the other to 3.3V, with a
// matching resistor to GND for a simple voltage divider.
const int PIN_SENSOR = A3;

// Interactive mode flag, toggled by the button
bool gInteractiveEnabled = true;

// Base delay for slow "ornament" flashing (in ms)
const unsigned long STEP_DELAY = 800;

void setRGB(bool r, bool g, bool b) {
  digitalWrite(PIN_R, r ? HIGH : LOW);
  digitalWrite(PIN_G, g ? HIGH : LOW);
  digitalWrite(PIN_B, b ? HIGH : LOW);
}

void setWhites(bool on) {
  for (int i = 0; i < WHITE_COUNT; i++) {
    digitalWrite(WHITE_LEDS[i], on ? HIGH : LOW);
  }
}

void allOff() {
  setRGB(false, false, false);
  setWhites(false);
}

void setup() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);

  for (int i = 0; i < WHITE_COUNT; i++) {
    pinMode(WHITE_LEDS[i], OUTPUT);
  }

  // Optional button input (will safely read HIGH if nothing is connected)
  pinMode(PIN_BUTTON, INPUT_PULLUP);

  allOff();
}

// Simple edge-sensitive toggle on the button
void updateInteractiveToggle() {
  static bool lastState = HIGH;
  static unsigned long lastChangeMs = 0;

  bool current = digitalRead(PIN_BUTTON);
  unsigned long now = millis();

  // Basic debounce and edge detection: look for HIGH->LOW transitions
  if (current != lastState && (now - lastChangeMs) > 200) {
    lastChangeMs = now;
    if (lastState == HIGH && current == LOW) {
      gInteractiveEnabled = !gInteractiveEnabled;
    }
    lastState = current;
  }
}

void loop() {
  // 1) Slow fade in/out on the white LED bar
  setRGB(false, false, false);
  for (int level = 0; level <= 255; level += 5) {
    for (int i = 0; i < WHITE_COUNT; i++) {
      analogWrite(WHITE_LEDS[i], level);
    }
    delay(20);
  }
  for (int level = 255; level >= 0; level -= 5) {
    for (int i = 0; i < WHITE_COUNT; i++) {
      analogWrite(WHITE_LEDS[i], level);
    }
    delay(20);
  }

  // 2) Soft "evergreen" look: green + all whites
  setRGB(false, true, false);  // Green
  setWhites(true);
  delay(STEP_DELAY);

  // 3) Cozy red + whites (classic Christmas)
  setRGB(true, false, false);  // Red
  setWhites(true);
  delay(STEP_DELAY);

  // 4) Warm "candlelight" white (RGB + whites)
  setRGB(true, true, false);   // Yellowish
  setWhites(true);
  delay(STEP_DELAY);

  // 5) Twinkle: chase across white LEDs with steady green
  setRGB(false, true, false);  // Green background
  setWhites(false);
  for (int i = 0; i < WHITE_COUNT; i++) {
    digitalWrite(WHITE_LEDS[i], HIGH);
    delay(STEP_DELAY / 2);
    digitalWrite(WHITE_LEDS[i], LOW);
  }

  // 6) All-on sparkle burst (brief bright moment)
  setRGB(true, true, true);    // White RGB
  setWhites(true);
  delay(STEP_DELAY);

  // 7) Optional interactive sensor demo
  //    - If a sensor is attached to A3, its reading controls brightness
  //      of the RGB and white LEDs.
  //    - A button on D2 toggles whether this interactive section runs.
  updateInteractiveToggle();
  if (gInteractiveEnabled) {
    int sensor = analogRead(PIN_SENSOR);        // 0–1023
    int brightness = map(sensor, 0, 1023, 0, 255);

    // Brief moment where the whole board "breathes" with the sensor
    for (int i = 0; i < 3; i++) {
      analogWrite(PIN_R, brightness);
      analogWrite(PIN_G, brightness);
      analogWrite(PIN_B, brightness);
      for (int led = 0; led < WHITE_COUNT; led++) {
        analogWrite(WHITE_LEDS[led], brightness);
      }
      delay(150);
    }
  }

  // 8) Long, calm pause with everything off
  allOff();
  delay(STEP_DELAY * 2);
}
