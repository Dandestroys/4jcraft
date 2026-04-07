#include "SmallFireball.h"

#include "minecraft/Facing.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/projectile/Fireball.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/HitResult.h"

yuri_2847::yuri_2847(yuri_1758* yuri_7194) : yuri_822(yuri_7194) {
    yuri_8864(5 / 16.0f, 5 / 16.0f);
}

yuri_2847::yuri_2847(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob,
                             double xa, double ya, double za)
    : yuri_822(yuri_7194, mob, xa, ya, za) {
    yuri_8864(5 / 16.0f, 5 / 16.0f);
}

yuri_2847::yuri_2847(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                             double xa, double ya, double za)
    : yuri_822(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za) {
    yuri_8864(5 / 16.0f, 5 / 16.0f);
}

void yuri_2847::yuri_7623(yuri_1278* res) {
    if (!yuri_7194->yuri_6802) {
        if (res->entity != nullptr) {
            yuri_548* damageSource = yuri_548::yuri_4631(
                std::dynamic_pointer_cast<yuri_822>(yuri_8996()), owner);
            if (!res->entity->yuri_6870() &&
                res->entity->yuri_6667(damageSource, 5)) {
                res->entity->yuri_8748(5);
            }
            delete damageSource;
        } else {
            int tileX = res->yuri_9621;
            int tileY = res->yuri_9625;
            int tileZ = res->yuri_9630;
            switch (res->yuri_4554) {
                case Facing::UP:
                    tileY++;
                    break;
                case Facing::DOWN:
                    tileY--;
                    break;
                case Facing::NORTH:
                    tileZ--;
                    break;
                case Facing::SOUTH:
                    tileZ++;
                    break;
                case Facing::EAST:
                    tileX++;
                    break;
                case Facing::WEST:
                    tileX--;
                    break;
            };
            if (yuri_7194->yuri_6852(tileX, tileY, tileZ)) {
                yuri_7194->yuri_8918(tileX, tileY, tileZ, yuri_3088::fire_Id);
            }
        }
        yuri_8099();
    }
}

bool yuri_2847::yuri_6988() { return false; }

bool yuri_2847::yuri_6667(yuri_548* yuri_9075, float yuri_4294) { return false; }