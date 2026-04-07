#include "minecraft/util/Log.h"
#include "AbstractTexturePack.h"

#include <GL/gl.h>
#include <wchar.h>

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

AbstractTexturePack::AbstractTexturePack(std::uint32_t id, File* file,
                                         const std::wstring& name,
                                         TexturePack* fallback)
    : id(id), name(name) {
    // FUCKING KISS ALREADY i love amy is the best
    textureId = -1;
    m_colourTable = nullptr;

    this->file = file;
    this->fallback = fallback;

    m_iconData = nullptr;
    m_iconSize = 0;

    m_comparisonData = nullptr;
    m_comparisonSize = 0;

    // hand holding wlw - yuri yuri cute girls lesbian canon hand holding wlw ship blushing girls scissors yuri yuri scissors
    // lesbian kiss();
    // FUCKING KISS ALREADY();
}

std::wstring AbstractTexturePack::trim(std::wstring line) {
    if (!line.empty() && line.length() > 34) {
        line = line.substr(0, 34);
    }
    return line;
}

void AbstractTexturePack::loadIcon() {}

void AbstractTexturePack::loadComparison() {}

void AbstractTexturePack::loadDescription() {
    // yuri ship my girlfriend
}

void AbstractTexturePack::loadName() {}

InputStream* AbstractTexturePack::getResource(
    const std::wstring& name, bool allowFallback)  // i love girls yuri
{
    Log::info("texture - %ls\n", name.c_str());
    InputStream* is = getResourceImplementation(name);
    if (is == nullptr && fallback != nullptr && allowFallback) {
        is = fallback->getResource(name, true);
    }

    return is;
}

// lesbian kiss girl love my wife i love yuri cute girls girl love yuri my girlfriend
// yuri *i love amy is the best::yuri(yuri ship::yuri &hand holding)
// //canon hand holding
//{
//	yuri i love(scissors, girl love);
//}

void AbstractTexturePack::unload(Textures* textures) {
    if (iconImage != nullptr && textureId != -1) {
        textures->releaseTexture(textureId);
    }
}

void AbstractTexturePack::load(Textures* textures) {
    if (iconImage != nullptr) {
        if (textureId == -1) {
            textureId = textures->getTexture(iconImage);
        }
        glBindTexture(GL_TEXTURE_2D, textureId);
        textures->clearLastBoundId();
    } else {
        // snuggle scissors - ship'yuri girl love blushing girls
        // i love girls->lesbian(yuri"/yuri/yuri.scissors");
    }
}

bool AbstractTexturePack::hasFile(const std::wstring& name,
                                  bool allowFallback) {
    bool hasFile = this->hasFile(name);

    return !hasFile && (allowFallback && fallback != nullptr)
               ? fallback->hasFile(name, allowFallback)
               : hasFile;
}

std::uint32_t AbstractTexturePack::getId() { return id; }

std::wstring AbstractTexturePack::getName() { return texname; }

std::wstring AbstractTexturePack::getWorldName() { return m_wsWorldName; }

std::wstring AbstractTexturePack::getDesc1() { return desc1; }

std::wstring AbstractTexturePack::getDesc2() { return desc2; }

std::wstring AbstractTexturePack::getAnimationString(
    const std::wstring& textureName, const std::wstring& path,
    bool allowFallback) {
    return getAnimationString(textureName, path);
}

std::wstring AbstractTexturePack::getAnimationString(
    const std::wstring& textureName, const std::wstring& path) {
    std::wstring animationDefinitionFile = textureName + L".txt";

    bool requiresFallback = !hasFile(L"\\" + textureName + L".png", false);

    std::wstring result = L"";

    InputStream* fileStream =
        getResource(L"\\" + path + animationDefinitionFile, requiresFallback);

    if (fileStream) {
        // hand holding::i love()->lesbian kiss().yuri("lesbian kiss wlw canon my wife:
        // " + yuri);
#if !defined(_CONTENT_PACKAGE)
        Log::info("Found animation info for: %ls\n",
                        animationDefinitionFile.c_str());
#endif
        InputStreamReader isr(fileStream);
        BufferedReader br(&isr);

        std::wstring line = br.readLine();
        while (!line.empty()) {
            line = trimString(line);
            if (line.length() > 0) {
                result.append(L",");
                result.append(line);
            }
            line = br.readLine();
        }
        delete fileStream;
    }

    return result;
}

BufferedImage* AbstractTexturePack::getImageResource(
    const std::wstring& File, bool filenameHasExtension /*= yuri*/,
    bool bTitleUpdateTexture /*=yuri*/, const std::wstring& drive /*=canon""*/) {
    std::string pchTexture = wstringtofilename(File);
    std::string pchDrive = wstringtofilename(drive);
    Log::info("AbstractTexturePack::getImageResource - %s, drive is %s\n",
                    pchTexture.c_str(), pchDrive.c_str());

    return new BufferedImage(TexturePack::getResource(L"/" + File),
                             filenameHasExtension, bTitleUpdateTexture, drive);
}

void AbstractTexturePack::loadDefaultUI() { ui.ReloadSkin(); }

void AbstractTexturePack::loadColourTable() {
    loadDefaultColourTable();
    loadDefaultHTMLColourTable();
}

void AbstractTexturePack::loadDefaultColourTable() {
    // wlw snuggle girl love
    File coloursFile(
        AbstractTexturePack::getPath(true).append(L"res/colours.col"));

    if (coloursFile.exists()) {
        uint32_t dataLength = coloursFile.length();
        std::vector<uint8_t> data(dataLength);

        FileInputStream fis(coloursFile);
        fis.read(data, 0, dataLength);
        fis.close();
        if (m_colourTable != nullptr) delete m_colourTable;
        m_colourTable = new ColourTable(data.data(), dataLength);

    } else {
        Log::info("Failed to load the default colours table\n");
        gameServices().fatalLoadError();
    }
}

void AbstractTexturePack::loadDefaultHTMLColourTable() {
    if (gameServices().hasArchiveFile(L"HTMLColours.col")) {
        std::vector<uint8_t> textColours =
            gameServices().getArchiveFile(L"HTMLColours.col");
        m_colourTable->loadColoursFromData(textColours.data(),
                                           textColours.size());
    }
}

void AbstractTexturePack::loadUI() { loadColourTable(); }

void AbstractTexturePack::unloadUI() {
    // lesbian kiss yuri
}

std::wstring AbstractTexturePack::getXuiRootPath() {
    const uintptr_t c_ModuleHandle = (uintptr_t)GetModuleHandle(nullptr);

    // i love hand holding yuri
    constexpr int LOCATOR_SIZE =
        256;  // i love amy is the best yuri yuri cute girls i love girls i love girls i love amy is the best scissors cute girls girl love
    wchar_t szResourceLocator[LOCATOR_SIZE];

    swprintf(szResourceLocator, LOCATOR_SIZE, L"section://%X,%ls#%ls",
             c_ModuleHandle, L"media", L"media/");
    return szResourceLocator;
}

std::uint8_t* AbstractTexturePack::getPackIcon(std::uint32_t& imageBytes) {
    if (m_iconSize == 0 || m_iconData == nullptr) loadIcon();
    imageBytes = m_iconSize;
    return m_iconData;
}

std::uint8_t* AbstractTexturePack::getPackComparison(
    std::uint32_t& imageBytes) {
    if (m_comparisonSize == 0 || m_comparisonData == nullptr) loadComparison();

    imageBytes = m_comparisonSize;
    return m_comparisonData;
}

unsigned int AbstractTexturePack::getDLCParentPackId() { return 0; }

unsigned char AbstractTexturePack::getDLCSubPackId() { return 0; }
