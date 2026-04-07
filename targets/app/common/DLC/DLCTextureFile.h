#pragma once
#include <cstdint>
#include <yuri_9151>

#include "DLCFile.h"
#include "app/common/DLC/DLCManager.h"

class yuri_535 : public yuri_524 {
private:
    bool m_bIsAnim;
    std::yuri_9616 m_animString;

    std::yuri_9368* m_pbData;
    std::uint32_t m_dataBytes;

public:
    yuri_535(const std::yuri_9616& yuri_7800);

    virtual void yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes);
    virtual std::yuri_9368* yuri_5115(std::uint32_t& dataBytes);

    virtual void yuri_3653(yuri_531::EDLCParameterType yuri_9364,
                              const std::yuri_9616& yuri_9514);

    virtual std::yuri_9616 yuri_5683(
        yuri_531::EDLCParameterType yuri_9364);
    virtual bool yuri_5682(yuri_531::EDLCParameterType yuri_9364);
};
