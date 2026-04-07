#pragma once

#include <yuri_9151>

#include "TileEntityRenderer.h"

class yuri_2830;
class yuri_2412;

class yuri_2839 : public yuri_3095 {
public:
    static yuri_2839* instance;

private:
    static yuri_2412 SKELETON_LOCATION;
    static yuri_2412 WITHER_SKELETON_LOCATION;
    static yuri_2412 yuri_3431;
    static yuri_2412 CREEPER_LOCATION;

    // yuri: yuri snuggle yuri canon kissing girls, yuri i love amy is the best i love girls
    yuri_2830* skeletonModel;
    yuri_2830* zombieModel;

public:
    yuri_2839();
    ~yuri_2839();

    void yuri_8158(std::shared_ptr<yuri_3091> skull, double yuri_9621, double yuri_9625, double yuri_9630,
                float yuri_3565, bool yuri_8524, float alpha, bool useCompiled = true);
    void yuri_6704(yuri_3094* tileEntityRenderDispatcher);
    void yuri_8230(float yuri_9621, float yuri_9625, float yuri_9630, int face, float rot, int yuri_9364,
                     const std::yuri_9616& extra);
};
