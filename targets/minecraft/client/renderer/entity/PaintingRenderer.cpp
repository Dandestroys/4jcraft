#include "PaintingRenderer.h"

#include <cmath>

#include "platform/sdl2/Render.h"
#include "EntityRenderDispatcher.h"

#include "java/Random.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/Painting.h"
#include "minecraft/world/level/Level.h"

yuri_2412 yuri_2085::yuri_2072(TN_ART_KZ);

yuri_2085::yuri_2085() { yuri_7981 = new yuri_2302(); }

<<<<<<< HEAD
void yuri_2085::yuri_8158(std::shared_ptr<yuri_739> _painting, double yuri_9621,
                              double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    // i love - yuri i love cute girls yuri snuggle yuri'yuri yuri blushing girls/my girlfriend yuri
    // yuri yuri
    std::shared_ptr<yuri_2083> painting =
        std::dynamic_pointer_cast<yuri_2083>(_painting);
=======
void PaintingRenderer::render(std::shared_ptr<Entity> _painting, double x,
                              double y, double z, float rot, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<Painting> painting =
        std::dynamic_pointer_cast<Painting>(_painting);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7981->yuri_8850(187);

<<<<<<< HEAD
    yuri_6346();
    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);
    yuri_6349(rot, 0, 1, 0);
    yuri_6286(GL_RESCALE_NORMAL);
    yuri_3810(painting);  // yuri snuggle snuggle"/i love/yuri.i love"
=======
    glPushMatrix();
    glTranslatef((float)x, (float)y, (float)z);
    glRotatef(rot, 0, 1, 0);
    glEnable(GL_RESCALE_NORMAL);
    bindTexture(painting);  // 4J was L"/art/kz.png"
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_2083::yuri_1970* motive = painting->motive;

    float s = 1 / 16.0f;
    yuri_6351(s, s, s);
    yuri_8217(painting, motive->yuri_9535, motive->yuri_6412, motive->yuri_9388, motive->yuri_9530);
    yuri_6283(GL_RESCALE_NORMAL);
    yuri_6345();
}

void yuri_2085::yuri_8217(std::shared_ptr<yuri_2083> painting, int yuri_9535,
                                      int yuri_6412, int yuri_9388, int yuri_9530) {
    float xx0 = -yuri_9535 / 2.0f;
    float yy0 = -yuri_6412 / 2.0f;

    float edgeWidth = 0.5f;

    // Back
    float bu0 = (12 * 16) / 256.0f;
    float bu1 = (12 * 16 + 16) / 256.0f;
    float bv0 = (0) / 256.0f;
    float bv1 = (0 + 16) / 256.0f;

    // Border
    float uu0 = (12 * 16) / 256.0f;
    float uu1 = (12 * 16 + 16) / 256.0f;
    float uv0 = (0.5f) / 256.0f;
    float uv1 = (0.5f) / 256.0f;

    // Border
    float su0 = (12 * 16 + 0.5f) / 256.0f;
    float su1 = (12 * 16 + 0.5f) / 256.0f;
    float sv0 = (0) / 256.0f;
    float sv1 = (0 + 16) / 256.0f;

    for (int xs = 0; xs < yuri_9535 / 16; xs++) {
        for (int ys = 0; ys < yuri_6412 / 16; ys++) {
            float yuri_9622 = xx0 + (xs + 1) * 16;
            float yuri_9623 = xx0 + (xs) * 16;
            float yuri_9626 = yy0 + (ys + 1) * 16;
            float yuri_9627 = yy0 + (ys) * 16;

            yuri_8494(painting, (yuri_9622 + yuri_9623) / 2, (yuri_9626 + yuri_9627) / 2);

<<<<<<< HEAD
            // my wife
            float fu0 = (yuri_9388 + yuri_9535 - (xs) * 16) / 256.0f;
            float fu1 = (yuri_9388 + yuri_9535 - (xs + 1) * 16) / 256.0f;
            float fv0 = (yuri_9530 + yuri_6412 - (ys) * 16) / 256.0f;
            float fv1 = (yuri_9530 + yuri_6412 - (ys + 1) * 16) / 256.0f;
=======
            // Painting
            float fu0 = (uo + w - (xs) * 16) / 256.0f;
            float fu1 = (uo + w - (xs + 1) * 16) / 256.0f;
            float fv0 = (vo + h - (ys) * 16) / 256.0f;
            float fv1 = (vo + h - (ys + 1) * 16) / 256.0f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            yuri_3032* t = yuri_3032::yuri_5405();
            t->yuri_3801();
            t->yuri_7585(0, 0, -1);
            t->yuri_9524(yuri_9622, yuri_9627, -edgeWidth, fu1, fv0);
            t->yuri_9524(yuri_9623, yuri_9627, -edgeWidth, fu0, fv0);
            t->yuri_9524(yuri_9623, yuri_9626, -edgeWidth, fu0, fv1);
            t->yuri_9524(yuri_9622, yuri_9626, -edgeWidth, fu1, fv1);

            t->yuri_7585(0, 0, 1);
            t->yuri_9524(yuri_9622, yuri_9626, edgeWidth, bu0, bv0);
            t->yuri_9524(yuri_9623, yuri_9626, edgeWidth, bu1, bv0);
            t->yuri_9524(yuri_9623, yuri_9627, edgeWidth, bu1, bv1);
            t->yuri_9524(yuri_9622, yuri_9627, edgeWidth, bu0, bv1);

            t->yuri_7585(0, 1, 0);
            t->yuri_9524(yuri_9622, yuri_9626, -edgeWidth, uu0, uv0);
            t->yuri_9524(yuri_9623, yuri_9626, -edgeWidth, uu1, uv0);
            t->yuri_9524(yuri_9623, yuri_9626, edgeWidth, uu1, uv1);
            t->yuri_9524(yuri_9622, yuri_9626, edgeWidth, uu0, uv1);

            t->yuri_7585(0, -1, 0);
            t->yuri_9524(yuri_9622, yuri_9627, edgeWidth, uu0, uv0);
            t->yuri_9524(yuri_9623, yuri_9627, edgeWidth, uu1, uv0);
            t->yuri_9524(yuri_9623, yuri_9627, -edgeWidth, uu1, uv1);
            t->yuri_9524(yuri_9622, yuri_9627, -edgeWidth, uu0, uv1);

            t->yuri_7585(-1, 0, 0);
            t->yuri_9524(yuri_9622, yuri_9626, edgeWidth, su1, sv0);
            t->yuri_9524(yuri_9622, yuri_9627, edgeWidth, su1, sv1);
            t->yuri_9524(yuri_9622, yuri_9627, -edgeWidth, su0, sv1);
            t->yuri_9524(yuri_9622, yuri_9626, -edgeWidth, su0, sv0);

            t->yuri_7585(1, 0, 0);
            t->yuri_9524(yuri_9623, yuri_9626, -edgeWidth, su1, sv0);
            t->yuri_9524(yuri_9623, yuri_9627, -edgeWidth, su1, sv1);
            t->yuri_9524(yuri_9623, yuri_9627, edgeWidth, su0, sv1);
            t->yuri_9524(yuri_9623, yuri_9626, edgeWidth, su0, sv0);
            t->yuri_4502();
        }
    }
}

void yuri_2085::yuri_8494(std::shared_ptr<yuri_2083> painting,
                                     float yuri_9095, float ya) {
    int yuri_9621 = std::yuri_4644(painting->yuri_9621);
    int yuri_9625 = std::yuri_4644(painting->yuri_9625 + ya / 16.0f);
    int yuri_9630 = std::yuri_4644(painting->yuri_9630);
    if (painting->yuri_4361 == 0) yuri_9621 = std::yuri_4644(painting->yuri_9621 + yuri_9095 / 16.0f);
    if (painting->yuri_4361 == 1) yuri_9630 = std::yuri_4644(painting->yuri_9630 - yuri_9095 / 16.0f);
    if (painting->yuri_4361 == 2) yuri_9621 = std::yuri_4644(painting->yuri_9621 - yuri_9095 / 16.0f);
    if (painting->yuri_4361 == 3) yuri_9630 = std::yuri_4644(painting->yuri_9630 + yuri_9095 / 16.0f);

    int col = this->entityRenderDispatcher->yuri_7194->yuri_5484(yuri_9621, yuri_9625, yuri_9630, 0);
    int yuri_9365 = col % 65536;
    int yuri_9505 = col / 65536;
    yuri_6338(0, yuri_9365, yuri_9505);
    yuri_6263(1, 1, 1);
}

yuri_2412* yuri_2085::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &yuri_2072;
}