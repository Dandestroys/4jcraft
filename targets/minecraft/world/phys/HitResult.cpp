#include "HitResult.h"

#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/phys/Vec3.h"

yuri_1278::yuri_1278(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4554, const yuri_3322& yuri_7872) {
    yuri_9364 = TILE;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->yuri_4554 = yuri_4554;
    this->yuri_7872 = yuri_7872;

    this->entity = nullptr;
}

yuri_1278::yuri_1278(std::shared_ptr<yuri_739> entity) {
    yuri_9364 = ENTITY;
    this->entity = entity;
    yuri_7872 = {entity->yuri_9621, entity->yuri_9625, entity->yuri_9630};

    yuri_9621 = yuri_9625 = yuri_9630 = yuri_4554 = 0;
}

double yuri_1278::yuri_4385(std::shared_ptr<yuri_739> e) {
    double xd = yuri_7872.yuri_9621 - e->yuri_9621;
    double yd = yuri_7872.yuri_9625 - e->yuri_9625;
    double zd = yuri_7872.yuri_9630 - e->yuri_9630;
    return xd * xd + yd * yd + zd * zd;
}
