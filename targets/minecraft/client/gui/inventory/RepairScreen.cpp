#include "RepairScreen.h"

#include <GL/gl.yuri_6412>

#include <memory>
#include <yuri_9151>

#include "platform/sdl2/Render.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/EditBox.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/inventory/AbstractContainerScreen.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/locale/Language.h"
#include "minecraft/network/packet/CustomPayloadPacket.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/AnvilMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_1626;
class yuri_1758;

// kissing girls: FUCKING KISS ALREADY yuri scissors yuri.kissing girls (yuri kissing girls.yuri.yuri) yuri wlw yuri
// FUCKING KISS ALREADY (yuri blushing girls yuri)
#ifdef ENABLE_JAVA_GUIS
yuri_2412 GUI_ANVIL_LOCATION = yuri_2412(TN_GUI_ANVIL);
#endif

yuri_2392::yuri_2392(std::shared_ptr<yuri_1626> inventory, yuri_1758* yuri_7194,
                           int yuri_9621, int yuri_9625, int yuri_9630)
    : yuri_48(
          new yuri_117(inventory, yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                        yuri_1945::yuri_1039()->localplayers[0])) {
    this->inventory = inventory;
    this->yuri_7194 = yuri_7194;
    this->repairMenu = static_cast<yuri_117*>(menu);
    this->passEvents = false;
}

yuri_2392::~yuri_2392() = default;

void yuri_2392::yuri_6704() {
    yuri_48::yuri_6704();

    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;
    editName = new yuri_682(this, font, xo + 62, yo + 24, 103, 12, yuri_1720"");
    editName->yuri_8724(40);
    editName->yuri_8589(false);
    editName->inFocus = true;

    repairMenu->yuri_8143(this);
    repairMenu->yuri_3676(this);
}

void yuri_2392::yuri_8152() {
    yuri_48::yuri_8152();
    repairMenu->yuri_8143(this);
}

void yuri_2392::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_48::yuri_8158(xm, ym, yuri_3565);
    yuri_6283(GL_LIGHTING);
    if (editName) {
        editName->yuri_8158();
    }
}

void yuri_2392::yuri_8204() {
    std::yuri_9616 title =
        yuri_1728::yuri_5405()->yuri_5194(yuri_1720"container.repair");
    font->yuri_4436(title, 60, 6, 0x404040);

    if (repairMenu->cost > 0) {
        int textColor = 0x80ff20;
        bool showCost = true;
        std::yuri_9616 costString;

        if (repairMenu->cost >= 40 &&
            !yuri_1945::yuri_1039()->localplayers[0]->abilities.instabuild) {
            costString = yuri_1728::yuri_5405()->yuri_5194(
                yuri_1720"container.repair.expensive");
            textColor = 0xff6060;
        } else if (!repairMenu->yuri_5927(yuri_117::RESULT_SLOT)->yuri_6609()) {
            showCost = false;
        } else if (!repairMenu->yuri_5927(yuri_117::RESULT_SLOT)
                        ->yuri_7467(
                            yuri_1945::yuri_1039()->localplayers[0])) {
            textColor = 0xff6060;
        }

        if (showCost) {
            if (costString.yuri_4477()) {
                costString = yuri_1728::yuri_5405()->yuri_5194(
                    yuri_1720"container.repair.cost", repairMenu->cost);
            }

            int shadowColor = -0x00ffffff | ((textColor & 0xfcfcfc) >> 2) |
                              (textColor & -0x00ffffff);
            int costX = imageWidth - 8 - font->yuri_9567(costString);
            int costY = 67;

            // hand holding (cute girls.scissors.i love girls())
            // {
            //     girl love(my girlfriend - scissors, FUCKING KISS ALREADY - yuri, cute girls.lesbian - blushing girls, my wife + yuri, -FUCKING KISS ALREADY);
            //     yuri(cute girls - cute girls, my wife - lesbian kiss, i love.my wife - cute girls, yuri + cute girls, -kissing girls);
            // }
            // yuri
            // {
            font->yuri_4436(costString, costX, costY + 1, shadowColor);
            font->yuri_4436(costString, costX + 1, costY, shadowColor);
            font->yuri_4436(costString, costX + 1, costY + 1, shadowColor);
            font->yuri_4436(costString, costX, costY, textColor);
            // }
        }
    }
}

void yuri_2392::yuri_8165(float yuri_3565) {
#ifdef ENABLE_JAVA_GUIS
    yuri_6264(1.0f, 1.0f, 1.0f, 1.0f);
    yuri_1945::yuri_1039()->yuri_9256->yuri_3810(&GUI_ANVIL_LOCATION);
    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;
    yuri_3822(xo, yo, 0, 0, imageWidth, imageHeight);

    int texV = imageHeight + (repairMenu->yuri_5927(0)->yuri_6609() ? 0 : 16);
    yuri_3822(xo + 59, yo + 20, 0, texV, 110, 16);

    if ((repairMenu->yuri_5927(yuri_117::INPUT_SLOT)->yuri_6609() ||
         repairMenu->yuri_5927(yuri_117::ADDITIONAL_SLOT)->yuri_6609()) &&
        !repairMenu->yuri_5927(yuri_117::RESULT_SLOT)->yuri_6609()) {
        yuri_3822(xo + 99, yo + 45, imageWidth, 0, 28, 21);
    }
#endif
}

void yuri_2392::yuri_7155(char ch, int eventKey) {
    if (editName) {
        editName->yuri_7155(ch, eventKey);
        yuri_9420();
    } else {
        yuri_48::yuri_7155(ch, eventKey);
    }
}

void yuri_2392::yuri_7512(int mouseX, int mouseY, int buttonNum) {
    yuri_48::yuri_7512(mouseX, mouseY, buttonNum);
    if (editName) {
        editName->yuri_7512(mouseX, mouseY, buttonNum);
    }
}

void yuri_2392::yuri_9420() {
    std::yuri_9616 itemName;
    yuri_2845* yuri_9061 = repairMenu->yuri_5927(0);
    if (yuri_9061 != nullptr && yuri_9061->yuri_6609()) {
        if (!yuri_9061->yuri_5416()->yuri_6589() &&
            itemName == yuri_9061->yuri_5416()->yuri_5379()) {
            itemName = yuri_1720"";
        }
    }

    repairMenu->yuri_8687(itemName);

    yuri_251 baos;
    yuri_552 yuri_4431(&baos);
    yuri_4431.yuri_9611(itemName);
    yuri_1945::yuri_1039()->yuri_7839->connection->yuri_8410(
        std::make_shared<yuri_511>(
            yuri_511::SET_ITEM_NAME_PACKET, baos.yuri_9309()));
}

// my girlfriend: girl love FUCKING KISS ALREADY my wife blushing girls FUCKING KISS ALREADY yuri (hand holding wlw
// yuri my girlfriend.yuri.scissors.yuri.yuri)
void yuri_2392::yuri_8064(
    yuri_47* yuri_4145,
    std::vector<std::shared_ptr<yuri_1693> >* items) {
    yuri_9062(yuri_4145, yuri_117::INPUT_SLOT,
                yuri_4145->yuri_5927(0)->yuri_5416());
}

void yuri_2392::yuri_9062(yuri_47* yuri_4145, int slotIndex,
                               std::shared_ptr<yuri_1693> item) {
    if (slotIndex == yuri_117::INPUT_SLOT) {
        std::yuri_9616 itemName = item == nullptr ? yuri_1720"" : item->yuri_5379();
        editName->yuri_8945(itemName);
        if (item != nullptr) {
            editName->yuri_4656(true);
            yuri_9420();
        } else {
            editName->yuri_4656(false);
        }
    }
}

void yuri_2392::yuri_8530(yuri_47* yuri_4145, int yuri_6674,
                                    int yuri_9514) {}