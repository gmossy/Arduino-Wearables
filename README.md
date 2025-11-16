# Welcome to My Arduino Wearables Open Source Community!

This repo is my playground for wearable electronics using the **SparkFun LilyPad USB Plus** and the broader **Arduino wearables** ecosystem. Its designed to be:

- **Learning-friendly**: clear examples you can step through and modify.
- **Makerspace-friendly**: step-by-step instructions for students and workshop participants.
- **Open for collaboration**: clone it, remix it, and share what you build.

Author: Glenn Mossy

![LilyPad USB Plus](https://cdn.sparkfun.com/r/600-600/assets/parts/1/1/2/0/9/14346-LilyPad_USB_Plus-01.jpg)

---

## What Is the LilyPad USB Plus?

The **LilyPad USB Plus** (SparkFun SKU: **DEV-14631**) is a **sewable electronics microcontroller board** designed for **e-textiles** and **wearable projects**. Its powered by an **ATmega32U4** running the **Arduino bootloader**, so you can program it just like any other Arduino board.

The board is built to streamline your next sewable project:

- **Built-in power**: JST connector with **on-board LiPo recharge circuit** and a handy **on/off switch**  no separate power board required.
- **Visual feedback**: a **center RGB LED** on pins `R=12`, `G=13`, `B=14` plus **six white LEDs** on pins `15–20`, perfect for bar-graph style animations and wearable light shows.
- **Easy programming**: a **micro-USB port** for both power and sketch uploads.
- **Sew tabs** around the edge for connecting sensors, actuators, and extra LEDs with conductive thread.

If youre new to this board, SparkFuns official resources are fantastic starting points:

- SparkFun product page: <https://www.sparkfun.com/lilypad-usb-plus.html>
- SparkFun LilyPad USB Plus Hookup Guide: <https://learn.sparkfun.com/tutorials/lilypad-usb-plus-hookup-guide/all>
- SparkFun LilyPad USB Plus Standalone GitHub repo: <https://github.com/sparkfun/LilyPad_USB_Plus_Standalone/tree/master>

Related Arduino wearables resources:

- Arduino wearables overview: <https://www.arduino.cc/en/Main/ArduinoBoardLilyPad>
- Getting started with LilyPad Arduino USB: <https://www.arduino.cc/en/Guide/ArduinoLilyPadUSB/>

LilyPad community discussion and troubleshooting:

- Arduino Forum (LilyPad section, including USB Plus threads): <https://forum.arduino.cc/>
- SparkFun community help (search for "LilyPad USB Plus"): <https://community.sparkfun.com/>

---

## Project Overview

This repo currently includes a **LilyPad USB Plus wearable light show demo**:

- `lilypad-USBPlus/USBPlusRGBBlink/`  a curated RGB + white LED sequence with optional button and sensor support.

You can:

- Use this as-is for workshops or show-and-tell.
- Fork it into your own wearable art pieces.
- Extend it with sensors (accelerometers, buttons, light sensors, etc.).

For **device-specific wiring, Arduino CLI commands, and Windsurf workflow**, see:

- `lilypad-USBPlus/README.md`

That file walks through the exact compile/upload steps and example MacBook/Windsurf setup.

---

## Editor + Tooling

Recommended setup:

- **Editor**: VS Code or Windsurf.
- **Tooling**: Arduino CLI for building/uploading, optional `uv` + Python for helper scripts.

See the detailed instructions in `lilypad-USBPlus/README.md` if you want copy-paste commands.

---

## Optional: Python/Tooling Environment with `uv`

If you want to add Python-based tooling around this project (log viewers, animation generators, CLI helpers, etc.), you can manage that environment with **`uv`**, a fast Python package and virtual environment manager.

See `lilypad-USBPlus/README.md` for one possible layout; feel free to customize it for your own workflow.

---

## Board Details: LEDs, Pins, and Tricks

Some quick facts handy for extending these demos:

- **Built-in RGB LED**
  - Red: pin `12`
  - Green: pin `13`
  - Blue: pin `14`
- **Six built-in white LEDs** on pins `15, 16, 17, 18, 19, 20`.
- **Microcontroller**: ATmega32U4 using the Caterina bootloader (Arduino-compatible).

These pins are already used in the demo sketches for color fades, chases, and sparkle effects you can show off in workshops or community demos.

---

## What the Demo Does

- **USBPlusRGBBlink**
  - Runs a curated sequence across the built-in RGB LED and six white LEDs.
  - Includes an optional interactive section using a button and analog sensor.

---

## Next Steps and Ideas

Use this repo as a starting point for:

- Classroom or makerspace labs on **wearable hardware**.
- Portfolio-ready demos of **non-blocking LED animations** and **embedded state machines**.
- Interactive garments that respond to **buttons, motion, or light**.

If you build something cool, open a PR or share links to your project threads on the Arduino or SparkFun forums!

---

Enjoy creating wearable light shows and sharing them with the community!
