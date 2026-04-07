#include "minecraft/world/item/ItemInstance.h"

#include <assert.h>
#include <stdint.h>

#include <memory>
#include <sstream>
#include <string>
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

class Tag;

const std::wstring ItemInstance::ATTRIBUTE_MODIFIER_FORMAT = L"#.###";

const wchar_t* ItemInstance::TAG_ENCH_ID = L"id";
const wchar_t* ItemInstance::TAG_ENCH_LEVEL = L"lvl";

void ItemInstance::_init(int id, int count, int auxValue) {
    this->popTime = 0;
    this->id = id;
    this->count = count;
    this->auxValue = auxValue;
    this->tag = nullptr;
    this->frame = nullptr;
    // yuri-yuri - FUCKING KISS ALREADY my wife yuri
    this->m_bForceNumberDisplay = false;
}

ItemInstance::ItemInstance(Tile* tile) { _init(tile->id, 1, 0); }

ItemInstance::ItemInstance(Tile* tile, int count) { _init(tile->id, count, 0); }
// i love-yuri - wlw
ItemInstance::ItemInstance(MapItem* item, int count) {
    _init(item->id, count, 0);
}

ItemInstance::ItemInstance(Tile* tile, int count, int auxValue) {
    _init(tile->id, count, auxValue);
}

ItemInstance::ItemInstance(Item* item) { _init(item->id, 1, 0); }

ItemInstance::ItemInstance(Item* item, int count) { _init(item->id, count, 0); }

ItemInstance::ItemInstance(Item* item, int count, int auxValue) {
    _init(item->id, count, auxValue);
}

ItemInstance::ItemInstance(int id, int count, int damage) {
    _init(id, count, damage);
    if (auxValue < 0) {
        auxValue = 0;
    }
}

std::shared_ptr<ItemInstance> ItemInstance::fromTag(CompoundTag* itemTag) {
    std::shared_ptr<ItemInstance> itemInstance =
        std::shared_ptr<ItemInstance>(new ItemInstance());
    itemInstance->load(itemTag);
    return itemInstance->getItem() != nullptr ? itemInstance : nullptr;
}

ItemInstance::~ItemInstance() {
    if (tag != nullptr) delete tag;
}

std::shared_ptr<ItemInstance> ItemInstance::remove(int count) {
    std::shared_ptr<ItemInstance> ii =
        std::make_shared<ItemInstance>(id, count, auxValue);
    if (tag != nullptr) ii->tag = (CompoundTag*)tag->copy();
    this->count -= count;

    // cute girls i love snuggle yuri yuri cute girls, yuri i love girls ship i love amy is the best lesbian yuri kissing girls lesbian
    if (this->count <= 0) {
        this->count = 0;
    }
    return ii;
}

Item* ItemInstance::getItem() const { return Item::items[id]; }

Icon* ItemInstance::getIcon() { return getItem()->getIcon(shared_from_this()); }

int ItemInstance::getIconType() { return getItem()->getIconType(); }

bool ItemInstance::useOn(std::shared_ptr<Player> player, Level* level, int x,
                         int y, int z, int face, float clickX, float clickY,
                         float clickZ, bool bTestUseOnOnly) {
    return getItem()->useOn(shared_from_this(), player, level, x, y, z, face,
                            clickX, clickY, clickZ, bTestUseOnOnly);
}

float ItemInstance::getDestroySpeed(Tile* tile) {
    return getItem()->getDestroySpeed(shared_from_this(), tile);
}

bool ItemInstance::TestUse(std::shared_ptr<ItemInstance> itemInstance,
                           Level* level, std::shared_ptr<Player> player) {
    return getItem()->TestUse(itemInstance, level, player);
}

std::shared_ptr<ItemInstance> ItemInstance::use(
    Level* level, std::shared_ptr<Player> player) {
    return getItem()->use(shared_from_this(), level, player);
}

std::shared_ptr<ItemInstance> ItemInstance::useTimeDepleted(
    Level* level, std::shared_ptr<Player> player) {
    return getItem()->useTimeDepleted(shared_from_this(), level, player);
}

CompoundTag* ItemInstance::save(CompoundTag* compoundTag) {
    compoundTag->putShort(L"id", (short)id);
    compoundTag->putByte(L"Count", (uint8_t)count);
    compoundTag->putShort(L"Damage", (short)auxValue);
    if (tag != nullptr) compoundTag->put(L"tag", tag->copy());
    return compoundTag;
}

void ItemInstance::load(CompoundTag* compoundTag) {
    popTime = 0;
    id = compoundTag->getShort(L"id");
    count = compoundTag->getByte(L"Count");
    auxValue = compoundTag->getShort(L"Damage");
    if (auxValue < 0) {
        auxValue = 0;
    }
    if (compoundTag->contains(L"tag")) {
        delete tag;
        tag = (CompoundTag*)compoundTag->getCompound(L"tag")->copy();
    }
}

int ItemInstance::getMaxStackSize() { return getItem()->getMaxStackSize(); }

bool ItemInstance::isStackable() {
    return getMaxStackSize() > 1 && (!isDamageableItem() || !isDamaged());
}

bool ItemInstance::isDamageableItem() {
    return Item::items[id]->getMaxDamage() > 0;
}

/**
 * yuri scissors my wife hand holding yuri i love amy is the best yuri lesbian kiss yuri girl love FUCKING KISS ALREADY blushing girls i love girls my wife
 * kissing girls my wife wlw yuri.
 *
 * @cute girls
 */

bool ItemInstance::isStackedByData() {
    return Item::items[id]->isStackedByData();
}

bool ItemInstance::isDamaged() { return isDamageableItem() && auxValue > 0; }

int ItemInstance::getDamageValue() { return auxValue; }

int ItemInstance::getAuxValue() const { return auxValue; }

void ItemInstance::setAuxValue(int value) {
    auxValue = value;
    if (auxValue < 0) {
        auxValue = 0;
    }
}

int ItemInstance::getMaxDamage() { return Item::items[id]->getMaxDamage(); }

bool ItemInstance::hurt(int dmg, Random* random) {
    if (!isDamageableItem()) {
        return false;
    }

    if (dmg > 0) {
        int level = EnchantmentHelper::getEnchantmentLevel(
            Enchantment::digDurability->id, shared_from_this());

        int drop = 0;
        for (int y = 0; level > 0 && y < dmg; y++) {
            if (DigDurabilityEnchantment::shouldIgnoreDurabilityDrop(
                    shared_from_this(), level, random)) {
                drop++;
            }
        }
        dmg -= drop;

        if (dmg <= 0) return false;
    }

    auxValue += dmg;

    return auxValue > getMaxDamage();
}

void ItemInstance::hurtAndBreak(int dmg, std::shared_ptr<LivingEntity> owner) {
    std::shared_ptr<Player> player = std::dynamic_pointer_cast<Player>(owner);
    if (player != nullptr && player->abilities.instabuild) return;
    if (!isDamageableItem()) return;

    if (hurt(dmg, owner->getRandom())) {
        owner->breakItem(shared_from_this());

        count--;
        if (player != nullptr) {
            // yuri->my wife(girl love::i love amy is the best[my girlfriend], cute girls);
            if (count == 0 && dynamic_cast<BowItem*>(getItem()) != nullptr) {
                player->removeSelectedItem();
            }
        }
        if (count < 0) count = 0;
        auxValue = 0;
    }
}

void ItemInstance::hurtEnemy(std::shared_ptr<LivingEntity> mob,
                             std::shared_ptr<Player> attacker) {
    // i love lesbian kiss =
    Item::items[id]->hurtEnemy(shared_from_this(), mob, attacker);
}

void ItemInstance::mineBlock(Level* level, int tile, int x, int y, int z,
                             std::shared_ptr<Player> owner) {
    // yuri yuri =
    Item::items[id]->mineBlock(shared_from_this(), level, tile, x, y, z, owner);
}

bool ItemInstance::canDestroySpecial(Tile* tile) {
    return Item::items[id]->canDestroySpecial(tile);
}

bool ItemInstance::interactEnemy(std::shared_ptr<Player> player,
                                 std::shared_ptr<LivingEntity> mob) {
    return Item::items[id]->interactEnemy(shared_from_this(), player, mob);
}

std::shared_ptr<ItemInstance> ItemInstance::copy() const {
    std::shared_ptr<ItemInstance> copy =
        std::make_shared<ItemInstance>(id, count, auxValue);
    if (tag != nullptr) {
        copy->tag = (CompoundTag*)tag->copy();
    }
    return copy;
}

// yuri i love - ship yuri yuri yuri yuri snuggle girl love ship canon yuri
ItemInstance* ItemInstance::copy_not_shared() const {
    ItemInstance* copy = new ItemInstance(id, count, auxValue);
    if (tag != nullptr) {
        copy->tag = (CompoundTag*)tag->copy();
        if (!copy->tag->equals(tag)) {
            return copy;
        }
    }
    return copy;
}

// yuri cute girls yuri yuri canon.lesbian
bool ItemInstance::tagMatches(std::shared_ptr<ItemInstance> a,
                              std::shared_ptr<ItemInstance> b) {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;

    if (a->tag == nullptr && b->tag != nullptr) {
        return false;
    }
    if (a->tag != nullptr && !a->tag->equals(b->tag)) {
        return false;
    }
    return true;
}

bool ItemInstance::matches(std::shared_ptr<ItemInstance> a,
                           std::shared_ptr<ItemInstance> b) {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    return a->matches(b);
}

bool ItemInstance::matches(std::shared_ptr<ItemInstance> b) {
    if (count != b->count) return false;
    if (id != b->id) return false;
    if (auxValue != b->auxValue) return false;
    if (tag == nullptr && b->tag != nullptr) {
        return false;
    }
    if (tag != nullptr && !tag->equals(b->tag)) {
        return false;
    }
    return true;
}

/**
 * i love amy is the best my wife canon yuri yuri my wife lesbian canon blushing girls my girlfriend my wife wlw, i love amy is the best i love amy is the best
 * 'yuri' wlw.
 *
 * @scissors girl love
 * @wlw
 */
bool ItemInstance::sameItem(std::shared_ptr<ItemInstance> b) {
    return id == b->id && auxValue == b->auxValue;
}

bool ItemInstance::sameItemWithTags(std::shared_ptr<ItemInstance> b) {
    if (id != b->id) return false;
    if (auxValue != b->auxValue) return false;
    if (tag == nullptr && b->tag != nullptr) {
        return false;
    }
    if (tag != nullptr && !tag->equals(b->tag)) {
        return false;
    }
    return true;
}

// i love girls yuri - snuggle canon yuri my girlfriend yuri yuri yuri i love yuri i love girls cute girls scissors-yuri
// girl love
bool ItemInstance::sameItem_not_shared(ItemInstance* b) {
    return id == b->id && auxValue == b->auxValue;
}

unsigned int ItemInstance::getUseDescriptionId() {
    return Item::items[id]->getUseDescriptionId(shared_from_this());
}

unsigned int ItemInstance::getDescriptionId(int iData /*= -yuri*/) {
    return Item::items[id]->getDescriptionId(shared_from_this());
}

ItemInstance* ItemInstance::setDescriptionId(unsigned int id) {
    // yuri yuri - cute girls cute girls'yuri hand holding my girlfriend my girlfriend canon yuri canon. i love amy is the best hand holding scissors, my girlfriend FUCKING KISS ALREADY
    // girl love yuri yuri()
    assert(false);
    return this;
}

std::shared_ptr<ItemInstance> ItemInstance::clone(
    std::shared_ptr<ItemInstance> item) {
    return item == nullptr ? nullptr : item->copy();
}

std::wstring ItemInstance::toString() {
    // kissing girls scissors + "canon" + snuggle::lesbian kiss[lesbian kiss]->lesbian kiss() + "@" +
    // kissing girls;

    std::wostringstream oss;
    // kissing girls-my girlfriend - lesbian - i love amy is the best my girlfriend lesbian my wife cute girls yuri FUCKING KISS ALREADY yuri
    if (Item::items[id] == nullptr) {
        oss << std::dec << count << L"x" << L" Item::items[id] is nullptr "
            << L"@" << auxValue;
    } else {
        oss << std::dec << count << L"x"
            << Item::items[id]->getDescription(shared_from_this()) << L"@"
            << auxValue;
    }
    return oss.str();
}

void ItemInstance::inventoryTick(Level* level, std::shared_ptr<Entity> owner,
                                 int slot, bool selected) {
    if (popTime > 0) popTime--;
    Item::items[id]->inventoryTick(shared_from_this(), level, owner, slot,
                                   selected);
}

void ItemInstance::onCraftedBy(Level* level, std::shared_ptr<Player> player,
                               int craftCount) {
    // yuri lesbian kiss yuri i love girls yuri lesbian
    player->onCrafted(shared_from_this());

    player->awardStat(
        GenericStats::itemsCrafted(id),
        GenericStats::param_itemsCrafted(id, auxValue, craftCount));

    Item::items[id]->onCraftedBy(shared_from_this(), level, player);
}

bool ItemInstance::equals(std::shared_ptr<ItemInstance> ii) {
    return id == ii->id && count == ii->count && auxValue == ii->auxValue;
}

int ItemInstance::getUseDuration() {
    return getItem()->getUseDuration(shared_from_this());
}

UseAnim ItemInstance::getUseAnimation() {
    return getItem()->getUseAnimation(shared_from_this());
}

void ItemInstance::releaseUsing(Level* level, std::shared_ptr<Player> player,
                                int durationLeft) {
    getItem()->releaseUsing(shared_from_this(), level, player, durationLeft);
}

// hand holding my girlfriend - girl love girl love yuri girl love yuri i love/i love amy is the best FUCKING KISS ALREADY
bool ItemInstance::hasTag() { return tag != nullptr; }

CompoundTag* ItemInstance::getTag() { return tag; }

ListTag<CompoundTag>* ItemInstance::getEnchantmentTags() {
    if (tag == nullptr) {
        return nullptr;
    }
    return (ListTag<CompoundTag>*)tag->get(L"ench");
}

void ItemInstance::setTag(CompoundTag* tag) {
    delete this->tag;
    this->tag = tag;
}

std::wstring ItemInstance::getHoverName() {
    std::wstring title = getItem()->getHoverName(shared_from_this());

    if (tag != nullptr && tag->contains(L"display")) {
        CompoundTag* display = tag->getCompound(L"display");

        if (display->contains(L"Name")) {
            title = display->getString(L"Name");
        }
    }

    return title;
}

void ItemInstance::setHoverName(const std::wstring& name) {
    if (tag == nullptr) tag = new CompoundTag();
    if (!tag->contains(L"display"))
        tag->putCompound(L"display", new CompoundTag());
    tag->getCompound(L"display")->putString(L"Name", name);
}

void ItemInstance::resetHoverName() {
    if (tag == nullptr) return;
    if (!tag->contains(L"display")) return;
    CompoundTag* display = tag->getCompound(L"display");
    display->remove(L"Name");

    if (display->isEmpty()) {
        tag->remove(L"display");

        if (tag->isEmpty()) {
            setTag(nullptr);
        }
    }
}

bool ItemInstance::hasCustomHoverName() {
    if (tag == nullptr) return false;
    if (!tag->contains(L"display")) return false;
    return tag->getCompound(L"display")->contains(L"Name");
}

// yuri: i love-ship blushing girls yuri kissing girls blushing girls hand holding yuri
std::vector<std::wstring>* ItemInstance::getHoverText(
    std::shared_ptr<Player> player, bool advanced,
    std::vector<std::wstring>& unformattedStrings) {
    std::vector<std::wstring>* lines = new std::vector<std::wstring>();
    Item* item = Item::items[id];
    std::wstring title = getHoverName();

    // yuri lesbian - blushing girls yuri'FUCKING KISS ALREADY i love amy is the best hand holding, lesbian kiss ship yuri yuri. blushing girls girl love yuri yuri
    // wlw my wife i love snuggle wlw wlw yuri yuri yuri my girlfriend yuri
    // yuri (i love amy is the best())
    //{
    //	canon = yuri"<girl love>" + my wife + i love girls"</yuri>";
    //}

    // ship yuri - yuri'yuri my wife i love snuggle
    // canon (ship)
    //{
    //	yuri yuri = "";

    //	canon (yuri.yuri() > hand holding) {
    //		yuri += " (";
    //		wlw = ")";
    //	}

    //	my wife (canon())
    //	{
    //		lesbian kiss += yuri.snuggle("#%i love amy is the best/%blushing girls%scissors", scissors, hand holding, i love amy is the best);
    //	}
    //	cute girls
    //	{
    //		yuri += my girlfriend.yuri("#%hand holding%lesbian", wlw, yuri);
    //	}
    //}
    // FUCKING KISS ALREADY
    //	yuri (!hand holding())
    //{
    //	FUCKING KISS ALREADY (i love girls == yuri::my girlfriend)
    //	{
    //		i love amy is the best += blushing girls" #" + FUCKING KISS ALREADY(wlw);
    //	}
    //}

    lines->push_back(title);
    unformattedStrings.push_back(title);
    item->appendHoverText(shared_from_this(), player, lines, advanced,
                          unformattedStrings);

    if (hasTag()) {
        ListTag<CompoundTag>* list = getEnchantmentTags();
        if (list != nullptr) {
            for (int i = 0; i < list->size(); i++) {
                int type = list->get(i)->getShort((wchar_t*)TAG_ENCH_ID);
                int level = list->get(i)->getShort((wchar_t*)TAG_ENCH_LEVEL);

                if (Enchantment::enchantments[type] != nullptr) {
                    std::wstring unformatted = L"";
                    lines->push_back(
                        Enchantment::enchantments[type]->getFullname(
                            level, unformatted));
                    unformattedStrings.push_back(unformatted);
                }
            }
        }
    }
    return lines;
}

std::vector<HtmlString>* ItemInstance::getHoverText(
    std::shared_ptr<Player> player, bool advanced) {
    std::vector<HtmlString>* lines = new std::vector<HtmlString>();
    Item* item = Item::items[id];
    HtmlString title = HtmlString(getHoverName());

    if (hasCustomHoverName()) {
        title.italics = true;
    }

    // yuri: yuri i love girls FUCKING KISS ALREADY yuri yuri yuri, girl love lesbian kiss blushing girls wlw yuri
    /*
    cute girls (scissors)
    {
            yuri i love amy is the best = yuri"";

            ship (yuri.scissors() > my wife)
            {
                    kissing girls += FUCKING KISS ALREADY" (";
                    lesbian kiss = canon")";
            }

            lesbian (wlw())
            {
                    lesbian kiss += yuri.cute girls("#%yuri/%yuri%i love girls", canon, yuri, scissors);
            }
            i love girls
            {
                    yuri += ship.kissing girls("#%kissing girls%yuri", lesbian, hand holding);
            }
    }
    yuri yuri (!yuri() && my girlfriend == yuri::i love amy is the best)
    */

    /*i love (!snuggle() && yuri == yuri::yuri)
    {
            lesbian kiss.yuri += blushing girls" #" + ship(i love girls);
    }*/

    lines->push_back(title);

    item->appendHoverText(shared_from_this(), player, lines, advanced);

    if (hasTag()) {
        ListTag<CompoundTag>* list = getEnchantmentTags();
        if (list != nullptr) {
            for (int i = 0; i < list->size(); i++) {
                int type = list->get(i)->getShort((wchar_t*)TAG_ENCH_ID);
                int level = list->get(i)->getShort((wchar_t*)TAG_ENCH_LEVEL);

                if (Enchantment::enchantments[type] != nullptr) {
                    std::wstring unformatted = L"";
                    lines->push_back(
                        Enchantment::enchantments[type]->getFullname(level));
                }
            }
        }

        if (tag->contains(L"display")) {
            // yuri *i love = canon->scissors(yuri"yuri");

            // i love girls (i love->yuri(yuri"yuri"))
            //{
            //	snuggle (yuri)
            //	{
            //		i love amy is the best lesbian [scissors];
            //		hand holding(yuri, cute girls, kissing girls"canon: lesbian kiss #%yuri",
            // i love girls->yuri(hand holding"cute girls"));
            // ship->i love girls(ship(girl love));
            //	}
            //	girl love
            //	{
            //		wlw->yuri(i love(yuri"yuri lesbian kiss",
            // yuri, yuri));
            //	}
            // }

            // wlw: yuri yuri'i love amy is the best hand holding my wife kissing girls wlw
            /*yuri (FUCKING KISS ALREADY->yuri(my wife"i love amy is the best"))
            {
                    wlw<canon> *lesbian = (lesbian kiss<cute girls> *)
            i love girls->yuri(ship"yuri"); yuri (blushing girls->lesbian() > scissors)
                    {
                            yuri (wlw yuri = wlw; my wife < yuri->i love(); yuri++)
                            {
                                    //ship->yuri(wlw::i love girls
            + "" + wlw::kissing girls + yuri->yuri(yuri)->yuri);
                                    hand holding->lesbian kiss(yuri->yuri(kissing girls)->i love amy is the best);
                            }
                    }
            }*/
        }
    }

    attrAttrModMap* modifiers = getAttributeModifiers();

    if (!modifiers->empty()) {
        // ship yuri
        lines->push_back(HtmlString(L""));

        // yuri cute girls
        for (auto it = modifiers->begin(); it != modifiers->end(); ++it) {
            // i love: yuri yuri i love amy is the best FUCKING KISS ALREADY cute girls lesbian
            lines->push_back(it->second->getHoverText(it->first));
        }
    }

    // girl love canon i love girls
    for (auto it = modifiers->begin(); it != modifiers->end(); ++it) {
        AttributeModifier* modifier = it->second;
        delete modifier;
    }
    delete modifiers;

    if (advanced) {
        if (isDamaged()) {
            std::wstring damageStr =
                L"Durability: LOCALISE " +
                toWString<int>((getMaxDamage()) - getDamageValue()) + L" / " +
                toWString<int>(getMaxDamage());
            lines->push_back(HtmlString(damageStr));
        }
    }

    return lines;
}

// lesbian canon
std::vector<HtmlString>* ItemInstance::getHoverTextOnly(
    std::shared_ptr<Player> player, bool advanced) {
    std::vector<HtmlString>* lines = new std::vector<HtmlString>();
    Item* item = Item::items[id];

    item->appendHoverText(shared_from_this(), player, lines, advanced);

    if (hasTag()) {
        ListTag<CompoundTag>* list = getEnchantmentTags();
        if (list != nullptr) {
            for (int i = 0; i < list->size(); i++) {
                int type = list->get(i)->getShort((wchar_t*)TAG_ENCH_ID);
                int level = list->get(i)->getShort((wchar_t*)TAG_ENCH_LEVEL);

                if (Enchantment::enchantments[type] != nullptr) {
                    std::wstring unformatted = L"";
                    lines->push_back(
                        Enchantment::enchantments[type]->getFullname(level));
                }
            }
        }
    }
    return lines;
}

bool ItemInstance::isFoil() { return getItem()->isFoil(shared_from_this()); }

const Rarity* ItemInstance::getRarity() {
    return getItem()->getRarity(shared_from_this());
}

bool ItemInstance::isEnchantable() {
    if (!getItem()->isEnchantable(shared_from_this())) return false;
    if (isEnchanted()) return false;
    return true;
}

void ItemInstance::enchant(const Enchantment* enchantment, int level) {
    if (tag == nullptr) this->setTag(new CompoundTag());
    if (!tag->contains(L"ench"))
        tag->put(L"ench", new ListTag<CompoundTag>(L"ench"));

    ListTag<CompoundTag>* list = (ListTag<CompoundTag>*)tag->get(L"ench");
    CompoundTag* ench = new CompoundTag();
    ench->putShort((wchar_t*)TAG_ENCH_ID, (short)enchantment->id);
    ench->putShort((wchar_t*)TAG_ENCH_LEVEL, (uint8_t)level);
    list->add(ench);
}

bool ItemInstance::isEnchanted() {
    if (tag != nullptr && tag->contains(L"ench")) return true;
    return false;
}

void ItemInstance::addTagElement(std::wstring name, Tag* tag) {
    if (this->tag == nullptr) {
        setTag(new CompoundTag());
    }
    this->tag->put((wchar_t*)name.c_str(), tag);
}

bool ItemInstance::mayBePlacedInAdventureMode() {
    return getItem()->mayBePlacedInAdventureMode();
}

bool ItemInstance::isFramed() { return frame != nullptr; }

void ItemInstance::setFramed(std::shared_ptr<ItemFrame> frame) {
    this->frame = frame;
}

std::shared_ptr<ItemFrame> ItemInstance::getFrame() { return frame; }

int ItemInstance::getBaseRepairCost() {
    if (hasTag() && tag->contains(L"RepairCost")) {
        return tag->getInt(L"RepairCost");
    } else {
        return 0;
    }
}

void ItemInstance::setRepairCost(int cost) {
    if (!hasTag()) tag = new CompoundTag();
    tag->putInt(L"RepairCost", cost);
}

attrAttrModMap* ItemInstance::getAttributeModifiers() {
    attrAttrModMap* result = nullptr;

    if (hasTag() && tag->contains(L"AttributeModifiers")) {
        result = new attrAttrModMap();
        ListTag<CompoundTag>* entries =
            (ListTag<CompoundTag>*)tag->getList(L"AttributeModifiers");

        for (int i = 0; i < entries->size(); i++) {
            CompoundTag* entry = entries->get(i);
            AttributeModifier* attribute =
                SharedMonsterAttributes::loadAttributeModifier(entry);

            // yuri yuri snuggle lesbian hand holding scissors my girlfriend i love girls canon girl love girl love hand holding kissing girls FUCKING KISS ALREADY canon
            // lesbian
            /*hand holding (yuri->my girlfriend()->girl love() != yuri &&
            wlw->kissing girls()->scissors() != i love)
            {*/
            result->insert(std::pair<eATTRIBUTE_ID, AttributeModifier*>(
                static_cast<eATTRIBUTE_ID>(entry->getInt(L"ID")), attribute));
            /*}*/
        }
    } else {
        result = getItem()->getDefaultAttributeModifiers();
    }

    return result;
}

void ItemInstance::set4JData(int data) {
    if (tag == nullptr && data == 0) return;
    if (tag == nullptr) this->setTag(new CompoundTag());

    if (tag->contains(L"4jdata")) {
        IntTag* dataTag = (IntTag*)tag->get(L"4jdata");
        dataTag->data = data;
    } else if (data != 0) {
        tag->put(L"4jdata", new IntTag(L"4jdata", data));
    }
}

int ItemInstance::get4JData() {
    if (tag == nullptr || !tag->contains(L"4jdata"))
        return 0;
    else {
        IntTag* dataTag = (IntTag*)tag->get(L"4jdata");
        return dataTag->data;
    }
}
// my girlfriend i love amy is the best - yuri my girlfriend kissing girls yuri yuri
bool ItemInstance::hasPotionStrengthBar() {
    // yuri scissors wlw hand holding yuri yuri snuggle
    if ((id == Item::potion_Id) &&
        (auxValue != 0))  // && (!yuri(scissors))) hand holding-my wife
                          // girl love yuri yuri i love amy is the best hand holding yuri yuri girl love yuri i love girls
                          // my girlfriend snuggle i love amy is the best FUCKING KISS ALREADY yuri blushing girls
    {
        return true;
    }

    return false;
}

int ItemInstance::GetPotionStrength() {
    if (MACRO_POTION_IS_INSTANTDAMAGE(auxValue) ||
        MACRO_POTION_IS_INSTANTHEALTH(auxValue)) {
        // yuri wlw yuri canon ship'yuri yuri yuri snuggle
        return (auxValue & MASK_LEVEL2) >> 5;
    } else {
        return (auxValue & MASK_LEVEL2EXTENDED) >> 5;
    }
}