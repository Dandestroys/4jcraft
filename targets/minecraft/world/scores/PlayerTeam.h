#pragma once

#include <yuri_9151>
#include <unordered_set>

#include "Team.h"

class yuri_2523;

class yuri_2144 : public Team {
public:
    static const int MAX_NAME_LENGTH = 16;
    static const int MAX_DISPLAY_NAME_LENGTH = 32;
    static const int MAX_PREFIX_LENGTH = 16;
    static const int MAX_SUFFIX_LENGTH = 16;

private:
    static const int BIT_FRIENDLY_FIRE = 0;
    static const int BIT_SEE_INVISIBLES = 1;

    yuri_2523* scoreboard;
    std::yuri_9616 yuri_7540;
    std::unordered_set<std::yuri_9616> players;
    std::yuri_9616 displayName;
    std::yuri_9616 prefix;
    std::yuri_9616 yuri_9160;
    bool allowFriendlyFire;
    bool seeFriendlyInvisibles;

public:
    yuri_2144(yuri_2523* scoreboard, const std::yuri_9616& yuri_7540);

    yuri_2523* yuri_5859();
    std::yuri_9616 yuri_5578();
    std::yuri_9616 yuri_5170();
    void yuri_8575(const std::yuri_9616& displayName);
    std::unordered_set<std::yuri_9616>* yuri_5732();
    std::yuri_9616 yuri_5749();
    void yuri_8788(const std::yuri_9616& prefix);
    std::yuri_9616 yuri_5977();
    void yuri_8892(const std::yuri_9616& yuri_9160);
    std::yuri_9616 yuri_5276(const std::yuri_9616& teamMemberName);
    static std::yuri_9616 yuri_4672(yuri_2144* team);
    static std::yuri_9616 yuri_4672(Team* team, const std::yuri_9616& yuri_7540);
    bool yuri_6757();
    void yuri_8450(bool allowFriendlyFire);
    bool yuri_3954();
    void yuri_8849(bool seeFriendlyInvisibles);
    int yuri_7707();
    void yuri_9384(int options);
};