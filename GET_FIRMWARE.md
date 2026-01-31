# ✅ SOLUTION: How to Get Your Firmware Bin File

## Your Request
You asked for a **bin file** for:
- Ender 3 Pro
- V4.2.2 board  
- CR Touch
- Sprite Pro
- 12864 screen

## ✅ Good News - Everything is Ready!

This repository is **already configured** for exactly your printer setup! The firmware build system is working and has been successfully tested.

---

## 🎯 THREE WAYS to Get Your Firmware Bin File

### Method 1: Download Pre-built Firmware (FASTEST - 30 seconds)

A firmware binary was **already built** for this configuration!

1. Go to [**Actions**](../../actions/workflows/build.yml)
2. Click on the most recent **successful** build (look for green ✅ checkmark)
3. Scroll to the bottom - find "Artifacts" section  
4. Click **"firmware-bin"** to download (it's a .zip file)
5. Extract the zip - inside you'll find **`firmware.bin`** ✅

**That's it!** You now have your firmware bin file ready to flash!

---

### Method 2: Build New Firmware (5-15 minutes)

If you want to build fresh firmware yourself:

1. Go to [**Actions**](../../actions/workflows/build.yml)
2. Click **"Run workflow"** button (top right)
3. Select branch: **main**  
4. Click green **"Run workflow"**
5. Wait for build to complete (shows green ✅ when done)
6. Download the firmware-bin artifact from the completed run

---

### Method 3: Build Locally (Advanced Users)

If you prefer to build on your own computer:
- See [README_Version3.md](README_Version3.md) for detailed local build instructions

---

## 📥 How to Flash the Firmware to Your Printer

Once you have `firmware.bin`:

1. **Format SD card** as FAT32
2. **Copy** `firmware.bin` to root of SD card
3. **Power off** printer
4. **Insert** SD card  
5. **Power on** printer
6. Wait ~30 seconds while it flashes (screen may go blank)
7. Printer reboots automatically when done
8. **Remove** SD card and power cycle

---

## ⚙️ Essential First-Time Setup

After flashing, you **MUST** do this initial setup (use terminal or printer menu):

```gcode
M502          ; Restore factory defaults
M500          ; Save to EEPROM
G28           ; Home all axes  
G29           ; Create bed mesh (heat bed to 60°C first!)
M500          ; Save the mesh
M92 E424.9    ; Set Sprite Pro E-steps
M500          ; Save settings
```

### Critical: Set Your Z-Offset

The firmware has a **placeholder** Z-offset. You MUST calibrate yours:

1. `G28` - Home the printer
2. Use paper method to find offset
3. `M851 Z-X.XX` - Set offset (e.g., `M851 Z-1.85`)  
4. `M500` - Save

---

## 📋 What's Configured in This Firmware

✅ Ender 3 Pro printer profile  
✅ V4.2.2 (STM32F103RET6) motherboard  
✅ CR Touch / BLTouch probe support  
✅ Sprite Pro extruder (E-steps: 424.9)  
✅ 12864 LCD display (knob/encoder)  
✅ Auto bed leveling (3x3 bilinear)  
✅ Z safe homing (probes center)  
✅ Mesh restored after G28  
✅ EEPROM save/restore enabled  

---

## 📚 Additional Help

- **Quick guide:** [QUICK_START.md](QUICK_START.md)
- **Full details:** [README.md](README.md)  
- **Advanced:** [README_Version3.md](README_Version3.md)

---

## ❓ Questions?

**Q: Will this firmware work on my exact setup?**  
A: Yes! It's configured for Ender 3 Pro + V4.2.2 + CR Touch + Sprite Pro + 12864 screen.

**Q: Is it safe to flash?**  
A: Yes, this is standard Marlin firmware configured for your hardware. You can always reflash if needed.

**Q: Do I need to compile anything?**  
A: No! Just download the pre-built firmware-bin artifact and flash it.

**Q: What if something goes wrong?**  
A: You can always reflash with stock firmware or rebuild. The SD card flash method is very safe.

---

## 🎉 You're All Set!

Your firmware bin file is ready to download and use. Follow Method 1 above to get it in 30 seconds!

Need help? [Create an issue](../../issues)
