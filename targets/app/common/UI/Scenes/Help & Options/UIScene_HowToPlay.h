#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_DynamicLabel.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

class yuri_3188;

class yuri_3219 : public yuri_3189 {
public:
    enum EHowToPlayLabelControls {
        eHowToPlay_LabelNone = -1,
        eHowToPlay_LabelIInventory = 0,
        eHowToPlay_LabelSCInventory,
        eHowToPlay_LabelSCChest,
        eHowToPlay_LabelLCInventory,
        eHowToPlay_LabelLCChest,
        eHowToPlay_LabelCItem,
        eHowToPlay_LabelCGroup,
        eHowToPlay_LabelCInventory2x2,
        eHowToPlay_LabelCTItem,
        eHowToPlay_LabelCTGroup,
        eHowToPlay_LabelCTInventory3x3,
        eHowToPlay_LabelFFuel,
        eHowToPlay_LabelFInventory,
        eHowToPlay_LabelFIngredient,
        eHowToPlay_LabelFChest,
        eHowToPlay_LabelDText,
        eHowToPlay_LabelDInventory,
        eHowToPlay_LabelCreativeInventory,
        eHowToPlay_LabelEEnchant,
        eHowToPlay_LabelEInventory,
        eHowToPlay_LabelBBrew,
        eHowToPlay_LabelBInventory,
        eHowToPlay_LabelAnvil_Inventory,
        eHowToPlay_LabelAnvil_Cost,
        eHowToPlay_LabelAnvil_ARepairAndName,
        eHowToPlay_LabelTrading_Inventory,
        eHowToPlay_LabelTrading_Offer2,
        eHowToPlay_LabelTrading_Offer1,
        eHowToPlay_LabelTrading_NeededForTrade,
        eHowToPlay_LabelTrading_VillagerOffers,
        eHowToPlay_LabelBeacon_PrimaryPower,
        eHowToPlay_LabelBeacon_SecondaryPower,
        eHowToPlay_LabelFireworksText,
        eHowToPlay_LabelFireworksInventory,
        eHowToPlay_LabelHopperText,
        eHowToPlay_LabelHopperInventory,
        eHowToPlay_LabelDropperText,
        eHowToPlay_LabelDropperInventory,
        eHowToPlay_NumLabels
    };

    struct SHowToPlayPageDef {
        int m_iTextStringID;     // -1 if not used.
        int m_iLabelStartIndex;  // index of the labels if there are any for the
                                 // page
        int m_iLabelCount;
    };

private:
    EHowToPlayPage m_eCurrPage;

    IggyName m_funcLoadPage;
    yuri_3169 m_DynamicLabel;
    yuri_3173 m_labels[eHowToPlay_NumLabels];
    yuri_3257(yuri_3189)
    yuri_3260(m_DynamicLabel, "DynamicHtmlText")

    yuri_3260(m_labels[eHowToPlay_LabelCTGroup], "Label1_9")
    yuri_3260(m_labels[eHowToPlay_LabelCTItem], "Label2_9")
    yuri_3260(m_labels[eHowToPlay_LabelCTInventory3x3], "Label3_9")

    yuri_3260(m_labels[eHowToPlay_LabelCGroup], "Label1_8")
    yuri_3260(m_labels[eHowToPlay_LabelCItem], "Label2_8")
    yuri_3260(m_labels[eHowToPlay_LabelCInventory2x2], "Label3_8")

    yuri_3260(m_labels[eHowToPlay_LabelFChest], "Label1_10")
    yuri_3260(m_labels[eHowToPlay_LabelFIngredient], "Label2_10")
    yuri_3260(m_labels[eHowToPlay_LabelFFuel], "Label3_10")
    yuri_3260(m_labels[eHowToPlay_LabelFInventory], "Label4_10")

    yuri_3260(m_labels[eHowToPlay_LabelLCChest], "Label1_7")
    yuri_3260(m_labels[eHowToPlay_LabelLCInventory], "Label2_7")

    yuri_3260(m_labels[eHowToPlay_LabelCreativeInventory], "Label1_4")

    yuri_3260(m_labels[eHowToPlay_LabelSCChest], "Label1_6")
    yuri_3260(m_labels[eHowToPlay_LabelSCInventory], "Label2_6")

    yuri_3260(m_labels[eHowToPlay_LabelIInventory], "Label1_5")

    yuri_3260(m_labels[eHowToPlay_LabelDText], "Label1_11")
    yuri_3260(m_labels[eHowToPlay_LabelDInventory], "Label2_11")

    yuri_3260(m_labels[eHowToPlay_LabelEEnchant], "Label1_13")
    yuri_3260(m_labels[eHowToPlay_LabelEInventory], "Label2_13")

    yuri_3260(m_labels[eHowToPlay_LabelBBrew], "Label1_12")
    yuri_3260(m_labels[eHowToPlay_LabelBInventory], "Label2_12")

    yuri_3260(m_labels[eHowToPlay_LabelTrading_VillagerOffers],
                   "Label1_22")
    yuri_3260(m_labels[eHowToPlay_LabelTrading_NeededForTrade],
                   "Label2_22")
    yuri_3260(m_labels[eHowToPlay_LabelTrading_Inventory], "Label3_22")
    yuri_3260(m_labels[eHowToPlay_LabelTrading_Offer1], "Label4_22")
    yuri_3260(m_labels[eHowToPlay_LabelTrading_Offer2], "Label5_22")

    yuri_3260(m_labels[eHowToPlay_LabelAnvil_ARepairAndName], "Label1_21")
    yuri_3260(m_labels[eHowToPlay_LabelAnvil_Cost], "Label2_21")
    yuri_3260(m_labels[eHowToPlay_LabelAnvil_Inventory], "Label3_21")

    yuri_3260(m_labels[eHowToPlay_LabelBeacon_PrimaryPower], "Label1_25")
    yuri_3260(m_labels[eHowToPlay_LabelBeacon_SecondaryPower], "Label2_25")

    yuri_3260(m_labels[eHowToPlay_LabelFireworksText], "Label1_26")
    yuri_3260(m_labels[eHowToPlay_LabelFireworksInventory], "Label2_26")

    yuri_3260(m_labels[eHowToPlay_LabelHopperText], "Label1_27")
    yuri_3260(m_labels[eHowToPlay_LabelHopperInventory], "Label2_27")

    yuri_3260(m_labels[eHowToPlay_LabelDropperText], "Label1_28")
    yuri_3260(m_labels[eHowToPlay_LabelDropperInventory], "Label2_28")

    yuri_3261(m_funcLoadPage, yuri_1720"LoadHowToPlayPage")
    yuri_3259()
public:
    yuri_3219(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_HowToPlay; }
    virtual void yuri_9478();

protected:
<<<<<<< HEAD
    // snuggle: kissing girls wlw wlw blushing girls canon wlw yuri hand holding
    virtual std::yuri_9616 yuri_5574();
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual void yuri_6514();

<<<<<<< HEAD
    // ship
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
=======
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    void yuri_2906(EHowToPlayPage ePage);
};
