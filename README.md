# Ender 3 Pro Firmware - FIXED VERSION

> **Good news!** The blue screen problem has been fixed. This firmware should now work properly on your printer.

## What This Is

This is an automatic firmware builder for the **Ender 3 Pro** 3D printer with:
- CR Touch (auto bed leveling sensor)  
- Sprite Extruder
- Standard LCD screen with knob (not touchscreen)
- V4.2.2 motherboard (STM32F103)

## Quick Start (3 Steps)

### 1️⃣ Build the Firmware
1. Click the "**Actions**" tab at the top of this page
2. Click "**Build Marlin (robust patch)**" on the left
3. Click the "**Run workflow**" button, then click the green "**Run workflow**" again
4. Wait 2-3 minutes for the green checkmark ✓

### 2️⃣ Download the Firmware
1. Click on the completed build (the one with the green ✓)
2. Scroll to the bottom and click "**firmware-bin**" to download
3. Unzip the file - you'll find `firmware.bin` inside

### 3️⃣ Flash to Your Printer
1. Copy `firmware.bin` to a FAT32 formatted SD card
2. Turn OFF your printer
3. Insert the SD card
4. Turn ON your printer
5. Wait for it to update (10-30 seconds)
6. Done! Your printer should show the normal menu

## 📖 Detailed Instructions

- **[HOW_TO_BUILD_AND_FLASH.md](HOW_TO_BUILD_AND_FLASH.md)** - Step-by-step guide with troubleshooting
- **[WHAT_WAS_FIXED.md](WHAT_WAS_FIXED.md)** - Explanation of what was wrong and how it's fixed

## ⚠️ Important Notes

### After Flashing (Required!)
You MUST reset the printer's memory:
- **Using the menu**: Configuration → Advanced Settings → Initialize EEPROM → Store Settings
- **Using terminal**: Send `M502` then `M500`

### SD Card Tips
- Use a good quality SD card formatted as **FAT32**
- 8GB or smaller cards work best
- If it doesn't work, try a different SD card

### If You Get a Blue Screen
The fixes in this version should prevent the blue screen, but if it still happens:
1. Try a different SD card
2. Make sure the file is named exactly `firmware.bin` (lowercase)
3. Try renaming it to `FIRMWARE.CUR`
4. Create an issue and I'll help you

## What Was Fixed

The previous version had a bug where important advanced settings weren't being applied during the build. This caused:
- Blue screen on startup
- Display not working
- Bed leveling mesh not loading automatically

All of these issues are now fixed. See [WHAT_WAS_FIXED.md](WHAT_WAS_FIXED.md) for details.

## Need Help?

Create an issue in this repository and describe:
1. What step you're on
2. What you see on the printer screen  
3. Any error messages

I'll help you get it working!

## Credits

- Marlin Firmware: https://github.com/MarlinFirmware/Marlin
- Configuration optimized for Ender 3 Pro with CR Touch and Sprite Extruder
