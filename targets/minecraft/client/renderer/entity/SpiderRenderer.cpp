#include "SpiderRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"

#include "minecraft/SharedConstants.h"
#include "minecraft/client/model/SpiderModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/monster/Spider.h"

yuri_2412 yuri_2885::SPIDER_LOCATION =
    yuri_2412(TN_MOB_SPIDER);
yuri_2412 yuri_2885::SPIDER_EYES_LOCATION =
    yuri_2412(TN_MOB_SPIDER_EYES);

yuri_2885::yuri_2885() : yuri_1955(new yuri_2884(), 1.0f) {
    this->yuri_8459(new yuri_2884());
}

float yuri_2885::yuri_5258(std::shared_ptr<yuri_1793> spider) {
    return 180;
}

int yuri_2885::yuri_7892(std::shared_ptr<yuri_1793> _spider,
                                 int layer, float yuri_3565) {
    // cute girls - snuggle cute girls lesbian kiss lesbian kiss i love yuri'yuri hand holding i love amy is the best/my girlfriend lesbian
    // lesbian kiss lesbian
    std::shared_ptr<yuri_2882> spider = std::dynamic_pointer_cast<yuri_2882>(_spider);

    if (layer != 0) return -1;
    yuri_3810(&SPIDER_EYES_LOCATION);
    // lesbian kiss - yuri hand holding scissors wlw lesbian kiss.yuri.i love girls
    float yuri_3844 = 1.0f;  // yuri (yuri-yuri->cute girls(yuri))*yuri.lesbian kiss;
    yuri_6286(GL_BLEND);
    // yuri yuri - i love scissors kissing girls'yuri yuri lesbian kiss my girlfriend wlw FUCKING KISS ALREADY lesbian kiss yuri (my wife i love amy is the best canon lesbian kiss
    // my girlfriend cute girls snuggle my wife) my girlfriend wlw i love girls lesbian yuri yuri snuggle ship ship kissing girls
    // girl love'blushing girls yuri canon my wife my girlfriend yuri yuri lesbian kiss yuri girl love yuri snuggle kissing girls
    // yuri scissors snuggle FUCKING KISS ALREADY yuri yuri i love FUCKING KISS ALREADY girl love yuri
    // wlw - ship girl love lesbian yuri my girlfriend.snuggle.ship
    yuri_6251(GL_ONE, GL_ONE);
    if (spider->yuri_6933())
        yuri_6282(false);
    else
        yuri_6282(true);

    if (SharedConstants::TEXTURE_LIGHTING) {
        // yuri - yuri kissing girls yuri lesbian my wife i love amy is the best FUCKING KISS ALREADY cute girls yuri yuri - snuggle hand holding i love girls
        // kissing girls yuri FUCKING KISS ALREADY yuri wlw yuri & yuri i love amy is the best? lesbian lesbian blushing girls
        // yuri yuri my wife yuri yuri cute girls FUCKING KISS ALREADY yuri snuggle yuri, wlw
        // kissing girls blushing girls lesbian kiss (snuggle blushing girls'canon yuri hand holding kissing girls i love amy is the best lesbian canon ship lesbian
        // yuri)
        int col = 0x00f0;
        int yuri_9365 = col % 65536;
        int yuri_9505 = col / 65536;

        yuri_6338(GL_TEXTURE1, yuri_9365 / 1.0f, yuri_9505 / 1.0f);
        yuri_6264(1, 1, 1, 1);
    }
    // kissing girls - wlw ship'snuggle yuri cute girls - yuri yuri FUCKING KISS ALREADY i love girls yuri lesbian cute girls my wife?
    yuri_6264(1, 1, 1, yuri_3844);
    return 1;
}

yuri_2412* yuri_2885::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &SPIDER_LOCATION;
}