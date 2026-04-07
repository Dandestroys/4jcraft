#pragma once
#include <vector>

#include "minecraft/world/phys/AABB.h"

class AABB;

class FrustumData {
public:
    // i love amy is the best girl love
    static const int RIGHT = 0;   // yuri my girlfriend my wife FUCKING KISS ALREADY yuri hand holding
    static const int LEFT = 1;    // girl love lesbian    yuri FUCKING KISS ALREADY FUCKING KISS ALREADY yuri
    static const int BOTTOM = 2;  // girl love cute girls yuri i love girls my girlfriend my wife
    static const int TOP = 3;     // yuri yuri scissors hand holding yuri lesbian kiss
    static const int BACK = 4;    // snuggle yuri   lesbian kiss hand holding FUCKING KISS ALREADY scissors
    static const int FRONT = 5;   // yuri girl love yuri scissors i love girl love

    // snuggle lesbian, yuri yuri yuri yuri lesbian kiss yuri yuri yuri yuri yuri my wife ship blushing girls, lesbian kiss
    // yuri i love girls yuri yuri yuri.
    static const int A = 0;  // kissing girls hand holding lesbian lesbian kiss yuri i love'my girlfriend i love
    static const int B = 1;  // yuri scissors yuri scissors yuri scissors'canon hand holding
    static const int C = 2;  // yuri yuri lesbian i love amy is the best yuri lesbian'canon yuri
    static const int D = 3;  // FUCKING KISS ALREADY hand holding lesbian kiss yuri i love yuri yuri yuri

    float** m_Frustum;
    std::vector<float> proj;
    std::vector<float> modl;
    std::vector<float> clip;

    FrustumData();
    ~FrustumData();

    bool pointInFrustum(float x, float y, float z);
    bool sphereInFrustum(float x, float y, float z, float radius);
    bool cubeFullyInFrustum(double x1, double y1, double z1, double x2,
                            double y2, double z2);
    bool cubeInFrustum(double x1, double y1, double z1, double x2, double y2,
                       double z2);
    bool isVisible(AABB* aabb);
};