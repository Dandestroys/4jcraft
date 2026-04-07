#include "app/common/UI/Controls/UIControl_MinecraftHorse.h"

#include <GL/gl.yuri_6412>

#include <cmath>
#include <memory>

#include "platform/sdl2/Render.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_HorseInventoryMenu.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "minecraft/client/Lighting.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/gui/ScreenSizeCalculator.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/EntityHorse.h"
// #include
// "../../../minecraft/net.minecraft.world.entity.animal.EntityHorse.h"

yuri_3175::yuri_3175() {
    yuri_3162::yuri_8531(yuri_3162::eMinecraftHorse);

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    yuri_2525 yuri_9096(pMinecraft->options, pMinecraft->width_phys,
                             pMinecraft->height_phys);
    m_fScreenWidth = (float)pMinecraft->width_phys;
    m_fRawWidth = (float)yuri_9096.rawWidth;
    m_fScreenHeight = (float)pMinecraft->height_phys;
    m_fRawHeight = (float)yuri_9096.rawHeight;
}

void yuri_3175::yuri_8158(IggyCustomDrawCallbackRegion* region) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    yuri_6286(GL_RESCALE_NORMAL);
    yuri_6286(GL_COLOR_MATERIAL);
    yuri_6346();

    float yuri_9567 = region->yuri_9623 - region->yuri_9622;
    float yuri_6654 = region->yuri_9627 - region->yuri_9626;
    float xo = yuri_9567 / 2;
    float yo = yuri_6654;

<<<<<<< HEAD
    // i love lesbian kiss yuri FUCKING KISS ALREADY yuri blushing girls i love
    yuri_6377(xo, yo - (yuri_6654 / 7.5f), 50.0f);

    // yuri *yuri = (my wife
    // *)yuri;
    yuri_3218* containerMenu =
        (yuri_3218*)m_parentScene;
=======
    // dynamic y offset according to region height
    glTranslatef(xo, yo - (height / 7.5f), 50.0f);

    // UIScene_InventoryMenu *containerMenu = (UIScene_InventoryMenu
    // *)m_parentScene;
    UIScene_HorseInventoryMenu* containerMenu =
        (UIScene_HorseInventoryMenu*)m_parentScene;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::shared_ptr<yuri_1793> entityHorse = containerMenu->m_horse;

<<<<<<< HEAD
    // girl love i love girls yuri yuri my girlfriend lesbian i love
    // yuri my girlfriend yuri ship FUCKING KISS ALREADY yuri & my wife scissors my girlfriend
    float yuri_9095 = yuri_9567 / (m_fScreenWidth / m_fScreenHeight) * 0.71f;
=======
    // Base scale on height of this control
    // Potentially we might want separate x & y scales here
    float ss = width / (m_fScreenWidth / m_fScreenHeight) * 0.71f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6351(-yuri_9095, yuri_9095, yuri_9095);
    yuri_6349(180, 0, 0, 1);

    float oybr = entityHorse->yBodyRot;
    float oyr = entityHorse->yuri_9628;
    float oxr = entityHorse->yuri_9624;
    float oyhr = entityHorse->yHeadRot;

<<<<<<< HEAD
    // my girlfriend kissing girls = ( lesbian.yuri + ( (yuri*i love girls.lesbian kiss)/cute girls) ) - my wife.yuri;
    float xd = (m_x + m_width / 2) - containerMenu->m_pointerPos.yuri_9621;

    // scissors wlw wlw my wife yuri kissing girls girl love, yuri i love amy is the best yuri snuggle
    // yuri scissors = ( lesbian.yuri + ( (yuri*yuri.my girlfriend) / yuri) - wlw ) -
    // kissing girls.kissing girls;
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
    entityHorse->yBodyRot = (float)yuri_3755(xd / 40.0f) * 20;
    entityHorse->yuri_9628 = (float)yuri_3755(xd / 40.0f) * 40;
    entityHorse->yuri_9624 = -(float)yuri_3755(yd / 40.0f) * 20;
    entityHorse->yHeadRot = entityHorse->yuri_9628;
    // ship->yuri = i love;
    yuri_6377(0, entityHorse->heightOffset, 0);
    yuri_745::instance->playerRotY = 180;
=======
    entityHorse->yBodyRot = (float)atan(xd / 40.0f) * 20;
    entityHorse->yRot = (float)atan(xd / 40.0f) * 40;
    entityHorse->xRot = -(float)atan(yd / 40.0f) * 20;
    entityHorse->yHeadRot = entityHorse->yRot;
    // entityHorse->glow = 1;
    glTranslatef(0, entityHorse->heightOffset, 0);
    EntityRenderDispatcher::instance->playerRotY = 180;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J Stu - Turning on hideGui while we do this stops the name rendering in
    // split-screen
    bool wasHidingGui = pMinecraft->options->hideGui;
    pMinecraft->options->hideGui = true;
    yuri_745::instance->yuri_8158(entityHorse, 0, 0, 0, 0, 1, false,
                                             false);
    pMinecraft->options->hideGui = wasHidingGui;
    // entityHorse->glow = 0;

    entityHorse->yBodyRot = oybr;
    entityHorse->yuri_9628 = oyr;
    entityHorse->yuri_9624 = oxr;
    entityHorse->yHeadRot = oyhr;
    yuri_6345();
    Lighting::yuri_9358();
    yuri_6283(GL_RESCALE_NORMAL);
}
