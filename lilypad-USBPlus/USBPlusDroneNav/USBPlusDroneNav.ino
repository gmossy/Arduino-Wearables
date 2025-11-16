/*
  USBPlusDroneNav.ino

  Navigation-style RGB LED pattern for mounting a SparkFun LilyPad USB Plus
  on a small drone for increased night visibility.

  Author: Glenn Mossy
  Board:  SparkFun LilyPad USB Plus (SparkFun:avr:LilyPadProtoUSB)

  Description:
    - Uses the built-in RGB LED (pins 12, 13, 14) as a compact nav light.
    - Emulates a common drone/aircraft-inspired scheme:
        * Slow pulsing "position" glow.
        * Periodic bright white strobe for visibility.
    - Timing and colors are chosen for demonstration/education only;
      this sketch does NOT claim to be legally certified for FAA/FCC
      requirements. Always follow your local regulations and
      manufacturer guidance for flight lighting.

  Suggested mounting:
    - Sew or Velcro the LilyPad USB Plus to the **top or rear** of the
      drone frame so the RGB LED is clearly visible.
    - Use a LiPo battery connected to the on-board JST and secure all
      wiring to avoid propellers.
*/

#include <Arduino.h>

// Built-in RGB LED pins on LilyPad USB Plus
const int PIN_R = 12;
const int PIN_G = 13;
const int PIN_B = 14;

// Timing configuration (in ms)
const unsigned long PULSE_PERIOD   = 2000;  // full in+out cycle
const unsigned long STROBE_PERIOD  = 1500;  // time between white strobes
const unsigned long STROBE_LENGTH  = 80;    // strobe on-time

unsigned long gLastStrobe = 0;

void setRGB(uint8_t r, uint8_t g, uint8_t b) {
  analogWrite(PIN_R, r);
  analogWrite(PIN_G, g);
  analogWrite(PIN_B, b);
}

void setup() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);

  // Start with everything off
  setRGB(0, 0, 0);
}

void loop() {
  unsigned long now = millis();

  // 1) Continuous low-level "position" glow using a red/green mix
  //    We generate a triangle-wave brightness over PULSE_PERIOD.
  unsigned long phase = now % PULSE_PERIOD;
  int half = PULSE_PERIOD / 2;
  int level;
  if (phase < (unsigned long)half) {
    level = map(phase, 0, half, 10, 80);   // fade in
  } else {
    level = map(phase - half, 0, half, 80, 10); // fade out
  }

  // Soft red/green mix (amber-ish) for general visibility
  uint8_t baseR = level;
  uint8_t baseG = level / 2;
  uint8_t baseB = 0;

  setRGB(baseR, baseG, baseB);

  // 2) Periodic bright white strobe layered on top
  if (now - gLastStrobe >= STROBE_PERIOD) {
    gLastStrobe = now;
  }

  if (now - gLastStrobe <= STROBE_LENGTH) {
    // Short white flash
    setRGB(255, 255, 255);
  }

  // Small delay to keep CPU use low while maintaining smooth animation
  delay(10);
}
