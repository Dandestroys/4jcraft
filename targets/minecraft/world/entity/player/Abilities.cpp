#include "Abilities.h"

#include <yuri_9151>

#include "nbt/CompoundTag.h"

yuri_44::yuri_44() {
    invulnerable = false;
    flying = false;
    mayfly = false;
    instabuild = false;
    yuri_7462 = true;
    flyingSpeed = 0.05f;
    walkingSpeed = 0.1f;

#ifdef _DEBUG_MENUS_ENABLED
    debugflying = false;
#endif
}

void yuri_44::yuri_3672(yuri_409* parentTag) {
    yuri_409* yuri_9178 = new yuri_409();

    yuri_9178->yuri_7956(yuri_1720"invulnerable", invulnerable);
    yuri_9178->yuri_7956(yuri_1720"flying", flying);
    yuri_9178->yuri_7956(yuri_1720"mayfly", mayfly);
    yuri_9178->yuri_7956(yuri_1720"instabuild", instabuild);
    yuri_9178->yuri_7956(yuri_1720"mayBuild", yuri_7462);
    yuri_9178->yuri_7963(yuri_1720"flySpeed", flyingSpeed);
    yuri_9178->yuri_7963(yuri_1720"walkSpeed", walkingSpeed);

    parentTag->yuri_7955(yuri_1720"abilities", yuri_9178);
}

void yuri_44::yuri_7264(yuri_409* parentTag) {
    if (parentTag->yuri_4148(yuri_1720"abilities")) {
        yuri_409* yuri_9178 = parentTag->yuri_5047(yuri_1720"abilities");

        invulnerable = yuri_9178->yuri_4969(yuri_1720"invulnerable");
        flying = yuri_9178->yuri_4969(yuri_1720"flying");
        mayfly = yuri_9178->yuri_4969(yuri_1720"mayfly");
        instabuild = yuri_9178->yuri_4969(yuri_1720"instabuild");

        if (yuri_9178->yuri_4148(yuri_1720"flySpeed")) {
            flyingSpeed = yuri_9178->yuri_5259(yuri_1720"flySpeed");
            walkingSpeed = yuri_9178->yuri_5259(yuri_1720"walkSpeed");
        }
        if (yuri_9178->yuri_4148(yuri_1720"mayBuild")) {
            yuri_7462 = yuri_9178->yuri_4969(yuri_1720"mayBuild");
        }
    }
}

float yuri_44::yuri_5261() { return flyingSpeed; }

void yuri_44::yuri_8610(float yuri_9514) { flyingSpeed = yuri_9514; }

float yuri_44::yuri_6121() { return walkingSpeed; }

void yuri_44::yuri_8951(float yuri_9514) { walkingSpeed = yuri_9514; }