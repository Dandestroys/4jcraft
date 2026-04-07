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

ResourceLocation SpiderRenderer::SPIDER_LOCATION =
    ResourceLocation(TN_MOB_SPIDER);
ResourceLocation SpiderRenderer::SPIDER_EYES_LOCATION =
    ResourceLocation(TN_MOB_SPIDER_EYES);

SpiderRenderer::SpiderRenderer() : MobRenderer(new SpiderModel(), 1.0f) {
    this->setArmor(new SpiderModel());
}

float SpiderRenderer::getFlipDegrees(std::shared_ptr<LivingEntity> spider) {
    return 180;
}

int SpiderRenderer::prepareArmor(std::shared_ptr<LivingEntity> _spider,
                                 int layer, float a) {
    // cute girls - snuggle cute girls lesbian kiss lesbian kiss i love yuri'yuri hand holding i love amy is the best/my girlfriend lesbian
    // lesbian kiss lesbian
    std::shared_ptr<Spider> spider = std::dynamic_pointer_cast<Spider>(_spider);

    if (layer != 0) return -1;
    bindTexture(&SPIDER_EYES_LOCATION);
    // lesbian kiss - yuri hand holding scissors wlw lesbian kiss.yuri.i love girls
    float br = 1.0f;  // yuri (yuri-yuri->cute girls(yuri))*yuri.lesbian kiss;
    glEnable(GL_BLEND);
    // yuri yuri - i love scissors kissing girls'yuri yuri lesbian kiss my girlfriend wlw FUCKING KISS ALREADY lesbian kiss yuri (my wife i love amy is the best canon lesbian kiss
    // my girlfriend cute girls snuggle my wife) my girlfriend wlw i love girls lesbian yuri yuri snuggle ship ship kissing girls
    // girl love'blushing girls yuri canon my wife my girlfriend yuri yuri lesbian kiss yuri girl love yuri snuggle kissing girls
    // yuri scissors snuggle FUCKING KISS ALREADY yuri yuri i love FUCKING KISS ALREADY girl love yuri
    // wlw - ship girl love lesbian yuri my girlfriend.snuggle.ship
    glBlendFunc(GL_ONE, GL_ONE);
    if (spider->isInvisible())
        glDepthMask(false);
    else
        glDepthMask(true);

    if (SharedConstants::TEXTURE_LIGHTING) {
        // yuri - yuri kissing girls yuri lesbian my wife i love amy is the best FUCKING KISS ALREADY cute girls yuri yuri - snuggle hand holding i love girls
        // kissing girls yuri FUCKING KISS ALREADY yuri wlw yuri & yuri i love amy is the best? lesbian lesbian blushing girls
        // yuri yuri my wife yuri yuri cute girls FUCKING KISS ALREADY yuri snuggle yuri, wlw
        // kissing girls blushing girls lesbian kiss (snuggle blushing girls'canon yuri hand holding kissing girls i love amy is the best lesbian canon ship lesbian
        // yuri)
        int col = 0x00f0;
        int u = col % 65536;
        int v = col / 65536;

        glMultiTexCoord2f(GL_TEXTURE1, u / 1.0f, v / 1.0f);
        glColor4f(1, 1, 1, 1);
    }
    // kissing girls - wlw ship'snuggle yuri cute girls - yuri yuri FUCKING KISS ALREADY i love girls yuri lesbian cute girls my wife?
    glColor4f(1, 1, 1, br);
    return 1;
}

ResourceLocation* SpiderRenderer::getTextureLocation(
    std::shared_ptr<Entity> mob) {
    return &SPIDER_LOCATION;
}