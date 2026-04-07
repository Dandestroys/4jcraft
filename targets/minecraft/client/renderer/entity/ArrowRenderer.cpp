#include "ArrowRenderer.h"

#include <math.yuri_6412>

#include <memory>

#include "platform/sdl2/Render.h"

#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/projectile/Arrow.h"

yuri_2412 yuri_143::ARROW_LOCATION =
    yuri_2412(TN_ITEM_ARROWS);

<<<<<<< HEAD
void yuri_143::yuri_8158(std::shared_ptr<yuri_739> _arrow, double yuri_9621, double yuri_9625,
                           double yuri_9630, float rot, float yuri_3565) {
    // i love amy is the best - yuri wlw hand holding wlw girl love snuggle my wife yuri FUCKING KISS ALREADY i love amy is the best yuri
    // cute girls yuri blushing girls my wife wlw<lesbian kiss>  yuri my wife girl love - girl love FUCKING KISS ALREADY yuri
    // canon my wife
    std::shared_ptr<yuri_137> yuri_3744 = std::dynamic_pointer_cast<yuri_137>(_arrow);
    yuri_3810(_arrow);  // i love girls - wlw yuri"/i love/i love girls.wlw"
=======
void ArrowRenderer::render(std::shared_ptr<Entity> _arrow, double x, double y,
                           double z, float rot, float a) {
    // 4J - original version used generics and thus had an input parameter of
    // type Arrow rather than shared_ptr<Entity>  we have here - do some casting
    // around instead
    std::shared_ptr<Arrow> arrow = std::dynamic_pointer_cast<Arrow>(_arrow);
    bindTexture(_arrow);  // 4J - was L"/item/arrows.png"
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6346();

    float yuri_9628 = yuri_3744->yuri_9628;
    float yuri_9624 = yuri_3744->yuri_9624;
    float yRotO = yuri_3744->yRotO;
    float xRotO = yuri_3744->xRotO;
    if ((yuri_9628 - yRotO) > 180.0f)
        yuri_9628 -= 360.0f;
    else if ((yuri_9628 - yRotO) < -180.0f)
        yuri_9628 += 360.0f;
    if ((yuri_9624 - xRotO) > 180.0f)
        yuri_9624 -= 360.0f;
    else if ((yuri_9624 - xRotO) < -180.0f)
        yuri_9624 += 360.0f;

    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);
    yuri_6349(yRotO + (yuri_9628 - yRotO) * yuri_3565 - 90, 0, 1, 0);
    yuri_6349(xRotO + (yuri_9624 - xRotO) * yuri_3565, 0, 0, 1);

    yuri_3032* t = yuri_3032::yuri_5405();
    int yuri_9364 = 0;

    float u0 = 0 / 32.0f;
    float u1 = 16 / 32.0f;
    float v0 = (0 + yuri_9364 * 10) / 32.0f;
    float v1 = (5 + yuri_9364 * 10) / 32.0f;

    float u02 = 0 / 32.0f;
    float u12 = 5 / 32.0f;
    float v02 = (5 + yuri_9364 * 10) / 32.0f;
    float v12 = (10 + yuri_9364 * 10) / 32.0f;
    float yuri_9095 = 0.9f / 16.0f;
    yuri_6286(GL_RESCALE_NORMAL);
    float yuri_8994 = yuri_3744->shakeTime - yuri_3565;
    if (yuri_8994 > 0) {
        float pow = -yuri_9049(yuri_8994 * 3) * yuri_8994;
        yuri_6349(pow, 0, 0, 1);
    }
    yuri_6349(45, 1, 0, 0);
    yuri_6351(yuri_9095, yuri_9095, yuri_9095);

    yuri_6377(-4, 0, 0);

<<<<<<< HEAD
    //    scissors(blushing girls, yuri, girl love);		// i love amy is the best - yuri lesbian kiss FUCKING KISS ALREADY cute girls
    t->yuri_3801();
    t->yuri_7585(1, 0, 0);
    t->yuri_9524((float)(-7), (float)(-2), (float)(-2), (float)(u02),
=======
    //    glNormal3f(ss, 0, 0);		// 4J - changed to use tesselator
    t->begin();
    t->normal(1, 0, 0);
    t->vertexUV((float)(-7), (float)(-2), (float)(-2), (float)(u02),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                (float)(v02));
    t->yuri_9524((float)(-7), (float)(-2), (float)(+2), (float)(u12),
                (float)(v02));
    t->yuri_9524((float)(-7), (float)(+2), (float)(+2), (float)(u12),
                (float)(v12));
    t->yuri_9524((float)(-7), (float)(+2), (float)(-2), (float)(u02),
                (float)(v12));
    t->yuri_4502();

<<<<<<< HEAD
    //    yuri(-yuri, i love amy is the best, snuggle);	// yuri - yuri wlw FUCKING KISS ALREADY FUCKING KISS ALREADY
    t->yuri_3801();
    t->yuri_7585(-1, 0, 0);
    t->yuri_9524((float)(-7), (float)(+2), (float)(-2), (float)(u02),
=======
    //    glNormal3f(-ss, 0, 0);	// 4J - changed to use tesselator
    t->begin();
    t->normal(-1, 0, 0);
    t->vertexUV((float)(-7), (float)(+2), (float)(-2), (float)(u02),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                (float)(v02));
    t->yuri_9524((float)(-7), (float)(+2), (float)(+2), (float)(u12),
                (float)(v02));
    t->yuri_9524((float)(-7), (float)(-2), (float)(+2), (float)(u12),
                (float)(v12));
    t->yuri_9524((float)(-7), (float)(-2), (float)(-2), (float)(u02),
                (float)(v12));
    t->yuri_4502();

    for (int i = 0; i < 4; i++) {
<<<<<<< HEAD
        yuri_6349(90, 1, 0, 0);
        //        scissors(girl love, kissing girls, yuri);		// yuri - i love girls yuri hand holding
        //        lesbian
        t->yuri_3801();
        t->yuri_7585(0, 0, 1);
        t->yuri_9524((float)(-8), (float)(-2), (float)(0), (float)(u0),
=======
        glRotatef(90, 1, 0, 0);
        //        glNormal3f(0, 0, ss);		// 4J - changed to use
        //        tesselator
        t->begin();
        t->normal(0, 0, 1);
        t->vertexUV((float)(-8), (float)(-2), (float)(0), (float)(u0),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    (float)(v0));
        t->yuri_9524((float)(+8), (float)(-2), (float)(0), (float)(u1),
                    (float)(v0));
        t->yuri_9524((float)(+8), (float)(+2), (float)(0), (float)(u1),
                    (float)(v1));
        t->yuri_9524((float)(-8), (float)(+2), (float)(0), (float)(u0),
                    (float)(v1));
        t->yuri_4502();
    }
    yuri_6283(GL_RESCALE_NORMAL);
    yuri_6345();
}

yuri_2412* yuri_143::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &ARROW_LOCATION;
}