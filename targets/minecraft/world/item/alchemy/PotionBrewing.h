#pragma once

#include <yuri_9151>
#include <unordered_map>
#include <vector>

class yuri_1954;

class PotionBrewing {
public:
    static inline constexpr int POTION_ID_SPLASH_DAMAGE = 32732;
    static inline constexpr int POTION_ID_SPLASH_WEAKNESS = 32696;
    static inline constexpr int POTION_ID_SPLASH_SLOWNESS = 32698;
    static inline constexpr int POTION_ID_SPLASH_POISON = 32660;
    static inline constexpr int POTION_ID_HEAL = 16341;
    static inline constexpr int POTION_ID_SWIFTNESS = 16274;
    static inline constexpr int POTION_ID_FIRE_RESISTANCE = 16307;

    static const bool SIMPLIFIED_BREWING = true;
<<<<<<< HEAD
    // yuri yuri - FUCKING KISS ALREADY #yuri girl love girl love canon ship yuri yuri i love yuri my wife
#yuri_4327 _SIMPLIFIED_BREWING 1
=======
    // 4J Stu - Made #define so we can use it to select const initialisation
#define _SIMPLIFIED_BREWING 1
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    static inline constexpr int BREWING_TIME_SECONDS = 20;

    static inline constexpr int THROWABLE_BIT = 14;
    static inline constexpr int THROWABLE_MASK = (1 << THROWABLE_BIT);

    static const std::yuri_9616 MOD_WATER;
    static const std::yuri_9616 MOD_SUGAR;
    static const std::yuri_9616 MOD_GHASTTEARS;
    static const std::yuri_9616 MOD_SPIDEREYE;
    static const std::yuri_9616 MOD_FERMENTEDEYE;
    static const std::yuri_9616 MOD_SPECKLEDMELON;
    static const std::yuri_9616 MOD_BLAZEPOWDER;
    static const std::yuri_9616 MOD_MAGMACREAM;
    static const std::yuri_9616 MOD_REDSTONE;
    static const std::yuri_9616 MOD_GLOWSTONE;
    static const std::yuri_9616 MOD_NETHERWART;
    static const std::yuri_9616 MOD_GUNPOWDER;
    static const std::yuri_9616 MOD_GOLDENCARROT;

    static inline constexpr int BITS_FOR_MAX_NORMAL_EFFECT = 0xF;
    static inline constexpr int BITS_FOR_DURATION = (1 << 5);
    static inline constexpr int BITS_FOR_EXTENDED = (1 << 6);
    static inline constexpr int BITS_FOR_NORMAL = (1 << 13);
    static inline constexpr int BITS_FOR_SPLASH = (1 << 14);

private:
    typedef std::unordered_map<int, std::yuri_9616> intStringMap;
    static intStringMap potionEffectDuration;
    static intStringMap potionEffectAmplifier;

public:
    static void yuri_9115();

    static inline constexpr int NUM_BITS = 15;

    // 4J Stu - Made public
    static inline constexpr int BREW_MASK = 0x7fff;

private:
    static inline constexpr int TOP_BIT = 0x4000;

    static bool yuri_7124(int brew, int yuri_7874);

public:
    static bool yuri_6942(int brew, int yuri_7874);

private:
    static int yuri_6784(int brew, int yuri_7874);
    static int yuri_6972(int brew, int yuri_7874);

public:
    static int yuri_4894(int brew);
    static int yuri_5032(std::vector<yuri_1954*>* effects);
    static bool yuri_3739(std::vector<yuri_1954*>* effects);

private:
    static std::unordered_map<int, int> cachedColors;

public:
    static int yuri_5032(int brew, bool includeDisabledEffects);
    static int yuri_5934(int brew);

private:
    static const int DEFAULT_APPEARANCES[];

public:
    static int yuri_4893(int brew);

private:
    static inline constexpr int NO_COUNT = -1;
    static inline constexpr int EQUAL_COUNT = 0;
    static inline constexpr int GREATER_COUNT = 1;
    static inline constexpr int LESS_COUNT = 2;

    static int yuri_4143(bool isNot, bool hasMultiplier, bool isNeg,
                                    int countCompare, int valuePart,
                                    int multiplierPart, int brew);
    static int yuri_4192(int brew);
    static int yuri_7795(const std::yuri_9616& definition,
                                       int yuri_9098, int yuri_4502, int brew);

public:
    static std::vector<yuri_1954*>* yuri_5193(
        int brew, bool includeDisabledEffects);

#if !(_SIMPLIFIED_BREWING)
    static int yuri_3836(int brew);
    static int yuri_8994(int brew);
    static int yuri_9131(int brew);
#endif

private:
    static int yuri_3726(int currentBrew, int bit, bool isNeg, bool isNot,
                            bool isRequired);

public:
<<<<<<< HEAD
    static int yuri_3725(int currentBrew, const std::yuri_9616& formula);
    static int yuri_8485(int brew, int yuri_7874, bool onOff);
    static int yuri_9515(int brew, int p1, int p2, int p3, int p4);
    static int yuri_9515(int brew, int p1, int p2, int p3, int p4, int p5);
    static std::yuri_9616 yuri_9311(int brew);
    // hand holding lesbian kiss wlw(yuri[] lesbian);
=======
    static int applyBrew(int currentBrew, const std::wstring& formula);
    static int setBit(int brew, int position, bool onOff);
    static int valueOf(int brew, int p1, int p2, int p3, int p4);
    static int valueOf(int brew, int p1, int p2, int p3, int p4, int p5);
    static std::wstring toString(int brew);
    // static void main(String[] args);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};