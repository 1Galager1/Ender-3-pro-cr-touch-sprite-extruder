# ✅ Firmware Flashing Checklist

Use this checklist BEFORE you flash firmware to avoid common problems.

## 📋 Pre-Flight Checklist

### SD Card Preparation
- [ ] SD card is **8GB or SMALLER** (not 16GB, 32GB, etc.)
- [ ] SD card is formatted as **FAT32** (not exFAT, not NTFS)
- [ ] SD card is completely empty (delete old firmware files if present)
- [ ] SD card is working and not corrupted (test by copying other files to it)

### Firmware File Preparation
- [ ] Downloaded the firmware from GitHub Actions → Artifacts
- [ ] **Extracted the .zip file** (don't copy the .zip itself!)
- [ ] Found the `firmware.bin` file inside the extracted folder
- [ ] Renamed the file to exactly **`firmware.bin`** (all lowercase)
- [ ] Verified there's no double extension like `firmware.bin.bin`
  - Windows Tip: In File Explorer → View tab → Check "File name extensions"
- [ ] File size is reasonable (200-300 KB is normal)

### Copying to SD Card
- [ ] Copied `firmware.bin` to the **ROOT** of the SD card (not in a folder)
- [ ] Verified it's the **ONLY .bin file** on the card
- [ ] Deleted any old firmware files (like `FIRMWARE.CUR` from previous flashes)
- [ ] **Safely ejected** the SD card from your computer

### Printer Preparation
- [ ] Printer is **POWERED OFF** completely
- [ ] SD card is inserted into the printer's SD card slot
- [ ] You're prepared to wait **60-90 seconds** after power-on

## 🚀 Flashing Process

1. [ ] Insert SD card into powered-off printer
2. [ ] Turn on the printer
3. [ ] Watch the screen:
   - Blank/blue screen for 5-10 seconds is **NORMAL**
   - Wait at least 60-90 seconds before assuming failure
4. [ ] Look for signs of success:
   - [ ] Screen shows Marlin boot screen
   - [ ] Printer boots to main menu
   - [ ] SD card LED may flash during update
5. [ ] After successful boot:
   - [ ] Turn off printer
   - [ ] Remove SD card
   - [ ] Turn on printer again to verify

## ⚠️ If Something Goes Wrong

**Blue screen lasting more than 2 minutes?**
→ See [TROUBLESHOOTING.md](TROUBLESHOOTING.md)

**Most common fixes (try these first):**
1. Use a different SD card (8GB or smaller)
2. Reformat the card as FAT32
3. Check the filename is exactly `firmware.bin` (lowercase)
4. Make sure you extracted the .zip file first
5. Wait longer (some printers take 90+ seconds)

## ✨ After Successful Flashing

Don't forget these important post-flash steps:

- [ ] Initialize EEPROM with `M502` then `M500`
- [ ] Home all axes with `G28`
- [ ] Run auto bed leveling with `G29` then save with `M500`
- [ ] Set your Z-offset with `M851 Z-X.XX` then save with `M500`
- [ ] Do a test print to verify everything works

## 📱 Quick Reference

| What | Requirement |
|------|-------------|
| SD Card Size | **8GB or smaller** |
| Format | **FAT32** |
| Filename | **firmware.bin** (lowercase) |
| Location | **Root of SD card** (not in a folder) |
| Flash Time | 10-90 seconds (wait patiently!) |

---

**Need more help?** See [TROUBLESHOOTING.md](TROUBLESHOOTING.md) for detailed recovery instructions.

**First time flashing?** See [SIMPLE_GUIDE.md](SIMPLE_GUIDE.md) for step-by-step instructions.
