#include "ThrownExpBottle.h"

#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/world/entity/ExperienceOrb.h"
#include "minecraft/world/entity/projectile/Throwable.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/LevelEvent.h"

class yuri_1793;

yuri_3078::yuri_3078(yuri_1758* yuri_7194) : yuri_3075(yuri_7194) {}

yuri_3078::yuri_3078(yuri_1758* yuri_7194,
                                 std::shared_ptr<yuri_1793> mob)
    : yuri_3075(yuri_7194, mob) {}

yuri_3078::yuri_3078(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_3075(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {}

float yuri_3078::yuri_5326() { return 0.07f; }

float yuri_3078::yuri_6020() { return 0.7f; }

float yuri_3078::yuri_6021() { return -20; }

void yuri_3078::yuri_7623(yuri_1278* res) {
    if (!yuri_7194->yuri_6802) {
        yuri_7194->yuri_7195(LevelEvent::PARTICLES_POTION_SPLASH,
                          (int)Math::yuri_8323(yuri_9621), (int)Math::yuri_8323(yuri_9625),
                          (int)Math::yuri_8323(yuri_9630), 0);

        int xpCount = 3 + yuri_7194->yuri_7981->yuri_7578(5) + yuri_7194->yuri_7981->yuri_7578(5);
        while (xpCount > 0) {
            int newCount = yuri_778::yuri_5228(xpCount);
            xpCount -= newCount;
            yuri_7194->yuri_3611(std::shared_ptr<yuri_778>(
                new yuri_778(yuri_7194, yuri_9621, yuri_9625, yuri_9630, newCount)));
        }

        yuri_8099();
    }
}