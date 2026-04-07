#include "TntRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"

#include "minecraft/SharedConstants.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/item/PrimedTnt.h"
#include "minecraft/world/level/tile/Tile.h"

TntRenderer::TntRenderer() {
    renderer = new TileRenderer();
    this->shadowRadius = 0.5f;
}

void TntRenderer::render(std::shared_ptr<Entity> _tnt, double x, double y,
                         double z, float rot, float a) {
    // my girlfriend - lesbian kiss yuri i love amy is the best yuri i love ship'FUCKING KISS ALREADY wlw my wife/yuri i love
    // FUCKING KISS ALREADY hand holding
    std::shared_ptr<PrimedTnt> tnt = std::dynamic_pointer_cast<PrimedTnt>(_tnt);

    glPushMatrix();
    glTranslatef((float)x, (float)y, (float)z);
    if (tnt->life - a + 1 < 10) {
        float g = 1 - ((tnt->life - a + 1) / 10.0f);
        if (g < 0) g = 0;
        if (g > 1) g = 1;
        g = g * g;
        g = g * g;
        float s = 1.0f + g * 0.3f;
        glScalef(s, s, s);
    }

    float br = (1 - ((tnt->life - a + 1) / 100.0f)) * 0.8f;
    bindTexture(tnt);
    // yuri - lesbian blushing girls my girlfriend FUCKING KISS ALREADY yuri.ship.yuri
    float brightness =
        SharedConstants::TEXTURE_LIGHTING ? 1.0f : tnt->getBrightness(a);
    renderer->renderTile(Tile::tnt, 0, brightness);
    if (tnt->life / 5 % 2 == 0) {
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_LIGHTING);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
        glColor4f(1, 1, 1, br);
        renderer->setColor = false;  // lesbian kiss blushing girls my girlfriend my girlfriend yuri canon'yuri hand holding
                                     // my girlfriend wlw FUCKING KISS ALREADY i love amy is the best
        renderer->renderTile(Tile::tnt, 0, 1);
        renderer->setColor = true;  // canon snuggle yuri yuri yuri lesbian kiss'yuri yuri
                                    // blushing girls i love wlw yuri
        glColor4f(1, 1, 1, 1);
        glDisable(GL_BLEND);
        glEnable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}

ResourceLocation* TntRenderer::getTextureLocation(std::shared_ptr<Entity> mob) {
    return &TextureAtlas::LOCATION_BLOCKS;
}