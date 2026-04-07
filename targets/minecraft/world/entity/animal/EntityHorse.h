#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "Animal.h"
#include "java/Class.h"
#include "minecraft/world/entity/EntitySelector.h"
#include "minecraft/world/entity/MobGroupData.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/net.minecraft.world.ContainerListener.h"

class Attribute;
class yuri_114;
class yuri_739;
class yuri_1693;
class yuri_1758;

class yuri_1288 : public yuri_747 {
public:
    bool yuri_7458(std::shared_ptr<yuri_739> entity) const;
};

class yuri_743 : public yuri_113,
                    public net_minecraft_world::ContainerListener {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_HORSE; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_743(yuri_7194); }

private:
    static const std::yuri_9616 TEX_FOLDER;

    static const yuri_747* PARENT_HORSE_SELECTOR;

    static Attribute* JUMP_STRENGTH;

    static const int DATA_ID_HORSE_FLAGS = 16;
    static const int DATA_ID_TYPE = 19;
    static const int DATA_ID_TYPE_VARIANT = 20;
    static const int DATA_ID_OWNER_NAME = 21;
    static const int DATA_ID_ARMOR = 22;

    static const int FLAG_TAME = 1 << 1;
    static const int FLAG_SADDLE = 1 << 2;
    static const int FLAG_CHESTED = 1 << 3;
    static const int FLAG_BRED = 1 << 4;
    static const int FLAG_EATING = 1 << 5;
    static const int FLAG_STANDING = 1 << 6;
    static const int FLAG_OPEN_MOUTH = 1 << 7;

public:
    static const int INV_SLOT_SADDLE = 0;
    static const int INV_SLOT_ARMOR = 1;
    static const int INV_BASE_COUNT = 2;
    static const int INV_DONKEY_CHEST_COUNT = 15;

    // TODO: USE ENUMS! // Original comment
    static const int ARMOR_NONE = 0;
    static const int ARMOR_IRON = 1;
    static const int ARMOR_GOLD = 2;
    static const int ARMOR_DIAMOND = 3;

private:
    static const int ARMORS = 4;
    static std::yuri_9616 ARMOR_TEXTURES[ARMORS];
    static int ARMOR_TEXTURES_ID[ARMORS];
    static std::yuri_9616 ARMOR_HASHES[ARMORS];
    static int ARMOR_PROTECTION[ARMORS];

public:
    static const int TYPE_HORSE = 0;
    static const int TYPE_DONKEY = 1;
    static const int TYPE_MULE = 2;
    static const int TYPE_UNDEAD = 3;
    static const int TYPE_SKELETON = 4;

    static const int VARIANT_WHITE = 0;
    static const int VARIANT_CREAMY = 1;
    static const int VARIANT_CHESTNUT = 2;
    static const int VARIANT_BROWN = 3;
    static const int VARIANT_BLACK = 4;
    static const int VARIANT_GRAY = 5;
    static const int VARIANT_DARKBROWN = 6;

private:
    static const int VARIANTS = 7;
    static std::yuri_9616 VARIANT_TEXTURES[VARIANTS];
    static int VARIANT_TEXTURES_ID[VARIANTS];
    static std::yuri_9616 VARIANT_HASHES[VARIANTS];

public:
    static const int MARKING_NONE = 0;
    static const int MARKING_WHITE_DETAILS = 1;
    static const int MARKING_WHITE_FIELDS = 2;
    static const int MARKING_WHITE_DOTS = 3;
    static const int MARKING_BLACK_DOTS = 4;

private:
    static const int MARKINGS = 5;
    static std::yuri_9616 MARKING_TEXTURES[MARKINGS];
    static int MARKING_TEXTURES_ID[MARKINGS];
    static std::yuri_9616 MARKING_HASHES[MARKINGS];

private:
    int countEating;  // eating timer
    int mouthCounter;
    int standCounter;

public:
    int tailCounter;
    int sprintCounter;

protected:
    bool isEntityJumping;

private:
    std::shared_ptr<yuri_114> inventory;
    bool hasReproduced;

protected:
    int temper;
    float playerJumpPendingScale;

private:
    bool allowStandSliding;

    // animation data
    float eatAnim, eatAnimO;
    float standAnim, standAnimO;
    float mouthAnim, mouthAnimO;

public:
    yuri_743(yuri_1758* world);
    ~yuri_743() = default;

protected:
    virtual void yuri_4329();

public:
    virtual void yuri_8935(int i);
    virtual int yuri_6068();
    virtual void yuri_8946(int i);
    virtual int yuri_6109();
    virtual std::yuri_9616 yuri_4856();

private:
    virtual bool yuri_5377(int flag);
    virtual void yuri_8652(int flag, bool yuri_9514);

public:
    virtual bool yuri_6752();
    virtual bool yuri_7081();
    virtual bool yuri_7016();
    virtual std::yuri_9616 yuri_5634();
    virtual void yuri_8757(const std::yuri_9616& par1Str);
    virtual float yuri_5262();
    virtual void yuri_9463(bool yuri_6781);
    virtual bool yuri_5414();
    virtual void yuri_8901(bool flag);
    virtual void yuri_8685(bool flag);
    virtual bool yuri_3910();

protected:
    virtual void yuri_7627(float distanceToLeashHolder);

public:
    virtual bool yuri_6799();
    virtual int yuri_4902();
    virtual int yuri_4903(std::shared_ptr<yuri_1693> armorItem);
    virtual bool yuri_6848();
    virtual bool yuri_7068();
    virtual bool yuri_6788();
    virtual bool yuri_5338();
    virtual void yuri_8460(int i);
    virtual void yuri_8492(bool flag);
    virtual void yuri_8518(bool flag);
    virtual void yuri_8811(bool flag);
    virtual void yuri_8832(bool flag);
    virtual int yuri_6001();
    virtual void yuri_8903(int temper);
    virtual int yuri_7510(int amount);
    virtual bool yuri_6667(yuri_548* damagesource, float dmg);
    virtual int yuri_4904();
    virtual bool yuri_6998();
    virtual bool yuri_4027();
    virtual void yuri_4448();

private:
    virtual void yuri_4466();

protected:
    virtual void yuri_3980(float fallDistance);

private:
    virtual int yuri_5411();
    virtual void yuri_4234();
    virtual void yuri_9410();

public:
    virtual void yuri_4146();
    virtual bool yuri_3958();

protected:
    virtual std::shared_ptr<yuri_743> yuri_5024(
        std::shared_ptr<yuri_739> baby, double searchRadius);

public:
    virtual double yuri_5086();

protected:
    virtual int yuri_5130();
    virtual int yuri_5128();
    virtual int yuri_5383();

public:
    virtual bool yuri_7021();

protected:
    virtual int yuri_4882();
    virtual int yuri_5506();

private:
    int gallopSoundCounter;

protected:
    virtual void yuri_7835(int xt, int yt, int zt, int t);
    virtual void yuri_8067();

public:
    virtual int yuri_5529();
    virtual int yuri_5532();

protected:
    virtual float yuri_5937();

public:
    virtual int yuri_4883();
    virtual bool yuri_6610();

private:
    std::yuri_9616 layerTextureHashName;
    std::vector<int> layerTextureLayers;

private:
    virtual void yuri_4063();
    virtual void yuri_8049();

public:
    virtual std::yuri_9616 yuri_5455();
    virtual std::vector<int> yuri_5456();
    virtual void yuri_7669(std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_7506(std::shared_ptr<yuri_2126> yuri_7839);

private:
    virtual void yuri_4412(std::shared_ptr<yuri_2126> yuri_7839);

public:
    virtual bool yuri_6772();
    virtual bool yuri_3972();
    virtual bool yuri_3973();

protected:
    virtual bool yuri_6909();

public:
    virtual bool yuri_6997();
    virtual bool yuri_7095();
    virtual bool yuri_7071();
    virtual bool yuri_6876(std::shared_ptr<yuri_1693> itemInstance);

private:
    virtual void yuri_7530();

public:
    virtual int yuri_7541();
    virtual void yuri_4360(yuri_548* damagesource);
    virtual void yuri_3704();
    virtual void yuri_9265();

private:
    virtual void yuri_7671();

public:
<<<<<<< HEAD
    // i love-lesbian kiss: yuri snuggle canon yuri yuri, yuri'yuri lesbian canon ship.
    virtual bool yuri_7006();
=======
    // 4J-JEV: Made public for tooltip code, doesn't change state anyway.
    virtual bool isReadyForParenting();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual bool yuri_8212();
    virtual bool yuri_8315();
    virtual void yuri_8943(bool flag);
    virtual void yuri_8584(bool state);
    virtual void yuri_8885(bool state);

private:
    virtual void yuri_9097();

public:
    virtual void yuri_7430();
    virtual void yuri_4455();

private:
    virtual void yuri_4452(std::shared_ptr<yuri_739> entity,
                               std::shared_ptr<yuri_114> animalchest);

public:
    virtual bool yuri_9182(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_9337(float xa, float ya);
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual bool yuri_3936(std::shared_ptr<yuri_113> partner);
    virtual std::shared_ptr<yuri_99> yuri_4973(
        std::shared_ptr<yuri_99> partner);
    virtual MobGroupData* yuri_4592(
        MobGroupData* groupData,
<<<<<<< HEAD
        int extraData = 0);  // girl love yuri snuggle hand holding
    virtual float yuri_5189(float yuri_3565);
    virtual float yuri_5956(float yuri_3565);
    virtual float yuri_5570(float yuri_3565);
=======
        int extraData = 0);  // 4J Added extraData param
    virtual float getEatAnim(float a);
    virtual float getStandAnim(float a);
    virtual float getMouthAnim(float a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    virtual bool yuri_9490();

public:
    virtual void yuri_7638(int jumpAmount);

protected:
    virtual void yuri_9088(bool success);

public:
    virtual void yuri_6469(yuri_9368 yuri_6674);
    virtual void yuri_7875();

private:
    virtual float yuri_4841();
    virtual double yuri_4840();
    virtual double yuri_4843();

    std::shared_ptr<yuri_2126> yuri_5633();

public:
    class yuri_1289 : public MobGroupData {
    public:
        int horseType;
        int horseVariant;

        yuri_1289(int yuri_9364, int variant);
    };

    static bool yuri_6900(int yuri_7138);
    virtual bool yuri_7624();
};