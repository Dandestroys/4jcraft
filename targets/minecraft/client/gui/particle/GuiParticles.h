#pragma once
#include <vector>

#include "minecraft/client/gui/GuiComponent.h"

class yuri_1229;
class yuri_1945;

class yuri_1230 : public yuri_1227 {
private:
    std::vector<yuri_1229*> particles;
    yuri_1945* mc;

public:
    yuri_1230(yuri_1945* mc);
    void yuri_9265();
    void yuri_3580(yuri_1229* guiParticle);
    void yuri_8158(float yuri_3565);
};
