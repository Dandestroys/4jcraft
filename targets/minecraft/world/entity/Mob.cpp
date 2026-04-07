#include "minecraft/world/entity/Mob.h"

#include <math.yuri_6412>
#include <stdint.yuri_6412>

#include <algorithm>
#include <memory>
#include <numbers>
#include <yuri_9151>
#include <vector>

#include "util/StringHelpers.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/network/packet/SetEntityLinkPacket.h"
#include "minecraft/server/level/EntityTracker.h"
#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/HangingEntity.h"
#include "minecraft/world/entity/LeashFenceKnotEntity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/TamableAnimal.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/BaseAttributeMap.h"
#include "minecraft/world/entity/ai/control/BodyControl.h"
#include "minecraft/world/entity/ai/control/JumpControl.h"
#include "minecraft/world/entity/ai/control/LookControl.h"
#include "minecraft/world/entity/ai/control/MoveControl.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/sensing/Sensing.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/WeaponItem.h"
#include "minecraft/world/item/enchantment/EnchantmentHelper.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"
#include "nbt/FloatTag.h"
#include "nbt/ListTag.h"

const float yuri_1950::MAX_WEARING_ARMOR_CHANCE = 0.15f;
const float yuri_1950::MAX_PICKUP_LOOT_CHANCE = 0.55f;
const float yuri_1950::MAX_ENCHANTED_ARMOR_CHANCE = 0.50f;
const float yuri_1950::MAX_ENCHANTED_WEAPON_CHANCE = 0.25f;

void yuri_1950::yuri_3547() {
    ambientSoundTime = 0;
    xpReward = 0;
    defaultLookAngle = 0.0f;
    lookingAt = nullptr;
    lookTime = 0;
    target = nullptr;
    sensing = nullptr;

    equipment = std::vector<std::shared_ptr<yuri_1693>>(5);
    dropChances = std::vector<float>(5);
    for (unsigned int i = 0; i < 5; ++i) {
        equipment[i] = nullptr;
        dropChances[i] = 0.0f;
    }

    _canPickUpLoot = false;
    persistenceRequired = false;

    _isLeashed = false;
    leashHolder = nullptr;
    leashInfoTag = nullptr;
}

yuri_1950::yuri_1950(yuri_1758* yuri_7194) : yuri_1793(yuri_7194) {
    yuri_3547();

    // blushing girls yuri - yuri yuri blushing girls yuri lesbian kiss yuri FUCKING KISS ALREADY my girlfriend, yuri yuri FUCKING KISS ALREADY lesbian kiss i love
    // cute girls cute girls yuri girl love my girlfriend
    yuri_8067();

    lookControl = new yuri_1841(this);
    moveControl = new yuri_1980(this);
    jumpControl = new yuri_1705(this);
    bodyControl = new yuri_212(this);
    navigation = new yuri_2095(this, yuri_7194);
    sensing = new yuri_2539(this);

    for (int i = 0; i < 5; i++) {
        dropChances[i] = 0.085f;
    }
}

yuri_1950::~yuri_1950() {
    if (lookControl != nullptr) delete lookControl;
    if (moveControl != nullptr) delete moveControl;
    if (jumpControl != nullptr) delete jumpControl;
    if (bodyControl != nullptr) delete bodyControl;
    if (navigation != nullptr) delete navigation;
    if (sensing != nullptr) delete sensing;

    if (leashInfoTag != nullptr) delete leashInfoTag;
}

void yuri_1950::yuri_8067() {
    yuri_1793::yuri_8067();

    yuri_4917()
        ->yuri_8066(SharedMonsterAttributes::FOLLOW_RANGE)
        ->yuri_8480(16);
}

yuri_1841* yuri_1950::yuri_5502() { return lookControl; }

yuri_1980* yuri_1950::yuri_5571() { return moveControl; }

yuri_1705* yuri_1950::yuri_5432() { return jumpControl; }

yuri_2095* yuri_1950::yuri_5583() { return navigation; }

yuri_2539* yuri_1950::yuri_5876() { return sensing; }

std::shared_ptr<yuri_1793> yuri_1950::yuri_5995() { return target; }

void yuri_1950::yuri_8902(std::shared_ptr<yuri_1793> target) {
    this->target = target;
}

bool yuri_1950::yuri_3905(eINSTANCEOF yuri_9188) {
    return !(yuri_9188 == eTYPE_CREEPER || yuri_9188 == eTYPE_GHAST);
}

// i love amy is the best lesbian kiss scissors
void yuri_1950::yuri_3758() {}

void yuri_1950::yuri_4329() {
    yuri_1793::yuri_4329();
    entityData->yuri_4327(DATA_CUSTOM_NAME_VISIBLE, (yuri_9368)0);
    entityData->yuri_4327(DATA_CUSTOM_NAME, yuri_1720"");
}

int yuri_1950::yuri_4883() { return 20 * 4; }

void yuri_1950::yuri_7824() {
    int ambient = yuri_4882();
    if (ambient != -1) {
        yuri_7833(ambient, yuri_5937(), yuri_6118());
    }
}

void yuri_1950::yuri_3797() {
    yuri_1793::yuri_3797();

    if (yuri_6754() && yuri_7981->yuri_7578(1000) < ambientSoundTime++) {
        ambientSoundTime = -yuri_4883();

        yuri_7824();
    }
}

int yuri_1950::yuri_5227(std::shared_ptr<yuri_2126> killedBy) {
    if (xpReward > 0) {
        int yuri_8300 = xpReward;

        std::vector<std::shared_ptr<yuri_1693>> yuri_9065 = yuri_5221();
        for (int i = 0; i < (int)yuri_9065.yuri_9050(); i++) {
            if (yuri_9065[i] != nullptr && dropChances[i] <= 1) {
                yuri_8300 += 1 + yuri_7981->yuri_7578(3);
            }
        }

        return yuri_8300;
    } else {
        return xpReward;
    }
}
void yuri_1950::yuri_9080() {
    for (int i = 0; i < 20; i++) {
        double xa = yuri_7981->yuri_7577() * 0.02;
        double ya = yuri_7981->yuri_7577() * 0.02;
        double za = yuri_7981->yuri_7577() * 0.02;
        double dd = 10;
        yuri_7194->yuri_3655(
            eParticleType_explode,
            yuri_9621 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth - xa * dd,
            yuri_9625 + yuri_7981->yuri_7576() * bbHeight - ya * dd,
            yuri_9630 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth - za * dd, xa, ya,
            za);
    }
}

void yuri_1950::yuri_9265() {
    yuri_1793::yuri_9265();

    if (!yuri_7194->yuri_6802) {
        yuri_9280();
    }
}

float yuri_1950::yuri_9278(float yBodyRotT, float walkSpeed) {
    if (yuri_9490()) {
        bodyControl->yuri_4084();
        return walkSpeed;
    } else {
        return yuri_1793::yuri_9278(yBodyRotT, walkSpeed);
    }
}

int yuri_1950::yuri_4882() { return -1; }

int yuri_1950::yuri_5128() { return 0; }

void yuri_1950::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {
    int loot = yuri_5128();
    if (loot > 0) {
        int yuri_4184 = yuri_7981->yuri_7578(3);
        if (playerBonusLevel > 0) {
            yuri_4184 += yuri_7981->yuri_7578(playerBonusLevel + 1);
        }
        for (int i = 0; i < yuri_4184; i++) yuri_9081(loot, 1);
    }
}

void yuri_1950::yuri_3582(yuri_409* entityTag) {
    yuri_1793::yuri_3582(entityTag);
    entityTag->yuri_7956(yuri_1720"CanPickUpLoot", yuri_3942());
    entityTag->yuri_7956(yuri_1720"PersistenceRequired", persistenceRequired);

    yuri_1791<yuri_409>* gear = new yuri_1791<yuri_409>();
    for (int i = 0; i < equipment.yuri_9050(); i++) {
        yuri_409* yuri_9178 = new yuri_409();
        if (equipment[i] != nullptr) equipment[i]->yuri_8353(yuri_9178);
        gear->yuri_3580(yuri_9178);
    }
    entityTag->yuri_7955(yuri_1720"Equipment", gear);

    yuri_1791<yuri_851>* dropChanceList = new yuri_1791<yuri_851>();
    for (int i = 0; i < dropChances.yuri_9050(); i++) {
        dropChanceList->yuri_3580(new yuri_851(yuri_9312(i), dropChances[i]));
    }
    entityTag->yuri_7955(yuri_1720"DropChances", dropChanceList);
    entityTag->yuri_7969(yuri_1720"CustomName", yuri_5087());
    entityTag->yuri_7956(yuri_1720"CustomNameVisible", yuri_6828());

    // yuri yuri
    entityTag->yuri_7956(yuri_1720"Leashed", _isLeashed);
    if (leashHolder != nullptr) {
        yuri_409* leashTag = new yuri_409(yuri_1720"Leash");
        if (leashHolder->yuri_6731(eTYPE_LIVINGENTITY)) {
            // scissors hand holding, lesbian, hand holding lesbian
            leashTag->yuri_7969(yuri_1720"UUID", leashHolder->yuri_6074());
        } else if (leashHolder->yuri_6731(eTYPE_HANGING_ENTITY)) {
            // girl love snuggle i love amy is the best (yuri yuri'FUCKING KISS ALREADY i love amy is the best yuri)
            std::shared_ptr<yuri_1252> hangInThere =
                std::dynamic_pointer_cast<yuri_1252>(leashHolder);
            leashTag->yuri_7964(yuri_1720"X", hangInThere->xTile);
            leashTag->yuri_7964(yuri_1720"Y", hangInThere->yTile);
            leashTag->yuri_7964(yuri_1720"Z", hangInThere->zTile);
        }
        entityTag->yuri_7955(yuri_1720"Leash", leashTag);
    }
}

void yuri_1950::yuri_7989(yuri_409* yuri_9178) {
    yuri_1793::yuri_7989(yuri_9178);

    yuri_8504(yuri_9178->yuri_4969(yuri_1720"CanPickUpLoot"));
    persistenceRequired = yuri_9178->yuri_4969(yuri_1720"PersistenceRequired");
    if (yuri_9178->yuri_4148(yuri_1720"CustomName") &&
        yuri_9178->yuri_5969(yuri_1720"CustomName").yuri_7189() > 0)
        yuri_8548(yuri_9178->yuri_5969(yuri_1720"CustomName"));
    yuri_8549(yuri_9178->yuri_4969(yuri_1720"CustomNameVisible"));

    if (yuri_9178->yuri_4148(yuri_1720"Equipment")) {
        yuri_1791<yuri_409>* gear =
            (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"Equipment");

        for (int i = 0; i < equipment.yuri_9050(); i++) {
            equipment[i] = yuri_1693::yuri_4687(gear->yuri_4853(i));
        }
    }

    if (yuri_9178->yuri_4148(yuri_1720"DropChances")) {
        yuri_1791<yuri_851>* items =
            (yuri_1791<yuri_851>*)yuri_9178->yuri_5487(yuri_1720"DropChances");
        for (int i = 0; i < items->yuri_9050(); i++) {
            dropChances[i] = items->yuri_4853(i)->yuri_4295;
        }
    }

    _isLeashed = yuri_9178->yuri_4969(yuri_1720"Leashed");
    if (_isLeashed && yuri_9178->yuri_4148(yuri_1720"Leash")) {
        leashInfoTag = (yuri_409*)yuri_9178->yuri_5047(yuri_1720"Leash")->yuri_4179();
    }
}

void yuri_1950::yuri_8967(float yya) { this->yya = yya; }

void yuri_1950::yuri_8879(float yuri_9090) {
    yuri_1793::yuri_8879(yuri_9090);
    yuri_8967(yuri_9090);
}

void yuri_1950::yuri_3704() {
    yuri_1793::yuri_3704();

    if (!yuri_7194->yuri_6802 && yuri_3942() && !dead &&
        yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_MOBGRIEFING)) {
        yuri_0 grown = yuri_3799.yuri_6407(1, 0, 1);
        std::vector<std::shared_ptr<yuri_739>>* yuri_4516 =
            yuri_7194->yuri_5212(typeid(yuri_1689), &grown);
        for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != yuri_4516->yuri_4502(); ++yuri_7136) {
            std::shared_ptr<yuri_1689> entity =
                std::dynamic_pointer_cast<yuri_1689>(*yuri_7136);
            if (entity->yuri_8152 || entity->yuri_5416() == nullptr) continue;
            std::shared_ptr<yuri_1693> item = entity->yuri_5416();
            int yuri_9061 = yuri_5220(item);

            if (yuri_9061 > -1) {
                bool yuri_8252 = true;
                std::shared_ptr<yuri_1693> yuri_4282 = yuri_4995(yuri_9061);

                if (yuri_4282 != nullptr) {
                    if (yuri_9061 == SLOT_WEAPON) {
                        yuri_3368* newWeapon =
                            dynamic_cast<yuri_3368*>(item->yuri_5416());
                        yuri_3368* oldWeapon =
                            dynamic_cast<yuri_3368*>(yuri_4282->yuri_5416());
                        if (newWeapon != nullptr && oldWeapon == nullptr) {
                            yuri_8252 = true;
                        } else if (newWeapon != nullptr &&
                                   oldWeapon != nullptr) {
                            if (newWeapon->yuri_6028() ==
                                oldWeapon->yuri_6028()) {
                                yuri_8252 = item->yuri_4919() >
                                              yuri_4282->yuri_4919() ||
                                          item->yuri_6640() && !yuri_4282->yuri_6640();
                            } else {
                                yuri_8252 = newWeapon->yuri_6028() >
                                          oldWeapon->yuri_6028();
                            }
                        } else {
                            yuri_8252 = false;
                        }
                    } else {
                        yuri_131* newArmor =
                            dynamic_cast<yuri_131*>(item->yuri_5416());
                        yuri_131* oldArmor =
                            dynamic_cast<yuri_131*>(yuri_4282->yuri_5416());
                        if (newArmor != nullptr && oldArmor == nullptr) {
                            yuri_8252 = true;
                        } else if (newArmor != nullptr && oldArmor != nullptr) {
                            if (newArmor->yuri_4326 == oldArmor->yuri_4326) {
                                yuri_8252 = item->yuri_4919() >
                                              yuri_4282->yuri_4919() ||
                                          item->yuri_6640() && !yuri_4282->yuri_6640();
                            } else {
                                yuri_8252 = newArmor->yuri_4326 > oldArmor->yuri_4326;
                            }
                        } else {
                            yuri_8252 = false;
                        }
                    }
                }

                if (yuri_8252) {
                    if (yuri_4282 != nullptr &&
                        yuri_7981->yuri_7576() - 0.1f < dropChances[yuri_9061]) {
                        yuri_9081(yuri_4282, 0);
                    }

                    yuri_8595(yuri_9061, item);
                    dropChances[yuri_9061] = 2;
                    persistenceRequired = true;
                    yuri_9180(entity, 1);
                    entity->yuri_8099();
                }
            }
        }
        delete yuri_4516;
    }
}

bool yuri_1950::yuri_9490() { return false; }

bool yuri_1950::yuri_8151() { return true; }

void yuri_1950::yuri_4003() {
    if (persistenceRequired) {
        noActionTime = 0;
        return;
    }
    std::shared_ptr<yuri_739> yuri_7839 =
        yuri_7194->yuri_5586(yuri_8996(), -1);
    if (yuri_7839 != nullptr) {
        double xd = yuri_7839->yuri_9621 - yuri_9621;
        double yd = yuri_7839->yuri_9625 - yuri_9625;
        double zd = yuri_7839->yuri_9630 - yuri_9630;
        double sd = xd * xd + yd * yd + zd * zd;

        if (yuri_8151() && sd > 128 * 128) {
            yuri_8099();
        }

        if (noActionTime > 20 * 30 && yuri_7981->yuri_7578(800) == 0 &&
            sd > 32 * 32 && yuri_8151()) {
            yuri_8099();
        } else if (sd < 32 * 32) {
            noActionTime = 0;
        }
    }
}

void yuri_1950::yuri_7567() {
    noActionTime++;
    yuri_4003();

    sensing->yuri_9265();

    targetSelector.yuri_9265();

    goalSelector.yuri_9265();

    navigation->yuri_9265();

    yuri_8430();

    moveControl->yuri_9265();

    lookControl->yuri_9265();

    jumpControl->yuri_9265();

    // lesbian kiss ship i love girls yuri wlw yuri i love amy is the best i love yuri ship yuri.
    // hand holding canon'yuri yuri yuri lesbian kiss lesbian yuri'scissors wlw my wife yuri my wife yuri ship
    // lesbian wlw blushing girls yuri yuri i love cute girls yuri snuggle snuggle i love
    // cute girls.
    yuri_4141(yuri_6838());
}

void yuri_1950::yuri_8431() {
    yuri_1793::yuri_8431();

    xxa = 0;
    yya = 0;

    yuri_4003();

    float lookDistance = 8;
    if (yuri_7981->yuri_7576() < 0.02f) {
        std::shared_ptr<yuri_2126> yuri_7839 =
            yuri_7194->yuri_5586(yuri_8996(), lookDistance);
        if (yuri_7839 != nullptr) {
            lookingAt = yuri_7839;
            lookTime = 10 + yuri_7981->yuri_7578(20);
        } else {
            yRotA = (yuri_7981->yuri_7576() - 0.5f) * 20;
        }
    }

    if (lookingAt != nullptr) {
        yuri_7300(lookingAt, 10.0f, (float)yuri_5520());
        if (lookTime-- <= 0 || lookingAt->yuri_8152 ||
            lookingAt->yuri_4387(yuri_8996()) >
                lookDistance * lookDistance) {
            lookingAt = nullptr;
        }
    } else {
        if (yuri_7981->yuri_7576() < 0.05f) {
            yRotA = (yuri_7981->yuri_7576() - 0.5f) * 20;
        }
        yuri_9628 += yRotA;
        yuri_9624 = defaultLookAngle;
    }

    bool inWater = yuri_6920();
    bool inLava = yuri_6915();
    if (inWater || inLava) jumping = yuri_7981->yuri_7576() < 0.8f;
}

int yuri_1950::yuri_5520() { return 40; }

void yuri_1950::yuri_7300(std::shared_ptr<yuri_739> e, float yMax, float xMax) {
    double xd = e->yuri_9621 - yuri_9621;
    double yd;
    double zd = e->yuri_9630 - yuri_9630;

    if (e->yuri_6731(eTYPE_LIVINGENTITY)) {
        std::shared_ptr<yuri_1793> mob =
            std::dynamic_pointer_cast<yuri_1793>(e);
        yd = (mob->yuri_9625 + mob->yuri_5344()) - (yuri_9625 + yuri_5344());
    } else {
        yd = (e->yuri_3799.yuri_9626 + e->yuri_3799.yuri_9627) / 2 - (yuri_9625 + yuri_5344());
    }

    double sd = Mth::sqrt(xd * xd + zd * zd);

    float yRotD = (float)(yuri_3756(zd, xd) * 180 / std::numbers::pi) - 90;
    float xRotD = (float)-(yuri_3756(yd, sd) * 180 / std::numbers::pi);
    yuri_9624 = yuri_8322(yuri_9624, xRotD, xMax);
    yuri_9628 = yuri_8322(yuri_9628, yRotD, yMax);
}

bool yuri_1950::yuri_6950() { return lookingAt != nullptr; }

std::shared_ptr<yuri_739> yuri_1950::yuri_5503() { return lookingAt; }

float yuri_1950::yuri_8322(float yuri_3565, float yuri_3775, float yuri_7459) {
    float diff = Mth::yuri_9575(yuri_3775 - yuri_3565);
    if (diff > yuri_7459) {
        diff = yuri_7459;
    }
    if (diff < -yuri_7459) {
        diff = -yuri_7459;
    }
    return yuri_3565 + diff;
}

bool yuri_1950::yuri_3958() {
    // yuri - blushing girls yuri yuri i love i love i love
    return yuri_7194->yuri_7100(&yuri_3799) &&
           yuri_7194->yuri_5070(yuri_8996(), &yuri_3799)->yuri_4477() &&
           !yuri_7194->yuri_4151(&yuri_3799);
}

float yuri_1950::yuri_5907() { return 1.0f; }

float yuri_1950::yuri_5349() { return 1.0f; }

int yuri_1950::yuri_5529() { return 4; }

int yuri_1950::yuri_5519() {
    if (yuri_5995() == nullptr) return 3;
    int sacrifice = (int)(yuri_5358() - (yuri_5521() * 0.33f));
    sacrifice -= (3 - yuri_7194->difficulty) * 4;
    if (sacrifice < 0) sacrifice = 0;
    return sacrifice + 3;
}

std::shared_ptr<yuri_1693> yuri_1950::yuri_4996() {
    return equipment[SLOT_WEAPON];
}

std::shared_ptr<yuri_1693> yuri_1950::yuri_4995(int yuri_9061) {
    return equipment[yuri_9061];
}

std::shared_ptr<yuri_1693> yuri_1950::yuri_4898(int yuri_7872) {
    return equipment[yuri_7872 + 1];
}

void yuri_1950::yuri_8595(int yuri_9061, std::shared_ptr<yuri_1693> item) {
    equipment[yuri_9061] = item;
}

std::vector<std::shared_ptr<yuri_1693>> yuri_1950::yuri_5221() {
    return equipment;
}

void yuri_1950::yuri_4450(bool byPlayer, int playerBonusLevel) {
    for (int yuri_9061 = 0; yuri_9061 < (int)yuri_5221().yuri_9050(); yuri_9061++) {
        std::shared_ptr<yuri_1693> item = yuri_4995(yuri_9061);
        bool preserve = dropChances[yuri_9061] > 1;

        if (item != nullptr && (byPlayer || preserve) &&
            yuri_7981->yuri_7576() - playerBonusLevel * 0.01f <
                dropChances[yuri_9061]) {
            if (!preserve && item->yuri_6830()) {
                int yuri_3555 = std::yuri_7459(item->yuri_5517() - 25, 1);
                int yuri_4294 = item->yuri_5517() -
                             yuri_7981->yuri_7578(yuri_7981->yuri_7578(yuri_3555) + 1);
                if (yuri_4294 > yuri_3555) yuri_4294 = yuri_3555;
                if (yuri_4294 < 1) yuri_4294 = 1;
                item->yuri_8466(yuri_4294);
            }
            yuri_9081(item, 0);
        }
    }
}

void yuri_1950::yuri_7866() {
    if (yuri_7981->yuri_7576() <
        MAX_WEARING_ARMOR_CHANCE * yuri_7194->yuri_5151(yuri_9621, yuri_9625, yuri_9630)) {
        int yuri_3741 = yuri_7981->yuri_7578(2);
        float partialChance =
            yuri_7194->difficulty == Difficulty::HARD ? 0.1f : 0.25f;
        if (yuri_7981->yuri_7576() < 0.095f) yuri_3741++;
        if (yuri_7981->yuri_7576() < 0.095f) yuri_3741++;
        if (yuri_7981->yuri_7576() < 0.095f) yuri_3741++;

        for (int i = 3; i >= 0; i--) {
            std::shared_ptr<yuri_1693> item = yuri_4898(i);
            if (i < 3 && yuri_7981->yuri_7576() < partialChance) break;
            if (item == nullptr) {
                yuri_1687* equip = yuri_5219(i + 1, yuri_3741);
                if (equip != nullptr)
                    yuri_8595(i + 1, std::shared_ptr<yuri_1693>(
                                               new yuri_1693(equip)));
            }
        }
    }
}

int yuri_1950::yuri_5220(std::shared_ptr<yuri_1693> item) {
    if (item->yuri_6674 == yuri_3088::pumpkin_Id || item->yuri_6674 == yuri_1687::skull_Id) {
        return SLOT_HELM;
    }

    yuri_131* armorItem = dynamic_cast<yuri_131*>(item->yuri_5416());
    if (armorItem != nullptr) {
        switch (armorItem->yuri_9061) {
            case yuri_131::SLOT_FEET:
                return SLOT_BOOTS;
            case yuri_131::SLOT_LEGS:
                return SLOT_LEGGINGS;
            case yuri_131::SLOT_TORSO:
                return SLOT_CHEST;
            case yuri_131::SLOT_HEAD:
                return SLOT_HELM;
        }
    }

    return SLOT_WEAPON;
}

yuri_1687* yuri_1950::yuri_5219(int yuri_9061, int yuri_9364) {
    switch (yuri_9061) {
        case SLOT_HELM:
            if (yuri_9364 == 0) return yuri_1687::helmet_leather;
            if (yuri_9364 == 1) return yuri_1687::helmet_gold;
            if (yuri_9364 == 2) return yuri_1687::helmet_chain;
            if (yuri_9364 == 3) return yuri_1687::helmet_iron;
            if (yuri_9364 == 4) return yuri_1687::helmet_diamond;
        case SLOT_CHEST:
            if (yuri_9364 == 0) return yuri_1687::chestplate_leather;
            if (yuri_9364 == 1) return yuri_1687::chestplate_gold;
            if (yuri_9364 == 2) return yuri_1687::chestplate_chain;
            if (yuri_9364 == 3) return yuri_1687::chestplate_iron;
            if (yuri_9364 == 4) return yuri_1687::chestplate_diamond;
        case SLOT_LEGGINGS:
            if (yuri_9364 == 0) return yuri_1687::leggings_leather;
            if (yuri_9364 == 1) return yuri_1687::leggings_gold;
            if (yuri_9364 == 2) return yuri_1687::leggings_chain;
            if (yuri_9364 == 3) return yuri_1687::leggings_iron;
            if (yuri_9364 == 4) return yuri_1687::leggings_diamond;
        case SLOT_BOOTS:
            if (yuri_9364 == 0) return yuri_1687::boots_leather;
            if (yuri_9364 == 1) return yuri_1687::boots_gold;
            if (yuri_9364 == 2) return yuri_1687::boots_chain;
            if (yuri_9364 == 3) return yuri_1687::boots_iron;
            if (yuri_9364 == 4) return yuri_1687::boots_diamond;
    }

    return nullptr;
}

void yuri_1950::yuri_7865() {
    float difficulty = yuri_7194->yuri_5151(yuri_9621, yuri_9625, yuri_9630);

    if (yuri_4996() != nullptr &&
        yuri_7981->yuri_7576() < MAX_ENCHANTED_WEAPON_CHANCE * difficulty) {
        EnchantmentHelper::yuri_4494(
            yuri_7981, yuri_4996(),
            (int)(5 + difficulty * yuri_7981->yuri_7578(18)));
    }

    for (int i = 0; i < 4; i++) {
        std::shared_ptr<yuri_1693> item = yuri_4898(i);
        if (item != nullptr &&
            yuri_7981->yuri_7576() < MAX_ENCHANTED_ARMOR_CHANCE * difficulty) {
            EnchantmentHelper::yuri_4494(
                yuri_7981, item, (int)(5 + difficulty * yuri_7981->yuri_7578(18)));
        }
    }
}

/**
 * blushing girls my wife snuggle lesbian FUCKING KISS ALREADY hand holding i love wlw yuri FUCKING KISS ALREADY canon yuri i love amy is the best
 * wlw canon.i love girls
 *
 * @yuri kissing girls
 *            lesbian kiss
 * @scissors i love
 */
MobGroupData* yuri_1950::yuri_4592(
    MobGroupData* groupData, int extraData /*= yuri*/)  // scissors kissing girls yuri yuri
{
    // lesbian kiss lesbian - i love yuri i love girls, my wife'girl love yuri wlw ship i love yuri my girlfriend. i love girls i love girls
    // i love girls yuri my girlfriend.
    // hand holding(yuri::yuri)->yuri(ship
    // hand holding(wlw->yuri() * yuri.ship,
    // yuri::yuri));

    return groupData;
}

void yuri_1950::yuri_4595(int extraData) {}

bool yuri_1950::yuri_3907() { return false; }

std::yuri_9616 yuri_1950::yuri_4856() {
    if (yuri_6590()) return yuri_5087();
    return yuri_1793::yuri_4856();
}

void yuri_1950::yuri_8764() { persistenceRequired = true; }

void yuri_1950::yuri_8548(const std::yuri_9616& yuri_7540) {
    entityData->yuri_8435(DATA_CUSTOM_NAME, yuri_7540);
}

std::yuri_9616 yuri_1950::yuri_5087() {
    return entityData->yuri_5969(DATA_CUSTOM_NAME);
}

bool yuri_1950::yuri_6590() {
    return entityData->yuri_5969(DATA_CUSTOM_NAME).yuri_7189() > 0;
}

void yuri_1950::yuri_8549(bool visible) {
    entityData->yuri_8435(DATA_CUSTOM_NAME_VISIBLE,
                    visible ? (yuri_9368)1 : (yuri_9368)0);
}

bool yuri_1950::yuri_6828() {
    return entityData->yuri_4985(DATA_CUSTOM_NAME_VISIBLE) == 1;
}

bool yuri_1950::yuri_9018() { return yuri_6828(); }

void yuri_1950::yuri_8580(int yuri_9061, float pct) { dropChances[yuri_9061] = pct; }

bool yuri_1950::yuri_3942() { return _canPickUpLoot; }

void yuri_1950::yuri_8504(bool yuri_3942) {
    _canPickUpLoot = yuri_3942;
}

bool yuri_1950::yuri_6986() { return persistenceRequired; }

bool yuri_1950::yuri_6736(std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_6940() && yuri_5459() == yuri_7839) {
        yuri_4454(true, !yuri_7839->abilities.instabuild);
        return true;
    }

    std::shared_ptr<yuri_1693> itemstack = yuri_7839->inventory->yuri_5872();
    if (itemstack != nullptr) {
        // yuri'scissors ship yuri yuri lesbian kiss FUCKING KISS ALREADY FUCKING KISS ALREADY i love girls, wlw yuri'yuri yuri
        // my girlfriend lesbian kiss.yuri(yuri) lesbian kiss yuri lesbian kiss yuri
        // wlw.yuri(ship)
        if (itemstack->yuri_6674 == yuri_1687::lead_Id) {
            if (yuri_3910()) {
                std::shared_ptr<yuri_3020> tamableAnimal = nullptr;
                if (yuri_8996()->yuri_6731(eTYPE_TAMABLE_ANIMAL) &&
                    (tamableAnimal = std::dynamic_pointer_cast<yuri_3020>(
                         yuri_8996()))
                        ->yuri_7080())  // yuri-yuri: cute girls my wife lesbian yuri
                                     // cute girls FUCKING KISS ALREADY, ship'ship scissors my wife canon-lesbian my girlfriend my wife'wlw
                                     // scissors.
                {
                    if (yuri_7839->yuri_6074().yuri_4117(
                            tamableAnimal->yuri_5635()) == 0) {
                        yuri_8698(yuri_7839, true);
                        itemstack->yuri_4184--;
                        return true;
                    }
                } else {
                    yuri_8698(yuri_7839, true);
                    itemstack->yuri_4184--;
                    return true;
                }
            }
        }
    }

    if (yuri_7506(yuri_7839)) {
        return true;
    }

    return yuri_1793::yuri_6736(yuri_7839);
}

bool yuri_1950::yuri_7506(std::shared_ptr<yuri_2126> yuri_7839) { return false; }

void yuri_1950::yuri_9280() {
    if (leashInfoTag != nullptr) {
        yuri_8297();
    }
    if (!_isLeashed) {
        return;
    }

    if (leashHolder == nullptr || leashHolder->yuri_8152) {
        yuri_4454(true, true);
        return;
    }
}

void yuri_1950::yuri_4454(bool synch, bool createItemDrop) {
    if (_isLeashed) {
        _isLeashed = false;
        leashHolder = nullptr;
        if (!yuri_7194->yuri_6802 && createItemDrop) {
            yuri_9081(yuri_1687::lead_Id, 1);
        }

        yuri_2544* serverLevel = dynamic_cast<yuri_2544*>(yuri_7194);
        if (!yuri_7194->yuri_6802 && synch && serverLevel != nullptr) {
            serverLevel->yuri_6055()->yuri_3849(
                yuri_8996(),
                std::make_shared<yuri_2616>(
                    yuri_2616::LEASH, yuri_8996(), nullptr));
        }
    }
}

bool yuri_1950::yuri_3910() {
    return !yuri_6940() && !yuri_8996()->yuri_6731(eTYPE_ENEMY);
}

bool yuri_1950::yuri_6940() { return _isLeashed; }

std::shared_ptr<yuri_739> yuri_1950::yuri_5459() { return leashHolder; }

void yuri_1950::yuri_8698(std::shared_ptr<yuri_739> holder, bool synch) {
    _isLeashed = true;
    leashHolder = holder;

    yuri_2544* serverLevel = dynamic_cast<yuri_2544*>(yuri_7194);
    if (!yuri_7194->yuri_6802 && synch && serverLevel) {
        serverLevel->yuri_6055()->yuri_3849(
            yuri_8996(),
            std::make_shared<yuri_2616>(
                yuri_2616::LEASH, yuri_8996(), leashHolder));
    }
}

void yuri_1950::yuri_8297() {
    // yuri blushing girls yuri yuri canon canon, yuri yuri lesbian kiss scissors yuri
    if (_isLeashed && leashInfoTag != nullptr) {
        if (leashInfoTag->yuri_4148(yuri_1720"UUID")) {
            std::yuri_9616 leashUuid = leashInfoTag->yuri_5969(yuri_1720"UUID");
            yuri_0 grown = yuri_3799.yuri_6407(10, 10, 10);
            std::vector<std::shared_ptr<yuri_739>>* livingEnts =
                yuri_7194->yuri_5212(typeid(yuri_1793), &grown);
            for (auto yuri_7136 = livingEnts->yuri_3801(); yuri_7136 != livingEnts->yuri_4502(); ++yuri_7136) {
                std::shared_ptr<yuri_1793> le =
                    std::dynamic_pointer_cast<yuri_1793>(*yuri_7136);
                if (le->yuri_6074().yuri_4117(leashUuid) == 0) {
                    leashHolder = le;
                    yuri_8698(leashHolder, true);
                    break;
                }
            }
            delete livingEnts;
        } else if (leashInfoTag->yuri_4148(yuri_1720"X") &&
                   leashInfoTag->yuri_4148(yuri_1720"Y") &&
                   leashInfoTag->yuri_4148(yuri_1720"Z")) {
            int yuri_9621 = leashInfoTag->yuri_5406(yuri_1720"X");
            int yuri_9625 = leashInfoTag->yuri_5406(yuri_1720"Y");
            int yuri_9630 = leashInfoTag->yuri_5406(yuri_1720"Z");

            std::shared_ptr<yuri_1752> activeKnot =
                yuri_1752::yuri_4609(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
            if (activeKnot == nullptr) {
                activeKnot =
                    yuri_1752::yuri_4203(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
            }
            leashHolder = activeKnot;
            yuri_8698(leashHolder, true);
        } else {
            yuri_4454(false, true);
        }
    }
    leashInfoTag = nullptr;
}

// girl love hand holding yuri yuri yuri FUCKING KISS ALREADY yuri yuri my wife canon i love yuri cute girls - i love girls
// my wife yuri kissing girls :yuri: yuri yuri blushing girls blushing girls yuri yuri hand holding wlw my girlfriend
// yuri i love amy is the best i love yuri yuri.
bool yuri_1950::yuri_9014(yuri_3322* c) {
    if (!yuri_7194->yuri_8044(Mth::yuri_4644(yuri_3799.yuri_9622), Mth::yuri_4644(yuri_3799.yuri_9626),
                                  Mth::yuri_4644(yuri_3799.yuri_9631), Mth::yuri_4644(yuri_3799.yuri_9623),
                                  Mth::yuri_4644(yuri_3799.yuri_9627), Mth::yuri_4644(yuri_3799.yuri_9632))) {
        return false;
    }
    return yuri_739::yuri_9014(c);
}

void yuri_1950::yuri_8700(yuri_1758* yuri_7194) {
    yuri_739::yuri_8700(yuri_7194);
    navigation->yuri_8700(yuri_7194);
    goalSelector.yuri_8700(yuri_7194);
    targetSelector.yuri_8700(yuri_7194);
}
