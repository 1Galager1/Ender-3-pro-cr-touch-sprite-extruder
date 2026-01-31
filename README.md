# Ender 3 Pro - CR Touch - Sprite Extruder Firmware

Custom Marlin firmware configuration and build system for the **Ender 3 Pro** with **CR Touch** bed leveling sensor and **Sprite Extruder**.

<!-- TODO: Remove this notice after PR #12 is merged -->
> **📌 Viewing from Pull Request #12?**
> 
> The new documentation files are in this PR but not yet merged to main. To access them:
> - **Option 1:** Click the **"Files changed"** tab in the PR to browse all new files
> - **Option 2:** Use these direct links to view files in this PR branch:
>   - [QUICK_START_FIRMWARE_REVIEW.md](https://github.com/1Galager1/Ender-3-pro-cr-touch-sprite-extruder/blob/copilot/review-printer-bin-file/QUICK_START_FIRMWARE_REVIEW.md) ⭐ **Start here for firmware review**
>   - [BIN_FILE_REVIEW_GUIDE.md](https://github.com/1Galager1/Ender-3-pro-cr-touch-sprite-extruder/blob/copilot/review-printer-bin-file/BIN_FILE_REVIEW_GUIDE.md)
>   - [SIMPLE_GUIDE.md](https://github.com/1Galager1/Ender-3-pro-cr-touch-sprite-extruder/blob/copilot/review-printer-bin-file/SIMPLE_GUIDE.md)
>   - [README_Version3.md](https://github.com/1Galager1/Ender-3-pro-cr-touch-sprite-extruder/blob/copilot/review-printer-bin-file/README_Version3.md)
> - **After the PR is merged**, all the relative links below will work normally.

## 🚀 Quick Start

Choose the guide that matches your situation:

### Option 1: Build New Firmware from Scratch
**You want to build custom firmware using this repository**

👉 **Start here:** [README_Version3.md](README_Version3.md)
- Complete step-by-step cloud build instructions
- Pre-configured Configuration.h files
- GitHub Actions workflow for automated building
- No local software installation required

Or for a simplified guide:
👉 **Alternative:** [SIMPLE_GUIDE.md](SIMPLE_GUIDE.md)
- Plain English instructions
- Explains GitHub Actions workflow
- Troubleshooting common issues

### Option 2: Review & Optimize Existing Firmware
**You already have a working bin file and want to improve it**

👉 **Start here:** [QUICK_START_FIRMWARE_REVIEW.md](QUICK_START_FIRMWARE_REVIEW.md)
- Quick guide to sharing your firmware
- Get expert review and optimization suggestions
- Understand what settings your firmware has

👉 **Detailed guide:** [BIN_FILE_REVIEW_GUIDE.md](BIN_FILE_REVIEW_GUIDE.md)
- Complete instructions for firmware review process
- How to extract settings from your printer
- What information to provide

## 📁 Repository Structure

```
├── Configuration_Version3.h          # Main Marlin configuration
├── Configuration_adv_Version3.h      # Advanced Marlin configuration
├── README_Version3.md                # Detailed build instructions
├── SIMPLE_GUIDE.md                   # Beginner-friendly guide
├── QUICK_START_FIRMWARE_REVIEW.md    # Quick guide for firmware review
├── BIN_FILE_REVIEW_GUIDE.md          # Detailed firmware review guide
├── firmware-bins/                    # Store firmware bin files here
│   ├── working/                      # Working firmware files
│   ├── tested/                       # Tested firmware files
│   ├── experimental/                 # Experimental builds
│   └── archive/                      # Old versions
├── .github/
│   ├── workflows/
│   │   └── build.yml                 # GitHub Actions build workflow
│   └── ISSUE_TEMPLATE/
│       └── firmware-review.md        # Template for firmware review requests
```

## 🎯 What This Repository Provides

### Pre-Configured Firmware Settings
- ✅ Ender 3 Pro V4.2.2 motherboard (STM32F103)
- ✅ CR Touch / BLTouch bed leveling (3x3 bilinear)
- ✅ Sprite Extruder with correct E-steps (424.9)
- ✅ 12864 LCD with knob controller (non-touch)
- ✅ EEPROM settings storage
- ✅ Safe defaults with thermal runaway protection

### Cloud Build System
- ✅ GitHub Actions workflow for automated building
- ✅ No local PlatformIO or VS Code installation needed
- ✅ Download ready-to-flash `.bin` files
- ✅ Build from any device with a web browser

### Firmware Review Service
- ✅ Upload your existing working firmware
- ✅ Get expert analysis and recommendations
- ✅ Receive optimized configuration suggestions
- ✅ Understand your current firmware settings

## 🛠️ Supported Hardware

This configuration is specifically designed for:

- **Printer:** Creality Ender 3 Pro
- **Motherboard:** V4.2.2 with STM32F103RET6 MCU
- **Display:** 12864 Full Graphic Smart Controller (knob + click wheel)
- **Bed Leveling:** CR Touch or BLTouch
- **Extruder:** Sprite Extruder with 0.9° stepper motor
- **Stepper Drivers:** TMC2208/TMC2209 (typical for V4.2.2)

## 📖 Documentation Guide

Not sure which guide to read? Here's what each file covers:

| File | Best For | Contents |
|------|----------|----------|
| **README_Version3.md** | Building firmware from scratch | Complete technical build guide, configuration details |
| **SIMPLE_GUIDE.md** | Beginners new to GitHub | Plain English, step-by-step GitHub Actions tutorial |
| **QUICK_START_FIRMWARE_REVIEW.md** | Have working firmware to review | Fast guide to share firmware and get feedback |
| **BIN_FILE_REVIEW_GUIDE.md** | Detailed firmware review process | Complete guide with templates and checklists |
| **firmware-bins/README.md** | Understanding file storage | How to organize and document firmware files |

## 🔄 Typical Workflows

### Workflow 1: First-Time Firmware Build

1. Read [SIMPLE_GUIDE.md](SIMPLE_GUIDE.md)
2. Go to GitHub Actions → Run "Build Marlin" workflow
3. Select "Branch: main"
4. Wait for build to complete
5. Download firmware artifact
6. Flash to printer via SD card
7. Configure using M-codes (M502, M500, G29, etc.)

### Workflow 2: Review Existing Firmware

1. Read [QUICK_START_FIRMWARE_REVIEW.md](QUICK_START_FIRMWARE_REVIEW.md)
2. Upload your `.bin` file to `firmware-bins/working/`
3. Create info file with M503 output
4. Create GitHub Issue using "Firmware Review Request" template
5. Receive analysis and recommendations
6. Optionally build improved firmware using suggestions

### Workflow 3: Custom Configuration Changes

1. Edit `Configuration_Version3.h` or `Configuration_adv_Version3.h`
2. Commit changes to GitHub
3. Run GitHub Actions workflow
4. Download and test new firmware
5. Iterate as needed

## ⚠️ Important Safety Notes

- **Always keep a backup** of your working firmware
- **Test new firmware carefully** - start with a bed leveling test
- **Never disable** thermal runaway protection
- **Verify probe offsets** after first flash using paper method
- **Calibrate E-steps** for your specific setup

## 📞 Getting Help

### Submit a Firmware Review Request
Create a GitHub Issue using the "Firmware Review Request" template:
- Go to "Issues" tab
- Click "New issue"
- Select "Firmware Review Request"
- Fill out the template

### Ask Questions
- Open a regular GitHub Issue
- Describe your problem clearly
- Include error messages or screenshots if applicable
- Mention which guide you're following

### Common Issues
See [SIMPLE_GUIDE.md](SIMPLE_GUIDE.md) for FAQ section covering:
- Which branch to select for builds
- What to do if build fails
- How to merge pull requests
- And more!

## 🤝 Contributing

Found an issue or want to suggest an improvement?
- Open a GitHub Issue
- Submit a Pull Request
- Share your successful firmware configuration

## 📄 License

This repository contains configuration files for Marlin firmware. 
Marlin is licensed under the GPL v3.0 license.

## 🔗 Useful Resources

- [Marlin Firmware Official Site](https://marlinfw.org/)
- [Marlin Documentation](https://marlinfw.org/docs/configuration/configuration.html)
- [Teaching Tech 3D Printer Calibration](https://teachingtechyt.github.io/calibration.html)
- [Creality Ender 3 Pro Specifications](https://www.creality.com/products/ender-3-pro-3d-printer)

---

**Ready to get started?** Pick your path above and dive in! 🚀
