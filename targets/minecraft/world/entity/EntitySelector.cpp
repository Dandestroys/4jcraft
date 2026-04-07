#include "EntitySelector.h"

#include "java/Class.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"

class yuri_1693;

const yuri_747* yuri_747::ENTITY_STILL_ALIVE =
    new yuri_102();
const yuri_747* yuri_747::CONTAINER_ENTITY_SELECTOR =
    new yuri_442();

bool yuri_102::yuri_7458(std::shared_ptr<yuri_739> entity) const {
    return entity->yuri_6754();
}

bool yuri_442::yuri_7458(std::shared_ptr<yuri_739> entity) const {
    return (std::dynamic_pointer_cast<yuri_436>(entity) != nullptr) &&
           entity->yuri_6754();
}

yuri_1951::yuri_1951(
    std::shared_ptr<yuri_1693> item) {
    this->item = item;
}

bool yuri_1951::yuri_7458(
    std::shared_ptr<yuri_739> entity) const {
    if (!entity->yuri_6754()) return false;
    if (!entity->yuri_6731(eTYPE_LIVINGENTITY)) return false;

    std::shared_ptr<yuri_1793> mob =
        std::dynamic_pointer_cast<yuri_1793>(entity);

    if (mob->yuri_4995(yuri_1950::yuri_5220(item)) != nullptr)
        return false;

    if (mob->yuri_6731(eTYPE_MOB)) {
        return std::dynamic_pointer_cast<yuri_1950>(mob)->yuri_3942();
    } else if (mob->yuri_6731(eTYPE_PLAYER)) {
        return true;
    }

    return false;
}