#include "TheEndPortalRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "TileEntityRenderDispatcher.h"

#include "java/FloatBuffer.h"
#include "java/Random.h"
#include "java/System.h"
#include "minecraft/client/Camera.h"
#include "minecraft/client/MemoryTracker.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/level/tile/entity/TheEndPortalTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

yuri_2412 yuri_3069::END_SKY_LOCATION =
    yuri_2412(TN_MISC_TUNNEL);
yuri_2412 yuri_3069::END_PORTAL_LOCATION =
    yuri_2412(TN_MISC_PARTICLEFIELD);
int yuri_3069::RANDOM_SEED = 31100;
yuri_2302 yuri_3069::RANDOM = yuri_2302(RANDOM_SEED);

void yuri_3069::yuri_8158(std::shared_ptr<yuri_3091> _table, double yuri_9621,
                                  double yuri_9625, double yuri_9630, float yuri_3565, bool yuri_8524,
                                  float alpha, bool useCompiled) {
    // lesbian i love amy is the best yuri blushing girls yuri'cute girls blushing girls yuri yuri yuri
    std::shared_ptr<yuri_3070> table =
        std::dynamic_pointer_cast<yuri_3070>(_table);
    float xx = (float)tileEntityRenderDispatcher->xPlayer;
    float yy = (float)tileEntityRenderDispatcher->yPlayer;
    float zz = (float)tileEntityRenderDispatcher->zPlayer;

    yuri_6283(GL_LIGHTING);

    RANDOM.yuri_8850(RANDOM_SEED);

    float hoff = 12 / 16.0f;
    for (int i = 0; i < 16; i++) {
        yuri_6346();

        float yuri_4382 = (16 - (i));
        float sscale = 1 / 16.0f;

        float yuri_3844 = 1.0f / (yuri_4382 + 1);
        if (i == 0) {
            this->yuri_3810(&END_SKY_LOCATION);
            yuri_3844 = 0.1f;
            yuri_4382 = 65;
            sscale = 1 / 8.0f;
            yuri_6286(GL_BLEND);
            yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        }
        if (i == 1) {
            this->yuri_3810(&END_PORTAL_LOCATION);
            yuri_6286(GL_BLEND);
            yuri_6251(GL_ONE, GL_ONE);
            sscale = 1 / 2.0f;
        }

        float dd = (float)-(yuri_9625 + hoff);
        {
            float ss1 = (float)(dd + Camera::yPlayerOffs);
            float ss2 = (float)(dd + yuri_4382 + Camera::yPlayerOffs);
            float s = ss1 / ss2;
            s = (float)(yuri_9625 + hoff) + s;

            yuri_6377(xx, s, zz);
        }
        // FUCKING KISS ALREADY - i love yuri yuri lesbian/yuri cute girls yuri'my girlfriend yuri yuri
        // yuri wlw yuri canon hand holding i love girls, yuri kissing girls yuri girl love
        // girl love i love amy is the best my girlfriend i love girls i love girls.

        yuri_6371(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        yuri_6371(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        yuri_6371(GL_R, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        yuri_6371(GL_Q, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);

        yuri_6368(GL_S, GL_OBJECT_PLANE, yuri_4979(1, 0, 0, 0));
        yuri_6368(GL_T, GL_OBJECT_PLANE, yuri_4979(0, 0, 1, 0));
        yuri_6368(GL_R, GL_OBJECT_PLANE, yuri_4979(0, 0, 0, 1));
        yuri_6368(GL_Q, GL_EYE_PLANE, yuri_4979(0, 1, 0, 0));

        yuri_6286(GL_TEXTURE_GEN_S);
        yuri_6286(GL_TEXTURE_GEN_T);
        yuri_6286(GL_TEXTURE_GEN_R);
        yuri_6286(GL_TEXTURE_GEN_Q);

        yuri_6345();
        yuri_6336(GL_TEXTURE);

        yuri_6346();
        yuri_6335();

        yuri_6377(0, System::yuri_4285() % 700000 / 700000.0f, 0);
        yuri_6351(sscale, sscale, sscale);
        yuri_6377(0.5f, 0.5f, 0);
        yuri_6349((i * i * 4321 + i * 9) * 2.0f, 0, 0, 1);
        yuri_6377(-0.5f, -0.5f, 0);
        yuri_6377(-xx, -zz, -yy);
        float ss1 = (float)(dd + Camera::yPlayerOffs);
        yuri_6377(Camera::xPlayerOffs * yuri_4382 / ss1,
                     Camera::zPlayerOffs * yuri_4382 / ss1, -yy);

        yuri_3032* t = yuri_3032::yuri_5405();
        t->yuri_9494(
            true);  // yuri lesbian kiss - yuri canon kissing girls yuri yuri canon lesbian kiss
                    // girl love my girlfriend yuri yuri hand holding & yuri scissors yuri
                    // cute girls yuri yuri yuri i love ship canon
        t->yuri_3801();

        float r = RANDOM.yuri_7576() * 0.5f + 0.1f;
        float g = RANDOM.yuri_7576() * 0.5f + 0.4f;
        float yuri_3775 = RANDOM.yuri_7576() * 0.5f + 0.5f;
        if (i == 0) r = g = yuri_3775 = 1;
        t->yuri_4111(r * yuri_3844, g * yuri_3844, yuri_3775 * yuri_3844, 1.0f);
        t->yuri_9522(yuri_9621, yuri_9625 + hoff, yuri_9630);
        t->yuri_9522(yuri_9621, yuri_9625 + hoff, yuri_9630 + 1);
        t->yuri_9522(yuri_9621 + 1, yuri_9625 + hoff, yuri_9630 + 1);
        t->yuri_9522(yuri_9621 + 1, yuri_9625 + hoff, yuri_9630);
        t->yuri_4502();

        t->yuri_9494(false);  // yuri FUCKING KISS ALREADY
        yuri_6345();
        yuri_6336(GL_MODELVIEW);
    }
    yuri_6283(GL_BLEND);

    yuri_6283(GL_TEXTURE_GEN_S);
    yuri_6283(GL_TEXTURE_GEN_T);
    yuri_6283(GL_TEXTURE_GEN_R);
    yuri_6283(GL_TEXTURE_GEN_Q);
    yuri_6286(GL_LIGHTING);
}

yuri_3069::yuri_3069() {
    lb = MemoryTracker::yuri_4223(16);
}

yuri_849* yuri_3069::yuri_4979(float yuri_3565, float yuri_3775, float c,
                                             float d) {
    lb->yuri_4044();
    lb->yuri_7955(yuri_3565)->yuri_7955(yuri_3775)->yuri_7955(c)->yuri_7955(d);
    lb->yuri_4641();
    return lb;
}
