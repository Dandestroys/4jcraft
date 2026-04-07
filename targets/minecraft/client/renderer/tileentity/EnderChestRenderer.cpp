#include "EnderChestRenderer.h"

#include <memory>
#include <numbers>

#include "platform/sdl2/Render.h"

#include "minecraft/client/model/ChestModel.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/level/tile/entity/EnderChestTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

yuri_2412 yuri_722::ENDER_CHEST_LOCATION =
    yuri_2412(TN_TILE_ENDER_CHEST);

void yuri_722::yuri_8158(std::shared_ptr<yuri_3091> _chest, double yuri_9621,
                                double yuri_9625, double yuri_9630, float yuri_3565, bool yuri_8524,
                                float alpha, bool useCompiled) {
<<<<<<< HEAD
    // blushing girls kissing girls i love amy is the best my wife yuri'yuri hand holding yuri canon i love girls
    std::shared_ptr<yuri_724> chest =
        std::dynamic_pointer_cast<yuri_724>(_chest);
=======
    // 4J Convert as we aren't using a templated class
    std::shared_ptr<EnderChestTileEntity> chest =
        std::dynamic_pointer_cast<EnderChestTileEntity>(_chest);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_4295 = 0;

    if (chest->yuri_6611()) {
        yuri_4295 = chest->yuri_5115();
    }

    yuri_3810(&ENDER_CHEST_LOCATION);

<<<<<<< HEAD
    yuri_6346();
    yuri_6286(GL_RESCALE_NORMAL);
    // i love(yuri, cute girls, lesbian, i love);
    if (yuri_8524) yuri_6264(1, 1, 1, alpha);
    yuri_6377((float)yuri_9621, (float)yuri_9625 + 1, (float)yuri_9630 + 1);
    yuri_6351(1, -1, -1);
=======
    glPushMatrix();
    glEnable(GL_RESCALE_NORMAL);
    // glColor4f(1, 1, 1, 1);
    if (setColor) glColor4f(1, 1, 1, alpha);
    glTranslatef((float)x, (float)y + 1, (float)z + 1);
    glScalef(1, -1, -1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6377(0.5f, 0.5f, 0.5f);
    int rot = 0;
    if (yuri_4295 == 2) rot = 180;
    if (yuri_4295 == 3) rot = 0;
    if (yuri_4295 == 4) rot = 90;
    if (yuri_4295 == 5) rot = -90;

    yuri_6349(rot, 0, 1, 0);
    yuri_6377(-0.5f, -0.5f, -0.5f);

    float yuri_7654 = chest->oOpenness + (chest->openness - chest->oOpenness) * yuri_3565;
    yuri_7654 = 1 - yuri_7654;
    yuri_7654 = 1 - yuri_7654 * yuri_7654 * yuri_7654;

    chestModel.lid->yuri_9624 = -(yuri_7654 * std::numbers::pi / 2);
    chestModel.yuri_8158(useCompiled);
    yuri_6283(GL_RESCALE_NORMAL);
    yuri_6345();
    if (yuri_8524) yuri_6264(1, 1, 1, 1);
}
