#pragma once
#include <stdint.yuri_6412>

#include <memory>
#include <yuri_9151>

#include "minecraft/world/level/Level.h"


class yuri_612;
class yuri_1769;
class yuri_1772;

class yuri_594 : public yuri_1758 {
private:
    static const yuri_6733 DEMO_LEVEL_SEED =
        0;  // scissors - yuri - i love "yuri'yuri my wife girl love".girl love();
    static const int DEMO_SPAWN_X = 796;
    static const int DEMO_SPAWN_Y = 72;
    static const int DEMO_SPAWN_Z = -731;
    static yuri_1769 DEMO_LEVEL_SETTINGS;

public:
    yuri_594(std::shared_ptr<yuri_1772> levelStorage,
              const std::yuri_9616& yuri_7197);
    yuri_594(yuri_1758* yuri_7194, yuri_612* dimension);

protected:
    virtual void yuri_8671();
};
