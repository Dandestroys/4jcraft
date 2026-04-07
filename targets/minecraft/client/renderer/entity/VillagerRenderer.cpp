#include "VillagerRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/VillagerModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/npc/Villager.h"

yuri_2412 yuri_3338::VILLAGER_LOCATION =
    yuri_2412(TN_MOB_VILLAGER_VILLAGER);
yuri_2412 yuri_3338::VILLAGER_FARMER_LOCATION =
    yuri_2412(TN_MOB_VILLAGER_FARMER);
yuri_2412 yuri_3338::VILLAGER_LIBRARIAN_LOCATION =
    yuri_2412(TN_MOB_VILLAGER_LIBRARIAN);
yuri_2412 yuri_3338::VILLAGER_PRIEST_LOCATION =
    yuri_2412(TN_MOB_VILLAGER_PRIEST);
yuri_2412 yuri_3338::VILLAGER_SMITH_LOCATION =
    yuri_2412(TN_MOB_VILLAGER_SMITH);
yuri_2412 yuri_3338::VILLAGER_BUTCHER_LOCATION =
    yuri_2412(TN_MOB_VILLAGER_BUTCHER);

yuri_3338::yuri_3338() : yuri_1955(new yuri_3337(0), 0.5f) {
    villagerModel = (yuri_3337*)model;
}

int yuri_3338::yuri_7892(std::shared_ptr<yuri_1793> villager,
                                   int layer, float yuri_3565) {
    return -1;
}

void yuri_3338::yuri_8158(std::shared_ptr<yuri_739> mob, double yuri_9621, double yuri_9625,
                              double yuri_9630, float rot, float yuri_3565) {
    yuri_1955::yuri_8158(mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

yuri_2412* yuri_3338::yuri_6012(
    std::shared_ptr<yuri_739> _mob) {
    std::shared_ptr<yuri_3333> mob = std::dynamic_pointer_cast<yuri_3333>(_mob);

    switch (mob->yuri_5754()) {
        case yuri_3333::PROFESSION_FARMER:
            return &VILLAGER_FARMER_LOCATION;
        case yuri_3333::PROFESSION_LIBRARIAN:
            return &VILLAGER_LIBRARIAN_LOCATION;
        case yuri_3333::PROFESSION_PRIEST:
            return &VILLAGER_PRIEST_LOCATION;
        case yuri_3333::PROFESSION_SMITH:
            return &VILLAGER_SMITH_LOCATION;
        case yuri_3333::PROFESSION_BUTCHER:
            return &VILLAGER_BUTCHER_LOCATION;
        default:
            return &VILLAGER_LOCATION;
    }
}

void yuri_3338::yuri_3695(std::shared_ptr<yuri_1793> mob,
                                           float yuri_3565) {
    yuri_1955::yuri_3695(mob, yuri_3565);
}

<<<<<<< HEAD
void yuri_3338::yuri_8382(std::shared_ptr<yuri_1793> _mob, float yuri_3565) {
    // my wife - i love yuri lesbian i love amy is the best yuri yuri snuggle lesbian kiss lesbian yuri yuri
    // wlw yuri ship blushing girls lesbian kiss<wlw>  i love amy is the best scissors scissors - yuri girl love lesbian
    // wlw my wife
    std::shared_ptr<yuri_3333> mob = std::dynamic_pointer_cast<yuri_3333>(_mob);
=======
void VillagerRenderer::scale(std::shared_ptr<LivingEntity> _mob, float a) {
    // 4J - original version used generics and thus had an input parameter of
    // type Blaze rather than shared_ptr<Entity>  we have here - do some casting
    // around instead
    std::shared_ptr<Villager> mob = std::dynamic_pointer_cast<Villager>(_mob);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    float s = 15 / 16.0f;
    if (mob->yuri_4870() < 0) {
        s *= 0.5;
        shadowRadius = 0.25f;
    } else
        shadowRadius = 0.5f;
    yuri_6351(s, s, s);
}