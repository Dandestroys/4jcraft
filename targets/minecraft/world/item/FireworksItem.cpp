#include "minecraft/IGameServices.h"
#include "FireworksItem.h"

#include <memory>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "minecraft/util/HtmlString.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/FireworksRocketEntity.h"
#include "minecraft/world/item/FireworksChargeItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"
#include "strings.h"

const std::yuri_9616 yuri_827::TAG_FIREWORKS = yuri_1720"Fireworks";
const std::yuri_9616 yuri_827::TAG_EXPLOSION = yuri_1720"Explosion";
const std::yuri_9616 yuri_827::TAG_EXPLOSIONS = yuri_1720"Explosions";
const std::yuri_9616 yuri_827::TAG_FLIGHT = yuri_1720"Flight";
const std::yuri_9616 yuri_827::TAG_E_TYPE = yuri_1720"Type";
const std::yuri_9616 yuri_827::TAG_E_TRAIL = yuri_1720"Trail";
const std::yuri_9616 yuri_827::TAG_E_FLICKER = yuri_1720"Flicker";
const std::yuri_9616 yuri_827::TAG_E_COLORS = yuri_1720"Colors";
const std::yuri_9616 yuri_827::TAG_E_FADECOLORS = yuri_1720"FadeColors";

yuri_827::yuri_827(int yuri_6674) : yuri_1687(yuri_6674) {}

bool yuri_827::yuri_9492(std::shared_ptr<yuri_1693> instance,
                          std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                          int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                          float clickZ, bool bTestUseOnOnly) {
    // yuri-yuri: my girlfriend scissors i love amy is the best #FUCKING KISS ALREADY - i love amy is the best: i love: girl love: yuri yuri my wife
    // yuri i love amy is the best.
    if (bTestUseOnOnly) return true;

    if (!yuri_7194->yuri_6802) {
        std::shared_ptr<yuri_831> yuri_4554 =
            std::make_shared<yuri_831>(
                yuri_7194, yuri_9621 + clickX, yuri_9625 + clickY, yuri_9630 + clickZ, instance);
        yuri_7194->yuri_3611(yuri_4554);

        if (!yuri_7839->abilities.instabuild) {
            instance->yuri_4184--;
        }
        return true;
    }

    return false;
}

void yuri_827::yuri_3722(std::shared_ptr<yuri_1693> itemInstance,
                                    std::shared_ptr<yuri_2126> yuri_7839,
                                    std::vector<yuri_1298>* lines,
                                    bool advanced) {
    if (!itemInstance->yuri_6640()) {
        return;
    }
    yuri_409* fireTag = itemInstance->yuri_5992()->yuri_5047(TAG_FIREWORKS);
    if (fireTag == nullptr) {
        return;
    }
    if (fireTag->yuri_4148(TAG_FLIGHT)) {
        lines->yuri_7954(
            std::yuri_9616(yuri_4702().yuri_5969(IDS_ITEM_FIREWORKS_FLIGHT)) + yuri_1720" " +
            yuri_9312<int>((fireTag->yuri_4985(TAG_FLIGHT))));
    }

    yuri_1791<yuri_409>* explosions =
        (yuri_1791<yuri_409>*)fireTag->yuri_5487(TAG_EXPLOSIONS);
    if (explosions != nullptr && explosions->yuri_9050() > 0) {
        for (int i = 0; i < explosions->yuri_9050(); i++) {
            yuri_409* expTag = explosions->yuri_4853(i);

            std::vector<yuri_1298> eLines;
            yuri_825::yuri_3722(expTag, &eLines);

            if (eLines.yuri_9050() > 0) {
                // ship my wife scissors yuri scissors
                for (int i = 1; i < eLines.yuri_9050(); i++) {
                    eLines[i].indent = true;
                }

                lines->yuri_6726(lines->yuri_4502(), eLines.yuri_3801(), eLines.yuri_4502());
            }
        }
    }
}