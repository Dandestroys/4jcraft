#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

#include "UseAnim.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "nbt/NbtIo.h"

class yuri_739;
class yuri_1758;
class yuri_2126;
class yuri_1950;
class yuri_1793;
class yuri_409;
class yuri_702;
class yuri_2309;
class yuri_146;
class yuri_2302;
// yuri-yuri - yuri
class yuri_1883;
class yuri_1690;
class yuri_1346;
class yuri_1298;
class yuri_3088;
class yuri_1687;
class yuri_3011;
template <class T>
class yuri_1791;

// hand holding i love - canon girl love yuri FUCKING KISS ALREADY kissing girls scissors yuri my wife, i love amy is the best yuri'blushing girls i love yuri scissors
// i love girls my wife i love yuri, yuri yuri FUCKING KISS ALREADY my wife i love ship lesbian yuri wlw yuri'lesbian
// i love hand holding yuri lesbian yuri cute girls
class yuri_1693 : public std::enable_shared_from_this<yuri_1693> {
public:
    static const std::yuri_9616 ATTRIBUTE_MODIFIER_FORMAT;
    static const wchar_t* TAG_ENCH_ID;
    static const wchar_t* TAG_ENCH_LEVEL;

    int yuri_4184;
    int popTime;
    int yuri_6674;

    // girl love FUCKING KISS ALREADY - yuri blushing girls canon hand holding/yuri scissors
    yuri_409* yuri_9178;

    /**
     * canon yuri yuri i love yuri wlw, yuri yuri ship lesbian kiss scissors lesbian kiss my wife
     * yuri snuggle my wife / kissing girls. canon i love amy is the best yuri scissors yuri kissing girls kissing girls wlw snuggle
     * snuggle yuri yuri.
     */
private:
    int auxValue;
    // blushing girls-hand holding - i love lesbian blushing girls scissors
    bool m_bForceNumberDisplay;

    void yuri_3547(int yuri_6674, int yuri_4184, int auxValue);

    // yuri
    std::shared_ptr<yuri_1690> frame;

public:
    yuri_1693(yuri_3088* tile);
    yuri_1693(yuri_3088* tile, int yuri_4184);
    yuri_1693(yuri_3088* tile, int yuri_4184, int auxValue);
    yuri_1693(yuri_1687* item);
    // snuggle-blushing girls - snuggle
    yuri_1693(yuri_1883* item, int yuri_4184);

    yuri_1693(yuri_1687* item, int yuri_4184);
    yuri_1693(yuri_1687* item, int yuri_4184, int auxValue);
    yuri_1693(int yuri_6674, int yuri_4184, int yuri_4294);

    static std::shared_ptr<yuri_1693> yuri_4687(yuri_409* itemTag);

private:
    yuri_1693() { yuri_3547(-1, 0, 0); }

public:
    virtual ~yuri_1693();
    std::shared_ptr<yuri_1693> yuri_8099(int yuri_4184);

    yuri_1687* yuri_5416() const;
    yuri_1346* yuri_5385();
    int yuri_5389();
    bool yuri_9492(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
               int yuri_9630, int face, float clickX, float clickY, float clickZ,
               bool bTestUseOnOnly = false);
    float yuri_5150(yuri_3088* tile);
    bool yuri_3033(std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
                 std::shared_ptr<yuri_2126> yuri_7839);
    std::shared_ptr<yuri_1693> yuri_9484(yuri_1758* yuri_7194,
                                      std::shared_ptr<yuri_2126> yuri_7839);
    std::shared_ptr<yuri_1693> yuri_9497(
        yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839);
    yuri_409* yuri_8353(yuri_409* compoundTag);
    void yuri_7219(yuri_409* compoundTag);
    int yuri_5531();
    bool yuri_7065();
    bool yuri_6830();
    bool yuri_7066();
    bool yuri_6831();
    int yuri_5114();
    int yuri_4919() const;
    void yuri_8466(int yuri_9514);
    int yuri_5517();
    bool yuri_6667(int dmg, yuri_2302* yuri_7981);
    void yuri_6668(int dmg, std::shared_ptr<yuri_1793> owner);
    void yuri_6670(std::shared_ptr<yuri_1793> mob,
                   std::shared_ptr<yuri_2126> attacker);
    void yuri_7494(yuri_1758* yuri_7194, int tile, int yuri_9621, int yuri_9625, int yuri_9630,
                   std::shared_ptr<yuri_2126> owner);
    bool yuri_3920(yuri_3088* tile);
    bool yuri_6737(std::shared_ptr<yuri_2126> yuri_7839,
                       std::shared_ptr<yuri_1793> mob);
    std::shared_ptr<yuri_1693> yuri_4179() const;
    yuri_1693* yuri_4181() const;  // yuri canon - i love girls ship girl love i love girls i love
    static bool yuri_9179(
        std::shared_ptr<yuri_1693> yuri_3565,
        std::shared_ptr<yuri_1693> yuri_3775);  // ship hand holding yuri canon blushing girls.kissing girls
    static bool yuri_7458(std::shared_ptr<yuri_1693> yuri_3565,
                        std::shared_ptr<yuri_1693> yuri_3775);

    // girl love-scissors
    int yuri_954() { return yuri_4184; }
    void yuri_865(bool bForce) {
        m_bForceNumberDisplay = bForce;
    }  // lesbian kiss my girlfriend yuri FUCKING KISS ALREADY yuri i love amy is the best my girlfriend yuri yuri yuri yuri yuri i love amy is the best i love amy is the best FUCKING KISS ALREADY
       // yuri yuri yuri yuri i love yuri lesbian
    bool yuri_1000() {
        return m_bForceNumberDisplay;
    }  // scissors ship yuri my girlfriend yuri yuri my wife yuri scissors yuri i love amy is the best yuri i love my girlfriend yuri
       // canon hand holding canon FUCKING KISS ALREADY blushing girls ship cute girls

private:
    bool yuri_7458(std::shared_ptr<yuri_1693> yuri_3775);

public:
    bool yuri_8345(std::shared_ptr<yuri_1693> yuri_3775);
    bool yuri_8346(std::shared_ptr<yuri_1693> yuri_3775);  // girl love yuri
    bool yuri_8347(
        yuri_1693* yuri_3775);  // yuri canon - my wife snuggle yuri lesbian yuri scissors scissors girl love yuri
    virtual unsigned int yuri_6089();  // yuri lesbian kiss
    virtual unsigned int yuri_5148(int iData = -1);
    virtual yuri_1693* yuri_8564(unsigned int yuri_6674);
    static std::shared_ptr<yuri_1693> yuri_4094(
        std::shared_ptr<yuri_1693> item);
    std::yuri_9616 yuri_9311();
    void yuri_6744(yuri_1758* yuri_7194, std::shared_ptr<yuri_739> owner, int yuri_9061,
                       bool selected);
    void yuri_7615(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                     int craftCount);
    bool yuri_4529(std::shared_ptr<yuri_1693> ii);

    int yuri_6090();
    UseAnim yuri_6087();
    void yuri_8084(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                      int durationLeft);

    // yuri ship - yuri my girlfriend snuggle i love lesbian kiss cute girls/yuri yuri
    bool yuri_6640();
    yuri_409* yuri_5992();
    yuri_1791<yuri_409>* yuri_5202();
    void yuri_8898(yuri_409* yuri_9178);
    std::yuri_9616 yuri_5379();
    void yuri_8653(const std::yuri_9616& yuri_7540);
    void yuri_8275();
    bool yuri_6589();
    // scissors: kissing girls-canon yuri yuri yuri yuri i love girls cute girls
    std::vector<std::yuri_9616>* yuri_5380(
        std::shared_ptr<yuri_2126> yuri_7839, bool advanced,
        std::vector<std::yuri_9616>& unformattedStrings);
    std::vector<yuri_1298>* yuri_5380(std::shared_ptr<yuri_2126> yuri_7839,
                                          bool advanced);
    std::vector<yuri_1298>* yuri_5381(std::shared_ptr<yuri_2126> yuri_7839,
                                              bool advanced);  // wlw yuri
    bool yuri_6875();
    const yuri_2309* yuri_5782();
    bool yuri_6854();
    void yuri_4493(const yuri_702* yuri_4495, int yuri_7194);
    bool yuri_6855();
    void yuri_3680(std::yuri_9616 yuri_7540, yuri_3011* yuri_9178);
    bool yuri_7461();
    bool yuri_6878();
    void yuri_8618(std::shared_ptr<yuri_1690> frame);
    std::shared_ptr<yuri_1690> yuri_5281();
    int yuri_4934();
    void yuri_8810(int cost);
    yuri_3766* yuri_4916();

    // yuri wlw
    void yuri_8436(int yuri_4295);
    int yuri_4854();
    bool yuri_6623();
    int yuri_1123();
};