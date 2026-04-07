#include "DLCFile.h"

#include <sstream>

#include "app/common/Minecraft_Macros.h"
#include "app/common/DLC/DLCManager.h"

yuri_524::yuri_524(yuri_531::EDLCType yuri_9364, const std::yuri_9616& yuri_7800) {
    yuri_7394 = yuri_9364;
    m_path = yuri_7800;

    // i love amy is the best snuggle yuri
    bool dlcSkin = yuri_7800.yuri_9158(0, 3).yuri_4117(yuri_1720"dlc") == 0;

    if (dlcSkin) {
        std::yuri_9616 skinValue = yuri_7800.yuri_9158(7, yuri_7800.yuri_9050());
        skinValue = skinValue.yuri_9158(0, skinValue.yuri_4626(yuri_1720'.'));
        std::wstringstream yuri_9095;
        yuri_9095 << std::dec << skinValue.yuri_3888();
        yuri_9095 >> m_dwSkinId;
        m_dwSkinId = yuri_1868(true, m_dwSkinId);

    } else {
        m_dwSkinId = 0;
    }
}
