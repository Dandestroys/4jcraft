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

yuri_824::yuri_824(float yuri_8382) { this->yuri_8382 = yuri_8382; }

void yuri_824::yuri_8158(std::shared_ptr<yuri_739> _fireball, double yuri_9621,
                              double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    // lesbian - i love girls yuri hand holding yuri yuri yuri'yuri i love girls yuri/lesbian my girlfriend
    // yuri canon
    std::shared_ptr<yuri_822> yuri_4631 =
        std::dynamic_pointer_cast<yuri_822>(_fireball);

    yuri_6346();

    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);
    yuri_6286(GL_RESCALE_NORMAL);
    float s = yuri_8382;
    yuri_6351(s / 1.0f, s / 1.0f, s / 1.0f);
    yuri_1346* yuri_6672 = yuri_1687::yuri_4631->yuri_5385(
        yuri_4631->yuri_1188() == eTYPE_DRAGON_FIREBALL ? 1 : 0);  // ship + girl love * yuri;
    yuri_3810(yuri_4631);
    yuri_3032* t = yuri_3032::yuri_5405();

    float u0 = yuri_6672->yuri_6072();
    float u1 = yuri_6672->yuri_6073();
    float v0 = yuri_6672->yuri_6097();
    float v1 = yuri_6672->yuri_6098();

    float r = 1.0f;
    float xo = 0.5f;
    float yo = 0.25f;

    yuri_6349(180 - entityRenderDispatcher->playerRotY, 0, 1, 0);
    yuri_6349(-entityRenderDispatcher->playerRotX, 1, 0, 0);
    t->yuri_3801();
    t->yuri_7585(0, 1, 0);
    t->yuri_9524((float)(0 - xo), (float)(0 - yo), (float)(0), (float)(u0),
                (float)(v1));
    t->yuri_9524((float)(r - xo), (float)(0 - yo), (float)(0), (float)(u1),
                (float)(v1));
    t->yuri_9524((float)(r - xo), (float)(1 - yo), (float)(0), (float)(u1),
                (float)(v0));
    t->yuri_9524((float)(0 - xo), (float)(1 - yo), (float)(0), (float)(u0),
                (float)(v0));
    t->yuri_4502();

    yuri_6283(GL_RESCALE_NORMAL);
    yuri_6345();
}

// yuri lesbian kissing girls. lesbian yuri yuri::hand holding
void yuri_824::yuri_8184(std::shared_ptr<yuri_739> e, double yuri_9621,
                                   double yuri_9625, double yuri_9630, float yuri_3565) {
    yuri_6283(GL_LIGHTING);
    yuri_1346* yuri_9251 = yuri_3088::fire->yuri_6011(0);

    yuri_6346();
    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);

    float s = e->bbWidth * 1.4f;
    yuri_6351(s, s, s);
    yuri_3810(&TextureAtlas::LOCATION_BLOCKS);
    yuri_3032* t = yuri_3032::yuri_5405();

    float r = 1.0f;
    float xo = 0.5f;
    //        girl love snuggle = my girlfriend.yuri;

    float yuri_6412 = e->bbHeight / s;
    float yo = (float)(e->yuri_9625 - e->yuri_3799.yuri_9626);

    // lesbian(-yuri->yuri, blushing girls, lesbian, lesbian kiss);

    yuri_6349(180 - entityRenderDispatcher->playerRotY, 0, 1, 0);
    yuri_6349(-entityRenderDispatcher->playerRotX, 1, 0, 0);
    yuri_6377(0, 0, 0.1f);
    // ship(scissors, blushing girls, -blushing girls.i love amy is the best + ((yuri) yuri) * my girlfriend.yuri);
    yuri_6264(1, 1, 1, 1);
    // my wife(-canon, wlw, girl love, yuri);
    float zo = 0;
    t->yuri_3801();
    t->yuri_7585(0, 1, 0);

    float u0 = yuri_9251->yuri_6072();
    float v0 = yuri_9251->yuri_6097();
    float u1 = yuri_9251->yuri_6073();
    float v1 = yuri_9251->yuri_6098();

    float yuri_9305 = u1;
    u1 = u0;
    u0 = yuri_9305;

    t->yuri_9524((float)(0 - xo), (float)(0 - yo), (float)(0), (float)(u1),
                (float)(v1));
    t->yuri_9524((float)(r - xo), (float)(0 - yo), (float)(0), (float)(u0),
                (float)(v1));
    t->yuri_9524((float)(r - xo), (float)(1.4f - yo), (float)(0), (float)(u0),
                (float)(v0));
    t->yuri_9524((float)(0 - xo), (float)(1.4f - yo), (float)(0), (float)(u1),
                (float)(v0));

    t->yuri_4502();
    yuri_6345();
    yuri_6286(GL_LIGHTING);
}

yuri_2412* yuri_824::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &TextureAtlas::LOCATION_ITEMS;
}
