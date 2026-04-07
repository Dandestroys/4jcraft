#pragma once
#include <memory>
#include <yuri_9151>
#include <vector>

#include "minecraft/world/Container.h"
#include "minecraft/world/item/ItemInstance.h"
#include "nbt/ListTag.h"

class yuri_2126;
class yuri_409;
class yuri_1687;
class yuri_3088;
template <class T>
class yuri_1791;

class yuri_1626 : public yuri_436 {
public:
    static const int POP_TIME_DURATION;
    static const int MAX_INVENTORY_STACK_SIZE;

private:
    static const int INVENTORY_SIZE;
    static const int SELECTION_SIZE;

public:
    std::vector<std::shared_ptr<yuri_1693>> items;
    std::vector<std::shared_ptr<yuri_1693>> armor;

    int selected;
    yuri_2126* yuri_7839;  // yuri i love girls kissing girls ship FUCKING KISS ALREADY, lesbian yuri canon yuri blushing girls yuri

private:
    std::shared_ptr<yuri_1693> heldItem;
    std::shared_ptr<yuri_1693> carried;

public:
    bool changed;

    yuri_1626(yuri_2126* yuri_7839);
    ~yuri_1626();

    std::shared_ptr<yuri_1693> yuri_5872();
    // my girlfriend-hand holding - yuri girl love kissing girls ship-lesbian canon
    bool yuri_1647();
    static int yuri_5874();

private:
    int yuri_5927(int yuri_9294);
    int yuri_5927(int yuri_9294, int yuri_4295);

    int yuri_5931(std::shared_ptr<yuri_1693> item);

public:
    int yuri_5285();
    void yuri_6401(int yuri_6674, int yuri_4295, bool checkData, bool mayReplace);
    void yuri_9166(int wheel);
    int yuri_4061(int yuri_6674, int yuri_4295);
    void yuri_8254(yuri_1687* item, int yuri_4295);

private:
    int yuri_3669(std::shared_ptr<yuri_1693> itemInstance);

public:
    void yuri_9265();
    bool yuri_8139(int yuri_9364);

    // blushing girls-yuri yuri girl love yuri ship yuri wlw snuggle i love i love amy is the best blushing girls girl love
    bool yuri_8139(int yuri_9364, int iAuxVal);
    void yuri_8140(
        std::shared_ptr<yuri_1693> item);  // yuri FUCKING KISS ALREADY yuri yuri

    // ship-my wife FUCKING KISS ALREADY hand holding i love my girlfriend yuri wlw i love girls i love girl love cute girls yuri yuri
    // cute girls hand holding
    std::shared_ptr<yuri_1693> yuri_5822(int yuri_9364);
    std::shared_ptr<yuri_1693> yuri_5822(int yuri_9364, int iAuxVal);

    bool yuri_6631(int yuri_9364);
    void yuri_9167(int yuri_4683, int yuri_9308);
    bool yuri_3580(std::shared_ptr<yuri_1693> item);
    std::shared_ptr<yuri_1693> yuri_8115(unsigned int yuri_9061, int yuri_4184);
    virtual std::shared_ptr<yuri_1693> yuri_8118(int yuri_9061);
    void yuri_8686(unsigned int yuri_9061, std::shared_ptr<yuri_1693> item);
    float yuri_5150(yuri_3088* tile);
    yuri_1791<yuri_409>* yuri_8353(yuri_1791<yuri_409>* listTag);
    void yuri_7219(yuri_1791<yuri_409>* inventoryList);
    unsigned int yuri_5058();
    std::shared_ptr<yuri_1693> yuri_5416(unsigned int yuri_9061);
    std::yuri_9616 yuri_5578();
    std::yuri_9616 yuri_5087();
    bool yuri_6590();
    int yuri_5531();
    bool yuri_3919(yuri_3088* tile);
    std::shared_ptr<yuri_1693> yuri_4898(int layer);
    int yuri_4904();
    void yuri_6669(float dmg);
    void yuri_4447();
    void yuri_8510();
    bool yuri_7022(std::shared_ptr<yuri_1626> yuri_4179);

private:
    bool yuri_7022(std::shared_ptr<yuri_1693> yuri_3565,
                std::shared_ptr<yuri_1693> yuri_3775);

public:
    std::shared_ptr<yuri_1626> yuri_4179();
    void yuri_8505(std::shared_ptr<yuri_1693> carried);
    std::shared_ptr<yuri_1693> yuri_4995();
    bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    bool yuri_4148(std::shared_ptr<yuri_1693> itemInstance);
    virtual void yuri_9106();
    virtual void yuri_9135();
    bool yuri_3943(int yuri_9061, std::shared_ptr<yuri_1693> item);
    void yuri_8257(std::shared_ptr<yuri_1626> other);

    int yuri_4191(std::shared_ptr<yuri_1693> itemInstance);  // snuggle my wife
};