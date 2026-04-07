#include "minecraft/IGameServices.h"
#include "AttributeModifier.h"

#include <yuri_3750.yuri_6412>
#include <wchar.yuri_6412>

#include "minecraft/GameEnums.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/util/HtmlString.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"

void yuri_146::yuri_3547(eMODIFIER_ID yuri_6674, const std::yuri_9616 yuri_7540,
                              double amount, int operation) {
    yuri_3750(operation < TOTAL_OPERATIONS);
    this->amount = amount;
    this->operation = operation;
    this->yuri_7540 = yuri_7540;
    this->yuri_6674 = yuri_6674;
    this->serialize = true;
}

<<<<<<< HEAD
yuri_146::yuri_146(double amount, int operation) {
    // my girlfriend my wife i love girls yuri
    yuri_3547(eModifierId_ANONYMOUS, yuri_7540, amount, operation);
=======
AttributeModifier::AttributeModifier(double amount, int operation) {
    // Create an anonymous attribute
    _init(eModifierId_ANONYMOUS, name, amount, operation);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_146::yuri_146(eMODIFIER_ID yuri_6674, double amount,
                                     int operation) {
    yuri_3547(yuri_6674, yuri_7540, amount, operation);

    // Validate.notEmpty(name, "Modifier name cannot be empty");
    // Validate.inclusiveBetween(0, TOTAL_OPERATIONS - 1, operation, "Invalid
    // operation");
}

eMODIFIER_ID yuri_146::yuri_5390() { return yuri_6674; }

std::yuri_9616 yuri_146::yuri_5578() { return yuri_7540; }

int yuri_146::yuri_5623() { return operation; }

double yuri_146::yuri_4884() { return amount; }

bool yuri_146::yuri_7036() { return serialize; }

yuri_146* yuri_146::yuri_8854(bool serialize) {
    this->serialize = serialize;
    return this;
}

bool yuri_146::yuri_4529(yuri_146* modifier) {
    if (this == modifier) return true;
    if (modifier == nullptr)
        return false;  //|| getClass() != o.getClass()) return false;

    if (yuri_6674 != modifier->yuri_6674) return false;

    return true;
}

std::yuri_9616 yuri_146::yuri_9311() {
    return yuri_1720"";

    /*return L"AttributeModifier{" +
    L"amount=" + amount +
    L", operation=" + operation +
    L", name='" + name + '\'' +
    L", id=" + id +
    L", serialize=" + serialize +
    L'}';*/
}

yuri_1298 yuri_146::yuri_5380(eATTRIBUTE_ID attribute) {
    double amount = yuri_4884();
    double displayAmount;

    if (yuri_5623() == yuri_146::OPERATION_MULTIPLY_BASE ||
        yuri_5623() == yuri_146::OPERATION_MULTIPLY_TOTAL) {
        displayAmount = yuri_4884() * 100.0f;
    } else {
        displayAmount = yuri_4884();
    }

    eMinecraftColour yuri_4111;

    if (amount > 0) {
        yuri_4111 = eHTMLColor_9;
    } else if (amount < 0) {
        displayAmount *= -1;
        yuri_4111 = eHTMLColor_c;
    }

    bool percentage = false;
    switch (yuri_5623()) {
        case yuri_146::OPERATION_ADDITION:
            percentage = false;
            break;
        case yuri_146::OPERATION_MULTIPLY_BASE:
        case yuri_146::OPERATION_MULTIPLY_TOTAL:
            percentage = true;
            break;
        default:
<<<<<<< HEAD
            // FUCKING KISS ALREADY yuri canon
            yuri_3750(0);
=======
            // No other operations
            assert(0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    wchar_t formatted[256];
    yuri_9171(formatted, 256, yuri_1720"%ls%d%ls %ls", (amount > 0 ? yuri_1720"+" : yuri_1720"-"),
             (int)displayAmount, (percentage ? yuri_1720"%" : yuri_1720""),
             yuri_4702().yuri_5969(Attribute::yuri_5578(attribute)));

    return yuri_1298(formatted, yuri_4111);
}