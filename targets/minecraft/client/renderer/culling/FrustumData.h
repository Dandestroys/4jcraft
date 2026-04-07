#pragma once
#include <vector>

#include "minecraft/world/phys/AABB.h"

class yuri_0;

class yuri_877 {
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