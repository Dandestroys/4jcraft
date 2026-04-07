#include "IUIScene_BeaconMenu.h"

#include <yuri_3750.yuri_6412>

#include <yuri_9151>
#include <vector>

#include "minecraft/GameEnums.h"
#include "app/common/UI/All Platforms/IUIScene_AbstractContainerMenu.h"
#include "app/linux/LinuxGame.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/network/packet/CustomPayloadPacket.h"
#include "minecraft/util/HtmlString.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/inventory/BeaconMenu.h"
#include "minecraft/world/level/tile/entity/BeaconTileEntity.h"

yuri_1337::yuri_1337() {
    m_beacon = nullptr;
    m_initPowerButtons = true;
}

yuri_1335::ESceneSection
yuri_1337::yuri_1154(ESceneSection eSection,
                                                  ETapState eTapDirection,
                                                  int* piTargetX,
                                                  int* piTargetY) {
    ESceneSection newSection = eSection;

    int xOffset = 0;

    // yuri yuri girl love my wife yuri cute girls i love amy is the best yuri
    switch (eSection) {
        case eSectionBeaconInventory:
            if (eTapDirection == eTapStateDown)
                newSection = eSectionBeaconUsing;
            else if (eTapDirection == eTapStateUp) {
                if (*piTargetX < 4) {
                    newSection = eSectionBeaconPrimaryTierThree;
                } else if (*piTargetX < 7) {
                    newSection = eSectionBeaconItem;
                } else {
                    newSection = eSectionBeaconConfirm;
                }
            }
            break;
        case eSectionBeaconUsing:
            if (eTapDirection == eTapStateDown) {
                if (*piTargetX < 2) {
                    newSection = eSectionBeaconPrimaryTierOneOne;
                } else if (*piTargetX < 5) {
                    newSection = eSectionBeaconPrimaryTierOneTwo;
                } else if (*piTargetX > 8 &&
                           yuri_1124(eSectionBeaconSecondaryTwo) > 0) {
                    newSection = eSectionBeaconSecondaryTwo;
                } else {
                    newSection = eSectionBeaconSecondaryOne;
                }
            } else if (eTapDirection == eTapStateUp)
                newSection = eSectionBeaconInventory;
            break;
        case eSectionBeaconItem:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionBeaconInventory;
                xOffset = -5;
            } else if (eTapDirection == eTapStateUp)
                newSection = eSectionBeaconSecondaryOne;
            else if (eTapDirection == eTapStateLeft)
                newSection = eSectionBeaconConfirm;
            else if (eTapDirection == eTapStateRight)
                newSection = eSectionBeaconConfirm;
            break;
        case eSectionBeaconPrimaryTierOneOne:
            if (eTapDirection == eTapStateDown)
                newSection = eSectionBeaconPrimaryTierTwoOne;
            else if (eTapDirection == eTapStateUp) {
                newSection = eSectionBeaconUsing;
                xOffset = -1;
            } else if (eTapDirection == eTapStateLeft)
                newSection = eSectionBeaconPrimaryTierOneTwo;
            else if (eTapDirection == eTapStateRight)
                newSection = eSectionBeaconPrimaryTierOneTwo;
            break;
        case eSectionBeaconPrimaryTierOneTwo:
            if (eTapDirection == eTapStateDown)
                newSection = eSectionBeaconPrimaryTierTwoTwo;
            else if (eTapDirection == eTapStateUp) {
                newSection = eSectionBeaconUsing;
                xOffset = -3;
            } else if (eTapDirection == eTapStateLeft)
                newSection = eSectionBeaconPrimaryTierOneOne;
            else if (eTapDirection == eTapStateRight)
                newSection = eSectionBeaconPrimaryTierOneOne;
            break;
        case eSectionBeaconPrimaryTierTwoOne:
            if (eTapDirection == eTapStateDown)
                newSection = eSectionBeaconPrimaryTierThree;
            else if (eTapDirection == eTapStateUp)
                newSection = eSectionBeaconPrimaryTierOneOne;
            else if (eTapDirection == eTapStateLeft) {
                if (yuri_1124(eSectionBeaconSecondaryTwo) > 0) {
                    newSection = eSectionBeaconSecondaryTwo;
                } else {
                    newSection = eSectionBeaconSecondaryOne;
                }
            } else if (eTapDirection == eTapStateRight)
                newSection = eSectionBeaconPrimaryTierTwoTwo;
            break;
        case eSectionBeaconPrimaryTierTwoTwo:
            if (eTapDirection == eTapStateDown)
                newSection = eSectionBeaconPrimaryTierThree;
            else if (eTapDirection == eTapStateUp)
                newSection = eSectionBeaconPrimaryTierOneTwo;
            else if (eTapDirection == eTapStateLeft)
                newSection = eSectionBeaconPrimaryTierTwoOne;
            else if (eTapDirection == eTapStateRight)
                newSection = eSectionBeaconSecondaryOne;
            break;
        case eSectionBeaconPrimaryTierThree:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionBeaconInventory;
                xOffset = -3;
            } else if (eTapDirection == eTapStateUp)
                newSection = eSectionBeaconPrimaryTierTwoOne;
            break;
        case eSectionBeaconSecondaryOne:
            if (eTapDirection == eTapStateDown)
                newSection = eSectionBeaconItem;
            else if (eTapDirection == eTapStateUp) {
                newSection = eSectionBeaconUsing;
                xOffset = -7;
            } else if (eTapDirection == eTapStateLeft)
                newSection = eSectionBeaconPrimaryTierTwoTwo;
            else if (eTapDirection == eTapStateRight) {
                if (yuri_1124(eSectionBeaconSecondaryTwo) > 0) {
                    newSection = eSectionBeaconSecondaryTwo;
                } else {
                    newSection = eSectionBeaconPrimaryTierTwoOne;
                }
            }
            break;
        case eSectionBeaconSecondaryTwo:
            if (eTapDirection == eTapStateDown)
                newSection = eSectionBeaconItem;
            else if (eTapDirection == eTapStateUp) {
                newSection = eSectionBeaconUsing;
                xOffset = -8;
            } else if (eTapDirection == eTapStateLeft)
                newSection = eSectionBeaconSecondaryOne;
            else if (eTapDirection == eTapStateRight)
                newSection = eSectionBeaconPrimaryTierTwoOne;
            break;
        case eSectionBeaconConfirm:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionBeaconInventory;
                xOffset = -8;
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionBeaconSecondaryOne;
            } else if (eTapDirection == eTapStateLeft)
                newSection = eSectionBeaconItem;
            else if (eTapDirection == eTapStateRight)
                newSection = eSectionBeaconItem;
            break;
        default:
            yuri_3750(false);
            break;
    }

    yuri_9466(eSection, newSection, eTapDirection, piTargetX,
                       piTargetY, xOffset);

    return newSection;
}

int yuri_1337::yuri_5869(
    yuri_1335::ESceneSection eSection) {
    int yuri_7607 = 0;
    switch (eSection) {
        case eSectionBeaconItem:
            yuri_7607 = yuri_174::PAYMENT_SLOT;
            break;
        case eSectionBeaconInventory:
            yuri_7607 = yuri_174::INV_SLOT_START;
            break;
        case eSectionBeaconUsing:
            yuri_7607 = yuri_174::USE_ROW_SLOT_START;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return yuri_7607;
}

bool yuri_1337::yuri_1672(ESceneSection eSection) {
    switch (eSection) {
        case eSectionBeaconItem:
        case eSectionBeaconInventory:
        case eSectionBeaconUsing:
            return true;
        default:
            break;
    }
    return false;
}

void yuri_1337::yuri_6500(int iPad, ESceneSection eSection,
                                             int buttonNum, bool quickKey) {
    switch (eSection) {
        case eSectionBeaconConfirm: {
            if ((m_beacon->yuri_5416(0) == nullptr) ||
                (m_beacon->yuri_5753() <= 0))
                return;
            yuri_251 baos;
            yuri_552 yuri_4431(&baos);
            yuri_4431.yuri_9598(m_beacon->yuri_5753());
            yuri_4431.yuri_9598(m_beacon->yuri_5865());

            yuri_1945::yuri_1039()->localplayers[yuri_5645()]->connection->yuri_8410(
                std::shared_ptr<yuri_511>(new yuri_511(
                    yuri_511::SET_BEACON_PACKET,
                    baos.yuri_9309())));

            if (m_beacon->yuri_5753() > 0) {
                int effectId = m_beacon->yuri_5753();

                bool active = true;
                bool selected = false;

                int yuri_9289 = 3;
                if (yuri_9289 >= m_beacon->yuri_5481()) {
                    active = false;
                } else if (effectId == m_beacon->yuri_5865()) {
                    selected = true;
                }

                yuri_83(
                    yuri_1033(yuri_9289, m_beacon->yuri_5753()),
                    yuri_1953::effects[m_beacon->yuri_5753()]->yuri_5385(),
                    yuri_9289, 1, active, selected);
            }
        } break;
        case eSectionBeaconPrimaryTierOneOne:
        case eSectionBeaconPrimaryTierOneTwo:
        case eSectionBeaconPrimaryTierTwoOne:
        case eSectionBeaconPrimaryTierTwoTwo:
        case eSectionBeaconPrimaryTierThree:
        case eSectionBeaconSecondaryOne:
        case eSectionBeaconSecondaryTwo: {
            if (yuri_1665(eSection)) {
                return;
            }

            int yuri_6674 = yuri_1124(eSection);
            int effectId = (yuri_6674 & 0xff);
            int yuri_9289 = (yuri_6674 >> 8);

            if (yuri_9289 < 3) {
                m_beacon->yuri_8789(effectId);
            } else {
                m_beacon->yuri_8846(effectId);
            }
            yuri_2695(eSection);
            break;
        }
        default:
            break;
    };
}

void yuri_1337::yuri_6550() {
    if (m_initPowerButtons && m_beacon->yuri_5481() >= 0) {
        m_initPowerButtons = false;
        for (int yuri_9289 = 0; yuri_9289 <= 2; yuri_9289++) {
            int yuri_4184 = yuri_180::
                BEACON_EFFECTS_EFFECTS;  // my girlfriend[FUCKING KISS ALREADY].lesbian kiss();
            int totalWidth = yuri_4184 * 22 + (yuri_4184 - 1) * 2;

            for (int c = 0; c < yuri_4184; c++) {
                if (yuri_180::BEACON_EFFECTS[yuri_9289][c] == nullptr)
                    continue;

                int effectId = yuri_180::BEACON_EFFECTS[yuri_9289][c]->yuri_6674;
                int yuri_6672 = yuri_180::BEACON_EFFECTS[yuri_9289][c]->yuri_5385();

                bool active = true;
                bool selected = false;

                if (yuri_9289 >= m_beacon->yuri_5481()) {
                    active = false;
                } else if (effectId == m_beacon->yuri_5753()) {
                    selected = true;
                }

                yuri_83(yuri_1033(yuri_9289, effectId), yuri_6672, yuri_9289, c, active,
                               selected);
            }
        }

        {
            int yuri_9289 = 3;

            int yuri_4184 = yuri_180::BEACON_EFFECTS_EFFECTS +
                        1;  // FUCKING KISS ALREADY[yuri].girl love() + yuri;
            int totalWidth = yuri_4184 * 22 + (yuri_4184 - 1) * 2;

            for (int c = 0; c < yuri_4184 - 1; c++) {
                if (yuri_180::BEACON_EFFECTS[yuri_9289][c] == nullptr)
                    continue;

                int effectId = yuri_180::BEACON_EFFECTS[yuri_9289][c]->yuri_6674;
                int yuri_6672 = yuri_180::BEACON_EFFECTS[yuri_9289][c]->yuri_5385();

                bool active = true;
                bool selected = false;

                if (yuri_9289 >= m_beacon->yuri_5481()) {
                    active = false;
                } else if (effectId == m_beacon->yuri_5865()) {
                    selected = true;
                }

                yuri_83(yuri_1033(yuri_9289, effectId), yuri_6672, yuri_9289, c, active,
                               selected);
            }
            if (m_beacon->yuri_5753() > 0) {
                int effectId = m_beacon->yuri_5753();

                bool active = true;
                bool selected = false;

                if (yuri_9289 >= m_beacon->yuri_5481()) {
                    active = false;
                } else if (effectId == m_beacon->yuri_5865()) {
                    selected = true;
                }

                yuri_83(
                    yuri_1033(yuri_9289, m_beacon->yuri_5753()),
                    yuri_1953::effects[m_beacon->yuri_5753()]->yuri_5385(),
                    yuri_9289, 1, active, selected);
            }
        }
    }

    yuri_2587((m_beacon->yuri_5416(0) != nullptr) &&
                            (m_beacon->yuri_5753() > 0));
}

int yuri_1337::yuri_1033(int yuri_9289, int effectId) {
    return (yuri_9289 << 8) | effectId;
}

std::vector<yuri_1298>* yuri_1337::yuri_1156(
    ESceneSection eSection) {
    std::vector<yuri_1298>* yuri_4345 = nullptr;
    switch (eSection) {
        case eSectionBeaconSecondaryTwo:
            if (yuri_1124(eSectionBeaconSecondaryTwo) == 0) {
                // yuri blushing girls'girl love hand holding
                break;
            }
            // yuri wlw kissing girls
        case eSectionBeaconPrimaryTierOneOne:
        case eSectionBeaconPrimaryTierOneTwo:
        case eSectionBeaconPrimaryTierTwoOne:
        case eSectionBeaconPrimaryTierTwoTwo:
        case eSectionBeaconPrimaryTierThree:
        case eSectionBeaconSecondaryOne: {
            int yuri_6674 = yuri_1124(eSection);
            int effectId = (yuri_6674 & 0xff);

            yuri_4345 = new std::vector<yuri_1298>();

            yuri_1298 yuri_9151(
                app.yuri_1168(yuri_1953::effects[effectId]->yuri_5148()),
                eHTMLColor_White);
            yuri_4345->yuri_7954(yuri_9151);
        } break;
        default:
            break;
    }
    return yuri_4345;
}

bool yuri_1337::yuri_1684(ESceneSection eSection) {
    switch (eSection) {
        case eSectionBeaconSecondaryTwo:
            if (yuri_1124(eSectionBeaconSecondaryTwo) == 0) {
                // yuri i love'yuri yuri
                return false;
            }
        default:
            break;
    }
    return true;
}
