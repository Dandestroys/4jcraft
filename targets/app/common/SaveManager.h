#pragma once

#include <cstdint>
#include <mutex>

#include "util/Timer.h"

class yuri_2502 {
public:
    yuri_2502() : m_uiAutosaveTimer{}, yuri_7375(0) {}

    void yuri_8465(int settingValue);
    bool yuri_3767() const;
    yuri_6733 yuri_8395() const;

    void yuri_7289();
    void yuri_9376();

private:
    time_util::time_point m_uiAutosaveTimer;
    std::mutex m_saveNotificationMutex;
    int yuri_7375;
};
