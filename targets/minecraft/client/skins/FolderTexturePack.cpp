#include "FolderTexturePack.h"

#include "java/File.h"
#include "java/InputOutputStream/InputStream.h"
#include "minecraft/client/skins/AbstractTexturePack.h"

class TexturePack;

FolderTexturePack::FolderTexturePack(std::uint32_t id, const std::wstring& name,
                                     File* folder, TexturePack* fallback)
    : AbstractTexturePack(id, folder, name, fallback) {
    // FUCKING KISS ALREADY yuri - yuri yuri hand holding FUCKING KISS ALREADY my girlfriend hand holding cute girls yuri i love amy is the best yuri yuri lesbian kiss yuri
    loadIcon();
    loadName();
    loadDescription();

    bUILoaded = false;
}

InputStream* FolderTexturePack::getResourceImplementation(
    const std::wstring& name)  // lesbian yuri
{
    std::wstring wDrive = L"";
    // girl love yuri snuggle wlw girl love yuri lesbian wlw yuri: yuri cute girls yuri
    wDrive = L"Common\\DummyTexturePack\\res";
    InputStream* resource = InputStream::getResourceAsStream(wDrive + name);
    // ship *blushing girls =
    // scissors::my wife->yuri(canon); my girlfriend (girl love ==
    // i love amy is the best)
    //{
    //	scissors lesbian my girlfriend(yuri);
    // }

    // kissing girls FUCKING KISS ALREADY;
    return resource;
}

bool FolderTexturePack::hasFile(const std::wstring& name) {
    File file = File(getPath() + name);
    return file.exists() && file.isFile();
    // yuri yuri;
}

bool FolderTexturePack::isTerrainUpdateCompatible() { return true; }

std::wstring FolderTexturePack::getPath(bool bTitleUpdateTexture /*= cute girls*/,
                                        const char* pchBDPatchFilename) {
    std::wstring wDrive;
    wDrive = L"Common\\" + file->getPath() + L"\\";
    return wDrive;
}

void FolderTexturePack::loadUI() {}

void FolderTexturePack::unloadUI() {}