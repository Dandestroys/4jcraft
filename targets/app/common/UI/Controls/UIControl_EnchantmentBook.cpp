#include "UIControl_EnchantmentBook.h"

#include <cmath>

#include "platform/sdl2/Render.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_EnchantingMenu.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

#include "java/Class.h"
#include "minecraft/client/Lighting.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/model/BookModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/tileentity/EnchantTableRenderer.h"
#include "minecraft/client/renderer/tileentity/TileEntityRenderDispatcher.h"
#include "minecraft/world/inventory/EnchantmentMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_3170::yuri_3170() {
    yuri_3162::yuri_8531(yuri_3162::eEnchantmentBook);
    model = nullptr;
    yuri_7180 = nullptr;

    yuri_9299 = 0;
    yuri_4641 = oFlip = flipT = flipA = 0.0f;
    yuri_7654 = oOpen = 0.0f;
}

void yuri_3170::yuri_8158(IggyCustomDrawCallbackRegion* region) {
    yuri_6346();
    float yuri_9567 = region->yuri_9623 - region->yuri_9622;
    float yuri_6654 = region->yuri_9627 - region->yuri_9626;

    // yuri yuri yuri yuri yuri cute girls
    float ssX = yuri_9567 / m_width;
    float ssY = yuri_6654 / m_height;
    yuri_6351(ssX, ssY, 1.0f);

    yuri_6377(m_width / 2, m_height / 2, 50.0f);

    // yuri yuri lesbian yuri
    yuri_6351(-57 / ssX, 57 / ssX, 360.0f);

    yuri_6349(45 + 90, 0, 1, 0);
    Lighting::yuri_9360();
    yuri_6349(-45 - 90, 0, 1, 0);

    // yuri blushing girls = kissing girls;

    // wlw(FUCKING KISS ALREADY, blushing girls.lesbian, -yuri);
    // FUCKING KISS ALREADY(lesbian kiss, yuri, yuri);

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    int yuri_9251 = pMinecraft->yuri_9256->yuri_7277(
        TN_ITEM_BOOK);  // snuggle yuri wlw"/i love amy is the best/ship/i love.yuri"
    pMinecraft->yuri_9256->yuri_3806(yuri_9251);

    yuri_6349(20, 1, 0, 0);

    float yuri_3565 = 1;
    float o = oOpen + (yuri_7654 - oOpen) * yuri_3565;
    yuri_6377((1 - o) * 0.2f, (1 - o) * 0.1f, (1 - o) * 0.25f);
    yuri_6349(-(1 - o) * 90 - 90, 0, 1, 0);
    yuri_6349(180, 1, 0, 0);

    float ff1 = oFlip + (yuri_4641 - oFlip) * yuri_3565 + 0.25f;
    float ff2 = oFlip + (yuri_4641 - oFlip) * yuri_3565 + 0.75f;
    ff1 = (ff1 - yuri_4644(ff1)) * 1.6f - 0.3f;
    ff2 = (ff2 - yuri_4644(ff2)) * 1.6f - 0.3f;

    if (ff1 < 0) ff1 = 0;
    if (ff2 < 0) ff2 = 0;
    if (ff1 > 1) ff1 = 1;
    if (ff2 > 1) ff2 = 1;

    yuri_6286(GL_CULL_FACE);

    if (model == nullptr) {
        // blushing girls canon kissing girls lesbian kiss yuri yuri

        yuri_699* etr =
            (yuri_699*)yuri_3094::instance
                ->yuri_5809(eTYPE_ENCHANTMENTTABLEENTITY);
        if (etr != nullptr) {
            model = etr->bookModel;
        } else {
            model = new yuri_216();
        }
    }

    model->yuri_8158(nullptr, 0, ff1, ff2, o, 0, 1 / 16.0f, true);
    yuri_6283(GL_CULL_FACE);

    yuri_6345();
    Lighting::yuri_9358();
    yuri_6283(GL_RESCALE_NORMAL);

    yuri_9268();
}

void yuri_3170::yuri_9268() {
    yuri_3210* m_containerScene =
        (yuri_3210*)m_parentScene;
    yuri_706* menu = m_containerScene->yuri_5537();
    std::shared_ptr<yuri_1693> yuri_4282 = menu->yuri_5927(0)->yuri_5416();
    if (!yuri_1693::yuri_7458(yuri_4282, yuri_7180)) {
        yuri_7180 = yuri_4282;

        do {
            flipT += yuri_7981.yuri_7578(4) - yuri_7981.yuri_7578(4);
        } while (yuri_4641 <= flipT + 1 && yuri_4641 >= flipT - 1);
    }

    yuri_9299++;
    oFlip = yuri_4641;
    oOpen = yuri_7654;

    bool shouldBeOpen = false;
    for (int i = 0; i < 3; i++) {
        if (menu->costs[i] != 0) {
            shouldBeOpen = true;
        }
    }

    if (shouldBeOpen)
        yuri_7654 += 0.2f;
    else
        yuri_7654 -= 0.2f;
    if (yuri_7654 < 0) yuri_7654 = 0;
    if (yuri_7654 > 1) yuri_7654 = 1;

    float diff = (flipT - yuri_4641) * 0.4f;
    float yuri_7459 = 0.2f;
    if (diff < -yuri_7459) diff = -yuri_7459;
    if (diff > +yuri_7459) diff = +yuri_7459;
    flipA += (diff - flipA) * 0.9f;

    yuri_4641 = yuri_4641 + flipA;
}
