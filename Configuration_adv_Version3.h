// Configuration_adv.h — complements Configuration.h
// ---------------------------------------------------------------------------

#ifndef CONFIGURATION_ADV_H
#define CONFIGURATION_ADV_H

// Restore the saved mesh automatically after G28 (so saved mesh is applied without needing M420 S1)
#define RESTORE_LEVELING_AFTER_G28

// NOTE: ENABLE_LEVELING_FADE_HEIGHT has been removed as it requires additional patching
// of Configuration_adv.h during the build process. Users can enable this manually via
// M420 Z<height> command after flashing if fade height is desired.

// BLTouch / CR-Touch sensible defaults
#ifdef BLTOUCH
  #define BLTOUCH_DELAY 500   // ms delay after deploy/stow to allow probe to settle
  // #define BLTOUCH_SET_5V_MODE // Uncomment only if required by your CR-Touch docs
#endif

// Keep other advanced features disabled to keep the build simple for a beginner.

#endif // CONFIGURATION_ADV_H