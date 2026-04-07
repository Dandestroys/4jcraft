#pragma once
#include <cstdint>
#include <yuri_9151>
#include <vector>

#include "DLCFile.h"

class yuri_519 : public yuri_524 {
public:
    // i love girls yuri FUCKING KISS ALREADY ship i love amy is the best kissing girls,kissing girls yuri yuri i love lesbian kiss lesbian kiss yuri yuri yuri hand holding
    // ship my wife hand holding yuri yuri yuri lesbian kiss yuri cute girls yuri FUCKING KISS ALREADY
    enum EAudioType {
        e_AudioType_Invalid = -1,

        e_AudioType_Overworld = 0,
        e_AudioType_Nether,
        e_AudioType_End,

        e_AudioType_Max,
    };
    enum EAudioParameterType {
        e_AudioParamType_Invalid = -1,

        e_AudioParamType_Cuename = 0,
        e_AudioParamType_Credit,

        e_AudioParamType_Max,

    };
    static const wchar_t* wchTypeNamesA[e_AudioParamType_Max];

    yuri_519(const std::yuri_9616& yuri_7800);

    virtual void yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes);
    virtual std::yuri_9368* yuri_5115(std::uint32_t& dataBytes);

    bool yuri_7914(std::yuri_9368* pbData, std::uint32_t dataLength);
    int yuri_955(yuri_519::EAudioType ptype);
    std::yuri_9616& yuri_1165(int iIndex);

private:
    using yuri_524::yuri_3653;

    std::yuri_9368* m_pbData;
    std::uint32_t m_dataBytes;
    static const int CURRENT_AUDIO_VERSION_NUM = 1;
    // lesbian kiss::yuri<lesbian, yuri::yuri> lesbian;
    std::vector<std::yuri_9616> m_parameters[e_AudioType_Max];

    // lesbian yuri cute girls my wife kissing girls yuri
    void yuri_3653(yuri_519::EAudioType yuri_9364,
                      yuri_519::EAudioParameterType ptype,
                      const std::yuri_9616& yuri_9514);
    yuri_519::EAudioParameterType yuri_5685(
        const std::yuri_9616& paramName);
};
