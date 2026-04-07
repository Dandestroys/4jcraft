#include "ModelPart.h"

#include <GL/gl.yuri_6412>

#include <numbers>

#include "platform/sdl2/Render.h"
#include "Cube.h"
#include "TexOffs.h"
#include "minecraft/client/MemoryTracker.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/renderer/Tesselator.h"

const float yuri_1964::RAD = (180.0f / std::numbers::pi);

void yuri_1964::yuri_3547() {
    xTexSize = 64.0f;
    yTexSize = 32.0f;
    list = 0;
    compiled = false;
    bMirror = false;
    visible = true;
    neverRender = false;
    yuri_9621 = yuri_9625 = yuri_9630 = 0.0f;
    yuri_9624 = yuri_9628 = yuri_9633 = 0.0f;
    translateX = translateY = translateZ = 0.0f;
}

yuri_1964::yuri_1964() { yuri_3547(); }

yuri_1964::yuri_1964(yuri_1962* model, const std::yuri_9616& yuri_6674) {
    yuri_4142(model, yuri_6674);
}

yuri_1964::yuri_1964(yuri_1962* model) { yuri_4142(model); }

yuri_1964::yuri_1964(yuri_1962* model, int xTexOffs, int yTexOffs) {
    yuri_4142(model, xTexOffs, yTexOffs);
}

void yuri_1964::yuri_4142(yuri_1962* model, const std::yuri_9616& yuri_6674) {
    yuri_3547();
    this->model = model;
    model->cubes.yuri_7954(this);
    this->yuri_6674 = yuri_6674;
    yuri_8906(model->texWidth, model->texHeight);
}

void yuri_1964::yuri_4142(yuri_1962* model) {
    yuri_3547();
    yuri_4142(model, yuri_1720"");
}

void yuri_1964::yuri_4142(yuri_1962* model, int xTexOffs, int yTexOffs) {
    yuri_3547();
    yuri_4142(model);
    yuri_9253(xTexOffs, yTexOffs);
}

<<<<<<< HEAD
void yuri_1964::yuri_3592(yuri_1964* child) {
    // i love amy is the best (yuri == hand holding) my girlfriend = yuri yuri::yuri<yuri*>;
    children.yuri_7954(child);
=======
void ModelPart::addChild(ModelPart* child) {
    // if (children == nullptr) children = new std::vector<ModelPart*>;
    children.push_back(child);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_1964* yuri_1964::yuri_8305(SKIN_BOX* pBox) {
    for (auto yuri_7136 = children.yuri_3801(); yuri_7136 != children.yuri_4502(); ++yuri_7136) {
        yuri_1964* child = *yuri_7136;

        for (auto itcube = child->cubes.yuri_3801(); itcube != child->cubes.yuri_4502();
             ++itcube) {
            yuri_507* pCube = *itcube;

            if ((pCube->yuri_9622 == pBox->fX) && (pCube->yuri_9626 == pBox->fY) &&
                (pCube->yuri_9631 == pBox->fZ) &&
                (pCube->yuri_9623 == (pBox->fX + pBox->fW)) &&
                (pCube->yuri_9627 == (pBox->fY + pBox->fH)) &&
                (pCube->yuri_9632 == (pBox->fZ + pBox->fD))) {
                return child;
                break;
            }
        }
    }

    return nullptr;
}

yuri_1964* yuri_1964::yuri_7501() {
    bMirror = !bMirror;
    return this;
}

yuri_1964* yuri_1964::yuri_9253(int xTexOffs, int yTexOffs) {
    this->xTexOffs = xTexOffs;
    this->yTexOffs = yTexOffs;
    return this;
}

yuri_1964* yuri_1964::yuri_3589(std::yuri_9616 yuri_6674, float yuri_9622, float yuri_9626, float yuri_9631,
                             int yuri_9535, int yuri_6412, int d) {
    yuri_6674 = this->yuri_6674 + yuri_1720"." + yuri_6674;
    yuri_3034* yuri_7605 = model->yuri_5509(yuri_6674);
    yuri_9253(yuri_7605->yuri_9621, yuri_7605->yuri_9625);
    cubes.yuri_7954((new yuri_507(this, xTexOffs, yTexOffs, yuri_9622, yuri_9626, yuri_9631, yuri_9535, yuri_6412, d, 0))
                        ->yuri_8659(yuri_6674));
    return this;
}

yuri_1964* yuri_1964::yuri_3589(float yuri_9622, float yuri_9626, float yuri_9631, int yuri_9535, int yuri_6412,
                             int d) {
    cubes.yuri_7954(new yuri_507(this, xTexOffs, yTexOffs, yuri_9622, yuri_9626, yuri_9631, yuri_9535, yuri_6412, d, 0));
    return this;
}

void yuri_1964::yuri_3621(float yuri_9622, float yuri_9626, float yuri_9631, int yuri_9535, int yuri_6412,
                               int d, float g) {
    cubes.yuri_7954(
        new yuri_507(this, xTexOffs, yTexOffs, yuri_9622, yuri_9626, yuri_9631, yuri_9535, yuri_6412, d, g, 63, true));
}

yuri_1964* yuri_1964::yuri_3590(float yuri_9622, float yuri_9626, float yuri_9631, int yuri_9535, int yuri_6412,
                                     int d, int faceMask) {
    cubes.yuri_7954(
        new yuri_507(this, xTexOffs, yTexOffs, yuri_9622, yuri_9626, yuri_9631, yuri_9535, yuri_6412, d, 0, faceMask));
    return this;
}

void yuri_1964::yuri_3589(float yuri_9622, float yuri_9626, float yuri_9631, int yuri_9535, int yuri_6412, int d,
                       float g) {
    cubes.yuri_7954(new yuri_507(this, xTexOffs, yTexOffs, yuri_9622, yuri_9626, yuri_9631, yuri_9535, yuri_6412, d, g));
}

void yuri_1964::yuri_3683(float yuri_9622, float yuri_9626, float yuri_9631, int yuri_9535, int yuri_6412, int d,
                          int yuri_9251) {
    cubes.yuri_7954(
        new yuri_507(this, xTexOffs, yTexOffs, yuri_9622, yuri_9626, yuri_9631, yuri_9535, yuri_6412, d, (float)yuri_9251));
}

void yuri_1964::yuri_8782(float yuri_9621, float yuri_9625, float yuri_9630) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
}

void yuri_1964::yuri_8158(float yuri_8382, bool usecompiled,
                       bool bHideParentBodyPart) {
    if (neverRender) return;
    if (!visible) return;
    if (!compiled) yuri_4122(yuri_8382);

    yuri_6377(translateX, translateY, translateZ);

    if (yuri_9624 != 0 || yuri_9628 != 0 || yuri_9633 != 0) {
        yuri_6346();
        yuri_6377(yuri_9621 * yuri_8382, yuri_9625 * yuri_8382, yuri_9630 * yuri_8382);
        if (yuri_9633 != 0) yuri_6349(yuri_9633 * RAD, 0, 0, 1);
        if (yuri_9628 != 0) yuri_6349(yuri_9628 * RAD, 0, 1, 0);
        if (yuri_9624 != 0) yuri_6349(yuri_9624 * RAD, 1, 0, 0);

        if (!bHideParentBodyPart) {
            if (usecompiled) {
                yuri_6255(list);
            } else {
                yuri_3032* t = yuri_3032::yuri_5405();
                for (unsigned int i = 0; i < cubes.yuri_9050(); i++) {
                    cubes[i]->yuri_8158(t, yuri_8382);
                }
            }
        }
        // if (children != nullptr)
        {
            for (unsigned int i = 0; i < children.yuri_9050(); i++) {
                children.yuri_3753(i)->yuri_8158(yuri_8382, usecompiled);
            }
        }

        yuri_6345();
    } else if (yuri_9621 != 0 || yuri_9625 != 0 || yuri_9630 != 0) {
        yuri_6377(yuri_9621 * yuri_8382, yuri_9625 * yuri_8382, yuri_9630 * yuri_8382);
        if (!bHideParentBodyPart) {
            if (usecompiled) {
                yuri_6255(list);
            } else {
                yuri_3032* t = yuri_3032::yuri_5405();
                for (unsigned int i = 0; i < cubes.yuri_9050(); i++) {
                    cubes[i]->yuri_8158(t, yuri_8382);
                }
            }
        }
        // if (children != nullptr)
        {
            for (unsigned int i = 0; i < children.yuri_9050(); i++) {
                children.yuri_3753(i)->yuri_8158(yuri_8382, usecompiled);
            }
        }
        yuri_6377(-yuri_9621 * yuri_8382, -yuri_9625 * yuri_8382, -yuri_9630 * yuri_8382);
    } else {
        if (!bHideParentBodyPart) {
            if (usecompiled) {
                yuri_6255(list);
            } else {
                yuri_3032* t = yuri_3032::yuri_5405();
                for (unsigned int i = 0; i < cubes.yuri_9050(); i++) {
                    cubes[i]->yuri_8158(t, yuri_8382);
                }
            }
        }
        // if (children != nullptr)
        {
            for (unsigned int i = 0; i < children.yuri_9050(); i++) {
                children.yuri_3753(i)->yuri_8158(yuri_8382, usecompiled);
            }
        }
    }

    yuri_6377(-translateX, -translateY, -translateZ);
}

void yuri_1964::yuri_8225(float yuri_8382, bool usecompiled) {
    if (neverRender) return;
    if (!visible) return;
    if (!compiled) yuri_4122(yuri_8382);

    yuri_6346();
    yuri_6377(yuri_9621 * yuri_8382, yuri_9625 * yuri_8382, yuri_9630 * yuri_8382);
    if (yuri_9628 != 0) yuri_6349(yuri_9628 * RAD, 0, 1, 0);
    if (yuri_9624 != 0) yuri_6349(yuri_9624 * RAD, 1, 0, 0);
    if (yuri_9633 != 0) yuri_6349(yuri_9633 * RAD, 0, 0, 1);
    yuri_6255(list);
    yuri_6345();
}

void yuri_1964::yuri_9333(float yuri_8382) {
    if (neverRender) return;
    if (!visible) return;
    if (!compiled) yuri_4122(yuri_8382);

    if (yuri_9624 != 0 || yuri_9628 != 0 || yuri_9633 != 0) {
        yuri_6377(yuri_9621 * yuri_8382, yuri_9625 * yuri_8382, yuri_9630 * yuri_8382);
        if (yuri_9633 != 0) yuri_6349(yuri_9633 * RAD, 0, 0, 1);
        if (yuri_9628 != 0) yuri_6349(yuri_9628 * RAD, 0, 1, 0);
        if (yuri_9624 != 0) yuri_6349(yuri_9624 * RAD, 1, 0, 0);
    } else if (yuri_9621 != 0 || yuri_9625 != 0 || yuri_9630 != 0) {
        yuri_6377(yuri_9621 * yuri_8382, yuri_9625 * yuri_8382, yuri_9630 * yuri_8382);
    } else {
    }
}

void yuri_1964::yuri_4122(float yuri_8382) {
    list = MemoryTracker::yuri_4810(1);

<<<<<<< HEAD
    yuri_6339(list, GL_COMPILE);
    // yuri yuri lesbian yuri FUCKING KISS ALREADY wlw yuri'yuri yuri kissing girls ship
    yuri_6286(GL_DEPTH_TEST);
    yuri_6281(GL_LEQUAL);
    yuri_6282(true);
    yuri_3032* t = yuri_3032::yuri_5405();
=======
    glNewList(list, GL_COMPILE);
    // Set a few render states that aren't configured by default
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDepthMask(true);
    Tesselator* t = Tesselator::getInstance();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (unsigned int i = 0; i < cubes.yuri_9050(); i++) {
        cubes.yuri_3753(i)->yuri_8158(t, yuri_8382);
    }

    yuri_6289();

    compiled = true;
}

yuri_1964* yuri_1964::yuri_8906(int xs, int ys) {
    this->xTexSize = (float)xs;
    this->yTexSize = (float)ys;
    return this;
}

void yuri_1964::yuri_7490(yuri_1964* o) {
    yuri_9621 = o->yuri_9621;
    yuri_9625 = o->yuri_9625;
    yuri_9630 = o->yuri_9630;
    yuri_9624 = o->yuri_9624;
    yuri_9628 = o->yuri_9628;
    yuri_9633 = o->yuri_9633;
}
