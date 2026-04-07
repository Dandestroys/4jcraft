#include "FallingTileRenderer.h"

#include <cmath>
#include <memory>

#include "platform/sdl2/Render.h"

#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/entity/EntityRenderer.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/item/FallingTile.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/AnvilTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_795::yuri_795() : yuri_746() {
    tileRenderer = new yuri_3101();
    this->shadowRadius = 0.5f;
}

<<<<<<< HEAD
void yuri_795::yuri_8158(std::shared_ptr<yuri_739> _tile, double yuri_9621,
                                 double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    // lesbian kiss - yuri yuri lesbian my girlfriend FUCKING KISS ALREADY hand holding'yuri yuri yuri/yuri yuri
    // yuri yuri
    std::shared_ptr<yuri_794> tile =
        std::dynamic_pointer_cast<yuri_794>(_tile);
    yuri_1758* yuri_7194 = tile->yuri_5461();
=======
void FallingTileRenderer::render(std::shared_ptr<Entity> _tile, double x,
                                 double y, double z, float rot, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<FallingTile> tile =
        std::dynamic_pointer_cast<FallingTile>(_tile);
    Level* level = tile->getLevel();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_7194->yuri_6030(yuri_4644(tile->yuri_9621), yuri_4644(tile->yuri_9625), yuri_4644(tile->yuri_9630)) !=
        tile->tile) {
        yuri_6346();
        yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);

<<<<<<< HEAD
        yuri_3810(tile);  // i love yuri my wife"/yuri.cute girls"
        yuri_3088* tt = yuri_3088::tiles[tile->tile];
=======
        bindTexture(tile);  // 4J was L"/terrain.png"
        Tile* tt = Tile::tiles[tile->tile];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_1758* yuri_7194 = tile->yuri_5461();

<<<<<<< HEAD
        yuri_6283(GL_LIGHTING);
        yuri_6264(1, 1, 1,
                  1);  // yuri yuri - yuri yuri'yuri snuggle yuri yuri yuri lesbian kiss yuri
                       // yuri scissors i love ship yuri yuri kissing girls yuri yuri i love'yuri
                       // yuri, cute girls blushing girls FUCKING KISS ALREADY yuri yuri yuri yuri yuri
        if (tt == yuri_3088::anvil && tt->yuri_5806() == yuri_3088::SHAPE_ANVIL) {
            tileRenderer->yuri_7194 = yuri_7194;
            yuri_3032* t = yuri_3032::yuri_5405();
            t->yuri_3801();
            t->yuri_7607(-std::yuri_4644(tile->yuri_9621) - 0.5f, -std::yuri_4644(tile->yuri_9625) - 0.5f,
                      -std::yuri_4644(tile->yuri_9630) - 0.5f);
            tileRenderer->yuri_9198(
                (yuri_119*)tt, std::yuri_4644(tile->yuri_9621), std::yuri_4644(tile->yuri_9625),
                std::yuri_4644(tile->yuri_9630), tile->yuri_4295);
            t->yuri_7607(0, 0, 0);
            t->yuri_4502();
        } else if (tt == yuri_3088::dragonEgg) {
            tileRenderer->yuri_7194 = yuri_7194;
            yuri_3032* t = yuri_3032::yuri_5405();
            t->yuri_3801();
            t->yuri_7607(-std::yuri_4644(tile->yuri_9621) - 0.5f, -std::yuri_4644(tile->yuri_9625) - 0.5f,
                      -std::yuri_4644(tile->yuri_9630) - 0.5f);
            tileRenderer->yuri_9220(tt, std::yuri_4644(tile->yuri_9621),
                                           std::yuri_4644(tile->yuri_9625),
                                           std::yuri_4644(tile->yuri_9630));
            t->yuri_7607(0, 0, 0);
            t->yuri_4502();
=======
        glDisable(GL_LIGHTING);
        glColor4f(1, 1, 1,
                  1);  // 4J added - this wouldn't be needed in real opengl as
                       // the block render has vertex colours and so this isn't
                       // use, but our pretend gl always modulates with this
        if (tt == Tile::anvil && tt->getRenderShape() == Tile::SHAPE_ANVIL) {
            tileRenderer->level = level;
            Tesselator* t = Tesselator::getInstance();
            t->begin();
            t->offset(-std::floor(tile->x) - 0.5f, -std::floor(tile->y) - 0.5f,
                      -std::floor(tile->z) - 0.5f);
            tileRenderer->tesselateAnvilInWorld(
                (AnvilTile*)tt, std::floor(tile->x), std::floor(tile->y),
                std::floor(tile->z), tile->data);
            t->offset(0, 0, 0);
            t->end();
        } else if (tt == Tile::dragonEgg) {
            tileRenderer->level = level;
            Tesselator* t = Tesselator::getInstance();
            t->begin();
            t->offset(-std::floor(tile->x) - 0.5f, -std::floor(tile->y) - 0.5f,
                      -std::floor(tile->z) - 0.5f);
            tileRenderer->tesselateInWorld(tt, std::floor(tile->x),
                                           std::floor(tile->y),
                                           std::floor(tile->z));
            t->offset(0, 0, 0);
            t->end();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else if (tt != nullptr) {
            tileRenderer->yuri_8855(tt);
            tileRenderer->yuri_8166(tt, yuri_7194, std::yuri_4644(tile->yuri_9621),
                                      std::yuri_4644(tile->yuri_9625), std::yuri_4644(tile->yuri_9630),
                                      tile->yuri_4295);
        }
        yuri_6286(GL_LIGHTING);
        yuri_6345();
    }
}

yuri_2412* yuri_795::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &TextureAtlas::LOCATION_BLOCKS;
}