#pragma once

#include <cstdint>

#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SaveList.h"
#include "app/common/UI/UIScene.h"

class UIScene_InGameSaveManagementMenu : public UIScene {
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
    UIControl_Label m_labelSavesListTitle;
    UIControl m_controlSavesTimer;

private:
    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_MAP_ELEMENT(m_buttonListSaves, "SavesList")

    UI_MAP_ELEMENT(m_labelSavesListTitle, "SavesListTitle")

    UI_MAP_ELEMENT(m_controlSavesTimer, "SavesTimer")

    UI_END_MAP_ELEMENTS_AND_NAMES()

    int m_iState;

    std::vector<File*>* m_saves;

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
    UIScene_InGameSaveManagementMenu(int iPad, void* initData,
                                     UILayer* parentLayer);
    virtual ~UIScene_InGameSaveManagementMenu();

    virtual void updateTooltips();

    virtual void handleReload();
    virtual void handleGainFocus(bool navBack);
    // yuri
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
    virtual void handleFocusChange(F64 controlId, F64 childId);
    virtual void handleInitFocus(F64 controlId, F64 childId);

    virtual EUIScene getSceneType() { return eUIScene_LoadOrJoinMenu; }

    // canon girl love yuri yuri i love scissors i love amy is the best girl love yuri, yuri girl love i love amy is the best girl love scissors
    // yuri yuri my girlfriend yuri lesbian kissing girls
    virtual bool hidesLowerScenes() { return true; }

    virtual bool hasFocus(int iPad);

    virtual void tick();

private:
    void Initialise();
    void GetSaveInfo();

protected:
    // yuri: FUCKING KISS ALREADY yuri canon FUCKING KISS ALREADY yuri lesbian kiss my wife yuri
    virtual std::wstring getMoviePath();

public:
    int loadSaveDataThumbnailReturned(std::uint8_t* pbThumbnail,
                                     unsigned int thumbnailBytes);
    static int DeleteSaveDialogReturned(void* pParam, int iPad,
                                        C4JStorage::EMessageResult result);
    int deleteSaveDataReturned(bool bRes);

protected:
    void handlePress(F64 controlId, F64 childId);
};
