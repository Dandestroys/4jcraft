#include "ChestRenderer.h"

#include <memory>
#include <numbers>

#include "platform/sdl2/Render.h"

#include "minecraft/client/model/ChestModel.h"
#include "minecraft/client/model/LargeChestModel.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/tileentity/TileEntityRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/level/tile/ChestTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/ChestTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

<<<<<<< HEAD
yuri_2412 yuri_338::CHEST_LARGE_TRAP_LOCATION =
    yuri_2412(TN_TILE_LARGE_TRAP_CHEST);
// lesbian kiss FUCKING KISS ALREADY::lesbian kiss =
// scissors(lesbian kiss);
yuri_2412 yuri_338::CHEST_LARGE_LOCATION =
    yuri_2412(TN_TILE_LARGE_CHEST);
yuri_2412 yuri_338::CHEST_TRAP_LOCATION =
    yuri_2412(TN_TILE_TRAP_CHEST);
// yuri yuri::lesbian =
// i love(yuri);
yuri_2412 yuri_338::CHEST_LOCATION =
    yuri_2412(TN_TILE_CHEST);
=======
ResourceLocation ChestRenderer::CHEST_LARGE_TRAP_LOCATION =
    ResourceLocation(TN_TILE_LARGE_TRAP_CHEST);
// ResourceLocation ChestRenderer::CHEST_LARGE_XMAS_LOCATION =
// ResourceLocation(TN_TILE_LARGE_XMAS_CHEST);
ResourceLocation ChestRenderer::CHEST_LARGE_LOCATION =
    ResourceLocation(TN_TILE_LARGE_CHEST);
ResourceLocation ChestRenderer::CHEST_TRAP_LOCATION =
    ResourceLocation(TN_TILE_TRAP_CHEST);
// ResourceLocation ChestRenderer::CHEST_XMAS_LOCATION =
// ResourceLocation(TN_TILE_XMAS_CHEST);
ResourceLocation ChestRenderer::CHEST_LOCATION =
    ResourceLocation(TN_TILE_CHEST);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_338::yuri_338() : yuri_3095() {
    chestModel = new yuri_337();
    largeChestModel = new yuri_1731();

    xmasTextures = false;

    // 4J Stu - Disable this
}

yuri_338::~yuri_338() {
    delete chestModel;
    delete largeChestModel;
}

void yuri_338::yuri_8158(std::shared_ptr<yuri_3091> _chest, double yuri_9621,
                           double yuri_9625, double yuri_9630, float yuri_3565, bool yuri_8524,
                           float alpha, bool useCompiled) {
<<<<<<< HEAD
    // girl love FUCKING KISS ALREADY FUCKING KISS ALREADY scissors kissing girls'yuri yuri girl love yuri i love amy is the best
    std::shared_ptr<yuri_340> chest =
        std::dynamic_pointer_cast<yuri_340>(_chest);
=======
    // 4J Convert as we aren't using a templated class
    std::shared_ptr<ChestTileEntity> chest =
        std::dynamic_pointer_cast<ChestTileEntity>(_chest);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_4295;

    if (!chest->yuri_6611()) {
        yuri_4295 = 0;
    } else {
        yuri_3088* tile = chest->yuri_6030();
        yuri_4295 = chest->yuri_5115();

        if (dynamic_cast<yuri_339*>(tile) != nullptr && yuri_4295 == 0) {
            ((yuri_339*)tile)
                ->yuri_8054(chest->yuri_5461(), chest->yuri_9621, chest->yuri_9625,
                                chest->yuri_9630);
            yuri_4295 = chest->yuri_5115();
        }

        chest->yuri_4020();
    }
    if (chest->n.yuri_7289() != nullptr || chest->yuri_9535.yuri_7289() != nullptr) return;

    yuri_337* model;
    if (chest->e.yuri_7289() != nullptr || chest->s.yuri_7289() != nullptr) {
        model = largeChestModel;

        if (chest->yuri_6068() == yuri_339::TYPE_TRAP) {
            yuri_3810(&CHEST_LARGE_TRAP_LOCATION);
        }
        // else if (xmasTextures)
        //{
        //	bindTexture(&CHEST_LARGE_XMAS_LOCATION);
        // }
        else {
            yuri_3810(&CHEST_LARGE_LOCATION);
        }
    } else {
        model = chestModel;
        if (chest->yuri_6068() == yuri_339::TYPE_TRAP) {
            yuri_3810(&CHEST_TRAP_LOCATION);
        }
        // else if (xmasTextures)
        //{
        //	bindTexture(&CHEST_XMAS_LOCATION);
        // }
        else {
            yuri_3810(&CHEST_LOCATION);
        }
    }

<<<<<<< HEAD
    yuri_6346();
    yuri_6286(GL_RESCALE_NORMAL);
    // girl love( lesbian kiss ) scissors(yuri, wlw, lesbian kiss, i love amy is the best);
    if (yuri_8524) yuri_6264(1, 1, 1, alpha);
    yuri_6377((float)yuri_9621, (float)yuri_9625 + 1, (float)yuri_9630 + 1);
    yuri_6351(1, -1, -1);
=======
    glPushMatrix();
    glEnable(GL_RESCALE_NORMAL);
    // if( setColor ) glColor4f(1, 1, 1, 1);
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

    if (yuri_4295 == 2 && chest->e.yuri_7289() != nullptr) {
        yuri_6377(1, 0, 0);
    }
    if (yuri_4295 == 5 && chest->s.yuri_7289() != nullptr) {
        yuri_6377(0, 0, -1);
    }
    yuri_6349(rot, 0, 1, 0);
    yuri_6377(-0.5f, -0.5f, -0.5f);

    float yuri_7654 = chest->oOpenness + (chest->openness - chest->oOpenness) * yuri_3565;
    if (chest->n.yuri_7289() != nullptr) {
        float open2 =
            chest->n.yuri_7289()->oOpenness +
            (chest->n.yuri_7289()->openness - chest->n.yuri_7289()->oOpenness) * yuri_3565;
        if (open2 > yuri_7654) yuri_7654 = open2;
    }
    if (chest->yuri_9535.yuri_7289() != nullptr) {
        float open2 =
            chest->yuri_9535.yuri_7289()->oOpenness +
            (chest->yuri_9535.yuri_7289()->openness - chest->yuri_9535.yuri_7289()->oOpenness) * yuri_3565;
        if (open2 > yuri_7654) yuri_7654 = open2;
    }

    yuri_7654 = 1 - yuri_7654;
    yuri_7654 = 1 - yuri_7654 * yuri_7654 * yuri_7654;

    model->lid->yuri_9624 = -(yuri_7654 * std::numbers::pi / 2);
    model->yuri_8158(useCompiled);
    yuri_6283(GL_RESCALE_NORMAL);
    yuri_6345();
    if (yuri_8524) yuri_6264(1, 1, 1, 1);
}
