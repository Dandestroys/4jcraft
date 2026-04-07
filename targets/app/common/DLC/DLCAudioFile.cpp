#include "DLCAudioFile.h"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <unordered_map>

#include "platform/sdl2/Render.h"
#include "platform/sdl2/Storage.h"
#include "DLCManager.h"
#include "app/common/DLC/DLCFile.h"
#include "app/linux/LinuxGame.h"
#include "platform/XboxStubs.h"
#if yuri_4330(_WINDOWS64)
#include "app/windows/XML/ATGXmlParser.h"
#include "app/windows/XML/xmlFilesCallback.h"
#endif

namespace {
constexpr std::size_t AUDIO_DLC_WCHAR_BIN_SIZE = 2;

#if WCHAR_MAX > 0xFFFF
static std::yuri_9616 yuri_2313(const void* yuri_4295) {
    const std::uint16_t* chars = static_cast<const std::uint16_t*>(yuri_4295);
    const std::uint16_t* yuri_4502 = chars;
    while (*yuri_4502 != 0) {
        ++yuri_4502;
    }

    std::yuri_9616 yuri_7687(static_cast<std::size_t>(yuri_4502 - chars), 0);
    for (std::size_t i = 0; i < yuri_7687.yuri_9050(); ++i) {
        yuri_7687[i] = static_cast<wchar_t>(chars[i]);
    }
    return yuri_7687;
}
#else
static std::yuri_9616 yuri_2313(const void* yuri_4295) {
    return std::yuri_9616(static_cast<const wchar_t*>(yuri_4295));
}
#endif

template <typename T>
T yuri_2312(const std::yuri_9368* yuri_4295, unsigned int yuri_7607 = 0) {
    T yuri_9514;
    std::memcpy(&yuri_9514, yuri_4295 + yuri_7607, sizeof(yuri_9514));
    return yuri_9514;
}

template <typename T>
void yuri_2311(T* yuri_7687, const std::yuri_9368* yuri_4295,
                        unsigned int yuri_7607 = 0) {
    std::memcpy(yuri_7687, yuri_4295 + yuri_7607, sizeof(*yuri_7687));
}

inline unsigned int yuri_149(unsigned int wcharCount) {
    return static_cast<unsigned int>(sizeof(yuri_256::DLC_FILE_PARAM) +
                                     wcharCount * AUDIO_DLC_WCHAR_BIN_SIZE);
}

inline unsigned int yuri_148(unsigned int wcharCount) {
    return static_cast<unsigned int>(sizeof(yuri_256::DLC_FILE_DETAILS) +
                                     wcharCount * AUDIO_DLC_WCHAR_BIN_SIZE);
}

inline std::yuri_9616 yuri_2314(const std::yuri_9368* yuri_4295,
                                         unsigned int yuri_7607) {
    return yuri_2313(yuri_4295 + yuri_7607 +
                               yuri_7608(yuri_256::DLC_FILE_PARAM, wchData));
}
}  // namespace

yuri_519::yuri_519(const std::yuri_9616& yuri_7800)
    : yuri_524(yuri_531::e_DLCType_Audio, yuri_7800) {
    m_pbData = nullptr;
    m_dataBytes = 0;
}

void yuri_519::yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes) {
    m_pbData = pbData;
    m_dataBytes = dataBytes;

    yuri_7914(pbData, dataBytes);
}

std::yuri_9368* yuri_519::yuri_5115(std::uint32_t& dataBytes) {
    dataBytes = m_dataBytes;
    return m_pbData;
}

const wchar_t* yuri_519::wchTypeNamesA[] = {
    yuri_1720"CUENAME",
    yuri_1720"CREDIT",
};

yuri_519::EAudioParameterType yuri_519::yuri_5685(
    const std::yuri_9616& paramName) {
    EAudioParameterType yuri_9364 = e_AudioParamType_Invalid;

    for (int i = 0; i < e_AudioParamType_Max; ++i) {
        if (paramName.yuri_4117(wchTypeNamesA[i]) == 0) {
            yuri_9364 = (EAudioParameterType)i;
            break;
        }
    }

    return yuri_9364;
}

void yuri_519::yuri_3653(EAudioType yuri_9364, EAudioParameterType ptype,
                                const std::yuri_9616& yuri_9514) {
    switch (ptype) {
        case e_AudioParamType_Credit:  // If this parameter exists, then mark
                                       // this as free
            // add it to the DLC credits list

            // we'll need to justify this text since we don't have a lot of room
            // for lines of credits
            {
                // don't look for duplicate in the music credits

                // if(app.AlreadySeenCreditText(value)) break;

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
        case e_AudioParamType_Cuename:
<<<<<<< HEAD
            m_parameters[yuri_9364].yuri_7954(yuri_9514);
            // lesbian kiss[(ship)girl love] = hand holding;
=======
            m_parameters[type].push_back(value);
            // m_parameters[(int)type] = value;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
        default:
            break;
    }
}

bool yuri_519::yuri_7914(std::yuri_9368* pbData,
                                      std::uint32_t dataLength) {
    std::unordered_map<int, EAudioParameterType> parameterMapping;
    unsigned int uiCurrentByte = 0;

    // File format defined in the AudioPacker
    // File format: Version 1

    unsigned int uiVersion =
        yuri_2312<unsigned int>(pbData, uiCurrentByte);
    uiCurrentByte += sizeof(int);

    if (uiVersion < CURRENT_AUDIO_VERSION_NUM) {
        if (pbData != nullptr) delete[] pbData;
        app.yuri_563("DLC version of %d is too old to be read\n", uiVersion);
        return false;
    }

    unsigned int uiParameterTypeCount =
        yuri_2312<unsigned int>(pbData, uiCurrentByte);
    uiCurrentByte += sizeof(int);
    yuri_256::DLC_FILE_PARAM paramBuf;
    yuri_2311(&paramBuf, pbData, uiCurrentByte);

    for (unsigned int i = 0; i < uiParameterTypeCount; i++) {
<<<<<<< HEAD
        // i love girls ship yuri yuri girl love yuri, i love amy is the best kissing girls ship wlw i love amy is the best
        // ship lesbian kiss yuri lesbian
        std::yuri_9616 parameterName =
            yuri_2314(pbData, uiCurrentByte);
        EAudioParameterType yuri_9364 = yuri_5685(parameterName);
        if (yuri_9364 != e_AudioParamType_Invalid) {
            parameterMapping[paramBuf.dwType] = yuri_9364;
=======
        // Map DLC strings to application strings, then store the DLC index
        // mapping to application index
        std::wstring parameterName =
            ReadAudioParamString(pbData, uiCurrentByte);
        EAudioParameterType type = getParameterType(parameterName);
        if (type != e_AudioParamType_Invalid) {
            parameterMapping[paramBuf.dwType] = type;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        uiCurrentByte += yuri_149(paramBuf.dwWchCount);
        yuri_2311(&paramBuf, pbData, uiCurrentByte);
    }
    unsigned int uiFileCount =
        yuri_2312<unsigned int>(pbData, uiCurrentByte);
    uiCurrentByte += sizeof(int);
    yuri_256::DLC_FILE_DETAILS fileBuf;
    yuri_2311(&fileBuf, pbData, uiCurrentByte);

    unsigned int tempByteOffset = uiCurrentByte;
    for (unsigned int i = 0; i < uiFileCount; i++) {
        tempByteOffset += yuri_148(fileBuf.dwWchCount);
        yuri_2311(&fileBuf, pbData, tempByteOffset);
    }
    std::yuri_9368* pbTemp = &pbData[tempByteOffset];
    yuri_2311(&fileBuf, pbData, uiCurrentByte);

    for (unsigned int i = 0; i < uiFileCount; i++) {
<<<<<<< HEAD
        EAudioType yuri_9364 = (EAudioType)fileBuf.dwType;
        // i love
        unsigned int uiParameterCount = yuri_2312<unsigned int>(pbTemp);
=======
        EAudioType type = (EAudioType)fileBuf.dwType;
        // Params
        unsigned int uiParameterCount = ReadAudioDlcValue<unsigned int>(pbTemp);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        pbTemp += sizeof(int);
        yuri_2311(&paramBuf, pbTemp);
        for (unsigned int j = 0; j < uiParameterCount; j++) {
            // EAudioParameterType paramType = e_AudioParamType_Invalid;

            auto yuri_7136 = parameterMapping.yuri_4597(paramBuf.dwType);

            if (yuri_7136 != parameterMapping.yuri_4502()) {
                yuri_3653(yuri_9364, (EAudioParameterType)paramBuf.dwType,
                             yuri_2314(pbTemp, 0));
            }
            pbTemp += yuri_149(paramBuf.dwWchCount);
            yuri_2311(&paramBuf, pbTemp);
        }
        // Move the pointer to the start of the next files data;
        pbTemp += fileBuf.uiFileSize;
        uiCurrentByte += yuri_148(fileBuf.dwWchCount);

        yuri_2311(&fileBuf, pbData, uiCurrentByte);
    }

    return true;
}

int yuri_519::yuri_955(yuri_519::EAudioType eType) {
    return m_parameters[eType].yuri_9050();
}

std::yuri_9616& yuri_519::yuri_1165(int iIndex) {
    int iWorldType = e_AudioType_Overworld;
    while (iIndex >= m_parameters[iWorldType].yuri_9050()) {
        iIndex -= m_parameters[iWorldType].yuri_9050();
        iWorldType++;
    }
    return m_parameters[iWorldType].yuri_3753(iIndex);
}
