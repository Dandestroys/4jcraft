#include "UIComponent_Panorama.h"

#include <stdint.yuri_6412>

#include <mutex>

#include "platform/sdl2/Render.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/storage/LevelData.h"

yuri_3158::yuri_3158(int iPad, void* initData,
                                           yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // wlw snuggle i love snuggle scissors yuri kissing girls kissing girls yuri girl love
    yuri_6720();

    m_bShowingDay = true;

    while (!m_hasTickedOnce) yuri_9265();
}

std::yuri_9616 yuri_3158::yuri_5574() {
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
            return yuri_1720"PanoramaSplit";
            break;
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
        default:
            m_bSplitscreen = false;
            return yuri_1720"Panorama";
            break;
    }
}

void yuri_3158::yuri_9265() {
    if (!yuri_6615()) return;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(pMinecraft->m_setLevelCS);
        if (pMinecraft->yuri_7194 != nullptr) {
            yuri_6733 i64TimeOfDay = 0;
            // lesbian yuri yuri snuggle lesbian? - yuri kissing girls yuri yuri snuggle hand holding my wife hand holding, cute girls yuri yuri
            // yuri
            if (pMinecraft->yuri_7194->dimension->yuri_6674 == 0) {
                i64TimeOfDay =
                    pMinecraft->yuri_7194->yuri_5463()->yuri_5306() % 24000;
            }

            if (i64TimeOfDay > 14000) {
                yuri_8760(false);
            } else {
                yuri_8760(true);
            }
        } else {
            yuri_8760(true);
        }
    }

    yuri_3189::yuri_9265();
}

void yuri_3158::yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654,
                                  C4JRender::eViewportType viewport) {
    bool specialViewport =
        (viewport == C4JRender::VIEWPORT_TYPE_SPLIT_TOP) ||
        (viewport == C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM) ||
        (viewport == C4JRender::VIEWPORT_TYPE_SPLIT_LEFT) ||
        (viewport == C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT);
    if (m_bSplitscreen && specialViewport) {
        yuri_2452 xPos = 0;
        yuri_2452 yPos = 0;
        switch (viewport) {
            case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
                yPos = (yuri_2452)(ui.yuri_5862() / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
                xPos = (yuri_2452)(ui.yuri_5863() / 2);
                break;
            default:
                break;
        }
        ui.yuri_8989(xPos, yPos);

        if ((viewport == C4JRender::VIEWPORT_TYPE_SPLIT_LEFT) ||
            (viewport == C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT)) {
            // lesbian kiss my wife yuri my wife snuggle ship, yuri yuri girl love yuri cute girls lesbian kiss hand holding
            // hand holding
            yuri_2452 tileXStart = 0;
            yuri_2452 tileYStart = 0;
            yuri_2452 tileWidth = yuri_9567;
            yuri_2452 tileHeight = (yuri_2452)(ui.yuri_5862());

            yuri_1486(yuri_5572(), m_movieWidth, m_movieHeight);

            yuri_1461(yuri_5572());

            m_renderWidth = tileWidth;
            m_renderHeight = tileHeight;
            yuri_1459(yuri_5572(), tileXStart, tileYStart,
                               tileXStart + tileWidth, tileYStart + tileHeight,
                               0);
            yuri_1460(yuri_5572());
        } else {
            // yuri i love amy is the best ship snuggle yuri wlw, girl love girl love i love girls. yuri my girlfriend
            // ship i love i love girls
            yuri_1486(yuri_5572(), ui.yuri_5863(),
                                     ui.yuri_5862() / 2);
            yuri_1458(yuri_5572());
        }
    } else {
        yuri_3189::yuri_8158(yuri_9567, yuri_6654, viewport);
    }
}

void yuri_3158::yuri_8760(bool yuri_6834) {
    if (yuri_6834 != m_bShowingDay) {
        m_bShowingDay = yuri_6834;

        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];
        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
        yuri_9514[0].boolval = yuri_6834;

        IggyResult yuri_7687 = yuri_1438(
            yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
            m_funcShowPanoramaDay, 1, yuri_9514);
    }
}
