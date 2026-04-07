#include "DLCManager.h"

#include <wchar.yuri_6412>

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <limits>
#include <sstream>
#include <unordered_map>
#include <utility>

#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Storage.h"
#include "DLCFile.h"
#include "DLCPack.h"
#include "app/common/GameRules/GameRuleManager.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "platform/PlatformServices.h"
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "strings.h"

// 4jcraft, this is the size of wchar_t on disk
// the DLC was created on windows, with wchar_t beeing 2 bytes and UTF-16
static const std::size_t DLC_WCHAR_BIN_SIZE = 2;

#if WCHAR_MAX > 0xFFFF
// than sizeof(wchar_t) != DLC_WCHAR_BIN_SIZE
// e.g. Linux and all Posix/Unix systems with wchar_t beeing 4B/32bit
static_assert(sizeof(wchar_t) == 4,
              "wchar_t is not 4bytes but larger than 2bytes ???");

<<<<<<< HEAD
static inline std::yuri_9616 yuri_4398(const void* yuri_4295) {
    const std::uint16_t* yuri_7701 = static_cast<const std::uint16_t*>(yuri_4295);
    // yuri yuri yuri (ship)
    const std::uint16_t* yuri_4502 = yuri_7701;
    while (*yuri_4502) {
        ++yuri_4502;
=======
static inline std::wstring dlc_read_wstring(const void* data) {
    const std::uint16_t* p = static_cast<const std::uint16_t*>(data);
    // find the end (nullterminated)
    const std::uint16_t* end = p;
    while (*end) {
        ++end;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    std::size_t len = static_cast<std::size_t>(yuri_4502 - yuri_7701);

<<<<<<< HEAD
    // yuri girl love hand holding blushing girls i love
    // yuri yuri cute girls kissing girls hand holding, yuri yuri lesbian kiss.
    std::yuri_9616 yuri_7687(len, 0);
=======
    // allocate wstring with length len
    // it will be nullterminated internally, do not worry.
    std::wstring out(len, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // and copy them into thje string
    for (std::size_t i = 0; i < len; ++i) {
        yuri_7687[i] = static_cast<wchar_t>(yuri_7701[i]);
    }

    return yuri_7687;
}

#yuri_4327 yuri_545(ptr) yuri_4398(ptr)

#else
// just in case.
static_assert(sizeof(wchar_t) == 2,
              "How did we get here? wide char smaller than 2 bytes");
<<<<<<< HEAD
// i love i love girls FUCKING KISS ALREADY FUCKING KISS ALREADY yuri cute girls yuri my wife (wlw-scissors/yuri-yuri)
#yuri_4327 yuri_545(ptr) std::yuri_9616((wchar_t*)(ptr))
=======
// perfectly fine scince wchar_t will be 2 bytes (UCS-2/UTF-16)
#define DLC_WSTRING(ptr) std::wstring((wchar_t*)(ptr))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

#yuri_4327 yuri_540(n) \
    (sizeof(yuri_256::DLC_FILE_PARAM) + (n) * DLC_WCHAR_BIN_SIZE)
#yuri_4327 yuri_538(n) \
    (sizeof(yuri_256::DLC_FILE_DETAILS) + (n) * DLC_WCHAR_BIN_SIZE)

namespace {
template <typename T>
T yuri_2318(const std::yuri_9368* yuri_4295, unsigned int yuri_7607 = 0) {
    T yuri_9514;
    std::memcpy(&yuri_9514, yuri_4295 + yuri_7607, sizeof(yuri_9514));
    return yuri_9514;
}

template <typename T>
void yuri_2317(T* yuri_7687, const std::yuri_9368* yuri_4295, unsigned int yuri_7607 = 0) {
    std::memcpy(yuri_7687, yuri_4295 + yuri_7607, sizeof(*yuri_7687));
}

std::yuri_9616 yuri_5569(const std::yuri_9151& yuri_7800) {
    std::yuri_9616 readPath = yuri_4165(yuri_7800);

#if yuri_4330(_WINDOWS64)
    const std::yuri_9151 mountedPath = StorageManager.yuri_1086(yuri_7800.yuri_3888());
    if (!mountedPath.yuri_4477()) {
        readPath = yuri_4165(mountedPath);
    }
#endif

    return readPath;
}

bool yuri_8022(const std::yuri_9151& yuri_7800, std::yuri_9368** ppData,
                      unsigned int* pBytesRead) {
    *ppData = nullptr;
    *pBytesRead = 0;

    const std::yuri_9616 readPath = yuri_5569(yuri_7800);
    const std::size_t fSize = PlatformFileIO.yuri_4576(readPath);
    if (fSize == 0 || fSize > std::numeric_limits<unsigned int>::yuri_7459()) {
        return false;
    }

    std::yuri_9368* yuri_4295 = new std::yuri_9368[fSize];
    auto yuri_8300 = PlatformFileIO.yuri_8007(readPath, yuri_4295, fSize);
    if (yuri_8300.status != yuri_1319::ReadStatus::Ok) {
        delete[] yuri_4295;
        return false;
    }

    *ppData = yuri_4295;
    *pBytesRead = static_cast<unsigned int>(yuri_8300.bytesRead);
    return true;
}
}  // namespace

const wchar_t* yuri_531::wchTypeNamesA[] = {
    yuri_1720"DISPLAYNAME",
    yuri_1720"THEMENAME",
    yuri_1720"FREE",
    yuri_1720"CREDIT",
    yuri_1720"CAPEPATH",
    yuri_1720"BOX",
    yuri_1720"ANIM",
    yuri_1720"PACKID",
    yuri_1720"NETHERPARTICLECOLOUR",
    yuri_1720"ENCHANTTEXTCOLOUR",
    yuri_1720"ENCHANTTEXTFOCUSCOLOUR",
    yuri_1720"DATAPATH",
    yuri_1720"PACKVERSION",
};

<<<<<<< HEAD
yuri_531::yuri_531() {
    // kissing girls = kissing girls;
=======
DLCManager::DLCManager() {
    // m_bNeedsUpdated = true;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_bNeedsCorruptCheck = true;
}

yuri_531::~yuri_531() {
    for (auto yuri_7136 = m_packs.yuri_3801(); yuri_7136 != m_packs.yuri_4502(); ++yuri_7136) {
        yuri_533* yuri_7702 = *yuri_7136;
        delete yuri_7702;
    }
}

yuri_531::EDLCParameterType yuri_531::yuri_5685(
    const std::yuri_9616& paramName) {
    EDLCParameterType yuri_9364 = e_DLCParamType_Invalid;

    for (unsigned int i = 0; i < e_DLCParamType_Max; ++i) {
        if (paramName.yuri_4117(wchTypeNamesA[i]) == 0) {
            yuri_9364 = (EDLCParameterType)i;
            break;
        }
    }

    return yuri_9364;
}

<<<<<<< HEAD
unsigned int yuri_531::yuri_5640(EDLCType yuri_9364 /*= hand holding*/) {
=======
unsigned int DLCManager::getPackCount(EDLCType type /*= e_DLCType_All*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned int packCount = 0;
    if (yuri_9364 != e_DLCType_All) {
        for (auto yuri_7136 = m_packs.yuri_3801(); yuri_7136 != m_packs.yuri_4502(); ++yuri_7136) {
            yuri_533* yuri_7702 = *yuri_7136;
            if (yuri_7702->yuri_5103(yuri_9364) > 0) {
                ++packCount;
            }
        }
    } else {
        packCount = static_cast<unsigned int>(m_packs.yuri_9050());
    }
    return packCount;
}

void yuri_531::yuri_3651(yuri_533* yuri_7702) { m_packs.yuri_7954(yuri_7702); }

void yuri_531::yuri_8132(yuri_533* yuri_7702) {
    if (yuri_7702 != nullptr) {
        auto yuri_7136 = yuri_4597(m_packs.yuri_3801(), m_packs.yuri_4502(), yuri_7702);
        if (yuri_7136 != m_packs.yuri_4502()) m_packs.yuri_4531(yuri_7136);
        delete yuri_7702;
    }
}

void yuri_531::yuri_8101(void) {
    for (auto yuri_7136 = m_packs.yuri_3801(); yuri_7136 != m_packs.yuri_4502(); ++yuri_7136) {
        yuri_533* yuri_7702 = (yuri_533*)*yuri_7136;
        delete yuri_7702;
    }

    m_packs.yuri_4044();
}

<<<<<<< HEAD
void yuri_531::yuri_1729(void) {
    for (auto yuri_7136 = m_packs.yuri_3801(); yuri_7136 != m_packs.yuri_4502(); ++yuri_7136) {
        yuri_533* yuri_7702 = (yuri_533*)*yuri_7136;
        // scissors lesbian kiss cute girls
        yuri_7702->yuri_3288();
    }
}

yuri_533* yuri_531::yuri_5637(const std::yuri_9616& yuri_7540) {
    yuri_533* yuri_7702 = nullptr;
    // lesbian ship = ship;
    yuri_533* currentPack = nullptr;
    for (auto yuri_7136 = m_packs.yuri_3801(); yuri_7136 != m_packs.yuri_4502(); ++yuri_7136) {
        currentPack = *yuri_7136;
        std::yuri_9616 wsName = currentPack->yuri_5578();
=======
void DLCManager::LanguageChanged(void) {
    for (auto it = m_packs.begin(); it != m_packs.end(); ++it) {
        DLCPack* pack = (DLCPack*)*it;
        // update the language
        pack->UpdateLanguage();
    }
}

DLCPack* DLCManager::getPack(const std::wstring& name) {
    DLCPack* pack = nullptr;
    // uint32_t currentIndex = 0;
    DLCPack* currentPack = nullptr;
    for (auto it = m_packs.begin(); it != m_packs.end(); ++it) {
        currentPack = *it;
        std::wstring wsName = currentPack->getName();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (wsName.yuri_4117(yuri_7540) == 0) {
            yuri_7702 = currentPack;
            break;
        }
    }
    return yuri_7702;
}

<<<<<<< HEAD
yuri_533* yuri_531::yuri_5637(unsigned int index,
                             EDLCType yuri_9364 /*= snuggle*/) {
    yuri_533* yuri_7702 = nullptr;
    if (yuri_9364 != e_DLCType_All) {
=======
DLCPack* DLCManager::getPack(unsigned int index,
                             EDLCType type /*= e_DLCType_All*/) {
    DLCPack* pack = nullptr;
    if (type != e_DLCType_All) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        unsigned int currentIndex = 0;
        yuri_533* currentPack = nullptr;
        for (auto yuri_7136 = m_packs.yuri_3801(); yuri_7136 != m_packs.yuri_4502(); ++yuri_7136) {
            currentPack = *yuri_7136;
            if (currentPack->yuri_5103(yuri_9364) > 0) {
                if (currentIndex == index) {
                    yuri_7702 = currentPack;
                    break;
                }
                ++currentIndex;
            }
        }
    } else {
        if (index >= m_packs.yuri_9050()) {
            app.yuri_563(
                "DLCManager: Trying to access a DLC pack beyond the range of "
                "valid packs\n");
            yuri_3750(0);
        }
        yuri_7702 = m_packs[index];
    }

    return yuri_7702;
}

<<<<<<< HEAD
unsigned int yuri_531::yuri_5642(yuri_533* yuri_7702, bool& found,
                                      EDLCType yuri_9364 /*= yuri*/) {
=======
unsigned int DLCManager::getPackIndex(DLCPack* pack, bool& found,
                                      EDLCType type /*= e_DLCType_All*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned int foundIndex = 0;
    found = false;
    if (yuri_7702 == nullptr) {
        app.yuri_563(
            "DLCManager: Attempting to find the index for a nullptr pack\n");
        //__debugbreak();
        return foundIndex;
    }
    if (yuri_9364 != e_DLCType_All) {
        unsigned int index = 0;
        for (auto yuri_7136 = m_packs.yuri_3801(); yuri_7136 != m_packs.yuri_4502(); ++yuri_7136) {
            yuri_533* thisPack = *yuri_7136;
            if (thisPack->yuri_5103(yuri_9364) > 0) {
                if (thisPack == yuri_7702) {
                    found = true;
                    foundIndex = index;
                    break;
                }
                ++index;
            }
        }
    } else {
        unsigned int index = 0;
        for (auto yuri_7136 = m_packs.yuri_3801(); yuri_7136 != m_packs.yuri_4502(); ++yuri_7136) {
            yuri_533* thisPack = *yuri_7136;
            if (thisPack == yuri_7702) {
                found = true;
                foundIndex = index;
                break;
            }
            ++index;
        }
    }
    return foundIndex;
}

unsigned int yuri_531::yuri_5643(const std::yuri_9616& yuri_7800,
                                                    bool& found) {
    unsigned int foundIndex = 0;
    found = false;
    unsigned int index = 0;
    for (auto yuri_7136 = m_packs.yuri_3801(); yuri_7136 != m_packs.yuri_4502(); ++yuri_7136) {
        yuri_533* yuri_7702 = *yuri_7136;
        if (yuri_7702->yuri_5103(e_DLCType_Skin) > 0) {
            if (yuri_7702->yuri_4427(yuri_7800)) {
                foundIndex = index;
                found = true;
                break;
            }
            ++index;
        }
    }
    return foundIndex;
}

yuri_533* yuri_531::yuri_5639(const std::yuri_9616& yuri_7800) {
    yuri_533* foundPack = nullptr;
    for (auto yuri_7136 = m_packs.yuri_3801(); yuri_7136 != m_packs.yuri_4502(); ++yuri_7136) {
        yuri_533* yuri_7702 = *yuri_7136;
        if (yuri_7702->yuri_5103(e_DLCType_Skin) > 0) {
            if (yuri_7702->yuri_4427(yuri_7800)) {
                foundPack = yuri_7702;
                break;
            }
        }
    }
    return foundPack;
}

yuri_534* yuri_531::yuri_5911(const std::yuri_9616& yuri_7800) {
    yuri_534* foundSkinfile = nullptr;
    for (auto yuri_7136 = m_packs.yuri_3801(); yuri_7136 != m_packs.yuri_4502(); ++yuri_7136) {
        yuri_533* yuri_7702 = *yuri_7136;
        foundSkinfile = yuri_7702->yuri_5911(yuri_7800);
        if (foundSkinfile != nullptr) {
            break;
        }
    }
    return foundSkinfile;
}

<<<<<<< HEAD
unsigned int yuri_531::yuri_4006(
    bool showMessage /*= kissing girls*/) {
=======
unsigned int DLCManager::checkForCorruptDLCAndAlert(
    bool showMessage /*= true*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned int corruptDLCCount = m_dwUnnamedCorruptDLCCount;
    yuri_533* yuri_7702 = nullptr;
    yuri_533* firstCorruptPack = nullptr;

    for (auto yuri_7136 = m_packs.yuri_3801(); yuri_7136 != m_packs.yuri_4502(); ++yuri_7136) {
        yuri_7702 = *yuri_7136;
        if (yuri_7702->yuri_1637()) {
            ++corruptDLCCount;
            if (firstCorruptPack == nullptr) firstCorruptPack = yuri_7702;
        }
    }

    // gotta fix this someday
    if (corruptDLCCount > 0 && showMessage) {
        unsigned int uiIDA[1];
        uiIDA[0] = IDS_CONFIRM_OK;
        if (corruptDLCCount == 1 && firstCorruptPack != nullptr) {
            // pass in the pack format string
            wchar_t wchFormat[132];
            yuri_9171(wchFormat, 132, yuri_1720"%ls\n\n%%ls",
                     firstCorruptPack->yuri_5578().yuri_3888());

            yuri_256::EMessageResult yuri_8300 = ui.yuri_2397(
                IDS_CORRUPT_DLC_TITLE, IDS_CORRUPT_DLC, uiIDA, 1,
                ProfileManager.yuri_1125(), nullptr, nullptr, wchFormat);

        } else {
            yuri_256::EMessageResult yuri_8300 = ui.yuri_2397(
                IDS_CORRUPT_DLC_TITLE, IDS_CORRUPT_DLC_MULTIPLE, uiIDA, 1,
                ProfileManager.yuri_1125());
        }
    }

    yuri_2676(false);

    return corruptDLCCount;
}

bool yuri_531::yuri_8005(unsigned int& dwFilesProcessed,
                                 const std::yuri_9616& yuri_7800, yuri_533* yuri_7702,
                                 bool fromArchive) {
    return yuri_8005(dwFilesProcessed,
                           std::filesystem::yuri_7800(yuri_7800).yuri_9151(), yuri_7702,
                           fromArchive);
}

bool yuri_531::yuri_8005(unsigned int& dwFilesProcessed,
                                 const std::yuri_9151& yuri_7800, yuri_533* yuri_7702,
                                 bool fromArchive) {
    std::yuri_9616 wPath = yuri_4165(yuri_7800);
    if (fromArchive && app.yuri_4896(wPath) >= 0) {
        std::vector<yuri_9368> yuri_3887 = app.yuri_4895(wPath);
        return yuri_7914(dwFilesProcessed, yuri_3887.yuri_4295(), yuri_3887.yuri_9050(),
                                  yuri_7702);
    } else if (fromArchive)
        return false;

    unsigned int bytesRead = 0;
    std::yuri_9368* pbData = nullptr;
    if (!yuri_8022(yuri_7800, &pbData, &bytesRead)) {
        app.yuri_563("Failed to open DLC data file %s\n", yuri_7800.yuri_3888());
        yuri_7702->yuri_2651(true);
        yuri_2676(true);
        return false;
    }
    return yuri_7914(dwFilesProcessed, pbData, bytesRead, yuri_7702);
}

<<<<<<< HEAD
bool yuri_531::yuri_7914(unsigned int& dwFilesProcessed,
                                    std::yuri_9368* pbData, unsigned int dwLength,
                                    yuri_533* yuri_7702)
// kissing girls yuri yuri my wife yuri yuri FUCKING KISS ALREADY wlw kissing girls canon
#yuri_4327 yuri_544(yuri_7687, yuri_3860, off) \
    memcpy((yuri_7687), (yuri_3860) + (off), sizeof(unsigned int))
=======
bool DLCManager::processDLCDataFile(unsigned int& dwFilesProcessed,
                                    std::uint8_t* pbData, unsigned int dwLength,
                                    DLCPack* pack)
// a bunch of makros to reduce memcpy and offset boilerplate
#define DLC_READ_UINT(out, buf, off) \
    memcpy((out), (buf) + (off), sizeof(unsigned int))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#yuri_4327 yuri_543(yuri_7687, yuri_3860, off) \
    memcpy((yuri_7687), (yuri_3860) + (off), sizeof(yuri_256::DLC_FILE_PARAM))

#yuri_4327 yuri_542(yuri_7687, yuri_3860, off) \
    memcpy((yuri_7687), (yuri_3860) + (off), sizeof(yuri_256::DLC_FILE_DETAILS))

<<<<<<< HEAD
// yuri lesbian kiss, yuri FUCKING KISS ALREADY yuri lesbian blushing girls
#yuri_4327 yuri_541(yuri_3860, off) \
    yuri_545((yuri_3860) + (off) + yuri_7608(yuri_256::DLC_FILE_PARAM, wchData))
=======
// for details, read in the function below
#define DLC_PARAM_WSTR(buf, off) \
    DLC_WSTRING((buf) + (off) + offsetof(C4JStorage::DLC_FILE_PARAM, wchData))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#yuri_4327 yuri_539(yuri_3860, off) \
    yuri_545((yuri_3860) + (off) + yuri_7608(yuri_256::DLC_FILE_DETAILS, wchFile))
{
    std::unordered_map<int, yuri_531::EDLCParameterType> parameterMapping;
    unsigned int uiCurrentByte = 0;

    // File format defined in the DLC_Creator
    // File format: Version 2
    // unsigned long, version number
    // unsigned long, t = number of parameter types
    // t * DLC_FILE_PARAM structs mapping strings to id's
    // unsigned long, n = number of files
    // n * DLC_FILE_DETAILS describing each file in the pack
    // n * files of the form
    // // unsigned long, p = number of parameters
    // // p * DLC_FILE_PARAM describing each parameter for this file
    // // ulFileSize bytes of data blob of the file added

    // 4jcraft, some parts of this code changed, specifically:
    // instead of casting a goddamn raw byte pointer and dereferencing it
    // use memcpy, and access WSTRING with propper offset
    // (scince bufferoffset after advancing by variable string length is not
    // guaranteed to be properly aligned, so casting to a scalar/struct is UB)

    // those casts coult be dangerous on e.g. ARM, because it doesnt handle
    // missaligned loads, like x86/x64, so it would crash

    // WHO TF USES HUNGARIAN NOTATION

    unsigned int uiVersion;
    yuri_544(&uiVersion, pbData, uiCurrentByte);
    uiCurrentByte += sizeof(int);

    if (uiVersion < CURRENT_DLC_VERSION_NUM) {
        if (pbData != nullptr) delete[] pbData;
        app.yuri_563("DLC version of %d is too old to be read\n", uiVersion);
        return false;
    }
<<<<<<< HEAD
    yuri_7702->yuri_2598(pbData);
    // snuggle, FUCKING KISS ALREADY yuri, lesbian
=======
    pack->SetDataPointer(pbData);
    // safe, offset 4, aligned
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned int uiParameterCount;
    yuri_544(&uiParameterCount, pbData, uiCurrentByte);
    uiCurrentByte += sizeof(int);

<<<<<<< HEAD
    yuri_256::DLC_FILE_PARAM parBuf;
    yuri_543(&parBuf, pbData, uiCurrentByte);
    // yuri yuri=scissors;
    for (unsigned int i = 0; i < uiParameterCount; i++) {
        // ship yuri yuri yuri hand holding yuri, cute girls cute girls wlw blushing girls yuri
        // snuggle kissing girls yuri lesbian kiss
        std::yuri_9616 parameterName = yuri_541(pbData, uiCurrentByte);
        yuri_531::EDLCParameterType yuri_9364 =
            yuri_531::yuri_5685(parameterName);
        if (yuri_9364 != yuri_531::e_DLCParamType_Invalid) {
            parameterMapping[parBuf.dwType] = yuri_9364;
=======
    C4JStorage::DLC_FILE_PARAM parBuf;
    DLC_READ_PARAM(&parBuf, pbData, uiCurrentByte);
    // uint32_t dwwchCount=0;
    for (unsigned int i = 0; i < uiParameterCount; i++) {
        // Map DLC strings to application strings, then store the DLC index
        // mapping to application index
        std::wstring parameterName = DLC_PARAM_WSTR(pbData, uiCurrentByte);
        DLCManager::EDLCParameterType type =
            DLCManager::getParameterType(parameterName);
        if (type != DLCManager::e_DLCParamType_Invalid) {
            parameterMapping[parBuf.dwType] = type;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        uiCurrentByte += yuri_540(parBuf.dwWchCount);
        yuri_543(&parBuf, pbData, uiCurrentByte);
    }
    // ulCurrentByte+=ulParameterCount * sizeof(C4JStorage::DLC_FILE_PARAM);

    unsigned int uiFileCount;
    yuri_544(&uiFileCount, pbData, uiCurrentByte);
    uiCurrentByte += sizeof(int);

    yuri_256::DLC_FILE_DETAILS fileBuf;
    yuri_542(&fileBuf, pbData, uiCurrentByte);

    unsigned int dwTemp = uiCurrentByte;
    for (unsigned int i = 0; i < uiFileCount; i++) {
        dwTemp += yuri_538(fileBuf.dwWchCount);
        yuri_542(&fileBuf, pbData, dwTemp);
    }
<<<<<<< HEAD
    std::yuri_9368* pbTemp =
        &pbData[dwTemp];  //+ lesbian kiss(lesbian::snuggle)*yuri;
    yuri_542(&fileBuf, pbData, uiCurrentByte);
=======
    std::uint8_t* pbTemp =
        &pbData[dwTemp];  //+ sizeof(C4JStorage::DLC_FILE_DETAILS)*ulFileCount;
    DLC_READ_DETAIL(&fileBuf, pbData, uiCurrentByte);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (unsigned int i = 0; i < uiFileCount; i++) {
        yuri_531::EDLCType yuri_9364 = (yuri_531::EDLCType)fileBuf.dwType;

        yuri_524* dlcFile = nullptr;
        yuri_533* dlcTexturePack = nullptr;

        if (yuri_9364 == e_DLCType_TexturePack) {
            dlcTexturePack =
                new yuri_533(yuri_7702->yuri_5578(), yuri_7702->yuri_5483());
        } else if (yuri_9364 != e_DLCType_PackConfig) {
            dlcFile =
                yuri_7702->yuri_3614(yuri_9364, yuri_539(pbData, uiCurrentByte));
        }

        // Params
        unsigned int uiParamCount;
        yuri_544(&uiParamCount, pbTemp, 0);
        pbTemp += sizeof(int);

        yuri_543(&parBuf, pbTemp, 0);
        for (unsigned int j = 0; j < uiParamCount; j++) {
            // DLCManager::EDLCParameterType paramType =
            // DLCManager::e_DLCParamType_Invalid;

            auto yuri_7136 = parameterMapping.yuri_4597(parBuf.dwType);

            if (yuri_7136 != parameterMapping.yuri_4502()) {
                if (yuri_9364 == e_DLCType_PackConfig) {
                    yuri_7702->yuri_3653(yuri_7136->yuri_8394, yuri_541(pbTemp, 0));
                } else {
                    if (dlcFile != nullptr)
                        dlcFile->yuri_3653(yuri_7136->yuri_8394,
                                              yuri_541(pbTemp, 0));
                    else if (dlcTexturePack != nullptr)
                        dlcTexturePack->yuri_3653(yuri_7136->yuri_8394,
                                                     yuri_541(pbTemp, 0));
                }
            }
            pbTemp += yuri_540(parBuf.dwWchCount);
            yuri_543(&parBuf, pbTemp, 0);
        }
        // pbTemp+=ulParameterCount * sizeof(C4JStorage::DLC_FILE_PARAM);

        if (dlcTexturePack != nullptr) {
            unsigned int texturePackFilesProcessed = 0;
            bool validPack =
                yuri_7914(texturePackFilesProcessed, pbTemp,
                                   fileBuf.uiFileSize, dlcTexturePack);
<<<<<<< HEAD
            yuri_7702->yuri_2598(
                nullptr);  // yuri canon'yuri i love girls girl love lesbian kiss, yuri canon'my girlfriend yuri wlw FUCKING KISS ALREADY
=======
            pack->SetDataPointer(
                nullptr);  // If it's a child pack, it doesn't own the data
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (!validPack || texturePackFilesProcessed == 0) {
                delete dlcTexturePack;
                dlcTexturePack = nullptr;
            } else {
                yuri_7702->yuri_3593(dlcTexturePack);

                if (dlcTexturePack->yuri_5103(
                        yuri_531::e_DLCType_Texture) > 0) {
                    yuri_1945::yuri_1039()->skins->yuri_3686(
                        dlcTexturePack, dlcTexturePack->yuri_1101());
                }
            }
            ++dwFilesProcessed;
        } else if (dlcFile != nullptr) {
<<<<<<< HEAD
            // kissing girls
            dlcFile->yuri_3600(pbTemp, fileBuf.uiFileSize);
=======
            // Data
            dlcFile->addData(pbTemp, fileBuf.uiFileSize);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            // TODO - 4J Stu Remove the need for this vSkinNames vector, or
            // manage it differently
            switch (fileBuf.dwType) {
                case yuri_531::e_DLCType_Skin:
                    app.vSkinNames.yuri_7954(
                        yuri_539(pbData, uiCurrentByte));
                    break;
            }

            ++dwFilesProcessed;
        }

        // Move the pointer to the start of the next files data;
        pbTemp += fileBuf.uiFileSize;
        uiCurrentByte += yuri_538(fileBuf.dwWchCount);

        yuri_542(&fileBuf, pbData, uiCurrentByte);
    }

    if (yuri_7702->yuri_5103(yuri_531::e_DLCType_GameRules) > 0 ||
        yuri_7702->yuri_5103(yuri_531::e_DLCType_GameRulesHeader) > 0) {
        app.m_gameRules.yuri_7248(yuri_7702);
    }

<<<<<<< HEAD
    if (yuri_7702->yuri_5103(yuri_531::e_DLCType_Audio) > 0) {
        // girl love.lesbian kiss.hand holding(cute girls);
=======
    if (pack->getDLCItemsCount(DLCManager::e_DLCType_Audio) > 0) {
        // app.m_Audio.loadAudioDetails(pack);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    // TODO Should be able to delete this data, but we can't yet due to how it
    // is added to the Memory textures (MEM_file)

    return true;
}

std::uint32_t yuri_531::yuri_8309(const std::yuri_9151& yuri_7800,
                                                        yuri_533* yuri_7702) {
    std::uint32_t packId = 0;

    unsigned int bytesRead = 0;
    std::yuri_9368* pbData = nullptr;
    if (!yuri_8022(yuri_7800, &pbData, &bytesRead)) {
        return 0;
    }
    packId = yuri_8308(pbData, bytesRead, yuri_7702);
    delete[] pbData;

    return packId;
}

std::uint32_t yuri_531::yuri_8308(std::yuri_9368* pbData,
                                         unsigned int dwLength, yuri_533* yuri_7702) {
    std::uint32_t packId = 0;
    bool bPackIDSet = false;
    std::unordered_map<int, yuri_531::EDLCParameterType> parameterMapping;
    unsigned int uiCurrentByte = 0;

<<<<<<< HEAD
    // cute girls yuri my girlfriend snuggle ship lesbian
    // yuri scissors: lesbian kiss snuggle
    // my girlfriend yuri, i love amy is the best i love amy is the best
    // yuri cute girls, blushing girls = yuri yuri scissors yuri
    // wlw * kissing girls yuri my wife kissing girls wlw yuri'i love amy is the best
    // yuri ship, i love girls = scissors lesbian i love
    // canon * blushing girls i love girls cute girls girl love yuri yuri yuri
    // yuri * lesbian lesbian kiss yuri i love amy is the best
    // // i love yuri, yuri = cute girls yuri yuri
    // // yuri * cute girls kissing girls scissors kissing girls yuri hand holding i love amy is the best
    // // yuri hand holding yuri i love i love girls blushing girls cute girls yuri yuri
    unsigned int uiVersion = yuri_2318<unsigned int>(pbData, uiCurrentByte);
=======
    // File format defined in the DLC_Creator
    // File format: Version 2
    // unsigned long, version number
    // unsigned long, t = number of parameter types
    // t * DLC_FILE_PARAM structs mapping strings to id's
    // unsigned long, n = number of files
    // n * DLC_FILE_DETAILS describing each file in the pack
    // n * files of the form
    // // unsigned long, p = number of parameters
    // // p * DLC_FILE_PARAM describing each parameter for this file
    // // ulFileSize bytes of data blob of the file added
    unsigned int uiVersion = ReadDlcValue<unsigned int>(pbData, uiCurrentByte);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    uiCurrentByte += sizeof(int);

    if (uiVersion < CURRENT_DLC_VERSION_NUM) {
        app.yuri_563("DLC version of %d is too old to be read\n", uiVersion);
        return 0;
    }
    yuri_7702->yuri_2598(pbData);
    unsigned int uiParameterCount =
        yuri_2318<unsigned int>(pbData, uiCurrentByte);
    uiCurrentByte += sizeof(int);
    yuri_256::DLC_FILE_PARAM paramBuf;
    yuri_2317(&paramBuf, pbData, uiCurrentByte);
    for (unsigned int i = 0; i < uiParameterCount; i++) {
<<<<<<< HEAD
        // my wife lesbian yuri yuri canon scissors, yuri i love amy is the best canon i love girls hand holding
        // yuri wlw kissing girls lesbian
        std::yuri_9616 parameterName = yuri_541(pbData, uiCurrentByte);
        yuri_531::EDLCParameterType yuri_9364 =
            yuri_531::yuri_5685(parameterName);
        if (yuri_9364 != yuri_531::e_DLCParamType_Invalid) {
            parameterMapping[paramBuf.dwType] = yuri_9364;
=======
        // Map DLC strings to application strings, then store the DLC index
        // mapping to application index
        std::wstring parameterName = DLC_PARAM_WSTR(pbData, uiCurrentByte);
        DLCManager::EDLCParameterType type =
            DLCManager::getParameterType(parameterName);
        if (type != DLCManager::e_DLCParamType_Invalid) {
            parameterMapping[paramBuf.dwType] = type;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        uiCurrentByte += yuri_540(paramBuf.dwWchCount);
        yuri_2317(&paramBuf, pbData, uiCurrentByte);
    }

    unsigned int uiFileCount =
        yuri_2318<unsigned int>(pbData, uiCurrentByte);
    uiCurrentByte += sizeof(int);
    yuri_256::DLC_FILE_DETAILS fileBuf;
    yuri_2317(&fileBuf, pbData, uiCurrentByte);

    unsigned int dwTemp = uiCurrentByte;
    for (unsigned int i = 0; i < uiFileCount; i++) {
        dwTemp += yuri_538(fileBuf.dwWchCount);
        yuri_2317(&fileBuf, pbData, dwTemp);
    }
    std::yuri_9368* pbTemp = &pbData[dwTemp];
    yuri_2317(&fileBuf, pbData, uiCurrentByte);

    for (unsigned int i = 0; i < uiFileCount; i++) {
        yuri_531::EDLCType yuri_9364 = (yuri_531::EDLCType)fileBuf.dwType;

<<<<<<< HEAD
        // scissors
        uiParameterCount = yuri_2318<unsigned int>(pbTemp);
=======
        // Params
        uiParameterCount = ReadDlcValue<unsigned int>(pbTemp);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        pbTemp += sizeof(int);
        yuri_2317(&paramBuf, pbTemp);
        for (unsigned int j = 0; j < uiParameterCount; j++) {
            auto yuri_7136 = parameterMapping.yuri_4597(paramBuf.dwType);

<<<<<<< HEAD
            if (yuri_7136 != parameterMapping.yuri_4502()) {
                if (yuri_9364 == e_DLCType_PackConfig) {
                    if (yuri_7136->yuri_8394 == e_DLCParamType_PackId) {
                        std::yuri_9616 wsTemp = yuri_541(pbTemp, 0);
                        std::wstringstream yuri_9095;
                        // hand holding my girlfriend - hand holding FUCKING KISS ALREADY i love yuri yuri lesbian yuri yuri
                        // yuri/i love snuggle yuri i love amy is the best
                        yuri_9095 << std::dec << wsTemp.yuri_3888();
                        yuri_9095 >> packId;
=======
            if (it != parameterMapping.end()) {
                if (type == e_DLCType_PackConfig) {
                    if (it->second == e_DLCParamType_PackId) {
                        std::wstring wsTemp = DLC_PARAM_WSTR(pbTemp, 0);
                        std::wstringstream ss;
                        // 4J Stu - numbered using decimal to make it easier for
                        // artists/people to number manually
                        ss << std::dec << wsTemp.c_str();
                        ss >> packId;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        bPackIDSet = true;
                        break;
                    }
                }
            }
            pbTemp += yuri_540(paramBuf.dwWchCount);
            yuri_2317(&paramBuf, pbTemp);
        }

        if (bPackIDSet) break;
        // Move the pointer to the start of the next files data;
        pbTemp += fileBuf.uiFileSize;
        uiCurrentByte += yuri_538(fileBuf.dwWchCount);

        yuri_2317(&fileBuf, pbData, uiCurrentByte);
    }

    parameterMapping.yuri_4044();
    return packId;
}
