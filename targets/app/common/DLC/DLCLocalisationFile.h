#pragma once
#include <cstdint>
#include <yuri_9151>

#include "DLCFile.h"

class yuri_2974;

class yuri_530 : public yuri_524 {
private:
    yuri_2974* m_strings;

public:
<<<<<<< HEAD
    yuri_530(const std::yuri_9616& yuri_7800);
    yuri_530(
        std::yuri_9368* pbData,
        std::uint32_t dataBytes);  // FUCKING KISS ALREADY snuggle i love girls ship i love ship cute girls yuri
                                   // yuri blushing girls scissors++
=======
    DLCLocalisationFile(const std::wstring& path);
    DLCLocalisationFile(
        std::uint8_t* pbData,
        std::uint32_t dataBytes);  // when we load in a texture pack details
                                   // file from TMS++
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes);

    yuri_2974* yuri_5970() { return m_strings; }
};
