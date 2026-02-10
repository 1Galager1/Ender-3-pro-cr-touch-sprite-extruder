# BLUE SCREEN FIX GUIDE - Ender 3 Pro V4.2.2

## If You're Seeing a Blue Screen After Flashing Firmware

Don't panic! This is a common issue and usually easy to fix. Follow these steps in order:

## Step 1: Verify Your SD Card

The **#1 cause** of blue screens is SD card issues.

### SD Card Checklist:
- [ ] SD card is formatted as **FAT32** (not exFAT or NTFS)
- [ ] SD card is 32GB or smaller (larger cards often cause issues)
- [ ] Firmware file is named **exactly** `firmware.bin` (all lowercase)
- [ ] `firmware.bin` is in the **root** of the SD card (not in a folder)
- [ ] SD card is clean (delete any old `.CUR` files)

### How to Fix SD Card Issues:

1. **Reformat your SD card:**
   - On Windows: Right-click SD card → Format → File System: FAT32
   - On Mac: Disk Utility → Erase → MS-DOS (FAT)
   - On Linux: `sudo mkfs.vfat -F 32 /dev/sdX1` (replace sdX1 with your card)

2. **Try a different SD card** if possible (preferably 8GB or 16GB)

3. **Copy firmware.bin to the card:**
   - Download the `firmware.bin` from GitHub Actions artifacts
   - Copy it to the root of the SD card
   - Verify the filename is exactly `firmware.bin`

## Step 2: Proper Flashing Procedure

1. **Power OFF** the printer completely
2. **Remove** the SD card from the printer
3. **Insert** the SD card with `firmware.bin` into your computer
4. **Verify** the file is there and named correctly
5. **Safely eject** the SD card
6. **Insert** the SD card into the printer (while still powered off)
7. **Power ON** the printer
8. **Wait** 30-60 seconds - you should hear beeping or see the screen flicker
9. The screen should show the Marlin boot screen, then the main menu

## Step 3: Initialize EEPROM (CRITICAL!)

After the first successful flash, you **MUST** initialize the EEPROM:

### Using the LCD Menu:
1. Navigate to: **Configuration** → **Initialize EEPROM**
2. Confirm the action
3. Wait for "EEPROM Initialized" message
4. Navigate to: **Configuration** → **Store Settings**

### Using G-code Terminal (Pronterface, OctoPrint, or Cura):
```gcode
M502    ; Reset to factory defaults
M500    ; Save settings to EEPROM
```

**This step is CRITICAL!** Old EEPROM settings from different firmware can cause crashes.

## Step 4: Alternative Flashing Methods

If the SD card method isn't working:

### Method A: Try Different Filename
Some boards need a different filename:
- Try: `FIRMWARE.CUR` (all uppercase)
- Try: `firmware.cur` (all lowercase)

### Method B: Use a Slower SD Card
Faster SD cards (Class 10, UHS-I) sometimes fail. Try an older, slower card.

### Method C: Format with Different Tools
- Windows: Try the official [SD Card Formatter](https://www.sdcard.org/downloads/formatter/)
- Mac/Linux: Use `dd` to zero the card first, then format

## Step 5: Verify Your Hardware

Make sure your printer actually has:
- [ ] **V4.2.2 board** (not V4.2.7 or other version)
  - Check the board: Remove the bottom panel, look at the motherboard label
- [ ] **12864 knob display** (not a touchscreen)
  - The display should have a rotary knob, not a touchscreen
- [ ] **CR Touch** properly connected

## Step 6: Build a Fresh Firmware

If you're still having issues, try building fresh firmware:

1. Go to your GitHub repository
2. Click **Actions** tab
3. Click **Build Marlin (robust patch)** workflow
4. Click **Run workflow** → **Run workflow**
5. Wait for the build to complete (green checkmark)
6. Download the **firmware-bin** artifact
7. Extract `firmware.bin` and flash it using the steps above

## Step 7: Emergency Recovery

If nothing works, you may need to:

1. **Try USB flashing** using STM32CubeProgrammer (advanced)
2. **Check for hardware damage** (bad display cable, loose connections)
3. **Restore original Creality firmware** to test if it's a hardware issue

## Common Mistakes to Avoid

❌ **Don't** leave old firmware files on the SD card  
❌ **Don't** use SD cards larger than 32GB  
❌ **Don't** skip the M502/M500 initialization step  
❌ **Don't** power off during the flash (wait for it to complete)  
❌ **Don't** use exFAT or NTFS formatted cards  

## Success Checklist

Once working, you should see:
- ✅ Marlin boot screen (with version number)
- ✅ Main menu with "Prepare", "Control", etc.
- ✅ Able to navigate with the knob
- ✅ Hear a beep on startup (if enabled)

## Still Having Issues?

If you've tried everything above and still see a blue screen:

1. **Check the Actions log** for build errors
2. **Verify board version** - you might have a different board than V4.2.2
3. **Test with original firmware** to rule out hardware issues
4. **Ask for help** - provide:
   - Exact board version (check the label on the board)
   - Display type (knob or touchscreen)
   - What you see (blue screen, blank screen, etc.)
   - Steps you've already tried

## Quick Reference Commands

After successful flash:
```gcode
M502        ; Reset to defaults
M500        ; Save to EEPROM
G28         ; Home all axes
M851 Z0     ; Reset Z offset (adjust later)
M500        ; Save again
G29         ; Create bed mesh (after bed is heated)
M500        ; Save mesh
```

---

**Need help?** Open an issue in this repository with:
- Your exact printer model
- Board version (visible on the motherboard)
- Display type
- What you see when you power on
