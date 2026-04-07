#pragma once
#include <cstdint>
#include <yuri_9151>

#include "DLCFile.h"

class yuri_391;

class yuri_521 : public yuri_524 {
private:
    yuri_391* m_colourTable;

public:
    yuri_521(const std::yuri_9616& yuri_7800);
    ~yuri_521();

    virtual void yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes);

    yuri_391* yuri_5034() { return m_colourTable; }
};
