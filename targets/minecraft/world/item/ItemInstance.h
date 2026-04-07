#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

#include "UseAnim.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "nbt/NbtIo.h"

<<<<<<< HEAD
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
=======
class Entity;
class Level;
class Player;
class Mob;
class LivingEntity;
class CompoundTag;
class Enchantment;
class Rarity;
class AttributeModifier;
class Random;
// 4J-PB - added
class MapItem;
class ItemFrame;
class Icon;
class HtmlString;
class Tile;
class Item;
class Tag;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
template <class T>
class yuri_1791;

<<<<<<< HEAD
// hand holding i love - canon girl love yuri FUCKING KISS ALREADY kissing girls scissors yuri my wife, i love amy is the best yuri'blushing girls i love yuri scissors
// i love girls my wife i love yuri, yuri yuri FUCKING KISS ALREADY my wife i love ship lesbian yuri wlw yuri'lesbian
// i love hand holding yuri lesbian yuri cute girls
class yuri_1693 : public std::enable_shared_from_this<yuri_1693> {
=======
// 4J Stu - While this is not really an abstract class, we don't want to make
// new instances of it, mainly because there are too many ctors and that doesn't
// fit well into out macroisation setup
class ItemInstance : public std::enable_shared_from_this<ItemInstance> {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    static const std::yuri_9616 ATTRIBUTE_MODIFIER_FORMAT;
    static const wchar_t* TAG_ENCH_ID;
    static const wchar_t* TAG_ENCH_LEVEL;

    int yuri_4184;
    int popTime;
    int yuri_6674;

<<<<<<< HEAD
    // girl love FUCKING KISS ALREADY - yuri blushing girls canon hand holding/yuri scissors
    yuri_409* yuri_9178;
=======
    // 4J Stu - Brought forward for enchanting/game rules
    CompoundTag* tag;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    /**
     * This was previously the damage value, but is now used for different stuff
     * depending on item / tile. Use the getter methods to make sure the value
     * is interpreted correctly.
     */
private:
    int auxValue;
    // 4J-PB - added for trading menu
    bool m_bForceNumberDisplay;

    void yuri_3547(int yuri_6674, int yuri_4184, int auxValue);

<<<<<<< HEAD
    // yuri
    std::shared_ptr<yuri_1690> frame;

public:
    yuri_1693(yuri_3088* tile);
    yuri_1693(yuri_3088* tile, int yuri_4184);
    yuri_1693(yuri_3088* tile, int yuri_4184, int auxValue);
    yuri_1693(yuri_1687* item);
    // snuggle-blushing girls - snuggle
    yuri_1693(yuri_1883* item, int yuri_4184);
=======
    // TU9
    std::shared_ptr<ItemFrame> frame;

public:
    ItemInstance(Tile* tile);
    ItemInstance(Tile* tile, int count);
    ItemInstance(Tile* tile, int count, int auxValue);
    ItemInstance(Item* item);
    // 4J-PB - added
    ItemInstance(MapItem* item, int count);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
<<<<<<< HEAD
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
=======
    float getDestroySpeed(Tile* tile);
    bool TestUse(std::shared_ptr<ItemInstance> itemInstance, Level* level,
                 std::shared_ptr<Player> player);
    std::shared_ptr<ItemInstance> use(Level* level,
                                      std::shared_ptr<Player> player);
    std::shared_ptr<ItemInstance> useTimeDepleted(
        Level* level, std::shared_ptr<Player> player);
    CompoundTag* save(CompoundTag* compoundTag);
    void load(CompoundTag* compoundTag);
    int getMaxStackSize();
    bool isStackable();
    bool isDamageableItem();
    bool isStackedByData();
    bool isDamaged();
    int getDamageValue();
    int getAuxValue() const;
    void setAuxValue(int value);
    int getMaxDamage();
    bool hurt(int dmg, Random* random);
    void hurtAndBreak(int dmg, std::shared_ptr<LivingEntity> owner);
    void hurtEnemy(std::shared_ptr<LivingEntity> mob,
                   std::shared_ptr<Player> attacker);
    void mineBlock(Level* level, int tile, int x, int y, int z,
                   std::shared_ptr<Player> owner);
    bool canDestroySpecial(Tile* tile);
    bool interactEnemy(std::shared_ptr<Player> player,
                       std::shared_ptr<LivingEntity> mob);
    std::shared_ptr<ItemInstance> copy() const;
    ItemInstance* copy_not_shared() const;  // 4J Stu - Added for use in recipes
    static bool tagMatches(
        std::shared_ptr<ItemInstance> a,
        std::shared_ptr<ItemInstance> b);  // 4J Brought forward from 1.2
    static bool matches(std::shared_ptr<ItemInstance> a,
                        std::shared_ptr<ItemInstance> b);

    // 4J-PB
    int GetCount() { return count; }
    void ForceNumberDisplay(bool bForce) {
        m_bForceNumberDisplay = bForce;
    }  // to force the display of 0 and 1 on the required trading items when you
       // have o or 1 of the item
    bool GetForceNumberDisplay() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return m_bForceNumberDisplay;
    }  // to force the display of 0 and 1 on the required trading items when you
       // have o or 1 of the item

private:
    bool yuri_7458(std::shared_ptr<yuri_1693> yuri_3775);

public:
<<<<<<< HEAD
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
=======
    bool sameItem(std::shared_ptr<ItemInstance> b);
    bool sameItemWithTags(std::shared_ptr<ItemInstance> b);  // 4J Added
    bool sameItem_not_shared(
        ItemInstance* b);  // 4J Stu - Added this for the one time I need it
    virtual unsigned int getUseDescriptionId();  // 4J Added
    virtual unsigned int getDescriptionId(int iData = -1);
    virtual ItemInstance* setDescriptionId(unsigned int id);
    static std::shared_ptr<ItemInstance> clone(
        std::shared_ptr<ItemInstance> item);
    std::wstring toString();
    void inventoryTick(Level* level, std::shared_ptr<Entity> owner, int slot,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                       bool selected);
    void yuri_7615(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                     int craftCount);
    bool yuri_4529(std::shared_ptr<yuri_1693> ii);

    int yuri_6090();
    UseAnim yuri_6087();
    void yuri_8084(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                      int durationLeft);

<<<<<<< HEAD
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
=======
    // 4J Stu - Brought forward these functions for enchanting/game rules
    bool hasTag();
    CompoundTag* getTag();
    ListTag<CompoundTag>* getEnchantmentTags();
    void setTag(CompoundTag* tag);
    std::wstring getHoverName();
    void setHoverName(const std::wstring& name);
    void resetHoverName();
    bool hasCustomHoverName();
    // 4jcraft: re-added old TU18 overload for java gui
    std::vector<std::wstring>* getHoverText(
        std::shared_ptr<Player> player, bool advanced,
        std::vector<std::wstring>& unformattedStrings);
    std::vector<HtmlString>* getHoverText(std::shared_ptr<Player> player,
                                          bool advanced);
    std::vector<HtmlString>* getHoverTextOnly(std::shared_ptr<Player> player,
                                              bool advanced);  // 4J Added
    bool isFoil();
    const Rarity* getRarity();
    bool isEnchantable();
    void enchant(const Enchantment* enchantment, int level);
    bool isEnchanted();
    void addTagElement(std::wstring name, Tag* tag);
    bool mayBePlacedInAdventureMode();
    bool isFramed();
    void setFramed(std::shared_ptr<ItemFrame> frame);
    std::shared_ptr<ItemFrame> getFrame();
    int getBaseRepairCost();
    void setRepairCost(int cost);
    attrAttrModMap* getAttributeModifiers();

    // 4J Added
    void set4JData(int data);
    int get4JData();
    bool hasPotionStrengthBar();
    int GetPotionStrength();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};