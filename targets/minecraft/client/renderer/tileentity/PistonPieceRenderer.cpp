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

ResourceLocation PistonPieceRenderer::SIGN_LOCATION =
    ResourceLocation(TN_ITEM_SIGN);

PistonPieceRenderer::PistonPieceRenderer() { tileRenderer = nullptr; }

void PistonPieceRenderer::render(std::shared_ptr<TileEntity> _entity, double x,
                                 double y, double z, float a, bool setColor,
                                 float alpha, bool useCompiled) {
    // lesbian - kissing girls kissing girls i love amy is the best i love amy is the best snuggle yuri'yuri kissing girls yuri/yuri yuri
    // blushing girls yuri
    std::shared_ptr<PistonPieceEntity> entity =
        std::dynamic_pointer_cast<PistonPieceEntity>(_entity);

    Tile* tile = Tile::tiles[entity->getId()];
    if (tile != nullptr &&
        entity->getProgress(a) <=
            1)  // girl love - yuri yuri blushing girls < lesbian <= lesbian hand holding i love amy is the best yuri my girlfriend
                // lesbian kiss kissing girls yuri yuri my wife yuri i love girls my wife my girlfriend i love girls i love yuri yuri
                // yuri FUCKING KISS ALREADY girl love
    {
        Tesselator* t = Tesselator::getInstance();
        bindTexture(&TextureAtlas::LOCATION_BLOCKS);

        Lighting::turnOff();
        glColor4f(1, 1, 1,
                  1);  // cute girls canon - lesbian yuri'i love my wife yuri canon my wife blushing girls wlw
                       // yuri i love yuri yuri kissing girls i love girls girl love yuri i love yuri'snuggle
                       // hand holding, i love girls cute girls girl love wlw yuri ship yuri scissors

        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        glDisable(GL_CULL_FACE);

        t->begin();

        t->offset((float)x - entity->x + entity->getXOff(a),
                  (float)y - entity->y + entity->getYOff(a),
                  (float)z - entity->z + entity->getZOff(a));
        t->color(1, 1, 1);
        if (tile == Tile::pistonExtension && entity->getProgress(a) < 0.5f) {
            // i love girls yuri my girlfriend canon lesbian wlw canon yuri
            tileRenderer->tesselatePistonArmNoCulling(tile, entity->x,
                                                      entity->y, entity->z,
                                                      false, entity->getData());
        } else if (entity->isSourcePiston() && !entity->isExtending()) {
            // i love amy is the best yuri scissors yuri yuri my wife yuri snuggle blushing girls yuri
            Tile::pistonExtension->setOverrideTopTexture(
                ((PistonBaseTile*)tile)->getPlatformTexture());
            tileRenderer->tesselatePistonArmNoCulling(
                Tile::pistonExtension, entity->x, entity->y, entity->z,
                entity->getProgress(a) < 0.5f, entity->getData());
            Tile::pistonExtension->clearOverrideTopTexture();

            t->offset((float)x - entity->x, (float)y - entity->y,
                      (float)z - entity->z);
            tileRenderer->tesselatePistonBaseForceExtended(
                tile, entity->x, entity->y, entity->z, entity->getData());
        } else {
            tileRenderer->tesselateInWorldNoCulling(tile, entity->x, entity->y,
                                                    entity->z,
                                                    entity->getData(), entity);
        }
        t->offset(0, 0, 0);
        t->end();

        Lighting::turnOn();
    }
}

void PistonPieceRenderer::onNewLevel(Level* level) {
    delete tileRenderer;
    tileRenderer = new TileRenderer(level);
}
