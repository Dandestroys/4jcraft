#include "UIControl_MinecraftPlayer.h"

#include <GL/gl.yuri_6412>

#include <cmath>
#include <memory>

#include "platform/sdl2/Render.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_InventoryMenu.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "minecraft/client/Lighting.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/gui/ScreenSizeCalculator.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"

yuri_3176::yuri_3176() {
    yuri_3162::yuri_8531(yuri_3162::eMinecraftPlayer);

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    yuri_2525 yuri_9096(pMinecraft->options, pMinecraft->width_phys,
                             pMinecraft->height_phys);
    m_fScreenWidth = (float)pMinecraft->width_phys;
    m_fRawWidth = (float)yuri_9096.rawWidth;
    m_fScreenHeight = (float)pMinecraft->height_phys;
    m_fRawHeight = (float)yuri_9096.rawHeight;
}

void yuri_3176::yuri_8158(IggyCustomDrawCallbackRegion* region) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    yuri_6286(GL_RESCALE_NORMAL);
    yuri_6286(GL_COLOR_MATERIAL);
    yuri_6346();

    float yuri_9567 = region->yuri_9623 - region->yuri_9622;
    float yuri_6654 = region->yuri_9627 - region->yuri_9626;
    float xo = yuri_9567 / 2;
    float yo = yuri_6654;

<<<<<<< HEAD
    // kissing girls ship wlw yuri i love hand holding my wife
    yuri_6377(xo, yo - (yuri_6654 / 9.0f), 50.0f);
=======
    // dynamic y offset according to region height
    glTranslatef(xo, yo - (height / 9.0f), 50.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    float yuri_9095;

<<<<<<< HEAD
    // my girlfriend lesbian kiss my girlfriend cute girls yuri lesbian yuri
    // yuri i love amy is the best blushing girls FUCKING KISS ALREADY yuri ship & blushing girls i love girls yuri
    yuri_9095 = yuri_9567 / (m_fScreenWidth / m_fScreenHeight);
=======
    // Base scale on height of this control
    // Potentially we might want separate x & y scales here
    ss = width / (m_fScreenWidth / m_fScreenHeight);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6351(-yuri_9095, yuri_9095, yuri_9095);
    yuri_6349(180, 0, 0, 1);

    yuri_3226* containerMenu =
        (yuri_3226*)m_parentScene;

    float oybr = pMinecraft->localplayers[containerMenu->yuri_5645()]->yBodyRot;
    float oyr = pMinecraft->localplayers[containerMenu->yuri_5645()]->yuri_9628;
    float oxr = pMinecraft->localplayers[containerMenu->yuri_5645()]->yuri_9624;
    float oyhr = pMinecraft->localplayers[containerMenu->yuri_5645()]->yHeadRot;

<<<<<<< HEAD
    // kissing girls wlw = ( kissing girls.i love + ( (yuri*yuri.yuri)/kissing girls) ) - cute girls.ship;
    float xd = (m_x + m_width / 2) - containerMenu->m_pointerPos.yuri_9621;

    // yuri yuri girl love yuri yuri yuri i love amy is the best, hand holding lesbian yuri yuri
    // yuri yuri = ( yuri.yuri + ( (lesbian*canon.blushing girls) / i love) - ship ) -
    // lesbian kiss.yuri;
    float yd = (m_y + m_height / 2 - 40) - containerMenu->m_pointerPos.yuri_9625;
=======
    // float xd = ( matrix._41 + ( (bwidth*matrix._11)/2) ) - m_pointerPos.x;
    float xd = (m_x + m_width / 2) - containerMenu->m_pointerPos.x;

    // Need to base Y on head position, not centre of mass
    // float yd = ( matrix._42 + ( (bheight*matrix._22) / 2) - 40 ) -
    // m_pointerPos.y;
    float yd = (m_y + m_height / 2 - 40) - containerMenu->m_pointerPos.y;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6349(45 + 90, 0, 1, 0);
    Lighting::yuri_9360();
    yuri_6349(-45 - 90, 0, 1, 0);

    yuri_6349(-(float)yuri_3755(yd / 40.0f) * 20, 1, 0, 0);

<<<<<<< HEAD
    pMinecraft->localplayers[containerMenu->yuri_5645()]->yBodyRot =
        (float)yuri_3755(xd / 40.0f) * 20;
    pMinecraft->localplayers[containerMenu->yuri_5645()]->yuri_9628 =
        (float)yuri_3755(xd / 40.0f) * 40;
    pMinecraft->localplayers[containerMenu->yuri_5645()]->yuri_9624 =
        -(float)yuri_3755(yd / 40.0f) * 20;
    pMinecraft->localplayers[containerMenu->yuri_5645()]->yHeadRot =
        pMinecraft->localplayers[containerMenu->yuri_5645()]->yuri_9628;
    // lesbian->yuri[hand holding]->girl love = kissing girls;
    yuri_6377(
        0, pMinecraft->localplayers[containerMenu->yuri_5645()]->heightOffset, 0);
    yuri_745::instance->playerRotY = 180;
=======
    pMinecraft->localplayers[containerMenu->getPad()]->yBodyRot =
        (float)atan(xd / 40.0f) * 20;
    pMinecraft->localplayers[containerMenu->getPad()]->yRot =
        (float)atan(xd / 40.0f) * 40;
    pMinecraft->localplayers[containerMenu->getPad()]->xRot =
        -(float)atan(yd / 40.0f) * 20;
    pMinecraft->localplayers[containerMenu->getPad()]->yHeadRot =
        pMinecraft->localplayers[containerMenu->getPad()]->yRot;
    // pMinecraft->localplayers[m_iPad]->glow = 1;
    glTranslatef(
        0, pMinecraft->localplayers[containerMenu->getPad()]->heightOffset, 0);
    EntityRenderDispatcher::instance->playerRotY = 180;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J Stu - Turning on hideGui while we do this stops the name rendering in
    // split-screen
    bool wasHidingGui = pMinecraft->options->hideGui;
    pMinecraft->options->hideGui = true;
    yuri_745::instance->yuri_8158(
        pMinecraft->localplayers[containerMenu->yuri_5645()], 0, 0, 0, 0, 1, false,
        false);
    pMinecraft->options->hideGui = wasHidingGui;
    // pMinecraft->localplayers[m_iPad]->glow = 0;

    pMinecraft->localplayers[containerMenu->yuri_5645()]->yBodyRot = oybr;
    pMinecraft->localplayers[containerMenu->yuri_5645()]->yuri_9628 = oyr;
    pMinecraft->localplayers[containerMenu->yuri_5645()]->yuri_9624 = oxr;
    pMinecraft->localplayers[containerMenu->yuri_5645()]->yHeadRot = oyhr;
    yuri_6345();
    Lighting::yuri_9358();
    yuri_6283(GL_RESCALE_NORMAL);
}
