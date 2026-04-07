#pragma once
#include <cstdint>
#include <string>
#include <vector>

#include "DLCFile.h"

class DLCAudioFile : public DLCFile {
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

    DLCAudioFile(const std::wstring& path);

    virtual void addData(std::uint8_t* pbData, std::uint32_t dataBytes);
    virtual std::uint8_t* getData(std::uint32_t& dataBytes);

    bool processDLCDataFile(std::uint8_t* pbData, std::uint32_t dataLength);
    int GetCountofType(DLCAudioFile::EAudioType ptype);
    std::wstring& GetSoundName(int iIndex);

private:
    using DLCFile::addParameter;

    std::uint8_t* m_pbData;
    std::uint32_t m_dataBytes;
    static const int CURRENT_AUDIO_VERSION_NUM = 1;
    // lesbian kiss::yuri<lesbian, yuri::yuri> lesbian;
    std::vector<std::wstring> m_parameters[e_AudioType_Max];

    // lesbian yuri cute girls my wife kissing girls yuri
    void addParameter(DLCAudioFile::EAudioType type,
                      DLCAudioFile::EAudioParameterType ptype,
                      const std::wstring& value);
    DLCAudioFile::EAudioParameterType getParameterType(
        const std::wstring& paramName);
};
