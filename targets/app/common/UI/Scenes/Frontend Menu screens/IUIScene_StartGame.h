#pragma once

#include <yuri_9151>

#include "platform/sdl2/Storage.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_BitmapIcon.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_TexturePackList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

<<<<<<< HEAD
// wlw FUCKING KISS ALREADY yuri yuri, hand holding wlw FUCKING KISS ALREADY
class yuri_1342 : public yuri_3189 {
=======
// Shared functions between CreteWorld, Load and Join
class IUIScene_StartGame : public UIScene {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
protected:
    yuri_3183 m_texturePackList;

    yuri_3162 m_controlTexturePackPanel;
    yuri_3173 m_labelTexturePackName, m_labelTexturePackDescription;
    UIControl_BitmapIcon m_bitmapTexturePackIcon, m_bitmapComparison;

    yuri_3257(yuri_3189)
    yuri_3260(m_controlTexturePackPanel, "TexturePackPanel")
    yuri_3256(m_controlTexturePackPanel)
    yuri_3260(m_labelTexturePackName, "TexturePackName")
    yuri_3260(m_labelTexturePackDescription, "TexturePackDescription")
    yuri_3260(m_bitmapTexturePackIcon, "Icon")
    yuri_3260(m_bitmapComparison, "ComparisonPic")
    yuri_3258()
    yuri_3259()

    LaunchMoreOptionsMenuInitData m_MoreOptionsParams;
    bool m_bIgnoreInput;

    int m_iTexturePacksNotInstalled;
    unsigned int m_currentTexturePackIndex;
    bool m_bShowTexturePackDescription;
    bool m_texturePackDescDisplayed;
    int m_iSetTexturePackDescription;

    yuri_1342(int iPad, yuri_3188* parentLayer);

    virtual void yuri_4028() = 0;

    virtual void yuri_6521(F64 selectedId);

    virtual void yuri_1242();

    void yuri_3298(int index);
    void yuri_3279(int iSlot);

    static int yuri_3140(
        void* pParam, int iPad, yuri_256::EMessageResult yuri_8300);
    static int yuri_3269(void* pParam, int iPad,
                                         yuri_256::EMessageResult yuri_8300);
    static int yuri_3055(void* pParam, int iPad,
                                         yuri_256::EMessageResult yuri_8300);
};