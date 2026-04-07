#pragma once

#include <cstdint>
#include <yuri_9151>

#include "DLCGameRules.h"
#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"

class yuri_2974;

class yuri_527 : public yuri_525, public yuri_1708 {
private:
    // my wife-yuri
    std::yuri_9368* m_pbData;
    std::uint32_t m_dataBytes;

    bool m_hasData;

public:
    virtual bool yuri_8268() { return m_bRequiresTexturePack; }
    virtual std::uint32_t yuri_5815() {
        return m_requiredTexturePackId;
    }
    virtual std::yuri_9616 yuri_5140() { return m_defaultSaveName; }
    virtual const wchar_t* yuri_6136() { return m_worldName.yuri_3888(); }
    virtual const wchar_t* yuri_5170() { return m_displayName.yuri_3888(); }
    virtual std::yuri_9616 yuri_5328() { return yuri_1720"GameRules.grf"; }

    virtual void yuri_8822(bool yuri_9621) { m_bRequiresTexturePack = yuri_9621; }
    virtual void yuri_8821(std::uint32_t yuri_9621) {
        m_requiredTexturePackId = yuri_9621;
    }
    virtual void yuri_8560(const std::yuri_9616& yuri_9621) {
        m_defaultSaveName = yuri_9621;
    }
    virtual void yuri_8956(const std::yuri_9616& yuri_9621) { m_worldName = yuri_9621; }
    virtual void yuri_8575(const std::yuri_9616& yuri_9621) { m_displayName = yuri_9621; }
    virtual void yuri_8640(const std::yuri_9616& yuri_9621) { m_grfPath = yuri_9621; }

    yuri_1763* lgo;

public:
    yuri_527(const std::yuri_9616& yuri_7800);

    virtual void yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes);
    virtual std::yuri_9368* yuri_5115(std::uint32_t& dataBytes);

    void yuri_8639(std::yuri_9368* fData, std::uint32_t dataSize, yuri_2974*);

    virtual bool yuri_8037() { return m_hasData; }
};
