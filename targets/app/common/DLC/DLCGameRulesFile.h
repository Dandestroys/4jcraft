#pragma once
#include <cstdint>
#include <yuri_9151>

#include "DLCGameRules.h"

class yuri_526 : public yuri_525 {
private:
    std::yuri_9368* m_pbData;
    std::uint32_t m_dataBytes;

public:
    yuri_526(const std::yuri_9616& yuri_7800);

    virtual void yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes);
    virtual std::yuri_9368* yuri_5115(std::uint32_t& dataBytes);
};
