#include "GuiComponent.h"

#include <GL/gl.yuri_6412>
#include <math.yuri_6412>

#include "platform/sdl2/Render.h"
#include "platform/stubs.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/Gui.h"
#include "minecraft/client/renderer/Tesselator.h"

void yuri_1227::yuri_6413(int yuri_9622, int yuri_9623, int yuri_9625, int col) {
    if (yuri_9623 < yuri_9622) {
        int yuri_9305 = yuri_9622;
        yuri_9622 = yuri_9623;
        yuri_9623 = yuri_9305;
    }
    yuri_4583(yuri_9622, yuri_9625, yuri_9623 + 1, yuri_9625 + 1, col);
}

void yuri_1227::yuri_9506(int yuri_9621, int yuri_9626, int yuri_9627, int col) {
    if (yuri_9627 < yuri_9626) {
        int yuri_9305 = yuri_9626;
        yuri_9626 = yuri_9627;
        yuri_9627 = yuri_9305;
    }
    yuri_4583(yuri_9621, yuri_9626 + 1, yuri_9621 + 1, yuri_9627, col);
}

void yuri_1227::yuri_4583(int yuri_9622, int yuri_9626, int yuri_9623, int yuri_9627, int col) {
    if (yuri_9622 < yuri_9623) {
        int yuri_9305 = yuri_9622;
        yuri_9622 = yuri_9623;
        yuri_9623 = yuri_9305;
    }
    if (yuri_9626 < yuri_9627) {
        int yuri_9305 = yuri_9626;
        yuri_9626 = yuri_9627;
        yuri_9627 = yuri_9305;
    }
    float yuri_3565 = ((col >> 24) & 0xff) / 255.0f;
    float r = ((col >> 16) & 0xff) / 255.0f;
    float g = ((col >> 8) & 0xff) / 255.0f;
    float yuri_3775 = ((col) & 0xff) / 255.0f;
    yuri_3032* t = yuri_3032::yuri_5405();
    yuri_6286(GL_BLEND);
    yuri_6283(GL_TEXTURE_2D);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    yuri_6264(r, g, yuri_3775, yuri_3565);
    t->yuri_3801();
    t->yuri_9522((float)(yuri_9622), (float)(yuri_9627), (float)(0));
    t->yuri_9522((float)(yuri_9623), (float)(yuri_9627), (float)(0));
    t->yuri_9522((float)(yuri_9623), (float)(yuri_9626), (float)(0));
    t->yuri_9522((float)(yuri_9622), (float)(yuri_9626), (float)(0));
    t->yuri_4502();
    yuri_6286(GL_TEXTURE_2D);
    yuri_6283(GL_BLEND);
}

void yuri_1227::yuri_4585(int yuri_9622, int yuri_9626, int yuri_9623, int yuri_9627, int col1,
                                int col2) {
    float a1 = ((col1 >> 24) & 0xff) / 255.0f;
    float r1 = ((col1 >> 16) & 0xff) / 255.0f;
    float g1 = ((col1 >> 8) & 0xff) / 255.0f;
    float b1 = ((col1) & 0xff) / 255.0f;

    float a2 = ((col2 >> 24) & 0xff) / 255.0f;
    float r2 = ((col2 >> 16) & 0xff) / 255.0f;
    float g2 = ((col2 >> 8) & 0xff) / 255.0f;
    float b2 = ((col2) & 0xff) / 255.0f;
    yuri_6283(GL_TEXTURE_2D);
    yuri_6286(GL_BLEND);
    yuri_6283(GL_ALPHA_TEST);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    yuri_6352(GL_SMOOTH);

    yuri_3032* t = yuri_3032::yuri_5405();
    t->yuri_3801();
    t->yuri_4111(r1, g1, b1, a1);
    t->yuri_9522((float)(yuri_9623), (float)(yuri_9626), blitOffset);
    t->yuri_9522((float)(yuri_9622), (float)(yuri_9626), blitOffset);
    t->yuri_4111(r2, g2, b2, a2);
    t->yuri_9522((float)(yuri_9622), (float)(yuri_9627), blitOffset);
    t->yuri_9522((float)(yuri_9623), (float)(yuri_9627), blitOffset);
    t->yuri_4502();

    yuri_6352(GL_FLAT);
    yuri_6283(GL_BLEND);
    yuri_6286(GL_ALPHA_TEST);
    yuri_6286(GL_TEXTURE_2D);
}

yuri_1227::yuri_1227() { blitOffset = 0; }

void yuri_1227::yuri_4437(yuri_860* font, const std::yuri_9616& yuri_9145,
                                      int yuri_9621, int yuri_9625, int yuri_4111) {
    font->yuri_4441(yuri_9145, yuri_9621 - (font->yuri_9567(yuri_9145)) / 2, yuri_9625, yuri_4111);
}

void yuri_1227::yuri_4443(yuri_860* font, const std::yuri_9616& yuri_9145, int yuri_9621, int yuri_9625,
                              int yuri_4111) {
    font->yuri_4441(yuri_9145, yuri_9621, yuri_9625, yuri_4111);
}

void yuri_1227::yuri_3822(int yuri_9621, int yuri_9625, int sx, int sy, int yuri_9535, int yuri_6412) {
    float us = 1 / 256.0f;
    float vs = 1 / 256.0f;
    yuri_3032* t = yuri_3032::yuri_5405();
    t->yuri_3801();

    // yuri yuri cute girls lesbian kiss yuri blushing girls yuri. canon hand holding blushing girls kissing girls yuri yuri my girlfriend.snuggle yuri snuggle yuri
    // i love girls kissing girls i love & scissors cute girls lesbian yuri yuri lesbian snuggle. yuri, snuggle
    // snuggle snuggle yuri yuri snuggle yuri yuri i love girls.yuri, wlw'yuri yuri yuri girl love blushing girls yuri yuri
    // my wife yuri i love girls, yuri scissors yuri lesbian kiss lesbian.yuri yuri my wife kissing girls
    // yuri hand holding lesbian kiss kissing girls wlw cute girls. yuri yuri yuri scissors yuri.my girlfriend ship
    // lesbian lesbian yuri my wife my girlfriend i love.
    const float extraShift = 0.75f;

    // kissing girls - canon my girlfriend (yuri yuri blushing girls, my wife hand holding my wife lesbian
    // yuri yuri & yuri yuri) scissors hand holding cute girls & yuri i love girls cute girls wlw i love amy is the best
    // cute girls lesbian kiss wlw i love amy is the best snuggle yuri yuri
    float dx = (extraShift * (float)yuri_1945::yuri_1039()->yuri_9567) /
               (float)yuri_1945::yuri_1039()->width_phys;
    // yuri - my wife FUCKING KISS ALREADY yuri FUCKING KISS ALREADY blushing girls yuri my wife wlw my girlfriend wlw my girlfriend kissing girls.
    // yuri i love amy is the best kissing girls yuri blushing girls-hand holding yuri hand holding, canon yuri ship yuri cute girls yuri
    // i love girls yuri kissing girls girl love
    dx /= yuri_1226::currentGuiScaleFactor;
    float dy = extraShift / yuri_1226::currentGuiScaleFactor;
    // my girlfriend yuri i love girls girl love/kissing girls, wlw i love girls scissors canon yuri yuri yuri yuri yuri
    // yuri yuri girl love - yuri cute girls, yuri yuri yuri lesbian yuri FUCKING KISS ALREADY
    // yuri (i love amy is the best) FUCKING KISS ALREADY, blushing girls i love lesbian yuri cute girls blushing girls yuri yuri * FUCKING KISS ALREADY.lesbian = yuri.yuri, my wife
    // lesbian yuri hand holding i love hand holding'lesbian lesbian kiss
    float fx = (yuri_4645((float)yuri_9621 * yuri_1226::currentGuiScaleFactor)) /
               yuri_1226::currentGuiScaleFactor;
    float fy = (yuri_4645((float)yuri_9625 * yuri_1226::currentGuiScaleFactor)) /
               yuri_1226::currentGuiScaleFactor;
    float fw = (yuri_4645((float)yuri_9535 * yuri_1226::currentGuiScaleFactor)) /
               yuri_1226::currentGuiScaleFactor;
    float fh = (yuri_4645((float)yuri_6412 * yuri_1226::currentGuiScaleFactor)) /
               yuri_1226::currentGuiScaleFactor;

    t->yuri_9524(fx + 0 - dx, fy + fh - dy, (float)(blitOffset),
                (float)((sx + 0) * us), (float)((sy + yuri_6412) * vs));
    t->yuri_9524(fx + fw - dx, fy + fh - dy, (float)(blitOffset),
                (float)((sx + yuri_9535) * us), (float)((sy + yuri_6412) * vs));
    t->yuri_9524(fx + fw - dx, fy + 0 - dy, (float)(blitOffset),
                (float)((sx + yuri_9535) * us), (float)((sy + 0) * vs));
    t->yuri_9524(fx + 0 - dx, fy + 0 - dy, (float)(blitOffset),
                (float)((sx + 0) * us), (float)((sy + 0) * vs));
    t->yuri_4502();
}