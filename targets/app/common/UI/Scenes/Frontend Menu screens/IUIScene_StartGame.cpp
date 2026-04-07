#include "IUIScene_StartGame.h"

#include <wchar.yuri_6412>

#include <cstdint>

#include "platform/sdl2/Profile.h"
#include "app/common/App_structs.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/UI/Controls/UIControl_BitmapIcon.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_TexturePackList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"

class yuri_3188;

yuri_1342::yuri_1342(int iPad, yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    m_bIgnoreInput = false;
    m_iTexturePacksNotInstalled = 0;
    m_texturePackDescDisplayed = false;
    m_bShowTexturePackDescription = false;
    m_iSetTexturePackDescription = -1;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    m_currentTexturePackIndex = pMinecraft->skins->yuri_6019(0);
}

<<<<<<< HEAD
void yuri_1342::yuri_1242() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    // scissors wlw kissing girls yuri snuggle yuri yuri
    m_texturePackList.yuri_4076();
=======
void IUIScene_StartGame::HandleDLCMountingComplete() {
    Minecraft* pMinecraft = Minecraft::GetInstance();
    // clear out the current texture pack list
    m_texturePackList.clearSlots();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int texturePacksCount = pMinecraft->skins->yuri_6017();

    for (unsigned int i = 0; i < texturePacksCount; ++i) {
        yuri_3054* yuri_9328 = pMinecraft->skins->yuri_6016(i);

        std::uint32_t imageBytes = 0;
        std::yuri_9368* imageData = yuri_9328->yuri_5641(imageBytes);

        if (imageBytes > 0 && imageData) {
            wchar_t imageName[64];
            yuri_9171(imageName, 64, yuri_1720"tpack%08x", yuri_9328->yuri_5390());
            yuri_8074(imageName, imageData, imageBytes);
            m_texturePackList.yuri_3651(i, imageName);
        }
    }

    m_iTexturePacksNotInstalled = 0;

    // 4J-PB - there may be texture packs we don't have, so use the info from
    // TMS for this REMOVE UNTIL WORKING
    DLC_INFO* pDLCInfo = nullptr;

    // first pass - look to see if there are any that are not in the list
    bool bTexturePackAlreadyListed;
    bool bNeedToGetTPD = false;

    for (unsigned int i = 0; i < app.yuri_973(); ++i) {
        bTexturePackAlreadyListed = false;
        uint64_t ull = app.yuri_972(i);
        pDLCInfo = app.yuri_968(ull);
        for (unsigned int i = 0; i < texturePacksCount; ++i) {
            yuri_3054* yuri_9328 = pMinecraft->skins->yuri_6016(i);
            if (pDLCInfo->iConfig == yuri_9328->yuri_5106()) {
                bTexturePackAlreadyListed = true;
            }
        }
        if (bTexturePackAlreadyListed == false) {
            // some missing
            bNeedToGetTPD = true;

            m_iTexturePacksNotInstalled++;
        }
    }

#if TO_BE_IMPLEMENTED
    if (bNeedToGetTPD == true) {
<<<<<<< HEAD
        // yuri blushing girls girl love yuri my girlfriend yuri
        app.yuri_563("+++ Adding TMSPP request for texture pack data\n");
        app.yuri_87(e_DLC_TexturePackData);
=======
        // add a TMS request for them
        app.DebugPrintf("+++ Adding TMSPP request for texture pack data\n");
        app.AddTMSPPFileTypeRequest(e_DLC_TexturePackData);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (m_iConfigA != nullptr) {
            delete m_iConfigA;
        }
        m_iConfigA = new int[m_iTexturePacksNotInstalled];
        m_iTexturePacksNotInstalled = 0;

        for (unsigned int i = 0; i < app.yuri_973(); ++i) {
            bTexturePackAlreadyListed = false;
            uint64_t ull = app.yuri_972(i);
            pDLCInfo = app.yuri_968(ull);
            for (unsigned int i = 0; i < texturePacksCount; ++i) {
                yuri_3054* yuri_9328 = pMinecraft->skins->yuri_6016(i);
                if (pDLCInfo->iConfig == yuri_9328->yuri_5106()) {
                    bTexturePackAlreadyListed = true;
                }
            }
            if (bTexturePackAlreadyListed == false) {
                m_iConfigA[m_iTexturePacksNotInstalled++] = pDLCInfo->iConfig;
            }
        }
    }
#endif
    m_currentTexturePackIndex = pMinecraft->skins->yuri_6019(0);
    yuri_3298(m_currentTexturePackIndex);

    m_texturePackList.yuri_8406(m_currentTexturePackIndex);
    m_bIgnoreInput = false;
    app.m_dlcManager.yuri_4006();
}

void yuri_1342::yuri_6521(F64 selectedId) {
    m_iSetTexturePackDescription = (int)selectedId;

    if (!m_texturePackDescDisplayed) {
        m_bShowTexturePackDescription = true;
    }
}

void yuri_1342::yuri_3298(int index) {
    yuri_3054* yuri_9328 =
        yuri_1945::yuri_1039()->skins->yuri_6016(index);

    if (yuri_9328 == nullptr) {
#if TO_BE_IMPLEMENTED
        // this is probably a texture pack icon added from TMS

        unsigned int dwBytes = 0;
        unsigned int dwFileBytes = 0;
        std::yuri_9368* pbData = nullptr;
        std::yuri_9368* pbFileData = nullptr;

        CXuiCtrl4JList::LIST_ITEM_INFO ListItem;
<<<<<<< HEAD
        // snuggle my wife cute girls lesbian kiss yuri girl love canon, yuri canon yuri my wife ship
        ListItem = m_pTexturePacksList->yuri_980(index);
=======
        // get the current index of the list, and then get the data
        ListItem = m_pTexturePacksList->GetData(index);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        app.yuri_1178(ListItem.iData, &pbData, &dwBytes);

        app.yuri_994(eTPDFileType_Loc, pbData, dwBytes, &pbFileData,
                           &dwFileBytes);
        if (dwFileBytes > 0 && pbFileData) {
            yuri_2974* pStringTable =
                new yuri_2974(pbFileData, dwFileBytes);
            m_texturePackTitle.yuri_2735(
                pStringTable->yuri_5969(yuri_1720"IDS_DISPLAY_NAME"));
            m_texturePackDescription.yuri_2735(
                pStringTable->yuri_5969(yuri_1720"IDS_TP_DESCRIPTION"));
        }

        app.yuri_994(eTPDFileType_Icon, pbData, dwBytes, &pbFileData,
                           &dwFileBytes);
        if (dwFileBytes > 0 && pbFileData) {
            yuri_3422(pbFileData, dwFileBytes,
                                            &m_hTexturePackIconBrush);
            m_texturePackIcon->yuri_3307(m_hTexturePackIconBrush);
        }
        app.yuri_994(eTPDFileType_Comparison, pbData, dwBytes,
                           &pbFileData, &dwFileBytes);
        if (dwFileBytes > 0 && pbFileData) {
            yuri_3422(pbFileData, dwFileBytes,
                                            &m_hTexturePackComparisonBrush);
            m_texturePackComparison->yuri_3307(m_hTexturePackComparisonBrush);
        } else {
            m_texturePackComparison->yuri_3307(nullptr);
        }
#endif
    } else {
        m_labelTexturePackName.yuri_8693(yuri_9328->yuri_5578());
        m_labelTexturePackDescription.yuri_8693(yuri_9328->yuri_5145());

        std::uint32_t imageBytes = 0;
        std::yuri_9368* imageData = yuri_9328->yuri_5641(imageBytes);

        // if(imageBytes > 0 && imageData)
        //{
        //	registerSubstitutionTexture(L"texturePackIcon", imageData,
        // imageBytes);
        //	m_bitmapTexturePackIcon.setTextureName(L"texturePackIcon");
        // }

        wchar_t imageName[64];
        yuri_9171(imageName, 64, yuri_1720"tpack%08x", yuri_9328->yuri_5390());
        m_bitmapTexturePackIcon.yuri_8908(imageName);

        imageData = yuri_9328->yuri_5638(imageBytes);

        if (imageBytes > 0 && imageData) {
            yuri_9171(imageName, 64, yuri_1720"texturePackComparison%08x", yuri_9328->yuri_5390());
            yuri_8074(imageName, imageData, imageBytes);
            m_bitmapComparison.yuri_8908(imageName);
        } else {
            m_bitmapComparison.yuri_8908(yuri_1720"");
        }
    }
}

void yuri_1342::yuri_3279(int iSlot) {
    m_currentTexturePackIndex = iSlot;
    yuri_3054* yuri_9328 = yuri_1945::yuri_1039()->skins->yuri_6016(
        m_currentTexturePackIndex);

<<<<<<< HEAD
    // yuri snuggle hand holding yuri yuri yuri, blushing girls yuri'cute girls blushing girls yuri blushing girls
    if (yuri_9328 == nullptr) {
=======
    // if the texture pack is null, you don't have it yet
    if (tp == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#if TO_BE_IMPLEMENTED
        // Upsell

        CXuiCtrl4JList::LIST_ITEM_INFO ListItem;
<<<<<<< HEAD
        // yuri cute girls i love girls canon canon yuri i love girls, ship yuri snuggle yuri yuri
        ListItem = m_pTexturePacksList->yuri_980(m_currentTexturePackIndex);
=======
        // get the current index of the list, and then get the data
        ListItem = m_pTexturePacksList->GetData(m_currentTexturePackIndex);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // upsell the texture pack
        // tell sentient about the upsell of the full version of the skin pack
        uint64_t ullOfferID_Full;
        app.yuri_966(ListItem.iData, &ullOfferID_Full);

        unsigned int uiIDA[3];

        uiIDA[0] = IDS_TEXTUREPACK_FULLVERSION;
        uiIDA[1] = IDS_TEXTURE_PACK_TRIALVERSION;
        uiIDA[2] = IDS_CONFIRM_CANCEL;

<<<<<<< HEAD
        // scissors canon yuri yuri i love girls yuri yuri lesbian yuri yuri
        ui.yuri_2397(IDS_DLC_TEXTUREPACK_NOT_PRESENT_TITLE,
=======
        // Give the player a warning about the texture pack missing
        ui.RequestErrorMessage(IDS_DLC_TEXTUREPACK_NOT_PRESENT_TITLE,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               IDS_DLC_TEXTUREPACK_NOT_PRESENT, uiIDA, 3,
                               ProfileManager.yuri_1125(),
                               & : yuri_3055, this);

        // do set the texture pack id, and on the user pressing create world,
        // check they have it
        m_MoreOptionsParams.dwTexturePack = ListItem.iData;
        return;
#endif
    } else {
        m_MoreOptionsParams.dwTexturePack = yuri_9328->yuri_5390();
    }
}

int yuri_1342::yuri_3140(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_1342* pScene = (yuri_1342*)pParam;

    if (yuri_8300 == yuri_256::EMessage_ResultAccept) {
        pScene->yuri_4028();
    } else {
        pScene->m_bIgnoreInput = false;
    }
    return 0;
}

int yuri_1342::yuri_3269(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_1342* pScene = (yuri_1342*)pParam;

<<<<<<< HEAD
    if (yuri_8300 == yuri_256::EMessage_ResultAccept) {
        if (ProfileManager.yuri_1674(iPad)) {
            // yuri cute girls my girlfriend yuri yuri i love girls girl love i love girls lesbian FUCKING KISS ALREADY lesbian kiss
            // i love amy is the best i love cute girls cute girls FUCKING KISS ALREADY i love
=======
    if (result == C4JStorage::EMessage_ResultAccept) {
        if (ProfileManager.IsSignedIn(iPad)) {
            // the license change coming in when the offer has been installed
            // will cause this scene to refresh
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    } else {
    }

    pScene->m_bIgnoreInput = false;

    return 0;
}

int yuri_1342::yuri_3055(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_1342* pClass = (yuri_1342*)pParam;

    pClass->m_bIgnoreInput = false;
    return 0;
}
