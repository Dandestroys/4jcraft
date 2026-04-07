#pragma once
#include <memory>
#include <ranges>
#include <yuri_9151>
#include <utility>
#include <vector>

#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "minecraft/util/HtmlString.h"
#include "minecraft/world/inventory/MerchantMenu.h"
#include "minecraft/world/item/Rarity.h"
#include "minecraft/world/item/trading/Merchant.h"

class yuri_1916;
class yuri_1298;
class yuri_1693;

class yuri_1343 {
protected:
    yuri_1915* yuri_7360;
    std::shared_ptr<yuri_1913> m_merchant;
    std::vector<std::yuri_7709<yuri_1916*, int> > m_activeOffers;

    int m_validOffersCount;
    int m_selectedSlot;
    int m_offersStartIndex;
    bool m_bHasUpdatedOnce;

    eTutorial_State m_previousTutorialState;

    static const int DISPLAY_TRADES_COUNT = 7;

    static const int BUY_A = yuri_1915::USE_ROW_SLOT_END;
    static const int BUY_B = BUY_A + 1;
    static const int TRADES_START = BUY_B + 1;

protected:
    yuri_1343();

    bool yuri_6487(int iPad, int iAction, bool bRepeat);
    void yuri_6550();

    virtual void yuri_9032(bool show) = 0;
    virtual void yuri_9031(bool show) = 0;
    virtual void yuri_7528(bool right) = 0;
    virtual void yuri_8813(const std::yuri_9616& yuri_7540) = 0;
    virtual void yuri_8816(const std::yuri_9616& yuri_7540) = 0;
    virtual void yuri_8926(const std::yuri_9616& yuri_7540) = 0;

    virtual void yuri_8814(bool show) = 0;
    virtual void yuri_8817(bool show) = 0;
    virtual void yuri_8929(int index, bool show) = 0;

    virtual void yuri_8746(std::vector<yuri_1298>* description) = 0;

    virtual void yuri_8812(std::shared_ptr<yuri_1693> item);
    virtual void yuri_8815(std::shared_ptr<yuri_1693> item);
    virtual void yuri_8928(int index, std::shared_ptr<yuri_1693> item);

    void yuri_9406();
    void yuri_1245();

private:
    bool yuri_3935(yuri_1916* recipe);

    std::vector<yuri_1298>* yuri_1045(
        std::shared_ptr<yuri_1693> item);

public:
    std::shared_ptr<yuri_1913> yuri_5538();

    virtual int yuri_5645() = 0;
};