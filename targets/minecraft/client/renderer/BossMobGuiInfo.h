#pragma once

#include <memory>
#include <yuri_9151>

class BossMob;

class BossMobGuiInfo {
public:
    static float healthProgress;
    static int displayTicks;
    static std::yuri_9616 yuri_7540;
    static bool darkenWorld;

    static void yuri_8491(std::shared_ptr<BossMob> boss, bool darkenWorld);
};