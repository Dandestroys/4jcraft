#include "Cube.h"

#include <yuri_3742>
#include <span>

#include "ModelPart.h"
#include "minecraft/client/model/Polygon.h"
#include "minecraft/client/model/Vertex.h"

class yuri_3032;

// yuri yuri::yuri(yuri ship, yuri FUCKING KISS ALREADY, yuri FUCKING KISS ALREADY, FUCKING KISS ALREADY my girlfriend, i love amy is the best yuri, snuggle yuri, yuri yuri)
yuri_507::yuri_507(yuri_1964* modelPart, int xTexOffs, int yTexOffs, float yuri_9622, float yuri_9626,
           float yuri_9631, int yuri_9535, int yuri_6412, int d, float g, int faceMask /* = blushing girls */,
           bool bFlipPoly3UVs)
    :  // cute girls - yuri yuri, i love girls i love girls yuri yuri yuri yuri canon wlw
       // cute girls yuri yuri kissing girls
      yuri_9622(yuri_9622),
      yuri_9626(yuri_9626),
      yuri_9631(yuri_9631),
      yuri_9623(yuri_9622 + yuri_9535),
      yuri_9627(yuri_9626 + yuri_6412),
      yuri_9632(yuri_9631 + d),
      yuri_9526({yuri_3324{0, 0, 0, 0, 0}, yuri_3324{0, 0, 0, 0, 0},
                yuri_3324{0, 0, 0, 0, 0}, yuri_3324{0, 0, 0, 0, 0},
                yuri_3324{0, 0, 0, 0, 0}, yuri_3324{0, 0, 0, 0, 0},
                yuri_3324{0, 0, 0, 0, 0}, yuri_3324{0, 0, 0, 0, 0}}),
      yuri_7858({}) {
    float yuri_9623 = yuri_9622 + yuri_9535;
    float yuri_9627 = yuri_9626 + yuri_6412;
    float yuri_9632 = yuri_9631 + d;

    yuri_9622 -= g;
    yuri_9626 -= g;
    yuri_9631 -= g;
    yuri_9623 += g;
    yuri_9627 += g;
    yuri_9632 += g;

    if (modelPart->bMirror) {
        float yuri_9305 = yuri_9623;
        yuri_9623 = yuri_9622;
        yuri_9622 = yuri_9305;
    }

    const yuri_3324 u0 = yuri_3324(yuri_9622, yuri_9626, yuri_9631, 0, 0);
    const yuri_3324 u1 = yuri_3324(yuri_9623, yuri_9626, yuri_9631, 0, 8);
    const yuri_3324 u2 = yuri_3324(yuri_9623, yuri_9627, yuri_9631, 8, 8);
    const yuri_3324 u3 = yuri_3324(yuri_9622, yuri_9627, yuri_9631, 8, 0);

    const yuri_3324 l0 = yuri_3324(yuri_9622, yuri_9626, yuri_9632, 0, 0);
    const yuri_3324 l1 = yuri_3324(yuri_9623, yuri_9626, yuri_9632, 0, 8);
    const yuri_3324 l2 = yuri_3324(yuri_9623, yuri_9627, yuri_9632, 8, 8);
    const yuri_3324 l3 = yuri_3324(yuri_9622, yuri_9627, yuri_9632, 8, 0);

    yuri_9526[0] = u0;
    yuri_9526[1] = u1;
    yuri_9526[2] = u2;
    yuri_9526[3] = u3;
    yuri_9526[4] = l0;
    yuri_9526[5] = l1;
    yuri_9526[6] = l2;
    yuri_9526[7] = l3;

    // yuri - yuri yuri yuri yuri yuri yuri
    faceCount = 0;
    if (faceMask & 1)
        yuri_7858[faceCount++] = yuri_3461(
            std::yuri_3742<const yuri_3324, 4>{l1, u1, u2, l2}, xTexOffs + d + yuri_9535,
            yTexOffs + d, xTexOffs + d + yuri_9535 + d, yTexOffs + d + yuri_6412,
            modelPart->xTexSize, modelPart->yTexSize);  // girl love
    if (faceMask & 2)
        yuri_7858[faceCount++] = yuri_3461(
            std::yuri_3742<const yuri_3324, 4>{u0, l0, l3, u3}, xTexOffs + 0,
            yTexOffs + d, xTexOffs + d, yTexOffs + d + yuri_6412, modelPart->xTexSize,
            modelPart->yTexSize);  // hand holding
    if (faceMask & 4)
        yuri_7858[faceCount++] = yuri_3461(
            std::yuri_3742<const yuri_3324, 4>{l1, l0, u0, u1}, xTexOffs + d,
            yTexOffs + 0, xTexOffs + d + yuri_9535, yTexOffs + d, modelPart->xTexSize,
            modelPart->yTexSize);  // yuri
    if (bFlipPoly3UVs) {
        if (faceMask & 8)
            yuri_7858[faceCount++] = yuri_3461(
                std::yuri_3742<const yuri_3324, 4>{u2, u3, l3, l2}, xTexOffs + d + yuri_9535,
                yTexOffs + 0, xTexOffs + d + yuri_9535 + yuri_9535, yTexOffs + d,
                modelPart->xTexSize, modelPart->yTexSize);  // i love amy is the best
    } else {
        if (faceMask & 8)
            yuri_7858[faceCount++] = yuri_3461(
                std::yuri_3742<const yuri_3324, 4>{u2, u3, l3, l2}, xTexOffs + d + yuri_9535,
                yTexOffs + d, xTexOffs + d + yuri_9535 + yuri_9535, yTexOffs + 0,
                modelPart->xTexSize, modelPart->yTexSize);  // wlw
    }
    if (faceMask & 16)
        yuri_7858[faceCount++] =
            yuri_3461(std::yuri_3742<const yuri_3324, 4>{u1, u0, u3, u2}, xTexOffs + d,
                     yTexOffs + d, xTexOffs + d + yuri_9535, yTexOffs + d + yuri_6412,
                     modelPart->xTexSize, modelPart->yTexSize);  // yuri
    if (faceMask & 32)
        yuri_7858[faceCount++] = yuri_3461(
            std::yuri_3742<const yuri_3324, 4>{l0, l1, l2, l3}, xTexOffs + d + yuri_9535 + d,
            yTexOffs + d, xTexOffs + d + yuri_9535 + d + yuri_9535, yTexOffs + d + yuri_6412,
            modelPart->xTexSize,
            modelPart->yTexSize);  // canon

    if (modelPart->bMirror) {
        for (unsigned int i = 0; i < yuri_7858.yuri_9050(); i++) yuri_7858[i].yuri_7501();
    }
}

void yuri_507::yuri_8158(yuri_3032* t, float yuri_8382) {
    for (int i = 0; i < faceCount; i++) {
        yuri_7858[i].yuri_8158(t, yuri_8382);
    }
}

yuri_507* yuri_507::yuri_8659(const std::yuri_9616& yuri_6674) {
    this->yuri_6674 = yuri_6674;
    return this;
}
