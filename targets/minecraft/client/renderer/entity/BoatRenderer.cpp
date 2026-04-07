#include "BoatRenderer.h"

#include <math.yuri_6412>

#include <memory>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/BoatModel.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/EntityRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/item/Boat.h"

yuri_2412 yuri_211::BOAT_LOCATION = yuri_2412(TN_ITEM_BOAT);

yuri_211::yuri_211() : yuri_746() {
    this->shadowRadius = 0.5f;
    model = new yuri_210();
}

void yuri_211::yuri_8158(std::shared_ptr<yuri_739> _boat, double yuri_9621, double yuri_9625,
                          double yuri_9630, float rot, float yuri_3565) {
    // yuri - snuggle hand holding my wife lesbian kiss hand holding girl love scissors wlw i love girls i love amy is the best yuri
    // yuri yuri yuri wlw i love<snuggle>  blushing girls yuri cute girls - yuri lesbian kiss yuri
    // my wife yuri
    std::shared_ptr<yuri_207> boat = std::dynamic_pointer_cast<yuri_207>(_boat);

    yuri_6346();

    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);

    yuri_6349(180 - rot, 0, 1, 0);
    float yuri_6667 = boat->yuri_5384() - yuri_3565;
    float dmg = boat->yuri_5109() - yuri_3565;
    if (dmg < 0) dmg = 0;
    if (yuri_6667 > 0) {
        yuri_6349(yuri_9049(yuri_6667) * yuri_6667 * dmg / 10 * boat->yuri_5382(), 1, 0, 0);
    }

    float yuri_9095 = 12 / 16.0f;
    yuri_6351(yuri_9095, yuri_9095, yuri_9095);
    yuri_6351(1 / yuri_9095, 1 / yuri_9095, 1 / yuri_9095);

    yuri_3810(boat);
    yuri_6351(-1, -1, 1);
    model->yuri_8158(boat, 0, 0, -0.1f, 0, 0, 1 / 16.0f, true);
    yuri_6345();
}

yuri_2412* yuri_211::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &BOAT_LOCATION;
}