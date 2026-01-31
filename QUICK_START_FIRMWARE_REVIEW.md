# Quick Start: Share Your Firmware for Review

Found a firmware bin file that works? Want it reviewed and optimized? Follow these simple steps!

## 🚀 Quick Steps

### 1. Prepare Your Information

Before sharing, gather this info (use your printer's USB connection):

```gcode
M503    # Get all current settings
M115    # Get firmware version info
```

Save the output to a text file.

### 2. Upload Your Firmware

**Easy way (GitHub Web Interface):**

1. Go to your repository on GitHub
2. Navigate to `firmware-bins/working/` folder
3. Click "Add file" → "Upload files"
4. Drag your `.bin` file here
5. Give it a good name like: `working-firmware-2026-01-31.bin`
6. Click "Commit changes"

### 3. Create an Info File

Create a text file with the same name as your bin file but ending in `.md`:

**Example:** If your file is `working-firmware-2026-01-31.bin`, create `working-firmware-2026-01-31.md`

**Minimum info to include:**
```markdown
# Firmware: working-firmware-2026-01-31.bin

## What Works
- Boots successfully
- Display works
- Bed leveling works
- [Add more]

## What Needs Improvement
- [List any issues]

## Settings (M503 output)
[Paste your M503 output here]
```

### 4. Request a Review

Two ways to request review:

**Option A: Create a GitHub Issue**
1. Go to "Issues" tab
2. Click "New issue"
3. Select "Firmware Review Request" template
4. Fill it out and submit

**Option B: Simple Comment**
Just create any issue and say:
```
I uploaded my working firmware to firmware-bins/working/my-file.bin
Can you review it and suggest improvements?

Here's my M503 output:
[paste output]
```

## 📋 What We'll Check

When we review your firmware, we'll look at:

- ✅ **Safety:** Thermal runaway protection, temperature limits
- 🎯 **Accuracy:** E-steps, probe offsets, bed size
- 🚀 **Performance:** Acceleration, jerk, speeds
- 🔧 **Features:** What's enabled, what could be added
- 🎨 **Quality:** Settings that affect print quality

## 💡 What You'll Get

After review, you'll receive:

1. **Analysis** of your current firmware settings
2. **Recommendations** for improvements
3. **Updated config files** (if needed)
4. **Step-by-step guide** to build improved firmware
5. **Testing checklist** for the new firmware

## ⚠️ Important Reminders

- **Keep a backup** of your working bin file (on SD card and computer)
- **Test carefully** - Don't flash untested firmware without a backup plan
- **One step at a time** - We'll make incremental improvements
- **Ask questions** - If anything is unclear, just ask!

## 📚 Detailed Guides

For more information, see:

- [BIN_FILE_REVIEW_GUIDE.md](BIN_FILE_REVIEW_GUIDE.md) - Complete guide to sharing firmware
- [firmware-bins/README.md](firmware-bins/README.md) - Info about the firmware storage directory
- [SIMPLE_GUIDE.md](SIMPLE_GUIDE.md) - General firmware building guide

## 🎯 Example Workflow

**Real example of what to expect:**

1. **You share:** "Here's my firmware-bins/working/current.bin and M503 output"
2. **We analyze:** "Your E-steps are 424.9 ✅ but Z-offset needs calibration"
3. **We suggest:** "Try M851 Z-2.0 and test with paper method"
4. **You test:** "That worked! What else can we improve?"
5. **We recommend:** "Let's enable features X, Y, Z and rebuild"
6. **We provide:** Updated Configuration.h files
7. **You build:** Using GitHub Actions
8. **You test:** New firmware with improvements
9. **Result:** Optimized firmware for your specific printer! 🎉

Ready to share your firmware? Start with step 1 above!
