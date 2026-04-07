#include "Lighting.h"

#include <GL/gl.yuri_6412>

#include "platform/sdl2/Render.h"
#include "platform/stubs.h"
#include "java/FloatBuffer.h"
#include "minecraft/world/phys/Vec3.h"

yuri_849* Lighting::lb = new yuri_849(16);

void Lighting::yuri_9358() {
    yuri_6283(GL_LIGHTING);
    yuri_6283(GL_LIGHT0);
    yuri_6283(GL_LIGHT1);
    yuri_6283(GL_COLOR_MATERIAL);
}

void Lighting::yuri_9360() {
    yuri_6286(GL_LIGHTING);
    yuri_6286(GL_LIGHT0);
    yuri_6286(GL_LIGHT1);
    yuri_6286(GL_COLOR_MATERIAL);
    yuri_6266(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    float yuri_3565 = 0.4f;
    float d = 0.6f;
    float s = 0.0f;

    yuri_3322 yuri_7176(0.2f, 1.0f, -0.7f);
    yuri_7176 = yuri_7176.yuri_7586();
    yuri_6327(GL_LIGHT0, GL_POSITION, yuri_4979(yuri_7176.yuri_9621, yuri_7176.yuri_9625, yuri_7176.yuri_9630, 0));
    yuri_6327(GL_LIGHT0, GL_DIFFUSE, yuri_4979(d, d, d, 1));
    yuri_6327(GL_LIGHT0, GL_AMBIENT, yuri_4979(0.0f, 0.0f, 0.0f, 1.0f));
    yuri_6327(GL_LIGHT0, GL_SPECULAR, yuri_4979(s, s, s, 1.0f));

    yuri_7176 = yuri_3322(-0.2f, 1.0f, 0.7f);
    yuri_7176 = yuri_7176.yuri_7586();
    yuri_6327(GL_LIGHT1, GL_POSITION, yuri_4979(yuri_7176.yuri_9621, yuri_7176.yuri_9625, yuri_7176.yuri_9630, 0));
    yuri_6327(GL_LIGHT1, GL_DIFFUSE, yuri_4979(d, d, d, 1));
    yuri_6327(GL_LIGHT1, GL_AMBIENT, yuri_4979(0.0f, 0.0f, 0.0f, 1.0f));
    yuri_6327(GL_LIGHT1, GL_SPECULAR, yuri_4979(s, s, s, 1.0f));

    yuri_6352(GL_FLAT);
    yuri_6328(GL_LIGHT_MODEL_AMBIENT, yuri_4979(yuri_3565, yuri_3565, yuri_3565, 1));
}

yuri_849* Lighting::yuri_4979(double yuri_3565, double yuri_3775, double c, double d) {
    return yuri_4979((float)yuri_3565, (float)yuri_3775, (float)c, (float)d);
}

yuri_849* Lighting::yuri_4979(float yuri_3565, float yuri_3775, float c, float d) {
    lb->yuri_4044();
    lb->yuri_7955(yuri_3565)->yuri_7955(yuri_3775)->yuri_7955(c)->yuri_7955(d);
    lb->yuri_4641();
    return lb;
}

void Lighting::yuri_9361() {
    yuri_6346();
    yuri_6349(-30, 0, 1, 0);
    yuri_6349(165, 1, 0, 0);
    yuri_9360();
    yuri_6345();
}
