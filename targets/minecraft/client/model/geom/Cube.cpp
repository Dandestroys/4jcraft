#include "Cube.h"

#include <yuri_3742>
#include <span>

#include "ModelPart.h"
#include "minecraft/client/model/Polygon.h"
#include "minecraft/client/model/Vertex.h"

class yuri_3032;

<<<<<<< HEAD
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
=======
// void Cube::addBox(float x0, float y0, float z0, int w, int h, int d, float g)
Cube::Cube(ModelPart* modelPart, int xTexOffs, int yTexOffs, float x0, float y0,
           float z0, int w, int h, int d, float g, int faceMask /* = 63 */,
           bool bFlipPoly3UVs)
    :  // 4J - added faceMask, added bFlipPoly3UVs to reverse the uvs back so
       // player skins display right
      x0(x0),
      y0(y0),
      z0(z0),
      x1(x0 + w),
      y1(y0 + h),
      z1(z0 + d),
      vertices({Vertex{0, 0, 0, 0, 0}, Vertex{0, 0, 0, 0, 0},
                Vertex{0, 0, 0, 0, 0}, Vertex{0, 0, 0, 0, 0},
                Vertex{0, 0, 0, 0, 0}, Vertex{0, 0, 0, 0, 0},
                Vertex{0, 0, 0, 0, 0}, Vertex{0, 0, 0, 0, 0}}),
      polygons({}) {
    float x1 = x0 + w;
    float y1 = y0 + h;
    float z1 = z0 + d;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

    // 4J - added ability to mask individual faces
    faceCount = 0;
    if (faceMask & 1)
<<<<<<< HEAD
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
=======
        polygons[faceCount++] = _Polygon(
            std::array<const Vertex, 4>{l1, u1, u2, l2}, xTexOffs + d + w,
            yTexOffs + d, xTexOffs + d + w + d, yTexOffs + d + h,
            modelPart->xTexSize, modelPart->yTexSize);  // Right
    if (faceMask & 2)
        polygons[faceCount++] = _Polygon(
            std::array<const Vertex, 4>{u0, l0, l3, u3}, xTexOffs + 0,
            yTexOffs + d, xTexOffs + d, yTexOffs + d + h, modelPart->xTexSize,
            modelPart->yTexSize);  // Left
    if (faceMask & 4)
        polygons[faceCount++] = _Polygon(
            std::array<const Vertex, 4>{l1, l0, u0, u1}, xTexOffs + d,
            yTexOffs + 0, xTexOffs + d + w, yTexOffs + d, modelPart->xTexSize,
            modelPart->yTexSize);  // Up
    if (bFlipPoly3UVs) {
        if (faceMask & 8)
            polygons[faceCount++] = _Polygon(
                std::array<const Vertex, 4>{u2, u3, l3, l2}, xTexOffs + d + w,
                yTexOffs + 0, xTexOffs + d + w + w, yTexOffs + d,
                modelPart->xTexSize, modelPart->yTexSize);  // Down
    } else {
        if (faceMask & 8)
            polygons[faceCount++] = _Polygon(
                std::array<const Vertex, 4>{u2, u3, l3, l2}, xTexOffs + d + w,
                yTexOffs + d, xTexOffs + d + w + w, yTexOffs + 0,
                modelPart->xTexSize, modelPart->yTexSize);  // Down
    }
    if (faceMask & 16)
        polygons[faceCount++] =
            _Polygon(std::array<const Vertex, 4>{u1, u0, u3, u2}, xTexOffs + d,
                     yTexOffs + d, xTexOffs + d + w, yTexOffs + d + h,
                     modelPart->xTexSize, modelPart->yTexSize);  // Front
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (faceMask & 32)
        yuri_7858[faceCount++] = yuri_3461(
            std::yuri_3742<const yuri_3324, 4>{l0, l1, l2, l3}, xTexOffs + d + yuri_9535 + d,
            yTexOffs + d, xTexOffs + d + yuri_9535 + d + yuri_9535, yTexOffs + d + yuri_6412,
            modelPart->xTexSize,
            modelPart->yTexSize);  // Back

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
