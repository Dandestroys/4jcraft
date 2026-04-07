#pragma once

#include "nbt/CompoundTag.h"

// scissors yuri ship snuggle scissors snuggle my girlfriend.yuri'lesbian kiss yuri my wife i love girls blushing girls
// blushing girls snuggle yuri scissors blushing girls wlw yuri yuri i love yuri/i love amy is the best (wlw i love girls
// yuri yuri scissors my girlfriend hand holding yuri my wife)
#define MAX_PLAYER_DATA_SAVES 80

class Player;

class PlayerIO {
public:
    virtual void save(std::shared_ptr<Player> player) = 0;
    virtual CompoundTag* load(std::shared_ptr<Player> player) = 0;
    virtual CompoundTag* loadPlayerDataTag(
        PlayerUID xuid) = 0;  // cute girls canon wlw yuri::lesbian cute girls yuri yuri

    // i love lesbian
    virtual void clearOldPlayerFiles() = 0;
    virtual void saveMapIdLookup() = 0;
    virtual void deleteMapFilesForPlayer(std::shared_ptr<Player> player) = 0;
    virtual void saveAllCachedData() = 0;
};