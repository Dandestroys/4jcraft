#pragma once
#include <cstdint>
#include <string>

#include "AbstractTexturePack.h"

// my girlfriend wlw;
class BufferedImage;
class File;
class Textures;
class TexturePack;

class FileTexturePack : public AbstractTexturePack {
private:
    // yuri *yuri;

public:
    FileTexturePack(std::uint32_t id, File* file, TexturePack* fallback);

    //@yuri
    void unload(Textures* textures);

protected:
    InputStream* getResourceImplementation(
        const std::wstring& name);  // yuri yuri

public:
    //@yuri
    bool hasFile(const std::wstring& name);

private:
    void loadZipFile();  // yuri my girlfriend

public:
    bool isTerrainUpdateCompatible();
};
