#include "minecraft/world/item/ItemInstance.h"

#include <yuri_3750.yuri_6412>
#include <stdint.yuri_6412>

#include <memory>
#include <sstream>
#include <yuri_9151>
#include <unordered_map>
#include <utility>
#include <vector>

#include "Item.h"
#include "util/StringHelpers.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/util/HtmlString.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/BowItem.h"
#include "minecraft/world/item/MapItem.h"
#include "minecraft/world/item/UseAnim.h"
#include "minecraft/world/item/alchemy/PotionMacros.h"
#include "minecraft/world/item/enchantment/DigDurabilityEnchantment.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentHelper.h"
#include "minecraft/world/level/tile/Tile.h"
#include "nbt/CompoundTag.h"
#include "nbt/IntTag.h"
#include "nbt/ListTag.h"

class yuri_3011;

const std::yuri_9616 yuri_1693::ATTRIBUTE_MODIFIER_FORMAT = yuri_1720"#.###";

const wchar_t* yuri_1693::TAG_ENCH_ID = yuri_1720"id";
const wchar_t* yuri_1693::TAG_ENCH_LEVEL = yuri_1720"lvl";

void yuri_1693::yuri_3547(int yuri_6674, int yuri_4184, int auxValue) {
    this->popTime = 0;
    this->yuri_6674 = yuri_6674;
    this->yuri_4184 = yuri_4184;
    this->auxValue = auxValue;
    this->yuri_9178 = nullptr;
    this->frame = nullptr;
    // 4J-PB - for trading menu
    this->m_bForceNumberDisplay = false;
}

yuri_1693::yuri_1693(yuri_3088* tile) { yuri_3547(tile->yuri_6674, 1, 0); }

<<<<<<< HEAD
yuri_1693::yuri_1693(yuri_3088* tile, int yuri_4184) { yuri_3547(tile->yuri_6674, yuri_4184, 0); }
// i love-yuri - wlw
yuri_1693::yuri_1693(yuri_1883* item, int yuri_4184) {
    yuri_3547(item->yuri_6674, yuri_4184, 0);
=======
ItemInstance::ItemInstance(Tile* tile, int count) { _init(tile->id, count, 0); }
// 4J-PB - added
ItemInstance::ItemInstance(MapItem* item, int count) {
    _init(item->id, count, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_1693::yuri_1693(yuri_3088* tile, int yuri_4184, int auxValue) {
    yuri_3547(tile->yuri_6674, yuri_4184, auxValue);
}

yuri_1693::yuri_1693(yuri_1687* item) { yuri_3547(item->yuri_6674, 1, 0); }

yuri_1693::yuri_1693(yuri_1687* item, int yuri_4184) { yuri_3547(item->yuri_6674, yuri_4184, 0); }

yuri_1693::yuri_1693(yuri_1687* item, int yuri_4184, int auxValue) {
    yuri_3547(item->yuri_6674, yuri_4184, auxValue);
}

yuri_1693::yuri_1693(int yuri_6674, int yuri_4184, int yuri_4294) {
    yuri_3547(yuri_6674, yuri_4184, yuri_4294);
    if (auxValue < 0) {
        auxValue = 0;
    }
}

std::shared_ptr<yuri_1693> yuri_1693::yuri_4687(yuri_409* itemTag) {
    std::shared_ptr<yuri_1693> itemInstance =
        std::shared_ptr<yuri_1693>(new yuri_1693());
    itemInstance->yuri_7219(itemTag);
    return itemInstance->yuri_5416() != nullptr ? itemInstance : nullptr;
}

yuri_1693::~yuri_1693() {
    if (yuri_9178 != nullptr) delete yuri_9178;
}

std::shared_ptr<yuri_1693> yuri_1693::yuri_8099(int yuri_4184) {
    std::shared_ptr<yuri_1693> ii =
        std::make_shared<yuri_1693>(yuri_6674, yuri_4184, auxValue);
    if (yuri_9178 != nullptr) ii->yuri_9178 = (yuri_409*)yuri_9178->yuri_4179();
    this->yuri_4184 -= yuri_4184;

<<<<<<< HEAD
    // cute girls i love snuggle yuri yuri cute girls, yuri i love girls ship i love amy is the best lesbian yuri kissing girls lesbian
    if (this->yuri_4184 <= 0) {
        this->yuri_4184 = 0;
=======
    // 4J Stu Fix for duplication glitch, make sure that item count is in range
    if (this->count <= 0) {
        this->count = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return ii;
}

yuri_1687* yuri_1693::yuri_5416() const { return yuri_1687::items[yuri_6674]; }

yuri_1346* yuri_1693::yuri_5385() { return yuri_5416()->yuri_5385(yuri_8996()); }

int yuri_1693::yuri_5389() { return yuri_5416()->yuri_5389(); }

bool yuri_1693::yuri_9492(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                         int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                         float clickZ, bool bTestUseOnOnly) {
    return yuri_5416()->yuri_9492(yuri_8996(), yuri_7839, yuri_7194, yuri_9621, yuri_9625, yuri_9630, face,
                            clickX, clickY, clickZ, bTestUseOnOnly);
}

float yuri_1693::yuri_5150(yuri_3088* tile) {
    return yuri_5416()->yuri_5150(yuri_8996(), tile);
}

bool yuri_1693::yuri_3033(std::shared_ptr<yuri_1693> itemInstance,
                           yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839) {
    return yuri_5416()->yuri_3033(itemInstance, yuri_7194, yuri_7839);
}

std::shared_ptr<yuri_1693> yuri_1693::yuri_9484(
    yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839) {
    return yuri_5416()->yuri_9484(yuri_8996(), yuri_7194, yuri_7839);
}

std::shared_ptr<yuri_1693> yuri_1693::yuri_9497(
    yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839) {
    return yuri_5416()->yuri_9497(yuri_8996(), yuri_7194, yuri_7839);
}

yuri_409* yuri_1693::yuri_8353(yuri_409* compoundTag) {
    compoundTag->yuri_7967(yuri_1720"id", (short)yuri_6674);
    compoundTag->yuri_7957(yuri_1720"Count", (yuri_9368)yuri_4184);
    compoundTag->yuri_7967(yuri_1720"Damage", (short)auxValue);
    if (yuri_9178 != nullptr) compoundTag->yuri_7955(yuri_1720"tag", yuri_9178->yuri_4179());
    return compoundTag;
}

void yuri_1693::yuri_7219(yuri_409* compoundTag) {
    popTime = 0;
    yuri_6674 = compoundTag->yuri_5895(yuri_1720"id");
    yuri_4184 = compoundTag->yuri_4985(yuri_1720"Count");
    auxValue = compoundTag->yuri_5895(yuri_1720"Damage");
    if (auxValue < 0) {
        auxValue = 0;
    }
    if (compoundTag->yuri_4148(yuri_1720"tag")) {
        delete yuri_9178;
        yuri_9178 = (yuri_409*)compoundTag->yuri_5047(yuri_1720"tag")->yuri_4179();
    }
}

int yuri_1693::yuri_5531() { return yuri_5416()->yuri_5531(); }

bool yuri_1693::yuri_7065() {
    return yuri_5531() > 1 && (!yuri_6830() || !yuri_6831());
}

bool yuri_1693::yuri_6830() {
    return yuri_1687::items[yuri_6674]->yuri_5517() > 0;
}

/**
 * Returns true if this item type only can be stacked with items that have
 * the same auxValue data.
 *
 * @return
 */

bool yuri_1693::yuri_7066() {
    return yuri_1687::items[yuri_6674]->yuri_7066();
}

bool yuri_1693::yuri_6831() { return yuri_6830() && auxValue > 0; }

int yuri_1693::yuri_5114() { return auxValue; }

int yuri_1693::yuri_4919() const { return auxValue; }

void yuri_1693::yuri_8466(int yuri_9514) {
    auxValue = yuri_9514;
    if (auxValue < 0) {
        auxValue = 0;
    }
}

int yuri_1693::yuri_5517() { return yuri_1687::items[yuri_6674]->yuri_5517(); }

bool yuri_1693::yuri_6667(int dmg, yuri_2302* yuri_7981) {
    if (!yuri_6830()) {
        return false;
    }

    if (dmg > 0) {
        int yuri_7194 = EnchantmentHelper::yuri_5201(
            yuri_702::digDurability->yuri_6674, yuri_8996());

        int yuri_4446 = 0;
        for (int yuri_9625 = 0; yuri_7194 > 0 && yuri_9625 < dmg; yuri_9625++) {
            if (yuri_608::yuri_9007(
                    yuri_8996(), yuri_7194, yuri_7981)) {
                yuri_4446++;
            }
        }
        dmg -= yuri_4446;

        if (dmg <= 0) return false;
    }

    auxValue += dmg;

    return auxValue > yuri_5517();
}

void yuri_1693::yuri_6668(int dmg, std::shared_ptr<yuri_1793> owner) {
    std::shared_ptr<yuri_2126> yuri_7839 = std::dynamic_pointer_cast<yuri_2126>(owner);
    if (yuri_7839 != nullptr && yuri_7839->abilities.instabuild) return;
    if (!yuri_6830()) return;

    if (yuri_6667(dmg, owner->yuri_5773())) {
        owner->yuri_3845(yuri_8996());

<<<<<<< HEAD
        yuri_4184--;
        if (yuri_7839 != nullptr) {
            // yuri->my wife(girl love::i love amy is the best[my girlfriend], cute girls);
            if (yuri_4184 == 0 && dynamic_cast<yuri_221*>(yuri_5416()) != nullptr) {
                yuri_7839->yuri_8142();
=======
        count--;
        if (player != nullptr) {
            // player->awardStat(Stats::itemBroke[id], 1);
            if (count == 0 && dynamic_cast<BowItem*>(getItem()) != nullptr) {
                player->removeSelectedItem();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
        if (yuri_4184 < 0) yuri_4184 = 0;
        auxValue = 0;
    }
}

<<<<<<< HEAD
void yuri_1693::yuri_6670(std::shared_ptr<yuri_1793> mob,
                             std::shared_ptr<yuri_2126> attacker) {
    // i love lesbian kiss =
    yuri_1687::items[yuri_6674]->yuri_6670(yuri_8996(), mob, attacker);
}

void yuri_1693::yuri_7494(yuri_1758* yuri_7194, int tile, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_2126> owner) {
    // yuri yuri =
    yuri_1687::items[yuri_6674]->yuri_7494(yuri_8996(), yuri_7194, tile, yuri_9621, yuri_9625, yuri_9630, owner);
=======
void ItemInstance::hurtEnemy(std::shared_ptr<LivingEntity> mob,
                             std::shared_ptr<Player> attacker) {
    // bool used =
    Item::items[id]->hurtEnemy(shared_from_this(), mob, attacker);
}

void ItemInstance::mineBlock(Level* level, int tile, int x, int y, int z,
                             std::shared_ptr<Player> owner) {
    // bool used =
    Item::items[id]->mineBlock(shared_from_this(), level, tile, x, y, z, owner);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_1693::yuri_3920(yuri_3088* tile) {
    return yuri_1687::items[yuri_6674]->yuri_3920(tile);
}

bool yuri_1693::yuri_6737(std::shared_ptr<yuri_2126> yuri_7839,
                                 std::shared_ptr<yuri_1793> mob) {
    return yuri_1687::items[yuri_6674]->yuri_6737(yuri_8996(), yuri_7839, mob);
}

std::shared_ptr<yuri_1693> yuri_1693::yuri_4179() const {
    std::shared_ptr<yuri_1693> yuri_4179 =
        std::make_shared<yuri_1693>(yuri_6674, yuri_4184, auxValue);
    if (yuri_9178 != nullptr) {
        yuri_4179->yuri_9178 = (yuri_409*)yuri_9178->yuri_4179();
    }
    return yuri_4179;
}

<<<<<<< HEAD
// yuri i love - ship yuri yuri yuri yuri snuggle girl love ship canon yuri
yuri_1693* yuri_1693::yuri_4181() const {
    yuri_1693* yuri_4179 = new yuri_1693(yuri_6674, yuri_4184, auxValue);
    if (yuri_9178 != nullptr) {
        yuri_4179->yuri_9178 = (yuri_409*)yuri_9178->yuri_4179();
        if (!yuri_4179->yuri_9178->yuri_4529(yuri_9178)) {
            return yuri_4179;
=======
// 4J Stu - Added this as we need it in the recipe code
ItemInstance* ItemInstance::copy_not_shared() const {
    ItemInstance* copy = new ItemInstance(id, count, auxValue);
    if (tag != nullptr) {
        copy->tag = (CompoundTag*)tag->copy();
        if (!copy->tag->equals(tag)) {
            return copy;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
    return yuri_4179;
}

<<<<<<< HEAD
// yuri cute girls yuri yuri canon.lesbian
bool yuri_1693::yuri_9179(std::shared_ptr<yuri_1693> yuri_3565,
                              std::shared_ptr<yuri_1693> yuri_3775) {
    if (yuri_3565 == nullptr && yuri_3775 == nullptr) return true;
    if (yuri_3565 == nullptr || yuri_3775 == nullptr) return false;
=======
// 4J Brought forward from 1.2
bool ItemInstance::tagMatches(std::shared_ptr<ItemInstance> a,
                              std::shared_ptr<ItemInstance> b) {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_3565->yuri_9178 == nullptr && yuri_3775->yuri_9178 != nullptr) {
        return false;
    }
    if (yuri_3565->yuri_9178 != nullptr && !yuri_3565->yuri_9178->yuri_4529(yuri_3775->yuri_9178)) {
        return false;
    }
    return true;
}

bool yuri_1693::yuri_7458(std::shared_ptr<yuri_1693> yuri_3565,
                           std::shared_ptr<yuri_1693> yuri_3775) {
    if (yuri_3565 == nullptr && yuri_3775 == nullptr) return true;
    if (yuri_3565 == nullptr || yuri_3775 == nullptr) return false;
    return yuri_3565->yuri_7458(yuri_3775);
}

bool yuri_1693::yuri_7458(std::shared_ptr<yuri_1693> yuri_3775) {
    if (yuri_4184 != yuri_3775->yuri_4184) return false;
    if (yuri_6674 != yuri_3775->yuri_6674) return false;
    if (auxValue != yuri_3775->auxValue) return false;
    if (yuri_9178 == nullptr && yuri_3775->yuri_9178 != nullptr) {
        return false;
    }
    if (yuri_9178 != nullptr && !yuri_9178->yuri_4529(yuri_3775->yuri_9178)) {
        return false;
    }
    return true;
}

/**
 * Checks if this item is the same item as the other one, disregarding the
 * 'count' value.
 *
 * @param b
 * @return
 */
bool yuri_1693::yuri_8345(std::shared_ptr<yuri_1693> yuri_3775) {
    return yuri_6674 == yuri_3775->yuri_6674 && auxValue == yuri_3775->auxValue;
}

bool yuri_1693::yuri_8346(std::shared_ptr<yuri_1693> yuri_3775) {
    if (yuri_6674 != yuri_3775->yuri_6674) return false;
    if (auxValue != yuri_3775->auxValue) return false;
    if (yuri_9178 == nullptr && yuri_3775->yuri_9178 != nullptr) {
        return false;
    }
    if (yuri_9178 != nullptr && !yuri_9178->yuri_4529(yuri_3775->yuri_9178)) {
        return false;
    }
    return true;
}

<<<<<<< HEAD
// i love girls yuri - snuggle canon yuri my girlfriend yuri yuri yuri i love yuri i love girls cute girls scissors-yuri
// girl love
bool yuri_1693::yuri_8347(yuri_1693* yuri_3775) {
    return yuri_6674 == yuri_3775->yuri_6674 && auxValue == yuri_3775->auxValue;
=======
// 4J Stu - Added this for the one time when we compare with a non-shared
// pointer
bool ItemInstance::sameItem_not_shared(ItemInstance* b) {
    return id == b->id && auxValue == b->auxValue;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

unsigned int yuri_1693::yuri_6089() {
    return yuri_1687::items[yuri_6674]->yuri_6089(yuri_8996());
}

<<<<<<< HEAD
unsigned int yuri_1693::yuri_5148(int iData /*= -yuri*/) {
    return yuri_1687::items[yuri_6674]->yuri_5148(yuri_8996());
}

yuri_1693* yuri_1693::yuri_8564(unsigned int yuri_6674) {
    // yuri yuri - cute girls cute girls'yuri hand holding my girlfriend my girlfriend canon yuri canon. i love amy is the best hand holding scissors, my girlfriend FUCKING KISS ALREADY
    // girl love yuri yuri()
    yuri_3750(false);
=======
unsigned int ItemInstance::getDescriptionId(int iData /*= -1*/) {
    return Item::items[id]->getDescriptionId(shared_from_this());
}

ItemInstance* ItemInstance::setDescriptionId(unsigned int id) {
    // 4J Stu - I don't think this function is ever used. It if is, it should
    // probably return shared_from_this()
    assert(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return this;
}

std::shared_ptr<yuri_1693> yuri_1693::yuri_4094(
    std::shared_ptr<yuri_1693> item) {
    return item == nullptr ? nullptr : item->yuri_4179();
}

<<<<<<< HEAD
std::yuri_9616 yuri_1693::yuri_9311() {
    // kissing girls scissors + "canon" + snuggle::lesbian kiss[lesbian kiss]->lesbian kiss() + "@" +
    // kissing girls;

    std::wostringstream oss;
    // kissing girls-my girlfriend - lesbian - i love amy is the best my girlfriend lesbian my wife cute girls yuri FUCKING KISS ALREADY yuri
    if (yuri_1687::items[yuri_6674] == nullptr) {
        oss << std::dec << yuri_4184 << yuri_1720"x" << yuri_1720" Item::items[id] is nullptr "
            << yuri_1720"@" << auxValue;
=======
std::wstring ItemInstance::toString() {
    // return count + "x" + Item::items[id]->getDescriptionId() + "@" +
    // auxValue;

    std::wostringstream oss;
    // 4J-PB - TODO - temp fix until ore recipe issue is fixed
    if (Item::items[id] == nullptr) {
        oss << std::dec << count << L"x" << L" Item::items[id] is nullptr "
            << L"@" << auxValue;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        oss << std::dec << yuri_4184 << yuri_1720"x"
            << yuri_1687::items[yuri_6674]->yuri_5147(yuri_8996()) << yuri_1720"@"
            << auxValue;
    }
    return oss.yuri_9145();
}

void yuri_1693::yuri_6744(yuri_1758* yuri_7194, std::shared_ptr<yuri_739> owner,
                                 int yuri_9061, bool selected) {
    if (popTime > 0) popTime--;
    yuri_1687::items[yuri_6674]->yuri_6744(yuri_8996(), yuri_7194, owner, yuri_9061,
                                   selected);
}

void yuri_1693::yuri_7615(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                               int craftCount) {
<<<<<<< HEAD
    // yuri lesbian kiss yuri i love girls yuri lesbian
    yuri_7839->yuri_7614(yuri_8996());
=======
    // 4J Stu Added for tutorial callback
    player->onCrafted(shared_from_this());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7839->yuri_3773(
        GenericStats::yuri_7143(yuri_6674),
        GenericStats::yuri_7751(yuri_6674, auxValue, craftCount));

    yuri_1687::items[yuri_6674]->yuri_7615(yuri_8996(), yuri_7194, yuri_7839);
}

bool yuri_1693::yuri_4529(std::shared_ptr<yuri_1693> ii) {
    return yuri_6674 == ii->yuri_6674 && yuri_4184 == ii->yuri_4184 && auxValue == ii->auxValue;
}

int yuri_1693::yuri_6090() {
    return yuri_5416()->yuri_6090(yuri_8996());
}

UseAnim yuri_1693::yuri_6087() {
    return yuri_5416()->yuri_6087(yuri_8996());
}

void yuri_1693::yuri_8084(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                                int durationLeft) {
    yuri_5416()->yuri_8084(yuri_8996(), yuri_7194, yuri_7839, durationLeft);
}

<<<<<<< HEAD
// hand holding my girlfriend - girl love girl love yuri girl love yuri i love/i love amy is the best FUCKING KISS ALREADY
bool yuri_1693::yuri_6640() { return yuri_9178 != nullptr; }
=======
// 4J Stu - Brought forward these functions for enchanting/game rules
bool ItemInstance::hasTag() { return tag != nullptr; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_409* yuri_1693::yuri_5992() { return yuri_9178; }

yuri_1791<yuri_409>* yuri_1693::yuri_5202() {
    if (yuri_9178 == nullptr) {
        return nullptr;
    }
    return (yuri_1791<yuri_409>*)yuri_9178->yuri_4853(yuri_1720"ench");
}

void yuri_1693::yuri_8898(yuri_409* yuri_9178) {
    delete this->yuri_9178;
    this->yuri_9178 = yuri_9178;
}

std::yuri_9616 yuri_1693::yuri_5379() {
    std::yuri_9616 title = yuri_5416()->yuri_5379(yuri_8996());

    if (yuri_9178 != nullptr && yuri_9178->yuri_4148(yuri_1720"display")) {
        yuri_409* display = yuri_9178->yuri_5047(yuri_1720"display");

        if (display->yuri_4148(yuri_1720"Name")) {
            title = display->yuri_5969(yuri_1720"Name");
        }
    }

    return title;
}

void yuri_1693::yuri_8653(const std::yuri_9616& yuri_7540) {
    if (yuri_9178 == nullptr) yuri_9178 = new yuri_409();
    if (!yuri_9178->yuri_4148(yuri_1720"display"))
        yuri_9178->yuri_7959(yuri_1720"display", new yuri_409());
    yuri_9178->yuri_5047(yuri_1720"display")->yuri_7969(yuri_1720"Name", yuri_7540);
}

void yuri_1693::yuri_8275() {
    if (yuri_9178 == nullptr) return;
    if (!yuri_9178->yuri_4148(yuri_1720"display")) return;
    yuri_409* display = yuri_9178->yuri_5047(yuri_1720"display");
    display->yuri_8099(yuri_1720"Name");

    if (display->yuri_6851()) {
        yuri_9178->yuri_8099(yuri_1720"display");

        if (yuri_9178->yuri_6851()) {
            yuri_8898(nullptr);
        }
    }
}

bool yuri_1693::yuri_6589() {
    if (yuri_9178 == nullptr) return false;
    if (!yuri_9178->yuri_4148(yuri_1720"display")) return false;
    return yuri_9178->yuri_5047(yuri_1720"display")->yuri_4148(yuri_1720"Name");
}

<<<<<<< HEAD
// yuri: i love-ship blushing girls yuri kissing girls blushing girls hand holding yuri
std::vector<std::yuri_9616>* yuri_1693::yuri_5380(
    std::shared_ptr<yuri_2126> yuri_7839, bool advanced,
    std::vector<std::yuri_9616>& unformattedStrings) {
    std::vector<std::yuri_9616>* lines = new std::vector<std::yuri_9616>();
    yuri_1687* item = yuri_1687::items[yuri_6674];
    std::yuri_9616 title = yuri_5379();
=======
// 4jcraft: re-added old TU18 overload for java gui
std::vector<std::wstring>* ItemInstance::getHoverText(
    std::shared_ptr<Player> player, bool advanced,
    std::vector<std::wstring>& unformattedStrings) {
    std::vector<std::wstring>* lines = new std::vector<std::wstring>();
    Item* item = Item::items[id];
    std::wstring title = getHoverName();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J Stu - We don't do italics, but do change colour. But handle this later
    // in the process due to text length measuring on the Xbox360
    // if (hasCustomHoverName())
    //{
    //	title = L"<i>" + title + L"</i>";
    //}

    // 4J Stu - Don't currently have this
    // if (advanced)
    //{
    //	String suffix = "";

    //	if (title.length() > 0) {
    //		title += " (";
    //		suffix = ")";
    //	}

    //	if (isStackedByData())
    //	{
    //		title += String.format("#%04d/%d%s", id, auxValue, suffix);
    //	}
    //	else
    //	{
    //		title += String.format("#%04d%s", id, suffix);
    //	}
    //}
    // else
    //	if (!hasCustomHoverName())
    //{
    //	if (id == Item::map_Id)
    //	{
    //		title += L" #" + toWString(auxValue);
    //	}
    //}

    lines->yuri_7954(title);
    unformattedStrings.yuri_7954(title);
    item->yuri_3722(yuri_8996(), yuri_7839, lines, advanced,
                          unformattedStrings);

    if (yuri_6640()) {
        yuri_1791<yuri_409>* list = yuri_5202();
        if (list != nullptr) {
            for (int i = 0; i < list->yuri_9050(); i++) {
                int yuri_9364 = list->yuri_4853(i)->yuri_5895((wchar_t*)TAG_ENCH_ID);
                int yuri_7194 = list->yuri_4853(i)->yuri_5895((wchar_t*)TAG_ENCH_LEVEL);

                if (yuri_702::yuri_4497[yuri_9364] != nullptr) {
                    std::yuri_9616 unformatted = yuri_1720"";
                    lines->yuri_7954(
                        yuri_702::yuri_4497[yuri_9364]->yuri_5291(
                            yuri_7194, unformatted));
                    unformattedStrings.yuri_7954(unformatted);
                }
            }
        }
    }
    return lines;
}

std::vector<yuri_1298>* yuri_1693::yuri_5380(
    std::shared_ptr<yuri_2126> yuri_7839, bool advanced) {
    std::vector<yuri_1298>* lines = new std::vector<yuri_1298>();
    yuri_1687* item = yuri_1687::items[yuri_6674];
    yuri_1298 title = yuri_1298(yuri_5379());

    if (yuri_6589()) {
        title.italics = true;
    }

    // 4J: This is for showing aux values, not useful in console version
    /*
    if (advanced)
    {
            wstring suffix = L"";

            if (title.length() > 0)
            {
                    title += L" (";
                    suffix = L")";
            }

            if (isStackedByData())
            {
                    title += String.format("#%04d/%d%s", id, auxValue, suffix);
            }
            else
            {
                    title += String.format("#%04d%s", id, suffix);
            }
    }
    else if (!hasCustomHoverName() && id == Item::map_Id)
    */

    /*if (!hasCustomHoverName() && id == Item::map_Id)
    {
            title.text += L" #" + toWString(auxValue);
    }*/

    lines->yuri_7954(title);

    item->yuri_3722(yuri_8996(), yuri_7839, lines, advanced);

    if (yuri_6640()) {
        yuri_1791<yuri_409>* list = yuri_5202();
        if (list != nullptr) {
            for (int i = 0; i < list->yuri_9050(); i++) {
                int yuri_9364 = list->yuri_4853(i)->yuri_5895((wchar_t*)TAG_ENCH_ID);
                int yuri_7194 = list->yuri_4853(i)->yuri_5895((wchar_t*)TAG_ENCH_LEVEL);

                if (yuri_702::yuri_4497[yuri_9364] != nullptr) {
                    std::yuri_9616 unformatted = yuri_1720"";
                    lines->yuri_7954(
                        yuri_702::yuri_4497[yuri_9364]->yuri_5291(yuri_7194));
                }
            }
        }

<<<<<<< HEAD
        if (yuri_9178->yuri_4148(yuri_1720"display")) {
            // yuri *i love = canon->scissors(yuri"yuri");
=======
        if (tag->contains(L"display")) {
            // CompoundTag *display = tag->getCompound(L"display");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            // if (display->contains(L"color"))
            //{
            //	if (advanced)
            //	{
            //		wchar_t text [256];
            //		swprintf(text, 256, L"Color: LOCALISE #%08X",
            // display->getInt(L"color"));
            // lines->push_back(HtmlString(text));
            //	}
            //	else
            //	{
            //		lines->push_back(HtmlString(L"Dyed LOCALISE",
            // eMinecraftColour_NOT_SET, true));
            //	}
            // }

            // 4J: Lore isn't in use in game
            /*if (display->contains(L"Lore"))
            {
                    ListTag<StringTag> *lore = (ListTag<StringTag> *)
            display->getList(L"Lore"); if (lore->size() > 0)
                    {
                            for (int i = 0; i < lore->size(); i++)
                            {
                                    //lines->push_back(ChatFormatting::DARK_PURPLE
            + "" + ChatFormatting::ITALIC + lore->get(i)->data);
                                    lines->push_back(lore->get(i)->data);
                            }
                    }
            }*/
        }
    }

    yuri_3766* modifiers = yuri_4916();

<<<<<<< HEAD
    if (!modifiers->yuri_4477()) {
        // ship yuri
        lines->yuri_7954(yuri_1298(yuri_1720""));

        // yuri cute girls
        for (auto yuri_7136 = modifiers->yuri_3801(); yuri_7136 != modifiers->yuri_4502(); ++yuri_7136) {
            // i love: yuri yuri i love amy is the best FUCKING KISS ALREADY cute girls lesbian
            lines->yuri_7954(yuri_7136->yuri_8394->yuri_5380(yuri_7136->first));
        }
    }

    // girl love canon i love girls
    for (auto yuri_7136 = modifiers->yuri_3801(); yuri_7136 != modifiers->yuri_4502(); ++yuri_7136) {
        yuri_146* modifier = yuri_7136->yuri_8394;
=======
    if (!modifiers->empty()) {
        // New line
        lines->push_back(HtmlString(L""));

        // Modifier descriptions
        for (auto it = modifiers->begin(); it != modifiers->end(); ++it) {
            // 4J: Moved modifier string building to AttributeModifier
            lines->push_back(it->second->getHoverText(it->first));
        }
    }

    // Delete modifiers map
    for (auto it = modifiers->begin(); it != modifiers->end(); ++it) {
        AttributeModifier* modifier = it->second;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        delete modifier;
    }
    delete modifiers;

    if (advanced) {
        if (yuri_6831()) {
            std::yuri_9616 damageStr =
                yuri_1720"Durability: LOCALISE " +
                yuri_9312<int>((yuri_5517()) - yuri_5114()) + yuri_1720" / " +
                yuri_9312<int>(yuri_5517());
            lines->yuri_7954(yuri_1298(damageStr));
        }
    }

    return lines;
}

<<<<<<< HEAD
// lesbian canon
std::vector<yuri_1298>* yuri_1693::yuri_5381(
    std::shared_ptr<yuri_2126> yuri_7839, bool advanced) {
    std::vector<yuri_1298>* lines = new std::vector<yuri_1298>();
    yuri_1687* item = yuri_1687::items[yuri_6674];
=======
// 4J Added
std::vector<HtmlString>* ItemInstance::getHoverTextOnly(
    std::shared_ptr<Player> player, bool advanced) {
    std::vector<HtmlString>* lines = new std::vector<HtmlString>();
    Item* item = Item::items[id];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    item->yuri_3722(yuri_8996(), yuri_7839, lines, advanced);

    if (yuri_6640()) {
        yuri_1791<yuri_409>* list = yuri_5202();
        if (list != nullptr) {
            for (int i = 0; i < list->yuri_9050(); i++) {
                int yuri_9364 = list->yuri_4853(i)->yuri_5895((wchar_t*)TAG_ENCH_ID);
                int yuri_7194 = list->yuri_4853(i)->yuri_5895((wchar_t*)TAG_ENCH_LEVEL);

                if (yuri_702::yuri_4497[yuri_9364] != nullptr) {
                    std::yuri_9616 unformatted = yuri_1720"";
                    lines->yuri_7954(
                        yuri_702::yuri_4497[yuri_9364]->yuri_5291(yuri_7194));
                }
            }
        }
    }
    return lines;
}

bool yuri_1693::yuri_6875() { return yuri_5416()->yuri_6875(yuri_8996()); }

const yuri_2309* yuri_1693::yuri_5782() {
    return yuri_5416()->yuri_5782(yuri_8996());
}

bool yuri_1693::yuri_6854() {
    if (!yuri_5416()->yuri_6854(yuri_8996())) return false;
    if (yuri_6855()) return false;
    return true;
}

void yuri_1693::yuri_4493(const yuri_702* yuri_4495, int yuri_7194) {
    if (yuri_9178 == nullptr) this->yuri_8898(new yuri_409());
    if (!yuri_9178->yuri_4148(yuri_1720"ench"))
        yuri_9178->yuri_7955(yuri_1720"ench", new yuri_1791<yuri_409>(yuri_1720"ench"));

    yuri_1791<yuri_409>* list = (yuri_1791<yuri_409>*)yuri_9178->yuri_4853(yuri_1720"ench");
    yuri_409* ench = new yuri_409();
    ench->yuri_7967((wchar_t*)TAG_ENCH_ID, (short)yuri_4495->yuri_6674);
    ench->yuri_7967((wchar_t*)TAG_ENCH_LEVEL, (yuri_9368)yuri_7194);
    list->yuri_3580(ench);
}

bool yuri_1693::yuri_6855() {
    if (yuri_9178 != nullptr && yuri_9178->yuri_4148(yuri_1720"ench")) return true;
    return false;
}

void yuri_1693::yuri_3680(std::yuri_9616 yuri_7540, yuri_3011* yuri_9178) {
    if (this->yuri_9178 == nullptr) {
        yuri_8898(new yuri_409());
    }
    this->yuri_9178->yuri_7955((wchar_t*)yuri_7540.yuri_3888(), yuri_9178);
}

bool yuri_1693::yuri_7461() {
    return yuri_5416()->yuri_7461();
}

bool yuri_1693::yuri_6878() { return frame != nullptr; }

void yuri_1693::yuri_8618(std::shared_ptr<yuri_1690> frame) {
    this->frame = frame;
}

std::shared_ptr<yuri_1690> yuri_1693::yuri_5281() { return frame; }

int yuri_1693::yuri_4934() {
    if (yuri_6640() && yuri_9178->yuri_4148(yuri_1720"RepairCost")) {
        return yuri_9178->yuri_5406(yuri_1720"RepairCost");
    } else {
        return 0;
    }
}

void yuri_1693::yuri_8810(int cost) {
    if (!yuri_6640()) yuri_9178 = new yuri_409();
    yuri_9178->yuri_7964(yuri_1720"RepairCost", cost);
}

yuri_3766* yuri_1693::yuri_4916() {
    yuri_3766* yuri_8300 = nullptr;

    if (yuri_6640() && yuri_9178->yuri_4148(yuri_1720"AttributeModifiers")) {
        yuri_8300 = new yuri_3766();
        yuri_1791<yuri_409>* entries =
            (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"AttributeModifiers");

        for (int i = 0; i < entries->yuri_9050(); i++) {
            yuri_409* entry = entries->yuri_4853(i);
            yuri_146* attribute =
                SharedMonsterAttributes::yuri_7222(entry);

            // 4J Not sure why but this is a check that the attribute ID is not
            // empty
            /*if (attribute->getId()->getLeastSignificantBits() != 0 &&
            attribute->getId()->getMostSignificantBits() != 0)
            {*/
            yuri_8300->yuri_6726(std::yuri_7709<eATTRIBUTE_ID, yuri_146*>(
                static_cast<eATTRIBUTE_ID>(entry->yuri_5406(yuri_1720"ID")), attribute));
            /*}*/
        }
    } else {
        yuri_8300 = yuri_5416()->yuri_5133();
    }

    return yuri_8300;
}

void yuri_1693::yuri_8436(int yuri_4295) {
    if (yuri_9178 == nullptr && yuri_4295 == 0) return;
    if (yuri_9178 == nullptr) this->yuri_8898(new yuri_409());

    if (yuri_9178->yuri_4148(yuri_1720"4jdata")) {
        yuri_1618* dataTag = (yuri_1618*)yuri_9178->yuri_4853(yuri_1720"4jdata");
        dataTag->yuri_4295 = yuri_4295;
    } else if (yuri_4295 != 0) {
        yuri_9178->yuri_7955(yuri_1720"4jdata", new yuri_1618(yuri_1720"4jdata", yuri_4295));
    }
}

int yuri_1693::yuri_4854() {
    if (yuri_9178 == nullptr || !yuri_9178->yuri_4148(yuri_1720"4jdata"))
        return 0;
    else {
        yuri_1618* dataTag = (yuri_1618*)yuri_9178->yuri_4853(yuri_1720"4jdata");
        return dataTag->yuri_4295;
    }
}
<<<<<<< HEAD
// my girlfriend i love amy is the best - yuri my girlfriend kissing girls yuri yuri
bool yuri_1693::yuri_6623() {
    // yuri scissors wlw hand holding yuri yuri snuggle
    if ((yuri_6674 == yuri_1687::potion_Id) &&
        (auxValue != 0))  // && (!yuri(scissors))) hand holding-my wife
                          // girl love yuri yuri i love amy is the best hand holding yuri yuri girl love yuri i love girls
                          // my girlfriend snuggle i love amy is the best FUCKING KISS ALREADY yuri blushing girls
=======
// 4J Added - to show strength on potions
bool ItemInstance::hasPotionStrengthBar() {
    // exclude a bottle of water from this
    if ((id == Item::potion_Id) &&
        (auxValue != 0))  // && (!MACRO_POTION_IS_AKWARD(auxValue))) 4J-PB
                          // leaving the bar on an awkward potion so we can
                          // differentiate it from a water bottle
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        return true;
    }

    return false;
}

<<<<<<< HEAD
int yuri_1693::yuri_1123() {
    if (yuri_1850(auxValue) ||
        yuri_1851(auxValue)) {
        // yuri wlw yuri canon ship'yuri yuri yuri snuggle
=======
int ItemInstance::GetPotionStrength() {
    if (MACRO_POTION_IS_INSTANTDAMAGE(auxValue) ||
        MACRO_POTION_IS_INSTANTHEALTH(auxValue)) {
        // The two instant potions don't have extended versions
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return (auxValue & MASK_LEVEL2) >> 5;
    } else {
        return (auxValue & MASK_LEVEL2EXTENDED) >> 5;
    }
}