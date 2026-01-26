# How to Build and Flash Your Ender 3 Pro Firmware

This guide uses **simple language** to help you get your printer working.

## What This Does

This repository will automatically build firmware (the software that runs your printer) for your Ender 3 Pro printer with:
- CR Touch (auto bed leveling sensor)
- Sprite Extruder
- The standard LCD screen with the knob (not a touchscreen)

## Step 1: Build the Firmware

1. **Go to your repository on GitHub** (you're probably looking at it right now!)

2. **Click on the "Actions" tab** at the top of the page
   - It's between "Pull requests" and "Projects"

3. **Click on "Build Marlin (robust patch)"** in the left sidebar

4. **Click the "Run workflow" button** on the right side
   - A dropdown will appear
   - Click the green "Run workflow" button in the dropdown

5. **Wait for the build to complete** (about 2-3 minutes)
   - You'll see a yellow circle while it's building
   - When done, you'll see a green checkmark ✓

## Step 2: Download the Firmware

1. **Click on the completed workflow run** (the one with the green checkmark)

2. **Scroll down to the "Artifacts" section** at the bottom

3. **Click on "firmware-bin"** to download it
   - This will download a .zip file to your computer

4. **Unzip/Extract the downloaded file**
   - Inside, you'll find a file called `firmware.bin`

## Step 3: Prepare Your SD Card

⚠️ **IMPORTANT**: Use a good quality microSD card formatted as FAT32
- 8GB or smaller cards work best
- If you have problems, try a different SD card

1. **Format the SD card as FAT32**
   - On Windows: Right-click the SD card → Format → Choose FAT32
   - On Mac: Use Disk Utility → Erase → Choose MS-DOS (FAT)

2. **Copy ONLY the `firmware.bin` file** to the SD card
   - Put it in the root (main folder), not in any subfolders
   - Make sure it's named exactly `firmware.bin` (all lowercase)
   - Delete any old firmware files first

## Step 4: Flash (Install) the Firmware

1. **Turn OFF your printer** completely (flip the power switch)

2. **Remove any SD card** that's currently in the printer

3. **Insert the SD card** with firmware.bin into the printer

4. **Turn ON the printer**
   - The screen should show something briefly, then restart
   - This process takes about 10-30 seconds
   - The screen might be blank or blue during this time - **this is normal**

5. **Wait for the printer screen to show the normal menu**
   - If you see the normal Marlin menu, SUCCESS! 🎉
   - The firmware has been installed

6. **Remove the SD card** after the printer has fully started

## Step 5: Initial Setup (IMPORTANT!)

After flashing the firmware, you MUST do these steps:

### Using the Printer Menu:
1. **Navigate to**: Configuration → Advanced Settings → Initialize EEPROM
   - This resets all settings to defaults
   
2. **Navigate to**: Configuration → Store Settings
   - This saves the defaults

### Using Pronterface, Cura, or OctoPrint Terminal:
If you have the printer connected to a computer, you can also do this:
1. Send command: `M502` (reset to defaults)
2. Send command: `M500` (save settings)

## What If It Doesn't Work?

### Problem: Blue screen that never goes away
- Try a different SD card (format it as FAT32)
- Make sure the firmware.bin file is in the root of the card
- Try renaming the file to `FIRMWARE.CUR` instead

### Problem: Nothing happens when I turn on the printer
- The SD card might not be formatted correctly (must be FAT32)
- Try a different, smaller SD card (8GB or less works best)
- Make sure the file is named exactly `firmware.bin`

### Problem: Screen shows errors or weird text
- Run the "Initialize EEPROM" step again from the menu
- Or send `M502` then `M500` from a terminal

## Need More Help?

Create an issue in this repository and describe:
1. What step you're on
2. What you see on the printer screen
3. Any error messages

I'll help you get it working!

## Next Steps After Successful Flash

Once the firmware is working, you'll need to:
1. **Level the bed** using the CR Touch (Auto Home, then Auto Level)
2. **Calibrate the extruder** steps (the instructions are in the other README files)
3. **Set the Z-offset** so the nozzle is the right distance from the bed

But first, let's just get the firmware loaded! The other steps can wait.
