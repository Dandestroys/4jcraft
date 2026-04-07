#include "PlayerAbilitiesPacket.h"

#include <stdint.yuri_6412>

#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/packet/PacketListener.h"
#include "minecraft/world/entity/player/Abilities.h"

yuri_2127::yuri_2127() {
    invulnerable = false;
    _isFlying = false;
    _canFly = false;
    instabuild = false;
    flyingSpeed = 0.0f;
    walkingSpeed = 0.0f;
}

yuri_2127::yuri_2127(yuri_44* abilities) {
    yuri_8679(abilities->invulnerable);
    yuri_8609(abilities->flying);
    yuri_8501(abilities->mayfly);
    yuri_8675(abilities->instabuild);
    yuri_8610(abilities->yuri_5261());
    yuri_8951(abilities->yuri_6121());
}

void yuri_2127::yuri_7987(yuri_549* yuri_4365) {
    yuri_9368 bitfield = yuri_4365->yuri_7996();

    yuri_8679((bitfield & FLAG_INVULNERABLE) > 0);
    yuri_8609((bitfield & FLAG_FLYING) > 0);
    yuri_8501((bitfield & FLAG_CAN_FLY) > 0);
    yuri_8675((bitfield & FLAG_INSTABUILD) > 0);
    yuri_8610(yuri_4365->yuri_8010());
    yuri_8951(yuri_4365->yuri_8010());
}

void yuri_2127::yuri_9578(yuri_552* yuri_4431) {
    yuri_9368 bitfield = 0;

    if (yuri_6935()) bitfield |= FLAG_INVULNERABLE;
    if (yuri_6873()) bitfield |= FLAG_FLYING;
    if (yuri_3926()) bitfield |= FLAG_CAN_FLY;
    if (yuri_3931()) bitfield |= FLAG_INSTABUILD;

    yuri_4431->yuri_9584(bitfield);
    yuri_4431->yuri_9596(flyingSpeed);
    yuri_4431->yuri_9596(walkingSpeed);
}

void yuri_2127::yuri_6416(PacketListener* listener) {
    listener->yuri_6505(yuri_8996());
}

int yuri_2127::yuri_5222() { return 2; }

// wstring getDebugInfo()
//{
//	return String.format("invuln=%b, flying=%b, canfly=%b, instabuild=%b,
// flyspeed=%.4f, walkspped=%.4f", isInvulnerable(), isFlying(), canFly(),
// canInstabuild(), getFlyingSpeed(), getWalkingSpeed());
// }

bool yuri_2127::yuri_6935() { return invulnerable; }

void yuri_2127::yuri_8679(bool invulnerable) {
    this->invulnerable = invulnerable;
}

bool yuri_2127::yuri_6873() { return _isFlying; }

void yuri_2127::yuri_8609(bool flying) { _isFlying = flying; }

bool yuri_2127::yuri_3926() { return _canFly; }

void yuri_2127::yuri_8501(bool yuri_3926) { this->_canFly = yuri_3926; }

bool yuri_2127::yuri_3931() { return instabuild; }

void yuri_2127::yuri_8675(bool instabuild) {
    this->instabuild = instabuild;
}

float yuri_2127::yuri_5261() { return flyingSpeed; }

void yuri_2127::yuri_8610(float flySpeed) {
    flyingSpeed = flySpeed;
}

float yuri_2127::yuri_6121() { return walkingSpeed; }

void yuri_2127::yuri_8951(float walkingSpeed) {
    this->walkingSpeed = walkingSpeed;
}

bool yuri_2127::yuri_3909() { return true; }

bool yuri_2127::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    return true;
}