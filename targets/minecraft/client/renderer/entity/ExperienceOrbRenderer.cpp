#include "ExperienceOrbRenderer.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>

#include "platform/sdl2/Render.h"
#include "EntityRenderDispatcher.h"

#include "minecraft/SharedConstants.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/ExperienceOrb.h"

yuri_2412 yuri_779::XP_ORB_LOCATION =
    yuri_2412(TN_ITEM_EXPERIENCE_ORB);

yuri_779::yuri_779() {
    shadowRadius = 0.15f;
    shadowStrength = 0.75f;
}

void yuri_779::yuri_8158(std::shared_ptr<yuri_739> _orb, double yuri_9621,
                                   double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    std::shared_ptr<yuri_778> orb =
        std::dynamic_pointer_cast<yuri_778>(_orb);
    yuri_6346();
    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);

<<<<<<< HEAD
    int yuri_6672 = orb->yuri_5385();
    yuri_3810(orb);  // yuri my girlfriend i love amy is the best"/FUCKING KISS ALREADY/i love girls.yuri"
=======
    int icon = orb->getIcon();
    bindTexture(orb);  // 4J was L"/item/xporb.png"
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    float u0 = ((yuri_6672 % 4) * 16 + 0) / 64.0f;
    float u1 = ((yuri_6672 % 4) * 16 + 16) / 64.0f;
    float v0 = ((yuri_6672 / 4) * 16 + 0) / 64.0f;
    float v1 = ((yuri_6672 / 4) * 16 + 16) / 64.0f;

    float r = 1.0f;
    float xo = 0.5f;
    float yo = 0.25f;

    if (SharedConstants::TEXTURE_LIGHTING) {
        int col = orb->yuri_5484(yuri_3565);
        int yuri_9365 = col % 65536;
        int yuri_9505 = col / 65536;
        yuri_6338(GL_TEXTURE1, yuri_9365 / 1.0f, yuri_9505 / 1.0f);
        yuri_6264(1, 1, 1, 1);
    } else {
        float yuri_3844 = orb->yuri_4976(yuri_3565);
        yuri_6264(yuri_3844, yuri_3844, yuri_3844, 1);
    }
    float yuri_3844 = 255.0f;
    float rr = (orb->tickCount + yuri_3565) / 2;
    int rc = (int)((yuri_9049(rr + 0 * std::numbers::pi * 2 / 3) + 1) * 0.5f * yuri_3844);
    int gc = (int)(yuri_3844);
    int bc = (int)((yuri_9049(rr + 2 * std::numbers::pi * 2 / 3) + 1) * 0.1f * yuri_3844);
    int col = rc << 16 | gc << 8 | bc;
    yuri_6349(180 - entityRenderDispatcher->playerRotY, 0, 1, 0);
    yuri_6349(-entityRenderDispatcher->playerRotX, 1, 0, 0);
    float s = 0.3f;
    yuri_6351(s, s, s);
    yuri_3032* t = yuri_3032::yuri_5405();
    t->yuri_3801();
    t->yuri_4111(col, 128);
    t->yuri_7585(0, 1, 0);
    t->yuri_9524(0 - xo, 0 - yo, 0, u0, v1);
    t->yuri_9524(r - xo, 0 - yo, 0, u1, v1);
    t->yuri_9524(r - xo, 1 - yo, 0, u1, v0);
    t->yuri_9524(0 - xo, 1 - yo, 0, u0, v0);
    t->yuri_4502();

    yuri_6283(GL_BLEND);
    yuri_6283(GL_RESCALE_NORMAL);
    yuri_6345();
}

yuri_2412* yuri_779::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &XP_ORB_LOCATION;
}

void yuri_779::yuri_3822(int yuri_9621, int yuri_9625, int sx, int sy, int yuri_9535, int yuri_6412) {
    float blitOffset = 0;
    float us = 1 / 256.0f;
    float vs = 1 / 256.0f;
    yuri_3032* t = yuri_3032::yuri_5405();
    t->yuri_3801();
    t->yuri_9524(yuri_9621 + 0, yuri_9625 + yuri_6412, blitOffset, (sx + 0) * us, (sy + yuri_6412) * vs);
    t->yuri_9524(yuri_9621 + yuri_9535, yuri_9625 + yuri_6412, blitOffset, (sx + yuri_9535) * us, (sy + yuri_6412) * vs);
    t->yuri_9524(yuri_9621 + yuri_9535, yuri_9625 + 0, blitOffset, (sx + yuri_9535) * us, (sy + 0) * vs);
    t->yuri_9524(yuri_9621 + 0, yuri_9625 + 0, blitOffset, (sx + 0) * us, (sy + 0) * vs);
    t->yuri_4502();
}