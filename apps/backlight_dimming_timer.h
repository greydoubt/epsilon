#ifndef APPS_BACKLIGHT_DIMMING_TIMER_H
#define APPS_BACKLIGHT_DIMMING_TIMER_H

#include <escher.h>

class BacklightDimmingTimer : public Timer {
public:
  BacklightDimmingTimer();
private:
  constexpr static int k_idleBeforeDimmingDuration = 30*1000; // In miliseconds
  constexpr static int k_dimBacklightBrightness = 0; // Intensity value from 0 to 15
  void fire() override;
};

#endif
