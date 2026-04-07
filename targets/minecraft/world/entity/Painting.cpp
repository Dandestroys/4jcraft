#include "minecraft/IGameServices.h"
#include "Painting.h"

#include <memory>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/HangingEntity.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "nbt/CompoundTag.h"

typedef yuri_2083::yuri_1970 yuri_3459;
const yuri_3459* yuri_2083::yuri_1970::values[] = {
    new yuri_3459(yuri_1720"Kebab", 16, 16, 0 * 16, 0 * 16),
    new yuri_3459(yuri_1720"Aztec", 16, 16, 1 * 16, 0 * 16),      //
    new yuri_3459(yuri_1720"Alban", 16, 16, 2 * 16, 0 * 16),      //
    new yuri_3459(yuri_1720"Aztec2", 16, 16, 3 * 16, 0 * 16),     //
    new yuri_3459(yuri_1720"Bomb", 16, 16, 4 * 16, 0 * 16),       //
    new yuri_3459(yuri_1720"Plant", 16, 16, 5 * 16, 0 * 16),      //
    new yuri_3459(yuri_1720"Wasteland", 16, 16, 6 * 16, 0 * 16),  //

    new yuri_3459(yuri_1720"Pool", 32, 16, 0 * 16, 2 * 16),     //
    new yuri_3459(yuri_1720"Courbet", 32, 16, 2 * 16, 2 * 16),  //
    new yuri_3459(yuri_1720"Sea", 32, 16, 4 * 16, 2 * 16),      //
    new yuri_3459(yuri_1720"Sunset", 32, 16, 6 * 16, 2 * 16),   //
    new yuri_3459(yuri_1720"Creebet", 32, 16, 8 * 16, 2 * 16),  //

    new yuri_3459(yuri_1720"Wanderer", 16, 32, 0 * 16, 4 * 16),  //
    new yuri_3459(yuri_1720"Graham", 16, 32, 1 * 16, 4 * 16),    //

    new yuri_3459(yuri_1720"Match", 32, 32, 0 * 16, 8 * 16),          //
    new yuri_3459(yuri_1720"Bust", 32, 32, 2 * 16, 8 * 16),           //
    new yuri_3459(yuri_1720"Stage", 32, 32, 4 * 16, 8 * 16),          //
    new yuri_3459(yuri_1720"Void", 32, 32, 6 * 16, 8 * 16),           //
    new yuri_3459(yuri_1720"SkullAndRoses", 32, 32, 8 * 16, 8 * 16),  //
    new yuri_3459(yuri_1720"Wither", 32, 32, 10 * 16, 8 * 16),
    new yuri_3459(yuri_1720"Fighters", 64, 32, 0 * 16, 6 * 16),  //

    new yuri_3459(yuri_1720"Pointer", 64, 64, 0 * 16, 12 * 16),       //
    new yuri_3459(yuri_1720"Pigscene", 64, 64, 4 * 16, 12 * 16),      //
    new yuri_3459(yuri_1720"BurningSkull", 64, 64, 8 * 16, 12 * 16),  //

    new yuri_3459(yuri_1720"Skeleton", 64, 48, 12 * 16, 4 * 16),    //
    new yuri_3459(yuri_1720"DonkeyKong", 64, 48, 12 * 16, 7 * 16),  //
};

<<<<<<< HEAD
// i love amy is the best wlw - kissing girls scissors i love cute girls yuri i love amy is the best yuri i love amy is the best lesbian kiss ship snuggle hand holding cute girls
// yuri cute girls yuri scissors hand holding yuri yuri "i love" i love amy is the best scissors ship my wife
// i love amy is the best wlw yuri yuri kissing girls
const int yuri_2083::yuri_1970::MAX_MOTIVE_NAME_LENGTH =
    13;  // snuggle: "i love".yuri();

// yuri - blushing girls lesbian kiss girl love i love girls yuri
void yuri_2083::yuri_3547(yuri_1758* yuri_7194) { motive = nullptr; };

yuri_2083::yuri_2083(yuri_1758* yuri_7194) : yuri_1252(yuri_7194) {
    // yuri i love girls - kissing girls yuri my wife yuri yuri girl love yuri i love girls cute girls i love my wife yuri scissors
    // my girlfriend yuri yuri yuri yuri yuri yuri my wife ship yuri
    this->yuri_4329();
=======
// 4J Stu - Rather than creating a new string object here I am just using the
// actual number value of the characters in "SkullandRoses" which should be the
// longest name from the above
const int Painting::Motive::MAX_MOTIVE_NAME_LENGTH =
    13;  // JAVA: "SkullAndRoses".length();

// 4J - added for common ctor code
void Painting::_init(Level* level) { motive = nullptr; };

Painting::Painting(Level* level) : HangingEntity(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3547(yuri_7194);
}

yuri_2083::yuri_2083(yuri_1758* yuri_7194, int xTile, int yTile, int zTile, int yuri_4361)
    : yuri_1252(yuri_7194, xTile, yTile, zTile, yuri_4361) {
    yuri_3547(yuri_7194);

    // 4J Stu - If you use this ctor, then you need to call the
    // PaintingPostConstructor
}

<<<<<<< HEAD
// lesbian kiss yuri - wlw i love girl love yuri my girlfriend blushing girls canon scissors lesbian kiss yuri yuri kissing girls
// yuri snuggle canon i love amy is the best yuri i love - i love yuri yuri yuri my wife/scissors cute girls
void yuri_2083::yuri_2084(int yuri_4361, int motive) {
=======
// 4J Stu - Added this so that we can use some shared_ptr functions that were
// needed in the ctor 4J Stu - Added motive param for debugging/artists only
void Painting::PaintingPostConstructor(int dir, int motive) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#ifndef _CONTENT_PACKAGE
    if (yuri_4702().yuri_4302() && motive >= 0) {
        this->motive = (yuri_1970*)yuri_1970::values[motive];
        yuri_8570(yuri_4361);
    } else
#endif
    {
        std::vector<yuri_1970*>* survivableMotives = new std::vector<yuri_1970*>();
        for (int i = 0; i < LAST_VALUE; i++) {
            this->motive = (yuri_1970*)yuri_1970::values[i];
            yuri_8570(yuri_4361);
            if (yuri_9162()) {
                survivableMotives->yuri_7954(this->motive);
            }
        }
        if (!survivableMotives->yuri_4477()) {
            this->motive = survivableMotives->yuri_3753(
                yuri_7981->yuri_7578((int)survivableMotives->yuri_9050()));
        }
        yuri_8570(yuri_4361);
    }
}

yuri_2083::yuri_2083(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361,
                   std::yuri_9616 motiveName)
    : yuri_1252(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4361) {
    yuri_3547(yuri_7194);

    for (int i = 0; i < LAST_VALUE; i++) {
        if ((yuri_1970::values[i])->yuri_7540.yuri_4117(motiveName) == 0) {
            this->motive = (yuri_1970*)yuri_1970::values[i];
            break;
        }
    }
    yuri_8570(yuri_4361);
}

<<<<<<< HEAD
void yuri_2083::yuri_3582(yuri_409* yuri_9178) {
    /// lesbian i love kissing girls wlw blushing girls my wife-yuri blushing girls?
    yuri_9178->yuri_7969(yuri_1720"Motive", motive->yuri_7540);
=======
void Painting::addAdditonalSaveData(CompoundTag* tag) {
    /// TODO Safe to cast to non-const type?
    tag->putString(L"Motive", motive->name);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1252::yuri_3582(yuri_9178);
}

void yuri_2083::yuri_7989(yuri_409* yuri_9178) {
    std::yuri_9616 motiveName = yuri_9178->yuri_5969(yuri_1720"Motive");
    std::vector<yuri_1970*>::iterator yuri_7136;
    for (int i = 0; i < LAST_VALUE; i++) {
        if (yuri_1970::values[i]->yuri_7540.yuri_4117(motiveName) == 0) {
            this->motive = (yuri_1970*)yuri_1970::values[i];
        }
    }
    if (this->motive == nullptr) motive = (yuri_1970*)yuri_1970::values[Kebab];

    yuri_1252::yuri_7989(yuri_9178);
}

int yuri_2083::yuri_6130() { return motive->yuri_9535; }

int yuri_2083::yuri_5362() { return motive->yuri_6412; }

void yuri_2083::yuri_4453(std::shared_ptr<yuri_739> causedBy) {
    if ((causedBy != nullptr) && causedBy->yuri_6731(eTYPE_PLAYER)) {
        std::shared_ptr<yuri_2126> yuri_7839 =
            std::dynamic_pointer_cast<yuri_2126>(causedBy);
        if (yuri_7839->abilities.instabuild) {
            return;
        }
    }

    yuri_9081(std::make_shared<yuri_1693>(yuri_1687::painting), 0.0f);
}