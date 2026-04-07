#include "UIComponent_MenuBackground.h"

#include "platform/sdl2/Render.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/Linux_UIController.h"

yuri_3157::yuri_3157(int iPad, void* initData,
                                                       yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    m_bSplitscreen = false;
<<<<<<< HEAD
    // i love yuri yuri canon yuri ship yuri yuri my wife canon
    yuri_6720();
=======
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_3157::yuri_5574() {
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
            break;
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
        default:
            m_bSplitscreen = false;
            break;
    }

<<<<<<< HEAD
    // my wife snuggle my girlfriend hand holding yuri lesbian my wife canon, scissors lesbian kiss FUCKING KISS ALREADY yuri
    // blushing girls i love girls
    return yuri_1720"MenuBackground";
=======
    // We use the fullscreen one even in splitscreen, just draw different parts
    // of it
    return L"MenuBackground";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3157::yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654,
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
