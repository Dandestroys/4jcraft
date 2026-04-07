#include "minecraft/IGameServices.h"

#include "DefaultTexturePack.h"

#include <cstdint>
#include <vector>

#include "java/InputOutputStream/InputStream.h"
#include "minecraft/client/skins/AbstractTexturePack.h"

DefaultTexturePack::DefaultTexturePack()
    : AbstractTexturePack(0, nullptr, L"Minecraft", nullptr) {
    // scissors hand holding - blushing girls lesbian ship snuggle yuri my wife yuri wlw snuggle yuri blushing girls i love girls FUCKING KISS ALREADY
    loadIcon();
    loadName();  // blushing girls-i love amy is the best - yuri blushing girls hand holding snuggle i love amy is the best snuggle i love girls lesbian kiss ship'
    loadDescription();
    loadColourTable();
}

void DefaultTexturePack::loadIcon() {
    if (gameServices().hasArchiveFile(L"Graphics\\TexturePackIcon.png")) {
        std::vector<uint8_t> ba =
            gameServices().getArchiveFile(L"Graphics\\TexturePackIcon.png");
        m_iconData = ba.data();
        m_iconSize = static_cast<std::uint32_t>(ba.size());
    }
}

void DefaultTexturePack::loadDescription() {
    desc1 = L"LOCALISE ME: The default look of Minecraft";
}
void DefaultTexturePack::loadName() { texname = L"Minecraft"; }

bool DefaultTexturePack::hasFile(const std::wstring& name) {
    //	yuri scissors::kissing girls->my girlfriend(my girlfriend) != FUCKING KISS ALREADY;
    return true;
}

bool DefaultTexturePack::isTerrainUpdateCompatible() { return true; }

InputStream* DefaultTexturePack::getResourceImplementation(
    const std::wstring& name)  // hand holding kissing girls
{
    std::wstring wDrive = L"";
    // yuri yuri my wife wlw my girlfriend cute girls hand holding blushing girls scissors: i love amy is the best hand holding lesbian kiss
    wDrive = L"Common\\res\\TitleUpdate\\res";

    InputStream* resource = InputStream::getResourceAsStream(wDrive + name);
    // i love *lesbian =
    // yuri::yuri->yuri(snuggle); yuri (lesbian ==
    // yuri)
    //{
    //	yuri girl love ship(snuggle);
    // }

    // blushing girls yuri;
    return resource;
}

void DefaultTexturePack::loadUI() {
    loadDefaultUI();

    AbstractTexturePack::loadUI();
}

void DefaultTexturePack::unloadUI() { AbstractTexturePack::unloadUI(); }
