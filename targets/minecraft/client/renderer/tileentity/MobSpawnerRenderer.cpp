#include "MobSpawnerRenderer.h"

#include "platform/sdl2/Render.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/BaseMobSpawner.h"
#include "minecraft/world/level/tile/entity/MobSpawnerTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

void yuri_1959::yuri_8158(std::shared_ptr<yuri_3091> _spawner, double yuri_9621,
                                double yuri_9625, double yuri_9630, float yuri_3565, bool yuri_8524,
                                float alpha, bool useCompiled) {
<<<<<<< HEAD
    // my wife - yuri yuri lesbian girl love yuri yuri'girl love my girlfriend yuri/i love girls ship
    // yuri yuri
    std::shared_ptr<yuri_1961> spawner =
        std::dynamic_pointer_cast<yuri_1961>(_spawner);
    yuri_8158(spawner->yuri_5949(), yuri_9621, yuri_9625, yuri_9630, yuri_3565);
    yuri_6345();
=======
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<MobSpawnerTileEntity> spawner =
        std::dynamic_pointer_cast<MobSpawnerTileEntity>(_spawner);
    render(spawner->getSpawner(), x, y, z, a);
    glPopMatrix();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1959::yuri_8158(yuri_164* spawner, double yuri_9621, double yuri_9625,
                                double yuri_9630, float yuri_3565) {
    yuri_6346();
    yuri_6377((float)yuri_9621 + 0.5f, (float)yuri_9625, (float)yuri_9630 + 0.5f);

    std::shared_ptr<yuri_739> e = spawner->yuri_5169();
    if (e != nullptr) {
        e->yuri_8700(spawner->yuri_5461());
        float s = 7 / 16.0f;
        yuri_6377(0, 0.4f, 0);
        yuri_6349(
            (float)(spawner->oSpin + (spawner->spin - spawner->oSpin) * yuri_3565) * 10,
            0, 1, 0);
        yuri_6349(-30, 1, 0, 0);
        yuri_6377(0, -0.4f, 0);
        yuri_6351(s, s, s);
        e->yuri_7531(yuri_9621, yuri_9625, yuri_9630, 0, 0);
        yuri_745::instance->yuri_8158(e, 0, 0, 0, 0, yuri_3565);
    }
}
