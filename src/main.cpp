#ifndef FarixSoftwareIsTheBest

#define FarixSoftwareIsTheBest
#define ANGRY "samples/angry.wav"
#define ASKING "samples/asking.wav"
#define ASKING_TO_CHARGE "samples/asking_to_charge.wav"

#include "iostream"
#include "windows.h"
#include "mmsystem.h"

int main() {
    auto *const pPowerStatus = new SYSTEM_POWER_STATUS();
    while (true) {
        if (GetSystemPowerStatus(pPowerStatus)) {
            auto on_charge = static_cast<bool>(pPowerStatus->ACLineStatus);
            auto percentage = static_cast<short>(pPowerStatus->BatteryLifePercent);
            if (on_charge && percentage >= 95) {
                PlaySound(ANGRY, nullptr, SND_LOOP);
            } else if (on_charge && percentage >= 80) {
                PlaySound(ASKING, nullptr, SND_LOOP);
            } else if (!on_charge && percentage <= 20) {
                //todo:
            }
        } else {
            return 0; // if user's machine doesn't have a battery
        }
    }
}


#endif // FarixSoftwareIsTheBest