# LilyPad USB Plus Demo (USBPlusRGBBlink)

This folder contains the **device-specific** code and docs for the
**SparkFun LilyPad USB Plus** light-show demo.

- Sketch: `USBPlusRGBBlink/USBPlusRGBBlink.ino`
- Board: SparkFun LilyPad USB Plus (`SparkFun:avr:LilyPadProtoUSB`)
- Author: Glenn Mossy

Use this when you want **copy-paste commands, wiring diagrams, and a
MacBook + Windsurf workflow** that you can share with students,
friends, and makerspace communities.

---

## What This Demo Does

The `USBPlusRGBBlink` sketch turns one board into a wearable
light-show + small interaction lab:

- Drives the **built-in RGB LED** (pins `12`, `13`, `14`).
- Uses the **row of six white LEDs** (pins `15–20`) as a bar graph /
  animation strip.
- Plays a curated sequence:
  - Slow fade in/out across the white LED bar.
  - Green + whites, red + whites, warm "candlelight" tones.
  - Green-background chase across the white bar.
  - Full sparkle burst, then a calm pause.
- Optional interactive section:
  - **Button on D2** toggles an interactive mode.
  - **Analog sensor on A3** (e.g., light or pressure sensor) controls
    LED brightness so the whole board "breathes" with your input.

This is designed to be:

- **Makerspace-friendly**: good first demo for wearable workshops.
- **Extendable**: add more patterns, sensors, or serial commands.

---

## Hardware You Need

- SparkFun **LilyPad USB Plus** board.
- Micro‑USB **data** cable.
- Optional:
  - Momentary **button** for D2.
  - Simple analog **sensor** (photoresistor, fabric pressure sensor,
    flex sensor, etc.) for A3.
  - Needle + conductive thread if you want to sew it into fabric.

---

## Wiring (Optional Inputs)

The demo runs **even with no extra hardware**. To show more of the
board's capabilities, you can add:

### Button on `D2`

- Connect one leg of a **momentary button** to `D2`.
- Connect the other leg to `GND`.
- The sketch enables the **internal pull-up**, so:
  - Released ⇒ reads `HIGH`.
  - Pressed  ⇒ reads `LOW` and **toggles interactive mode**.

### Analog sensor on `A3`

Use a simple voltage divider, for example a **photoresistor**:

- Connect one side of the sensor to **3.3V**.
- Connect the other side to **A3**.
- Add a fixed resistor (e.g., 10kΩ) between **A3** and **GND**.

In the interactive section of the loop, the sketch does:

- `sensor = analogRead(A3)` → 0–1023.
- Maps to `brightness` 0–255.
- Uses `analogWrite` on the RGB and white LEDs so the whole board
  brightens/dims with the sensor value.

---

## MacBook + Windsurf Workflow

This section assumes:

- You are on **macOS**.
- You open this repo folder (`Arduino_Lillypad`) in **Windsurf**.
- The LilyPad USB Plus appears as `/dev/cu.usbmodem1431301` when
  plugged in.

### 1. Install Arduino CLI

In a terminal (can be Windsurf's integrated terminal):

```bash
brew update
brew install arduino-cli
```

Or follow the official docs:

<https://arduino.github.io/arduino-cli/latest/installation/>

### 2. Configure Arduino CLI for LilyPad USB Plus

```bash
arduino-cli config init
arduino-cli config add board_manager.additional_urls \
  https://raw.githubusercontent.com/sparkfun/Arduino_Boards/master/IDE_Board_Manager/package_sparkfun_index.json
arduino-cli core update-index
arduino-cli core install SparkFun:avr

# Confirm the LilyPad USB Plus board definition exists
arduino-cli board listall | grep -i "lilypad usb plus"
```

### 3. Open the Project in Windsurf

1. In Windsurf, open the folder `Arduino_Lillypad`.
2. Open:
   - `lilypad-USBPlus/USBPlusRGBBlink/USBPlusRGBBlink.ino`
   - This `README.md` for reference.
3. Use the integrated terminal for all CLI commands.

### 4. Connect the Board (MacBook)

1. Plug the LilyPad USB Plus into your MacBook with a **data-capable
   micro‑USB cable**.
2. Slide the **ON/OFF switch** to **ON**.
3. If the port does not show up, **double-tap RESET** on the board to
   enter the bootloader.
4. List available boards:

```bash
arduino-cli board list
```

You should see a line similar to:

```text
/dev/cu.usbmodem1431301  serial  Serial Port (USB) LilyPad USB Plus SparkFun:avr:LilyPadProtoUSB SparkFun:avr
```

Here, the port is:

```text
/dev/cu.usbmodem1431301
```

---

## Build and Upload the Demo

All commands below assume your current directory is the **repo root**:

```bash
cd /Users/gmossy/Arduino_Lillypad
```

### 1. Compile `USBPlusRGBBlink`

```bash
arduino-cli compile \
  --fqbn SparkFun:avr:LilyPadProtoUSB \
  lilypad-USBPlus/USBPlusRGBBlink
```

You should see something like:

```text
Sketch uses XXXX bytes (YY%) of program storage space.
Global variables use ZZZ bytes (WW%) of dynamic memory.
```

### 2. Upload to `/dev/cu.usbmodem1431301`

```bash
arduino-cli upload \
  -p /dev/cu.usbmodem1431301 \
  --fqbn SparkFun:avr:LilyPadProtoUSB \
  lilypad-USBPlus/USBPlusRGBBlink
```

If you change Macs or USB ports, re-run:

```bash
arduino-cli board list
```

and update the `-p` value accordingly.

---

## What to Demo (Talk Track)

When showing this project to students or friends, you can say:

1. **Board intro**
   - "This is a SparkFun LilyPad USB Plus, an Arduino-compatible
     wearables board with a built-in RGB LED, a row of six white LEDs,
     and a LiPo charger."
2. **Software toolchain**
   - "I use Windsurf on a MacBook with the Arduino CLI so everything
     is scriptable and version-controlled."
3. **Patterns**
   - Point out the fade, color scenes, chase, and sparkle sections in
     `USBPlusRGBBlink.ino`.
4. **Interactivity**
   - Show the button on `D2` toggling interactive mode.
   - Show how covering a light sensor or pressing on a fabric sensor
     on `A3` changes the brightness breathing.
5. **Extensibility**
   - Describe how you would add more modes, serial commands, or
     support for additional sewable LEDs and sensors.

---

## Makerspace Lesson Outline (45–60 minutes)

You can run a simple workshop around this board and sketch:

1. **Welcome + safety (5 min)**
   - Quick overview of wearables and the LilyPad USB Plus.
   - Basic safety: no shorting pads, careful with needles and LiPo batteries.

2. **Hardware setup (10–15 min)**
   - Hand out boards, USB cables, and (optional) buttons/sensors.
   - Show how to plug into laptops and find the serial port with
     `arduino-cli board list`.

3. **First upload (10–15 min)**
   - Open `USBPlusRGBBlink.ino` in Windsurf.
   - Walk everyone through compiling and uploading to their
     `/dev/cu.usbmodemXXXX` port.
   - Celebrate the first full light show.

4. **Interactivity (10–15 min)**
   - Wire a button to D2 and a sensor to A3.
   - Explain how the code reads button/sensor values.
   - Let students experiment with covering sensors, pressing fabric,
     and watching the brightness change.

5. **Tweak + share (10–15 min)**
   - Invite small edits: change colors, delays, or the number of
     loops in the interactive section.
   - Quick show-and-tell of everyones favorite pattern.

---

## Troubleshooting

- **Board not detected**
  - Try a different USB port or cable.
  - Double-tap RESET and re-run `arduino-cli board list`.
- **Upload fails**
  - Make sure `--fqbn SparkFun:avr:LilyPadProtoUSB` is correct.
  - Confirm the SparkFun AVR core is installed.
- **LEDs very dim**
  - Check battery/USB power.
  - Verify no short circuits in sew traces or alligator clips.
- **Sensor section seems random**
  - If nothing is wired to `A3`, it will float; either wire a sensor
    as described or toggle the interactive mode off with the button.

---

Enjoy hacking on the LilyPad USB Plus and turning wearables into
fun, classroom-ready light shows!
