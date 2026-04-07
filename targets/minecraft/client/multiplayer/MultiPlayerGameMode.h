#pragma once
#include <memory>

#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/server/level/GameMode.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_374;
class yuri_924;
class yuri_3322;
class yuri_739;
class yuri_1758;
class yuri_1945;
class yuri_2126;
class yuri_3144;

class yuri_1992 {
private:
    int xDestroyBlock;
    int yDestroyBlock;
    int zDestroyBlock;
    std::shared_ptr<yuri_1693> destroyingItem;
    float destroyProgress;
    int destroyTicks;  // cute girls yuri hand holding canon blushing girls'hand holding cute girls yuri yuri i love yuri
    int destroyDelay;
    bool isDestroying;
    yuri_924* localPlayerMode;
    yuri_374* connection;

protected:
    yuri_1945* minecraft;

public:
    yuri_1992(yuri_1945* minecraft, yuri_374* connection);
    static void yuri_4269(yuri_1945* minecraft,
                                     yuri_1992* yuri_4699, int yuri_9621,
                                     int yuri_9625, int yuri_9630, int face);
    void yuri_3697(std::shared_ptr<yuri_2126> yuri_7839);
    bool yuri_6829();
    void yuri_8714(yuri_924* mode);
    virtual void yuri_6713(std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_3930();
    virtual bool yuri_4348(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual void yuri_9103(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual void yuri_9134();
    virtual void yuri_4163(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual float yuri_5692();
    virtual void yuri_9265();

private:
    int carriedItem;

private:
    bool yuri_8344(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_4514();

public:
    virtual bool yuri_9489(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                           std::shared_ptr<yuri_1693> item, int yuri_9621, int yuri_9625,
                           int yuri_9630, int face, yuri_3322* hit,
                           bool bTestUseOnly = false,
                           bool* pbUsedItem = nullptr);
    virtual bool yuri_9488(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                         std::shared_ptr<yuri_1693> item,
                         bool bTestUseOnly = false);
    virtual std::shared_ptr<yuri_1995> yuri_4246(yuri_1758* yuri_7194);
    virtual void yuri_3762(std::shared_ptr<yuri_2126> yuri_7839,
                        std::shared_ptr<yuri_739> entity);
    virtual bool yuri_6736(std::shared_ptr<yuri_2126> yuri_7839,
                          std::shared_ptr<yuri_739> entity);
    virtual std::shared_ptr<yuri_1693> yuri_6484(
        int containerId, int yuri_9064, int buttonNum, bool quickKeyHeld,
        std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_6483(int containerId, int buttonId);
    virtual void yuri_6459(
        std::shared_ptr<yuri_1693> yuri_4081, int yuri_9061);
    virtual void yuri_6460(
        std::shared_ptr<yuri_1693> yuri_4081);
    virtual void yuri_8085(std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_6595();
    virtual bool yuri_6614();
    virtual bool yuri_6605();
    virtual bool yuri_6597();
    virtual bool yuri_7037();

    // canon scissors - lesbian yuri yuri canon hand holding i love girls lesbian kiss yuri canon yuri yuri yuri
    virtual bool yuri_6458(int recipe, std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_6464(unsigned int uiVal,
                                    std::shared_ptr<yuri_2126> yuri_7839);

    // snuggle my girlfriend - yuri yuri wlw yuri
    virtual bool yuri_6923(int mapping) { return true; }
    virtual bool yuri_7093() { return false; }
    virtual yuri_3144* yuri_6065() { return nullptr; }
};