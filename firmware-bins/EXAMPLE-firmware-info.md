# Firmware: example-firmware-2026-01-31.bin

> This is an EXAMPLE template showing how to document your firmware bin files.
> Copy this file and rename it to match your bin file name.

## Build Information
- **Date:** 2026-01-31
- **Source:** Built using GitHub Actions from this repository
- **Marlin Version:** 2.1.x bugfix branch
- **Built with:** PlatformIO (STM32F103RE_creality environment)

## Printer Configuration
- **Motherboard:** V4.2.2 (STM32F103)
- **Display:** 12864 LCD with knob (non-touch)
- **Probe:** CR Touch
- **Extruder:** Sprite Extruder with 0.9° stepper
- **E-steps:** 424.9
- **Bed Size:** 220mm x 220mm x 250mm

## Test Results

### ✅ Working Features
- Boots successfully on first try
- Display shows correctly with full graphics
- Bed leveling probe deploys and retracts properly
- G29 auto bed leveling works (3x3 grid)
- Mesh saves to EEPROM (M500) and loads on boot (M420 S1)
- Temperature control stable (hotend and bed)
- SD card reading works
- Manual movement in all axes works correctly
- Extrusion works properly

### ❌ Issues / Not Working
- Z-offset needs calibration (too high by about 0.2mm)
- First layer slightly inconsistent in corners

### ❓ Untested
- Print from SD card (not tested yet)
- Linear Advance
- Print speeds above 60mm/s

## Settings (M503 Output)

```
Send: M503
Recv: echo:  G21    ; Units in mm (mm)
Recv: echo:; Filament settings: Disabled
Recv: echo:  M200 S0 D1.75
Recv: echo:; Steps per unit:
Recv: echo: M92 X80.00 Y80.00 Z400.00 E424.90
Recv: echo:; Maximum feedrates (units/s):
Recv: echo:  M203 X500.00 Y500.00 Z5.00 E25.00
Recv: echo:; Maximum Acceleration (units/s2):
Recv: echo:  M201 X500.00 Y500.00 Z100.00 E1000.00
Recv: echo:; Acceleration (units/s2): P<print_accel> R<retract_accel> T<travel_accel>
Recv: echo:  M204 P500.00 R500.00 T500.00
Recv: echo:; Advanced: B<min_segment_time_us> S<min_feedrate> T<min_travel_feedrate> X<max_x_jerk> Y<max_y_jerk> Z<max_z_jerk> E<max_e_jerk>
Recv: echo:  M205 B20000.00 S0.00 T0.00 X7.00 Y7.00 Z0.40 E5.00
Recv: echo:; Home offset:
Recv: echo:  M206 X0.00 Y0.00 Z0.00
Recv: echo:; Auto Bed Leveling:
Recv: echo:  M420 S1 Z10.00
Recv: echo:  G29 W I0 J0 Z0.21250
Recv: echo:  G29 W I1 J0 Z0.10000
Recv: echo:  G29 W I2 J0 Z0.05000
Recv: echo:  G29 W I0 J1 Z0.15000
Recv: echo:  G29 W I1 J1 Z0.00000
Recv: echo:  G29 W I2 J1 Z-0.03750
Recv: echo:  G29 W I0 J2 Z0.12500
Recv: echo:  G29 W I1 J2 Z-0.02500
Recv: echo:  G29 W I2 J2 Z-0.08750
Recv: echo:; Material heatup parameters:
Recv: echo:  M145 S0 H200 B60 F0
Recv: echo:  M145 S1 H240 B80 F0
Recv: echo:; PID settings:
Recv: echo:  M301 P21.73 I1.54 D76.55
Recv: echo:  M304 P462.10 I85.47 D496.68
Recv: echo:; Probe Offset:
Recv: echo:  M851 X-44.00 Y-9.00 Z-2.00
Recv: ok
```

## Tuning/Calibration Performed

- ✅ **PID Tuning:** Hotend PID tuned at 200°C
- ✅ **Bed Leveling:** 3x3 mesh created and saved
- ✅ **Z-Offset:** Set to -2.00mm (may need fine-tuning)
- ⏳ **E-steps:** Using factory default 424.9 - needs calibration
- ⏳ **Flow Rate:** Not calibrated yet
- ⏳ **Retraction:** Using defaults - needs tuning

## Slicer Settings Used

**Slicer:** Cura 5.x

**Start G-code:**
```gcode
G28          ; Home all axes
M420 S1      ; Load bed leveling mesh
G1 Z2 F240   ; Raise nozzle
G1 X2 Y10 F3000  ; Move to prime position
M109 S{material_print_temperature_layer_0}  ; Wait for temp
G92 E0       ; Reset extruder
G1 Z0.3 F240 ; Lower to print height
G1 X2 Y200 E15 F1500  ; Prime line
G92 E0       ; Reset extruder
```

**Print Settings:**
- Layer height: 0.2mm
- Print speed: 50mm/s
- Retraction: 5mm @ 45mm/s
- Bed temp: 60°C (PLA)
- Hotend temp: 200°C (PLA)

## Recommended Next Steps

1. Calibrate E-steps properly using extrusion test
2. Fine-tune Z-offset for perfect first layer
3. Test retraction settings to reduce stringing
4. Perform temperature tower test
5. Try higher print speeds once basics are dialed in

## Notes

This firmware boots reliably and basic functionality is confirmed. The main focus should be on calibration (E-steps, Z-offset) rather than changing the firmware. The bed leveling mesh looks good with appropriate variation for a typical bed.

Consider enabling Linear Advance in future builds once E-steps are properly calibrated.

## Photos/Videos

<!-- If you have photos or test prints, link them here or describe results -->

- First benchy print: Good quality, slight stringing
- Bed adhesion: Excellent with cleaned bed
- Corner quality: Minor elephants foot, needs Z-offset adjustment
