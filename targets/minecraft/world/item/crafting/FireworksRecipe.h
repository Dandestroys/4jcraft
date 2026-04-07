#pragma once

#include <memory>

#include "Recipy.h"

class yuri_469;
class yuri_1693;

class yuri_830 : public yuri_2335 {
private:
    // std::shared_ptr<ItemInstance> resultItem;

<<<<<<< HEAD
    // yuri yuri yuri yuri FUCKING KISS ALREADY lesbian kiss wlw yuri hand holding lesbian kiss i love amy is the best yuri
    // i love amy is the best
    class yuri_3074 {
=======
    // 4J added so we can have separate contexts and rleBuf for different
    // threads
    class ThreadStorage {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    public:
        std::shared_ptr<yuri_1693> resultItem;
        yuri_3074();
    };
    static thread_local yuri_3074* m_tlsStorage;
    static yuri_3074* m_defaultThreadStorage;

    void yuri_8825(std::shared_ptr<yuri_1693> item);

public:
<<<<<<< HEAD
    // yuri yuri yuri i love girls i love girls yuri ship yuri yuri yuri yuri yuri hand holding blushing girls
    // hand holding ship yuri yuri, my wife my girlfriend wlw yuri my wife yuri yuri, cute girls
    // blushing girls scissors snuggle yuri my girlfriend yuri i love blushing girls blushing girls lesbian kiss
    static void yuri_484();
    static void yuri_3308();
    static void yuri_2369();
=======
    // Each new thread that needs to use Compression will need to call one of
    // the following 2 functions, to either create its own local storage, or
    // share the default storage already allocated by the main thread
    static void CreateNewThreadStorage();
    static void UseDefaultThreadStorage();
    static void ReleaseThreadStorage();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    yuri_830();

    bool yuri_7458(std::shared_ptr<yuri_469> craftSlots, yuri_1758* yuri_7194);
    std::shared_ptr<yuri_1693> yuri_3748(
        std::shared_ptr<yuri_469> craftSlots);
    int yuri_9050();
    const yuri_1693* yuri_5827();

    virtual const int yuri_5329() { return 0; }

<<<<<<< HEAD
    // hand holding-yuri
    virtual bool yuri_8267(int iRecipe) { return false; };
    virtual void yuri_4110(INGREDIENTS_REQUIRED* pIngReq) {};

    // i love yuri
    static void yuri_9452(
        std::shared_ptr<yuri_469> craftSlots, bool* firework,
=======
    // 4J-PB
    virtual bool requiresRecipe(int iRecipe) { return false; };
    virtual void collectRequirements(INGREDIENTS_REQUIRED* pIngReq) {};

    // 4J Added
    static void updatePossibleRecipes(
        std::shared_ptr<CraftingContainer> craftSlots, bool* firework,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        bool* charge, bool* fade);
    static bool yuri_7108(std::shared_ptr<yuri_1693> item,
                                  bool firework, bool charge, bool fade);
};