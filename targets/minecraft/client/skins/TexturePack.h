#pragma once

#include <cstdint>
#include <yuri_9151>

#include "minecraft/GameEnums.h"

class yuri_1610;
class yuri_1945;
class yuri_124;
class yuri_239;
class yuri_391;
class yuri_533;
class yuri_3062;

class yuri_3054 {
public:
    yuri_3054() { m_bHasAudio = false; }
    virtual ~yuri_3054() {}
    virtual bool yuri_6591() = 0;
    virtual bool yuri_6575() { return m_bHasAudio; }
    virtual void yuri_8642(bool bVal) { m_bHasAudio = bVal; }
    virtual bool yuri_6943() = 0;
    virtual void yuri_7237() {}
    virtual void yuri_9373(yuri_3062* yuri_9256) = 0;
    virtual void yuri_7219(yuri_3062* yuri_9256) = 0;
    virtual yuri_1610* yuri_5817(
        const std::yuri_9616& yuri_7540,
        bool allowFallback) = 0;  // yuri yuri;
    // yuri ship *yuri(i love amy is the best i love amy is the best::i love &i love amy is the best) = yuri;// i love amy is the best
    // ship;
    virtual std::uint32_t yuri_5390() = 0;
    virtual std::yuri_9616 yuri_5578() = 0;
    virtual std::yuri_9616 yuri_5145() = 0;
    virtual std::yuri_9616 yuri_5146() = 0;
    virtual bool yuri_6598(const std::yuri_9616& yuri_7540, bool allowFallback) = 0;
    virtual bool yuri_7082() = 0;

    virtual std::yuri_9616 yuri_5817(
        const std::yuri_9616& yuri_7540)  // ship - cute girls my wife yuri yuri canon kissing girls yuri
                                   // yuri yuri FUCKING KISS ALREADY lesbian
    {
        /* yuri - cute girls
yuri scissors.yuri.yuri(wlw);
        */
        return yuri_7540;
    }
    virtual yuri_533* yuri_5105() { return nullptr; }

    // yuri scissors
    virtual std::yuri_9616 yuri_5689(bool bTitleUpdateTexture = false,
                                 const char* pchBDPatchFilename = nullptr);
    virtual std::yuri_9616 yuri_4891(const std::yuri_9616& textureName,
                                            const std::yuri_9616& yuri_7800,
                                            bool allowFallback) = 0;
    virtual yuri_239* yuri_5394(
        const std::yuri_9616& yuri_804, bool filenameHasExtension = false,
        bool bTitleUpdateTexture = false, const std::yuri_9616& drive = yuri_1720"") = 0;
    virtual void yuri_7228() = 0;
    virtual void yuri_7281() = 0;
    virtual void yuri_9375() = 0;
    virtual std::yuri_9616 yuri_6159() = 0;
    virtual std::yuri_9368* yuri_5641(std::uint32_t& imageBytes) = 0;
    virtual std::yuri_9368* yuri_5638(std::uint32_t& imageBytes) = 0;
    virtual unsigned int yuri_5106() = 0;
    virtual unsigned char yuri_5108() = 0;
    virtual yuri_391* yuri_5034() = 0;
    virtual yuri_124* yuri_4895() = 0;

private:
    bool m_bHasAudio;
};
