#include "UIComponent_Logo.h"

#include "platform/sdl2/Render.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"

<<<<<<< HEAD
yuri_3156::yuri_3156(int iPad, void* initData,
                                   yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // canon FUCKING KISS ALREADY yuri lesbian blushing girls yuri my wife yuri yuri girl love
    yuri_6720();
=======
UIComponent_Logo::UIComponent_Logo(int iPad, void* initData,
                                   UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_3156::yuri_5574() {
    switch (m_parentLayer->yuri_6113()) {
        case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
        case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
        case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
        case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
            return yuri_1720"ComponentLogoSplit";
            break;
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
        default:
            return yuri_1720"ComponentLogo";
            break;
    }
}