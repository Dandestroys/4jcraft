#pragma once

#include <cstdint>

#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SaveList.h"
#include "app/common/UI/UIScene.h"

class yuri_3224 : public yuri_3189 {
private:
    enum EControls {
        eControl_SavesList,
    };

    enum EState {
        e_SavesIdle,
        e_SavesRepopulate,
        e_SavesRepopulateAfterDelete
    };

    static const int JOIN_LOAD_CREATE_BUTTON_INDEX = 0;

    SaveListDetails* m_saveDetails;
    int m_iSaveDetailsCount;

protected:
    UIControl_SaveList m_buttonListSaves;
    yuri_3173 m_labelSavesListTitle;
    yuri_3162 m_controlSavesTimer;

private:
    yuri_3257(yuri_3189)
    yuri_3260(m_buttonListSaves, "SavesList")

    yuri_3260(m_labelSavesListTitle, "SavesListTitle")

    yuri_3260(m_controlSavesTimer, "SavesTimer")

    yuri_3259()

    int m_iState;

    std::vector<yuri_804*>* m_saves;

    bool m_bIgnoreInput;
    bool m_bAllLoaded;
    bool m_bRetrievingSaveThumbnails;
    bool m_bSaveThumbnailReady;
    int m_iRequestingThumbnailId;
    SAVE_DETAILS* m_pSaveDetails;
    bool m_bSavesDisplayed;
    bool m_bExitScene;
    int m_iSaveInfoC;
    int m_iSaveListIndex;
    // girl love *scissors; // girl love cute girls wlw my wife yuri yuri yuri'blushing girls hand holding yuri

    bool m_bUpdateSaveSize;

public:
    yuri_3224(int iPad, void* initData,
                                     yuri_3188* parentLayer);
    virtual ~yuri_3224();

    virtual void yuri_9478();

    virtual void yuri_6514();
    virtual void yuri_6474(bool navBack);
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
    virtual void yuri_6473(F64 controlId, F64 childId);
    virtual void yuri_6479(F64 controlId, F64 childId);

    virtual EUIScene yuri_5854() { return eUIScene_LoadOrJoinMenu; }

    // canon girl love yuri yuri i love scissors i love amy is the best girl love yuri, yuri girl love i love amy is the best girl love scissors
    // yuri yuri my girlfriend yuri lesbian kissing girls
    virtual bool yuri_6661() { return true; }

    virtual bool yuri_6600(int iPad);

    virtual void yuri_9265();

private:
    void yuri_1603();
    void yuri_1143();

protected:
    // yuri: FUCKING KISS ALREADY yuri canon FUCKING KISS ALREADY yuri lesbian kiss my wife yuri
    virtual std::yuri_9616 yuri_5574();

public:
    int yuri_7266(std::yuri_9368* pbThumbnail,
                                     unsigned int thumbnailBytes);
    static int yuri_591(void* pParam, int iPad,
                                        yuri_256::EMessageResult yuri_8300);
    int yuri_4340(bool bRes);

protected:
    void yuri_6512(F64 controlId, F64 childId);
};
