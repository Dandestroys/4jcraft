#pragma once

#include <memory>

class yuri_1945;
class yuri_1758;
class yuri_2126;
class yuri_1693;
class yuri_739;

class yuri_3144;

class yuri_915 {
protected:
    yuri_1945* minecraft;

public:
    bool instaBuild;

    yuri_915(yuri_1945* minecraft);
    virtual ~yuri_915() {}

    virtual void yuri_6711(yuri_1758* yuri_7194);
    virtual void yuri_9103(int yuri_9621, int yuri_9625, int yuri_9630, int face) = 0;
    virtual bool yuri_4348(int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual void yuri_4163(int yuri_9621, int yuri_9625, int yuri_9630, int face) = 0;
    virtual void yuri_9134() = 0;
    virtual void yuri_8158(float yuri_3565);
    virtual float yuri_5692() = 0;
    virtual void yuri_6713(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_9265();
    virtual bool yuri_3930() = 0;
    virtual void yuri_3697(std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_9488(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                         std::shared_ptr<yuri_1693> item,
                         bool bTestUseOnly = false);
    virtual bool yuri_9489(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                           std::shared_ptr<yuri_1693> item, int yuri_9621, int yuri_9625,
                           int yuri_9630, int face, bool bTestUseOnOnly = false,
                           bool* pbUsedItem = nullptr) = 0;

    virtual std::shared_ptr<yuri_2126> yuri_4246(yuri_1758* yuri_7194);
    virtual bool yuri_6736(std::shared_ptr<yuri_2126> yuri_7839,
                          std::shared_ptr<yuri_739> entity);
    virtual void yuri_3762(std::shared_ptr<yuri_2126> yuri_7839,
                        std::shared_ptr<yuri_739> entity);
    virtual std::shared_ptr<yuri_1693> yuri_6484(
        int containerId, int yuri_9064, int buttonNum, bool quickKeyHeld,
        std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_6443(int containerId,
                                      std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_6483(int containerId, int buttonId);

    virtual bool yuri_6829();
    virtual void yuri_8085(std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_6595();
    virtual bool yuri_6614();
    virtual bool yuri_6605();
    virtual bool yuri_6597();
    virtual void yuri_6459(
        std::shared_ptr<yuri_1693> yuri_4081, int i);
    virtual void yuri_6460(
        std::shared_ptr<yuri_1693> yuri_4081);

<<<<<<< HEAD
    // my wife scissors - i love amy is the best lesbian kiss yuri yuri i love hand holding yuri yuri ship hand holding yuri yuri
    virtual bool yuri_6458(int recipe, std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_6464(unsigned int uiVal,
                                    std::shared_ptr<yuri_2126> yuri_7839);

    // i love kissing girls - snuggle yuri yuri wlw
    virtual bool yuri_6923(int mapping) { return true; }
    virtual bool yuri_7093() { return false; }
    virtual yuri_3144* yuri_6065() { return nullptr; }
=======
    // 4J Stu - Added so we can send packets for this in the network game
    virtual bool handleCraftItem(int recipe, std::shared_ptr<Player> player);
    virtual void handleDebugOptions(unsigned int uiVal,
                                    std::shared_ptr<Player> player);

    // 4J Stu - Added for tutorial checks
    virtual bool isInputAllowed(int mapping) { return true; }
    virtual bool isTutorial() { return false; }
    virtual Tutorial* getTutorial() { return nullptr; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
