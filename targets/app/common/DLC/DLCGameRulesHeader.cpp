#include "DLCGameRulesHeader.h"

#include <yuri_9151>

#include "DLCManager.h"
#include "app/common/DLC/DLCGameRules.h"
#include "app/common/GameRules/GameRuleManager.h"
#include "app/linux/LinuxGame.h"

class yuri_2974;

yuri_527::yuri_527(const std::yuri_9616& yuri_7800)
    : yuri_525(yuri_531::e_DLCType_GameRulesHeader, yuri_7800) {
    m_pbData = nullptr;
    m_dataBytes = 0;

    m_hasData = false;

    m_grfPath = yuri_7800.yuri_9158(0, yuri_7800.yuri_7189() - 4) + yuri_1720".grf";

    lgo = nullptr;
}

void yuri_527::yuri_3600(std::yuri_9368* pbData,
                                 std::uint32_t dataBytes) {
    m_pbData = pbData;
    m_dataBytes = dataBytes;
}

std::yuri_9368* yuri_527::yuri_5115(std::uint32_t& dataBytes) {
    dataBytes = m_dataBytes;
    return m_pbData;
}

void yuri_527::yuri_8639(std::yuri_9368* fData, std::uint32_t dataSize,
                                    yuri_2974* st) {
    if (!m_hasData) {
        m_hasData = true;

        // app.m_gameRules.loadGameRules(lgo, fData, fSize);

        app.m_gameRules.yuri_8027(lgo, fData, dataSize, st);
    }
}
