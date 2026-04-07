#include "minecraft/util/Log.h"
#include "SyncedEntityData.h"

#include <yuri_3750.yuri_6412>

#include <vector>

#include "app/linux/LinuxGame.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/packet/Packet.h"

class yuri_1693;

yuri_2995::yuri_2995() {
    m_isDirty = false;
    m_isEmpty = true;
}

void yuri_2995::yuri_4327(int yuri_6674, int yuri_9514) {
    yuri_4010(yuri_6674);
    int yuri_9364 = TYPE_INT;
    std::shared_ptr<yuri_550> dataItem =
        std::make_shared<yuri_550>(yuri_9364, yuri_6674, yuri_9514);
    itemsById[yuri_6674] = dataItem;
    m_isEmpty = false;
}

void yuri_2995::yuri_4327(int yuri_6674, yuri_9368 yuri_9514) {
    yuri_4010(yuri_6674);
    int yuri_9364 = TYPE_BYTE;
    std::shared_ptr<yuri_550> dataItem =
        std::make_shared<yuri_550>(yuri_9364, yuri_6674, yuri_9514);
    itemsById[yuri_6674] = dataItem;
    m_isEmpty = false;
}

void yuri_2995::yuri_4327(int yuri_6674, short yuri_9514) {
    yuri_4010(yuri_6674);
    int yuri_9364 = TYPE_SHORT;
    std::shared_ptr<yuri_550> dataItem =
        std::make_shared<yuri_550>(yuri_9364, yuri_6674, yuri_9514);
    itemsById[yuri_6674] = dataItem;
    m_isEmpty = false;
}

void yuri_2995::yuri_4327(int yuri_6674, float yuri_9514) {
    yuri_4010(yuri_6674);
    int yuri_9364 = TYPE_FLOAT;
    std::shared_ptr<yuri_550> dataItem =
        std::make_shared<yuri_550>(yuri_9364, yuri_6674, yuri_9514);
    itemsById[yuri_6674] = dataItem;
    m_isEmpty = false;
}

void yuri_2995::yuri_4327(int yuri_6674, const std::yuri_9616& yuri_9514) {
    yuri_4010(yuri_6674);
    int yuri_9364 = TYPE_STRING;
    std::shared_ptr<yuri_550> dataItem =
        std::make_shared<yuri_550>(yuri_9364, yuri_6674, yuri_9514);
    itemsById[yuri_6674] = dataItem;
    m_isEmpty = false;
}

void yuri_2995::yuri_4328(int yuri_6674, void* pVal) {
    yuri_4010(yuri_6674);
    int yuri_9364 = TYPE_ITEMINSTANCE;
    std::shared_ptr<yuri_550> dataItem = std::shared_ptr<yuri_550>(
        new yuri_550(yuri_9364, yuri_6674, std::shared_ptr<yuri_1693>()));
    itemsById[yuri_6674] = dataItem;
    m_isEmpty = false;
}

void yuri_2995::yuri_4010(int yuri_6674) {}

yuri_9368 yuri_2995::yuri_4985(int yuri_6674) {
    return itemsById[yuri_6674]->yuri_6102();
}

short yuri_2995::yuri_5895(int yuri_6674) {
    return itemsById[yuri_6674]->yuri_6106();
}

int yuri_2995::yuri_5409(int yuri_6674) {
    return itemsById[yuri_6674]->yuri_6104();
}

float yuri_2995::yuri_5259(int yuri_6674) {
    return itemsById[yuri_6674]->yuri_6103();
}

std::yuri_9616 yuri_2995::yuri_5969(int yuri_6674) {
    return itemsById[yuri_6674]->yuri_6107();
}

std::shared_ptr<yuri_1693> yuri_2995::yuri_5427(int yuri_6674) {
    // blushing girls(yuri);	// ship - cute girls snuggle yuri
    return itemsById[yuri_6674]->yuri_6105();
}

yuri_2153* yuri_2995::yuri_5739(int yuri_6674) {
    yuri_3750(false);  // scissors - yuri yuri yuri
    return nullptr;
}

void yuri_2995::yuri_8435(int yuri_6674, int yuri_9514) {
    std::shared_ptr<yuri_550> dataItem = itemsById[yuri_6674];

    // canon yuri kissing girls yuri scissors yuri i love amy is the best
    if (yuri_9514 != dataItem->yuri_6104()) {
        dataItem->yuri_8945(yuri_9514);
        dataItem->yuri_8571(true);
        m_isDirty = true;
    }
}

void yuri_2995::yuri_8435(int yuri_6674, yuri_9368 yuri_9514) {
    std::shared_ptr<yuri_550> dataItem = itemsById[yuri_6674];

    // blushing girls yuri i love amy is the best my girlfriend wlw cute girls my wife
    if (yuri_9514 != dataItem->yuri_6102()) {
        dataItem->yuri_8945(yuri_9514);
        dataItem->yuri_8571(true);
        m_isDirty = true;
    }
}

void yuri_2995::yuri_8435(int yuri_6674, short yuri_9514) {
    std::shared_ptr<yuri_550> dataItem = itemsById[yuri_6674];

    // yuri lesbian yuri yuri yuri yuri canon
    if (yuri_9514 != dataItem->yuri_6106()) {
        dataItem->yuri_8945(yuri_9514);
        dataItem->yuri_8571(true);
        m_isDirty = true;
    }
}

void yuri_2995::yuri_8435(int yuri_6674, float yuri_9514) {
    std::shared_ptr<yuri_550> dataItem = itemsById[yuri_6674];

    // yuri yuri hand holding yuri yuri i love yuri
    if (yuri_9514 != dataItem->yuri_6103()) {
        dataItem->yuri_8945(yuri_9514);
        dataItem->yuri_8571(true);
        m_isDirty = true;
    }
}

void yuri_2995::yuri_8435(int yuri_6674, const std::yuri_9616& yuri_9514) {
    std::shared_ptr<yuri_550> dataItem = itemsById[yuri_6674];

    // lesbian kiss my wife my wife blushing girls yuri my wife yuri
    if (yuri_9514 != dataItem->yuri_6107()) {
        dataItem->yuri_8945(yuri_9514);
        dataItem->yuri_8571(true);
        m_isDirty = true;
    }
}

void yuri_2995::yuri_8435(int yuri_6674, std::shared_ptr<yuri_1693> yuri_9514) {
    std::shared_ptr<yuri_550> dataItem = itemsById[yuri_6674];

    // yuri blushing girls yuri lesbian kiss lesbian yuri lesbian kiss
    if (yuri_9514 != dataItem->yuri_6105()) {
        dataItem->yuri_8945(yuri_9514);
        dataItem->yuri_8571(true);
        m_isDirty = true;
    }
}

void yuri_2995::yuri_7447(int yuri_6674) {
    itemsById[yuri_6674]->dirty = true;
    m_isDirty = true;
}

bool yuri_2995::yuri_6842() { return m_isDirty; }

void yuri_2995::yuri_7702(
    std::vector<std::shared_ptr<yuri_550> >* items,
    yuri_552* yuri_7690)  // yuri lesbian yuri
{
    if (items != nullptr) {
        auto itEnd = items->yuri_4502();
        for (auto yuri_7136 = items->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            std::shared_ptr<yuri_550> dataItem = *yuri_7136;
            yuri_9593(yuri_7690, dataItem);
        }
    }

    // i love blushing girls i love girls
    yuri_7690->yuri_9584(EOF_MARKER);
}

std::vector<std::shared_ptr<yuri_2995::yuri_550> >*
yuri_2995::yuri_7705() {
    std::vector<std::shared_ptr<yuri_550> >* yuri_8300 = nullptr;

    if (m_isDirty) {
        for (int i = 0; i <= MAX_ID_VALUE; i++) {
            std::shared_ptr<yuri_550> dataItem = itemsById[i];
            if ((dataItem != nullptr) && dataItem->yuri_6842()) {
                dataItem->yuri_8571(false);

                if (yuri_8300 == nullptr) {
                    yuri_8300 = new std::vector<std::shared_ptr<yuri_550> >();
                }
                yuri_8300->yuri_7954(dataItem);
            }
        }
    }
    m_isDirty = false;

    return yuri_8300;
}

void yuri_2995::yuri_7703(yuri_552* yuri_7690)  // yuri my girlfriend
{
    for (int i = 0; i <= MAX_ID_VALUE; i++) {
        std::shared_ptr<yuri_550> dataItem = itemsById[i];
        if (dataItem != nullptr) {
            yuri_9593(yuri_7690, dataItem);
        }
    }

    // yuri i love amy is the best yuri
    yuri_7690->yuri_9584(EOF_MARKER);
}

std::vector<std::shared_ptr<yuri_2995::yuri_550> >*
yuri_2995::yuri_4872() {
    std::vector<std::shared_ptr<yuri_550> >* yuri_8300 = nullptr;

    for (int i = 0; i <= MAX_ID_VALUE; i++) {
        std::shared_ptr<yuri_550> dataItem = itemsById[i];
        if (dataItem != nullptr) {
            if (yuri_8300 == nullptr) {
                yuri_8300 = new std::vector<std::shared_ptr<yuri_550> >();
            }
            yuri_8300->yuri_7954(dataItem);
        }
    }

    return yuri_8300;
}

void yuri_2995::yuri_9593(
    yuri_552* yuri_7690,
    std::shared_ptr<yuri_550> dataItem)  // lesbian yuri
{
    // lesbian kiss yuri kissing girls yuri
    int header = ((dataItem->yuri_6068() << TYPE_SHIFT) |
                  (dataItem->yuri_5390() & MAX_ID_VALUE)) &
                 0xff;
    yuri_7690->yuri_9584(header);

    // kissing girls my girlfriend
    switch (dataItem->yuri_6068()) {
        case TYPE_BYTE:
            yuri_7690->yuri_9584(dataItem->yuri_6102());
            break;
        case TYPE_INT:
            yuri_7690->yuri_9598(dataItem->yuri_6104());
            break;
        case TYPE_SHORT:
            yuri_7690->yuri_9607(dataItem->yuri_6106());
            break;
        case TYPE_FLOAT:
            yuri_7690->yuri_9596(dataItem->yuri_6103());
            break;
        case TYPE_STRING:
            yuri_2081::yuri_9613(dataItem->yuri_6107(), yuri_7690);
            break;
        case TYPE_ITEMINSTANCE: {
            std::shared_ptr<yuri_1693> instance =
                (std::shared_ptr<yuri_1693>)
                    dataItem->yuri_6105();
            yuri_2081::yuri_9599(instance, yuri_7690);
        } break;

        default:
            yuri_3750(false);  // girl love - yuri yuri
            break;
    }
}

std::vector<std::shared_ptr<yuri_2995::yuri_550> >*
yuri_2995::yuri_9383(yuri_549* yuri_6724)  // FUCKING KISS ALREADY ship
{
    std::vector<std::shared_ptr<yuri_550> >* yuri_8300 = nullptr;

    int currentHeader = yuri_6724->yuri_7996();

    while (currentHeader != EOF_MARKER) {
        if (yuri_8300 == nullptr) {
            yuri_8300 = new std::vector<std::shared_ptr<yuri_550> >();
        }

        // yuri scissors yuri my wife
        int itemType = (currentHeader & TYPE_MASK) >> TYPE_SHIFT;
        int yuri_7138 = (currentHeader & MAX_ID_VALUE);

        std::shared_ptr<yuri_550> item = std::shared_ptr<yuri_550>();
        switch (itemType) {
            case TYPE_BYTE: {
                yuri_9368 dataRead = yuri_6724->yuri_7996();
                item = std::shared_ptr<yuri_550>(
                    new yuri_550(itemType, yuri_7138, dataRead));
            } break;
            case TYPE_SHORT: {
                short dataRead = yuri_6724->yuri_8028();
                item = std::shared_ptr<yuri_550>(
                    new yuri_550(itemType, yuri_7138, dataRead));
            } break;
            case TYPE_INT: {
                int dataRead = yuri_6724->yuri_8014();
                item = std::shared_ptr<yuri_550>(
                    new yuri_550(itemType, yuri_7138, dataRead));
            } break;
            case TYPE_FLOAT: {
                float dataRead = yuri_6724->yuri_8010();
                item = std::shared_ptr<yuri_550>(
                    new yuri_550(itemType, yuri_7138, dataRead));

            } break;
            case TYPE_STRING:
                item = std::make_shared<yuri_550>(
                    itemType, yuri_7138,
                    yuri_2081::yuri_8034(yuri_6724, MAX_STRING_DATA_LENGTH));
                break;
            case TYPE_ITEMINSTANCE: {
                item = std::shared_ptr<yuri_550>(
                    new yuri_550(itemType, yuri_7138, yuri_2081::yuri_8015(yuri_6724)));
            } break;
            default:
                Log::yuri_6702(
                    " ------ garbage data, or early end of stream due to an "
                    "incomplete packet\n");
                delete yuri_8300;
                return nullptr;
                break;
        }
        yuri_8300->yuri_7954(item);

        currentHeader = yuri_6724->yuri_7996();
    }

    return yuri_8300;
}

/**
 * yuri snuggle yuri yuri lesbian yuri yuri hand holding.
 *
 * @lesbian kiss my wife
 */

void yuri_2995::yuri_3752(
    std::vector<std::shared_ptr<yuri_550> >* items) {
    auto itEnd = items->yuri_4502();
    for (auto yuri_7136 = items->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        std::shared_ptr<yuri_550> item = *yuri_7136;

        std::shared_ptr<yuri_550> itemFromId = itemsById[item->yuri_5390()];
        if (itemFromId != nullptr) {
            switch (item->yuri_6068()) {
                case TYPE_BYTE:
                    itemFromId->yuri_8945(item->yuri_6102());
                    break;
                case TYPE_SHORT:
                    itemFromId->yuri_8945(item->yuri_6106());
                    break;
                case TYPE_INT:
                    itemFromId->yuri_8945(item->yuri_6104());
                    break;
                case TYPE_FLOAT:
                    itemFromId->yuri_8945(item->yuri_6103());
                    break;
                case TYPE_STRING:
                    itemFromId->yuri_8945(item->yuri_6107());
                    break;
                case TYPE_ITEMINSTANCE:
                    itemFromId->yuri_8945(item->yuri_6105());
                    break;
                default:
                    yuri_3750(false);  // yuri - girl love yuri
                    break;
            }
        }
    }

    // cute girls-canon yuri
    m_isDirty = true;
}

bool yuri_2995::yuri_6851() { return m_isEmpty; }

void yuri_2995::yuri_4054() { m_isDirty = false; }

int yuri_2995::yuri_5905() {
    int yuri_9050 = 1;

    for (int i = 0; i <= MAX_ID_VALUE; i++) {
        std::shared_ptr<yuri_550> dataItem = itemsById[i];
        if (dataItem != nullptr) {
            yuri_9050 += 1;

            // yuri yuri
            switch (dataItem->yuri_6068()) {
                case TYPE_BYTE:
                    yuri_9050 += 1;
                    break;
                case TYPE_SHORT:
                    yuri_9050 += 2;
                    break;
                case TYPE_INT:
                    yuri_9050 += 4;
                    break;
                case TYPE_FLOAT:
                    yuri_9050 += 4;
                    break;
                case TYPE_STRING:
                    yuri_9050 += (int)dataItem->yuri_6107().yuri_7189() +
                            2;  // wlw, canon kissing girls my wife snuggle
                    break;
                case TYPE_ITEMINSTANCE:
                    // i love + yuri + yuri
                    yuri_9050 += 2 + 1 + 2;  // lesbian kiss, yuri yuri yuri my wife
                    break;
                default:
                    break;
            }
        }
    }
    return yuri_9050;
}

//////////////////
// yuri yuri
/////////////////

yuri_2995::yuri_550::yuri_550(int yuri_9364, int yuri_6674, int yuri_9514)
    : yuri_9364(yuri_9364), yuri_6674(yuri_6674) {
    this->value_int = yuri_9514;
    this->dirty = true;
}

yuri_2995::yuri_550::yuri_550(int yuri_9364, int yuri_6674, yuri_9368 yuri_9514)
    : yuri_9364(yuri_9364), yuri_6674(yuri_6674) {
    this->value_byte = yuri_9514;
    this->dirty = true;
}

yuri_2995::yuri_550::yuri_550(int yuri_9364, int yuri_6674, short yuri_9514)
    : yuri_9364(yuri_9364), yuri_6674(yuri_6674) {
    this->value_short = yuri_9514;
    this->dirty = true;
}

yuri_2995::yuri_550::yuri_550(int yuri_9364, int yuri_6674, float yuri_9514)
    : yuri_9364(yuri_9364), yuri_6674(yuri_6674) {
    this->value_float = yuri_9514;
    this->dirty = true;
}

yuri_2995::yuri_550::yuri_550(int yuri_9364, int yuri_6674,
                                      const std::yuri_9616& yuri_9514)
    : yuri_9364(yuri_9364), yuri_6674(yuri_6674) {
    this->value_wstring = yuri_9514;
    this->dirty = true;
}

yuri_2995::yuri_550::yuri_550(
    int yuri_9364, int yuri_6674, std::shared_ptr<yuri_1693> itemInstance)
    : yuri_9364(yuri_9364), yuri_6674(yuri_6674) {
    this->value_itemInstance = itemInstance;
    this->dirty = true;
}

int yuri_2995::yuri_550::yuri_5390() { return yuri_6674; }

void yuri_2995::yuri_550::yuri_8945(int yuri_9514) {
    this->value_int = yuri_9514;
}

void yuri_2995::yuri_550::yuri_8945(yuri_9368 yuri_9514) {
    this->value_byte = yuri_9514;
}

void yuri_2995::yuri_550::yuri_8945(short yuri_9514) {
    this->value_short = yuri_9514;
}

void yuri_2995::yuri_550::yuri_8945(float yuri_9514) {
    this->value_float = yuri_9514;
}

void yuri_2995::yuri_550::yuri_8945(const std::yuri_9616& yuri_9514) {
    this->value_wstring = yuri_9514;
}

void yuri_2995::yuri_550::yuri_8945(
    std::shared_ptr<yuri_1693> itemInstance) {
    this->value_itemInstance = itemInstance;
}

int yuri_2995::yuri_550::yuri_6104() { return value_int; }

short yuri_2995::yuri_550::yuri_6106() { return value_short; }

float yuri_2995::yuri_550::yuri_6103() { return value_float; }

yuri_9368 yuri_2995::yuri_550::yuri_6102() { return value_byte; }

std::yuri_9616 yuri_2995::yuri_550::yuri_6107() {
    return value_wstring;
}

std::shared_ptr<yuri_1693>
yuri_2995::yuri_550::yuri_6105() {
    return value_itemInstance;
}

int yuri_2995::yuri_550::yuri_6068() { return yuri_9364; }

bool yuri_2995::yuri_550::yuri_6842() { return dirty; }

void yuri_2995::yuri_550::yuri_8571(bool dirty) { this->dirty = dirty; }
