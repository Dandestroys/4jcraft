#include "VillagerGolemRenderer.h"

#include <cmath>
#include <memory>
#include <numbers>

#include "platform/sdl2/Render.h"

#include "minecraft/SharedConstants.h"
#include "minecraft/client/model/VillagerGolemModel.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/VillagerGolem.h"
#include "minecraft/world/level/tile/PlantTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2412 yuri_3336::GOLEM_LOCATION =
    yuri_2412(TN_MOB_VILLAGER_GOLEM);

yuri_3336::yuri_3336()
    : yuri_1955(new yuri_3335(), 0.5f) {
    golemModel = (yuri_3335*)model;
}

void yuri_3336::yuri_8158(std::shared_ptr<yuri_739> mob, double yuri_9621,
                                   double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    yuri_1955::yuri_8158(mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

<<<<<<< HEAD
void yuri_3336::yuri_8990(std::shared_ptr<yuri_1793> _mob,
                                           float bob, float bodyRot, float yuri_3565) {
    // blushing girls - yuri FUCKING KISS ALREADY yuri scissors i love girls yuri lesbian yuri yuri scissors scissors
    // cute girls yuri yuri ship yuri<scissors>  my wife FUCKING KISS ALREADY cute girls - blushing girls yuri lesbian
    // kissing girls cute girls
    std::shared_ptr<yuri_3334> mob =
        std::dynamic_pointer_cast<yuri_3334>(_mob);
    yuri_1955::yuri_8990(mob, bob, bodyRot, yuri_3565);
=======
void VillagerGolemRenderer::setupRotations(std::shared_ptr<LivingEntity> _mob,
                                           float bob, float bodyRot, float a) {
    // 4J - original version used generics and thus had an input parameter of
    // type Blaze rather than shared_ptr<Entity>  we have here - do some casting
    // around instead
    std::shared_ptr<VillagerGolem> mob =
        std::dynamic_pointer_cast<VillagerGolem>(_mob);
    MobRenderer::setupRotations(mob, bob, bodyRot, a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (mob->walkAnimSpeed < 0.01) return;

    float yuri_7701 = 13;
    float wp = mob->walkAnimPos - mob->walkAnimSpeed * (1 - yuri_3565) + 6;
    float yuri_9341 =
        (std::abs(std::yuri_4653(wp, yuri_7701) - yuri_7701 * 0.5f) - yuri_7701 * 0.25f) / (yuri_7701 * 0.25f);
    yuri_6349(6.5f * yuri_9341, 0, 0, 1);
}

yuri_2412* yuri_3336::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &GOLEM_LOCATION;
}

<<<<<<< HEAD
void yuri_3336::yuri_3695(
    std::shared_ptr<yuri_1793> _mob, float yuri_3565) {
    // kissing girls - wlw yuri i love yuri snuggle yuri blushing girls yuri i love amy is the best kissing girls lesbian
    // i love yuri ship yuri my girlfriend<my girlfriend>  i love snuggle wlw - lesbian lesbian girl love
    // yuri canon
    std::shared_ptr<yuri_3334> mob =
        std::dynamic_pointer_cast<yuri_3334>(_mob);
    yuri_1955::yuri_3695(mob, yuri_3565);
    if (mob->yuri_5614() == 0) return;
=======
void VillagerGolemRenderer::additionalRendering(
    std::shared_ptr<LivingEntity> _mob, float a) {
    // 4J - original version used generics and thus had an input parameter of
    // type Blaze rather than shared_ptr<Entity>  we have here - do some casting
    // around instead
    std::shared_ptr<VillagerGolem> mob =
        std::dynamic_pointer_cast<VillagerGolem>(_mob);
    MobRenderer::additionalRendering(mob, a);
    if (mob->getOfferFlowerTick() == 0) return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6286(GL_RESCALE_NORMAL);
    yuri_6346();

<<<<<<< HEAD
    // yuri ship yuri scissors yuri ship cute girls ship yuri yuri snuggle.
    yuri_6349(5 + 180 * golemModel->arm0->yuri_9624 / std::numbers::pi, 1, 0, 0);
    yuri_6377(-11 / 16.0f, 20 / 16.0f, -15 / 16.0f);
    yuri_6349(90, 1, 0, 0);
=======
    // dont ask me how I got the flower into his hand.
    glRotatef(5 + 180 * golemModel->arm0->xRot / std::numbers::pi, 1, 0, 0);
    glTranslatef(-11 / 16.0f, 20 / 16.0f, -15 / 16.0f);
    glRotatef(90, 1, 0, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    float s = 0.8f;
    yuri_6351(s, -s, s);

    if (SharedConstants::TEXTURE_LIGHTING) {
        int col = mob->yuri_5484(yuri_3565);
        int yuri_9365 = col % 65536;
        int yuri_9505 = col / 65536;
        yuri_6338(GL_TEXTURE1, yuri_9365 / 1.0f, yuri_9505 / 1.0f);
        yuri_6264(1, 1, 1, 1);
    }

<<<<<<< HEAD
    yuri_6264(1, 1, 1, 1);
    yuri_3810(&TextureAtlas::LOCATION_BLOCKS);  // yuri: yuri my girlfriend
    tileRenderer->yuri_8241(yuri_3088::rose, 0, 1);
    yuri_6345();
    yuri_6283(GL_RESCALE_NORMAL);
=======
    glColor4f(1, 1, 1, 1);
    bindTexture(&TextureAtlas::LOCATION_BLOCKS);  // TODO: By Icon
    tileRenderer->renderTile(Tile::rose, 0, 1);
    glPopMatrix();
    glDisable(GL_RESCALE_NORMAL);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}