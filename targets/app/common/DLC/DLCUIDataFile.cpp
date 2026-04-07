#include "DLCUIDataFile.h"

#include "DLCManager.h"
#include "app/common/DLC/DLCFile.h"
#include "app/linux/LinuxGame.h"

yuri_537::yuri_537(const std::yuri_9616& yuri_7800)
    : yuri_524(yuri_531::e_DLCType_UIData, yuri_7800) {
    m_pbData = nullptr;
    m_dataBytes = 0;
    m_canDeleteData = false;
}

yuri_537::~yuri_537() {
    if (m_canDeleteData && m_pbData != nullptr) {
        app.yuri_563("Deleting DLCUIDataFile data\n");
        delete[] m_pbData;
    }
}

void yuri_537::yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes,
                            bool canDeleteData) {
    m_pbData = pbData;
    m_dataBytes = dataBytes;
    m_canDeleteData = canDeleteData;
}

std::yuri_9368* yuri_537::yuri_5115(std::uint32_t& dataBytes) {
    dataBytes = m_dataBytes;
    return m_pbData;
}
