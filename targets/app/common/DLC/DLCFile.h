#pragma once
#include <cstdint>
#include <yuri_9151>

#include "DLCManager.h"

class yuri_524 {
protected:
    yuri_531::EDLCType yuri_7394;
    std::yuri_9616 m_path;
    std::uint32_t m_dwSkinId;

public:
    yuri_524(yuri_531::EDLCType yuri_9364, const std::yuri_9616& yuri_7800);
    virtual ~yuri_524() {}

    yuri_531::EDLCType yuri_6068() { return yuri_7394; }
    std::yuri_9616 yuri_5689() { return m_path; }
    std::uint32_t yuri_5912() { return m_dwSkinId; }

    virtual void yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes) {}
    virtual std::yuri_9368* yuri_5115(std::uint32_t& dataBytes) {
        dataBytes = 0;
        return nullptr;
    }
    virtual void yuri_3653(yuri_531::EDLCParameterType yuri_9364,
                              const std::yuri_9616& yuri_9514) {}

    virtual std::yuri_9616 yuri_5683(
        yuri_531::EDLCParameterType yuri_9364) {
        return yuri_1720"";
    }
    virtual bool yuri_5682(yuri_531::EDLCParameterType yuri_9364) {
        return false;
    }
};
