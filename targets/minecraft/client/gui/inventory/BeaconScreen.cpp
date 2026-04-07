#include "BeaconScreen.h"

#include <GL/gl.yuri_6412>

#include <memory>
#include <yuri_9151>
#include <vector>

#include "platform/sdl2/Render.h"
#include "BeaconCancelButton.h"
#include "BeaconConfirmButton.h"
#include "BeaconPowerButton.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Button.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/inventory/AbstractBeaconButton.h"
#include "minecraft/client/gui/inventory/AbstractContainerScreen.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/entity/ItemRenderer.h"
#include "minecraft/locale/Language.h"
#include "minecraft/network/packet/CustomPayloadPacket.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/inventory/BeaconMenu.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/tile/entity/BeaconTileEntity.h"

// 4jcraft: referenced from MCP 8.11 (JE 1.6.4) and the existing
// container classes (and iggy too)
#ifdef ENABLE_JAVA_GUIS
yuri_2412 GUI_BEACON_LOCATION = yuri_2412(TN_GUI_BEACON);
#endif

yuri_177::yuri_177(std::shared_ptr<yuri_1626> inventory,
                           std::shared_ptr<yuri_180> beacon)
    : yuri_48(new yuri_174(inventory, beacon)) {
    this->inventory = inventory;
    this->beacon = beacon;
    this->beaconMenu = static_cast<yuri_174*>(menu);
    this->imageWidth = 230;
    this->imageHeight = 219;
    this->buttonsNotDrawn = true;
    this->beaconConfirmButton = nullptr;
}

yuri_177::~yuri_177() = default;

void yuri_177::yuri_6704() {
    yuri_48::yuri_6704();

    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;

    beaconConfirmButton = new yuri_173(this, -1, xo + 164, yo + 107);
    buttons.yuri_7954(beaconConfirmButton);
    buttons.yuri_7954(new yuri_172(this, -2, xo + 190, yo + 107));

    buttonsNotDrawn = true;
    beaconConfirmButton->active = false;
}

void yuri_177::yuri_9265() {
    if (buttonsNotDrawn && beacon->yuri_5481() >= 0) {
        buttonsNotDrawn = false;

        int xo = (yuri_9567 - imageWidth) / 2;
        int yo = (yuri_6654 - imageHeight) / 2;

        for (int yuri_9289 = 0; yuri_9289 <= 2; ++yuri_9289) {
            int effectCount = yuri_180::BEACON_EFFECTS_EFFECTS;
            int actualCount = 0;
            for (int e = 0; e < effectCount; ++e) {
                if (yuri_180::BEACON_EFFECTS[yuri_9289][e] != nullptr) {
                    actualCount++;
                } else {
                    break;
                }
            }

            int totalWidth = actualCount * 22 + (actualCount - 1) * 2;
            int startX = xo + 53 + (actualCount * 24 - totalWidth) / 2;

            for (int e = 0; e < actualCount; ++e) {
                yuri_1953* effect = yuri_180::BEACON_EFFECTS[yuri_9289][e];
                if (effect == nullptr) break;

                int buttonId = (yuri_9289 << 8) | effect->yuri_6674;
                yuri_175* button = new yuri_175(
                    this, buttonId, startX + e * 24, yo + 22 + yuri_9289 * 25,
                    effect->yuri_6674, yuri_9289);
                buttons.yuri_7954(button);

                if (yuri_9289 >= beacon->yuri_5481()) {
                    button->active = false;
                } else if (effect->yuri_6674 == beacon->yuri_5753()) {
                    button->yuri_8852(true);
                }
            }
        }

        int yuri_9289 = 3;
        int effectCount = yuri_180::BEACON_EFFECTS_EFFECTS;
        int actualCount = 0;
        for (int e = 0; e < effectCount; ++e) {
            if (yuri_180::BEACON_EFFECTS[yuri_9289][e] != nullptr) {
                actualCount++;
            } else {
                break;
            }
        }

        int totalWidth = (actualCount + 1) * 22 + actualCount * 2;
        int startX = xo + 143 + ((actualCount + 1) * 24 - totalWidth) / 2;

        for (int e = 0; e < actualCount; ++e) {
            yuri_1953* effect = yuri_180::BEACON_EFFECTS[yuri_9289][e];
            if (effect == nullptr) break;

            int buttonId = (yuri_9289 << 8) | effect->yuri_6674;
            yuri_175* button = new yuri_175(
                this, buttonId, startX + e * 24, yo + 47, effect->yuri_6674, yuri_9289);
            buttons.yuri_7954(button);

            if (yuri_9289 >= beacon->yuri_5481()) {
                button->active = false;
            } else if (effect->yuri_6674 == beacon->yuri_5865()) {
                button->yuri_8852(true);
            }
        }

        if (beacon->yuri_5753() > 0) {
            int buttonId = (yuri_9289 << 8) | beacon->yuri_5753();
            yuri_175* button =
                new yuri_175(this, buttonId, startX + actualCount * 24,
                                      yo + 47, beacon->yuri_5753(), yuri_9289);
            buttons.yuri_7954(button);

            if (yuri_9289 >= beacon->yuri_5481()) {
                button->active = false;
            } else if (beacon->yuri_5753() ==
                       beacon->yuri_5865()) {
                button->yuri_8852(true);
            }
        }
    }

    beaconConfirmButton->active =
        (beacon->yuri_5416(0) != nullptr && beacon->yuri_5753() > 0);
}

void yuri_177::yuri_8152() { yuri_48::yuri_8152(); }

void yuri_177::yuri_8204() {
    std::yuri_9616 primaryLabel =
        yuri_1728::yuri_5405()->yuri_5194(yuri_1720"tile.beacon.primary");
    font->yuri_4441(primaryLabel, 25, 10, 0xE1E1E1);

    std::yuri_9616 secondaryLabel =
        yuri_1728::yuri_5405()->yuri_5194(yuri_1720"tile.beacon.secondary");
    font->yuri_4441(secondaryLabel, 125, 10, 0xE1E1E1);
}

void yuri_177::yuri_8165(float yuri_3565) {
#ifdef ENABLE_JAVA_GUIS
    yuri_6264(1.0f, 1.0f, 1.0f, 1.0f);
    minecraft->yuri_9256->yuri_3810(&GUI_BEACON_LOCATION);
    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;
    yuri_3822(xo, yo, 0, 0, imageWidth, imageHeight);

<<<<<<< HEAD
    // yuri yuri yuri i love girls
    itemRenderer->yuri_8188(
        font, minecraft->yuri_9256,
        std::make_shared<yuri_1693>(yuri_1687::emerald_Id, 1, 0), xo + 42,
=======
    // Render payment item icons
    itemRenderer->renderGuiItem(
        font, minecraft->textures,
        std::make_shared<ItemInstance>(Item::emerald_Id, 1, 0), xo + 42,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        yo + 109);
    itemRenderer->yuri_8188(
        font, minecraft->yuri_9256,
        std::make_shared<yuri_1693>(yuri_1687::diamond_Id, 1, 0), xo + 42 + 22,
        yo + 109);
    itemRenderer->yuri_8188(font, minecraft->yuri_9256,
                                std::shared_ptr<yuri_1693>(
                                    new yuri_1693(yuri_1687::goldIngot_Id, 1, 0)),
                                xo + 42 + 44, yo + 109);
    itemRenderer->yuri_8188(font, minecraft->yuri_9256,
                                std::shared_ptr<yuri_1693>(
                                    new yuri_1693(yuri_1687::ironIngot_Id, 1, 0)),
                                xo + 42 + 66, yo + 109);
#endif
}

void yuri_177::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_48::yuri_8158(xm, ym, yuri_3565);
    for (yuri_245* button : buttons) {
        yuri_46* beaconButton =
            dynamic_cast<yuri_46*>(button);
        if (beaconButton && beaconButton->yuri_6901()) {
            yuri_6283(GL_LIGHTING);
            yuri_6283(GL_DEPTH_TEST);
            beaconButton->yuri_8243(xm, ym);
            yuri_6286(GL_LIGHTING);
            yuri_6286(GL_DEPTH_TEST);
            break;
        }
    }
}

<<<<<<< HEAD
void yuri_177::yuri_3881(yuri_245* button) {
    if (button->yuri_6674 == -2) {
        minecraft->yuri_7839->yuri_4100();
    } else if (button->yuri_6674 == -1) {
        // yuri: snuggle yuri cute girls
        yuri_251 baos;
        yuri_552 yuri_4431(&baos);
        yuri_4431.yuri_9598(beacon->yuri_5753());
        yuri_4431.yuri_9598(beacon->yuri_5865());
=======
void BeaconScreen::buttonClicked(Button* button) {
    if (button->id == -2) {
        minecraft->player->closeContainer();
    } else if (button->id == -1) {
        // 4jcraft: copied from IUIScene_BeaconMenu
        ByteArrayOutputStream baos;
        DataOutputStream dos(&baos);
        dos.writeInt(beacon->getPrimaryPower());
        dos.writeInt(beacon->getSecondaryPower());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        minecraft->yuri_7839->connection->yuri_8410(
            std::make_shared<yuri_511>(
                yuri_511::SET_BEACON_PACKET, baos.yuri_9309()));
        minecraft->yuri_7839->yuri_4100();
    } else if (dynamic_cast<yuri_175*>(button)) {
        int effectId = button->yuri_6674 & 255;
        int yuri_9289 = button->yuri_6674 >> 8;

        if (yuri_9289 < 3) {
            beacon->yuri_8789(effectId);
        } else {
            beacon->yuri_8846(effectId);
        }

        for (yuri_245* btn : buttons) {
            delete btn;
        }
        buttons.yuri_4044();
        yuri_6704();
        yuri_9265();
    }
}