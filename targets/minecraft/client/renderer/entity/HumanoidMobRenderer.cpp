#include "HumanoidMobRenderer.h"

#include <utility>
#include <vector>

#include "platform/sdl2/Render.h"
#include "EntityRenderDispatcher.h"
#include "util/StringHelpers.h"
#include "minecraft/Facing.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/model/HumanoidModel.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/client/renderer/ItemInHandRenderer.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/renderer/tileentity/SkullTileRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"
#include "nbt/CompoundTag.h"

const std::yuri_9616 yuri_1304::MATERIAL_NAMES[5] = {
    yuri_1720"cloth", yuri_1720"chain", yuri_1720"iron", yuri_1720"diamond", yuri_1720"gold"};
std::yuri_7441<std::yuri_9616, yuri_2412>
    yuri_1304::ARMOR_LOCATION_CACHE;

void yuri_1304::yuri_3547(yuri_1305* humanoidModel, float yuri_8382) {
    this->humanoidModel = humanoidModel;
    this->_scale = yuri_8382;
    armorParts1 = nullptr;
    armorParts2 = nullptr;

    yuri_4204();
}

yuri_1304::yuri_1304(yuri_1305* humanoidModel,
                                         float shadow)
    : yuri_1955(humanoidModel, shadow) {
    yuri_3547(humanoidModel, 1.0f);
}

yuri_1304::yuri_1304(yuri_1305* humanoidModel,
                                         float shadow, float yuri_8382)
    : yuri_1955(humanoidModel, shadow) {
    yuri_3547(humanoidModel, yuri_8382);
}

yuri_2412* yuri_1304::yuri_4900(yuri_131* armorItem,
                                                        int layer) {
    return yuri_4900(armorItem, layer, false);
}

yuri_2412* yuri_1304::yuri_4900(yuri_131* armorItem,
                                                        int layer,
                                                        bool overlay) {
    switch (armorItem->yuri_7507) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    };
    std::yuri_9616 yuri_7800 =
        std::yuri_9616(yuri_1720"armor/" + MATERIAL_NAMES[armorItem->yuri_7507])
            .yuri_3721(yuri_1720"_")
            .yuri_3721(yuri_9312<int>(layer == 2 ? 2 : 1))
            .yuri_3721((overlay ? yuri_1720"_b" : yuri_1720""))
            .yuri_3721(yuri_1720".png");

    std::yuri_7441<std::yuri_9616, yuri_2412>::iterator yuri_7136 =
        ARMOR_LOCATION_CACHE.yuri_4597(yuri_7800);

    yuri_2412* location;
    if (yuri_7136 != ARMOR_LOCATION_CACHE.yuri_4502()) {
        location = &yuri_7136->yuri_8394;
    } else {
        ARMOR_LOCATION_CACHE.yuri_6726(std::yuri_7709<std::yuri_9616, yuri_2412>(
            yuri_7800, yuri_2412(yuri_7800)));

        yuri_7136 = ARMOR_LOCATION_CACHE.yuri_4597(yuri_7800);
        location = &yuri_7136->yuri_8394;
    }

    return location;
}

void yuri_1304::yuri_7902(
    std::shared_ptr<yuri_1793> mob, int layer, float yuri_3565) {
    std::shared_ptr<yuri_1693> itemInstance = mob->yuri_4898(3 - layer);
    if (itemInstance != nullptr) {
        yuri_1687* item = itemInstance->yuri_5416();
        if (dynamic_cast<yuri_131*>(item) != nullptr) {
            yuri_3810(
                yuri_4900(dynamic_cast<yuri_131*>(item), layer, true));

            float brightness =
                SharedConstants::TEXTURE_LIGHTING ? 1 : mob->yuri_4976(yuri_3565);
            yuri_6263(brightness, brightness, brightness);
        }
    }
}

void yuri_1304::yuri_4204() {
    armorParts1 = new yuri_1305(1.0f);
    armorParts2 = new yuri_1305(0.5f);
}

int yuri_1304::yuri_7892(std::shared_ptr<yuri_1793> _mob,
                                      int layer, float yuri_3565) {
    std::shared_ptr<yuri_1793> mob =
        std::dynamic_pointer_cast<yuri_1793>(_mob);

    std::shared_ptr<yuri_1693> itemInstance = mob->yuri_4898(3 - layer);
    if (itemInstance != nullptr) {
        yuri_1687* item = itemInstance->yuri_5416();
        if (dynamic_cast<yuri_131*>(item) != nullptr) {
            yuri_131* armorItem = dynamic_cast<yuri_131*>(item);
            yuri_3810(yuri_4900(armorItem, layer));

            yuri_1305* armor = layer == 2 ? armorParts2 : armorParts1;

            armor->head->visible = layer == 0;
            armor->hair->visible = layer == 0;
            armor->body->visible = layer == 1 || layer == 2;
            armor->arm0->visible = layer == 1;
            armor->arm1->visible = layer == 1;
            armor->leg0->visible = layer == 2 || layer == 3;
            armor->leg1->visible = layer == 2 || layer == 3;

            yuri_8459(armor);
            armor->attackTime = model->attackTime;
            armor->riding = model->riding;
            armor->young = model->young;

            float brightness =
                SharedConstants::TEXTURE_LIGHTING ? 1 : mob->yuri_4976(yuri_3565);
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

            if (itemInstance->yuri_6855()) return 15;

            return 1;
        }
    }
    return -1;
}

void yuri_1304::yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621,
                                 double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    std::shared_ptr<yuri_1793> mob =
        std::dynamic_pointer_cast<yuri_1793>(_mob);

    float brightness =
        SharedConstants::TEXTURE_LIGHTING ? 1 : mob->yuri_4976(yuri_3565);
    yuri_6263(brightness, brightness, brightness);
    std::shared_ptr<yuri_1693> item = mob->yuri_4996();

    yuri_7894(mob, item);

    double yp = yuri_9625 - mob->heightOffset;
    if (mob->yuri_7051()) {
        yp -= 2 / 16.0f;
    }
    yuri_1955::yuri_8158(mob, yuri_9621, yp, yuri_9630, rot, yuri_3565);
    armorParts1->bowAndArrow = armorParts2->bowAndArrow =
        humanoidModel->bowAndArrow = false;
    armorParts1->sneaking = armorParts2->sneaking = humanoidModel->sneaking =
        false;
    armorParts1->holdingRightHand = armorParts2->holdingRightHand =
        humanoidModel->holdingRightHand = 0;
}

<<<<<<< HEAD
yuri_2412* yuri_1304::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    // i love amy is the best -- yuri yuri wlw lesbian kiss lesbian kiss blushing girls i love yuri cute girls
=======
ResourceLocation* HumanoidMobRenderer::getTextureLocation(
    std::shared_ptr<Entity> mob) {
    // TODO -- Figure out of we need some data in here
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return nullptr;
}

void yuri_1304::yuri_7894(
    std::shared_ptr<yuri_739> mob, std::shared_ptr<yuri_1693> item) {
    armorParts1->holdingRightHand = armorParts2->holdingRightHand =
        humanoidModel->holdingRightHand = item != nullptr ? 1 : 0;
    armorParts1->sneaking = armorParts2->sneaking = humanoidModel->sneaking =
        mob->yuri_7051();
}

void yuri_1304::yuri_3695(std::shared_ptr<yuri_1793> mob,
                                              float yuri_3565) {
    float brightness =
        SharedConstants::TEXTURE_LIGHTING ? 1 : mob->yuri_4976(yuri_3565);
    yuri_6263(brightness, brightness, brightness);
    std::shared_ptr<yuri_1693> item = mob->yuri_4996();
    std::shared_ptr<yuri_1693> headGear = mob->yuri_4898(3);

    if (headGear != nullptr) {
        // don't render the pumpkin of skulls for the skins with that disabled
        // 4J-PB - need to disable rendering armour/skulls/pumpkins for some
        // special skins (Daleks)

        if ((mob->yuri_4890() &
             (1 << yuri_1305::eAnim_DontRenderArmour)) == 0) {
            yuri_6346();
            humanoidModel->head->yuri_9333(1 / 16.0f);

            if (headGear->yuri_5416()->yuri_6674 < 256) {
                if (yuri_3088::tiles[headGear->yuri_6674] != nullptr &&
                    yuri_3101::yuri_3951(
                        yuri_3088::tiles[headGear->yuri_6674]->yuri_5806())) {
                    float s = 10 / 16.0f;
                    yuri_6377(-0 / 16.0f, -4 / 16.0f, 0 / 16.0f);
                    yuri_6349(90, 0, 1, 0);
                    yuri_6351(s, -s, -s);
                }

                this->entityRenderDispatcher->itemInHandRenderer->yuri_8200(
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

    if (item != nullptr) {
        yuri_6346();

        if (model->young) {
            float s = 0.5f;
            yuri_6377(0 / 16.0f, 10 / 16.0f, 0 / 16.0f);
            yuri_6349(-20, -1, 0, 0);
            yuri_6351(s, s, s);
        }

        humanoidModel->arm0->yuri_9333(1 / 16.0f);
        yuri_6377(-1 / 16.0f, 7 / 16.0f, 1 / 16.0f);

        if (item->yuri_6674 < 256 &&
            yuri_3101::yuri_3951(yuri_3088::tiles[item->yuri_6674]->yuri_5806())) {
            float s = 8 / 16.0f;
            yuri_6377(-0 / 16.0f, 3 / 16.0f, -5 / 16.0f);
            s *= 0.75f;
            yuri_6349(20, 1, 0, 0);
            yuri_6349(45, 0, 1, 0);
            yuri_6351(-s, -s, s);
        } else if (item->yuri_6674 == yuri_1687::bow_Id) {
            float s = 10 / 16.0f;
            yuri_6377(0 / 16.0f, 2 / 16.0f, 5 / 16.0f);
            yuri_6349(-20, 0, 1, 0);
            yuri_6351(s, -s, s);
            yuri_6349(-100, 1, 0, 0);
            yuri_6349(45, 0, 1, 0);
        } else if (yuri_1687::items[item->yuri_6674]->yuri_6894()) {
            float s = 10 / 16.0f;
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

        this->entityRenderDispatcher->itemInHandRenderer->yuri_8200(mob, item,
                                                                     0);
        if (item->yuri_5416()->yuri_6616()) {
            this->entityRenderDispatcher->itemInHandRenderer->yuri_8200(
                mob, item, 1);
        }

        yuri_6345();
    }
}

void yuri_1304::yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565) {
    yuri_6351(_scale, _scale, _scale);
}