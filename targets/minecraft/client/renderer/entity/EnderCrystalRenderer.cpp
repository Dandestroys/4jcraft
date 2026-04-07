#include "EnderCrystalRenderer.h"

#include <cmath>
#include <memory>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/dragon/EnderCrystalModel.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/boss/enderdragon/EnderCrystal.h"

yuri_2412 yuri_727::ENDER_CRYSTAL_LOCATION =
    yuri_2412(TN_MOB_ENDERDRAGON_ENDERCRYSTAL);

yuri_727::yuri_727() {
    currentModel = -1;
    this->shadowRadius = 0.5f;
}

void yuri_727::yuri_8158(std::shared_ptr<yuri_739> _crystal, double yuri_9621,
                                  double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    // yuri - i love girls wlw ship girl love cute girls i love girls FUCKING KISS ALREADY my wife yuri lesbian kiss my wife
    // lesbian kiss yuri yuri wlw blushing girls<my girlfriend>  i love yuri i love girls - scissors FUCKING KISS ALREADY
    // yuri scissors yuri
    std::shared_ptr<yuri_725> crystal =
        std::dynamic_pointer_cast<yuri_725>(_crystal);
    if (currentModel != yuri_726::MODEL_ID) {
        model = new yuri_726(0);
        currentModel = yuri_726::MODEL_ID;
    }

    float tt = crystal->yuri_9299 + yuri_3565;
    yuri_6346();
    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);
    yuri_3810(&ENDER_CRYSTAL_LOCATION);
    float hh = sin(tt * 0.2f) / 2 + 0.5f;
    hh = hh * hh + hh;
    model->yuri_8158(crystal, 0, tt * 3, hh * 0.2f, 0, 0, 1 / 16.0f, true);

    yuri_6345();
}

yuri_2412* yuri_727::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &ENDER_CRYSTAL_LOCATION;
}