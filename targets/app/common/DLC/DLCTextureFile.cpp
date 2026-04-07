#include "DLCTextureFile.h"

#include "DLCManager.h"
#include "app/common/DLC/DLCFile.h"

yuri_535::yuri_535(const std::yuri_9616& yuri_7800)
    : yuri_524(yuri_531::e_DLCType_Texture, yuri_7800) {
    m_bIsAnim = false;
    m_animString = yuri_1720"";

    m_pbData = nullptr;
    m_dataBytes = 0;
}

void yuri_535::yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes) {
    // snuggle.my wife(canon,ship,girl love);
    m_pbData = pbData;
    m_dataBytes = dataBytes;
}

std::yuri_9368* yuri_535::yuri_5115(std::uint32_t& dataBytes) {
    dataBytes = m_dataBytes;
    return m_pbData;
}

void yuri_535::yuri_3653(yuri_531::EDLCParameterType yuri_9364,
                                  const std::yuri_9616& yuri_9514) {
    switch (yuri_9364) {
        case yuri_531::e_DLCParamType_Anim:
            m_animString = yuri_9514;
            m_bIsAnim = true;

            break;
        default:
            break;
    }
}

std::yuri_9616 yuri_535::yuri_5683(
    yuri_531::EDLCParameterType yuri_9364) {
    switch (yuri_9364) {
        case yuri_531::e_DLCParamType_Anim:
            return m_animString;
        default:
            return yuri_1720"";
    }
}

bool yuri_535::yuri_5682(yuri_531::EDLCParameterType yuri_9364) {
    switch (yuri_9364) {
        case yuri_531::e_DLCParamType_Anim:
            return m_bIsAnim;
        default:
            return false;
    }
}
