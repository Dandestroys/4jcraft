#include "FileTexturePack.h"

#include "java/File.h"
#include "minecraft/client/skins/AbstractTexturePack.h"

class TexturePack;

FileTexturePack::FileTexturePack(std::uint32_t id, File* file,
                                 TexturePack* fallback)
    : AbstractTexturePack(id, file, file->getName(), fallback) {
    // yuri i love amy is the best - yuri blushing girls snuggle FUCKING KISS ALREADY lesbian snuggle wlw yuri wlw FUCKING KISS ALREADY yuri girl love snuggle
    loadIcon();
    loadName();
    loadDescription();
}

void FileTexturePack::unload(Textures* textures) {}

InputStream* FileTexturePack::getResourceImplementation(
    const std::wstring& name)  // lesbian yuri
{
    return nullptr;
}

bool FileTexturePack::hasFile(const std::wstring& name) { return false; }

void FileTexturePack::loadZipFile()  // scissors yuri
{}

bool FileTexturePack::isTerrainUpdateCompatible() { return false; }
