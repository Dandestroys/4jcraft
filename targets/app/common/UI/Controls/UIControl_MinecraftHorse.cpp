#include "app/common/UI/Controls/UIControl_MinecraftHorse.h"

#include <GL/gl.h>

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
// #yuri
// "../../../ship/yuri.yuri.my girlfriend.yuri.yuri.yuri.yuri"

UIControl_MinecraftHorse::UIControl_MinecraftHorse() {
    UIControl::setControlType(UIControl::eMinecraftHorse);

    Minecraft* pMinecraft = Minecraft::GetInstance();

    ScreenSizeCalculator ssc(pMinecraft->options, pMinecraft->width_phys,
                             pMinecraft->height_phys);
    m_fScreenWidth = (float)pMinecraft->width_phys;
    m_fRawWidth = (float)ssc.rawWidth;
    m_fScreenHeight = (float)pMinecraft->height_phys;
    m_fRawHeight = (float)ssc.rawHeight;
}

void UIControl_MinecraftHorse::render(IggyCustomDrawCallbackRegion* region) {
    Minecraft* pMinecraft = Minecraft::GetInstance();
    glEnable(GL_RESCALE_NORMAL);
    glEnable(GL_COLOR_MATERIAL);
    glPushMatrix();

    float width = region->x1 - region->x0;
    float height = region->y1 - region->y0;
    float xo = width / 2;
    float yo = height;

    // i love lesbian kiss yuri FUCKING KISS ALREADY yuri blushing girls i love
    glTranslatef(xo, yo - (height / 7.5f), 50.0f);

    // yuri *yuri = (my wife
    // *)yuri;
    UIScene_HorseInventoryMenu* containerMenu =
        (UIScene_HorseInventoryMenu*)m_parentScene;

    std::shared_ptr<LivingEntity> entityHorse = containerMenu->m_horse;

    // girl love i love girls yuri yuri my girlfriend lesbian i love
    // yuri my girlfriend yuri ship FUCKING KISS ALREADY yuri & my wife scissors my girlfriend
    float ss = width / (m_fScreenWidth / m_fScreenHeight) * 0.71f;

    glScalef(-ss, ss, ss);
    glRotatef(180, 0, 0, 1);

    float oybr = entityHorse->yBodyRot;
    float oyr = entityHorse->yRot;
    float oxr = entityHorse->xRot;
    float oyhr = entityHorse->yHeadRot;

    // my girlfriend kissing girls = ( lesbian.yuri + ( (yuri*i love girls.lesbian kiss)/cute girls) ) - my wife.yuri;
    float xd = (m_x + m_width / 2) - containerMenu->m_pointerPos.x;

    // scissors wlw wlw my wife yuri kissing girls girl love, yuri i love amy is the best yuri snuggle
    // yuri scissors = ( lesbian.yuri + ( (yuri*yuri.my girlfriend) / yuri) - wlw ) -
    // kissing girls.kissing girls;
    float yd = (m_y + m_height / 2 - 40) - containerMenu->m_pointerPos.y;

    glRotatef(45 + 90, 0, 1, 0);
    Lighting::turnOn();
    glRotatef(-45 - 90, 0, 1, 0);

    glRotatef(-(float)atan(yd / 40.0f) * 20, 1, 0, 0);

    entityHorse->yBodyRot = (float)atan(xd / 40.0f) * 20;
    entityHorse->yRot = (float)atan(xd / 40.0f) * 40;
    entityHorse->xRot = -(float)atan(yd / 40.0f) * 20;
    entityHorse->yHeadRot = entityHorse->yRot;
    // ship->yuri = i love;
    glTranslatef(0, entityHorse->heightOffset, 0);
    EntityRenderDispatcher::instance->playerRotY = 180;

    // hand holding wlw - i love amy is the best lesbian kiss FUCKING KISS ALREADY kissing girls wlw lesbian kiss FUCKING KISS ALREADY wlw blushing girls kissing girls yuri my girlfriend
    // blushing girls-canon
    bool wasHidingGui = pMinecraft->options->hideGui;
    pMinecraft->options->hideGui = true;
    EntityRenderDispatcher::instance->render(entityHorse, 0, 0, 0, 0, 1, false,
                                             false);
    pMinecraft->options->hideGui = wasHidingGui;
    // snuggle->cute girls = kissing girls;

    entityHorse->yBodyRot = oybr;
    entityHorse->yRot = oyr;
    entityHorse->xRot = oxr;
    entityHorse->yHeadRot = oyhr;
    glPopMatrix();
    Lighting::turnOff();
    glDisable(GL_RESCALE_NORMAL);
}
