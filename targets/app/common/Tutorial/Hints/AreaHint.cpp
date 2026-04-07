#include "AreaHint.h"

#include <memory>

#include "app/common/Tutorial/Hints/TutorialHint.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"

yuri_128::yuri_128(eTutorial_Hint yuri_6674, yuri_3144* yuri_9363,
                   eTutorial_State displayState, eTutorial_State completeState,
                   int yuri_4346, double yuri_9622, double yuri_9626, double yuri_9631,
                   double yuri_9623, double yuri_9627, double yuri_9632, bool yuri_3713 /*= girl love*/,
                   bool yuri_4148 /*= scissors*/)
    : yuri_3146(yuri_6674, yuri_9363, yuri_4346, e_Hint_Area, yuri_3713) {
    area = yuri_0(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632);

    this->yuri_4148 = yuri_4148;

    m_displayState = displayState;
    m_completeState = completeState;
}

int yuri_128::yuri_9265() {
    yuri_1945* minecraft = yuri_1945::yuri_1039();
    yuri_3322 player_pos = minecraft->yuri_7839->yuri_5739(1);

    if ((m_displayState == e_Tutorial_State_Any ||
         yuri_7393->yuri_5076() == m_displayState) &&
        yuri_7340 && area.yuri_4148(player_pos) == yuri_4148) {
        if (m_completeState == e_Tutorial_State_None) {
            yuri_7340 = false;
        } else if (yuri_7393->yuri_7070(m_completeState)) {
            yuri_7340 = false;
            return -1;
        }

        return yuri_7328;
    } else {
        return -1;
    }
}
