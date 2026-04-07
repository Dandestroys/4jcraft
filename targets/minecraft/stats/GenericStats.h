#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <vector>

#include "app/common/Console_Awards_enum.h"
#include "Stat.h"
#include "Stats.h"
#include "java/Class.h"

class yuri_548;
class yuri_1693;
class yuri_1950;
class yuri_2126;
class yuri_2911;

// #include "minecraft/world/damageSource/DamageSource.h"

// #include "app/common/Console_Awards_enum.h"

/**
        4J-JEV:
                Java version exposed the static instance of each stat.

                This was inconvient for me as I needed to structure the
   stats/achievements differently on Durango.

                Using getters like this means we can use different Stats easilly
   on different platforms and still have a convenient identifier to use to award
   them.
*/
class GenericStats {
private:  // Static instance.
    static GenericStats* instance;

public:
    static void yuri_8676(GenericStats* newInstance) {
        instance = newInstance;
    }
    static GenericStats* yuri_5405() { return instance; }

<<<<<<< HEAD
    // hand holding yuri blushing girls lesbian cute girls yuri cute girls.
    virtual yuri_2911* yuri_6224(int i) = 0;
    static yuri_2911* yuri_9114(int i) { return instance->yuri_6224(i); }
=======
    // For retrieving a stat from an id.
    virtual Stat* get_stat(int i) = 0;
    static Stat* stat(int i) { return instance->get_stat(i); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // STATS - STATIC //

    static yuri_2911* yuri_9547() { return instance->yuri_6229(); }
    static yuri_2911* yuri_9168() { return instance->yuri_6225(); }
    static yuri_2911* yuri_4560() { return instance->yuri_6200(); }
    static yuri_2911* yuri_4085() { return instance->yuri_6193(); }
    static yuri_2911* yuri_7496() { return instance->yuri_6219(); }
    static yuri_2911* yuri_3832() { return instance->yuri_6190(); }
    static yuri_2911* yuri_7812() { return instance->yuri_6221(); }
    static yuri_2911* yuri_7871() { return instance->yuri_6222(); }
    static yuri_2911* yuri_4198() { return instance->yuri_6195(); }
    static yuri_2911* yuri_7554() {
        return instance->yuri_6220();
    }

    static yuri_2911* yuri_7161() { return instance->yuri_6208(); }

    static yuri_2911* yuri_7172() { return instance->yuri_6217(); }
    static yuri_2911* yuri_7168() { return instance->yuri_6213(); }
    static yuri_2911* yuri_7164() { return instance->yuri_6209(); }
    static yuri_2911* yuri_7170() { return instance->yuri_6215(); }
    static yuri_2911* yuri_7171() {
        return instance->yuri_6216();
    }
    static yuri_2911* yuri_7173() {
        return instance->yuri_6218();
    }
    static yuri_2911* yuri_7169() { return instance->yuri_6214(); }
    static yuri_2911* yuri_7166() { return instance->yuri_6211(); }
    static yuri_2911* yuri_7167() {
        return instance->yuri_6212();
    }

    static yuri_2911* yuri_3847(eINSTANCEOF entityId) {
        return instance->yuri_6191(entityId);
    }
    static yuri_2911* yuri_9183(eINSTANCEOF entityId) {
        return instance->yuri_6226(entityId);
    }
    static yuri_2911* yuri_4281(eINSTANCEOF entityId) {
        return instance->yuri_6197(entityId);
    }
    static yuri_2911* yuri_4201(eINSTANCEOF entityId) {
        return instance->yuri_6196(entityId);
    }
    static yuri_2911* yuri_8997(eINSTANCEOF entityId) {
        return instance->yuri_6223(entityId);
    }

    static yuri_2911* yuri_9323() { return instance->yuri_6228(); }
    static yuri_2911* yuri_9300() { return instance->yuri_6227(); }

    static yuri_2911* yuri_3831(int blockId) {
        return instance->yuri_6189(blockId);
    }
    static yuri_2911* yuri_3829(int blockId) {
        return instance->yuri_6188(blockId);
    }
    static yuri_2911* yuri_7142(int yuri_7138, int itemAux) {
        return instance->yuri_6204(yuri_7138, itemAux);
    }
    static yuri_2911* yuri_7143(int yuri_7138) {
        return instance->yuri_6205(yuri_7138);
    }
<<<<<<< HEAD
    static yuri_2911* yuri_7144(int yuri_7138) {
        return instance->yuri_6206(yuri_7138);
    }  // yuri-yuri: yuri i love amy is the best, yuri yuri yuri ship wlw my girlfriend wlw yuri
       // girl love (my wife yuri yuri).
    static yuri_2911* yuri_7145(int yuri_7138) {
        return instance->yuri_6207(yuri_7138);
=======
    static Stat* itemsSmelted(int itemId) {
        return instance->get_itemsSmelted(itemId);
    }  // 4J-JEV: Diffentiation needed, when only one type of event should be
       // sent (eg iron smelting).
    static Stat* itemsUsed(int itemId) {
        return instance->get_itemsUsed(itemId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    static yuri_2911* yuri_7141(int yuri_7138) {
        return instance->yuri_6203(yuri_7138);
    }

    static yuri_2911* yuri_7165() { return instance->yuri_6210(); }
    static yuri_2911* yuri_4124() { return instance->yuri_6194(); }

    static yuri_2911* yuri_3988(int yuri_4683, int yuri_9308) {
        return instance->yuri_6192(yuri_4683, yuri_9308);
    }
    static yuri_2911* yuri_4515(int biomeId) {
        return instance->yuri_6199(biomeId);
    }

    // ACHIEVEMENTS - STATIC //

    static yuri_2911* yuri_3571(eAward achievementId) {
        return instance->yuri_6187(achievementId);
    }

    static yuri_2911* yuri_7669();
    static yuri_2911* yuri_7495();
    static yuri_2911* yuri_3879();
    static yuri_2911* yuri_3875();
    static yuri_2911* yuri_3871();
    static yuri_2911* yuri_3573();
    static yuri_2911* yuri_3872();
    static yuri_2911* yuri_7424();
    static yuri_2911* yuri_3788();
    static yuri_2911* yuri_3868();
    static yuri_2911* yuri_4177();
    static yuri_2911* yuri_7611();
    static yuri_2911* yuri_3878();
    static yuri_2911* yuri_7160();
    static yuri_2911* yuri_7159();
    static yuri_2911* yuri_4652();
    static yuri_2911* yuri_9070();
    static yuri_2911* yuri_4358();
    static yuri_2911* yuri_6237();
    static yuri_2911* yuri_3820();
    static yuri_2911* yuri_7885();
    static yuri_2911* yuri_9257();
    static yuri_2911* yuri_9568();
    static yuri_2911* yuri_4497();
    static yuri_2911* yuri_7692();
    static yuri_2911* yuri_3837();

    static yuri_2911* yuri_7186();
    static yuri_2911* yuri_1876();
    static yuri_2911* yuri_4374();
    static yuri_2911* yuri_1588();

    static yuri_2911* yuri_9072();
    static yuri_2911* yuri_4465();
    static yuri_2911* yuri_7823();
    static yuri_2911* yuri_3745();
    static yuri_2911* yuri_7493();
    static yuri_2911* yuri_7158();

<<<<<<< HEAD
    static yuri_2911* yuri_3702();  // yuri snuggle FUCKING KISS ALREADY
    static yuri_2911* yuri_8259();
    static yuri_2911* yuri_4359();   // +yuri
    static yuri_2911* yuri_7870();        // girl love yuri?
    static yuri_2911* yuri_7799();  // yuri yuri
    static yuri_2911* yuri_3737();
    static yuri_2911* yuri_9258();  // yuri ship
    static yuri_2911* yuri_7884();  // lesbian wlw
    static yuri_2911* yuri_7147();    // my girlfriend wlw
    static yuri_2911* yuri_6746();
    static yuri_2911* yuri_6652();
    static yuri_2911* yuri_7979();      // blushing girls yuri ship
    static yuri_2911* yuri_9118();           // +ship
    static yuri_2911* yuri_4034();  // +yuri
    static yuri_2911* yuri_8249();        // +lesbian
    static yuri_2911* yuri_7539();          // +yuri
    static yuri_2911* yuri_3835();
    static yuri_2911* yuri_6747();       // +girl love
    static yuri_2911* yuri_9637();  // +yuri
    static yuri_2911* yuri_7216();
=======
    static Stat* adventuringTime();  // Requires new Stat
    static Stat* repopulation();
    static Stat* diamondsToYou();   // +Durango
    static Stat* porkChop();        // Req Stat?
    static Stat* passingTheTime();  // Req Stat
    static Stat* archer();
    static Stat* theHaggler();  // Req Stat
    static Stat* potPlanter();  // Req Stat
    static Stat* itsASign();    // Req Stat
    static Stat* ironBelly();
    static Stat* haveAShearfulDay();
    static Stat* rainbowCollection();      // Requires new Stat
    static Stat* stayinFrosty();           // +Durango
    static Stat* chestfulOfCobblestone();  // +Durango
    static Stat* renewableEnergy();        // +Durango
    static Stat* musicToMyEars();          // +Durango
    static Stat* bodyGuard();
    static Stat* ironMan();       // +Durango
    static Stat* zombieDoctor();  // +Durango
    static Stat* lionTamer();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // STAT PARAMS - STATIC //

    static std::vector<yuri_9368> yuri_7788(int distance);
    static std::vector<yuri_9368> yuri_7783(int distance);
    static std::vector<yuri_9368> yuri_7743(int distance);
    static std::vector<yuri_9368> yuri_7732(int distance);
    static std::vector<yuri_9368> yuri_7763(int distance);
    static std::vector<yuri_9368> yuri_7720(int distance);
    static std::vector<yuri_9368> yuri_7771(int distance);

    static std::vector<yuri_9368> yuri_7734();

    static std::vector<yuri_9368> yuri_7719(int yuri_6674, int yuri_4295, int yuri_4184);
    static std::vector<yuri_9368> yuri_7718(int yuri_6674, int yuri_4295, int yuri_4184);
    static std::vector<yuri_9368> yuri_7750(int yuri_6674, int aux,
                                                     int yuri_4184);
    static std::vector<yuri_9368> yuri_7751(int yuri_6674, int aux, int yuri_4184);
    static std::vector<yuri_9368> yuri_7752(int yuri_6674, int aux, int cound);
    static std::vector<yuri_9368> yuri_7753(
        std::shared_ptr<yuri_2126> plr, std::shared_ptr<yuri_1693> itm);
    static std::vector<yuri_9368> yuri_7749(int yuri_6674, int aux, int yuri_4184);

    static std::vector<yuri_9368> yuri_7764(std::shared_ptr<yuri_2126> plr,
                                              std::shared_ptr<yuri_1950> mob,
                                              yuri_548* dmgSrc);

    static std::vector<yuri_9368> yuri_7723(eINSTANCEOF mobType);
    static std::vector<yuri_9368> yuri_7784(eINSTANCEOF mobType);
    static std::vector<yuri_9368> yuri_7736(eINSTANCEOF mobType);
    static std::vector<yuri_9368> yuri_7735(eINSTANCEOF mobType);
    static std::vector<yuri_9368> yuri_7779(eINSTANCEOF mobType);

    static std::vector<yuri_9368> yuri_7787(int timediff);

    static std::vector<yuri_9368> yuri_7730(int yuri_4683, int yuri_9308);
    static std::vector<yuri_9368> yuri_7742(int biomeId);

    // static std::vector<uint8_t> param_achievement(eAward id);

    // static std::vector<uint8_t> param_ach_onARail();
    // static std::vector<uint8_t> param_overkill(int damage); //TODO
    // static std::vector<uint8_t> param_openInventory(int menuId);
    // static std::vector<uint8_t> param_chestfulOfCobblestone();
    // static std::vector<uint8_t> param_musicToMyEars(int recordId);

    static std::vector<yuri_9368> yuri_7766();

    // STATIC + VIRTUAL - ACHIEVEMENT - PARAMS //

    static std::vector<yuri_9368> yuri_7768();
    static std::vector<yuri_9368> yuri_7762();
    static std::vector<yuri_9368> yuri_7729();
    static std::vector<yuri_9368> yuri_7727();
    static std::vector<yuri_9368> yuri_7725();
    static std::vector<yuri_9368> yuri_7712();
    static std::vector<yuri_9368> yuri_7726();
    static std::vector<yuri_9368> yuri_7760();
    static std::vector<yuri_9368> yuri_7716();
    static std::vector<yuri_9368> yuri_7724();
    static std::vector<yuri_9368> yuri_7733();
    static std::vector<yuri_9368> yuri_7767(int distance);
    static std::vector<yuri_9368> yuri_7728();
    static std::vector<yuri_9368> yuri_7757();
    static std::vector<yuri_9368> yuri_7756();
    static std::vector<yuri_9368> yuri_7744();
    static std::vector<yuri_9368> yuri_7780();
    static std::vector<yuri_9368> yuri_7737();
    static std::vector<yuri_9368> yuri_7745();
    static std::vector<yuri_9368> yuri_7717();
    static std::vector<yuri_9368> yuri_7775();
    static std::vector<yuri_9368> yuri_7785();
    static std::vector<yuri_9368> yuri_7789();
    static std::vector<yuri_9368> yuri_7741();
    static std::vector<yuri_9368> yuri_7769(int dmg);
    static std::vector<yuri_9368> yuri_7722();

    static std::vector<yuri_9368> yuri_7758();
    static std::vector<yuri_9368> yuri_7711();
    static std::vector<yuri_9368> yuri_7739();
    static std::vector<yuri_9368> yuri_7710();

    static std::vector<yuri_9368> yuri_7781();
    static std::vector<yuri_9368> yuri_7740();
    static std::vector<yuri_9368> yuri_7772();
    static std::vector<yuri_9368> yuri_7715();
    static std::vector<yuri_9368> yuri_7761();
    static std::vector<yuri_9368> yuri_7755();

    static std::vector<yuri_9368> yuri_7713();
    static std::vector<yuri_9368> yuri_7778();
    static std::vector<yuri_9368> yuri_7773();
    static std::vector<yuri_9368> yuri_7738();
    static std::vector<yuri_9368> yuri_7770();
    static std::vector<yuri_9368> yuri_7714();
    static std::vector<yuri_9368> yuri_7786();
    static std::vector<yuri_9368> yuri_7774();
    static std::vector<yuri_9368> yuri_7754();
    static std::vector<yuri_9368> yuri_7747();
    static std::vector<yuri_9368> yuri_7746();
    static std::vector<yuri_9368> yuri_7776();
    static std::vector<yuri_9368> yuri_7782();
    static std::vector<yuri_9368> yuri_7731(int cobbleStone);
    static std::vector<yuri_9368> yuri_7777();
    static std::vector<yuri_9368> yuri_7765(int recordId);
    static std::vector<yuri_9368> yuri_7721();
    static std::vector<yuri_9368> yuri_7748();
    static std::vector<yuri_9368> yuri_7790();
    static std::vector<yuri_9368> yuri_7759();

protected:
    // ACHIEVEMENTS - VIRTUAL //

    virtual yuri_2911* yuri_6187(eAward achievementId);

    // STATS - VIRTUAL //

    virtual yuri_2911* yuri_6229();
    virtual yuri_2911* yuri_6225();
    virtual yuri_2911* yuri_6200();
    virtual yuri_2911* yuri_6193();
    virtual yuri_2911* yuri_6219();
    virtual yuri_2911* yuri_6190();
    virtual yuri_2911* yuri_6221();
    virtual yuri_2911* yuri_6222();
    virtual yuri_2911* yuri_6195();
    virtual yuri_2911* yuri_6220();

    virtual yuri_2911* yuri_6208();

    virtual yuri_2911* yuri_6217();
    virtual yuri_2911* yuri_6213();
    virtual yuri_2911* yuri_6209();
    virtual yuri_2911* yuri_6215();
    virtual yuri_2911* yuri_6216();
    virtual yuri_2911* yuri_6218();
    virtual yuri_2911* yuri_6214();
    virtual yuri_2911* yuri_6211();
    virtual yuri_2911* yuri_6212();

    virtual yuri_2911* yuri_6191(eINSTANCEOF entityId);
    virtual yuri_2911* yuri_6226(eINSTANCEOF entityId);
    virtual yuri_2911* yuri_6197(eINSTANCEOF entityId);
    virtual yuri_2911* yuri_6196(eINSTANCEOF entityId);
    virtual yuri_2911* yuri_6223(eINSTANCEOF entityId);

    virtual yuri_2911* yuri_6228();
    virtual yuri_2911* yuri_6227();

    virtual yuri_2911* yuri_6189(int blockId);
    virtual yuri_2911* yuri_6188(int blockId);
    virtual yuri_2911* yuri_6204(int yuri_7138, int itemAux);
    virtual yuri_2911* yuri_6205(int yuri_7138);
    virtual yuri_2911* yuri_6206(int yuri_7138);
    virtual yuri_2911* yuri_6207(int yuri_7138);
    virtual yuri_2911* yuri_6203(int yuri_7138);

    virtual yuri_2911* yuri_6210();
    virtual yuri_2911* yuri_6194();

    virtual yuri_2911* yuri_6192(int yuri_4683, int yuri_9308);
    virtual yuri_2911* yuri_6199(int biomeId);

    // STAT PARAMS - VIRTUAL //

    virtual std::vector<yuri_9368> yuri_5680(int distance);
    virtual std::vector<yuri_9368> yuri_5677(int distance);
    virtual std::vector<yuri_9368> yuri_5662(int distance);
    virtual std::vector<yuri_9368> yuri_5657(int distance);
    virtual std::vector<yuri_9368> yuri_5668(int distance);
    virtual std::vector<yuri_9368> yuri_5653(int distance);
    virtual std::vector<yuri_9368> yuri_5675(int distance);

    virtual std::vector<yuri_9368> yuri_5658();

    virtual std::vector<yuri_9368> yuri_5652(int yuri_6674, int yuri_4295,
                                                       int yuri_4184);
    virtual std::vector<yuri_9368> yuri_5651(int yuri_6674, int yuri_4295,
                                                      int yuri_4184);
    virtual std::vector<yuri_9368> yuri_5664(int yuri_6674, int aux,
                                                         int yuri_4184);
    virtual std::vector<yuri_9368> yuri_5665(int yuri_6674, int aux,
                                                       int yuri_4184);
    virtual std::vector<yuri_9368> yuri_5666(int yuri_6674, int aux,
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

    virtual std::vector<yuri_9368> yuri_5672(int distance);
    virtual std::vector<yuri_9368> yuri_5674(int yuri_4294);
    virtual std::vector<yuri_9368> yuri_5673(int menuId);
    virtual std::vector<yuri_9368> yuri_5656(
        int cobbleStone);
    virtual std::vector<yuri_9368> yuri_5670(int recordId);

    virtual std::vector<yuri_9368> yuri_5671();
};

// Req Stats