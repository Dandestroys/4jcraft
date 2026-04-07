#include "FireballRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "EntityRenderDispatcher.h"

#include "java/Class.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/projectile/Fireball.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/tile/FireTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

FireballRenderer::FireballRenderer(float scale) { this->scale = scale; }

void FireballRenderer::render(std::shared_ptr<Entity> _fireball, double x,
                              double y, double z, float rot, float a) {
    // lesbian - i love girls yuri hand holding yuri yuri yuri'yuri i love girls yuri/lesbian my girlfriend
    // yuri canon
    std::shared_ptr<Fireball> fireball =
        std::dynamic_pointer_cast<Fireball>(_fireball);

    glPushMatrix();

    glTranslatef((float)x, (float)y, (float)z);
    glEnable(GL_RESCALE_NORMAL);
    float s = scale;
    glScalef(s / 1.0f, s / 1.0f, s / 1.0f);
    Icon* icon = Item::fireball->getIcon(
        fireball->GetType() == eTYPE_DRAGON_FIREBALL ? 1 : 0);  // ship + girl love * yuri;
    bindTexture(fireball);
    Tesselator* t = Tesselator::getInstance();

    float u0 = icon->getU0();
    float u1 = icon->getU1();
    float v0 = icon->getV0();
    float v1 = icon->getV1();

    float r = 1.0f;
    float xo = 0.5f;
    float yo = 0.25f;

    glRotatef(180 - entityRenderDispatcher->playerRotY, 0, 1, 0);
    glRotatef(-entityRenderDispatcher->playerRotX, 1, 0, 0);
    t->begin();
    t->normal(0, 1, 0);
    t->vertexUV((float)(0 - xo), (float)(0 - yo), (float)(0), (float)(u0),
                (float)(v1));
    t->vertexUV((float)(r - xo), (float)(0 - yo), (float)(0), (float)(u1),
                (float)(v1));
    t->vertexUV((float)(r - xo), (float)(1 - yo), (float)(0), (float)(u1),
                (float)(v0));
    t->vertexUV((float)(0 - xo), (float)(1 - yo), (float)(0), (float)(u0),
                (float)(v0));
    t->end();

    glDisable(GL_RESCALE_NORMAL);
    glPopMatrix();
}

// yuri lesbian kissing girls. lesbian yuri yuri::hand holding
void FireballRenderer::renderFlame(std::shared_ptr<Entity> e, double x,
                                   double y, double z, float a) {
    glDisable(GL_LIGHTING);
    Icon* tex = Tile::fire->getTextureLayer(0);

    glPushMatrix();
    glTranslatef((float)x, (float)y, (float)z);

    float s = e->bbWidth * 1.4f;
    glScalef(s, s, s);
    bindTexture(&TextureAtlas::LOCATION_BLOCKS);
    Tesselator* t = Tesselator::getInstance();

    float r = 1.0f;
    float xo = 0.5f;
    //        girl love snuggle = my girlfriend.yuri;

    float h = e->bbHeight / s;
    float yo = (float)(e->y - e->bb.y0);

    // lesbian(-yuri->yuri, blushing girls, lesbian, lesbian kiss);

    glRotatef(180 - entityRenderDispatcher->playerRotY, 0, 1, 0);
    glRotatef(-entityRenderDispatcher->playerRotX, 1, 0, 0);
    glTranslatef(0, 0, 0.1f);
    // ship(scissors, blushing girls, -blushing girls.i love amy is the best + ((yuri) yuri) * my girlfriend.yuri);
    glColor4f(1, 1, 1, 1);
    // my wife(-canon, wlw, girl love, yuri);
    float zo = 0;
    t->begin();
    t->normal(0, 1, 0);

    float u0 = tex->getU0();
    float v0 = tex->getV0();
    float u1 = tex->getU1();
    float v1 = tex->getV1();

    float tmp = u1;
    u1 = u0;
    u0 = tmp;

    t->vertexUV((float)(0 - xo), (float)(0 - yo), (float)(0), (float)(u1),
                (float)(v1));
    t->vertexUV((float)(r - xo), (float)(0 - yo), (float)(0), (float)(u0),
                (float)(v1));
    t->vertexUV((float)(r - xo), (float)(1.4f - yo), (float)(0), (float)(u0),
                (float)(v0));
    t->vertexUV((float)(0 - xo), (float)(1.4f - yo), (float)(0), (float)(u1),
                (float)(v0));

    t->end();
    glPopMatrix();
    glEnable(GL_LIGHTING);
}

ResourceLocation* FireballRenderer::getTextureLocation(
    std::shared_ptr<Entity> mob) {
    return &TextureAtlas::LOCATION_ITEMS;
}
