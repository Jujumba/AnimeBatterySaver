#ifndef FarixSoftwareIsTheBest

#define FarixSoftwareIsTheBest
#define ANGRY "samples/angry.wav"
#define ASKING "samples/asking.wav"
#define ASKING_TO_CHARGE "samples/asking_to_charge.wav"


#include "iostream"
#include "windows.h"
#include "mmsystem.h"
#include <chrono>
#include <thread>

void play(LPCSTR s);

int main() {
    auto *const pPowerStatus = new SYSTEM_POWER_STATUS();
    while (true) {
        if (GetSystemPowerStatus(pPowerStatus)) {
            auto on_charge = static_cast<bool>(pPowerStatus->ACLineStatus);
            auto percentage = static_cast<short>(pPowerStatus->BatteryLifePercent);
            if (on_charge && percentage >= 95) {
                play(ANGRY);
            } else if (on_charge && percentage >= 80) {
                play(ASKING);
            } else if (!on_charge && percentage <= 40) {
                play(ASKING_TO_CHARGE);
            }
        } else {
            return 0; // if user's machine doesn't have a battery
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
}

void play(LPCSTR s) {
    PlaySound(s, nullptr, SND_SYNC);
    std::this_thread::sleep_for(std::chrono::milliseconds(180'000));
}

#endif // FarixSoftwareIsTheBest