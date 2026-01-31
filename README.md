# Ender 3 Pro Firmware - V4.2.2 Board + CR Touch + Sprite Pro + 12864 Screen

This repository contains pre-configured Marlin firmware for:
- **Printer:** Ender 3 Pro
- **Board:** V4.2.2 (STM32F103RET6)
- **Probe:** CR Touch (BLTouch compatible)
- **Extruder:** Sprite Pro (E-steps: 424.9)
- **Display:** 12864 LCD with knob/encoder

## 🎯 Quick Start - Get Your Firmware Bin File

### Option 1: Build Firmware Using GitHub Actions (Recommended)

1. **Go to the Actions Tab**
   - Click on the ["Actions"](../../actions) tab at the top of this repository

2. **Select the Build Workflow**
   - On the left sidebar, click "Build Marlin (robust patch)"

3. **Run the Workflow**
   - Click the "Run workflow" button (top right)
   - Select branch: **main**
   - Click the green "Run workflow" button

4. **Wait for Build to Complete**
   - The build takes about 5-15 minutes
   - Wait for the green checkmark ✅

5. **Download Your Firmware**
   - Click on the completed workflow run
   - Scroll to the bottom to find "Artifacts"
   - Download the "firmware-bin" artifact (it's a .zip file)
   - Extract the zip to find `firmware.bin`

### Option 2: Download Pre-built Firmware (If Available)

Check the [Releases](../../releases) page for pre-built firmware binaries.

## 📥 Flashing the Firmware

1. **Prepare SD Card**
   - Format a microSD card as FAT32
   - Copy `firmware.bin` to the root of the SD card
   - Ensure the file is named `firmware.bin` (lowercase)

2. **Flash to Printer**
   - Power off your printer
   - Insert the SD card
   - Power on the printer
   - The screen will go blank during flashing (10-30 seconds)
   - Printer will reboot automatically when done

3. **Remove SD Card**
   - Power off the printer
   - Remove the SD card
   - Power on again

## ⚙️ First-Time Setup After Flashing

Send these commands via terminal (OctoPrint, Pronterface, etc.) or use the printer menu:

```gcode
M502          ; Restore defaults
M500          ; Save to EEPROM
G28           ; Home all axes
G29           ; Create bed mesh (heat bed to 60°C first)
M500          ; Save mesh
M92 E424.9    ; Set Sprite Pro E-steps
M500          ; Save E-steps
```

### Set Z-Offset

The probe offset in the firmware is a placeholder. You MUST calibrate your Z-offset:

1. Home the printer: `G28`
2. Use paper method to find correct Z-offset
3. Set the offset: `M851 Z-X.XX` (replace X.XX with your value, e.g., -1.85)
4. Save: `M500`

## 📝 Configuration Details

- **Marlin Version:** bugfix-2.1.x
- **Auto Bed Leveling:** Bilinear (3x3 grid)
- **Probe Offset:** { -44, -9, 0 } (X, Y, Z) - **MUST BE CALIBRATED**
- **Steps/mm:** X=80, Y=80, Z=400, E=424.9
- **Features Enabled:**
  - BLTouch/CR Touch
  - EEPROM settings (M500/M501)
  - Z Safe Homing
  - Restore leveling after G28
  - 12864 LCD Controller

## 📚 Additional Documentation

- [README_Version3.md](README_Version3.md) - Detailed cloud build instructions
- [SIMPLE_GUIDE.md](SIMPLE_GUIDE.md) - Step-by-step guide for beginners

## ⚠️ Important Notes

1. **Probe Offset:** The Z-offset value in the firmware is a placeholder. You MUST measure and set your specific offset after flashing.

2. **E-Steps Calibration:** The default E-steps (424.9) is the Sprite Pro factory value. For best results, calibrate using the standard extrusion test:
   - Heat nozzle to printing temperature
   - Mark filament 120mm above extruder
   - Extrude 100mm: `G1 E100 F100`
   - Measure actual extrusion
   - Calculate new E-steps: `New = 424.9 × (100 / actual_mm)`
   - Set with `M92 E[new_value]` and save with `M500`

3. **Start G-code:** Add this to your slicer's start G-code to use the saved mesh:
   ```gcode
   G28           ; Home
   M420 S1       ; Restore saved bed mesh
   ```

## 🔧 Customization

If you need to modify the configuration:
1. Edit `Configuration_Version3.h` and/or `Configuration_adv_Version3.h`
2. Commit and push changes
3. Run the GitHub Actions workflow again

## 📖 Troubleshooting

**Firmware won't flash:**
- Ensure SD card is FAT32 formatted (not exFAT)
- Try a different SD card (8GB or smaller works best)
- Ensure filename is exactly `firmware.bin`

**Printer won't boot after flash:**
- Power cycle the printer
- If still not working, reflash with a known working firmware

**Build fails in GitHub Actions:**
- Check the Actions logs for errors
- Ensure Configuration files are valid
- Create an issue with the error details

## 📄 License

This configuration is based on Marlin Firmware. See Marlin's license for details.

---

**Need help?** Create an [issue](../../issues) or refer to the detailed guides in this repository.
