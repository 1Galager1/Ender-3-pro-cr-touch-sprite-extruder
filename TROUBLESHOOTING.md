# Troubleshooting Guide

## Blue Screen Still Happening?

### Most Common Issue: Using Old Firmware
**Problem**: You downloaded firmware from the "main" branch instead of the fixed branch.

**Solution**: Build new firmware from the correct branch:
1. Go to Actions tab
2. Click "Build Marlin (robust patch)"
3. Click "Run workflow"
4. **SELECT BRANCH**: Choose **"copilot/fix-firmware-issue-ender-3-pro"** from the dropdown
5. Click the green "Run workflow" button
6. Wait for it to complete
7. Download the firmware-bin artifact from THIS build
8. Flash it to your printer

### Other Common Issues

#### SD Card Problems
**Symptoms**: Printer doesn't recognize the firmware file, nothing happens when you turn on the printer.

**Solutions**:
1. **Use a smaller SD card** - 8GB or less works best
2. **Format as FAT32** - Windows: Right-click → Format → FAT32
3. **Try a different SD card** - Some cards just don't work well with printers
4. **Rename the file**:
   - Try `FIRMWARE.CUR` instead of `firmware.bin`
   - Make sure there's no `.bin.bin` double extension (Windows sometimes hides extensions)
5. **Clean the SD card slot** - Dust can cause connection problems

#### Blue Screen That Never Goes Away
**What it means**: The firmware file is being detected, but something is preventing the printer from starting.

**What to try**:
1. **First, make sure you built from the correct branch** (see above)
2. **Remove the SD card** after 30 seconds and restart the printer
   - Sometimes the printer needs a clean restart
3. **Try a factory reset** if the printer does boot to a menu:
   - Configuration → Reset → Factory Reset
   - Then flash firmware again
4. **Clear the SD card** completely:
   - Delete ALL files from the SD card
   - Copy ONLY the new firmware.bin
   - Try flashing again

#### Printer Boots But Display Shows Garbage/Weird Characters
**Problem**: Display configuration issue.

**Solution**: This means the firmware is partially working but the display type is wrong. The fixes should have addressed this, so:
1. Make sure you built from **"copilot/fix-firmware-issue-ender-3-pro"** branch
2. The build script specifically configures for the knob LCD (not touchscreen)
3. If this still happens, reset EEPROM: Send `M502` then `M500`

#### Firmware Flashes But Settings Are Wrong
**Problem**: Old settings are conflicting with new firmware.

**Solution**: Reset EEPROM (this clears old settings):
- **Method 1 (Menu)**: Configuration → Advanced Settings → Initialize EEPROM → Store Settings
- **Method 2 (G-code)**: Send `M502` then `M500`

## Still Having Problems?

Create an issue in this repository with:
1. **What SD card you're using** (size, brand if known)
2. **Which branch you built from** (this is critical!)
3. **What you see on the screen** (blue screen, garbage text, nothing, etc.)
4. **How long you waited** (30 seconds, 5 minutes, etc.)
5. **Whether you tried a different SD card**

## Quick Checklist

Before asking for help, verify you've done these:
- [ ] Built firmware from **"copilot/fix-firmware-issue-ender-3-pro"** branch (NOT "main")
- [ ] SD card is formatted as FAT32
- [ ] SD card is 8GB or smaller
- [ ] File is named exactly `firmware.bin` (all lowercase)
- [ ] Tried waiting at least 30 seconds after turning on the printer
- [ ] Tried a different SD card
- [ ] Removed SD card and restarted printer after flashing attempt

## Advanced: If Nothing Works

If you've tried everything above and it still doesn't work, the issue might be:
1. **Hardware problem** with the motherboard or display
2. **Wrong motherboard version** - This firmware is for V4.2.2 boards
3. **Corrupted bootloader** - Would need USB flashing or ST-Link recovery

Let me know in an issue and we'll figure it out together.
