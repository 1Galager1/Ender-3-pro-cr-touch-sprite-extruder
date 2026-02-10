# 🚀 QUICK START - 3 STEPS TO WORKING PRINTER

## You're 3 steps away from fixing your blue screen!

### ✅ STEP 1: BUILD (5 minutes)
1. Click **[Actions](../../actions)** tab at top of this page
2. Click **Build Marlin (robust patch)**
3. Click **Run workflow** button (right side)
4. Click green **Run workflow** in dropdown
5. Wait for ✓ green checkmark (~5 min)
6. Click on the completed run
7. Scroll to **Artifacts**
8. Download **firmware-bin**
9. Unzip to get `firmware.bin`

### ✅ STEP 2: FLASH (2 minutes)
1. **Format SD card** as FAT32 (8-32GB)
2. **Copy** `firmware.bin` to SD card root
3. **Power OFF** printer
4. **Insert** SD card
5. **Power ON** printer
6. **Wait** 60 seconds
7. See Marlin boot screen! 🎉

### ✅ STEP 3: INITIALIZE (1 minute)
**LCD Menu:** Configuration → Initialize EEPROM → Store Settings

**OR via USB:**
```
M502
M500
```

## 🎯 DONE! Your printer should now work!

---

## ⚠️ STILL BLUE SCREEN?

→ Read **[BLUE_SCREEN_FIX.md](BLUE_SCREEN_FIX.md)** for detailed troubleshooting

Common fixes:
- Use a different/slower SD card
- Reformat SD card as FAT32
- Try filename `FIRMWARE.CUR` instead
- Verify you have V4.2.2 board (not V4.2.7)

---

## 📖 More Info

- **Full README**: [README.md](README.md)
- **Blue Screen Help**: [BLUE_SCREEN_FIX.md](BLUE_SCREEN_FIX.md)
- **Original Guide**: [README_Version3.md](README_Version3.md)

---

**First time?** Follow the 3 steps above in order.  
**Having issues?** Read BLUE_SCREEN_FIX.md thoroughly.  
**Need the firmware NOW?** Go to Actions and run the workflow!
