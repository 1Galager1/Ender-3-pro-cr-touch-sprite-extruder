// Configuration_adv.h — complements Configuration.h
// ---------------------------------------------------------------------------

#ifndef CONFIGURATION_ADV_H
#define CONFIGURATION_ADV_H

// Restore the saved mesh automatically after G28 (so saved mesh is applied without needing M420 S1)
#define RESTORE_LEVELING_AFTER_G28

// Fade leveling over first layers (gentle fade to natural first layers)
#define ENABLE_LEVELING_FADE_HEIGHT
#define ENABLE_LEVELING_FADE_ONLY_ONCE

// BLTouch / CR-Touch sensible defaults
#ifdef BLTOUCH
  #define BLTOUCH_DELAY 500   // ms delay after deploy/stow to allow probe to settle
  // #define BLTOUCH_SET_5V_MODE // Uncomment only if required by your CR-Touch docs
#endif

// Keep other advanced features disabled to keep the build simple for a beginner.

#endif // CONFIGURATION_ADV_H