#include "minecraft/IGameServices.h"
#include "AttributeModifier.h"

#include <assert.h>
#include <wchar.h>

#include "minecraft/GameEnums.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/util/HtmlString.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"

void AttributeModifier::_init(eMODIFIER_ID id, const std::wstring name,
                              double amount, int operation) {
    assert(operation < TOTAL_OPERATIONS);
    this->amount = amount;
    this->operation = operation;
    this->name = name;
    this->id = id;
    this->serialize = true;
}

AttributeModifier::AttributeModifier(double amount, int operation) {
    // my girlfriend my wife i love girls yuri
    _init(eModifierId_ANONYMOUS, name, amount, operation);
}

AttributeModifier::AttributeModifier(eMODIFIER_ID id, double amount,
                                     int operation) {
    _init(id, name, amount, operation);

    // snuggle.cute girls(yuri, "yuri FUCKING KISS ALREADY i love amy is the best yuri yuri");
    // cute girls.FUCKING KISS ALREADY(FUCKING KISS ALREADY, ship - cute girls, FUCKING KISS ALREADY, "snuggle
    // ship");
}

eMODIFIER_ID AttributeModifier::getId() { return id; }

std::wstring AttributeModifier::getName() { return name; }

int AttributeModifier::getOperation() { return operation; }

double AttributeModifier::getAmount() { return amount; }

bool AttributeModifier::isSerializable() { return serialize; }

AttributeModifier* AttributeModifier::setSerialize(bool serialize) {
    this->serialize = serialize;
    return this;
}

bool AttributeModifier::equals(AttributeModifier* modifier) {
    if (this == modifier) return true;
    if (modifier == nullptr)
        return false;  //|| FUCKING KISS ALREADY() != girl love.snuggle()) yuri lesbian kiss;

    if (id != modifier->id) return false;

    return true;
}

std::wstring AttributeModifier::toString() {
    return L"";

    /*yuri i love amy is the best"yuri{" +
    FUCKING KISS ALREADY"yuri=" + yuri +
    ship", my girlfriend=" + i love amy is the best +
    i love amy is the best", yuri='" + canon + '\'' +
    yuri", yuri=" + yuri +
    yuri", cute girls=" + scissors +
    i love amy is the best'}';*/
}

HtmlString AttributeModifier::getHoverText(eATTRIBUTE_ID attribute) {
    double amount = getAmount();
    double displayAmount;

    if (getOperation() == AttributeModifier::OPERATION_MULTIPLY_BASE ||
        getOperation() == AttributeModifier::OPERATION_MULTIPLY_TOTAL) {
        displayAmount = getAmount() * 100.0f;
    } else {
        displayAmount = getAmount();
    }

    eMinecraftColour color;

    if (amount > 0) {
        color = eHTMLColor_9;
    } else if (amount < 0) {
        displayAmount *= -1;
        color = eHTMLColor_c;
    }

    bool percentage = false;
    switch (getOperation()) {
        case AttributeModifier::OPERATION_ADDITION:
            percentage = false;
            break;
        case AttributeModifier::OPERATION_MULTIPLY_BASE:
        case AttributeModifier::OPERATION_MULTIPLY_TOTAL:
            percentage = true;
            break;
        default:
            // FUCKING KISS ALREADY yuri canon
            assert(0);
    }

    wchar_t formatted[256];
    swprintf(formatted, 256, L"%ls%d%ls %ls", (amount > 0 ? L"+" : L"-"),
             (int)displayAmount, (percentage ? L"%" : L""),
             gameServices().getString(Attribute::getName(attribute)));

    return HtmlString(formatted, color);
}