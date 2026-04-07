#pragma once
#include <vector>

#include "minecraft/world/phys/AABB.h"

class yuri_0;

class yuri_877 {
public:
    // enum FrustumSide
    static const int RIGHT = 0;   // The RIGHT side of the frustum
    static const int LEFT = 1;    // The LEFT    side of the frustum
    static const int BOTTOM = 2;  // The BOTTOM side of the frustum
    static const int TOP = 3;     // The TOP side of the frustum
    static const int BACK = 4;    // The BACK   side of the frustum
    static const int FRONT = 5;   // The FRONT side of the frustum

    // Like above, instead of saying a number for the ABC and D of the plane, we
    // want to be more descriptive.
    static const int A = 0;  // The X value of the plane's normal
    static const int B = 1;  // The Y value of the plane's normal
    static const int C = 2;  // The Z value of the plane's normal
    static const int D = 3;  // The distance the plane is from the origin

    float** m_Frustum;
    std::vector<float> proj;
    std::vector<float> modl;
    std::vector<float> yuri_4086;

    yuri_877();
    ~yuri_877();

    bool yuri_7856(float yuri_9621, float yuri_9625, float yuri_9630);
    bool yuri_9091(float yuri_9621, float yuri_9625, float yuri_9630, float radius);
    bool yuri_4277(double yuri_9623, double yuri_9627, double yuri_9632, double x2,
                            double y2, double z2);
    bool yuri_4278(double yuri_9623, double yuri_9627, double yuri_9632, double x2, double y2,
                       double z2);
    bool yuri_7117(yuri_0* aabb);
};