---
name: Firmware Review Request
about: Request a review of a firmware bin file for your printer
title: '[FIRMWARE REVIEW] '
labels: firmware-review
assignees: ''
---

## Firmware Bin File - Review Request

### 📦 Bin File Location
<!-- 
Upload your bin file to the firmware-bins/ directory or provide a link here.
Example: firmware-bins/working/my-firmware-2026-01-31.bin
Or provide a download link if hosted elsewhere.
-->

**File location or link:**


### 🖨️ Printer Setup

**Model:** Ender 3 Pro

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
<!-- Factory default for Sprite: 424.9 -->


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
<!-- List any other modifications to your printer -->


### ✅ Current Status

**What's Working:**
<!-- List what works well with this firmware -->
- Printer boots successfully
- 

**What's Not Working / Needs Improvement:**
<!-- List any issues or areas that need improvement -->
- 

**What You'd Like to Add/Improve:**
<!-- List features or improvements you're interested in -->
- 

### 📊 Current Settings (M503 Output)

<!-- 
If possible, connect your printer via USB and send the M503 command.
Paste the entire output below. This helps us understand your current configuration.
-->

```
[Paste M503 command output here]
```

### ℹ️ Firmware Source

**Where did you get this firmware?**
<!-- Example: Downloaded from website, built myself, provided by someone, etc. -->


**Marlin version (if known):**


### ❓ Specific Questions

<!-- Any specific questions or concerns you have about this firmware? -->


### 📝 Additional Notes

<!-- Any other information you think would be helpful -->


---

**Checklist before submitting:**
- [ ] I've uploaded the bin file or provided a download link
- [ ] I've filled out the printer setup information
- [ ] I've described what's working and what's not
- [ ] I've included M503 output (if possible)
- [ ] I have a backup of my current working firmware

See [BIN_FILE_REVIEW_GUIDE.md](../BIN_FILE_REVIEW_GUIDE.md) for more detailed instructions on sharing firmware for review.
