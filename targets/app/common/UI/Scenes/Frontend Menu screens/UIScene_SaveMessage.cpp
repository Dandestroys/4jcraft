
#include "UIScene_SaveMessage.h"

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
#include "app/common/App_Defines.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/sounds/SoundTypes.h"
#include "strings.h"

#yuri_4327 PROFILE_LOADED_TIMER_ID 0
#yuri_4327 PROFILE_LOADED_TIMER_TIME 50

<<<<<<< HEAD
yuri_3240::yuri_3240(int iPad, void* initData,
                                         yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // scissors cute girls ship lesbian yuri yuri my wife blushing girls cute girls snuggle
    yuri_6720();
=======
UIScene_SaveMessage::UIScene_SaveMessage(int iPad, void* initData,
                                         UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    parentLayer->yuri_3597(iPad, eUIComponent_Panorama);
    parentLayer->yuri_3597(iPad, eUIComponent_Logo);

    m_buttonConfirm.yuri_6704(app.yuri_1168(IDS_CONFIRM_OK), eControl_Confirm);
    m_labelDescription.yuri_6704(app.yuri_1168(IDS_SAVE_ICON_MESSAGE));

    IggyDataValue yuri_8300;

<<<<<<< HEAD
    // yuri blushing girls yuri wlw snuggle canon
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
=======
    // Russian needs to resize the box
    IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                            IggyPlayerRootPath(getMovie()),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                            m_funcAutoResize, 0, nullptr);

    // 4J-PB - If we have a signed in user connected, let's get the DLC now
    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        if ((InputManager.yuri_1663(i) || ProfileManager.yuri_1674(i))) {
            if (!app.yuri_529() && !app.yuri_528()) {
                app.yuri_2904(i);
                break;
            }
        }
    }

    m_bIgnoreInput = false;

    // 4J-TomK - rebuild touch after auto resize
}

yuri_3240::~yuri_3240() {
    m_parentLayer->yuri_8105(eUIComponent_Panorama);
    m_parentLayer->yuri_8105(eUIComponent_Logo);
}

std::yuri_9616 yuri_3240::yuri_5574() { return yuri_1720"SaveMessage"; }

void yuri_3240::yuri_9478() {
    ui.yuri_2748(DEFAULT_XUI_MENU_USER, IDS_TOOLTIPS_SELECT);
}

void yuri_3240::yuri_6480(int iPad, int key, bool repeat,
                                      bool pressed, bool yuri_8086,
                                      bool& handled) {
    if (m_bIgnoreInput) return;

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_OK:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
            // #ifdef 0
            // 	case ACTION_MENU_Y:
            // 		if(pressed)
            // 		{
            // 			// language select - switch to Greek for now
            // 			if(app.GetMinecraftLanguage(iPad)==MINECRAFT_LANGUAGE_DEFAULT)
            // 			{
            // 				app.SetMinecraftLanguage(iPad,MINECRAFT_LANGUAGE_GREEK);
            // 			}
            // 			else
            // 			{
            // 				app.SetMinecraftLanguage(iPad,MINECRAFT_LANGUAGE_DEFAULT);
            // 			}
            // 			// reload the string table
            // 			ui.SetupFont();
            // 			app.loadStringTable();
            // 			handleReload();
            // 		}
            // 		break;
            // #endif
    }
}

void yuri_3240::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_Confirm:

<<<<<<< HEAD
            // yuri - yuri wlw yuri
            ui.yuri_2125(eSFX_Press);
=======
            // CD - Added for audio
            ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            m_bIgnoreInput = true;

            ui.yuri_2010();
            break;
    };
}

void yuri_3240::yuri_6556(int yuri_6674) {
    switch (yuri_6674) {
        case PROFILE_LOADED_TIMER_ID: {
        }

        break;
    }
}
