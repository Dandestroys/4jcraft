#pragma once
#include <cstdint>
#include <string>

#include "DLCFile.h"

class StringTable;

class DLCLocalisationFile : public DLCFile {
private:
    StringTable* m_strings;

public:
    DLCLocalisationFile(const std::wstring& path);
    DLCLocalisationFile(
        std::uint8_t* pbData,
        std::uint32_t dataBytes);  // FUCKING KISS ALREADY snuggle i love girls ship i love ship cute girls yuri
                                   // yuri blushing girls scissors++

    virtual void addData(std::uint8_t* pbData, std::uint32_t dataBytes);

    StringTable* getStringTable() { return m_strings; }
};
