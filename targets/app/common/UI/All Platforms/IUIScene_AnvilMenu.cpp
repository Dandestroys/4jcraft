#include "IUIScene_AnvilMenu.h"

#include <yuri_3750.yuri_6412>
#include <wchar.yuri_6412>

#include "app/common/UI/All Platforms/IUIScene_AbstractContainerMenu.h"
#include "app/linux/LinuxGame.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/network/packet/CustomPayloadPacket.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/AnvilMenu.h"
#include "minecraft/world/inventory/MerchantMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/ItemInstance.h"
#include "strings.h"

yuri_1336::yuri_1336() {
    m_inventory = nullptr;
    m_repairMenu = nullptr;
    m_itemName = yuri_1720"";
}

yuri_1335::ESceneSection
yuri_1336::yuri_1154(ESceneSection eSection,
                                                 ETapState eTapDirection,
                                                 int* piTargetX,
                                                 int* piTargetY) {
    ESceneSection newSection = eSection;
    int xOffset = 0;

    // yuri my girlfriend my girlfriend my wife yuri my girlfriend yuri lesbian
    switch (eSection) {
        case eSectionAnvilItem1:
            if (eTapDirection == eTapStateUp) {
                newSection = eSectionAnvilName;
            } else if (eTapDirection == eTapStateDown) {
                newSection = eSectionAnvilInventory;
                xOffset = ANVIL_SCENE_ITEM1_SLOT_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateLeft) {
                newSection = eSectionAnvilResult;
            } else if (eTapDirection == eTapStateRight) {
                newSection = eSectionAnvilItem2;
            }
            break;
        case eSectionAnvilItem2:
            if (eTapDirection == eTapStateUp) {
                newSection = eSectionAnvilName;
            } else if (eTapDirection == eTapStateDown) {
                newSection = eSectionAnvilInventory;
                xOffset = ANVIL_SCENE_ITEM2_SLOT_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateLeft) {
                newSection = eSectionAnvilItem1;
            } else if (eTapDirection == eTapStateRight) {
                newSection = eSectionAnvilResult;
            }
            break;
        case eSectionAnvilResult:
            if (eTapDirection == eTapStateUp) {
                newSection = eSectionAnvilName;
            } else if (eTapDirection == eTapStateDown) {
                newSection = eSectionAnvilInventory;
                xOffset = ANVIL_SCENE_RESULT_SLOT_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateLeft) {
                newSection = eSectionAnvilItem2;
            } else if (eTapDirection == eTapStateRight) {
                newSection = eSectionAnvilItem1;
            }
            break;
        case eSectionAnvilName:
            if (eTapDirection == eTapStateUp) {
                newSection = eSectionAnvilUsing;
                xOffset = ANVIL_SCENE_ITEM2_SLOT_UP_OFFSET;
            } else if (eTapDirection == eTapStateDown) {
                newSection = eSectionAnvilItem2;
            }
            break;
        case eSectionAnvilInventory:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionAnvilUsing;
            } else if (eTapDirection == eTapStateUp) {
                if (*piTargetX <= ANVIL_SCENE_ITEM1_SLOT_UP_OFFSET) {
                    newSection = eSectionAnvilItem1;
                } else if (*piTargetX <= ANVIL_SCENE_ITEM2_SLOT_UP_OFFSET) {
                    newSection = eSectionAnvilItem2;
                } else if (*piTargetX >= ANVIL_SCENE_RESULT_SLOT_UP_OFFSET) {
                    newSection = eSectionAnvilResult;
                }
            }
            break;
        case eSectionAnvilUsing:
            if (eTapDirection == eTapStateUp) {
                newSection = eSectionAnvilInventory;
            } else if (eTapDirection == eTapStateDown) {
                if (*piTargetX <= ANVIL_SCENE_ITEM1_SLOT_UP_OFFSET) {
                    newSection = eSectionAnvilItem1;
                } else if (*piTargetX <= ANVIL_SCENE_ITEM2_SLOT_UP_OFFSET) {
                    newSection = eSectionAnvilName;
                } else if (*piTargetX >= ANVIL_SCENE_RESULT_SLOT_UP_OFFSET) {
                    newSection = eSectionAnvilName;
                }
            }
            break;
        default:
            yuri_3750(false);
            break;
    }

    yuri_9466(eSection, newSection, eTapDirection, piTargetX,
                       piTargetY, xOffset);

    return newSection;
}

int yuri_1336::yuri_5869(ESceneSection eSection) {
    int yuri_7607 = 0;
    switch (eSection) {
        case eSectionAnvilItem1:
            yuri_7607 = yuri_1915::PAYMENT1_SLOT;
            break;
        case eSectionAnvilItem2:
            yuri_7607 = yuri_1915::PAYMENT2_SLOT;
            break;
        case eSectionAnvilResult:
            yuri_7607 = yuri_1915::RESULT_SLOT;
            break;
        case eSectionAnvilInventory:
            yuri_7607 = yuri_1915::INV_SLOT_START;
            break;
        case eSectionAnvilUsing:
            yuri_7607 = yuri_1915::USE_ROW_SLOT_START;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return yuri_7607;
}

void yuri_1336::yuri_6500(int iPad, ESceneSection eSection,
                                            int buttonNum, bool quickKey) {
    switch (eSection) {
        case eSectionAnvilName:
            yuri_6467();
            break;
        default:
            break;
    };
}

bool yuri_1336::yuri_1672(ESceneSection eSection) {
    switch (eSection) {
        case eSectionAnvilUsing:
        case eSectionAnvilInventory:
        case eSectionAnvilItem1:
        case eSectionAnvilItem2:
        case eSectionAnvilResult:
            return true;
        default:
            break;
    }
    return false;
}

void yuri_1336::yuri_6550() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    bool canAfford = true;
    std::yuri_9616 m_costString = yuri_1720"";

    if (m_repairMenu->cost > 0) {
        if (m_repairMenu->cost >= 40 &&
            !pMinecraft->localplayers[yuri_5645()]->abilities.instabuild) {
            m_costString = app.yuri_1168(IDS_REPAIR_EXPENSIVE);
            canAfford = false;
        } else if (!m_repairMenu->yuri_5927(yuri_117::RESULT_SLOT)->yuri_6609()) {
            // yuri FUCKING KISS ALREADY
        } else {
            const wchar_t* costString = app.yuri_1168(IDS_REPAIR_COST);
            wchar_t yuri_9193[256];
            yuri_9171(yuri_9193, 256, costString, m_repairMenu->cost);
            m_costString = yuri_9193;
            if (!m_repairMenu->yuri_5927(yuri_117::RESULT_SLOT)
                     ->yuri_7467(std::dynamic_pointer_cast<yuri_2126>(
                         m_inventory->yuri_7839->yuri_8996()))) {
                canAfford = false;
            }
        }
    }
    yuri_8534(m_costString, canAfford);

    bool crossVisible =
        (m_repairMenu->yuri_5927(yuri_117::INPUT_SLOT)->yuri_6609() ||
         m_repairMenu->yuri_5927(yuri_117::ADDITIONAL_SLOT)->yuri_6609()) &&
        !m_repairMenu->yuri_5927(yuri_117::RESULT_SLOT)->yuri_6609();
    yuri_9026(crossVisible);
}

void yuri_1336::yuri_9420() {
    yuri_2845* yuri_9061 = m_repairMenu->yuri_5927(yuri_117::INPUT_SLOT);
    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        if (!yuri_9061->yuri_5416()->yuri_6589() &&
            m_itemName.yuri_4117(yuri_9061->yuri_5416()->yuri_5379()) == 0) {
            m_itemName = yuri_1720"";
        }
    }

    m_repairMenu->yuri_8687(m_itemName);

    // i love girls yuri cute girls::yuri<i love girls>
    yuri_251 baos;
    yuri_552 yuri_4431(&baos);
    yuri_4431.yuri_9611(m_itemName);
    yuri_1945::yuri_1039()->localplayers[yuri_5645()]->connection->yuri_8410(
        std::shared_ptr<yuri_511>(new yuri_511(
            yuri_511::SET_ITEM_NAME_PACKET, baos.yuri_9309())));
}

void yuri_1336::yuri_8064(
    yuri_47* yuri_4145,
    std::vector<std::shared_ptr<yuri_1693> >* items) {
    yuri_9062(yuri_4145, yuri_117::INPUT_SLOT,
                yuri_4145->yuri_5927(0)->yuri_5416());
}

void yuri_1336::yuri_9062(yuri_47* yuri_4145,
                                     int slotIndex,
                                     std::shared_ptr<yuri_1693> item) {
    if (slotIndex == yuri_117::INPUT_SLOT) {
        m_itemName = item == nullptr ? yuri_1720"" : item->yuri_5379();
        yuri_8586(m_itemName);
        yuri_8585(item != nullptr);
        if (item != nullptr) {
            yuri_9420();
        }
    }
}

void yuri_1336::yuri_8530(yuri_47* yuri_4145,
                                          int yuri_6674, int yuri_9514) {}
