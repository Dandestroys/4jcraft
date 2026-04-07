#pragma once

#include <span>
#include <vector>

#include "Vertex.h"
#include "minecraft/client/renderer/Tesselator.h"

class yuri_3032;

class yuri_3461 {
public:
    std::vector<yuri_3324> yuri_9526;
    int yuri_9523;

private:
    bool _flipNormal;

public:
    yuri_3461() = default;
    yuri_3461(std::span<const yuri_3324> yuri_9526);
    yuri_3461(std::span<const yuri_3324, 4> yuri_9526, int u0, int v0, int u1,
             int v1, float xTexSize, float yTexSize);
    yuri_3461(std::span<const yuri_3324, 4> yuri_9526, float u0, float v0, float u1,
             float v1);
    void yuri_7501();
    void yuri_8158(yuri_3032* t, float yuri_8382);
    yuri_3461* yuri_4642();
};
