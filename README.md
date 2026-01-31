# Ender 3 Pro Firmware - CR Touch + Sprite Extruder

**✅ YES! Pre-built firmware (.bin files) are available for download!**

## ⚠️ CRITICAL WARNING: Check Your Board Chip FIRST!

**BEFORE downloading firmware, you MUST verify your motherboard chip type!**

V4.2.2 boards come with **TWO different chips**:
- **STM32F103** ← This firmware works ONLY with this chip
- **GD32F303** ← This firmware will NOT work and causes blue screen!

**👉 [Read TROUBLESHOOTING.md](TROUBLESHOOTING.md) to identify your chip and get the right firmware!**

If you flash the wrong firmware, your printer will show a **blue screen and won't boot**. This is NOT permanent damage - you just need the correct firmware for your chip.

---

This repository provides ready-to-use firmware for the **Ender 3 Pro** with:
- **Motherboard:** Creality V4.2.2 with **STM32F103 chip only**
- **Probe:** CR Touch (BLTouch compatible)
- **Extruder:** Sprite Extruder Direct Drive
- **Display:** Stock 12864 LCD (knob-based, non-touch)
- **Auto Bed Leveling:** Enabled with 3x3 bilinear grid
- **E-steps:** Pre-configured for Sprite (424.9)

## 🆘 Firmware Not Working? Blue Screen?

**If your printer shows a blue screen or won't boot after flashing:**

👉 **[READ THE TROUBLESHOOTING GUIDE](TROUBLESHOOTING.md)** 👈

Common issues:
- ❌ Wrong chip type (GD32 vs STM32) - **MOST COMMON!**
- ❌ Same filename used twice (printer won't reflash same name)
- ❌ SD card compatibility issues
- ❌ Not waiting long enough during flash

**Alternative firmware repositories** with the same configuration are also listed in the troubleshooting guide!

## 🎯 Quick Start: Download Pre-Built Firmware

### Option 1: Download from GitHub Actions (Latest Build)

**This is the easiest way to get the latest pre-compiled firmware!**

1. **Go to the Actions tab:**
   - Visit: https://github.com/1Galager1/Ender-3-pro-cr-touch-sprite-extruder/actions
   - Or click "Actions" at the top of this repository page

2. **Find the latest successful build:**
   - Look for the most recent workflow run with a **✅ green checkmark**
   - The workflow is called "Build Marlin (robust patch)"
   - Click on it to open the build details

3. **Download the firmware:**
   - Scroll to the bottom of the page to the "Artifacts" section
   - Click on **"firmware-bin"** to download a .zip file
   - Extract the .zip file on your computer
   - Inside you'll find **firmware.bin** - this is your pre-compiled firmware!

4. **Flash to your printer:**
   - Copy `firmware.bin` to a blank FAT32-formatted microSD card (8GB or smaller, root directory)
   - **IMPORTANT:** If you've flashed before, **rename the file** to something unique (e.g., `firmware1.bin`, `firmware_jan31.bin`) - the printer won't reflash the same filename!
   - Power off your printer
   - Insert the SD card into the printer
   - Power on the printer
   - **Wait at least 60 seconds** while it flashes (screen may go blank - this is NORMAL)
   - When complete, the printer will reboot with the new firmware
   - Remove the SD card and reboot again

**⚠️ If you get a blue screen or printer won't boot:** See [TROUBLESHOOTING.md](TROUBLESHOOTING.md)

**Download Link:** [Latest Firmware Artifacts](https://github.com/1Galager1/Ender-3-pro-cr-touch-sprite-extruder/actions/workflows/build.yml)

### Option 2: Build Your Own (Advanced)

If you want to customize settings or build from source:

1. Fork this repository
2. Go to Actions → "Build Marlin (robust patch)" → "Run workflow"
3. Select branch: **main**
4. Click "Run workflow"
5. Wait for the build to complete (5-15 minutes)
6. Download the artifact as described above

For detailed build instructions, see: [README_Version3.md](README_Version3.md)

## ⚙️ Post-Flash Setup (Important!)

After flashing the firmware for the first time:

1. **Reset to defaults:**
   ```
   M502
   M500
   ```

2. **Home all axes:**
   ```
   G28
   ```

3. **Create bed mesh (one-time setup):**
   - Preheat bed to 60°C
   - Run bed leveling:
     ```
     G29
     M500
     ```

4. **Set Z-offset (adjust as needed):**
   ```
   M851 Z-1.85
   M500
   ```
   Use paper method to find your ideal Z-offset

5. **Add to your slicer start G-code:**
   ```
   G28        ; Home all axes
   M420 S1    ; Restore saved bed mesh
   ```

6. **Optional: Calibrate E-steps**
   - The firmware is pre-configured with E-steps of 424.9 for the Sprite extruder
   - For best results, calibrate using the 100mm extrusion test
   - See [README_Version3.md](README_Version3.md#extruder-calibration-recommended-after-the-factory-setting) for detailed instructions

## 📋 What's Included in This Firmware

- ✅ Marlin bugfix-2.1.x (latest stable)
- ✅ CR Touch / BLTouch support
- ✅ Auto bed leveling (bilinear 3x3 grid)
- ✅ Sprite extruder E-steps (424.9)
- ✅ EEPROM settings storage
- ✅ Z-safe homing
- ✅ Fade height support (use `M420 Z10` to enable)
- ✅ Stock Creality 12864 LCD support
- ✅ Optimized for Creality V4.2.2 board

## ⚠️ Important Notes

1. **Probe Offset:** The default probe offset is a placeholder. You MUST measure your actual probe offset and adjust it using `M851 X<x> Y<y> Z<z>` followed by `M500` to save.

2. **Compatibility:** This firmware is specifically for:
   - Ender 3 Pro with Creality V4.2.2 motherboard (STM32F103 chip)
   - CR Touch or BLTouch probe
   - Sprite extruder direct drive
   - Stock 12864 LCD display

3. **SD Card:** Use an 8GB or smaller microSD card formatted as FAT32 for best compatibility when flashing.

## 🆘 Troubleshooting

**Firmware won't flash:**
- Try a different SD card (8GB or smaller, FAT32 format)
- Ensure the file is named exactly `firmware.bin` (lowercase)
- Try renaming to `FIRMWARE.CUR` if `firmware.bin` doesn't work

**Printer won't boot after flash:**
- The screen might stay blank for 30-60 seconds on first boot - be patient
- If it doesn't boot after 2 minutes, reflash with a different SD card

**Need help?**
- Create an issue in this repository
- Include details about your printer configuration and what went wrong

## 📚 Additional Documentation

- [README_Version3.md](README_Version3.md) - Detailed build instructions and technical details
- [SIMPLE_GUIDE.md](SIMPLE_GUIDE.md) - Step-by-step guide for beginners
- [Configuration_Version3.h](Configuration_Version3.h) - Main configuration file
- [Configuration_adv_Version3.h](Configuration_adv_Version3.h) - Advanced configuration

## 🤝 Credits

This firmware configuration is based on Marlin Firmware with customizations for the Ender 3 Pro with CR Touch and Sprite Extruder setup.

## 📝 License

This repository contains configuration files for Marlin Firmware. Marlin is licensed under GPLv3. See the [Marlin repository](https://github.com/MarlinFirmware/Marlin) for more information.
