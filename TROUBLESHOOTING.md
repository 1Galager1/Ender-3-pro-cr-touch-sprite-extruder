# 🆘 PRINTER BLUE SCREEN / BOOT FAILURE TROUBLESHOOTING

## ✅ DON'T PANIC - Your Printer is NOT Ruined!

If you're seeing a blue screen after trying to flash firmware, **this is a common issue and your printer is almost certainly fine**. The blue screen usually means the firmware didn't flash at all, so your printer is still running the old firmware (or no firmware loaded yet).

---

## 🔍 Understanding What Happened

When you see a **blue screen** and nothing happens:
- ✅ **Good news**: Your printer's hardware is fine
- ✅ **Good news**: The bootloader is still intact
- ⚠️ **The issue**: The firmware file didn't flash properly

**Common causes:**
1. Wrong firmware file for your board version
2. SD card compatibility issues
3. File naming requirements not met
4. SD card not properly formatted
5. Corrupt firmware file download

---

## 🚑 IMMEDIATE RECOVERY STEPS (Try These First)

### Step 1: Power Cycle the Printer Properly

1. **Turn OFF the printer** (use the power switch)
2. **Remove the SD card**
3. **Wait 30 seconds** (this clears the bootloader state)
4. **Turn ON the printer WITHOUT the SD card**
   - If you see the normal Creality/Marlin screen → Your printer is fine! The firmware just didn't flash.
   - If you still see blue screen → Continue to Step 2

### Step 2: Try a Different SD Card

**SD Card Requirements:**
- ✅ **Size**: 8GB or SMALLER (many printers can't read larger cards)
- ✅ **Format**: FAT32 (NOT exFAT, NOT NTFS)
- ✅ **Speed**: Class 4 or Class 10 (avoid ultra-high-speed cards)
- ✅ **Condition**: Use a NEW or known-working card

**How to format the SD card properly:**

**On Windows:**
1. Insert SD card into your computer
2. Open "This PC" or "My Computer"
3. Right-click on the SD card drive
4. Select "Format..."
5. Set:
   - File system: **FAT32** (if you don't see FAT32, see note below)
   - Allocation unit size: **4096 bytes** or **Default**
   - Volume label: (anything you want)
   - Quick Format: **Checked**
6. Click "Start"

**Note**: Windows doesn't show FAT32 for drives over 32GB. If you have a larger card:
- Use a tool like "FAT32 Format" (free download) OR
- Use a smaller SD card (8GB recommended)

**On Mac:**
1. Insert SD card
2. Open "Disk Utility" (Applications → Utilities)
3. Select your SD card from the left sidebar
4. Click "Erase"
5. Set:
   - Format: **MS-DOS (FAT)**
   - Scheme: **Master Boot Record**
6. Click "Erase"

### Step 3: Check the Firmware File

**Critical file naming requirements:**
- ✅ Filename MUST be: `firmware.bin` (all lowercase)
- ✅ File must be in the ROOT of the SD card (NOT in a folder)
- ✅ It must be the ONLY .bin file on the card
- ✅ The file should be 60-120 KB for STM32F103 boards (V4.2.2/V4.2.7). If it's much smaller (under 50KB) or suspiciously large (over 200KB), it might be wrong

**Common mistakes:**
- ❌ `Firmware.bin` (capital F - won't work on some printers)
- ❌ `firmware.bin.bin` (double extension - Windows hides file extensions by default)
- ❌ `firmware (1).bin` (Windows adds this if you downloaded twice)
- ❌ File is in a folder on the SD card

**How to check for hidden file extensions (Windows):**
1. Open File Explorer
2. Click the "View" tab
3. Check the box "File name extensions"
4. Now you can see the real filename

### Step 4: Verify You Downloaded the Correct File

**Where to get the firmware:**
1. Go to this GitHub repository (the one you're viewing this document in)
2. Click "Actions" tab
3. Click on the most recent successful build (green checkmark ✅)
4. Scroll down to "Artifacts"
5. Download "firmware-bin"
6. **Unzip the downloaded file**
7. Inside, find `firmware.bin` - this is your file

**Common mistake**: Putting the .zip file on the SD card instead of extracting it first!

### Step 5: Flash the Firmware (The Right Way)

1. ✅ **Format SD card as FAT32** (Step 2 above)
2. ✅ **Copy ONLY the firmware.bin file to the root** of the SD card
3. ✅ **Safely eject** the SD card from your computer
4. ✅ **Printer must be OFF** before inserting the card
5. ✅ **Insert the SD card** into the printer
6. ✅ **Turn ON the printer**
7. ⏳ **Wait and watch**:
   - You might see a blank/blue screen for 5-10 seconds - **this is normal**
   - The screen might flash or show a progress bar
   - After 10-30 seconds, you should see the Marlin boot screen
   - If nothing happens after 1 minute → Try the advanced recovery below

8. ✅ **Turn OFF printer and remove SD card**
9. ✅ **Turn ON printer again** to verify it works

---

## 🔧 ADVANCED RECOVERY (If Basic Steps Didn't Work)

### Option A: Try Alternate Firmware Filenames

Some Ender 3 Pro boards are picky about filenames. Try these in order:

1. **Try**: `firmware.bin` (lowercase - try this first)
2. **Try**: `FIRMWARE.CUR` (all caps with .CUR extension)
3. **Try**: `firmware.bin` but check that your SD card doesn't already have a `FIRMWARE.CUR` file on it from a previous flash (delete it if it does)

⚠️ **IMPORTANT - Do NOT rename to firmware1.bin or similar!**
- The bootloader ONLY recognizes specific filenames: `firmware.bin` or `FIRMWARE.CUR`
- Names like `firmware1.bin`, `firmware2.bin`, `fw.bin`, etc. will NOT work
- If your first flash attempt failed, you must:
  1. Delete the old `firmware.bin` from the SD card
  2. Copy a fresh `firmware.bin` file (same name) to try again
  3. The bootloader looks for the exact filename, not a numbered version

### Option B: Verify Your Board Version

**CRITICAL**: This firmware is built for **V4.2.2 or V4.2.7 boards with STM32F103 chip**.

**How to check your board version:**
1. Remove the printer's bottom cover (4 screws)
2. Look at the mainboard - it should say "V4.2.2" or "V4.2.7" on the board
3. If it says something different (like V4.3.1 or V1.1.5), **STOP** - you need different firmware

**If you have a different board:**
- V4.3.1 or newer: Uses STM32G0 or GD32F303 chip (different build environment needed)
- V1.1.x: Much older board (ATmega-based, completely different firmware)

### Option C: Download Pre-Built Firmware from Creality

If the custom firmware isn't working, you can recover with stock Creality firmware:

1. Go to: https://www.creality.com/pages/download-ender-3-pro
2. Download the firmware for your specific board version
3. Follow the same flashing steps above
4. This will restore your printer to stock settings

⚠️ **Note**: Stock firmware won't have your CR Touch or Sprite extruder configured - you'll need to reconfigure afterward.

### Option D: Flash via USB (Advanced)

If SD card flashing completely fails, you can flash via USB:

**What you need:**
- USB cable (printer to computer)
- Software: Cura, Pronterface, or OctoPrint
- The firmware.hex file (from the same GitHub Actions artifact)

**Steps:**
1. Download STM32CubeProgrammer or use PlatformIO
2. Connect printer to computer via USB
3. Put printer in DFU mode (this varies by board - may need to hold reset button)
4. Use the programmer to flash the .hex file

⚠️ **This is advanced** - only try if you're comfortable with these tools or have someone who can help.

---

## 📋 PREVENTION CHECKLIST (For Next Time)

Before flashing firmware, verify:

- [ ] **Board version matches** (V4.2.2 or V4.2.7 for this firmware)
- [ ] **SD card is 8GB or smaller**
- [ ] **SD card is formatted as FAT32**
- [ ] **Firmware file is named exactly** `firmware.bin` (lowercase)
- [ ] **Firmware file is in the root** of the SD card (not in a folder)
- [ ] **Only ONE .bin file** is on the SD card
- [ ] **SD card is empty** except for firmware.bin
- [ ] **You unzipped the downloaded file** (not copying the .zip)
- [ ] **Printer is OFF** before inserting SD card
- [ ] **Wait at least 60 seconds** after power-on before assuming failure

---

## ❓ FAQ - Common Questions

### Q: How long should flashing take?
**A**: Usually 10-30 seconds. The screen might be blank/blue during this time. If nothing happens after 60-90 seconds, something is wrong.

### Q: Will this damage my printer?
**A**: No. If the firmware doesn't flash, the bootloader simply ignores it and boots the old firmware. The worst case is you need to reflash stock firmware.

### Q: The firmware flashed, but now my printer behaves weird. What do I do?
**A**: After flashing new firmware, you MUST run these commands (via USB terminal or LCD menu):
1. `M502` - Load factory defaults
2. `M500` - Save to EEPROM
3. Then configure your settings (Z-offset, bed leveling, etc.)

### Q: My SD card slot is broken - can I still update?
**A**: Yes! Use the USB flashing method (Option D above) or get an SD card extender/adapter.

### Q: If the flash failed, should I rename the file to firmware1.bin for the next try?
**A**: **NO!** The bootloader only recognizes `firmware.bin` or `FIRMWARE.CUR` - it will ignore files named firmware1.bin, firmware2.bin, etc. If your flash attempt failed:
1. Delete the old firmware.bin from the SD card
2. Copy a fresh firmware.bin file (same exact name)
3. Try flashing again with the same filename

The bootloader doesn't track previous attempts - it just looks for the specific filename each time you boot.

### Q: I'm still stuck. What should I do?
**A**: Create a GitHub Issue in this repository with:
- Your board version (found on the mainboard)
- Exactly what you see on the screen
- What SD card you're using (size, brand)
- Whether you've successfully flashed firmware before

---

## 🎯 Most Common Solution

**90% of blue screen issues are solved by:**

1. Using a **different SD card** (8GB or smaller, FAT32)
2. Making absolutely sure the filename is `firmware.bin` (lowercase, no double extension)
3. **Waiting longer** (up to 2 minutes) - some printers are just slow

**Try these three things first before anything else!**

---

## 📞 Getting Help

If you're still stuck after trying all the steps above:

1. **Create a GitHub Issue**: Go to the "Issues" tab in this repository
2. **Include this information**:
   - Your mainboard version (V4.2.2, V4.2.7, etc.)
   - What you see on the screen (blue screen, black screen, error message, etc.)
   - SD card details (size, how you formatted it)
   - The exact filename you used
   - Whether the printer ever worked before
   - What you've already tried from this guide

Remember: **Hundreds of people have recovered from this exact situation. You will too!** 🚀
