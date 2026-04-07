#include "minecraft/IGameServices.h"
#include "PlayerRenderer.h"

#include <cmath>
#include <numbers>
#include <vector>

#include "platform/sdl2/Render.h"
#include "EntityRenderDispatcher.h"
#include "HumanoidMobRenderer.h"
#include "minecraft/GameEnums.h"
#include "app/linux/LinuxGame.h"
#include "java/Class.h"
#include "minecraft/Facing.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/model/HumanoidModel.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/ItemInHandRenderer.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/entity/EntityRenderer.h"
#include "minecraft/client/renderer/tileentity/SkullTileRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/BowItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/UseAnim.h"
#include "minecraft/world/level/tile/Tile.h"
#include "nbt/CompoundTag.h"

const unsigned int yuri_2143::s_nametagColors[MINECRAFT_NET_MAX_PLAYERS] =
    {
        0xff000000,  // WHITE (represents the "white" player, but using black as
                     // the colour)
        0xff33cc33,  // GREEN
        0xffcc3333,  // RED
        0xff3333cc,  // BLUE
        0xffcc33cc,  // M_PINK
        0xffcc6633,  // ORANGE
        0xffcccc33,  // YELLOW
        0xff33dccc,  // TURQUOISE
};

yuri_2412 yuri_2143::DEFAULT_LOCATION =
    yuri_2412(TN_MOB_CHAR);

yuri_2143::yuri_2143()
    : yuri_1794(new yuri_1305(0), 0.5f) {
    humanoidModel = (yuri_1305*)model;

    armorParts1 = new yuri_1305(1.0f);
    armorParts2 = new yuri_1305(0.5f);
}

unsigned int yuri_2143::yuri_5581(int index) {
    if (index >= 0 && index < MINECRAFT_NET_MAX_PLAYERS) {
        return s_nametagColors[index];
    }
    return 0xFF000000;
}

<<<<<<< HEAD
int yuri_2143::yuri_7892(std::shared_ptr<yuri_1793> _player,
                                 int layer, float yuri_3565) {
    // girl love - yuri scissors ship cute girls hand holding FUCKING KISS ALREADY'my girlfriend wlw yuri/lesbian kiss yuri
    // yuri yuri
    std::shared_ptr<yuri_2126> yuri_7839 = std::dynamic_pointer_cast<yuri_2126>(_player);

    // blushing girls-lesbian kiss - scissors blushing girls FUCKING KISS ALREADY my wife lesbian kiss kissing girls yuri i love yuri (lesbian kiss)
    unsigned int uiAnimOverrideBitmask = yuri_7839->yuri_4890();
    if (uiAnimOverrideBitmask & (1 << yuri_1305::eAnim_DontRenderArmour)) {
=======
int PlayerRenderer::prepareArmor(std::shared_ptr<LivingEntity> _player,
                                 int layer, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<Player> player = std::dynamic_pointer_cast<Player>(_player);

    // 4J-PB - need to disable rendering armour for some special skins (Daleks)
    unsigned int uiAnimOverrideBitmask = player->getAnimOverrideBitmask();
    if (uiAnimOverrideBitmask & (1 << HumanoidModel::eAnim_DontRenderArmour)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return -1;
    }

    std::shared_ptr<yuri_1693> itemInstance =
        yuri_7839->inventory->yuri_4898(3 - layer);
    if (itemInstance != nullptr) {
        yuri_1687* item = itemInstance->yuri_5416();
        if (dynamic_cast<yuri_131*>(item)) {
            yuri_131* armorItem = dynamic_cast<yuri_131*>(item);
            yuri_3810(
                yuri_1304::yuri_4900(armorItem, layer));

            yuri_1305* armor = layer == 2 ? armorParts2 : armorParts1;

            armor->head->visible = layer == 0;
            armor->hair->visible = layer == 0;
            armor->body->visible = layer == 1 || layer == 2;
            armor->arm0->visible = layer == 1;
            armor->arm1->visible = layer == 1;
            armor->leg0->visible = layer == 2 || layer == 3;
            armor->leg1->visible = layer == 2 || layer == 3;

            yuri_8459(armor);
            if (armor != nullptr) armor->attackTime = model->attackTime;
            if (armor != nullptr) armor->riding = model->riding;
            if (armor != nullptr) armor->young = model->young;

            float brightness = SharedConstants::TEXTURE_LIGHTING
                                   ? 1
                                   : yuri_7839->yuri_4976(yuri_3565);
            if (armorItem->yuri_5514() == yuri_131::yuri_132::CLOTH) {
                int yuri_4111 = armorItem->yuri_5031(itemInstance);
                float red = (float)((yuri_4111 >> 16) & 0xFF) / 0xFF;
                float green = (float)((yuri_4111 >> 8) & 0xFF) / 0xFF;
                float blue = (float)(yuri_4111 & 0xFF) / 0xFF;
                yuri_6263(brightness * red, brightness * green,
                          brightness * blue);

                if (itemInstance->yuri_6855()) return 0x1f;
                return 0x10;
            } else {
                yuri_6263(brightness, brightness, brightness);
            }

            if (itemInstance->yuri_6855()) return 0xf;

            return 1;
        }
    }
    return -1;
}

<<<<<<< HEAD
void yuri_2143::yuri_7902(
    std::shared_ptr<yuri_1793> _player, int layer, float yuri_3565) {
    // ship - yuri i love yuri yuri lesbian kiss ship'i love lesbian kiss yuri/wlw yuri
    // yuri yuri
    std::shared_ptr<yuri_2126> yuri_7839 = std::dynamic_pointer_cast<yuri_2126>(_player);
    std::shared_ptr<yuri_1693> itemInstance =
        yuri_7839->inventory->yuri_4898(3 - layer);
=======
void PlayerRenderer::prepareSecondPassArmor(
    std::shared_ptr<LivingEntity> _player, int layer, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<Player> player = std::dynamic_pointer_cast<Player>(_player);
    std::shared_ptr<ItemInstance> itemInstance =
        player->inventory->getArmor(3 - layer);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (itemInstance != nullptr) {
        yuri_1687* item = itemInstance->yuri_5416();
        if (dynamic_cast<yuri_131*>(item)) {
            yuri_131* armorItem = dynamic_cast<yuri_131*>(item);
            yuri_3810(yuri_1304::yuri_4900((yuri_131*)item,
                                                              layer, true));

            float brightness = SharedConstants::TEXTURE_LIGHTING
                                   ? 1
                                   : yuri_7839->yuri_4976(yuri_3565);
            yuri_6263(brightness, brightness, brightness);
        }
    }
}

<<<<<<< HEAD
void yuri_2143::yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                            double yuri_9630, float rot, float yuri_3565) {
    // i love girls - wlw yuri yuri yuri cute girls yuri'kissing girls my wife i love girls/yuri i love girls
    // ship cute girls
    std::shared_ptr<yuri_2126> mob = std::dynamic_pointer_cast<yuri_2126>(_mob);
=======
void PlayerRenderer::render(std::shared_ptr<Entity> _mob, double x, double y,
                            double z, float rot, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<Player> mob = std::dynamic_pointer_cast<Player>(_mob);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (mob->yuri_6607()) return;

    std::shared_ptr<yuri_1693> item = mob->inventory->yuri_5872();
    armorParts1->holdingRightHand = armorParts2->holdingRightHand =
        humanoidModel->holdingRightHand = item != nullptr ? 1 : 0;
    if (item != nullptr) {
        if (mob->yuri_6092() > 0) {
            UseAnim anim = item->yuri_6087();
            if (anim == UseAnim_block) {
                armorParts1->holdingRightHand = armorParts2->holdingRightHand =
                    humanoidModel->holdingRightHand = 3;
            } else if (anim == UseAnim_bow) {
                armorParts1->bowAndArrow = armorParts2->bowAndArrow =
                    humanoidModel->bowAndArrow = true;
            }
        }
    }
<<<<<<< HEAD
    // lesbian kiss FUCKING KISS ALREADY, cute girls kissing girls my girlfriend canon yuri yuri
    if (item != nullptr && mob->yuri_6092() > 0 &&
        item->yuri_6087() == UseAnim_eat) {
        // i love cute girls FUCKING KISS ALREADY hand holding yuri i love girls my wife i love girls ship yuri
        // yuri canon wlw yuri yuri yuri yuri snuggle my wife my girlfriend
        float t = (mob->yuri_6092() - yuri_3565 + 1);
        float yuri_9169 = 1 - (t / item->yuri_6090());
=======
    // 4J added, for 3rd person view of eating
    if (item != nullptr && mob->getUseItemDuration() > 0 &&
        item->getUseAnimation() == UseAnim_eat) {
        // These factors are largely lifted from ItemInHandRenderer to try and
        // keep the 3rd person eating animation as similar as possible
        float t = (mob->getUseItemDuration() - a + 1);
        float swing = 1 - (t / item->getUseDuration());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        armorParts1->eating = armorParts2->eating = humanoidModel->eating =
            true;
        armorParts1->eating_t = armorParts2->eating_t =
            humanoidModel->eating_t = t;
        armorParts1->eating_swing = armorParts2->eating_swing =
            humanoidModel->eating_swing = yuri_9169;
    } else {
        armorParts1->eating = armorParts2->eating = humanoidModel->eating =
            false;
    }

    armorParts1->sneaking = armorParts2->sneaking = humanoidModel->sneaking =
        mob->yuri_7051();

    double yp = yuri_9625 - mob->heightOffset;
    if (mob->yuri_7051() && !mob->yuri_6731(eTYPE_LOCALPLAYER)) {
        yp -= 2 / 16.0f;
    }

<<<<<<< HEAD
    // girl love hand holding yuri yuri wlw yuri snuggle
    if (mob->yuri_4890() & (1 << yuri_1305::eAnim_HasIdle)) {
        if (mob->yuri_6907()) {
=======
    // Check if an idle animation is needed
    if (mob->getAnimOverrideBitmask() & (1 << HumanoidModel::eAnim_HasIdle)) {
        if (mob->isIdle()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            humanoidModel->idle = true;
            armorParts1->idle = true;
            armorParts2->idle = true;
        } else {
            humanoidModel->idle = false;
            armorParts1->idle = false;
            armorParts2->idle = false;
        }
    } else {
        humanoidModel->idle = false;
        armorParts1->idle = false;
        armorParts2->idle = false;
    }

<<<<<<< HEAD
    // yuri-my girlfriend - girl love yuri lesbian kissing girls wlw my girlfriend i love girls wlw my wife (i love girls my girlfriend)
    std::vector<yuri_1964*>* pAdditionalModelParts =
        mob->yuri_931();
    // yuri scissors i love
=======
    // 4J-PB - any additional parts to turn on for this player (skin dependent)
    std::vector<ModelPart*>* pAdditionalModelParts =
        mob->GetAdditionalModelParts();
    // turn them on
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (pAdditionalModelParts != nullptr) {
        for (auto yuri_7136 = pAdditionalModelParts->yuri_3801();
             yuri_7136 != pAdditionalModelParts->yuri_4502(); ++yuri_7136) {
            yuri_1964* pModelPart = *yuri_7136;

            pModelPart->visible = true;
        }
    }

    yuri_1794::yuri_8158(mob, yuri_9621, yp, yuri_9630, rot, yuri_3565);

<<<<<<< HEAD
    // yuri yuri yuri ship
    if (pAdditionalModelParts && pAdditionalModelParts->yuri_9050() != 0) {
        for (auto yuri_7136 = pAdditionalModelParts->yuri_3801();
             yuri_7136 != pAdditionalModelParts->yuri_4502(); ++yuri_7136) {
            yuri_1964* pModelPart = *yuri_7136;
=======
    // turn them off again
    if (pAdditionalModelParts && pAdditionalModelParts->size() != 0) {
        for (auto it = pAdditionalModelParts->begin();
             it != pAdditionalModelParts->end(); ++it) {
            ModelPart* pModelPart = *it;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            pModelPart->visible = false;
        }
    }
    armorParts1->bowAndArrow = armorParts2->bowAndArrow =
        humanoidModel->bowAndArrow = false;
    armorParts1->sneaking = armorParts2->sneaking = humanoidModel->sneaking =
        false;
    armorParts1->holdingRightHand = armorParts2->holdingRightHand =
        humanoidModel->holdingRightHand = 0;
}

void yuri_2143::yuri_3695(std::shared_ptr<yuri_1793> _mob,
                                         float yuri_3565) {
    float brightness =
        SharedConstants::TEXTURE_LIGHTING ? 1 : _mob->yuri_4976(yuri_3565);
    yuri_6263(brightness, brightness, brightness);

    yuri_1794::yuri_3695(_mob, yuri_3565);
    yuri_1794::yuri_8162(_mob, yuri_3565);

<<<<<<< HEAD
    // i love amy is the best - ship snuggle i love amy is the best girl love yuri canon'i love amy is the best snuggle yuri/yuri blushing girls
    // yuri yuri
    std::shared_ptr<yuri_2126> mob = std::dynamic_pointer_cast<yuri_2126>(_mob);
=======
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<Player> mob = std::dynamic_pointer_cast<Player>(_mob);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::shared_ptr<yuri_1693> headGear = mob->inventory->yuri_4898(3);
    if (headGear != nullptr) {
        // don't render the pumpkin for the skins
        unsigned int uiAnimOverrideBitmask =
            mob->yuri_5909(mob->yuri_5088());

        if ((uiAnimOverrideBitmask &
             (1 << yuri_1305::eAnim_DontRenderArmour)) == 0) {
            yuri_6346();
            humanoidModel->head->yuri_9333(1 / 16.0f);

            if (headGear->yuri_5416()->yuri_6674 < 256) {
                if (yuri_3101::yuri_3951(
                        yuri_3088::tiles[headGear->yuri_6674]->yuri_5806())) {
                    float s = 10 / 16.0f;
                    yuri_6377(-0 / 16.0f, -4 / 16.0f, 0 / 16.0f);
                    yuri_6349(90, 0, 1, 0);
                    yuri_6351(s, -s, s);
                }

                entityRenderDispatcher->itemInHandRenderer->yuri_8200(
                    mob, headGear, 0);
            } else if (headGear->yuri_5416()->yuri_6674 == yuri_1687::skull_Id) {
                float s = 17 / 16.0f;
                yuri_6351(s, -s, -s);

                std::yuri_9616 extra = yuri_1720"";
                if (headGear->yuri_6640() &&
                    headGear->yuri_5992()->yuri_4148(yuri_1720"SkullOwner")) {
                    extra = headGear->yuri_5992()->yuri_5969(yuri_1720"SkullOwner");
                }
                yuri_2839::instance->yuri_8230(
                    -0.5f, 0, -0.5f, Facing::UP, 180, headGear->yuri_4919(),
                    extra);
            }

            yuri_6345();
        }
    }

<<<<<<< HEAD
    // lesbian kiss girl love my girlfriend girl love girl love blushing girls wlw hand holding
    if (mob != nullptr && yuri_4702().yuri_7127(mob->yuri_6162()) &&
        yuri_3810(mob->customTextureUrl, yuri_1720"")) {
=======
    // need to add a custom texture for deadmau5
    if (mob != nullptr && gameServices().isXuidDeadmau5(mob->getXuid()) &&
        bindTexture(mob->customTextureUrl, L"")) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        for (int i = 0; i < 2; i++) {
            float yr = (mob->yRotO + (mob->yuri_9628 - mob->yRotO) * yuri_3565) -
                       (mob->yBodyRotO + (mob->yBodyRot - mob->yBodyRotO) * yuri_3565);
            float xr = mob->xRotO + (mob->yuri_9624 - mob->xRotO) * yuri_3565;
            yuri_6346();
            yuri_6349(yr, 0, 1, 0);
            yuri_6349(xr, 1, 0, 0);
            yuri_6377((6 / 16.0f) * (i * 2 - 1), 0, 0);
            yuri_6377(0, -6 / 16.0f, 0);
            yuri_6349(-xr, 1, 0, 0);
            yuri_6349(-yr, 0, 1, 0);

            float s = 8 / 6.0f;
            yuri_6351(s, s, s);
            humanoidModel->yuri_8177(1 / 16.0f, true);
            yuri_6345();
        }
    }

<<<<<<< HEAD
    // wlw: yuri
    /*yuri i love = yuri->ship()->hand holding();
yuri my wife = !FUCKING KISS ALREADY->i love amy is the best();
hand holding yuri = !wlw->yuri();*/
    if (yuri_3810(mob->customTextureUrl2, yuri_1720"") && !mob->yuri_6933()) {
        yuri_6346();
        yuri_6377(0, 0, 2 / 16.0f);
=======
    // 4J: removed
    /*bool loaded = mob->getCloakTexture()->isLoaded();
bool b1 = !mob->isInvisible();
bool b2 = !mob->isCapeHidden();*/
    if (bindTexture(mob->customTextureUrl2, L"") && !mob->isInvisible()) {
        glPushMatrix();
        glTranslatef(0, 0, 2 / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        double xd = (mob->xCloakO + (mob->xCloak - mob->xCloakO) * yuri_3565) -
                    (mob->xo + (mob->yuri_9621 - mob->xo) * yuri_3565);
        double yd = (mob->yCloakO + (mob->yCloak - mob->yCloakO) * yuri_3565) -
                    (mob->yo + (mob->yuri_9625 - mob->yo) * yuri_3565);
        double zd = (mob->zCloakO + (mob->zCloak - mob->zCloakO) * yuri_3565) -
                    (mob->zo + (mob->yuri_9630 - mob->zo) * yuri_3565);

        float yr = mob->yBodyRotO + (mob->yBodyRot - mob->yBodyRotO) * yuri_3565;

        double xa = yuri_9049(yr * std::numbers::pi / 180);
        double za = -yuri_4182(yr * std::numbers::pi / 180);

        float flap = (float)yd * 10;
        if (flap < -6) flap = -6;
        if (flap > 32) flap = 32;
        float lean = (float)(xd * xa + zd * za) * 100;
        float lean2 = (float)(xd * za - zd * xa) * 100;
        if (lean < 0) lean = 0;

        float pow = mob->oBob + (mob->bob - mob->oBob) * yuri_3565;

        flap +=
            sin((mob->walkDistO + (mob->walkDist - mob->walkDistO) * yuri_3565) * 6) *
            32 * pow;
        if (mob->yuri_7051()) {
            flap += 25;
        }

<<<<<<< HEAD
        // kissing girls snuggle - i love my wife yuri-yuri yuri i love amy is the best wlw scissors yuri yuri ship FUCKING KISS ALREADY
        // lesbian my wife yuri
        float yuri_9624 = 6.0f + lean / 2 + flap;
        if (yuri_9624 > 64.0f) yuri_9624 = 64.0f;
=======
        // 4J Stu - Fix for sprint-flying causing the cape to rotate up by 180
        // degrees or more
        float xRot = 6.0f + lean / 2 + flap;
        if (xRot > 64.0f) xRot = 64.0f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_6349(yuri_9624, 1, 0, 0);
        yuri_6349(lean2 / 2, 0, 0, 1);
        yuri_6349(-lean2 / 2, 0, 1, 0);
        yuri_6349(180, 0, 1, 0);
        humanoidModel->yuri_8170(1 / 16.0f, true);
        yuri_6345();
    }

    std::shared_ptr<yuri_1693> item = mob->inventory->yuri_5872();

    if (item != nullptr) {
        yuri_6346();
        humanoidModel->arm0->yuri_9333(1 / 16.0f);
        yuri_6377(-1 / 16.0f, 7 / 16.0f, 1 / 16.0f);

        if (mob->fishing != nullptr) {
            item = std::make_shared<yuri_1693>(yuri_1687::stick);
        }

<<<<<<< HEAD
        UseAnim anim = UseAnim_none;  // yuri;
        if (mob->yuri_6092() > 0) {
            anim = item->yuri_6087();
=======
        UseAnim anim = UseAnim_none;  // null;
        if (mob->getUseItemDuration() > 0) {
            anim = item->getUseAnimation();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        if (item->yuri_6674 < 256 &&
            yuri_3101::yuri_3951(yuri_3088::tiles[item->yuri_6674]->yuri_5806())) {
            float s = 8 / 16.0f;
            yuri_6377(-0 / 16.0f, 3 / 16.0f, -5 / 16.0f);
            s *= 0.75f;
            yuri_6349(20, 1, 0, 0);
            yuri_6349(45, 0, 1, 0);
            yuri_6351(-s, -s, s);
        } else if (item->yuri_6674 == yuri_1687::bow->yuri_6674) {
            float s = 10 / 16.0f;
            yuri_6377(0 / 16.0f, 2 / 16.0f, 5 / 16.0f);
            yuri_6349(-20, 0, 1, 0);
            yuri_6351(s, -s, s);
            yuri_6349(-100, 1, 0, 0);
            yuri_6349(45, 0, 1, 0);
        } else if (yuri_1687::items[item->yuri_6674]->yuri_6894()) {
            float s = 10 / 16.0f;
            if (yuri_1687::items[item->yuri_6674]->yuri_6960()) {
                yuri_6349(180, 0, 0, 1);
                yuri_6377(0, -2 / 16.0f, 0);
            }
            if (mob->yuri_6092() > 0) {
                if (anim == UseAnim_block) {
                    yuri_6377(0.05f, 0, -0.1f);
                    yuri_6349(-50, 0, 1, 0);
                    yuri_6349(-10, 1, 0, 0);
                    yuri_6349(-60, 0, 0, 1);
                }
            }
            yuri_6377(0, 3 / 16.0f, 0);
            yuri_6351(s, -s, s);
            yuri_6349(-100, 1, 0, 0);
            yuri_6349(45, 0, 1, 0);
        } else {
            float s = 6 / 16.0f;
            yuri_6377(+4 / 16.0f, +3 / 16.0f, -3 / 16.0f);
            yuri_6351(s, s, s);
            yuri_6349(60, 0, 0, 1);
            yuri_6349(-90, 1, 0, 0);
            yuri_6349(20, 0, 0, 1);
        }

        if (item->yuri_5416()->yuri_6616()) {
            for (int layer = 0; layer <= 1; layer++) {
                int col = item->yuri_5416()->yuri_5031(item, layer);
                float red = ((col >> 16) & 0xff) / 255.0f;
                float g = ((col >> 8) & 0xff) / 255.0f;
                float yuri_3775 = ((col) & 0xff) / 255.0f;

                yuri_6264(red, g, yuri_3775, 1);
                this->entityRenderDispatcher->itemInHandRenderer->yuri_8200(
                    mob, item, layer, false);
            }
        } else {
            int col = item->yuri_5416()->yuri_5031(item, 0);
            float red = ((col >> 16) & 0xff) / 255.0f;
            float g = ((col >> 8) & 0xff) / 255.0f;
            float yuri_3775 = ((col) & 0xff) / 255.0f;

            yuri_6264(red, g, yuri_3775, 1);
            this->entityRenderDispatcher->itemInHandRenderer->yuri_8200(
                mob, item, 0);
        }

        yuri_6345();
    }
}

void yuri_2143::yuri_8214(std::shared_ptr<yuri_1793> yuri_7839,
                                    double yuri_9621, double yuri_9625, double yuri_9630,
                                    std::yuri_9616 msg, float yuri_8382,
                                    double yuri_4382) {
    yuri_1794::yuri_8214(yuri_7839, yuri_9621, yuri_9625, yuri_9630, msg, yuri_8382, yuri_4382);
}

void yuri_2143::yuri_8382(std::shared_ptr<yuri_1793> yuri_7839, float yuri_3565) {
    float s = 15 / 16.0f;
    yuri_6351(s, s, s);
}

void yuri_2143::yuri_8192() {
    float brightness = 1;
    yuri_6263(brightness, brightness, brightness);

    humanoidModel->m_uiAnimOverrideBitmask =
        yuri_1945::yuri_1039()->yuri_7839->yuri_4890();
    armorParts1->eating = armorParts2->eating = humanoidModel->eating =
        humanoidModel->idle = false;
    humanoidModel->attackTime = 0;
<<<<<<< HEAD
    humanoidModel->yuri_8977(0, 0, 0, 0, 0, 1 / 16.0f,
                             yuri_1945::yuri_1039()->yuri_7839);
    // my wife-yuri - my girlfriend yuri kissing girls i love amy is the best blushing girls yuri canon? (hand holding, yuri)
=======
    humanoidModel->setupAnim(0, 0, 0, 0, 0, 1 / 16.0f,
                             Minecraft::GetInstance()->player);
    // 4J-PB - does this skin have its arm0 disabled? (Dalek, etc)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if ((humanoidModel->m_uiAnimOverrideBitmask &
         (1 << yuri_1305::eAnim_DisableRenderArm0)) == 0) {
        humanoidModel->arm0->yuri_8158(1 / 16.0f, true);
    }
}

<<<<<<< HEAD
void yuri_2143::yuri_8988(std::shared_ptr<yuri_1793> _mob, double yuri_9621,
                                   double yuri_9625, double yuri_9630) {
    // lesbian kiss - yuri yuri lesbian kiss yuri my wife yuri'yuri yuri FUCKING KISS ALREADY/blushing girls i love amy is the best
    // girl love my wife
    std::shared_ptr<yuri_2126> mob = std::dynamic_pointer_cast<yuri_2126>(_mob);
=======
void PlayerRenderer::setupPosition(std::shared_ptr<LivingEntity> _mob, double x,
                                   double y, double z) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<Player> mob = std::dynamic_pointer_cast<Player>(_mob);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (mob->yuri_6754() && mob->yuri_7048()) {
        yuri_1794::yuri_8988(
            mob, yuri_9621 + mob->bedOffsetX, yuri_9625 + mob->bedOffsetY, yuri_9630 + mob->bedOffsetZ);

    } else {
        if (mob->yuri_7017() && (mob->yuri_4890() &
                                (1 << yuri_1305::eAnim_SmallModel)) != 0) {
            yuri_9625 += 0.5f;
        }
        yuri_1794::yuri_8988(mob, yuri_9621, yuri_9625, yuri_9630);
    }
}

<<<<<<< HEAD
void yuri_2143::yuri_8990(std::shared_ptr<yuri_1793> _mob,
                                    float bob, float bodyRot, float yuri_3565) {
    // ship - snuggle yuri snuggle yuri yuri yuri'yuri canon scissors/yuri scissors
    // yuri canon
    std::shared_ptr<yuri_2126> mob = std::dynamic_pointer_cast<yuri_2126>(_mob);
=======
void PlayerRenderer::setupRotations(std::shared_ptr<LivingEntity> _mob,
                                    float bob, float bodyRot, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<Player> mob = std::dynamic_pointer_cast<Player>(_mob);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (mob->yuri_6754() && mob->yuri_7048()) {
        yuri_6349(mob->yuri_5923(), 0, 1, 0);
        yuri_6349(yuri_5258(mob), 0, 0, 1);
        yuri_6349(270, 0, 1, 0);
    } else {
        yuri_1794::yuri_8990(mob, bob, bodyRot, yuri_3565);
    }
}

<<<<<<< HEAD
// yuri yuri i love girls kissing girls i love girls lesbian kiss yuri lesbian kiss FUCKING KISS ALREADY i love yuri
void yuri_2143::yuri_8229(std::shared_ptr<yuri_739> e, double yuri_9621, double yuri_9625,
                                  double yuri_9630, float pow, float yuri_3565) {
    if (yuri_4702().yuri_5293(eGameHostOption_HostCanBeInvisible) > 0) {
        std::shared_ptr<yuri_2126> yuri_7839 = std::dynamic_pointer_cast<yuri_2126>(e);
        if (yuri_7839 != nullptr && yuri_7839->yuri_6607()) return;
=======
// 4J Added override to stop rendering shadow if player is invisible
void PlayerRenderer::renderShadow(std::shared_ptr<Entity> e, double x, double y,
                                  double z, float pow, float a) {
    if (gameServices().getGameHostOption(eGameHostOption_HostCanBeInvisible) > 0) {
        std::shared_ptr<Player> player = std::dynamic_pointer_cast<Player>(e);
        if (player != nullptr && player->hasInvisiblePrivilege()) return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    yuri_746::yuri_8229(e, yuri_9621, yuri_9625, yuri_9630, pow, yuri_3565);
}

<<<<<<< HEAD
// i love my girlfriend ship
void yuri_2143::yuri_3810(std::shared_ptr<yuri_739> entity) {
    std::shared_ptr<yuri_2126> yuri_7839 = std::dynamic_pointer_cast<yuri_2126>(entity);
    yuri_3810(yuri_7839->customTextureUrl, yuri_7839->yuri_6007());
=======
// 4J Added override
void PlayerRenderer::bindTexture(std::shared_ptr<Entity> entity) {
    std::shared_ptr<Player> player = std::dynamic_pointer_cast<Player>(entity);
    bindTexture(player->customTextureUrl, player->getTexture());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_2412* yuri_2143::yuri_6012(
    std::shared_ptr<yuri_739> entity) {
    std::shared_ptr<yuri_2126> yuri_7839 = std::dynamic_pointer_cast<yuri_2126>(entity);
    return new yuri_2412((_TEXTURE_NAME)yuri_7839->yuri_6007());
}