# How to Share Your Firmware Bin File for Review

Great! You found a bin file that allows your printer to boot. This guide will help you share it so we can review it and make suggestions to perfect it for your specific printer setup.

## 🎯 What We Need From You

When sharing your firmware bin file, please provide the following information to help us give you the best recommendations:

### 1. The Bin File Itself

**How to share the bin file:**

There are several ways you can share your firmware bin file:

#### Option A: Upload to the Repository (Recommended)
1. Download your working bin file to your computer
2. Create a folder called `firmware-bins/` in this repository
3. Name your file descriptively, for example:
   - `working-firmware-DATE.bin` (e.g., `working-firmware-2026-01-31.bin`)
   - `ender3-pro-crtouch-sprite-v1.bin`
4. Upload it to the `firmware-bins/` folder via GitHub:
   - Go to your repository on GitHub
   - Click "Add file" → "Upload files"
   - Drag and drop your bin file
   - Commit the changes

#### Option B: Share via GitHub Release
1. Go to your repository on GitHub
2. Click "Releases" on the right side
3. Click "Create a new release"
4. Tag it with a version like `v1.0-working`
5. Attach your bin file to the release
6. Publish the release

#### Option C: Use a File Sharing Service
If the file is too large or you prefer, you can:
- Upload to Google Drive, Dropbox, or similar
- Make it publicly accessible
- Share the link in a GitHub issue or pull request

### 2. Printer Information Checklist

Please fill out this information about your printer setup:

```
**Printer Model:** Ender 3 Pro

**Motherboard:**
- [ ] V4.2.2 (STM32F103)
- [ ] V4.2.7 (STM32F103)
- [ ] Other: _______________

**Display Type:**
- [ ] 12864 LCD with knob (non-touch)
- [ ] Touchscreen
- [ ] Other: _______________

**Bed Leveling Sensor:**
- [ ] CR Touch
- [ ] BLTouch
- [ ] None
- [ ] Other: _______________

**Extruder:**
- [ ] Sprite Extruder (0.9° stepper)
- [ ] Stock Creality Extruder
- [ ] Other: _______________

**Current E-steps value:**
- Factory default for Sprite: 424.9
- My current setting: _______________

**Build Volume:**
- X: ___ mm (usually 220mm)
- Y: ___ mm (usually 220mm)
- Z: ___ mm (usually 250mm)

**Stepper Drivers:**
- [ ] TMC2208
- [ ] TMC2209
- [ ] A4988
- [ ] Unknown

**Other Modifications:**
- [ ] Direct Drive conversion
- [ ] Different hotend
- [ ] Different fans
- [ ] Other: _______________
```

### 3. What's Working and What's Not

Please describe:

**✅ What works well:**
- Printer boots successfully
- (Add other things that work)

**❌ What doesn't work or needs improvement:**
- (List any issues or features you'd like to improve)
- (Examples: bed leveling, temperature control, display issues, etc.)

**❓ What you'd like to add or improve:**
- (Examples: better bed leveling, mesh storage, specific features, etc.)

### 4. Current Settings (Optional but Helpful)

If you can, share these G-code commands from your printer's terminal:

```
M503    (This shows all current EEPROM settings)
M115    (This shows firmware version and capability info)
```

Copy and paste the output here.

## 📋 How to Extract Configuration from Your Bin File

Unfortunately, you **cannot directly extract** the configuration files (Configuration.h and Configuration_adv.h) from a compiled .bin file. The compilation process transforms the human-readable code into machine code that the printer can execute.

However, we can still help! Here's what we can do:

### Method 1: Analyze Firmware Behavior
We can send G-code commands to your printer to discover its settings:
1. Connect your printer to a computer via USB
2. Use software like:
   - Pronterface
   - OctoPrint
   - Repetier-Host
   - Arduino IDE Serial Monitor
3. Send the `M503` command
4. Copy all the output and share it

The `M503` output will show us:
- Steps per unit (including E-steps)
- Acceleration and jerk settings
- Probe offsets
- Bed leveling settings
- Temperature limits
- And much more!

### Method 2: Compare with Reference Firmware
Tell us where you got the bin file:
- Downloaded from a specific website? (Share the link)
- Built using a specific Marlin version?
- Provided by someone else?

This helps us understand what might be in it.

### Method 3: Test Specific Features
We can guide you through testing specific features to determine what's enabled:
- Does bed leveling work? (`G29` command)
- Does mesh storage work? (`G29` then `M500` then reboot and `M420 S1`)
- What LCD type is configured?
- What probe type is detected?

## 🔍 What We'll Review

Once you share your bin file and information, we'll help you with:

1. **Configuration Verification**
   - Ensure your E-steps are correct for the Sprite extruder
   - Verify probe offsets are set properly
   - Check that bed size is configured correctly

2. **Feature Optimization**
   - Suggest enabling helpful features you might be missing
   - Recommend settings for better print quality
   - Identify potentially unsafe configurations

3. **Safety Checks**
   - Verify thermal runaway protection is enabled
   - Check min/max temperature limits
   - Ensure endstop configurations are safe

4. **Performance Improvements**
   - Suggest acceleration/jerk tuning
   - Recommend print speed optimizations
   - Advise on advanced features like Linear Advance

## 📝 Template for Sharing

Here's a template you can copy and use when sharing your firmware:

```markdown
## Working Firmware Bin File - Review Request

### Bin File Location
[Upload your bin file or provide a link here]

### Printer Setup
- **Model:** Ender 3 Pro
- **Motherboard:** V4.2.2 (STM32F103)
- **Display:** 12864 LCD with knob
- **Probe:** CR Touch
- **Extruder:** Sprite Extruder
- **E-steps:** 424.9

### Current Status
**Working:**
- Printer boots and operates
- [Add more]

**Not Working / Needs Improvement:**
- [List issues]

**Desired Improvements:**
- [What you want to improve]

### M503 Output
```
[Paste M503 command output here]
```

### Questions
[Any specific questions you have]
```

## 🚀 Next Steps

After you share your firmware:

1. **We'll analyze** the information you provide
2. **We'll suggest** specific improvements for your setup
3. **We can create** updated configuration files optimized for your printer
4. **We can build** a new firmware.bin using GitHub Actions
5. **You can test** the improved firmware and report back

## ⚠️ Important Notes

- **Always keep a backup** of your working bin file on your SD card
- **Test new firmware carefully** - do a bed leveling calibration after flashing
- **Never flash untested firmware** without having a working backup
- **If something goes wrong** during flashing, you can always reflash your working bin file

## 📞 Need Help?

If you have questions about this process:
1. Open a GitHub Issue in this repository
2. Title it: "Firmware Review Request - [Brief Description]"
3. Use the template above to provide information
4. We'll respond with analysis and recommendations!

---

Remember: The goal is to help you get the best possible firmware for your specific printer configuration. Don't hesitate to ask questions!
