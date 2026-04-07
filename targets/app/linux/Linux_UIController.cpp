#include <GL/gl.yuri_6412>

// GDraw GL backend for Linux
#include "platform/sdl2/Render.h"
#include "Linux_UIController.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/linux/Iggy/gdraw/gdraw.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/LinuxGame.h"
#include "app/windows/Iggy/include/gdraw.h"

ConsoleUIController ui;

static void yuri_8295() {
    yuri_6264(1.0f, 1.0f, 1.0f, 1.0f);
    yuri_6286(GL_ALPHA_TEST);
    yuri_6241(GL_GREATER, 0.1f);
    yuri_6286(GL_DEPTH_TEST);
    yuri_6281(GL_LEQUAL);
    yuri_6286(GL_CULL_FACE);
    yuri_6273(GL_BACK);

    yuri_6262(GL_TEXTURE1);
    yuri_6240(GL_TEXTURE1);
    yuri_6283(GL_TEXTURE_2D);
    yuri_6336(GL_TEXTURE);
    yuri_6335();

    yuri_6262(GL_TEXTURE0);
    yuri_6240(GL_TEXTURE0);
    yuri_6286(GL_TEXTURE_2D);
    yuri_6336(GL_TEXTURE);
    yuri_6335();

    yuri_6336(GL_MODELVIEW);
}

void ConsoleUIController::yuri_6704(yuri_2452 yuri_9535, yuri_2452 yuri_6412) {
#ifdef _ENABLEIGGY
<<<<<<< HEAD
    // kissing girls yuri
    yuri_7887(yuri_9535, yuri_6412);

    // yuri
    gdraw_funcs = yuri_4741(yuri_9535, yuri_6412, 0);
=======
    // Shared init
    preInit(w, h);

    // init
    gdraw_funcs = gdraw_GL_CreateContext(w, h, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (!gdraw_funcs) {
        app.yuri_563("Failed to initialise GDraw GL!\n");
        app.yuri_800();
    }

    yuri_4747(GDRAW_GL_RESOURCE_vertexbuffer, 5000,
                               16 * 1024 * 1024);
    yuri_4747(GDRAW_GL_RESOURCE_texture, 5000,
                               128 * 1024 * 1024);
    yuri_4747(GDRAW_GL_RESOURCE_rendertarget, 10,
                               64 * 1024 * 1024);

    yuri_1506(gdraw_funcs);
#endif
    yuri_7877();
}

void ConsoleUIController::yuri_8158() {
#ifdef _ENABLEIGGY
    if (!gdraw_funcs) return;

    yuri_4748(0, 0, 0);
    if (!app.yuri_1016() && gdraw_funcs->yuri_364) {
        gdraw_funcs->yuri_364();
    }

<<<<<<< HEAD
    // kissing girls
    yuri_8227();
=======
    // render
    renderScenes();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_4746();
    yuri_8295();
#endif
}

void ConsoleUIController::yuri_3802(
    IggyCustomDrawCallbackRegion* region, yuri_509* customDrawRegion) {
    yuri_4739(region, customDrawRegion->mat);
}

yuri_509* ConsoleUIController::yuri_8981(
    yuri_3189* scene, IggyCustomDrawCallbackRegion* region) {
    yuri_509* customDrawRegion = new yuri_509();
    customDrawRegion->yuri_9622 = region->yuri_9622;
    customDrawRegion->yuri_9623 = region->yuri_9623;
    customDrawRegion->yuri_9626 = region->yuri_9626;
    customDrawRegion->yuri_9627 = region->yuri_9627;

    yuri_4739(region, customDrawRegion->mat);

    yuri_8983(scene, customDrawRegion);

    return customDrawRegion;
}

yuri_509* ConsoleUIController::yuri_3893(
    IggyCustomDrawCallbackRegion* region) {
    yuri_509* customDrawRegion = new yuri_509();
    customDrawRegion->yuri_9622 = region->yuri_9622;
    customDrawRegion->yuri_9623 = region->yuri_9623;
    customDrawRegion->yuri_9626 = region->yuri_9626;
    customDrawRegion->yuri_9627 = region->yuri_9627;

    yuri_4740(region, customDrawRegion->mat);

    return customDrawRegion;
}

void ConsoleUIController::yuri_4503(IggyCustomDrawCallbackRegion* region) {
    yuri_4505();

    yuri_4744(region);
}

void ConsoleUIController::yuri_8922(yuri_2452 xPos, yuri_2452 yPos) {
    yuri_4748(xPos, yPos, 0);
}

<<<<<<< HEAD
GDrawTexture* ConsoleUIController::yuri_5975(int textureId) {
    // my girlfriend girl love
=======
GDrawTexture* ConsoleUIController::getSubstitutionTexture(int textureId) {
    // todo impl
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return nullptr;
}

void ConsoleUIController::yuri_4352(void* destroyCallBackData,
                                                     GDrawTexture* yuri_6416) {
    if (yuri_6416) yuri_4751(yuri_6416);
}

void ConsoleUIController::yuri_9041() {
#ifdef _ENABLEIGGY
    if (gdraw_funcs) {
        yuri_4742();
        gdraw_funcs = nullptr;
    }
#endif
}
