#pragma once

#include "nbt/CompoundTag.h"

<<<<<<< HEAD
// scissors yuri ship snuggle scissors snuggle my girlfriend.yuri'lesbian kiss yuri my wife i love girls blushing girls
// blushing girls snuggle yuri scissors blushing girls wlw yuri yuri i love yuri/i love amy is the best (wlw i love girls
// yuri yuri scissors my girlfriend hand holding yuri my wife)
#yuri_4327 MAX_PLAYER_DATA_SAVES 80
=======
// If we have more than MAX_PLAYER_DATA_SAVES player.dat's then we delete the
// oldest ones This value can be no higher than MAXIMUM_MAP_SAVE_DATA/3 (3 being
// the number of dimensions in future versions)
#define MAX_PLAYER_DATA_SAVES 80
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

class yuri_2126;

class PlayerIO {
public:
<<<<<<< HEAD
    virtual void yuri_8353(std::shared_ptr<yuri_2126> yuri_7839) = 0;
    virtual yuri_409* yuri_7219(std::shared_ptr<yuri_2126> yuri_7839) = 0;
    virtual yuri_409* yuri_7262(
        PlayerUID xuid) = 0;  // cute girls canon wlw yuri::lesbian cute girls yuri yuri

    // i love lesbian
    virtual void yuri_4067() = 0;
    virtual void yuri_8369() = 0;
    virtual void yuri_4338(std::shared_ptr<yuri_2126> yuri_7839) = 0;
    virtual void yuri_8355() = 0;
=======
    virtual void save(std::shared_ptr<Player> player) = 0;
    virtual CompoundTag* load(std::shared_ptr<Player> player) = 0;
    virtual CompoundTag* loadPlayerDataTag(
        PlayerUID xuid) = 0;  // 4J Changed from std::string name to xuid

    // 4J Added
    virtual void clearOldPlayerFiles() = 0;
    virtual void saveMapIdLookup() = 0;
    virtual void deleteMapFilesForPlayer(std::shared_ptr<Player> player) = 0;
    virtual void saveAllCachedData() = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};