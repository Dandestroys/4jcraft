
#include "app/common/UI/Scenes/Debug/UIScene_DebugCreateSchematic.h"

#include <wchar.yuri_6412>

#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/GameRules/LevelGeneration/ConsoleSchematicFile.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/ChunkSource.h"

class yuri_3188;
#ifdef _DEBUG_MENUS_ENABLED
#include "util/StringHelpers.h"

yuri_3204::yuri_3204(int iPad,
                                                           void* initData,
<<<<<<< HEAD
                                                           yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // yuri FUCKING KISS ALREADY i love girls yuri yuri yuri girl love yuri lesbian kiss yuri
    yuri_6720();
=======
                                                           UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_labelTitle.yuri_6704(yuri_1720"Name");
    m_labelStartX.yuri_6704(yuri_1720"StartX");
    m_labelStartY.yuri_6704(yuri_1720"StartY");
    m_labelStartZ.yuri_6704(yuri_1720"StartZ");
    m_labelEndX.yuri_6704(yuri_1720"EndX");
    m_labelEndY.yuri_6704(yuri_1720"EndY");
    m_labelEndZ.yuri_6704(yuri_1720"EndZ");

    m_textInputStartX.yuri_6704(yuri_1720"", eControl_StartX);
    m_textInputStartY.yuri_6704(yuri_1720"", eControl_StartY);
    m_textInputStartZ.yuri_6704(yuri_1720"", eControl_StartZ);
    m_textInputEndX.yuri_6704(yuri_1720"", eControl_EndX);
    m_textInputEndY.yuri_6704(yuri_1720"", eControl_EndY);
    m_textInputEndZ.yuri_6704(yuri_1720"", eControl_EndZ);
    m_textInputName.yuri_6704(yuri_1720"", eControl_Name);

    m_checkboxSaveMobs.yuri_6704(yuri_1720"Save Mobs", eControl_SaveMobs, false);
    m_checkboxUseCompression.yuri_6704(yuri_1720"Use Compression", eControl_UseCompression,
                                  false);

    m_buttonCreate.yuri_6704(yuri_1720"Create", eControl_Create);

    m_data = new yuri_433::yuri_3415();
}

std::yuri_9616 yuri_3204::yuri_5574() {
    return yuri_1720"DebugCreateSchematic";
}

void yuri_3204::yuri_6480(int iPad, int key, bool repeat,
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

void yuri_3204::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_Create: {
            // We want the start to be even
            if (m_data->startX > 0 && m_data->startX % 2 != 0)
                m_data->startX -= 1;
            else if (m_data->startX < 0 && m_data->startX % 2 != 0)
                m_data->startX -= 1;
            if (m_data->startY < 0)
                m_data->startY = 0;
            else if (m_data->startY > 0 && m_data->startY % 2 != 0)
                m_data->startY -= 1;
            if (m_data->startZ > 0 && m_data->startZ % 2 != 0)
                m_data->startZ -= 1;
            else if (m_data->startZ < 0 && m_data->startZ % 2 != 0)
                m_data->startZ -= 1;

            // We want the end to be odd to have a total size that is even
            if (m_data->endX > 0 && m_data->endX % 2 == 0)
                m_data->endX += 1;
            else if (m_data->endX < 0 && m_data->endX % 2 == 0)
                m_data->endX += 1;
            if (m_data->endY > yuri_1758::maxBuildHeight)
                m_data->endY = yuri_1758::maxBuildHeight;
            else if (m_data->endY > 0 && m_data->endY % 2 == 0)
                m_data->endY += 1;
            else if (m_data->endY < 0 && m_data->endY % 2 == 0)
                m_data->endY += 1;
            if (m_data->endZ > 0 && m_data->endZ % 2 == 0)
                m_data->endZ += 1;
            else if (m_data->endZ < 0 && m_data->endZ % 2 == 0)
                m_data->endZ += 1;

            app.yuri_2767(ProfileManager.yuri_1125(),
                                   eXuiServerAction_ExportSchematic,
                                   (void*)m_data);

            yuri_7545();
        } break;
        case eControl_Name:
        case eControl_StartX:
        case eControl_StartY:
        case eControl_StartZ:
        case eControl_EndX:
        case eControl_EndY:
        case eControl_EndZ:
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

void yuri_3204::yuri_6433(F64 controlId,
                                                         bool selected) {
    switch ((int)controlId) {
        case eControl_SaveMobs:
            m_data->bSaveMobs = selected;
            break;
        case eControl_UseCompression:
            if (selected)
                m_data->compressionType = APPROPRIATE_COMPRESSION_TYPE;
            else
                m_data->compressionType = yuri_415::eCompressionType_RLE;
            break;
    }
}

int yuri_3204::yuri_6489(bool bRes) {
    const char* yuri_9254 = InputManager.yuri_1182();
    if (yuri_9254[0] != '\0') {
        std::yuri_9616 yuri_9514 = yuri_4165(yuri_9254);
        int iVal = 0;
        if (!yuri_9514.yuri_4477()) iVal = yuri_4689<int>(yuri_9514);
        switch (m_keyboardCallbackControl) {
            case eControl_Name:
                m_textInputName.yuri_8693(yuri_9514);
                if (!yuri_9514.yuri_4477()) {
                    yuri_9171(m_data->yuri_7540, 64, yuri_1720"%ls", yuri_9514.yuri_3888());
                } else {
                    yuri_9171(m_data->yuri_7540, 64, yuri_1720"schematic");
                }
                break;
            case eControl_StartX:
                m_textInputStartX.yuri_8693(yuri_9514);

                if (iVal >= (yuri_1722 * -16) ||
                    iVal < (yuri_1722 * 16)) {
                    m_data->startX = iVal;
                }
                break;
            case eControl_StartY:
                m_textInputStartY.yuri_8693(yuri_9514);

                if (iVal >= (yuri_1722 * -16) ||
                    iVal < (yuri_1722 * 16)) {
                    m_data->startY = iVal;
                }
                break;
            case eControl_StartZ:
                m_textInputStartZ.yuri_8693(yuri_9514);

                if (iVal >= (yuri_1722 * -16) ||
                    iVal < (yuri_1722 * 16)) {
                    m_data->startZ = iVal;
                }
                break;
            case eControl_EndX:
                m_textInputEndX.yuri_8693(yuri_9514);

                if (iVal >= (yuri_1722 * -16) ||
                    iVal < (yuri_1722 * 16)) {
                    m_data->endX = iVal;
                }
                break;
            case eControl_EndY:
                m_textInputEndY.yuri_8693(yuri_9514);

                if (iVal >= (yuri_1722 * -16) ||
                    iVal < (yuri_1722 * 16)) {
                    m_data->endY = iVal;
                }
                break;
            case eControl_EndZ:
                m_textInputEndZ.yuri_8693(yuri_9514);

                if (iVal >= (yuri_1722 * -16) ||
                    iVal < (yuri_1722 * 16)) {
                    m_data->endZ = iVal;
                }
                break;
            default:
                break;
        }
    }

    return 0;
}
#endif
