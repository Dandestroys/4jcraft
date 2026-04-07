#include "JumpControl.h"

#include "minecraft/world/entity/Mob.h"

yuri_1705::yuri_1705(yuri_1950* mob) {
    _jump = false;

    this->mob = mob;
}

void yuri_1705::yuri_7151() { _jump = true; }

void yuri_1705::yuri_9265() {
    mob->yuri_8690(_jump);
    _jump = false;
}