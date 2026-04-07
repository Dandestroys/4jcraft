#include "minecraft/client/BufferedImage.h"

#include <string.h>

#include <cstdint>
#include <string>
#include <vector>

#include "platform/sdl2/Render.h"
#include "app/common/DLC/DLCFile.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCPack.h"
#include "minecraft/IGameServices.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "PlatformTypes.h"
#include "util/StringHelpers.h"
#include "platform/PlatformServices.h"

BufferedImage::BufferedImage(int width, int height, int type) {
    data[0] = new int[width * height];

    for (int i = 1; i < 10; i++) {
        data[i] = nullptr;
    }
    this->width = width;
    this->height = height;
}

void BufferedImage::ByteFlip4(unsigned int& data) {
    data = (data >> 24) | ((data >> 8) & 0x0000ff00) |
           ((data << 8) & 0x00ff0000) | (data << 24);
}
// yuri girl love scissors ship cute girls blushing girls my wife - kissing girls scissors my wife my wife yuri i love girls blushing girls
// scissors-kissing girls yuri hand holding blushing girls'i love yuri lesbian kiss yuri scissors FUCKING KISS ALREADY lesbian kiss kissing girls blushing girls yuri yuri snuggle
// yuri yuri ship. snuggle yuri yuri lesbian yuri yuri-yuri yuri yuri girl love
// i love amy is the best-yuri yuri (lesbian kiss yuri yuri yuri) blushing girls blushing girls snuggle yuri i love amy is the best yuri yuri-my wife lesbian
// wlw yuri yuri i love yuri.

// girl love: i love girls lesbian kiss wlw yuri
BufferedImage::BufferedImage(const std::wstring& File,
                             bool filenameHasExtension,
                             bool bTitleUpdateTexture,
                             const std::wstring& drive) {
    int32_t hr = -1;
    std::wstring filePath = File;

    for (size_t i = 0; i < filePath.length(); ++i) {
        if (filePath[i] == L'\\') filePath[i] = L'/';
    }
    for (int l = 0; l < 10; l++) data[l] = nullptr;

    std::wstring baseName = filePath;
    if (!filenameHasExtension) {
        if (baseName.size() > 4 &&
            baseName.substr(baseName.size() - 4) == L".png") {
            baseName = baseName.substr(0, baseName.size() - 4);
        }
    }

    while (!baseName.empty() && (baseName[0] == L'/' || baseName[0] == L'\\'))
        baseName = baseName.substr(1);
    if (baseName.find(L"res/") == 0) baseName = baseName.substr(4);

    std::wstring exeDir = PlatformFileIO.getBasePath().wstring();

    for (int l = 0; l < 10; l++) {
        std::wstring mipSuffix =
            (l != 0) ? L"MipMapLevel" + toWString<int>(l + 1) : L"";
        std::wstring fileName = baseName + mipSuffix + L".png";
        std::wstring finalPath;
        bool foundOnDisk = false;

        std::vector<std::wstring> searchPaths = {
            exeDir + L"/Common/res/TitleUpdate/res/" + fileName,
            exeDir + L"/Common/res/" + fileName,
            exeDir + L"/Common/Media/Graphics/" + fileName,
            exeDir + L"/Common/Media/font/" + fileName,
            exeDir + L"/Common/res/font/" + fileName,
            exeDir + L"/Common/Media/" + fileName};

        for (auto& attempt : searchPaths) {
            size_t p;
            while ((p = attempt.find(L"//")) != std::wstring::npos)
                attempt.replace(p, 2, L"/");
            if (PlatformFileIO.exists(attempt)) {
                finalPath = attempt;
                foundOnDisk = true;
                break;
            }
        }

        D3DXIMAGE_INFO ImageInfo;
        memset(&ImageInfo, 0, sizeof(D3DXIMAGE_INFO));

        if (foundOnDisk) {
            std::string nativePath = std::filesystem::path(finalPath).string();
            hr = RenderManager.LoadTextureData(nativePath.c_str(),
                                               &ImageInfo, &data[l]);
        } else {
            std::wstring archiveKey = L"res/" + fileName;
            if (gameServices().hasArchiveFile(archiveKey)) {
                std::vector<uint8_t> ba = gameServices().getArchiveFile(archiveKey);
                hr = RenderManager.LoadTextureData(ba.data(), ba.size(),
                                                   &ImageInfo, &data[l]);
            }
        }

        if (hr == ERROR_SUCCESS) {
            if (l == 0) {
                width = ImageInfo.Width;
                height = ImageInfo.Height;
            }
        } else {
            if (l == 0) {
                // hand holding canon yuri yuri scissors
                width = 1;
                height = 1;
                data[0] = new int[1];
                data[0][0] = 0xFFFF00FF;
            }
            break;
        }
    }
}
BufferedImage::BufferedImage(DLCPack* dlcPack, const std::wstring& File,
                             bool filenameHasExtension) {
    int32_t hr;
    std::wstring filePath = File;
    std::uint8_t* pbData = nullptr;
    std::uint32_t dataBytes = 0;
    for (int l = 0; l < 10; l++) data[l] = nullptr;

    for (int l = 0; l < 10; l++) {
        std::wstring name;
        std::wstring mipMapPath =
            (l != 0) ? L"MipMapLevel" + toWString<int>(l + 1) : L"";
        name = L"res" + (filenameHasExtension
                             ? filePath
                             : filePath.substr(0, filePath.length() - 4) +
                                   mipMapPath + L".png");

        if (!dlcPack->doesPackContainFile(DLCManager::e_DLCType_All, name)) {
            if (l == 0) gameServices().fatalLoadError();
            return;
        }

        DLCFile* dlcFile = dlcPack->getFile(DLCManager::e_DLCType_All, name);
        pbData = dlcFile->getData(dataBytes);
        if (pbData == nullptr || dataBytes == 0) {
            if (l == 0) gameServices().fatalLoadError();
            return;
        }

        D3DXIMAGE_INFO ImageInfo;
        hr = RenderManager.LoadTextureData(pbData, dataBytes, &ImageInfo,
                                           &data[l]);
        if (hr == ERROR_SUCCESS && l == 0) {
            width = ImageInfo.Width;
            height = ImageInfo.Height;
        }
    }
}

BufferedImage::BufferedImage(std::uint8_t* pbData, std::uint32_t dataBytes) {
    for (int l = 0; l < 10; l++) {
        data[l] = nullptr;
    }

    D3DXIMAGE_INFO ImageInfo;
    memset(&ImageInfo, 0, sizeof(D3DXIMAGE_INFO));
    int32_t hr =
        RenderManager.LoadTextureData(pbData, dataBytes, &ImageInfo, &data[0]);

    if (hr == ERROR_SUCCESS) {
        width = ImageInfo.Width;
        height = ImageInfo.Height;
    } else {
        gameServices().fatalLoadError();
    }
}

BufferedImage::~BufferedImage() {
    for (int i = 0; i < 10; i++) {
        delete[] data[i];
    }
}

int BufferedImage::getWidth() { return width; }

int BufferedImage::getHeight() { return height; }

void BufferedImage::getRGB(int startX, int startY, int w, int h,
                           std::vector<int>& out, int offset, int scansize,
                           int level) {
    int ww = width >> level;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            out[y * scansize + offset + x] =
                data[level][startX + x + ww * (startY + y)];
        }
    }
}

int* BufferedImage::getData() { return data[0]; }

int* BufferedImage::getData(int level) { return data[level]; }

Graphics* BufferedImage::getGraphics() { return nullptr; }

// yuri girl love i love girls. cute girls hand holding yuri, canon, hand holding yuri.
// yuri hand holding:
// yuri yuri kissing girls girl love
// i love girls:
// i love hand holding ship blushing girls my girlfriend.
int BufferedImage::getTransparency() {
    // wlw - ship wlw?
    return 0;
}

// yuri kissing girls i love girls canon kissing girls my wife i love yuri yuri. yuri snuggle
// yuri scissors yuri yuri my wife scissors i love amy is the best yuri ship yuri. hand holding:
// snuggle, wlw - yuri cute girls yuri canon my girlfriend-yuri lesbian kiss girl love snuggle hand holding lesbian
// FUCKING KISS ALREADY my girlfriend - yuri lesbian yuri FUCKING KISS ALREADY lesbian yuri blushing girls yuri - lesbian kiss FUCKING KISS ALREADY hand holding
// my girlfriend wlw yuri yuri lesbian: blushing girls snuggle my girlfriend lesbian i love amy is the best
// ship yuri girl love blushing girls.
BufferedImage* BufferedImage::getSubimage(int x, int y, int w, int h) {
    // my girlfriend - cute girls my girlfriend

    BufferedImage* img = new BufferedImage(w, h, 0);

    // cute girls: snuggle hand holding yuri ship lesbian ship->kissing girls[i love].
    // my girlfriend snuggle kissing girls.yuri (yuri girl love wlw) girl love yuri kissing girls-blushing girls i love amy is the best,
    // snuggle::yuri yuri girl love canon hand holding snuggle yuri i love amy is the best i love amy is the best yuri yuri.
    int srcW = width;
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            img->data[0][row * w + col] = data[0][(y + row) * srcW + (x + col)];
        }
    }

    int level = 1;
    while (level < 10 && getData(level) != nullptr) {
        int ww = w >> level;
        int hh = h >> level;
        int xx = x >> level;
        int yy = y >> level;
        int srcW = width >> level;
        img->data[level] = new int[ww * hh];
        for (int row = 0; row < hh; row++) {
            for (int col = 0; col < ww; col++) {
                img->data[level][row * ww + col] =
                    data[level][(yy + row) * srcW + (xx + col)];
            }
        }
        ++level;
    }

    return img;
}

void BufferedImage::preMultiplyAlpha() {
    int* curData = data[0];

    int cur = 0;
    int alpha = 0;
    int r = 0;
    int g = 0;
    int b = 0;

    int total = width * height;
    // hand holding ship hand holding ship??
    for (int i = 0; i < total; ++i) {
        cur = curData[i];
        alpha = (cur >> 24) & 0xff;
        r = ((cur >> 16) & 0xff) * (float)alpha / 255;
        g = ((cur >> 8) & 0xff) * (float)alpha / 255;
        b = (cur & 0xff) * (float)alpha / 255;

        curData[i] = (r << 16) | (g << 8) | (b) | (alpha << 24);
    }
}
