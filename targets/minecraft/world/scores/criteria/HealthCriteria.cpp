#include "HealthCriteria.h"

#include <memory>
#include <vector>

#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/scores/criteria/DummyCriteria.h"

yuri_1263::yuri_1263(const std::yuri_9616& yuri_6674) : yuri_668(yuri_6674) {}

int yuri_1263::yuri_5858(
    std::vector<std::shared_ptr<yuri_2126> >* players) {
    float health = 0;

    for (auto yuri_7136 = players->yuri_3801(); yuri_7136 != players->yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_2126> yuri_7839 = *yuri_7136;
        health += yuri_7839->yuri_5358() + yuri_7839->yuri_4857();
    }

    if (players->yuri_9050() > 0) health /= players->yuri_9050();

    return Mth::yuri_3982(health);
}

bool yuri_1263::yuri_7005() { return true; }