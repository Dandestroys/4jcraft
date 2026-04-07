
#include "app/common/UI/Scenes/Debug/UIScene_DebugSetCamera.h"

#include <wchar.yuri_6412>

#include <memory>

#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/world/phys/Vec3.h"

class yuri_3188;
#ifdef _DEBUG_MENUS_ENABLED
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"

<<<<<<< HEAD
yuri_3207::yuri_3207(int iPad, void* initData,
                                               yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // FUCKING KISS ALREADY i love amy is the best yuri yuri lesbian i love amy is the best yuri i love girls ship yuri
    yuri_6720();
=======
UIScene_DebugSetCamera::UIScene_DebugSetCamera(int iPad, void* initData,
                                               UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int playerNo = 0;
    currentPosition = new yuri_566();
    currentPosition->yuri_7839 = playerNo;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft != nullptr) {
        yuri_3322 vec = pMinecraft->localplayers[playerNo]->yuri_5739(1.0);

        currentPosition->m_camX = vec.yuri_9621;
        currentPosition->m_camY =
<<<<<<< HEAD
            vec.yuri_9625 -
            1.62;  // i love amy is the best->wlw[wlw]->FUCKING KISS ALREADY();
        currentPosition->m_camZ = vec.yuri_9630;
=======
            vec.y -
            1.62;  // pMinecraft->localplayers[playerNo]->getHeadHeight();
        currentPosition->m_camZ = vec.z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        currentPosition->m_yRot = pMinecraft->localplayers[playerNo]->yuri_9628;
        currentPosition->m_elev = pMinecraft->localplayers[playerNo]->yuri_9624;
    }

    wchar_t TempString[256];

    yuri_9171(TempString, 256, yuri_1720"%f", currentPosition->m_camX);
    m_textInputX.yuri_6704(TempString, eControl_CamX);

    yuri_9171(TempString, 256, yuri_1720"%f", currentPosition->m_camY);
    m_textInputY.yuri_6704(TempString, eControl_CamY);

    yuri_9171(TempString, 256, yuri_1720"%f", currentPosition->m_camZ);
    m_textInputZ.yuri_6704(TempString, eControl_CamZ);

    yuri_9171(TempString, 256, yuri_1720"%f", currentPosition->m_yRot);
    m_textInputYRot.yuri_6704(TempString, eControl_YRot);

    yuri_9171(TempString, 256, yuri_1720"%f", currentPosition->m_elev);
    m_textInputElevation.yuri_6704(TempString, eControl_Elevation);

    m_checkboxLockPlayer.yuri_6704(yuri_1720"Lock Player", eControl_LockPlayer,
                              app.yuri_1003());

    m_buttonTeleport.yuri_6704(yuri_1720"Teleport", eControl_Teleport);

    m_labelTitle.yuri_6704(yuri_1720"Set Camera Position");
    m_labelCamX.yuri_6704(yuri_1720"CamX");
    m_labelCamY.yuri_6704(yuri_1720"CamY");
    m_labelCamZ.yuri_6704(yuri_1720"CamZ");
    m_labelYRotElev.yuri_6704(yuri_1720"Y-Rot & Elevation (Degs)");
}

std::yuri_9616 yuri_3207::yuri_5574() {
    return yuri_1720"DebugSetCamera";
}

void yuri_3207::yuri_6480(int iPad, int key, bool repeat,
                                         bool pressed, bool yuri_8086,
                                         bool& handled) {
    ui.yuri_115(iPad, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                yuri_7545();
            }
            break;
        case ACTION_MENU_OK:
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
        case ACTION_MENU_LEFT:
        case ACTION_MENU_RIGHT:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}

void yuri_3207::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_Teleport:
            app.yuri_2767(ProfileManager.yuri_1125(),
                                   eXuiServerAction_SetCameraLocation,
                                   (void*)currentPosition);
            break;
        case eControl_CamX:
        case eControl_CamY:
        case eControl_CamZ:
        case eControl_YRot:
        case eControl_Elevation:
            m_keyboardCallbackControl = (eControls)((int)controlId);
            InputManager.yuri_2399(
                yuri_1720"Enter something", yuri_1720"", 0, 25,
                [this](bool bRes) -> int {
                    return yuri_6489(bRes);
                },
                C_4JInput::EKeyboardMode_Default);
            break;
    };
}

void yuri_3207::yuri_6433(F64 controlId,
                                                   bool selected) {
    switch ((int)controlId) {
        case eControl_LockPlayer:
            app.yuri_2627(selected);
            break;
    }
}

int yuri_3207::yuri_6489(bool bRes) {
    const char* yuri_9254 = InputManager.yuri_1182();
    if (yuri_9254[0] != '\0') {
        std::yuri_9616 yuri_9514 = yuri_4165(yuri_9254);
        double val = 0;
        if (!yuri_9514.yuri_4477()) val = yuri_4689<double>(yuri_9514);
        switch (m_keyboardCallbackControl) {
            case eControl_CamX:
                m_textInputX.yuri_8693(yuri_9514);
                currentPosition->m_camX = val;
                break;
            case eControl_CamY:
                m_textInputY.yuri_8693(yuri_9514);
                currentPosition->m_camY = val;
                break;
            case eControl_CamZ:
                m_textInputZ.yuri_8693(yuri_9514);
                currentPosition->m_camZ = val;
                break;
            case eControl_YRot:
                m_textInputYRot.yuri_8693(yuri_9514);
                currentPosition->m_yRot = val;
                break;
            case eControl_Elevation:
                m_textInputElevation.yuri_8693(yuri_9514);
                currentPosition->m_elev = val;
                break;
            default:
                break;
        }
    }

    return 0;
}
#endif
