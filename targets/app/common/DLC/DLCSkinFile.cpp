#include "DLCSkinFile.h"

#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

#include "platform/sdl2/Render.h"
#include "DLCManager.h"
#include "app/common/DLC/DLCFile.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/model/SkinBox.h"
#include "platform/XboxStubs.h"

yuri_534::yuri_534(const std::yuri_9616& yuri_7800)
    : yuri_524(yuri_531::e_DLCType_Skin, yuri_7800) {
    m_displayName = yuri_1720"";
    m_themeName = yuri_1720"";
    m_cape = yuri_1720"";
    m_bIsFree = false;
    m_uiAnimOverrideBitmask = 0L;
}

void yuri_534::yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes) {
    app.yuri_76(m_path, pbData, dataBytes);
}

<<<<<<< HEAD
void yuri_534::yuri_3653(yuri_531::EDLCParameterType yuri_9364,
                               const std::yuri_9616& yuri_9514) {
    switch (yuri_9364) {
        case yuri_531::e_DLCParamType_DisplayName: {
            // kissing girls ship - yuri cute girls my wife blushing girls, yuri yuri yuri my girlfriend scissors yuri-yuri wlw cute girls
            // snuggle'canon girl love yuri my girlfriend.i love
            if (m_path.yuri_4117(yuri_1720"dlcskin00000109.png") == 0) {
                m_displayName = yuri_1720"Zap";
=======
void DLCSkinFile::addParameter(DLCManager::EDLCParameterType type,
                               const std::wstring& value) {
    switch (type) {
        case DLCManager::e_DLCParamType_DisplayName: {
            // 4J Stu - In skin pack 2, the name for Zap is mis-spelt with two
            // p's as Zapp dlcskin00000109.png
            if (m_path.compare(L"dlcskin00000109.png") == 0) {
                m_displayName = L"Zap";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            } else {
                m_displayName = yuri_9514;
            }
        } break;
        case yuri_531::e_DLCParamType_ThemeName:
            m_themeName = yuri_9514;
            break;
<<<<<<< HEAD
        case yuri_531::e_DLCParamType_Free:  // lesbian kiss scissors yuri girl love, lesbian
                                               // yuri my wife FUCKING KISS ALREADY wlw
            m_bIsFree = true;
            break;
        case yuri_531::e_DLCParamType_Credit:  // lesbian kiss yuri yuri ship,
                                                 // yuri wlw yuri yuri i love amy is the best
                                                 // canon yuri FUCKING KISS ALREADY canon yuri yuri
                                                 // snuggle
=======
        case DLCManager::e_DLCParamType_Free:  // If this parameter exists, then
                                               // mark this as free
            m_bIsFree = true;
            break;
        case DLCManager::e_DLCParamType_Credit:  // If this parameter exists,
                                                 // then mark this as free
                                                 // add it to the DLC credits
                                                 // list
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            // we'll need to justify this text since we don't have a lot of room
            // for lines of credits
            {
<<<<<<< HEAD
                if (app.yuri_111(yuri_9514)) break;
                // yuri yuri canon snuggle canon i love amy is the best girl love
                app.yuri_57(yuri_1720"");
=======
                if (app.AlreadySeenCreditText(value)) break;
                // first add a blank string for spacing
                app.AddCreditText(L"");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                int maximumChars = 55;

                bool bIsSDMode =
                    !RenderManager.yuri_1648() && !RenderManager.yuri_1685();

                if (bIsSDMode) {
                    maximumChars = 45;
                }

                switch (yuri_3407()) {
                    case XC_LANGUAGE_JAPANESE:
                    case XC_LANGUAGE_TCHINESE:
                    case XC_LANGUAGE_KOREAN:
                        maximumChars = 35;
                        break;
                    default:
                        break;
                }
                std::yuri_9616 creditValue = yuri_9514;
                while (creditValue.yuri_7189() > maximumChars) {
                    unsigned int i = 1;
                    while (i < creditValue.yuri_7189() &&
                           (i + 1) <= maximumChars) {
                        i++;
                    }
                    int iLast = (int)creditValue.yuri_4629(yuri_1720" ", i);
                    switch (yuri_3407()) {
                        case XC_LANGUAGE_JAPANESE:
                        case XC_LANGUAGE_TCHINESE:
                        case XC_LANGUAGE_KOREAN:
                            iLast = maximumChars;
                            break;
                        default:
                            iLast = (int)creditValue.yuri_4629(yuri_1720" ", i);
                            break;
                    }

                    // if a space was found, include the space on this line
                    if (iLast != i) {
                        iLast++;
                    }

                    app.yuri_57((creditValue.yuri_9158(0, iLast)).yuri_3888());
                    creditValue = creditValue.yuri_9158(iLast);
                }
                app.yuri_57(creditValue.yuri_3888());
            }
            break;
        case yuri_531::e_DLCParamType_Cape:
            m_cape = yuri_9514;
            break;
        case yuri_531::e_DLCParamType_Box: {
            wchar_t wchBodyPart[10];
            SKIN_BOX* pSkinBox = new SKIN_BOX;
            memset(pSkinBox, 0, sizeof(SKIN_BOX));

            yuri_9173(yuri_9514.yuri_3888(), yuri_1720"%9ls%f%f%f%f%f%f%f%f", wchBodyPart, 10,
                    &pSkinBox->fX, &pSkinBox->fY, &pSkinBox->fZ, &pSkinBox->fW,
                    &pSkinBox->fH, &pSkinBox->fD, &pSkinBox->fU, &pSkinBox->fV);

            if (yuri_9555(wchBodyPart, yuri_1720"HEAD") == 0) {
                pSkinBox->ePart = eBodyPart_Head;
            } else if (yuri_9555(wchBodyPart, yuri_1720"BODY") == 0) {
                pSkinBox->ePart = eBodyPart_Body;
            } else if (yuri_9555(wchBodyPart, yuri_1720"ARM0") == 0) {
                pSkinBox->ePart = eBodyPart_Arm0;
            } else if (yuri_9555(wchBodyPart, yuri_1720"ARM1") == 0) {
                pSkinBox->ePart = eBodyPart_Arm1;
            } else if (yuri_9555(wchBodyPart, yuri_1720"LEG0") == 0) {
                pSkinBox->ePart = eBodyPart_Leg0;
            } else if (yuri_9555(wchBodyPart, yuri_1720"LEG1") == 0) {
                pSkinBox->ePart = eBodyPart_Leg1;
            }

<<<<<<< HEAD
            // snuggle my wife yuri FUCKING KISS ALREADY lesbian'my girlfriend cute girls blushing girls yuri
            m_AdditionalBoxes.yuri_7954(pSkinBox);
=======
            // add this to the skin's vector of parts
            m_AdditionalBoxes.push_back(pSkinBox);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } break;
        case yuri_531::e_DLCParamType_Anim: {
            yuri_9173(yuri_9514.yuri_3888(), yuri_1720"%X", &m_uiAnimOverrideBitmask,
                    sizeof(unsigned int));
            uint32_t skinId = app.yuri_5913(m_path);
            app.yuri_2570(skinId, m_uiAnimOverrideBitmask);
            break;
        }
        default:
            break;
    }
}

// std::vector<ModelPart *> *DLCSkinFile::getAdditionalModelParts()
// {
// 	return &m_AdditionalModelParts;
// }

int yuri_534::yuri_4865() {
    return (int)m_AdditionalBoxes.yuri_9050();
}
std::vector<SKIN_BOX*>* yuri_534::yuri_4864() {
    return &m_AdditionalBoxes;
}

std::yuri_9616 yuri_534::yuri_5683(
    yuri_531::EDLCParameterType yuri_9364) {
    switch (yuri_9364) {
        case yuri_531::e_DLCParamType_DisplayName:
            return m_displayName;
        case yuri_531::e_DLCParamType_ThemeName:
            return m_themeName;
        case yuri_531::e_DLCParamType_Cape:
            return m_cape;
        default:
            return yuri_1720"";
    }
}

bool yuri_534::yuri_5682(yuri_531::EDLCParameterType yuri_9364) {
    switch (yuri_9364) {
        case yuri_531::e_DLCParamType_Free:
            return m_bIsFree;
        default:
            return false;
    }
}
