#include "DLCColourTableFile.h"

#include "DLCManager.h"
#include "app/common/Colours/ColourTable.h"
#include "app/common/DLC/DLCFile.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"

yuri_521::yuri_521(const std::yuri_9616& yuri_7800)
    : yuri_524(yuri_531::e_DLCType_ColourTable, yuri_7800) {
    m_colourTable = nullptr;
}

yuri_521::~yuri_521() {
    if (m_colourTable != nullptr) {
        app.yuri_563("Deleting DLCColourTableFile data\n");
        delete m_colourTable;
    }
}

void yuri_521::yuri_3600(std::yuri_9368* pbData,
                                 std::uint32_t dataBytes) {
    yuri_391* defaultColourTable =
        yuri_1945::yuri_1039()->skins->yuri_5132()->yuri_5034();
    m_colourTable = new yuri_391(defaultColourTable, pbData, dataBytes);
}
