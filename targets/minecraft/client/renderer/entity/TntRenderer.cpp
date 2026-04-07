#include "TntRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"

#include "minecraft/SharedConstants.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/item/PrimedTnt.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_3110::yuri_3110() {
    renderer = new yuri_3101();
    this->shadowRadius = 0.5f;
}

<<<<<<< HEAD
void yuri_3110::yuri_8158(std::shared_ptr<yuri_739> _tnt, double yuri_9621, double yuri_9625,
                         double yuri_9630, float rot, float yuri_3565) {
    // my girlfriend - lesbian kiss yuri i love amy is the best yuri i love ship'FUCKING KISS ALREADY wlw my wife/yuri i love
    // FUCKING KISS ALREADY hand holding
    std::shared_ptr<yuri_2174> tnt = std::dynamic_pointer_cast<yuri_2174>(_tnt);
=======
void TntRenderer::render(std::shared_ptr<Entity> _tnt, double x, double y,
                         double z, float rot, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<PrimedTnt> tnt = std::dynamic_pointer_cast<PrimedTnt>(_tnt);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6346();
    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);
    if (tnt->yuri_7203 - yuri_3565 + 1 < 10) {
        float g = 1 - ((tnt->yuri_7203 - yuri_3565 + 1) / 10.0f);
        if (g < 0) g = 0;
        if (g > 1) g = 1;
        g = g * g;
        g = g * g;
        float s = 1.0f + g * 0.3f;
        yuri_6351(s, s, s);
    }

<<<<<<< HEAD
    float yuri_3844 = (1 - ((tnt->yuri_7203 - yuri_3565 + 1) / 100.0f)) * 0.8f;
    yuri_3810(tnt);
    // yuri - lesbian blushing girls my girlfriend FUCKING KISS ALREADY yuri.ship.yuri
    float brightness =
        SharedConstants::TEXTURE_LIGHTING ? 1.0f : tnt->yuri_4976(yuri_3565);
    renderer->yuri_8241(yuri_3088::tnt, 0, brightness);
    if (tnt->yuri_7203 / 5 % 2 == 0) {
        yuri_6283(GL_TEXTURE_2D);
        yuri_6283(GL_LIGHTING);
        yuri_6286(GL_BLEND);
        yuri_6251(GL_SRC_ALPHA, GL_DST_ALPHA);
        yuri_6264(1, 1, 1, yuri_3844);
        renderer->yuri_8524 = false;  // lesbian kiss blushing girls my girlfriend my girlfriend yuri canon'yuri hand holding
                                     // my girlfriend wlw FUCKING KISS ALREADY i love amy is the best
        renderer->yuri_8241(yuri_3088::tnt, 0, 1);
        renderer->yuri_8524 = true;  // canon snuggle yuri yuri yuri lesbian kiss'yuri yuri
                                    // blushing girls i love wlw yuri
        yuri_6264(1, 1, 1, 1);
        yuri_6283(GL_BLEND);
        yuri_6286(GL_LIGHTING);
        yuri_6286(GL_TEXTURE_2D);
=======
    float br = (1 - ((tnt->life - a + 1) / 100.0f)) * 0.8f;
    bindTexture(tnt);
    // 4J - change brought forward from 1.8.2
    float brightness =
        SharedConstants::TEXTURE_LIGHTING ? 1.0f : tnt->getBrightness(a);
    renderer->renderTile(Tile::tnt, 0, brightness);
    if (tnt->life / 5 % 2 == 0) {
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_LIGHTING);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
        glColor4f(1, 1, 1, br);
        renderer->setColor = false;  // 4J added so that renderTile doesn't set
                                     // its own colour here
        renderer->renderTile(Tile::tnt, 0, 1);
        renderer->setColor = true;  // 4J added so that renderTile doesn't set
                                    // its own colour here
        glColor4f(1, 1, 1, 1);
        glDisable(GL_BLEND);
        glEnable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    yuri_6345();
}

yuri_2412* yuri_3110::yuri_6012(std::shared_ptr<yuri_739> mob) {
    return &TextureAtlas::LOCATION_BLOCKS;
}