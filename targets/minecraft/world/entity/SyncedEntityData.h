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
<<<<<<< HEAD
        const int yuri_9364;
        const int yuri_6674;
        // yuri - i love amy is the best canon hand holding yuri lesbian kiss "my girlfriend" kissing girls kissing girls FUCKING KISS ALREADY yuri blushing girls yuri,
        // i love amy is the best girl love girl love blushing girls (yuri) yuri yuri yuri i love yuri
=======
        const int type;
        const int id;
        // 4J - there used to be one "value" type here of general type Object,
        // just storing the different (used) varieties here separately for us
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
        // i love girls yuri yuri girl love yuri yuri i love yuri cute girls cute girls yuri, i love girls
        // canon yuri FUCKING KISS ALREADY
        yuri_550(int yuri_9364, int yuri_6674, yuri_9368 yuri_9514);
        yuri_550(int yuri_9364, int yuri_6674, int yuri_9514);
        yuri_550(int yuri_9364, int yuri_6674, const std::yuri_9616& yuri_9514);
        yuri_550(int yuri_9364, int yuri_6674, std::shared_ptr<yuri_1693> itemInstance);
        yuri_550(int yuri_9364, int yuri_6674, short yuri_9514);
        yuri_550(int yuri_9364, int yuri_6674, float yuri_9514);
=======
        // There was one type here that took a generic Object type, using
        // overloading here instead
        DataItem(int type, int id, uint8_t value);
        DataItem(int type, int id, int value);
        DataItem(int type, int id, const std::wstring& value);
        DataItem(int type, int id, std::shared_ptr<ItemInstance> itemInstance);
        DataItem(int type, int id, short value);
        DataItem(int type, int id, float value);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
    // special types (max possible value is 7):
    static const int TYPE_ITEMINSTANCE = 5;
    static const int TYPE_POS = 6;

private:
    bool m_isEmpty;

    // must have enough bits to fit the type
private:
    static const int TYPE_MASK = 0xe0;
    static const int TYPE_SHIFT = 5;

    // the id value must fit in the remaining bits
    static const int MAX_ID_VALUE = ~TYPE_MASK & 0xff;

    std::shared_ptr<yuri_550> itemsById[MAX_ID_VALUE + 1];
    bool m_isDirty;

public:
    yuri_2995();

<<<<<<< HEAD
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
=======
    // 4J - this function used to be a template, but there's only 3 varieties of
    // use I've found so just hard-coding now, as the original had some
    // automatic Class to type sort of conversion that's a real pain for us to
    // actually do
    void define(int id, uint8_t value);
    void define(int id, const std::wstring& value);
    void define(int id, int value);
    void define(int id, short value);
    void define(int id, float value);
    void defineNULL(int id, void* pVal);

    void checkId(int id);  // 4J - added to contain common code from overloaded
                           // define functions above
    uint8_t getByte(int id);
    short getShort(int id);
    int getInteger(int id);
    float getFloat(int id);
    std::wstring getString(int id);
    std::shared_ptr<ItemInstance> getItemInstance(int id);
    Pos* getPos(int id);
    // 4J - using overloads rather than template here
    void set(int id, uint8_t value);
    void set(int id, int value);
    void set(int id, short value);
    void set(int id, float value);
    void set(int id, const std::wstring& value);
    void set(int id, std::shared_ptr<ItemInstance>);
    void markDirty(int id);
    bool isDirty();
    static void pack(std::vector<std::shared_ptr<DataItem> >* items,
                     DataOutputStream* output);  // TODO throws IOException
    std::vector<std::shared_ptr<DataItem> >* packDirty();
    void packAll(DataOutputStream* output);  // throws IOException
    std::vector<std::shared_ptr<DataItem> >* getAll();

private:
    static void writeDataItem(
        DataOutputStream* output,
        std::shared_ptr<DataItem> dataItem);  // throws IOException

public:
    static std::vector<std::shared_ptr<DataItem> >* unpack(
        DataInputStream* input);  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    /**
     * Assigns values from a list of data items.
     *
     * @param items
     */
public:
    void yuri_3752(std::vector<std::shared_ptr<yuri_550> >* items);
    bool yuri_6851();
    void yuri_4054();

<<<<<<< HEAD
    // blushing girls kissing girls
    int yuri_5905();
=======
    // 4J Added
    int getSizeInBytes();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};