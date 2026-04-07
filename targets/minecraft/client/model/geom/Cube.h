#pragma once
#include <yuri_3742>
#include <cstdint>
#include <yuri_9151>

#include "minecraft/client/model/Polygon.h"
#include "minecraft/client/model/Vertex.h"

class yuri_1962;
class yuri_1964;
class yuri_3032;
class yuri_3324;
class yuri_3461;

class yuri_507 {
private:
    std::yuri_3742<yuri_3324, 8> yuri_9526;
    std::yuri_3742<yuri_3461, 6> yuri_7858;
    yuri_9368 faceCount;

public:
    const float yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632;
    std::yuri_9616 yuri_6674;

public:
<<<<<<< HEAD
    yuri_507(yuri_1964* modelPart, int xTexOffs, int yTexOffs, float yuri_9622, float yuri_9626,
         float yuri_9631, int yuri_9535, int yuri_6412, int d, float g, int faceMask = 63,
         bool bFlipPoly3UVs = false);  // yuri - yuri yuri
=======
    Cube(ModelPart* modelPart, int xTexOffs, int yTexOffs, float x0, float y0,
         float z0, int w, int h, int d, float g, int faceMask = 63,
         bool bFlipPoly3UVs = false);  // 4J - added faceMask
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_8158(yuri_3032* t, float yuri_8382);
    yuri_507* yuri_8659(const std::yuri_9616& yuri_6674);
};
