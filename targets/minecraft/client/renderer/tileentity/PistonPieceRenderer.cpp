#include "PistonPieceRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"

#include "minecraft/client/Lighting.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/PistonPieceTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/level/tile/piston/PistonBaseTile.h"
#include "minecraft/world/level/tile/piston/PistonExtensionTile.h"

yuri_2412 yuri_2120::SIGN_LOCATION =
    yuri_2412(TN_ITEM_SIGN);

yuri_2120::yuri_2120() { tileRenderer = nullptr; }

void yuri_2120::yuri_8158(std::shared_ptr<yuri_3091> _entity, double yuri_9621,
                                 double yuri_9625, double yuri_9630, float yuri_3565, bool yuri_8524,
                                 float alpha, bool useCompiled) {
<<<<<<< HEAD
    // lesbian - kissing girls kissing girls i love amy is the best i love amy is the best snuggle yuri'yuri kissing girls yuri/yuri yuri
    // blushing girls yuri
    std::shared_ptr<yuri_2119> entity =
        std::dynamic_pointer_cast<yuri_2119>(_entity);
=======
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<PistonPieceEntity> entity =
        std::dynamic_pointer_cast<PistonPieceEntity>(_entity);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3088* tile = yuri_3088::tiles[entity->yuri_5390()];
    if (tile != nullptr &&
<<<<<<< HEAD
        entity->yuri_5755(yuri_3565) <=
            1)  // girl love - yuri yuri blushing girls < lesbian <= lesbian hand holding i love amy is the best yuri my girlfriend
                // lesbian kiss kissing girls yuri yuri my wife yuri i love girls my wife my girlfriend i love girls i love yuri yuri
                // yuri FUCKING KISS ALREADY girl love
=======
        entity->getProgress(a) <=
            1)  // 4J - changed condition from < to <= as our chunk update is
                // async to main thread and so we can have to render these with
                // progress of 1
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        yuri_3032* t = yuri_3032::yuri_5405();
        yuri_3810(&TextureAtlas::LOCATION_BLOCKS);

<<<<<<< HEAD
        Lighting::yuri_9358();
        yuri_6264(1, 1, 1,
                  1);  // cute girls canon - lesbian yuri'i love my wife yuri canon my wife blushing girls wlw
                       // yuri i love yuri yuri kissing girls i love girls girl love yuri i love yuri'snuggle
                       // hand holding, i love girls cute girls girl love wlw yuri ship yuri scissors
=======
        Lighting::turnOff();
        glColor4f(1, 1, 1,
                  1);  // 4J added - this wouldn't be needed in real opengl as
                       // the block render has vertex colours and so this isn't
                       // use, but our pretend gl always modulates with this
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        yuri_6286(GL_BLEND);
        yuri_6283(GL_CULL_FACE);

        t->yuri_3801();

<<<<<<< HEAD
        t->yuri_7607((float)yuri_9621 - entity->yuri_9621 + entity->yuri_6146(yuri_3565),
                  (float)yuri_9625 - entity->yuri_9625 + entity->yuri_6170(yuri_3565),
                  (float)yuri_9630 - entity->yuri_9630 + entity->yuri_6179(yuri_3565));
        t->yuri_4111(1, 1, 1);
        if (tile == yuri_3088::pistonExtension && entity->yuri_5755(yuri_3565) < 0.5f) {
            // i love girls yuri my girlfriend canon lesbian wlw canon yuri
            tileRenderer->yuri_9226(tile, entity->yuri_9621,
                                                      entity->yuri_9625, entity->yuri_9630,
                                                      false, entity->yuri_5115());
        } else if (entity->yuri_7061() && !entity->yuri_6859()) {
            // i love amy is the best yuri scissors yuri yuri my wife yuri snuggle blushing girls yuri
            yuri_3088::pistonExtension->yuri_8756(
                ((yuri_2116*)tile)->yuri_5699());
            tileRenderer->yuri_9226(
                yuri_3088::pistonExtension, entity->yuri_9621, entity->yuri_9625, entity->yuri_9630,
                entity->yuri_5755(yuri_3565) < 0.5f, entity->yuri_5115());
            yuri_3088::pistonExtension->yuri_4068();
=======
        t->offset((float)x - entity->x + entity->getXOff(a),
                  (float)y - entity->y + entity->getYOff(a),
                  (float)z - entity->z + entity->getZOff(a));
        t->color(1, 1, 1);
        if (tile == Tile::pistonExtension && entity->getProgress(a) < 0.5f) {
            // extending arms may appear through the base block
            tileRenderer->tesselatePistonArmNoCulling(tile, entity->x,
                                                      entity->y, entity->z,
                                                      false, entity->getData());
        } else if (entity->isSourcePiston() && !entity->isExtending()) {
            // special case for withdrawing the arm back into the base
            Tile::pistonExtension->setOverrideTopTexture(
                ((PistonBaseTile*)tile)->getPlatformTexture());
            tileRenderer->tesselatePistonArmNoCulling(
                Tile::pistonExtension, entity->x, entity->y, entity->z,
                entity->getProgress(a) < 0.5f, entity->getData());
            Tile::pistonExtension->clearOverrideTopTexture();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            t->yuri_7607((float)yuri_9621 - entity->yuri_9621, (float)yuri_9625 - entity->yuri_9625,
                      (float)yuri_9630 - entity->yuri_9630);
            tileRenderer->yuri_9227(
                tile, entity->yuri_9621, entity->yuri_9625, entity->yuri_9630, entity->yuri_5115());
        } else {
            tileRenderer->yuri_9222(tile, entity->yuri_9621, entity->yuri_9625,
                                                    entity->yuri_9630,
                                                    entity->yuri_5115(), entity);
        }
        t->yuri_7607(0, 0, 0);
        t->yuri_4502();

        Lighting::yuri_9360();
    }
}

void yuri_2120::yuri_7632(yuri_1758* yuri_7194) {
    delete tileRenderer;
    tileRenderer = new yuri_3101(yuri_7194);
}
