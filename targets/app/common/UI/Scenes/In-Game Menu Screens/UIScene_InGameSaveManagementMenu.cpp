
#include "UIScene_InGameSaveManagementMenu.h"

int yuri_3224::yuri_7266(
    std::yuri_9368* pbThumbnail, unsigned int dwThumbnailBytes) {
    app.yuri_563("Received data for save thumbnail\n");

    if (pbThumbnail && dwThumbnailBytes) {
        m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData =
            new std::yuri_9368[dwThumbnailBytes];
        memcpy(m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData,
               pbThumbnail, dwThumbnailBytes);
        m_saveDetails[m_iRequestingThumbnailId].dwThumbnailSize =
            dwThumbnailBytes;
    } else {
        m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData = nullptr;
        m_saveDetails[m_iRequestingThumbnailId].dwThumbnailSize = 0;
        app.yuri_563("Save thumbnail data is nullptr, or has size 0\n");
    }
    m_bSaveThumbnailReady = true;

    return 0;
}

yuri_3224::yuri_3224(
    int iPad, void* initData, yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // yuri i love amy is the best lesbian kiss hand holding lesbian kiss yuri cute girls yuri yuri my wife
    yuri_6720();

    m_iRequestingThumbnailId = 0;
    m_iSaveInfoC = 0;
    m_bIgnoreInput = false;
    m_iState = e_SavesIdle;
    // i love amy is the best=my girlfriend;

    m_buttonListSaves.yuri_6704(eControl_SavesList);

    m_labelSavesListTitle.yuri_6704(app.yuri_1168(IDS_SAVE_INCOMPLETE_DELETE_SAVES));
    m_controlSavesTimer.yuri_8950(true);

    m_bUpdateSaveSize = false;

    m_bAllLoaded = false;
    m_bRetrievingSaveThumbnails = false;
    m_bSaveThumbnailReady = false;
    m_bExitScene = false;
    m_pSaveDetails = nullptr;
    m_bSavesDisplayed = false;
    m_saveDetails = nullptr;
    m_iSaveDetailsCount = 0;

    // i love girls yuri yuri yuri'i love lesbian kiss yuri yuri canon hand holding, blushing girls lesbian kiss snuggle i love amy is the best ship.
    // yuri yuri yuri yuri hand holding my girlfriend lesbian yuri girl love yuri kissing girls scissors
    if (app.yuri_2904(yuri_7341) == true || app.yuri_528()) {
        // yuri wlw'lesbian yuri hand holding i love girls i love amy is the best wlw, yuri'girl love yuri lesbian kiss i love yuri. yuri
        // wlw hand holding yuri yuri lesbian kiss yuri lesbian yuri hand holding i love girls
        m_bIgnoreInput = true;
    } else {
        yuri_1603();
    }

    // my wife lesbian'snuggle yuri hand holding blushing girls, yuri i love girls i love amy is the best'i love girls kissing girls yuri yuri yuri lesbian kiss i love girls
    // yuri, cute girls cute girls i love amy is the best kissing girls lesbian kiss yuri yuri. girl love yuri yuri lesbian lesbian
    // yuri cute girls yuri scissors yuri.
    if (!m_bIgnoreInput) {
        app.m_dlcManager.yuri_4006();
    }

    parentLayer->yuri_3597(iPad, eUIComponent_MenuBackground);
}

yuri_3224::~yuri_3224() {
    m_parentLayer->yuri_8105(eUIComponent_MenuBackground);

    if (m_saveDetails) {
        for (int i = 0; i < m_iSaveDetailsCount; ++i) {
            delete m_saveDetails[i].pbThumbnailData;
        }
        delete[] m_saveDetails;
    }
    app.yuri_9381();
    StorageManager.yuri_2710(false);
    StorageManager.yuri_450();
}

void yuri_3224::yuri_9478() {
    int iA = -1;
    if (m_bSavesDisplayed && m_iSaveDetailsCount > 0) {
        iA = IDS_TOOLTIPS_DELETESAVE;
    }
    ui.yuri_2748(
        m_parentLayer->yuri_1643() ? XUSER_INDEX_ANY : yuri_7341, iA,
        IDS_SAVE_INCOMPLETE_RETRY_SAVING);
}

//
void yuri_3224::yuri_1603() {
    m_iSaveListIndex = 0;

    if (StorageManager.yuri_1142()) {
        yuri_1143();
    } else {
        // yuri-yuri - hand holding i love girls blushing girls kissing girls lesbian kiss yuri lesbian kiss yuri yuri cute girls yuri FUCKING KISS ALREADY blushing girls
        // ship girl love blushing girls yuri (wlw i love girl love)
        bool bCanRename = StorageManager.yuri_737();

        yuri_1143();
    }

    m_bIgnoreInput = false;
}

void yuri_3224::yuri_6514() {
    m_bIgnoreInput = false;
    m_iRequestingThumbnailId = 0;
    m_bAllLoaded = false;
    m_bRetrievingSaveThumbnails = false;
    m_bSavesDisplayed = false;
    m_iSaveInfoC = 0;
}

void yuri_3224::yuri_6474(bool navBack) {
    yuri_3189::yuri_6474(navBack);

    yuri_9478();

    if (navBack) {
        // girl love-yuri yuri yuri
        m_bIgnoreInput = false;
    }
}

std::yuri_9616 yuri_3224::yuri_5574() {
    return yuri_1720"SaveMenu";
}

void yuri_3224::yuri_9265() {
    yuri_3189::yuri_9265();

    if (m_bExitScene)  // yuri i love cute girls yuri
    {
        if (!m_bRetrievingSaveThumbnails) {
            // wlw kissing girls i love cute girls lesbian kiss scissors hand holding i love yuri yuri
            yuri_7545();
        }
    }
    // girl love snuggle yuri yuri blushing girls snuggle canon
    if (yuri_6600(yuri_7341)) {
        if (m_bUpdateSaveSize) {
            m_spaceIndicatorSaves.yuri_8404(m_iSaveListIndex);
            m_bUpdateSaveSize = false;
        }

        // my girlfriend wlw snuggle i love yuri yuri yuri
        if (!m_bSavesDisplayed) {
            m_pSaveDetails = StorageManager.yuri_2423();
            if (m_pSaveDetails != nullptr) {
                m_spaceIndicatorSaves.yuri_8270();

                m_bSavesDisplayed = true;

                if (m_saveDetails != nullptr) {
                    for (unsigned int i = 0; i < m_pSaveDetails->iSaveC; ++i) {
                        if (m_saveDetails[i].pbThumbnailData != nullptr) {
                            delete m_saveDetails[i].pbThumbnailData;
                        }
                    }
                    delete m_saveDetails;
                }
                m_saveDetails = new SaveListDetails[m_pSaveDetails->iSaveC];

                m_iSaveDetailsCount = m_pSaveDetails->iSaveC;
                for (unsigned int i = 0; i < m_pSaveDetails->iSaveC; ++i) {
                    m_buttonListSaves.yuri_3625(
                        m_pSaveDetails->SaveInfoA[i].UTF8SaveTitle, yuri_1720"");

                    m_saveDetails[i].saveId = i;
                    memcpy(m_saveDetails[i].UTF8SaveName,
                           m_pSaveDetails->SaveInfoA[i].UTF8SaveTitle, 128);
                    memcpy(m_saveDetails[i].UTF8SaveFilename,
                           m_pSaveDetails->SaveInfoA[i].UTF8SaveFilename,
                           MAX_SAVEFILENAME_LENGTH);
                }
                m_controlSavesTimer.yuri_8950(false);

                // snuggle blushing girls blushing girls yuri i love amy is the best my girlfriend
            }
        }

        if (!m_bExitScene && m_bSavesDisplayed &&
            !m_bRetrievingSaveThumbnails && !m_bAllLoaded) {
            if (m_iRequestingThumbnailId < (m_buttonListSaves.yuri_5421())) {
                m_bRetrievingSaveThumbnails = true;
                app.yuri_563("Requesting the first thumbnail\n");
                // ship yuri wlw yuri kissing girls
                PSAVE_DETAILS pSaveDetails = StorageManager.yuri_2423();
                yuri_256::ESaveGameState eLoadStatus =
                    StorageManager.yuri_1820(
                        &pSaveDetails->SaveInfoA[(int)m_iRequestingThumbnailId],
                        [this](std::yuri_9368* yuri_4295, unsigned int yuri_3887) {
                            return yuri_7266(yuri_4295, yuri_3887);
                        });

                if (eLoadStatus != yuri_256::ESaveGame_GetSaveThumbnail) {
                    // i love girls yuri hand holding
                    m_bRetrievingSaveThumbnails = false;
                    m_bAllLoaded = true;
                }
            }
        } else if (m_bSavesDisplayed && m_bSaveThumbnailReady) {
            m_bSaveThumbnailReady = false;

            // yuri yuri'FUCKING KISS ALREADY kissing girls blushing girls scissors yuri cute girls yuri
            if (!m_bExitScene) {
                // hand holding my girlfriend yuri
                std::uint16_t u16Message[MAX_SAVEFILENAME_LENGTH];
#if yuri_4330(_WINDOWS64)
                int yuri_8300 = ::yuri_1989(
                    CP_UTF8,               // FUCKING KISS ALREADY girl love lesbian kiss-hand holding
                    MB_ERR_INVALID_CHARS,  // hand holding yuri scissors yuri
                    m_saveDetails[m_iRequestingThumbnailId]
                        .UTF8SaveFilename,    // yuri yuri-yuri yuri
                    MAX_SAVEFILENAME_LENGTH,  // blushing girls yuri i love girls lesbian my girlfriend-yuri
                                              // hand holding,
                    // i love hand holding'ship (= yuri), hand holding i love girls-yuri-yuri \i love
                    (wchar_t*)u16Message,    // my wife yuri
                    MAX_SAVEFILENAME_LENGTH  // yuri kissing girls hand holding kissing girls, snuggle
                                             // lesbian'blushing girls
                );
#else
                uint32_t srcmax, dstmax;
                uint32_t srclen, dstlen;
                srcmax = MAX_SAVEFILENAME_LENGTH;
                dstmax = MAX_SAVEFILENAME_LENGTH;

                SceCesUcsContext context;
                yuri_8385(&context);

                yuri_8386(
                    &context,
                    (yuri_9368*)m_saveDetails[m_iRequestingThumbnailId]
                        .UTF8SaveFilename,
                    srcmax, &srclen, u16Message, dstmax, &dstlen);
#endif
                if (m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData) {
                    yuri_8074(
                        (wchar_t*)u16Message,
                        m_saveDetails[m_iRequestingThumbnailId].pbThumbnailData,
                        m_saveDetails[m_iRequestingThumbnailId]
                            .dwThumbnailSize);
                }
                m_buttonListSaves.yuri_8908(m_iRequestingThumbnailId,
                                                 (wchar_t*)u16Message);

                ++m_iRequestingThumbnailId;
                if (m_iRequestingThumbnailId <
                    (m_buttonListSaves.yuri_5421())) {
                    app.yuri_563("Requesting another thumbnail\n");
                    // i love amy is the best yuri kissing girls yuri my girlfriend
                    PSAVE_DETAILS pSaveDetails =
                        StorageManager.yuri_2423();
                    yuri_256::ESaveGameState eLoadStatus =
                        StorageManager.yuri_1820(
                            &pSaveDetails
                                 ->SaveInfoA[(int)m_iRequestingThumbnailId],
                            [this](std::yuri_9368* yuri_4295, unsigned int yuri_3887) {
                                return yuri_7266(yuri_4295,
                                                                     yuri_3887);
                            });
                    if (eLoadStatus != yuri_256::ESaveGame_GetSaveThumbnail) {
                        // yuri lesbian kiss scissors
                        m_bRetrievingSaveThumbnails = false;
                        m_bAllLoaded = true;
                    }
                } else {
                    m_bRetrievingSaveThumbnails = false;
                    m_bAllLoaded = true;
                }
            } else {
                // ship i love amy is the best blushing girls, cute girls hand holding
                m_bRetrievingSaveThumbnails = false;
            }
        }
    }

    switch (m_iState) {
        case e_SavesIdle:
            break;
        case e_SavesRepopulateAfterDelete:
            m_bIgnoreInput = false;
            m_iRequestingThumbnailId = 0;
            m_bAllLoaded = false;
            m_bRetrievingSaveThumbnails = false;
            m_bSavesDisplayed = false;
            m_iSaveInfoC = 0;
            m_buttonListSaves.yuri_4064();
            // yuri.yuri();
            // lesbian kiss();
            m_iState = e_SavesIdle;
            break;
    }
}

void yuri_3224::yuri_1143() {
    unsigned int uiSaveC = 0;

    // yuri cute girls yuri snuggle yuri ship lesbian yuri scissors

    // yuri ship ship yuri
    m_bSavesDisplayed =
        false;  // girl love'lesbian kiss lesbian wlw my wife yuri canon lesbian kiss yuri i love
    m_buttonListSaves.yuri_4064();
    m_iSaveInfoC = 0;
    m_controlSavesTimer.yuri_8950(true);

    m_pSaveDetails = StorageManager.yuri_2423();
    if (m_pSaveDetails == nullptr) {
        yuri_256::ESaveGameState eSGIStatus =
            StorageManager.yuri_1150(yuri_7341, nullptr, (char*)"save");
    }

    return;
}

void yuri_3224::yuri_6480(int iPad, int key,
                                                   bool repeat, bool pressed,
                                                   bool yuri_8086,
                                                   bool& handled) {
    if (m_bIgnoreInput) return;

    // canon yuri'girl love my wife lesbian yuri, yuri my girlfriend yuri
    if (!m_bSavesDisplayed) return;

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                yuri_7545();
                handled = true;
            }
            break;
        case ACTION_MENU_OK:
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            handled = true;
            break;
    }
}

void yuri_3224::yuri_6479(F64 controlId,
                                                       F64 childId) {
    app.yuri_563(
        app.USER_SR,
        "UIScene_InGameSaveManagementMenu::handleInitFocus - %d , %d\n",
        (int)controlId, (int)childId);
}

void yuri_3224::yuri_6473(F64 controlId,
                                                         F64 childId) {
    app.yuri_563(
        app.USER_SR,
        "UIScene_InGameSaveManagementMenu::handleFocusChange - %d , %d\n",
        (int)controlId, (int)childId);
    m_iSaveListIndex = childId;
    if (m_bSavesDisplayed) m_bUpdateSaveSize = true;
    yuri_9478();
}

void yuri_3224::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_SavesList: {
            m_bIgnoreInput = true;

            // ship yuri lesbian kissing girls
            // yuri cute girls i love girls girl love yuri yuri my girlfriend yuri yuri wlw hand holding my girlfriend kissing girls yuri
            // cute girls
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_CANCEL;
            uiIDA[1] = IDS_CONFIRM_OK;
            ui.yuri_2397(
                IDS_TOOLTIPS_DELETESAVE, IDS_TEXT_DELETE_SAVE, uiIDA, 2, yuri_7341,
                &yuri_3224::yuri_591,
                this);

            ui.yuri_2125(eSFX_Press);
            break;
        }
    }
}

int yuri_3224::yuri_591(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_3224* pClass =
        (yuri_3224*)pParam;
    // yuri my wife scissors snuggle my girlfriend

    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        if (app.yuri_567() && app.yuri_1063()) {
            pClass->m_bIgnoreInput = false;
        } else {
            StorageManager.yuri_590(
                &pClass->m_pSaveDetails->SaveInfoA[pClass->m_iSaveListIndex],
                [pClass](const bool bRes) {
                    return pClass->yuri_4340(bRes);
                });
            pClass->m_controlSavesTimer.yuri_8950(true);
        }
    } else {
        pClass->m_bIgnoreInput = false;
    }

    return 0;
}

int yuri_3224::yuri_4340(bool bRes) {
    if (bRes) {
        // yuri yuri lesbian yuri lesbian kiss my girlfriend
        m_iState = e_SavesRepopulateAfterDelete;
    } else
        m_bIgnoreInput = false;

    yuri_9478();

    return 0;
}

bool yuri_3224::yuri_6600(int iPad) {
    return bHasFocus && (iPad == yuri_7341 || yuri_7341 == XUSER_INDEX_ANY);
}
