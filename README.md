# Ender 3 Pro Firmware - CR Touch & Sprite Extruder

Custom Marlin firmware configuration for **Ender 3 Pro** with:
- **CR Touch** auto bed leveling
- **Sprite Extruder** (direct drive)
- **V4.2.2/V4.2.7 board** (STM32F103)

---

## 🆘 HAVING PROBLEMS?

### Blue Screen or Boot Failure?
**👉 [TROUBLESHOOTING.md](TROUBLESHOOTING.md) - START HERE!**

Your printer is almost certainly NOT ruined. See the troubleshooting guide for immediate recovery steps.

### First Time Flashing?
**👉 [SIMPLE_GUIDE.md](SIMPLE_GUIDE.md) - Complete step-by-step guide**

### Need a Quick Checklist?
**👉 [FLASHING_CHECKLIST.md](FLASHING_CHECKLIST.md) - Print-friendly checklist**

---

## 📚 Documentation Overview

| Document | When to Use |
|----------|-------------|
| **[TROUBLESHOOTING.md](TROUBLESHOOTING.md)** | Blue screen, boot failure, or any flashing problems |
| **[SIMPLE_GUIDE.md](SIMPLE_GUIDE.md)** | First time setup - complete walkthrough |
| **[FLASHING_CHECKLIST.md](FLASHING_CHECKLIST.md)** | Quick reference before flashing |
| **[README_Version3.md](README_Version3.md)** | Technical details and configuration info |

---

## ⚡ Quick Start (For Experienced Users)

1. **Build firmware**: Go to Actions → "Build Marlin (robust patch)" → Run workflow (select `main` branch)
2. **Download**: Wait for build to complete → Download artifact → Extract .zip
3. **Flash**: Copy `firmware.bin` to FAT32 SD card (8GB or less) → Insert in printer → Power on
4. **Initialize**: Run `M502` then `M500` to load defaults
5. **Calibrate**: Run `G28`, then `G29`, then `M500` to save bed mesh

**⚠️ CRITICAL**: 
- SD card must be **8GB or smaller** and **FAT32** formatted
- File must be named **`firmware.bin`** (lowercase) in the root
- Wait **60-90 seconds** after power-on for flashing to complete

---

## 🛠️ What's Included

This repository contains:
- Pre-configured `Configuration.h` and `Configuration_adv.h` for Marlin
- GitHub Actions workflow to build firmware automatically (no local tools needed)
- Comprehensive documentation and troubleshooting guides

### Features Enabled
- ✅ BLTouch/CR Touch auto bed leveling (3x3 grid)
- ✅ Bilinear bed leveling with mesh save/restore
- ✅ Sprite extruder E-steps (424.9) - calibrate after first flash
- ✅ 12864 LCD controller (knob-based, non-touch)
- ✅ EEPROM settings storage
- ✅ Z-safe homing
- ✅ Bed leveling fade height support

### Configuration Notes
- **Motherboard**: BOARD_CREALITY_V422 (compatible with both V4.2.2 and V4.2.7 boards)
- **Marlin Version**: bugfix-2.1.x branch (latest stable)
- **Build Environment**: STM32F103RE_creality
- **Probe Offset**: Placeholder values - **MUST calibrate** after flashing

---

## 📖 Detailed Instructions

### First Time Setup

If this is your first time flashing custom firmware, **read [SIMPLE_GUIDE.md](SIMPLE_GUIDE.md)** for complete step-by-step instructions including:
- How to run the GitHub Actions workflow
- Where to download the firmware
- How to format your SD card properly
- How to flash the firmware safely
- Post-flash configuration steps

### Troubleshooting

If you encounter any problems (especially blue screen or boot failures), **read [TROUBLESHOOTING.md](TROUBLESHOOTING.md)** which covers:
- Blue screen recovery (most common issue)
- SD card compatibility and formatting
- File naming requirements
- Alternative flashing methods
- Bootloader recovery
- When and how to get help

### Before Each Flash

Use **[FLASHING_CHECKLIST.md](FLASHING_CHECKLIST.md)** as a pre-flight checklist to avoid common mistakes.

---

## 🔧 Post-Flash Configuration

After successfully flashing firmware, you MUST run these commands:

### 1. Initialize EEPROM
```gcode
M502  ; Load factory defaults
M500  ; Save to EEPROM
```

### 2. Calibrate Z-Offset
```gcode
G28   ; Home all axes
; Use paper method to find Z-offset, then:
M851 Z-X.XX  ; Set your measured Z-offset (e.g., -1.85)
M500  ; Save to EEPROM
```

### 3. Create Bed Mesh
```gcode
G28   ; Home all axes
G29   ; Run auto bed leveling
M500  ; Save mesh to EEPROM
```

### 4. Calibrate E-Steps (Recommended)
The firmware sets E-steps to 424.9 (Sprite factory default), but you should calibrate:

1. Heat nozzle to printing temperature
2. Mark filament 120mm above extruder entry
3. Run: `G92 E0` then `G1 E100 F100`
4. Measure actual extrusion
5. Calculate: New E-steps = 424.9 × (100 / actual_mm)
6. Set: `M92 E[new_value]` then `M500`

---

## 🎯 Slicer Start G-Code

Add this to your slicer's start G-code to use the saved bed mesh:

```gcode
G28        ; Home all axes
M420 S1    ; Enable saved bed leveling mesh
; ... rest of your start code ...
```

---

## ⚠️ Important Warnings

### Probe Offset
The `NOZZLE_TO_PROBE_OFFSET` in the firmware is a **placeholder**. You MUST:
- Measure your actual probe offset (X, Y, Z) for your specific installation
- Set it using `M851 X## Y## Z##` command
- Save with `M500`

### Board Compatibility
This firmware is **ONLY** for:
- ✅ Ender 3 Pro V4.2.2 board (STM32F103)
- ✅ Ender 3 Pro V4.2.7 board (STM32F103)

**NOT compatible with:**
- ❌ V4.3.1 or newer (different chip)
- ❌ V1.1.x boards (much older)
- ❌ Other Creality printers without verification

Check your board version before flashing! (Remove bottom cover to see board label)

---

## 🤝 Getting Help

### If Something Goes Wrong

1. **Check documentation first**:
   - [TROUBLESHOOTING.md](TROUBLESHOOTING.md) for blue screen / boot issues
   - [SIMPLE_GUIDE.md](SIMPLE_GUIDE.md) for step-by-step instructions

2. **Create a GitHub Issue** with:
   - Your board version (V4.2.2, V4.2.7, etc.)
   - Exact description of the problem
   - What you see on the screen
   - SD card details (size, format)
   - What you've already tried

3. **Be patient**: This is a community project. Response time varies.

### Common Solutions

**90% of problems are solved by:**
1. Using a different SD card (8GB or smaller, FAT32)
2. Checking filename is exactly `firmware.bin` (lowercase)
3. Waiting longer (up to 2 minutes) during flashing
4. Reformatting the SD card properly

---

## 📄 License

This configuration is provided as-is for the Ender 3 Pro community. Marlin firmware itself is licensed under GPL v3.

---

## 🙏 Credits

- **Marlin Firmware**: https://github.com/MarlinFirmware/Marlin
- **Community contributors** who helped test and improve this configuration

---

**Ready to flash?** Choose your path:
- 🆕 First time: [SIMPLE_GUIDE.md](SIMPLE_GUIDE.md)
- ⚡ Experienced: Use the Quick Start above
- 🆘 Problems: [TROUBLESHOOTING.md](TROUBLESHOOTING.md)
