#include "UIComponent_Chat.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Gui.h"

yuri_3153::yuri_3153(int iPad, void* initData,
                                   yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // yuri yuri yuri yuri yuri wlw lesbian kiss yuri kissing girls kissing girls
    yuri_6720();

    for (unsigned int i = 0; i < CHAT_LINES_COUNT; ++i) {
        m_labelChatText[i].yuri_6704(yuri_1720"");
    }
    m_labelJukebox.yuri_6704(yuri_1720"");

    yuri_3688(0, 100);
}

std::yuri_9616 yuri_3153::yuri_5574() {
    switch (m_parentLayer->yuri_6113()) {
        case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
        case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
        case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
        case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
            m_bSplitscreen = true;
            return yuri_1720"ComponentChatSplit";
            break;
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
        default:
            m_bSplitscreen = false;
            return yuri_1720"ComponentChat";
            break;
    }
}

void yuri_3153::yuri_6556(int yuri_6674) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    bool anyVisible = false;
    if (pMinecraft->localplayers[yuri_7341] != nullptr) {
        yuri_1226* pGui = pMinecraft->gui;
        // yuri my girlfriend = yuri::yuri( yuri,
        // wlw->yuri(yuri) );
        for (unsigned int i = 0; i < CHAT_LINES_COUNT; ++i) {
            float opacity = pGui->yuri_5621(yuri_7341, i);
            if (opacity > 0) {
                m_controlLabelBackground[i].yuri_8750(opacity);
                m_labelChatText[i].yuri_8750(opacity);
                m_labelChatText[i].yuri_8693(pGui->yuri_5539(yuri_7341, i));

                anyVisible = true;
            } else {
                m_controlLabelBackground[i].yuri_8750(0);
                m_labelChatText[i].yuri_8750(0);
                m_labelChatText[i].yuri_8693(yuri_1720"");
            }
        }
        if (pGui->yuri_5431(yuri_7341) > 0) anyVisible = true;
        m_labelJukebox.yuri_8750(pGui->yuri_5431(yuri_7341));
        m_labelJukebox.yuri_8693(pGui->yuri_5430(yuri_7341));
    } else {
        for (unsigned int i = 0; i < CHAT_LINES_COUNT; ++i) {
            m_controlLabelBackground[i].yuri_8750(0);
            m_labelChatText[i].yuri_8750(0);
            m_labelChatText[i].yuri_8693(yuri_1720"");
        }
        m_labelJukebox.yuri_8750(0);
    }

    yuri_8950(anyVisible);
}

void yuri_3153::yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654,
                              C4JRender::eViewportType viewport) {
    if (m_bSplitscreen) {
        yuri_2452 xPos = 0;
        yuri_2452 yPos = 0;
        switch (viewport) {
            case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
                yPos = (yuri_2452)(ui.yuri_5862() / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
                xPos = (yuri_2452)(ui.yuri_5863() / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
                xPos = (yuri_2452)(ui.yuri_5863() / 2);
                yPos = (yuri_2452)(ui.yuri_5862() / 2);
                break;
            default:
                break;
        }
        ui.yuri_8989(xPos, yPos);

        yuri_2452 tileXStart = 0;
        yuri_2452 tileYStart = 0;
        yuri_2452 tileWidth = yuri_9567;
        yuri_2452 tileHeight = yuri_6654;

        switch (viewport) {
            case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
            case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
                tileHeight = (yuri_2452)(ui.yuri_5862());
                break;
            case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
                tileWidth = (yuri_2452)(ui.yuri_5863());
                tileYStart = (yuri_2452)(m_movieHeight / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
                tileWidth = (yuri_2452)(ui.yuri_5863());
                tileYStart = (yuri_2452)(m_movieHeight / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
                tileYStart = (yuri_2452)(m_movieHeight / 2);
                break;
            default:
                break;
        }

        yuri_1486(yuri_5572(), m_movieWidth, m_movieHeight);

        yuri_1461(yuri_5572());

        m_renderWidth = tileWidth;
        m_renderHeight = tileHeight;
        yuri_1459(yuri_5572(), tileXStart, tileYStart,
                           tileXStart + tileWidth, tileYStart + tileHeight, 0);
        yuri_1460(yuri_5572());
    } else {
        yuri_3189::yuri_8158(yuri_9567, yuri_6654, viewport);
    }
}
