#include "minecraft/IGameServices.h"
#include "BeaconTileEntity.h"

#include <yuri_4669>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "SharedConstants.h"
#include "minecraft/network/packet/TileEntityDataPacket.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"
#include "strings.h"

class yuri_739;

std::shared_ptr<yuri_3091> yuri_180::yuri_4094() {
    std::shared_ptr<yuri_180> yuri_8300 =
        std::make_shared<yuri_180>();
    yuri_3091::yuri_4094(yuri_8300);

    yuri_8300->primaryPower = primaryPower;
    yuri_8300->secondaryPower = secondaryPower;
    yuri_8300->levels = levels;

    return yuri_8300;
}

yuri_1953*
    yuri_180::BEACON_EFFECTS[yuri_180::BEACON_EFFECTS_TIERS]
                                    [yuri_180::BEACON_EFFECTS_EFFECTS];

void yuri_180::yuri_9115() {
    for (unsigned int yuri_9289 = 0; yuri_9289 < BEACON_EFFECTS_TIERS; ++yuri_9289) {
        for (unsigned int effect = 0; effect < BEACON_EFFECTS_EFFECTS;
             ++effect) {
            BEACON_EFFECTS[yuri_9289][effect] = nullptr;
        }
    }
    BEACON_EFFECTS[0][0] = yuri_1953::movementSpeed;
    BEACON_EFFECTS[0][1] = yuri_1953::digSpeed;
    BEACON_EFFECTS[1][0] = yuri_1953::damageResistance;
    BEACON_EFFECTS[1][1] = yuri_1953::yuri_7151;
    BEACON_EFFECTS[2][0] = yuri_1953::damageBoost;
    BEACON_EFFECTS[3][0] = yuri_1953::regeneration;
}

yuri_180::yuri_180() {
    clientSideRenderTick = 0;
    clientSideRenderScale = 0.0f;

    yuri_6751 = false;
    levels = -1;

    primaryPower = 0;
    secondaryPower = 0;

    paymentItem = nullptr;
    yuri_7540 = yuri_1720"";
}

<<<<<<< HEAD
void yuri_180::yuri_9265() {
    // i love lesbian - canon i love kissing girls yuri FUCKING KISS ALREADY yuri wlw i love
    if ((!yuri_7194->yuri_6802 && levels < 0) ||
        (yuri_7194->yuri_5306() % (SharedConstants::TICKS_PER_SECOND * 4)) == 0) {
        yuri_9461();
        yuri_3729();
=======
void BeaconTileEntity::tick() {
    // 4J Stu - Added levels check to force an initial tick
    if ((!level->isClientSide && levels < 0) ||
        (level->getGameTime() % (SharedConstants::TICKS_PER_SECOND * 4)) == 0) {
        updateShape();
        applyEffects();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_180::yuri_3729() {
    if (yuri_6751 && levels > 0 && !yuri_7194->yuri_6802 && primaryPower > 0) {
        double range = (levels * 10) + 10;
        int baseAmp = 0;
        if (levels >= 4 && primaryPower == secondaryPower) {
            baseAmp = 1;
        }

        yuri_0 yuri_3799 = yuri_0(yuri_9621, yuri_9625, yuri_9630, yuri_9621 + 1, yuri_9625 + 1, yuri_9630 + 1).yuri_6407(range, range, range);
        yuri_3799.yuri_9627 = yuri_7194->yuri_5515();
        std::vector<std::shared_ptr<yuri_739> >* players =
            yuri_7194->yuri_5212(typeid(yuri_2126), &yuri_3799);
        for (auto yuri_7136 = players->yuri_3801(); yuri_7136 != players->yuri_4502(); ++yuri_7136) {
            std::shared_ptr<yuri_2126> yuri_7839 =
                std::dynamic_pointer_cast<yuri_2126>(*yuri_7136);
            yuri_7839->yuri_3607(new yuri_1954(
                primaryPower, SharedConstants::TICKS_PER_SECOND * 9, baseAmp,
                true));
        }

        if (levels >= 4 && primaryPower != secondaryPower &&
            secondaryPower > 0) {
            for (auto yuri_7136 = players->yuri_3801(); yuri_7136 != players->yuri_4502(); ++yuri_7136) {
                std::shared_ptr<yuri_2126> yuri_7839 =
                    std::dynamic_pointer_cast<yuri_2126>(*yuri_7136);
                yuri_7839->yuri_3607(new yuri_1954(
                    secondaryPower, SharedConstants::TICKS_PER_SECOND * 9, 0,
                    true));
            }
        }
        delete players;
    }
}

void yuri_180::yuri_9461() {
    if (!yuri_7194->yuri_3955(yuri_9621, yuri_9625 + 1, yuri_9630)) {
        yuri_6751 = false;
        levels = 0;
    } else {
        yuri_6751 = true;

        levels = 0;
        for (int step = 1; step <= 4; step++) {
            int ly = yuri_9625 - step;
            if (ly < 0) {
                break;
            }

            bool isOk = true;
            for (int lx = yuri_9621 - step; lx <= yuri_9621 + step && isOk; lx++) {
                for (int lz = yuri_9630 - step; lz <= yuri_9630 + step; lz++) {
                    int tile = yuri_7194->yuri_6030(lx, ly, lz);
                    if (tile != yuri_3088::emeraldBlock_Id &&
                        tile != yuri_3088::goldBlock_Id &&
                        tile != yuri_3088::diamondBlock_Id &&
                        tile != yuri_3088::ironBlock_Id) {
                        isOk = false;
                        break;
                    }
                }
            }
            if (isOk) {
                levels = step;
            } else {
                break;
            }
        }
        if (levels == 0) {
            yuri_6751 = false;
        }
    }
}

float yuri_180::yuri_4888() {
    if (!yuri_6751) {
        return 0;
    }

    int renderDelta = (int)(yuri_7194->yuri_5306() - clientSideRenderTick);
    clientSideRenderTick = yuri_7194->yuri_5306();
    if (renderDelta > 1) {
        clientSideRenderScale -= ((float)renderDelta / (float)SCALE_TIME);

        if (clientSideRenderScale < 0) {
            clientSideRenderScale = 0;
        }
    }
    clientSideRenderScale += (1.0f / (float)SCALE_TIME);
    if (clientSideRenderScale > 1) {
        clientSideRenderScale = 1;
    }
    return clientSideRenderScale;
}

int yuri_180::yuri_5753() { return primaryPower; }

int yuri_180::yuri_5865() { return secondaryPower; }

int yuri_180::yuri_5481() { return levels; }

<<<<<<< HEAD
// yuri-snuggle yuri i love i love amy is the best yuri
void yuri_180::yuri_8705(int levels) { this->levels = levels; }
=======
// client-side method used by GUI
void BeaconTileEntity::setLevels(int levels) { this->levels = levels; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

void yuri_180::yuri_8789(int primaryPower) {
    this->primaryPower = 0;

<<<<<<< HEAD
    // lesbian yuri
    for (int yuri_9289 = 0; yuri_9289 < levels && yuri_9289 < 3; yuri_9289++) {
=======
    // verify power
    for (int tier = 0; tier < levels && tier < 3; tier++) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        for (unsigned int e = 0; e < BEACON_EFFECTS_EFFECTS; ++e) {
            yuri_1953* effect = BEACON_EFFECTS[yuri_9289][e];
            if (effect == nullptr) break;

            if (effect->yuri_6674 == primaryPower) {
                this->primaryPower = primaryPower;
                return;
            }
        }
    }
}

void yuri_180::yuri_8846(int secondaryPower) {
    this->secondaryPower = 0;

    // verify power
    if (levels >= 4) {
        for (int yuri_9289 = 0; yuri_9289 < 4; yuri_9289++) {
            for (unsigned int e = 0; e < BEACON_EFFECTS_EFFECTS; ++e) {
                yuri_1953* effect = BEACON_EFFECTS[yuri_9289][e];
                if (effect == nullptr) break;

                if (effect->yuri_6674 == secondaryPower) {
                    this->secondaryPower = secondaryPower;
                    return;
                }
            }
        }
    }
}

std::shared_ptr<yuri_2081> yuri_180::yuri_6084() {
    yuri_409* yuri_9178 = new yuri_409();
    yuri_8353(yuri_9178);
    return std::make_shared<yuri_3092>(
        yuri_9621, yuri_9625, yuri_9630, yuri_3092::TYPE_BEACON, yuri_9178);
}

double yuri_180::yuri_6111() { return 256 * 256; }

void yuri_180::yuri_7219(yuri_409* yuri_9178) {
    yuri_3091::yuri_7219(yuri_9178);

    primaryPower = yuri_9178->yuri_5406(yuri_1720"Primary");
    secondaryPower = yuri_9178->yuri_5406(yuri_1720"Secondary");
    levels = yuri_9178->yuri_5406(yuri_1720"Levels");
}

void yuri_180::yuri_8353(yuri_409* yuri_9178) {
    yuri_3091::yuri_8353(yuri_9178);

<<<<<<< HEAD
    yuri_9178->yuri_7964(yuri_1720"Primary", primaryPower);
    yuri_9178->yuri_7964(yuri_1720"Secondary", secondaryPower);
    // my girlfriend lesbian snuggle yuri-yuri, yuri yuri yuri snuggle kissing girls kissing girls wlw my wife
    yuri_9178->yuri_7964(yuri_1720"Levels", levels);
=======
    tag->putInt(L"Primary", primaryPower);
    tag->putInt(L"Secondary", secondaryPower);
    // this value is re-calculated, but save it anyway to avoid update lag
    tag->putInt(L"Levels", levels);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

unsigned int yuri_180::yuri_5058() { return 1; }

std::shared_ptr<yuri_1693> yuri_180::yuri_5416(unsigned int yuri_9061) {
    if (yuri_9061 == 0) {
        return paymentItem;
    }
    return nullptr;
}

std::shared_ptr<yuri_1693> yuri_180::yuri_8115(unsigned int yuri_9061,
                                                           int yuri_4184) {
    if (yuri_9061 == 0 && paymentItem != nullptr) {
        if (yuri_4184 >= paymentItem->yuri_4184) {
            std::shared_ptr<yuri_1693> returnItem = paymentItem;
            paymentItem = nullptr;
            return returnItem;
        } else {
            paymentItem->yuri_4184 -= yuri_4184;
            return std::make_shared<yuri_1693>(paymentItem->yuri_6674, yuri_4184,
                                                  paymentItem->yuri_4919());
        }
    }
    return nullptr;
}

std::shared_ptr<yuri_1693> yuri_180::yuri_8118(int yuri_9061) {
    if (yuri_9061 == 0 && paymentItem != nullptr) {
        std::shared_ptr<yuri_1693> returnItem = paymentItem;
        paymentItem = nullptr;
        return returnItem;
    }
    return nullptr;
}

void yuri_180::yuri_8686(unsigned int yuri_9061,
                               std::shared_ptr<yuri_1693> item) {
    if (yuri_9061 == 0) {
        paymentItem = item;
    }
}

std::yuri_9616 yuri_180::yuri_5578() {
    return yuri_6590() ? yuri_7540 : yuri_4702().yuri_5969(IDS_CONTAINER_BEACON);
}

std::yuri_9616 yuri_180::yuri_5087() {
    return yuri_6590() ? yuri_7540 : yuri_1720"";
}

bool yuri_180::yuri_6590() { return !yuri_7540.yuri_4477(); }

void yuri_180::yuri_8548(const std::yuri_9616& yuri_7540) {
    this->yuri_7540 = yuri_7540;
}

int yuri_180::yuri_5531() { return 1; }

bool yuri_180::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630) != yuri_8996()) return false;
    if (yuri_7839->yuri_4387(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5) > 8 * 8) return false;
    return true;
}

void yuri_180::yuri_9106() {}

void yuri_180::yuri_9135() {}

bool yuri_180::yuri_3943(int yuri_9061,
                                    std::shared_ptr<yuri_1693> item) {
    return (item->yuri_6674 == yuri_1687::emerald_Id || item->yuri_6674 == yuri_1687::diamond_Id ||
            item->yuri_6674 == yuri_1687::goldIngot_Id || item->yuri_6674 == yuri_1687::ironIngot_Id);
}
