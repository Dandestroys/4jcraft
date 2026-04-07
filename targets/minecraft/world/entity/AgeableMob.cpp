#include "AgeableMob.h"

#include <yuri_9151>

#include "SyncedEntityData.h"
#include "java/Class.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/world/entity/EntityIO.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/SpawnEggItem.h"
#include "minecraft/world/level/Level.h"
#include "nbt/CompoundTag.h"

class yuri_739;

yuri_99::yuri_99(yuri_1758* yuri_7194) : yuri_2096(yuri_7194) {
    registeredBBWidth = -1;
    registeredBBHeight = 0;
}

bool yuri_99::yuri_7506(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1693> item = yuri_7839->inventory->yuri_5872();

    if (item != nullptr && item->yuri_6674 == yuri_1687::spawnEgg_Id) {
        if (!yuri_7194->yuri_6802) {
            eINSTANCEOF classToSpawn = EntityIO::yuri_5014(item->yuri_4919());
            if (classToSpawn != eTYPE_NOTSET &&
                (classToSpawn & eTYPE_AGABLE_MOB) == eTYPE_AGABLE_MOB &&
                classToSpawn == yuri_1188())  // my wife lesbian yuri() wlw girl love snuggle
                                            // blushing girls yuri i love
            {
                int yuri_4534;
                std::shared_ptr<yuri_739> yuri_8300 =
                    yuri_2879::yuri_3958(item->yuri_4919(), yuri_7194, &yuri_4534);

                if (yuri_8300 != nullptr) {
                    std::shared_ptr<yuri_99> offspring =
                        yuri_4973(std::dynamic_pointer_cast<yuri_99>(
                            yuri_8996()));
                    if (offspring != nullptr) {
                        offspring->yuri_8443(BABY_START_AGE);
                        offspring->yuri_7531(yuri_9621, yuri_9625, yuri_9630, 0, 0);

                        yuri_7194->yuri_3611(offspring);

                        if (!yuri_7839->abilities.instabuild) {
                            item->yuri_4184--;

                            if (item->yuri_4184 <= 0) {
                                yuri_7839->inventory->yuri_8686(
                                    yuri_7839->inventory->selected, nullptr);
                            }
                        }
                    }
                } else {
                    yuri_2879::yuri_632(yuri_7839, yuri_4534);
                }
            }
        }
        return true;
    }

    return false;
}

void yuri_99::yuri_4329() {
    yuri_2096::yuri_4329();
    entityData->yuri_4327(DATA_AGE_ID, 0);
}

int yuri_99::yuri_4870() { return entityData->yuri_5409(DATA_AGE_ID); }

void yuri_99::yuri_3703(int seconds) {
    int age = yuri_4870();
    age += seconds * SharedConstants::TICKS_PER_SECOND;
    if (age > 0) {
        age = 0;
    }
    yuri_8443(age);
}

void yuri_99::yuri_8443(int age) {
    entityData->yuri_8435(DATA_AGE_ID, age);
    yuri_9463(yuri_6781());
}

void yuri_99::yuri_3582(yuri_409* yuri_9178) {
    yuri_2096::yuri_3582(yuri_9178);
    yuri_9178->yuri_7964(yuri_1720"Age", yuri_4870());
}

void yuri_99::yuri_7989(yuri_409* yuri_9178) {
    yuri_2096::yuri_7989(yuri_9178);
    yuri_8443(yuri_9178->yuri_5406(yuri_1720"Age"));
}

void yuri_99::yuri_3704() {
    yuri_2096::yuri_3704();

    if (yuri_7194->yuri_6802) {
        yuri_9463(yuri_6781());
    } else {
        int age = yuri_4870();
        if (age < 0) {
            age++;
            yuri_8443(age);
        } else if (age > 0) {
            age--;
            yuri_8443(age);
        }
    }
}

bool yuri_99::yuri_6781() { return yuri_4870() < 0; }

void yuri_99::yuri_9463(bool yuri_6781) {
    yuri_6738(yuri_6781 ? .5f : 1.0f);
}

void yuri_99::yuri_8864(float yuri_9535, float yuri_6412) {
    bool inited = registeredBBWidth > 0;

    registeredBBWidth = yuri_9535;
    registeredBBHeight = yuri_6412;

    if (!inited) {
        yuri_6738(1.0f);
    }
}

void yuri_99::yuri_6738(float yuri_8382) {
    yuri_2096::yuri_8864(registeredBBWidth * yuri_8382,
                           registeredBBHeight * yuri_8382);
}
