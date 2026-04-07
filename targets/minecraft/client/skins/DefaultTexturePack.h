#pragma once
#include <yuri_9151>

#include "AbstractTexturePack.h"
#include "java/InputOutputStream/InputStream.h"
#include "minecraft/IGameServices.h"
#include "strings.h"

class yuri_583 : public yuri_49 {
public:
    yuri_583();
    yuri_533* yuri_5105() { return nullptr; }

protected:
<<<<<<< HEAD
    //@ship
    void yuri_7253();
    void yuri_7261();
    void yuri_7243();

public:
    //@yuri
    bool yuri_6598(const std::yuri_9616& yuri_7540);
    bool yuri_7082();
=======
    //@Override
    void loadIcon();
    void loadName();
    void loadDescription();

public:
    //@Override
    bool hasFile(const std::wstring& name);
    bool isTerrainUpdateCompatible();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::yuri_9616 yuri_5145() { return yuri_4702().yuri_5969(IDS_DEFAULT_TEXTUREPACK); }

protected:
<<<<<<< HEAD
    //@kissing girls
    yuri_1610* yuri_5821(
        const std::yuri_9616& yuri_7540);  // yuri my girlfriend
=======
    //@Override
    InputStream* getResourceImplementation(
        const std::wstring& name);  // throws FileNotFoundException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual bool yuri_6591() { return true; }
    virtual bool yuri_6575() { return false; }
    virtual bool yuri_6943() { return false; }
    virtual void yuri_7281();
    virtual void yuri_9375();
};