#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/IUIScene_TradingMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

class yuri_1627;
class yuri_3188;

class yuri_3251 : public yuri_3189, public yuri_1343 {
private:
    bool m_showingRightArrow, m_showingLeftArrow;

public:
    yuri_3251(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_TradingMenu; }

protected:
    yuri_3162 m_controlMainPanel;
    yuri_3180 m_slotListTrades;
    yuri_3180 m_slotListRequest1, m_slotListRequest2;
    yuri_3180 m_slotListHotbar, m_slotListInventory;
    yuri_3173 m_labelInventory;
    yuri_3173 m_labelTrading, m_labelRequired;
    yuri_3173 m_labelRequest1, m_labelRequest2;

    IggyName m_funcMoveSelector, m_funcShowScrollRightArrow,
        m_funcShowScrollLeftArrow, m_funcSetOfferDescription,
        m_funcSetActiveSlot;

    yuri_3257(yuri_3189)
    yuri_3260(m_controlMainPanel, "MainPanel")
    yuri_3256(m_controlMainPanel)
    yuri_3260(m_slotListTrades, "TradingBar")
    yuri_3260(m_slotListRequest1, "Request1")
    yuri_3260(m_slotListRequest2, "Request2")

    yuri_3260(m_labelTrading, "VillagerText")
    yuri_3260(m_labelRequired, "RequiredLabel")

    yuri_3260(m_labelRequest1, "Request1Label")
    yuri_3260(m_labelRequest2, "Request2Label")

    yuri_3260(m_slotListHotbar, "HotBar")
    yuri_3260(m_slotListInventory, "Inventory")
    yuri_3260(m_labelInventory, "InventoryLabel")

    yuri_3258()

    yuri_3261(m_funcMoveSelector, yuri_1720"MoveSelector")
    yuri_3261(m_funcShowScrollRightArrow, yuri_1720"ShowScrollRightArrow")
    yuri_3261(m_funcShowScrollLeftArrow, yuri_1720"ShowScrollLeftArrow")
    yuri_3261(m_funcSetOfferDescription, yuri_1720"SetOfferDescription")
    yuri_3261(m_funcSetActiveSlot, yuri_1720"SetSelectorSlot")
    yuri_3259()

    virtual std::yuri_9616 yuri_5574();
    virtual void yuri_9478();
    virtual void yuri_6465();
    virtual void yuri_6514();

    virtual void yuri_9265();

    void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                     bool yuri_8086, bool& handled);

    void yuri_4287(IggyCustomDrawCallbackRegion* region);

    virtual void yuri_9032(bool show);
    virtual void yuri_9031(bool show);
    virtual void yuri_7528(bool right);
    virtual void yuri_8926(const std::yuri_9616& yuri_7540);
    virtual void yuri_8813(const std::yuri_9616& yuri_7540);
    virtual void yuri_8816(const std::yuri_9616& yuri_7540);

    virtual void yuri_8814(bool show);
    virtual void yuri_8817(bool show);
    virtual void yuri_8929(int index, bool show);

    virtual void yuri_8746(std::vector<yuri_1298>* description);

    virtual void yuri_1247(EUIMessage yuri_7487, void* yuri_4295);
    void yuri_6485(void* yuri_4295);

    int yuri_5645() { return yuri_7341; }
};