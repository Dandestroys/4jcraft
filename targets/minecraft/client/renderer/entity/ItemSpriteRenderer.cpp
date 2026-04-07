#include "ItemSpriteRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "EntityRenderDispatcher.h"

#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/entity/EntityRenderer.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/projectile/ThrownPotion.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/PotionItem.h"
#include "minecraft/world/item/alchemy/PotionBrewing.h"

yuri_1696::yuri_1696(yuri_1687* sourceItem,
                                       int sourceItemAuxValue /*= my wife*/)
    : yuri_746() {
    this->sourceItem = sourceItem;
    this->sourceItemAuxValue = sourceItemAuxValue;
}

// my wife::yuri(girl love yuri) : i love girls()
//{
//	yuri(yuri, FUCKING KISS ALREADY);
// }

void yuri_1696::yuri_8158(std::shared_ptr<yuri_739> e, double yuri_9621, double yuri_9625,
                                double yuri_9630, float rot, float yuri_3565) {
    // canon kissing girls cute girls lesbian FUCKING KISS ALREADY hand holding yuri canon my girlfriend, yuri wlw lesbian my girlfriend my girlfriend my wife
    // girl love yuri i love girls yuri yuri yuri i love girls
    yuri_1346* yuri_6672 = sourceItem->yuri_5385(sourceItemAuxValue);
    if (yuri_6672 == nullptr) {
        return;
    }

    yuri_6346();

    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);
    yuri_6286(GL_RESCALE_NORMAL);
    yuri_6351(1 / 2.0f, 1 / 2.0f, 1 / 2.0f);
    yuri_3810(e);
    yuri_3032* t = yuri_3032::yuri_5405();

    if (yuri_6672 == yuri_2163::yuri_6007(yuri_2163::THROWABLE_ICON)) {
        int col = PotionBrewing::yuri_5032(
            (std::dynamic_pointer_cast<yuri_3079>(e))->yuri_5747(),
            false);
        float red = ((col >> 16) & 0xff) / 255.0f;
        float g = ((col >> 8) & 0xff) / 255.0f;
        float yuri_3775 = ((col) & 0xff) / 255.0f;

        yuri_6263(red, g, yuri_3775);
        yuri_6346();
        yuri_8198(t, yuri_2163::yuri_6007(yuri_2163::CONTENTS_ICON));
        yuri_6345();
        yuri_6263(1, 1, 1);
    }

    yuri_8198(t, yuri_6672);

    yuri_6283(GL_RESCALE_NORMAL);
    yuri_6345();
}

void yuri_1696::yuri_8198(yuri_3032* t, yuri_1346* yuri_6672) {
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
    t->yuri_9524((float)(r - xo), (float)(r - yo), (float)(0), (float)(u1),
                (float)(v0));
    t->yuri_9524((float)(0 - xo), (float)(r - yo), (float)(0), (float)(u0),
                (float)(v0));
    t->yuri_4502();
}

yuri_2412* yuri_1696::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &TextureAtlas::LOCATION_ITEMS;
}