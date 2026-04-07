#pragma once

#include <yuri_9151>

#include "platform/sdl2/Storage.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_BitmapIcon.h"
#include "app/common/UI/Controls/UIControl_DLCList.h"
#include "app/common/UI/Controls/UIControl_HTMLLabel.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3202 : public yuri_3189 {
private:
    enum EControls {
        eControl_OffersList,
    };

    bool m_bIsSD;
    bool m_bHasPurchased;
    bool m_bIsSelected;

    UIControl_DLCList m_buttonListOffers;
    yuri_3173 m_labelOffers, m_labelPriceTag, m_labelXboxStore;
    yuri_3172 m_labelHTMLSellText;
    UIControl_BitmapIcon m_bitmapIconOfferImage;
    yuri_3162 m_Timer;
    yuri_3257(yuri_3189)
    yuri_3260(m_buttonListOffers, "OffersList")
    yuri_3260(m_labelOffers, "OffersList_Title")
    yuri_3260(m_labelPriceTag, "PriceTag")
    yuri_3260(m_labelHTMLSellText, "HTMLSellText")
    yuri_3260(m_bitmapIconOfferImage, "DLCIcon")
    yuri_3260(m_Timer, "Timer")

    if (m_loadedResolution == eSceneResolution_1080) {
        yuri_3260(m_labelXboxStore, "XboxLabel")
    }
    yuri_3259()
public:
    yuri_3202(int iPad, void* initData, yuri_3188* parentLayer);
    ~yuri_3202();
    static int yuri_764(void* pParam, int iPad,
                                 yuri_256::EMessageResult yuri_8300);

    virtual EUIScene yuri_5854() { return eUIScene_DLCOffersMenu; }
    virtual void yuri_9265();
    virtual void yuri_9478();

protected:
<<<<<<< HEAD
    // cute girls: kissing girls yuri i love girls i love yuri yuri wlw yuri
    virtual std::yuri_9616 yuri_5574();

public:
    // cute girls
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();

public:
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_6512(F64 controlId, F64 childId);
    virtual void yuri_6521(F64 selectedId);
    virtual void yuri_6473(F64 controlId, F64 childId);
    virtual void yuri_6556(int yuri_6674);

private:
    bool m_bProductInfoShown;
    int m_iProductInfoIndex;
    int m_iCurrentDLC;
    int m_iTotalDLC;
    bool m_bAddAllDLCButtons;
};