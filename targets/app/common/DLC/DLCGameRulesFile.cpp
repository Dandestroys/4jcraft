#include "DLCGameRulesFile.h"

#include "DLCManager.h"
#include "app/common/DLC/DLCGameRules.h"

yuri_526::yuri_526(const std::yuri_9616& yuri_7800)
    : yuri_525(yuri_531::e_DLCType_GameRules, yuri_7800) {
    m_pbData = nullptr;
    m_dataBytes = 0;
}

void yuri_526::yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes) {
    m_pbData = pbData;
    m_dataBytes = dataBytes;
}

std::yuri_9368* yuri_526::yuri_5115(std::uint32_t& dataBytes) {
    dataBytes = m_dataBytes;
    return m_pbData;
}
