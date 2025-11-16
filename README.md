# Welcome to My Arduino Wearables Open Source Community!

This repo is my playground for wearable electronics using the **SparkFun LilyPad USB Plus** and the broader **Arduino wearables** ecosystem. Its designed to be:

- **Interview-ready**: clean examples you can walk through with hiring managers.
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

This repo currently includes demo sketches that turn the LilyPad USB Plus into a **wearable light show**:

- `USBPlusRGBBlink/`  minimal RGB center LED color cycle.
- `USBPlusFunDemo/`  a full light show using the RGB LED + six white LEDs (chase, bounce, wipe, sparkle).

You can:

- Use these as-is for workshops or show-and-tell.
- Fork them into your own wearable art pieces.
- Extend them with sensors (accelerometers, buttons, light sensors, etc.).

---

## Dev Workflow: VS Code or Windsurf + Arduino CLI

You can work on this project using **VS Code** or **Windsurf** as your editor, with the **Arduino CLI** doing all the compiling and uploading.

### 1. Install Arduino CLI

On macOS (recommended):

```bash
brew update
brew install arduino-cli
```

Or use the official installer: <https://arduino.github.io/arduino-cli/latest/installation/>

### 2. Configure Arduino CLI for SparkFun LilyPad USB Plus

```bash
arduino-cli config init
arduino-cli config add board_manager.additional_urls \
  https://raw.githubusercontent.com/sparkfun/Arduino_Boards/master/IDE_Board_Manager/package_sparkfun_index.json
arduino-cli core update-index
arduino-cli core install SparkFun:avr

# Confirm the LilyPad USB Plus FQBN is available
arduino-cli board listall | grep -i "lilypad usb plus"
```

### 3. Open the Repo in VS Code or Windsurf

- **VS Code**: `File → Open Folder...` and select the cloned repo.
- **Windsurf**: Open the workspace folder (same repo) and use the built-in terminal.

Tip: Install an **Arduino** or **C/C++** extension for syntax highlighting and IntelliSense.

### 4. Connect the Board

- Plug in the LilyPad USB Plus with a **data-capable** micro‑USB cable.
- Switch the board to **ON**.
- If the serial port doesnt appear, **double-tap RESET** to enter the bootloader.
- List the ports:

```bash
arduino-cli board list
```

Replace `<PORT>` below with something like `/dev/cu.usbmodemXXXX`.

### 5. Build and Upload from the Terminal

#### RGB Blink

```bash
arduino-cli compile --fqbn SparkFun:avr:LilyPadProtoUSB lillypad/USBPlusRGBBlink
arduino-cli upload  -p <PORT> --fqbn SparkFun:avr:LilyPadProtoUSB lillypad/USBPlusRGBBlink
```

#### Full Fun Demo

```bash
arduino-cli compile --fqbn SparkFun:avr:LilyPadProtoUSB lillypad/USBPlusFunDemo
arduino-cli upload  -p <PORT> --fqbn SparkFun:avr:LilyPadProtoUSB lillypad/USBPlusFunDemo
```

You can run these commands directly in the **VS Code** or **Windsurf** integrated terminal so everything lives in one window.

---

## Optional: Python/Tooling Environment with `uv`

If you want to add Python-based tooling around this project (log viewers, animation generators, CLI helpers, etc.), you can manage that environment with **`uv`**, a fast Python package and virtual environment manager.

### 1. Install `uv`

See the official instructions: <https://docs.astral.sh/uv/>

On macOS, a typical install looks like:

```bash
curl -LsSf https://astral.sh/uv/install.sh | sh
```

Make sure `uv` is on your `PATH` (restart your terminal if needed), then verify:

```bash
uv --version
```

### 2. Create a Project Environment

From the root of this repo:

```bash
uv venv .venv
source .venv/bin/activate
```

You can now install any Python tools you want for this project, for example:

```bash
uv pip install pyserial
```

Use this environment for helper scripts that talk to the board, visualize sensor data, or generate animation patterns. The Arduino code itself is still built and uploaded with **Arduino CLI**.

---

## Board Details: LEDs, Pins, and Tricks

Some quick facts handy for extending these demos:

- **Built-in RGB LED**
  - Red: pin `12`
  - Green: pin `13`
  - Blue: pin `14`
- **Six built-in white LEDs** on pins `15, 16, 17, 18, 19, 20`.
- **Microcontroller**: ATmega32U4 using the Caterina bootloader (Arduino-compatible).

These pins are already used in the demo sketches for color fades, chases, and sparkle effects you can show off during interviews or workshops.

---

## What the Demos Do

- **RGB Blink**
  - Cycles solid colors (R, G, B, Y, M, C, White, Off) on the center RGB LED.

- **Fun Demo**
  - Flashes all LEDs, runs RGB color cycles, theater chase, bounce, wipe, and sparkle patterns across the white LEDs.
  - Great for showing how timing, state machines, and non-blocking animation patterns work on microcontrollers.

---

## Next Steps and Ideas

Use this repo as a starting point for:

- Classroom or makerspace labs on **wearable hardware**.
- Portfolio-ready demos of **non-blocking LED animations** and **embedded state machines**.
- Interactive garments that respond to **buttons, motion, or light**.

If you build something cool, open a PR or share links to your project threads on the Arduino or SparkFun forums!

---

Enjoy creating wearable light shows and sharing them with the community!
