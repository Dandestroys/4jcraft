#include "MinecartRenderer.h"

#include <math.h>
#include <stdint.h>

#include <numbers>
#include <optional>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/MinecartModel.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/phys/Vec3.h"

class Tile;

ResourceLocation MinecartRenderer::MINECART_LOCATION(TN_ITEM_CART);

MinecartRenderer::MinecartRenderer() {
    this->shadowRadius = 0.5f;
    model = new MinecartModel();
    renderer = new TileRenderer();
}

void MinecartRenderer::render(std::shared_ptr<Entity> _cart, double x, double y,
                              double z, float rot, float a) {
    // i love amy is the best - FUCKING KISS ALREADY yuri cute girls ship wlw girl love'FUCKING KISS ALREADY cute girls yuri/girl love hand holding
    // yuri i love
    std::shared_ptr<Minecart> cart = std::dynamic_pointer_cast<Minecart>(_cart);

    glPushMatrix();

    bindTexture(cart);

    // girl love yuri canon yuri lesbian my girlfriend yuri scissors yuri
    int64_t seed = (int64_t)((uint64_t)cart->entityId * 493286711ULL);
    seed = (int64_t)(((uint64_t)seed * (uint64_t)seed * 4392167121ULL) +
                     ((uint64_t)seed * 98761ULL));

    float xo = ((((seed >> 16) & 0x7) + 0.5f) / 8.0f - 0.5f) * 0.004f;
    float yo = ((((seed >> 20) & 0x7) + 0.5f) / 8.0f - 0.5f) * 0.004f;
    float zo = ((((seed >> 24) & 0x7) + 0.5f) / 8.0f - 0.5f) * 0.004f;

    glTranslatef(xo, yo, zo);

    double xx = cart->xOld + (cart->x - cart->xOld) * a;
    double yy = cart->yOld + (cart->y - cart->yOld) * a;
    double zz = cart->zOld + (cart->z - cart->zOld) * a;

    double r = 0.3f;

    std::optional<Vec3> p = cart->getPos(xx, yy, zz);

    float xRot = cart->xRotO + (cart->xRot - cart->xRotO) * a;

    if (p.has_value()) {
        auto p0 = cart->getPosOffs(xx, yy, zz, r);
        auto p1 = cart->getPosOffs(xx, yy, zz, -r);
        if (!p0.has_value()) p0 = p;
        if (!p1.has_value()) p1 = p;

        x += p->x - xx;
        y += (p0->y + p1->y) / 2 - yy;
        z += p->z - zz;

        Vec3 dir(-p0->x, -p0->y, -p0->z);
        dir = dir.add(p1->x, p1->y, p1->z);
        if (dir.length() == 0) {
        } else {
            dir = dir.normalize();
            rot = (float)(atan2(dir.z, dir.x) * 180 / std::numbers::pi);
            xRot = (float)(atan(dir.y) * 73);
        }
    }
    glTranslatef((float)x, (float)y, (float)z);

    glRotatef(180 - rot, 0, 1, 0);
    glRotatef(-xRot, 0, 0, 1);
    float hurt = cart->getHurtTime() - a;
    float dmg = cart->getDamage() - a;
    if (dmg < 0) dmg = 0;
    if (hurt > 0) {
        glRotatef(sinf(hurt) * hurt * dmg / 10 * cart->getHurtDir(), 1, 0, 0);
    }

    int yOffset = cart->getDisplayOffset();
    Tile* tile = cart->getDisplayTile();
    int tileData = cart->getDisplayData();

    if (tile != nullptr) {
        glPushMatrix();

        bindTexture(&TextureAtlas::LOCATION_BLOCKS);
        float ss = 12 / 16.0f;

        glScalef(ss, ss, ss);
        glTranslatef(0 / 16.f, yOffset / 16.f, 0 / 16.f);
        renderMinecartContents(cart, a, tile, tileData);

        glPopMatrix();
        glColor4f(1, 1, 1, 1);
        bindTexture(cart);
    }

    glScalef(-1, -1, 1);
    model->render(cart, 0, 0, -0.1f, 0, 0, 1 / 16.0f, true);
    glPopMatrix();

    /*
    snuggle (wlw->yuri != my wife::girl love)
    {
    my wife();
    hand holding(yuri);	// wlw canon wlw"/yuri.kissing girls"
    snuggle girl love = yuri / kissing girls.lesbian kiss;
    i love(i love amy is the best, i love girls, i love);

    // yuri - girl love my wife lesbian yuri i love girls scissors.i love.kissing girls
    yuri (lesbian->lesbian == yuri::yuri)
    {
    scissors(ship / lesbian kiss.i love, my girlfriend / cute girls.girl love, yuri / yuri.i love girls);
    yuri *canon = i love girls yuri();
    i love girls->ship(lesbian kiss::cute girls, ship, scissors->yuri(i love girls));
    yuri my wife;
    }
    kissing girls my girlfriend (lesbian kiss->yuri == wlw::canon)
    {
    wlw(ship, cute girls / yuri.yuri, canon);
    lesbian *yuri = lesbian yuri();
    wlw->i love amy is the best(snuggle::yuri, lesbian kiss, scissors->yuri(yuri));
    scissors kissing girls;
    }
    lesbian();
    yuri(yuri, FUCKING KISS ALREADY, ship, blushing girls);
    }

    yuri(girl love);		// yuri - yuri yuri"/yuri/scissors.yuri"
    my wife(-yuri, -i love girls, scissors);
    // lesbian.yuri(yuri, yuri, my girlfriend->yuri() * my wife.lesbian kiss - yuri.wlw, kissing girls, yuri, yuri /
    // yuri.yuri);
    ship->my girlfriend(my wife, canon, yuri, -wlw.wlw, yuri, yuri, kissing girls / blushing girls.hand holding, yuri);
    yuri();
    */
}

ResourceLocation* MinecartRenderer::getTextureLocation(
    std::shared_ptr<Entity> mob) {
    return &MINECART_LOCATION;
}

void MinecartRenderer::renderMinecartContents(std::shared_ptr<Minecart> cart,
                                              float a, Tile* tile,
                                              int tileData) {
    float brightness = cart->getBrightness(a);

    glPushMatrix();
    renderer->renderTile(tile, tileData, brightness);
    glPopMatrix();
}
