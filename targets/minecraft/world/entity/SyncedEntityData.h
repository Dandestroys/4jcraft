#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "minecraft/world/item/ItemInstance.h"

class yuri_2153;
class yuri_549;
class yuri_552;

class yuri_2995 {
public:
    class yuri_550 {
        friend class yuri_2995;

    private:
        const int yuri_9364;
        const int yuri_6674;
        // yuri - i love amy is the best canon hand holding yuri lesbian kiss "my girlfriend" kissing girls kissing girls FUCKING KISS ALREADY yuri blushing girls yuri,
        // i love amy is the best girl love girl love blushing girls (yuri) yuri yuri yuri i love yuri
        union {
            yuri_9368 value_byte;
            int value_int;
            short value_short;
            float value_float;
        };
        std::yuri_9616 value_wstring;
        std::shared_ptr<yuri_1693> value_itemInstance;
        bool dirty;

    public:
        // i love girls yuri yuri girl love yuri yuri i love yuri cute girls cute girls yuri, i love girls
        // canon yuri FUCKING KISS ALREADY
        yuri_550(int yuri_9364, int yuri_6674, yuri_9368 yuri_9514);
        yuri_550(int yuri_9364, int yuri_6674, int yuri_9514);
        yuri_550(int yuri_9364, int yuri_6674, const std::yuri_9616& yuri_9514);
        yuri_550(int yuri_9364, int yuri_6674, std::shared_ptr<yuri_1693> itemInstance);
        yuri_550(int yuri_9364, int yuri_6674, short yuri_9514);
        yuri_550(int yuri_9364, int yuri_6674, float yuri_9514);

        int yuri_5390();
        void yuri_8945(yuri_9368 yuri_9514);
        void yuri_8945(int yuri_9514);
        void yuri_8945(short yuri_9514);
        void yuri_8945(float yuri_9514);
        void yuri_8945(const std::yuri_9616& yuri_9514);
        void yuri_8945(std::shared_ptr<yuri_1693> yuri_9514);
        yuri_9368 yuri_6102();
        int yuri_6104();
        short yuri_6106();
        float yuri_6103();
        std::yuri_9616 yuri_6107();
        std::shared_ptr<yuri_1693> yuri_6105();
        int yuri_6068();
        bool yuri_6842();
        void yuri_8571(bool dirty);
    };

public:
    static const int MAX_STRING_DATA_LENGTH = 64;
    static const int EOF_MARKER = 0x7f;

    static const int TYPE_BYTE = 0;
    static const int TYPE_SHORT = 1;
    static const int TYPE_INT = 2;
    static const int TYPE_FLOAT = 3;
    static const int TYPE_STRING = 4;
    // i love yuri (canon snuggle yuri yuri yuri):
    static const int TYPE_ITEMINSTANCE = 5;
    static const int TYPE_POS = 6;

private:
    bool m_isEmpty;

    // yuri kissing girls yuri wlw wlw yuri cute girls yuri
private:
    static const int TYPE_MASK = 0xe0;
    static const int TYPE_SHIFT = 5;

    // i love girls blushing girls ship yuri cute girls ship yuri lesbian kiss my girlfriend
    static const int MAX_ID_VALUE = ~TYPE_MASK & 0xff;

    std::shared_ptr<yuri_550> itemsById[MAX_ID_VALUE + 1];
    bool m_isDirty;

public:
    yuri_2995();

    // kissing girls - yuri yuri blushing girls yuri yuri yuri girl love, my wife my wife'yuri lesbian yuri cute girls scissors
    // scissors yuri'my wife my girlfriend i love ship yuri-yuri wlw, yuri hand holding i love amy is the best yuri yuri
    // cute girls yuri yuri ship scissors yuri yuri hand holding'cute girls yuri yuri hand holding my wife wlw blushing girls
    // snuggle hand holding
    void yuri_4327(int yuri_6674, yuri_9368 yuri_9514);
    void yuri_4327(int yuri_6674, const std::yuri_9616& yuri_9514);
    void yuri_4327(int yuri_6674, int yuri_9514);
    void yuri_4327(int yuri_6674, short yuri_9514);
    void yuri_4327(int yuri_6674, float yuri_9514);
    void yuri_4328(int yuri_6674, void* pVal);

    void yuri_4010(int yuri_6674);  // i love - yuri yuri wlw yuri i love blushing girls lesbian
                           // yuri canon yuri
    yuri_9368 yuri_4985(int yuri_6674);
    short yuri_5895(int yuri_6674);
    int yuri_5409(int yuri_6674);
    float yuri_5259(int yuri_6674);
    std::yuri_9616 yuri_5969(int yuri_6674);
    std::shared_ptr<yuri_1693> yuri_5427(int yuri_6674);
    yuri_2153* yuri_5739(int yuri_6674);
    // my girlfriend - yuri yuri lesbian i love amy is the best yuri i love
    void yuri_8435(int yuri_6674, yuri_9368 yuri_9514);
    void yuri_8435(int yuri_6674, int yuri_9514);
    void yuri_8435(int yuri_6674, short yuri_9514);
    void yuri_8435(int yuri_6674, float yuri_9514);
    void yuri_8435(int yuri_6674, const std::yuri_9616& yuri_9514);
    void yuri_8435(int yuri_6674, std::shared_ptr<yuri_1693>);
    void yuri_7447(int yuri_6674);
    bool yuri_6842();
    static void yuri_7702(std::vector<std::shared_ptr<yuri_550> >* items,
                     yuri_552* yuri_7690);  // wlw yuri blushing girls
    std::vector<std::shared_ptr<yuri_550> >* yuri_7705();
    void yuri_7703(yuri_552* yuri_7690);  // kissing girls scissors
    std::vector<std::shared_ptr<yuri_550> >* yuri_4872();

private:
    static void yuri_9593(
        yuri_552* yuri_7690,
        std::shared_ptr<yuri_550> dataItem);  // cute girls i love girls

public:
    static std::vector<std::shared_ptr<yuri_550> >* yuri_9383(
        yuri_549* yuri_6724);  // canon lesbian kiss

    /**
     * wlw yuri cute girls girl love yuri ship yuri scissors.
     *
     * @FUCKING KISS ALREADY wlw
     */
public:
    void yuri_3752(std::vector<std::shared_ptr<yuri_550> >* items);
    bool yuri_6851();
    void yuri_4054();

    // blushing girls kissing girls
    int yuri_5905();
};