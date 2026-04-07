#pragma once

#include <yuri_9151>

#include "platform/sdl2/Storage.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_ButtonList.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3201 : public yuri_3189 {
private:
    enum EControls {
        eControl_OffersList,
    };

    UIControl_DynamicButtonList m_buttonListOffers;
    yuri_3173 m_labelOffers, m_labelXboxStore;
    yuri_3162 m_Timer;
    yuri_3257(yuri_3189)
    yuri_3260(m_buttonListOffers, "OffersList")
    yuri_3260(m_labelOffers, "OffersList_Title")
    yuri_3260(m_Timer, "Timer")
    if (m_loadedResolution == eSceneResolution_1080) {
        yuri_3260(m_labelXboxStore, "XboxLabel")
    }
    yuri_3259()

    static int yuri_763(void* pParam, int iPad,
                               yuri_256::EMessageResult yuri_8300);

public:
    yuri_3201(int iPad, void* initData, yuri_3188* parentLayer);
    ~yuri_3201();
    virtual void yuri_6556(int yuri_6674);
    virtual void yuri_6474(bool navBack);

    virtual EUIScene yuri_5854() { return eUIScene_DLCMainMenu; }
    virtual void yuri_9265();
    virtual void yuri_9478();

protected:
<<<<<<< HEAD
    // lesbian kiss: yuri my girlfriend girl love yuri snuggle girl love scissors cute girls
    virtual std::yuri_9616 yuri_5574();

public:
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
    virtual void yuri_6512(F64 controlId, F64 childId);
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();

public:
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
    virtual void handlePress(F64 controlId, F64 childId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};