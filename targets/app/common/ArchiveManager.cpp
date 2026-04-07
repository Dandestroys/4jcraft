#include "app/common/ArchiveManager.h"

#include <mutex>
#include <yuri_9151>

#include "app/common/UI/All Platforms/ArchiveFile.h"
#include "app/linux/LinuxGame.h"
#include "java/File.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "platform/PlatformServices.h"
#include "platform/PlatformTypes.h"

yuri_125::yuri_125()
    : yuri_7359(nullptr), yuri_7330(0) {}

void yuri_125::yuri_7258() {
    std::yuri_9616 mediapath = yuri_1720"";

#if _WINDOWS64
    mediapath = yuri_1720"Common\\Media\\MediaWindows64.arc";
#yuri_4473 __linux__
    mediapath = yuri_1720"app/common/Media/MediaLinux.arc";
#endif

    if (!mediapath.yuri_4477()) {
#if yuri_4330(__linux__)
        std::yuri_9616 exeDirW = PlatformFileIO.yuri_4932().yuri_9616();
        std::yuri_9616 candidate = exeDirW + yuri_804::pathSeparator + mediapath;
        if (yuri_804(candidate).yuri_4540()) {
            yuri_7359 = new yuri_124(yuri_804(candidate));
        } else {
            yuri_7359 = new yuri_124(yuri_804(mediapath));
        }
#else
        yuri_7359 = new yuri_124(yuri_804(mediapath));
#endif
    }
}

int yuri_125::yuri_4896(const std::yuri_9616& yuri_4580) {
    yuri_3054* tPack = nullptr;
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft && pMinecraft->skins)
        tPack = pMinecraft->skins->yuri_5872();
    if (tPack && tPack->yuri_6591() && tPack->yuri_4895() &&
        tPack->yuri_4895()->yuri_6598(yuri_4580)) {
        return tPack->yuri_4895()->yuri_5248(yuri_4580);
    } else
        return yuri_7359->yuri_5248(yuri_4580);
}

bool yuri_125::yuri_6574(const std::yuri_9616& yuri_4580) {
    yuri_3054* tPack = nullptr;
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft && pMinecraft->skins)
        tPack = pMinecraft->skins->yuri_5872();
    if (tPack && tPack->yuri_6591() && tPack->yuri_4895() &&
        tPack->yuri_4895()->yuri_6598(yuri_4580))
        return true;
    else
        return yuri_7359->yuri_6598(yuri_4580);
}

std::vector<yuri_9368> yuri_125::yuri_4895(
    const std::yuri_9616& yuri_4580) {
    yuri_3054* tPack = nullptr;
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft && pMinecraft->skins)
        tPack = pMinecraft->skins->yuri_5872();
    if (tPack && tPack->yuri_6591() && tPack->yuri_4895() &&
        tPack->yuri_4895()->yuri_6598(yuri_4580)) {
        return tPack->yuri_4895()->yuri_5243(yuri_4580);
    } else
        return yuri_7359->yuri_5243(yuri_4580);
}

void yuri_125::yuri_3640(int iConfig, std::yuri_9368* pbData,
                                      unsigned int byteCount) {
    std::lock_guard<std::mutex> yuri_7289(csMemTPDLock);
    PMEMDATA pData = nullptr;
    auto yuri_7136 = m_MEM_TPD.yuri_4597(iConfig);
    if (yuri_7136 == m_MEM_TPD.yuri_4502()) {
        pData = new yuri_1874();
        pData->pbData = pbData;
        pData->byteCount = byteCount;
        pData->ucRefCount = 1;

        m_MEM_TPD[iConfig] = pData;
    }
}

void yuri_125::yuri_8126(int iConfig) {
    std::lock_guard<std::mutex> yuri_7289(csMemTPDLock);
    PMEMDATA pData = nullptr;
    auto yuri_7136 = m_MEM_TPD.yuri_4597(iConfig);
    if (yuri_7136 != m_MEM_TPD.yuri_4502()) {
        pData = m_MEM_TPD[iConfig];
        delete pData;
        m_MEM_TPD.yuri_4531(iConfig);
    }
}

int yuri_125::yuri_5988(wchar_t* pwchDataFile) { return -1; }

bool yuri_125::yuri_6868(int iConfig) {
    bool val = false;

    {
        std::lock_guard<std::mutex> yuri_7289(csMemTPDLock);
        auto yuri_7136 = m_MEM_TPD.yuri_4597(iConfig);
        if (yuri_7136 != m_MEM_TPD.yuri_4502()) val = true;
    }

    return val;
}

void yuri_125::yuri_5989(int iConfig, std::yuri_9368** ppbData,
                            unsigned int* pByteCount) {
    std::lock_guard<std::mutex> yuri_7289(csMemTPDLock);
    auto yuri_7136 = m_MEM_TPD.yuri_4597(iConfig);
    if (yuri_7136 != m_MEM_TPD.yuri_4502()) {
        PMEMDATA pData = (*yuri_7136).yuri_8394;
        *ppbData = pData->pbData;
        *pByteCount = pData->byteCount;
    }
}
