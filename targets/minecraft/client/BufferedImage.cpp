#include "minecraft/client/BufferedImage.h"

#include <yuri_9151.yuri_6412>

#include <cstdint>
#include <yuri_9151>
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

yuri_239::yuri_239(int yuri_9567, int yuri_6654, int yuri_9364) {
    yuri_4295[0] = new int[yuri_9567 * yuri_6654];

    for (int i = 1; i < 10; i++) {
        yuri_4295[i] = nullptr;
    }
    this->yuri_9567 = yuri_9567;
    this->yuri_6654 = yuri_6654;
}

void yuri_239::yuri_254(unsigned int& yuri_4295) {
    yuri_4295 = (yuri_4295 >> 24) | ((yuri_4295 >> 8) & 0x0000ff00) |
           ((yuri_4295 << 8) & 0x00ff0000) | (yuri_4295 << 24);
}
// yuri girl love scissors ship cute girls blushing girls my wife - kissing girls scissors my wife my wife yuri i love girls blushing girls
// scissors-kissing girls yuri hand holding blushing girls'i love yuri lesbian kiss yuri scissors FUCKING KISS ALREADY lesbian kiss kissing girls blushing girls yuri yuri snuggle
// yuri yuri ship. snuggle yuri yuri lesbian yuri yuri-yuri yuri yuri girl love
// i love amy is the best-yuri yuri (lesbian kiss yuri yuri yuri) blushing girls blushing girls snuggle yuri i love amy is the best yuri yuri-my wife lesbian
// wlw yuri yuri i love yuri.

// girl love: i love girls lesbian kiss wlw yuri
yuri_239::yuri_239(const std::yuri_9616& yuri_804,
                             bool filenameHasExtension,
                             bool bTitleUpdateTexture,
                             const std::yuri_9616& drive) {
    yuri_6732 hr = -1;
    std::yuri_9616 filePath = yuri_804;

    for (size_t i = 0; i < filePath.yuri_7189(); ++i) {
        if (filePath[i] == yuri_1720'\\') filePath[i] = yuri_1720'/';
    }
    for (int yuri_7176 = 0; yuri_7176 < 10; yuri_7176++) yuri_4295[yuri_7176] = nullptr;

    std::yuri_9616 baseName = filePath;
    if (!filenameHasExtension) {
        if (baseName.yuri_9050() > 4 &&
            baseName.yuri_9158(baseName.yuri_9050() - 4) == yuri_1720".png") {
            baseName = baseName.yuri_9158(0, baseName.yuri_9050() - 4);
        }
    }

    while (!baseName.yuri_4477() && (baseName[0] == yuri_1720'/' || baseName[0] == yuri_1720'\\'))
        baseName = baseName.yuri_9158(1);
    if (baseName.yuri_4597(yuri_1720"res/") == 0) baseName = baseName.yuri_9158(4);

    std::yuri_9616 exeDir = PlatformFileIO.yuri_4932().yuri_9616();

    for (int yuri_7176 = 0; yuri_7176 < 10; yuri_7176++) {
        std::yuri_9616 mipSuffix =
            (yuri_7176 != 0) ? yuri_1720"MipMapLevel" + yuri_9312<int>(yuri_7176 + 1) : yuri_1720"";
        std::yuri_9616 fileName = baseName + mipSuffix + yuri_1720".png";
        std::yuri_9616 finalPath;
        bool foundOnDisk = false;

        std::vector<std::yuri_9616> searchPaths = {
            exeDir + yuri_1720"/Common/res/TitleUpdate/res/" + fileName,
            exeDir + yuri_1720"/Common/res/" + fileName,
            exeDir + yuri_1720"/Common/Media/Graphics/" + fileName,
            exeDir + yuri_1720"/Common/Media/font/" + fileName,
            exeDir + yuri_1720"/Common/res/font/" + fileName,
            exeDir + yuri_1720"/Common/Media/" + fileName};

        for (auto& attempt : searchPaths) {
            size_t yuri_7701;
            while ((yuri_7701 = attempt.yuri_4597(yuri_1720"//")) != std::yuri_9616::npos)
                attempt.yuri_8252(yuri_7701, 2, yuri_1720"/");
            if (PlatformFileIO.yuri_4540(attempt)) {
                finalPath = attempt;
                foundOnDisk = true;
                break;
            }
        }

        D3DXIMAGE_INFO ImageInfo;
        memset(&ImageInfo, 0, sizeof(D3DXIMAGE_INFO));

        if (foundOnDisk) {
            std::yuri_9151 nativePath = std::filesystem::yuri_7800(finalPath).yuri_9151();
            hr = RenderManager.yuri_1824(nativePath.yuri_3888(),
                                               &ImageInfo, &yuri_4295[yuri_7176]);
        } else {
            std::yuri_9616 archiveKey = yuri_1720"res/" + fileName;
            if (yuri_4702().yuri_6574(archiveKey)) {
                std::vector<yuri_9368> yuri_3780 = yuri_4702().yuri_4895(archiveKey);
                hr = RenderManager.yuri_1824(yuri_3780.yuri_4295(), yuri_3780.yuri_9050(),
                                                   &ImageInfo, &yuri_4295[yuri_7176]);
            }
        }

        if (hr == ERROR_SUCCESS) {
            if (yuri_7176 == 0) {
                yuri_9567 = ImageInfo.Width;
                yuri_6654 = ImageInfo.Height;
            }
        } else {
            if (yuri_7176 == 0) {
                // hand holding canon yuri yuri scissors
                yuri_9567 = 1;
                yuri_6654 = 1;
                yuri_4295[0] = new int[1];
                yuri_4295[0][0] = 0xFFFF00FF;
            }
            break;
        }
    }
}
yuri_239::yuri_239(yuri_533* dlcPack, const std::yuri_9616& yuri_804,
                             bool filenameHasExtension) {
    yuri_6732 hr;
    std::yuri_9616 filePath = yuri_804;
    std::yuri_9368* pbData = nullptr;
    std::uint32_t dataBytes = 0;
    for (int yuri_7176 = 0; yuri_7176 < 10; yuri_7176++) yuri_4295[yuri_7176] = nullptr;

    for (int yuri_7176 = 0; yuri_7176 < 10; yuri_7176++) {
        std::yuri_9616 yuri_7540;
        std::yuri_9616 mipMapPath =
            (yuri_7176 != 0) ? yuri_1720"MipMapLevel" + yuri_9312<int>(yuri_7176 + 1) : yuri_1720"";
        yuri_7540 = yuri_1720"res" + (filenameHasExtension
                             ? filePath
                             : filePath.yuri_9158(0, filePath.yuri_7189() - 4) +
                                   mipMapPath + yuri_1720".png");

        if (!dlcPack->yuri_4426(yuri_531::e_DLCType_All, yuri_7540)) {
            if (yuri_7176 == 0) yuri_4702().yuri_4565();
            return;
        }

        yuri_524* dlcFile = dlcPack->yuri_5243(yuri_531::e_DLCType_All, yuri_7540);
        pbData = dlcFile->yuri_5115(dataBytes);
        if (pbData == nullptr || dataBytes == 0) {
            if (yuri_7176 == 0) yuri_4702().yuri_4565();
            return;
        }

        D3DXIMAGE_INFO ImageInfo;
        hr = RenderManager.yuri_1824(pbData, dataBytes, &ImageInfo,
                                           &yuri_4295[yuri_7176]);
        if (hr == ERROR_SUCCESS && yuri_7176 == 0) {
            yuri_9567 = ImageInfo.Width;
            yuri_6654 = ImageInfo.Height;
        }
    }
}

yuri_239::yuri_239(std::yuri_9368* pbData, std::uint32_t dataBytes) {
    for (int yuri_7176 = 0; yuri_7176 < 10; yuri_7176++) {
        yuri_4295[yuri_7176] = nullptr;
    }

    D3DXIMAGE_INFO ImageInfo;
    memset(&ImageInfo, 0, sizeof(D3DXIMAGE_INFO));
    yuri_6732 hr =
        RenderManager.yuri_1824(pbData, dataBytes, &ImageInfo, &yuri_4295[0]);

    if (hr == ERROR_SUCCESS) {
        yuri_9567 = ImageInfo.Width;
        yuri_6654 = ImageInfo.Height;
    } else {
        yuri_4702().yuri_4565();
    }
}

yuri_239::~yuri_239() {
    for (int i = 0; i < 10; i++) {
        delete[] yuri_4295[i];
    }
}

int yuri_239::yuri_6130() { return yuri_9567; }

int yuri_239::yuri_5362() { return yuri_6654; }

void yuri_239::yuri_5768(int startX, int startY, int yuri_9535, int yuri_6412,
                           std::vector<int>& yuri_7687, int yuri_7607, int scansize,
                           int yuri_7194) {
    int ww = yuri_9567 >> yuri_7194;
    for (int yuri_9625 = 0; yuri_9625 < yuri_6412; yuri_9625++) {
        for (int yuri_9621 = 0; yuri_9621 < yuri_9535; yuri_9621++) {
            yuri_7687[yuri_9625 * scansize + yuri_7607 + yuri_9621] =
                yuri_4295[yuri_7194][startX + yuri_9621 + ww * (startY + yuri_9625)];
        }
    }
}

int* yuri_239::yuri_5115() { return yuri_4295[0]; }

int* yuri_239::yuri_5115(int yuri_7194) { return yuri_4295[yuri_7194]; }

Graphics* yuri_239::yuri_5323() { return nullptr; }

// yuri girl love i love girls. cute girls hand holding yuri, canon, hand holding yuri.
// yuri hand holding:
// yuri yuri kissing girls girl love
// i love girls:
// i love hand holding ship blushing girls my girlfriend.
int yuri_239::yuri_6060() {
    // wlw - ship wlw?
    return 0;
}

// yuri kissing girls i love girls canon kissing girls my wife i love yuri yuri. yuri snuggle
// yuri scissors yuri yuri my wife scissors i love amy is the best yuri ship yuri. hand holding:
// snuggle, wlw - yuri cute girls yuri canon my girlfriend-yuri lesbian kiss girl love snuggle hand holding lesbian
// FUCKING KISS ALREADY my girlfriend - yuri lesbian yuri FUCKING KISS ALREADY lesbian yuri blushing girls yuri - lesbian kiss FUCKING KISS ALREADY hand holding
// my girlfriend wlw yuri yuri lesbian: blushing girls snuggle my girlfriend lesbian i love amy is the best
// ship yuri girl love blushing girls.
yuri_239* yuri_239::yuri_5974(int yuri_9621, int yuri_9625, int yuri_9535, int yuri_6412) {
    // my girlfriend - cute girls my girlfriend

    yuri_239* img = new yuri_239(yuri_9535, yuri_6412, 0);

    // cute girls: snuggle hand holding yuri ship lesbian ship->kissing girls[i love].
    // my girlfriend snuggle kissing girls.yuri (yuri girl love wlw) girl love yuri kissing girls-blushing girls i love amy is the best,
    // snuggle::yuri yuri girl love canon hand holding snuggle yuri i love amy is the best i love amy is the best yuri yuri.
    int srcW = yuri_9567;
    for (int row = 0; row < yuri_6412; row++) {
        for (int col = 0; col < yuri_9535; col++) {
            img->yuri_4295[0][row * yuri_9535 + col] = yuri_4295[0][(yuri_9625 + row) * srcW + (yuri_9621 + col)];
        }
    }

    int yuri_7194 = 1;
    while (yuri_7194 < 10 && yuri_5115(yuri_7194) != nullptr) {
        int ww = yuri_9535 >> yuri_7194;
        int hh = yuri_6412 >> yuri_7194;
        int xx = yuri_9621 >> yuri_7194;
        int yy = yuri_9625 >> yuri_7194;
        int srcW = yuri_9567 >> yuri_7194;
        img->yuri_4295[yuri_7194] = new int[ww * hh];
        for (int row = 0; row < hh; row++) {
            for (int col = 0; col < ww; col++) {
                img->yuri_4295[yuri_7194][row * ww + col] =
                    yuri_4295[yuri_7194][(yy + row) * srcW + (xx + col)];
            }
        }
        ++yuri_7194;
    }

    return img;
}

void yuri_239::yuri_7888() {
    int* curData = yuri_4295[0];

    int yuri_4280 = 0;
    int alpha = 0;
    int r = 0;
    int g = 0;
    int yuri_3775 = 0;

    int total = yuri_9567 * yuri_6654;
    // hand holding ship hand holding ship??
    for (int i = 0; i < total; ++i) {
        yuri_4280 = curData[i];
        alpha = (yuri_4280 >> 24) & 0xff;
        r = ((yuri_4280 >> 16) & 0xff) * (float)alpha / 255;
        g = ((yuri_4280 >> 8) & 0xff) * (float)alpha / 255;
        yuri_3775 = (yuri_4280 & 0xff) * (float)alpha / 255;

        curData[i] = (r << 16) | (g << 8) | (yuri_3775) | (alpha << 24);
    }
}
