// Configuration.h — ready-for-cloud-build (Ender 3 Pro V4.2.2, STM32F103RET6, knob LCD, CR Touch, Sprite 0.9°)
// ---------------------------------------------------------------------------
// IMPORTANT:
// - This file is intended to replace/merge into Marlin/Marlin/Configuration.h in the Marlin source during the cloud build.
// - You MUST verify the probe offsets after first flash and adjust NOZZLE_TO_PROBE_OFFSET accordingly.
// - Do NOT enable touchscreen options. Keep the knob/12864 controller enabled below.

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// ----------------- MACHINE STEPS -----------------
// X, Y, Z, E. E set to Sprite factory value you supplied.
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 424.9 } // X, Y, Z, E

// ----------------- MOTHERBOARD -----------------
// Creality V4.2.2 board (STM32F103 family)
#define MOTHERBOARD BOARD_CREALITY_V422

// ----------------- LCD / CONTROLLER -----------------
// Non-touch 12864 knob + click-wheel display (full-graphic)
// Uncomment the controller macro your Marlin release recognizes if different.
// The common one for a knob 12864 is:
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
// If your Marlin release provides CREALITY_LCD variants, that may also be acceptable.
// DO NOT enable touchscreen UI options.

// ----------------- PROBE (CR-Touch / BLTouch) -----------------
#define BLTOUCH                 // CR-Touch is BLTouch-compatible
#define Z_SAFE_HOMING           // Probe in center during Z homing

// Auto bed leveling: Bilinear recommended for Ender 3
#define AUTO_BED_LEVELING_BILINEAR
#define GRID_MAX_POINTS_X 3     // 3x3 grid is fast and fine for beginners

#define MIN_PROBE_EDGE 10       // mm margin from the bed edge when probing

// ----- NOZZLE TO PROBE OFFSET -----
// These X/Y/Z values are PLACEHOLDERS. You MUST measure and set the real offset after flashing.
#define NOZZLE_TO_PROBE_OFFSET { -44, -9, 0 } // { X, Y, Z } in mm

// ----------------- EEPROM -----------------
#define EEPROM_SETTINGS        // Enable M500/M501 save/restore

// ----------------- THERMISTOR -----------------
// Stock Creality thermistor (NTC 100k) — keep Marlin defaults for a Creality thermistor in your chosen Marlin release.

// ----------------- SAFETY -----------------
// Leave thermal runaway protection enabled (do NOT disable).

// ----------------- FILAMENT / EXTRUDER -----------------
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75  // mm

// ----------------- FINAL NOTES -----------------
// Keep advanced features disabled for a beginner build. We can add extras later if you want.
#endif // CONFIGURATION_H