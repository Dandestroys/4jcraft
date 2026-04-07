#pragma once
#include <cstdint>
#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "DLCFile.h"
#include "app/common/DLC/DLCManager.h"
#include "minecraft/client/model/SkinBox.h"
#include "minecraft/client/model/HumanoidModel.h"

class yuri_534 : public yuri_524 {
private:
    std::yuri_9616 m_displayName;
    std::yuri_9616 m_themeName;
    std::yuri_9616 m_cape;
    unsigned int m_uiAnimOverrideBitmask;
    bool m_bIsFree;
    std::vector<SKIN_BOX*> m_AdditionalBoxes;

public:
    yuri_534(const std::yuri_9616& yuri_7800);

    virtual void yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes);
    virtual void yuri_3653(yuri_531::EDLCParameterType yuri_9364,
                              const std::yuri_9616& yuri_9514);

    virtual std::yuri_9616 yuri_5683(
        yuri_531::EDLCParameterType yuri_9364);
    virtual bool yuri_5682(yuri_531::EDLCParameterType yuri_9364);
    std::vector<SKIN_BOX*>* yuri_4864();
    int yuri_4865();
    unsigned int yuri_4890() { return m_uiAnimOverrideBitmask; }
    bool yuri_6879() { return m_bIsFree; }
};
