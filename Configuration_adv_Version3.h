// Configuration_adv.h — complements Configuration.h
// ---------------------------------------------------------------------------
// MINIMAL BUT COMPLETE configuration for reliable boot on Ender 3 Pro V4.2.2
// This file contains essential settings to ensure proper display initialization and boot sequence

#ifndef CONFIGURATION_ADV_H
#define CONFIGURATION_ADV_H

// ========== SERIAL COMMUNICATION ==========
// Set baudrate for serial communication (115200 is standard for Creality boards)
#define BAUDRATE 115200

// ========== DISPLAY & UI SETTINGS ==========
// Boot screen timeout (ms) - helps ensure display initializes properly
#define BOOTSCREEN_TIMEOUT 3000

// Encoder settings for knob-based displays
#define ENCODER_PULSES_PER_STEP 4
#define ENCODER_STEPS_PER_MENU_ITEM 1

// Reverse encoder direction if needed (uncomment if knob turns backwards)
// #define REVERSE_ENCODER_DIRECTION
// #define REVERSE_MENU_DIRECTION

// ========== AUTO BED LEVELING ==========
// Restore the saved mesh automatically after G28 (so saved mesh is applied without needing M420 S1)
#define RESTORE_LEVELING_AFTER_G28

// NOTE: ENABLE_LEVELING_FADE_HEIGHT has been removed as it requires additional patching
// of Configuration_adv.h during the build process. Users can enable this manually via
// M420 Z<height> command after flashing if fade height is desired.

// ========== BLTOUCH / CR-TOUCH SETTINGS ==========
#ifdef BLTOUCH
  #define BLTOUCH_DELAY 500   // ms delay after deploy/stow to allow probe to settle
  // #define BLTOUCH_SET_5V_MODE // Uncomment only if required by your CR-Touch docs
#endif

// ========== THERMAL PROTECTION ==========
// These are enabled by default in Marlin but we ensure they stay enabled
// (Do NOT disable these - they protect against thermal runaway)

// ========== EEPROM SETTINGS ==========
// Allow EEPROM auto-init on first boot (helps prevent corruption issues)
#define EEPROM_AUTO_INIT

// ========== SD CARD ==========
// Enable SD card menu (standard for Creality boards)
#define SDSUPPORT

// ========== STARTUP CONFIGURATION ==========
// Play a beep on startup to confirm boot
#define STARTUP_COMMANDS "M300 S440 P200"

// ========== SAFETY FEATURES ==========
// Keep endstop interrupts enabled for safety
// These are typically enabled by default but we ensure they remain active

// ========== ADVANCED FEATURES (DISABLED FOR MINIMAL BUILD) ==========
// The following are commented out to keep the build minimal and stable
// You can enable these later after confirming the printer boots successfully:
//
// #define LIN_ADVANCE              // Linear advance for better print quality
// #define ARC_SUPPORT              // G2/G3 arc commands
// #define ADVANCED_PAUSE_FEATURE   // M600 filament change
// #define INDIVIDUAL_AXIS_HOMING_MENU  // Home axes individually from menu

#endif // CONFIGURATION_ADV_H