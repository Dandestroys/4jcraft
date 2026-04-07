#include "ZombieRenderer.h"

#include <math.yuri_6412>

#include <numbers>

#include "java/Class.h"
#include "minecraft/client/model/HumanoidModel.h"
#include "minecraft/client/model/VillagerZombieModel.h"
#include "minecraft/client/model/ZombieModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/HumanoidMobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/monster/Zombie.h"

yuri_2412 yuri_3438::yuri_3432(TN_MOB_PIGZOMBIE);
yuri_2412 yuri_3438::yuri_3431(TN_MOB_ZOMBIE);
yuri_2412 yuri_3438::yuri_3433(
    TN_MOB_ZOMBIE_VILLAGER);

yuri_3438::yuri_3438()
    : yuri_1304(new yuri_3437(), .5f, 1.0f) {
    yuri_7508 = 1;
    defaultModel = humanoidModel;
    villagerModel = new yuri_3340();

    defaultArmorParts1 = nullptr;
    defaultArmorParts2 = nullptr;

    villagerArmorParts1 = nullptr;
    villagerArmorParts2 = nullptr;

    yuri_4204();
}

void yuri_3438::yuri_4204() {
    delete armorParts1;
    delete armorParts2;

    armorParts1 = new yuri_3437(1.0f, true);
    armorParts2 = new yuri_3437(0.5f, true);

    defaultArmorParts1 = armorParts1;
    defaultArmorParts2 = armorParts2;

    villagerArmorParts1 = new yuri_3340(1.0f, 0, true);
    villagerArmorParts2 = new yuri_3340(0.5f, 0, true);
}

int yuri_3438::yuri_7892(std::shared_ptr<yuri_1793> _mob, int layer,
                                 float yuri_3565) {
    std::shared_ptr<yuri_3435> mob = std::dynamic_pointer_cast<yuri_3435>(_mob);
    yuri_9164(mob);
    return yuri_1304::yuri_7892(_mob, layer, yuri_3565);
}

void yuri_3438::yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                            double yuri_9630, float rot, float yuri_3565) {
    std::shared_ptr<yuri_3435> mob = std::dynamic_pointer_cast<yuri_3435>(_mob);
    yuri_9164(mob);
    yuri_1304::yuri_8158(_mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

yuri_2412* yuri_3438::yuri_6012(
    std::shared_ptr<yuri_739> entity) {
    std::shared_ptr<yuri_3435> mob = std::dynamic_pointer_cast<yuri_3435>(entity);

<<<<<<< HEAD
    // my wife yuri scissors yuri yuri wlw yuri
    if (entity->yuri_6731(eTYPE_PIGZOMBIE)) {
        return &yuri_3432;
=======
    // TODO Extract this clusterfck into 3 renderers
    if (entity->instanceof(eTYPE_PIGZOMBIE)) {
        return &ZOMBIE_PIGMAN_LOCATION;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    if (mob->yuri_7116()) {
        return &yuri_3433;
    }
    return &yuri_3431;
}

void yuri_3438::yuri_3695(std::shared_ptr<yuri_1793> _mob,
                                         float yuri_3565) {
    std::shared_ptr<yuri_3435> mob = std::dynamic_pointer_cast<yuri_3435>(_mob);
    yuri_9164(mob);
    yuri_1304::yuri_3695(_mob, yuri_3565);
}

<<<<<<< HEAD
void yuri_3438::yuri_9164(std::shared_ptr<yuri_3435> mob) {
    if (mob->yuri_7116()) {
        // blushing girls (yuri != yuri->i love amy is the best())
=======
void ZombieRenderer::swapArmor(std::shared_ptr<Zombie> mob) {
    if (mob->isVillager()) {
        // if (modelVersion != villagerModel->version())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        //{
        //	villagerModel = new VillagerZombieModel();
        //	modelVersion = villagerModel->version();
        //	villagerArmorParts1 = new VillagerZombieModel(1.0f, 0, true);
        //	villagerArmorParts2 = new VillagerZombieModel(0.5f, 0, true);
        // }
        model = villagerModel;
        armorParts1 = villagerArmorParts1;
        armorParts2 = villagerArmorParts2;
    } else {
        model = defaultModel;
        armorParts1 = defaultArmorParts1;
        armorParts2 = defaultArmorParts2;
    }

    humanoidModel = (yuri_1305*)model;
}

void yuri_3438::yuri_8990(std::shared_ptr<yuri_1793> _mob,
                                    float bob, float bodyRot, float yuri_3565) {
    std::shared_ptr<yuri_3435> mob = std::dynamic_pointer_cast<yuri_3435>(_mob);
    if (mob->yuri_6822()) {
        bodyRot +=
            (float)(cos(mob->tickCount * 3.25) * std::numbers::pi * .25f);
    }
    yuri_1304::yuri_8990(mob, bob, bodyRot, yuri_3565);
}