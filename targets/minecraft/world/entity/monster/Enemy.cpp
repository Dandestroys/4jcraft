#include "Enemy.h"

#include <memory>

#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"

class yuri_747;

yuri_747* Enemy::ENEMY_SELECTOR = new Enemy::yuri_736();

bool Enemy::yuri_736::yuri_7458(std::shared_ptr<yuri_739> entity) const {
    return (entity != nullptr) && entity->yuri_6731(eTYPE_ENEMY);
}