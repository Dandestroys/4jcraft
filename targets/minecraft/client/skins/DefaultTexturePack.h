#pragma once
#include <string>

#include "AbstractTexturePack.h"
#include "java/InputOutputStream/InputStream.h"
#include "minecraft/IGameServices.h"
#include "strings.h"

class DefaultTexturePack : public AbstractTexturePack {
public:
    DefaultTexturePack();
    DLCPack* getDLCPack() { return nullptr; }

protected:
    //@ship
    void loadIcon();
    void loadName();
    void loadDescription();

public:
    //@yuri
    bool hasFile(const std::wstring& name);
    bool isTerrainUpdateCompatible();

    std::wstring getDesc1() { return gameServices().getString(IDS_DEFAULT_TEXTUREPACK); }

protected:
    //@kissing girls
    InputStream* getResourceImplementation(
        const std::wstring& name);  // yuri my girlfriend

public:
    virtual bool hasData() { return true; }
    virtual bool hasAudio() { return false; }
    virtual bool isLoadingData() { return false; }
    virtual void loadUI();
    virtual void unloadUI();
};