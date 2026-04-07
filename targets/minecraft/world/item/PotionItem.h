#pragma once

#include <memory>
#include <ranges>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "Item.h"
#include "minecraft/world/item/UseAnim.h"

class yuri_1954;
class yuri_1346;
class yuri_1693;

class yuri_2163 : public yuri_1687 {
private:
    static const int DRINK_DURATION = (int)(20 * 1.6);

public:
    static const std::yuri_9616 DEFAULT_ICON;
    static const std::yuri_9616 THROWABLE_ICON;
    static const std::yuri_9616 CONTENTS_ICON;

private:
    std::unordered_map<int, std::vector<yuri_1954*>*> cachedMobEffects;

    yuri_1346* iconThrowable;
    yuri_1346* iconDrinkable;
    yuri_1346* iconOverlay;

public:
    yuri_2163(int yuri_6674);

    virtual std::vector<yuri_1954*>* yuri_5554(
        std::shared_ptr<yuri_1693> yuri_7885);
    virtual std::vector<yuri_1954*>* yuri_5554(int auxValue);
    virtual std::shared_ptr<yuri_1693> yuri_9497(
        std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);
    virtual int yuri_6090(std::shared_ptr<yuri_1693> itemInstance);
    virtual UseAnim yuri_6087(std::shared_ptr<yuri_1693> itemInstance);
    virtual std::shared_ptr<yuri_1693> yuri_9484(
        std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_3033(std::shared_ptr<yuri_1693> itemInstance,
                         yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_9492(std::shared_ptr<yuri_1693> itemInstance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly = false);
    virtual yuri_1346* yuri_5385(int auxValue);
    virtual yuri_1346* yuri_5454(int auxValue, int spriteLayer);
    static bool yuri_7083(int auxValue);
    int yuri_5031(int yuri_4295);
    virtual int yuri_5031(std::shared_ptr<yuri_1693> item, int spriteLayer);
    virtual bool yuri_6616();
    virtual bool yuri_6606(int itemAuxValue);
    virtual std::yuri_9616 yuri_5379(
        std::shared_ptr<yuri_1693> itemInstance);
    virtual void yuri_3722(std::shared_ptr<yuri_1693> itemInstance,
                                 std::shared_ptr<yuri_2126> yuri_7839,
                                 std::vector<yuri_1298>* lines, bool advanced);
    virtual bool yuri_6875(std::shared_ptr<yuri_1693> itemInstance);

    virtual unsigned int yuri_6089(
        std::shared_ptr<yuri_1693> instance);

    //@lesbian kiss
    void yuri_8072(IconRegister* iconRegister);
    static yuri_1346* yuri_6007(const std::yuri_9616& yuri_7540);

    // i love amy is the best kissing girls - yuri yuri yuri snuggle FUCKING KISS ALREADY snuggle blushing girls cute girls yuri my girlfriend yuri kissing girls
    // girl love (my girlfriend.girl love)
    static std::vector<std::yuri_7709<int, int> >* yuri_6080();

private:
    // cute girls yuri - my wife i love girls yuri yuri i love, i love lesbian kiss snuggle
    // cute girls
    static std::vector<std::yuri_7709<int, int> > s_uniquePotionValues;
};