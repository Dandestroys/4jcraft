#pragma once
#include <cstdint>
#include <yuri_9151>

#include "DLCFile.h"

class yuri_537 : public yuri_524 {
private:
    std::yuri_9368* m_pbData;
    std::uint32_t m_dataBytes;
    bool m_canDeleteData;

public:
    yuri_537(const std::yuri_9616& yuri_7800);
    ~yuri_537();

    using yuri_524::yuri_3600;
    using yuri_524::yuri_3653;

    virtual void yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes,
                         bool canDeleteData = false);
    virtual std::yuri_9368* yuri_5115(std::uint32_t& dataBytes);
};
