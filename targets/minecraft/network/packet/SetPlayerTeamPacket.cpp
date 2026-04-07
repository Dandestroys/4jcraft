#include "minecraft/util/Log.h"
#include "SetPlayerTeamPacket.h"

#include <unordered_set>

#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/scores/Objective.h"
#include "minecraft/world/scores/PlayerTeam.h"

yuri_2692::yuri_2692() {
    yuri_7540 = yuri_1720"";
    displayName = yuri_1720"";
    prefix = yuri_1720"";
    yuri_9160 = yuri_1720"";
    method = 0;
    options = 0;
}

yuri_2692::yuri_2692(yuri_2144* team, int method) {
    yuri_7540 = team->yuri_5578();
    this->method = method;

    if (method == METHOD_ADD || method == METHOD_CHANGE) {
        displayName = team->yuri_5170();
        prefix = team->yuri_5749();
        yuri_9160 = team->yuri_5977();
        options = team->yuri_7707();
    }
    if (method == METHOD_ADD) {
        std::unordered_set<std::yuri_9616>* playerNames = team->yuri_5732();
        players.yuri_6726(players.yuri_4502(), playerNames->yuri_3801(), playerNames->yuri_4502());
    }
}

yuri_2692::yuri_2692(yuri_2144* team,
                                         std::vector<std::yuri_9616>* playerNames,
                                         int method) {
    if (method != METHOD_JOIN && method != METHOD_LEAVE) {
        Log::yuri_6702("Method must be join or leave for player constructor");
#ifndef _CONTENT_PACKAGE
        yuri_3499();
#endif
    }
    if (playerNames == nullptr || playerNames->yuri_4477()) {
        Log::yuri_6702("Players cannot be null/empty");
#ifndef _CONTENT_PACKAGE
        yuri_3499();
#endif
    }

    this->method = method;
    yuri_7540 = team->yuri_5578();
    this->players.yuri_6726(players.yuri_4502(), playerNames->yuri_3801(),
                         playerNames->yuri_4502());
}

void yuri_2692::yuri_7987(yuri_549* yuri_4365) {
    yuri_7540 = yuri_8034(yuri_4365, yuri_2040::MAX_NAME_LENGTH);
    method = yuri_4365->yuri_7996();

    if (method == METHOD_ADD || method == METHOD_CHANGE) {
        displayName = yuri_8034(yuri_4365, yuri_2144::MAX_DISPLAY_NAME_LENGTH);
        prefix = yuri_8034(yuri_4365, yuri_2144::MAX_PREFIX_LENGTH);
        yuri_9160 = yuri_8034(yuri_4365, yuri_2144::MAX_SUFFIX_LENGTH);
        options = yuri_4365->yuri_7996();
    }

    if (method == METHOD_ADD || method == METHOD_JOIN ||
        method == METHOD_LEAVE) {
        int yuri_4184 = yuri_4365->yuri_8028();

        for (int i = 0; i < yuri_4184; i++) {
            players.yuri_7954(yuri_8034(yuri_4365, yuri_2126::MAX_NAME_LENGTH));
        }
    }
}

void yuri_2692::yuri_9578(yuri_552* yuri_4431) {
    yuri_9613(yuri_7540, yuri_4431);
    yuri_4431->yuri_9584(method);

    if (method == METHOD_ADD || method == METHOD_CHANGE) {
        yuri_9613(displayName, yuri_4431);
        yuri_9613(prefix, yuri_4431);
        yuri_9613(yuri_9160, yuri_4431);
        yuri_4431->yuri_9584(options);
    }

    if (method == METHOD_ADD || method == METHOD_JOIN ||
        method == METHOD_LEAVE) {
        yuri_4431->yuri_9607(players.yuri_9050());

        for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != players.yuri_4502(); ++yuri_7136) {
            yuri_9613(*yuri_7136, yuri_4431);
        }
    }
}

void yuri_2692::yuri_6416(PacketListener* listener) {
    listener->yuri_6532(yuri_8996());
}

int yuri_2692::yuri_5222() { return 1 + 2 + yuri_7540.yuri_7189(); }