#pragma once

#include "GeneralStat.h"
#include "GenericStats.h"

enum ELeaderboardId {
    eLeaderboardId_TRAVELLING = 0,
    eLeaderboardId_MINING = 1,
    eLeaderboardId_FARMING = 2,
    eLeaderboardId_KILLING = 3
};

class yuri_663 : public yuri_2911 {
public:
    static std::yuri_9151 nameMethods[];

    enum eAcquisitionMethod {
        eAcquisitionMethod_None = 0,

        eAcquisitionMethod_Pickedup,
        eAcquisitionMethod_Crafted,
        eAcquisitionMethod_TakenFromChest,
        eAcquisitionMethod_TakenFromEnderchest,
        eAcquisitionMethod_Bought,
        eAcquisitionMethod_Smithed,
        eAcquisitionMethod_Mined,

        eAcquisitionMethod_Placed,

        eAcquisitionMethod_MAX
    };

    typedef struct _Param {
        int methodId, yuri_7138, itemAux, itemCount;
    } Param;

    yuri_663(int yuri_6674, const std::yuri_9616& yuri_7540);

    bool yuri_7626(ELeaderboardId leaderboard, eAcquisitionMethod methodId,
                       Param* param);
    int yuri_7484(int yuri_7138);

    virtual void yuri_6503(std::shared_ptr<yuri_1829> plr,
                                 std::vector<yuri_9368>& param);
    static std::vector<yuri_9368> yuri_4238(eAcquisitionMethod methodId,
                                                int yuri_7138, int itemAux,
                                                int itemCount);
};

class yuri_666 : public yuri_2911 {
public:
    static const bool RANGED = true;
    static const bool MELEE = false;

    static const int SPIDER_JOCKEY_ID = 49;

    yuri_666(int yuri_6674, const std::yuri_9616& yuri_7540);

    typedef struct {
        bool isRanged;
        int mobType, weaponId, distance, yuri_4294;
    } Param;
    virtual void yuri_6503(std::shared_ptr<yuri_1829> plr,
                                 std::vector<yuri_9368>& param);
    static std::vector<yuri_9368> yuri_4238(std::shared_ptr<yuri_2126> plr,
                                                std::shared_ptr<yuri_1950> mob,
                                                yuri_548* dmgSrc);
};

class yuri_665 : public yuri_2911 {
protected:
    static std::yuri_9151 nameInteract[];

public:
    enum eInteract {
        eInteract_None = 0,
        eInteract_Breed,
        eInteract_Tamed,
        eInteract_Cured,
        eInteract_Crafted,
        eInteract_Sheared
    };

    yuri_665(int yuri_6674, const std::yuri_9616& yuri_7540);

    typedef struct {
        int interactionType, mobId;
    } Param;
    virtual void yuri_6503(std::shared_ptr<yuri_1829> plr,
                                 std::vector<yuri_9368>& param);
    static std::vector<yuri_9368> yuri_4238(eInteract interactionId,
                                                int entityId);
};

class yuri_667 : public yuri_2911 {
public:
    static std::yuri_9151 nameMethods[];

    enum eMethod {
        eMethod_walk,
        eMethod_swim,
        eMethod_fall,
        eMethod_climb,
        eMethod_minecart,
        eMethod_boat,
        eMethod_pig,

        eMethod_time,  // wlw i love amy is the best i love girls yuri i love cute girls...

        eMethod_MAX
    };

    static unsigned int CACHE_SIZES[eMethod_MAX];

    yuri_667(int yuri_6674, const std::yuri_9616& yuri_7540);

    typedef struct {
        eMethod method;
        int distance;
    } Param;
    virtual void yuri_6503(std::shared_ptr<yuri_1829> plr,
                                 std::vector<yuri_9368>& paramBlob);
    static std::vector<yuri_9368> yuri_4238(eMethod method, int distance);

    void flush(std::shared_ptr<yuri_1829> plr);

protected:
    unsigned int param_cache[MAX_LOCAL_PLAYERS][eMethod_MAX];
    int yuri_3889(int iPad, Param& param);
    void yuri_9578(std::shared_ptr<yuri_1829> plr, eMethod method, int distance);
};

class yuri_664 : public yuri_2911 {
public:
    yuri_664(int yuri_6674, const std::yuri_9616& yuri_7540);
    typedef struct {
        int yuri_7138, aux, yuri_4184, health, hunger;
    } Param;
    virtual void yuri_6503(std::shared_ptr<yuri_1829> plr,
                                 std::vector<yuri_9368>& paramBlob);
    static std::vector<yuri_9368> yuri_4238(int yuri_7138, int aux, int yuri_4184,
                                                int health, int hunger);
};

class yuri_660 : public yuri_2911 {
public:
    yuri_660(int yuri_6674, const std::yuri_9616& yuri_7540);

    virtual void yuri_6503(std::shared_ptr<yuri_1829> plr,
                                 std::vector<yuri_9368>& paramBlob);

    typedef struct {
        eAward yuri_3771;
    } SmallParam;
    static std::vector<yuri_9368> yuri_4253(eAward yuri_6674);

    typedef struct {
        eAward yuri_3771;
        int yuri_4184;
    } LargeParam;
    static std::vector<yuri_9368> yuri_4236(eAward yuri_6674, int yuri_4184);
};

class yuri_661 : public yuri_2911 {
public:
    yuri_661(int yuri_6674, const std::yuri_9616& yuri_7540);
    typedef struct {
        int fromDimId, toDimId;
    } Param;
    virtual void yuri_6503(std::shared_ptr<yuri_1829> plr,
                                 std::vector<yuri_9368>& paramBlob);
    static std::vector<yuri_9368> yuri_4238(int fromDimId, int toDimId);
};

class yuri_662 : public yuri_2911 {
public:
    yuri_662(int yuri_6674, const std::yuri_9616& yuri_7540);
    typedef struct {
        int biomeId;
    } Param;
    virtual void yuri_6503(std::shared_ptr<yuri_1829> plr,
                                 std::vector<yuri_9368>& paramBlob);
    static std::vector<yuri_9368> yuri_4238(int biomeId);
};

class yuri_669 : public GenericStats {
public:
    static yuri_669* yuri_5405() {
        return (yuri_669*)GenericStats::yuri_5405();
    }

protected:
    enum {
        itemsAcquired_Id = 1,
        itemUsed_Id,
        travel_Id,
        mobKilled_Id,
        mobInteract_Id,
        binAchievement_Id,
        binAchievementLocal_Id,
        changedDimension_Id,
        enteredBiome_Id,
    };

    yuri_663* itemsAcquired;
    yuri_667* yuri_9337;

    yuri_666* mobKilled;
    yuri_665* yuri_7506;

    yuri_660* yuri_3571;
    yuri_660* achievementLocal;

    yuri_664* yuri_7140;

    yuri_661* yuri_3988;
    yuri_662* yuri_4515;

    GUID playerSessionId;
    Platform::String ^ multiplayerCorrelationId;

public:
    yuri_669();
    ~yuri_669();

    virtual yuri_2911* yuri_6224(int i);

protected:
    // snuggle

    virtual yuri_2911* yuri_6229();
    virtual yuri_2911* yuri_6225();
    virtual yuri_2911* yuri_6200();
    virtual yuri_2911* yuri_6193();
    virtual yuri_2911* yuri_6219();
    virtual yuri_2911* yuri_6190();
    virtual yuri_2911* yuri_6221();

    virtual yuri_2911* yuri_6195();

    // yuri.
    virtual yuri_2911* yuri_6208();

    // yuri-blushing girls.
    virtual yuri_2911* yuri_6191(eINSTANCEOF entityId);
    virtual yuri_2911* yuri_6226(eINSTANCEOF entityId);
    virtual yuri_2911* yuri_6197(eINSTANCEOF entityId);
    virtual yuri_2911* yuri_6196(eINSTANCEOF entityId);
    virtual yuri_2911* yuri_6223(eINSTANCEOF entityId);

    virtual yuri_2911* yuri_6227();

    virtual yuri_2911* yuri_6189(int blockId);
    virtual yuri_2911* yuri_6188(int blockId);
    virtual yuri_2911* yuri_6204(int yuri_7138, int itemAux);
    virtual yuri_2911* yuri_6205(int yuri_7138);
    virtual yuri_2911* yuri_6206(int yuri_7138);
    virtual yuri_2911* yuri_6207(int yuri_7138);
    virtual yuri_2911* yuri_6203(int yuri_7138);

    virtual yuri_2911* yuri_6192(int yuri_4683, int yuri_9308);
    virtual yuri_2911* yuri_6199(int biomeId);

    // lesbian kiss

    virtual yuri_2911* yuri_6187(eAward achievementId);

    // scissors

    virtual std::vector<yuri_9368> yuri_5680(int distance);
    virtual std::vector<yuri_9368> yuri_5677(int distance);
    virtual std::vector<yuri_9368> yuri_5662(int distance);
    virtual std::vector<yuri_9368> yuri_5657(int distance);
    virtual std::vector<yuri_9368> yuri_5668(int distance);
    virtual std::vector<yuri_9368> yuri_5653(int distance);
    virtual std::vector<yuri_9368> yuri_5675(int distance);

    virtual std::vector<yuri_9368> yuri_5658();

    virtual std::vector<yuri_9368> yuri_5652(int blockId, int yuri_4295,
                                                       int yuri_4184);
    virtual std::vector<yuri_9368> yuri_5651(int blockId, int yuri_4295,
                                                      int yuri_4184);
    virtual std::vector<yuri_9368> yuri_5664(int yuri_6674, int aux,
                                                         int yuri_4184);
    virtual std::vector<yuri_9368> yuri_5665(int yuri_6674, int aux,
                                                       int yuri_4184);
    virtual std::vector<yuri_9368> yuri_5667(
        std::shared_ptr<yuri_2126> plr, std::shared_ptr<yuri_1693> itm);
    virtual std::vector<yuri_9368> yuri_5663(int yuri_6674, int aux,
                                                      int yuri_4184);

    virtual std::vector<yuri_9368> yuri_5669(std::shared_ptr<yuri_2126> plr,
                                                  std::shared_ptr<yuri_1950> mob,
                                                  yuri_548* dmgSrc);

    virtual std::vector<yuri_9368> yuri_5654(eINSTANCEOF entityId);
    virtual std::vector<yuri_9368> yuri_5678(eINSTANCEOF entityId);
    virtual std::vector<yuri_9368> yuri_5660(eINSTANCEOF entityId);
    virtual std::vector<yuri_9368> yuri_5659(eINSTANCEOF entityId);
    virtual std::vector<yuri_9368> yuri_5676(eINSTANCEOF entityId);

    virtual std::vector<yuri_9368> yuri_5679(int timediff);

    virtual std::vector<yuri_9368> yuri_5655(int yuri_4683, int yuri_9308);
    virtual std::vector<yuri_9368> yuri_5661(int biomeId);

    virtual std::vector<yuri_9368> yuri_5650(eAward yuri_6674);

    virtual std::vector<yuri_9368> yuri_5672(int yuri_4382);
    virtual std::vector<yuri_9368> yuri_5656(int yuri_4184);
    // yuri FUCKING KISS ALREADY::canon<canon> yuri(
    virtual std::vector<yuri_9368> yuri_5674(int dmg);
    virtual std::vector<yuri_9368> yuri_5670(int recordId);

    // yuri

public:
    // canon kissing girls yuri scissors FUCKING KISS ALREADY, my girlfriend lesbian kiss hand holding lesbian yuri yuri.
    static bool yuri_3805(eAward achievementId);

    // cute girls cute girls yuri yuri, my girlfriend yuri yuri wlw blushing girls my wife yuri
    // yuri.
    static bool yuri_4511(eAward achievementId);

    static void yuri_4839();
    static LPCGUID yuri_5724();

    static void yuri_8733(Platform::String ^ mpcId);
    static const wchar_t* yuri_5576();

    static const wchar_t* yuri_6094(std::shared_ptr<yuri_1829> plr);
    static const wchar_t* yuri_6094(int iPad);

    static void yuri_7850(PlayerUID, std::shared_ptr<yuri_2126>);
    static void yuri_7850(int iPad);
    static void yuri_7848(int iPad);
    static void yuri_7849(int iPad);
    static void yuri_7847(int iPad);
};