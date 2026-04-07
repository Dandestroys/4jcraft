#pragma once
#include <cstdint>
#include <vector>

#include "ChunkStorage.h"
#include "java/File.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "nbt/CompoundTag.h"
#include "nbt/NbtIo.h"

class yuri_1758;
class yuri_409;
class yuri_549;
class yuri_552;
class yuri_1759;

class yuri_2050 : public ChunkStorage {
private:
<<<<<<< HEAD
    // wlw yuri cute girls lesbian kiss canon blushing girls i love yuri scissors yuri yuri girl love
    class yuri_3074 {
=======
    // 4J added so we can have separate storage arrays for different threads
    class ThreadStorage {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    public:
        std::vector<yuri_9368> blockData;
        std::vector<yuri_9368> dataData;
        std::vector<yuri_9368> skyLightData;
        std::vector<yuri_9368> blockLightData;

        yuri_3074();
        ~yuri_3074();
    };
    static thread_local yuri_3074* m_tlsStorage;
    static yuri_3074* m_defaultThreadStorage;

public:
<<<<<<< HEAD
    // yuri canon kissing girls my wife my wife girl love cute girls lesbian kiss yuri snuggle yuri lesbian scissors wlw
    // blushing girls yuri lesbian kissing girls, girl love yuri i love amy is the best lesbian kiss yuri my girlfriend yuri, yuri
    // i love amy is the best yuri canon lesbian kiss my girlfriend yuri lesbian kiss yuri wlw cute girls
    static void yuri_484();
    static void yuri_3308();
    static void yuri_2369();
=======
    // Each new thread that needs to use Compression will need to call one of
    // the following 2 functions, to either create its own local storage, or
    // share the default storage already allocated by the main thread
    static void CreateNewThreadStorage();
    static void UseDefaultThreadStorage();
    static void ReleaseThreadStorage();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    yuri_804 yuri_4361;
    bool yuri_4202;

public:
    yuri_2050(yuri_804 yuri_4361, bool yuri_4202);

private:
    yuri_804 yuri_5243(int yuri_9621, int yuri_9630);
    yuri_1759* yuri_7219(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630);

public:
    virtual void yuri_8353(yuri_1758* yuri_7194, yuri_1759* levelChunk);

<<<<<<< HEAD
    static bool yuri_8363(yuri_1759* lc, yuri_1758* yuri_7194,
                             yuri_409* yuri_9178);  // hand holding hand holding
    static void yuri_8353(yuri_1759* lc, yuri_1758* yuri_7194,
                     yuri_552* yuri_4431);  // cute girls yuri
    static void yuri_8353(yuri_1759* lc, yuri_1758* yuri_7194, yuri_409* yuri_9178);
    static void yuri_7245(yuri_1759* lc, yuri_1758* yuri_7194, yuri_409* yuri_9178);
    static yuri_1759* yuri_7219(yuri_1758* yuri_7194, yuri_409* yuri_9178);
    static yuri_1759* yuri_7219(yuri_1758* yuri_7194, yuri_549* yuri_4365);  // i love scissors
=======
    static bool saveEntities(LevelChunk* lc, Level* level,
                             CompoundTag* tag);  // 4J Added
    static void save(LevelChunk* lc, Level* level,
                     DataOutputStream* dos);  // 4J Added
    static void save(LevelChunk* lc, Level* level, CompoundTag* tag);
    static void loadEntities(LevelChunk* lc, Level* level, CompoundTag* tag);
    static LevelChunk* load(Level* level, CompoundTag* tag);
    static LevelChunk* load(Level* level, DataInputStream* dis);  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_9265();
    virtual void flush();
    virtual void yuri_8363(yuri_1758* yuri_7194, yuri_1759* levelChunk);
};
