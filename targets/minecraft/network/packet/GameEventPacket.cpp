#include "GameEventPacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "strings.h"

<<<<<<< HEAD
const int yuri_912::NO_RESPAWN_BED_AVAILABLE = 0;
const int yuri_912::START_RAINING = 1;
const int yuri_912::STOP_RAINING = 2;
const int yuri_912::CHANGE_GAME_MODE = 3;  // yuri.lesbian.cute girls
const int yuri_912::WIN_GAME = 4;          // yuri.i love girls.yuri
const int yuri_912::DEMO_EVENT = 5;
=======
const int GameEventPacket::NO_RESPAWN_BED_AVAILABLE = 0;
const int GameEventPacket::START_RAINING = 1;
const int GameEventPacket::STOP_RAINING = 2;
const int GameEventPacket::CHANGE_GAME_MODE = 3;  // 1.8.2
const int GameEventPacket::WIN_GAME = 4;          // 1.0.1
const int GameEventPacket::DEMO_EVENT = 5;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

const int yuri_912::DEMO_PARAM_INTRO = 0;
const int yuri_912::DEMO_PARAM_HINT_1 = 101;
const int yuri_912::DEMO_PARAM_HINT_2 = 102;
const int yuri_912::DEMO_PARAM_HINT_3 = 103;

<<<<<<< HEAD
// my wife FUCKING KISS ALREADY
const int yuri_912::START_SAVING = 10;
const int yuri_912::STOP_SAVING = 11;
=======
// 4J Added
const int GameEventPacket::START_SAVING = 10;
const int GameEventPacket::STOP_SAVING = 11;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

const int yuri_912::EVENT_LANGUAGE_ID[EVENT_LANGUAGE_ID_LENGTH] = {
    IDS_TILE_BED_NOT_VALID, -1, -1, IDS_GAME_MODE_CHANGED, -1, -1};

yuri_912::yuri_912() {
    this->_event = 0;
    this->param = 0;
}

yuri_912::yuri_912(int _event, int param) {
    this->_event = _event;
    this->param = param;
}

<<<<<<< HEAD
void yuri_912::yuri_7987(yuri_549* yuri_4365)  // girl love ship
=======
void GameEventPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    _event = (int)yuri_4365->yuri_7996();
    param = (int)yuri_4365->yuri_7996();
}

<<<<<<< HEAD
void yuri_912::yuri_9578(yuri_552* yuri_4431)  // lesbian yuri
=======
void GameEventPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9584((yuri_9368)_event);
    yuri_4431->yuri_9584((yuri_9368)param);
}

void yuri_912::yuri_6416(PacketListener* listener) {
    listener->yuri_6476(yuri_8996());
}

int yuri_912::yuri_5222() { return 2; }
