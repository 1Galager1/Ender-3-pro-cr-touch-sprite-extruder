# Ender 3 Pro Firmware - EMERGENCY BASIC BUILD

## 🚨 BLUE SCREEN? START HERE! 🚨

If you're seeing a **blue screen** on your printer, read **[BLUE_SCREEN_FIX.md](BLUE_SCREEN_FIX.md)** first!

## Quick Start: Get Your Printer Working NOW

This repository builds a **minimal, stable firmware** for:
- **Ender 3 Pro** with **V4.2.2 board** (STM32F103)
- **CR Touch** (BLTouch compatible)
- **Sprite Extruder** with 0.9° stepper
- **12864 knob display** (NOT touchscreen)

### Step 1: Build the Firmware (Takes 5 minutes)

1. **Go to the Actions tab** (at the top of this GitHub page)
2. **Click** on "Build Marlin (robust patch)"
3. **Click** the "Run workflow" button (on the right)
4. **Click** the green "Run workflow" button in the dropdown
5. **Wait** for the green checkmark (about 3-5 minutes)
6. **Click** on the completed build
7. **Scroll down** to "Artifacts" section
8. **Download** the "firmware-bin" file
9. **Extract** the ZIP file to get `firmware.bin`

### Step 2: Flash to Your Printer

1. **Format** an SD card as FAT32 (32GB or smaller recommended)
2. **Copy** `firmware.bin` to the root of the SD card
3. **Power OFF** the printer
4. **Insert** the SD card into the printer
5. **Power ON** the printer
6. **Wait** 30-60 seconds for flashing to complete
7. You should see the Marlin boot screen! 🎉

### Step 3: Initialize Settings (IMPORTANT!)

After the first boot, you MUST reset the EEPROM:

**Using the LCD menu:**
- Go to: Configuration → Initialize EEPROM → Confirm
- Go to: Configuration → Store Settings

**Or via USB terminal:**
```gcode
M502    ; Reset to defaults
M500    ; Save to EEPROM
```

**This step is critical!** Skip it and you may get crashes or weird behavior.

## What's Included in This Build

✅ **Basic settings** - Everything needed to boot and home  
✅ **CR Touch support** - Auto bed leveling with 3x3 grid  
✅ **Correct E-steps** - Sprite extruder factory value (424.9)  
✅ **EEPROM enabled** - Save/load settings with M500/M501  
✅ **Safety features** - Thermal runaway protection  
✅ **Minimal config** - No fancy features that could cause issues  

## What's NOT Included (For Stability)

❌ Touchscreen UI  
❌ Linear Advance (K-factor)  
❌ Arc support (G2/G3)  
❌ Input Shaping  
❌ Advanced pause features  

**These can be added later** once you confirm the basic build works!

## Post-Flash Setup

After your printer boots successfully:

### 1. Heat the bed and create a mesh:
```gcode
M190 S60    ; Heat bed to 60°C and wait
G28         ; Home all axes
G29         ; Create bed mesh
M500        ; Save mesh to EEPROM
```

### 2. Calibrate Z-offset:
```gcode
G28         ; Home
G1 Z0       ; Move to Z=0
; Use paper method to find proper Z height
M851 Z-X.XX ; Set Z offset (e.g., M851 Z-1.85)
M500        ; Save
```

### 3. (Optional) Calibrate E-steps:
The firmware uses **424.9 steps/mm** (Sprite factory default).  
To calibrate it yourself:
```gcode
M302 S0     ; Allow cold extrusion (for testing)
G92 E0      ; Reset extruder position
G1 E100 F100 ; Extrude 100mm
; Measure actual extrusion, adjust with:
M92 E424.9  ; Set new E-steps value
M500        ; Save
```

## Troubleshooting

### Blue screen / blank screen?
→ Read **[BLUE_SCREEN_FIX.md](BLUE_SCREEN_FIX.md)**

### Build failed on GitHub Actions?
→ Check the Actions log for errors  
→ Open an issue with the error details

### Printer boots but can't move/home?
→ Run `M502` then `M500` to reset EEPROM  
→ Check endstop connections  
→ Send `M119` to check endstop status

### Probe deploys but doesn't work?
→ The probe offsets are **placeholders** (-44, -9, 0)  
→ Measure your actual offsets and set with `M851`  
→ Save with `M500`

## Advanced: Customizing the Firmware

The configuration files are in the root of this repo:
- **Configuration_Version3.h** - Main settings
- **Configuration_adv_Version3.h** - Advanced settings

To modify:
1. Edit the files
2. Commit changes
3. Run the workflow again
4. Download new firmware

## Need Help?

1. **Blue screen?** → [BLUE_SCREEN_FIX.md](BLUE_SCREEN_FIX.md)
2. **Build issues?** → Check Actions logs
3. **Can't find firmware.bin?** → Make sure build succeeded (green checkmark)
4. **Still stuck?** → Open an issue with details

## Files in This Repository

- `Configuration_Version3.h` - Main Marlin configuration
- `Configuration_adv_Version3.h` - Advanced Marlin configuration  
- `.github/workflows/build.yml` - Automated build workflow
- `BLUE_SCREEN_FIX.md` - Comprehensive blue screen troubleshooting
- `README_Version3.md` - Original detailed README
- `SIMPLE_GUIDE.md` - Guide for understanding pull requests

## Important Notes

⚠️ **Probe offsets are placeholders!** Measure and update after first boot.  
⚠️ **Always run M502/M500** after first flash to prevent EEPROM issues.  
⚠️ **Use FAT32 SD cards** - exFAT won't work!  
⚠️ **Verify your board version** - This build is for V4.2.2 only!  

## Success Indicators

When everything works, you should see:
- ✅ Marlin boot screen with version number
- ✅ Main menu (Prepare, Control, Print, etc.)
- ✅ Able to navigate with the knob
- ✅ Startup beep (if enabled)
- ✅ Can home axes (G28)
- ✅ CR Touch deploys and stows

---

**First time flashing?** Follow the steps above in order.  
**Having issues?** Read BLUE_SCREEN_FIX.md thoroughly.  
**Need more details?** Check README_Version3.md for advanced info.
