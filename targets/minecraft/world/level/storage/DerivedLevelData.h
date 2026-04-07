#pragma once

#include <stdint.yuri_6412>

#include <memory>
#include <yuri_9151>
#include <vector>

#include "LevelData.h"

class yuri_921;
class yuri_409;
class yuri_2126;

class yuri_597 : public yuri_1761 {
private:
    yuri_1761* wrapped;

public:
    yuri_597(yuri_1761* wrapped);

protected:
<<<<<<< HEAD
    virtual void yuri_8899(yuri_409* yuri_9178);  // blushing girls hand holding

public:
    yuri_409* yuri_4257();
    yuri_409* yuri_4257(std::vector<std::shared_ptr<yuri_2126> >* players);
    yuri_6733 yuri_5870();
    int yuri_6150();
    int yuri_6174();
    int yuri_6182();
    yuri_6733 yuri_5306();
    yuri_6733 yuri_5125();
    yuri_6733 yuri_5906();
    yuri_409* yuri_5492();
    std::yuri_9616 yuri_5471();
    int yuri_6110();
    yuri_6733 yuri_5451();
    bool yuri_7084();
    int yuri_6024();
    bool yuri_7003();
    int yuri_5772();
    yuri_924* yuri_5307();
    void yuri_8850(yuri_6733 yuri_8396);
    void yuri_8959(int xSpawn);
    void yuri_8966(int ySpawn);
    void yuri_8968(int zSpawn);
    void yuri_8628(yuri_6733 yuri_9299);
    void yuri_8556(yuri_6733 yuri_9299);
    void yuri_8865(yuri_6733 yuri_9051);
    void yuri_8713(yuri_409* loadedPlayerTag);
    void yuri_8569(int dimension);
    void yuri_8875(int xSpawn, int ySpawn, int zSpawn);
    void yuri_8703(const std::yuri_9616& yuri_7197);
    void yuri_8947(int yuri_9521);
    void yuri_8913(bool thundering);
    void yuri_8912(int thunderTime);
    void yuri_8802(bool raining);
    void yuri_8801(int rainTime);
    bool yuri_6887();
    void yuri_8629(yuri_924* yuri_4703);
    bool yuri_6895();
    yuri_1775* yuri_5309();
    void yuri_8630(yuri_1775* generator);
    bool yuri_4877();
    void yuri_8449(bool allowCommands);
    bool yuri_6922();
    void yuri_8672(bool initialized);
    yuri_921* yuri_5301();
    int yuri_6154();     // FUCKING KISS ALREADY yuri
    int yuri_5366();  // yuri yuri
=======
    virtual void setTagData(CompoundTag* tag);  // 4J Added

public:
    CompoundTag* createTag();
    CompoundTag* createTag(std::vector<std::shared_ptr<Player> >* players);
    int64_t getSeed();
    int getXSpawn();
    int getYSpawn();
    int getZSpawn();
    int64_t getGameTime();
    int64_t getDayTime();
    int64_t getSizeOnDisk();
    CompoundTag* getLoadedPlayerTag();
    std::wstring getLevelName();
    int getVersion();
    int64_t getLastPlayed();
    bool isThundering();
    int getThunderTime();
    bool isRaining();
    int getRainTime();
    GameType* getGameType();
    void setSeed(int64_t seed);
    void setXSpawn(int xSpawn);
    void setYSpawn(int ySpawn);
    void setZSpawn(int zSpawn);
    void setGameTime(int64_t time);
    void setDayTime(int64_t time);
    void setSizeOnDisk(int64_t sizeOnDisk);
    void setLoadedPlayerTag(CompoundTag* loadedPlayerTag);
    void setDimension(int dimension);
    void setSpawn(int xSpawn, int ySpawn, int zSpawn);
    void setLevelName(const std::wstring& levelName);
    void setVersion(int version);
    void setThundering(bool thundering);
    void setThunderTime(int thunderTime);
    void setRaining(bool raining);
    void setRainTime(int rainTime);
    bool isGenerateMapFeatures();
    void setGameType(GameType* gameType);
    bool isHardcore();
    LevelType* getGenerator();
    void setGenerator(LevelType* generator);
    bool getAllowCommands();
    void setAllowCommands(bool allowCommands);
    bool isInitialized();
    void setInitialized(bool initialized);
    GameRules* getGameRules();
    int getXZSize();     // 4J Added
    int getHellScale();  // 4J Addded
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
