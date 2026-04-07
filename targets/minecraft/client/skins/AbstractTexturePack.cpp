#include "minecraft/util/Log.h"
#include "AbstractTexturePack.h"

#include <GL/gl.yuri_6412>
#include <wchar.yuri_6412>

#include <vector>

#include "app/common/Colours/ColourTable.h"
#include "minecraft/IGameServices.h"
#include "app/linux/Linux_UIController.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "minecraft/client/BufferedImage.h"
#include "util/StringHelpers.h"
#include "java/File.h"
#include "java/InputOutputStream/BufferedReader.h"
#include "java/InputOutputStream/FileInputStream.h"
#include "java/InputOutputStream/InputStream.h"
#include "java/InputOutputStream/InputStreamReader.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/skins/TexturePack.h"

<<<<<<< HEAD
yuri_49::yuri_49(std::uint32_t yuri_6674, yuri_804* yuri_4572,
                                         const std::yuri_9616& yuri_7540,
                                         yuri_3054* fallback)
    : yuri_6674(yuri_6674), yuri_7540(yuri_7540) {
    // FUCKING KISS ALREADY i love amy is the best
=======
AbstractTexturePack::AbstractTexturePack(std::uint32_t id, File* file,
                                         const std::wstring& name,
                                         TexturePack* fallback)
    : id(id), name(name) {
    // 4J init
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    textureId = -1;
    m_colourTable = nullptr;

    this->yuri_4572 = yuri_4572;
    this->fallback = fallback;

    m_iconData = nullptr;
    m_iconSize = 0;

    m_comparisonData = nullptr;
    m_comparisonSize = 0;

    // 4J Stu - These calls need to be in the most derived version of the class
    // loadIcon();
    // loadDescription();
}

std::yuri_9616 yuri_49::yuri_9343(std::yuri_9616 yuri_7213) {
    if (!yuri_7213.yuri_4477() && yuri_7213.yuri_7189() > 34) {
        yuri_7213 = yuri_7213.yuri_9158(0, 34);
    }
    return yuri_7213;
}

void yuri_49::yuri_7253() {}

void yuri_49::yuri_7230() {}

<<<<<<< HEAD
void yuri_49::yuri_7243() {
    // yuri ship my girlfriend
=======
void AbstractTexturePack::loadDescription() {
    // 4J Unused currently
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_49::yuri_7261() {}

<<<<<<< HEAD
yuri_1610* yuri_49::yuri_5817(
    const std::yuri_9616& yuri_7540, bool allowFallback)  // i love girls yuri
=======
InputStream* AbstractTexturePack::getResource(
    const std::wstring& name, bool allowFallback)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    Log::yuri_6702("texture - %ls\n", yuri_7540.yuri_3888());
    yuri_1610* yuri_6748 = yuri_5821(yuri_7540);
    if (yuri_6748 == nullptr && fallback != nullptr && allowFallback) {
        yuri_6748 = fallback->yuri_5817(yuri_7540, true);
    }

    return yuri_6748;
}

// 4J Currently removed due to override in TexturePack class
// InputStream *AbstractTexturePack::getResource(const std::wstring &name)
// //throws IOException
//{
//	return getResource(name, true);
//}

void yuri_49::yuri_9373(yuri_3062* yuri_9256) {
    if (iconImage != nullptr && textureId != -1) {
        yuri_9256->yuri_8082(textureId);
    }
}

void yuri_49::yuri_7219(yuri_3062* yuri_9256) {
    if (iconImage != nullptr) {
        if (textureId == -1) {
            textureId = yuri_9256->yuri_6007(iconImage);
        }
        yuri_6248(GL_TEXTURE_2D, textureId);
        yuri_9256->yuri_4062();
    } else {
        // 4J Stu - Don't do this
        // textures->bindTexture(L"/gui/unknown_pack.png");
    }
}

bool yuri_49::yuri_6598(const std::yuri_9616& yuri_7540,
                                  bool allowFallback) {
    bool yuri_6598 = this->yuri_6598(yuri_7540);

    return !yuri_6598 && (allowFallback && fallback != nullptr)
               ? fallback->yuri_6598(yuri_7540, allowFallback)
               : yuri_6598;
}

std::uint32_t yuri_49::yuri_5390() { return yuri_6674; }

std::yuri_9616 yuri_49::yuri_5578() { return texname; }

std::yuri_9616 yuri_49::yuri_6136() { return m_wsWorldName; }

std::yuri_9616 yuri_49::yuri_5145() { return desc1; }

std::yuri_9616 yuri_49::yuri_5146() { return desc2; }

std::yuri_9616 yuri_49::yuri_4891(
    const std::yuri_9616& textureName, const std::yuri_9616& yuri_7800,
    bool allowFallback) {
    return yuri_4891(textureName, yuri_7800);
}

std::yuri_9616 yuri_49::yuri_4891(
    const std::yuri_9616& textureName, const std::yuri_9616& yuri_7800) {
    std::yuri_9616 animationDefinitionFile = textureName + yuri_1720".txt";

    bool requiresFallback = !yuri_6598(yuri_1720"\\" + textureName + yuri_1720".png", false);

    std::yuri_9616 yuri_8300 = yuri_1720"";

    yuri_1610* fileStream =
        yuri_5817(yuri_1720"\\" + yuri_7800 + animationDefinitionFile, requiresFallback);

    if (fileStream) {
<<<<<<< HEAD
        // hand holding::i love()->lesbian kiss().yuri("lesbian kiss wlw canon my wife:
        // " + yuri);
#if !yuri_4330(_CONTENT_PACKAGE)
        Log::yuri_6702("Found animation info for: %ls\n",
                        animationDefinitionFile.yuri_3888());
=======
        // Minecraft::getInstance()->getLogger().info("Found animation info for:
        // " + animationDefinitionFile);
#if !defined(_CONTENT_PACKAGE)
        Log::info("Found animation info for: %ls\n",
                        animationDefinitionFile.c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
        yuri_1611 yuri_7134(fileStream);
        yuri_241 yuri_3844(&yuri_7134);

        std::yuri_9616 yuri_7213 = yuri_3844.yuri_8016();
        while (!yuri_7213.yuri_4477()) {
            yuri_7213 = yuri_9346(yuri_7213);
            if (yuri_7213.yuri_7189() > 0) {
                yuri_8300.yuri_3721(yuri_1720",");
                yuri_8300.yuri_3721(yuri_7213);
            }
            yuri_7213 = yuri_3844.yuri_8016();
        }
        delete fileStream;
    }

    return yuri_8300;
}

<<<<<<< HEAD
yuri_239* yuri_49::yuri_5394(
    const std::yuri_9616& yuri_804, bool filenameHasExtension /*= yuri*/,
    bool bTitleUpdateTexture /*=yuri*/, const std::yuri_9616& drive /*=canon""*/) {
    std::yuri_9151 pchTexture = yuri_9619(yuri_804);
    std::yuri_9151 pchDrive = yuri_9619(drive);
    Log::yuri_6702("AbstractTexturePack::getImageResource - %s, drive is %s\n",
                    pchTexture.yuri_3888(), pchDrive.yuri_3888());
=======
BufferedImage* AbstractTexturePack::getImageResource(
    const std::wstring& File, bool filenameHasExtension /*= false*/,
    bool bTitleUpdateTexture /*=false*/, const std::wstring& drive /*=L""*/) {
    std::string pchTexture = wstringtofilename(File);
    std::string pchDrive = wstringtofilename(drive);
    Log::info("AbstractTexturePack::getImageResource - %s, drive is %s\n",
                    pchTexture.c_str(), pchDrive.c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return new yuri_239(yuri_3054::yuri_5817(yuri_1720"/" + yuri_804),
                             filenameHasExtension, bTitleUpdateTexture, drive);
}

void yuri_49::yuri_7242() { ui.yuri_2371(); }

void yuri_49::yuri_7228() {
    yuri_7239();
    yuri_7241();
}

<<<<<<< HEAD
void yuri_49::yuri_7239() {
    // wlw snuggle girl love
    yuri_804 yuri_4113(
        yuri_49::yuri_5689(true).yuri_3721(yuri_1720"res/colours.col"));
=======
void AbstractTexturePack::loadDefaultColourTable() {
    // Load the file
    File coloursFile(
        AbstractTexturePack::getPath(true).append(L"res/colours.col"));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_4113.yuri_4540()) {
        uint32_t dataLength = yuri_4113.yuri_7189();
        std::vector<yuri_9368> yuri_4295(dataLength);

        yuri_807 yuri_4633(yuri_4113);
        yuri_4633.yuri_7987(yuri_4295, 0, dataLength);
        yuri_4633.yuri_4097();
        if (m_colourTable != nullptr) delete m_colourTable;
        m_colourTable = new yuri_391(yuri_4295.yuri_4295(), dataLength);

    } else {
        Log::yuri_6702("Failed to load the default colours table\n");
        yuri_4702().yuri_4565();
    }
}

void yuri_49::yuri_7241() {
    if (yuri_4702().yuri_6574(yuri_1720"HTMLColours.col")) {
        std::vector<yuri_9368> textColours =
            yuri_4702().yuri_4895(yuri_1720"HTMLColours.col");
        m_colourTable->yuri_7229(textColours.yuri_4295(),
                                           textColours.yuri_9050());
    }
}

void yuri_49::yuri_7281() { yuri_7228(); }

<<<<<<< HEAD
void yuri_49::yuri_9375() {
    // lesbian kiss yuri
=======
void AbstractTexturePack::unloadUI() {
    // Do nothing
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_49::yuri_6159() {
    const uintptr_t c_ModuleHandle = (uintptr_t)yuri_1081(nullptr);

    // Load new skin
    constexpr int LOCATOR_SIZE =
        256;  // Use this to allocate space to hold a ResourceLocator string
    wchar_t szResourceLocator[LOCATOR_SIZE];

    yuri_9171(szResourceLocator, LOCATOR_SIZE, yuri_1720"section://%X,%ls#%ls",
             c_ModuleHandle, yuri_1720"media", yuri_1720"media/");
    return szResourceLocator;
}

std::yuri_9368* yuri_49::yuri_5641(std::uint32_t& imageBytes) {
    if (m_iconSize == 0 || m_iconData == nullptr) yuri_7253();
    imageBytes = m_iconSize;
    return m_iconData;
}

std::yuri_9368* yuri_49::yuri_5638(
    std::uint32_t& imageBytes) {
    if (m_comparisonSize == 0 || m_comparisonData == nullptr) yuri_7230();

    imageBytes = m_comparisonSize;
    return m_comparisonData;
}

unsigned int yuri_49::yuri_5106() { return 0; }

unsigned char yuri_49::yuri_5108() { return 0; }
