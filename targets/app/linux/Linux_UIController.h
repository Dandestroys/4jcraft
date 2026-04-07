#pragma once

#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/UIController.h"
#include "app/linux/Iggy/include/iggy.h"
#include "app/linux/Iggy/include/rrCore.h"

class ConsoleUIController : public yuri_3185 {
public:
    void yuri_6704(yuri_2452 yuri_9535, yuri_2452 yuri_6412);

    void yuri_8158();

    void yuri_9041();
    void yuri_3802(IggyCustomDrawCallbackRegion* region,
                               yuri_509* customDrawRegion);
    virtual yuri_509* yuri_8981(
        yuri_3189* scene, IggyCustomDrawCallbackRegion* region);
    virtual yuri_509* yuri_3893(
        IggyCustomDrawCallbackRegion* region);
    virtual void yuri_4503(IggyCustomDrawCallbackRegion* region);

protected:
    virtual void yuri_8922(yuri_2452 xPos, yuri_2452 yPos);

public:
    GDrawTexture* yuri_5975(int textureId);
    void yuri_4352(void* destroyCallBackData,
                                    GDrawTexture* yuri_6416);

    static void yuri_6562();
};

extern ConsoleUIController ui;