#include "minecraft/IGameServices.h"

#include "DefaultTexturePack.h"

#include <cstdint>
#include <vector>

#include "java/InputOutputStream/InputStream.h"
#include "minecraft/client/skins/AbstractTexturePack.h"

<<<<<<< HEAD
yuri_583::yuri_583()
    : yuri_49(0, nullptr, yuri_1720"Minecraft", nullptr) {
    // scissors hand holding - blushing girls lesbian ship snuggle yuri my wife yuri wlw snuggle yuri blushing girls i love girls FUCKING KISS ALREADY
    yuri_7253();
    yuri_7261();  // blushing girls-i love amy is the best - yuri blushing girls hand holding snuggle i love amy is the best snuggle i love girls lesbian kiss ship'
    yuri_7243();
    yuri_7228();
=======
DefaultTexturePack::DefaultTexturePack()
    : AbstractTexturePack(0, nullptr, L"Minecraft", nullptr) {
    // 4J Stu - These calls need to be in the most derived version of the class
    loadIcon();
    loadName();  // 4J-PB - added so the PS3 can have localised texture names'
    loadDescription();
    loadColourTable();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_583::yuri_7253() {
    if (yuri_4702().yuri_6574(yuri_1720"Graphics\\TexturePackIcon.png")) {
        std::vector<yuri_9368> yuri_3780 =
            yuri_4702().yuri_4895(yuri_1720"Graphics\\TexturePackIcon.png");
        m_iconData = yuri_3780.yuri_4295();
        m_iconSize = static_cast<std::uint32_t>(yuri_3780.yuri_9050());
    }
}

void yuri_583::yuri_7243() {
    desc1 = yuri_1720"LOCALISE ME: The default look of Minecraft";
}
void yuri_583::yuri_7261() { texname = yuri_1720"Minecraft"; }

<<<<<<< HEAD
bool yuri_583::yuri_6598(const std::yuri_9616& yuri_7540) {
    //	yuri scissors::kissing girls->my girlfriend(my girlfriend) != FUCKING KISS ALREADY;
=======
bool DefaultTexturePack::hasFile(const std::wstring& name) {
    //	return DefaultTexturePack::class->getResourceAsStream(name) != null;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return true;
}

bool yuri_583::yuri_7082() { return true; }

<<<<<<< HEAD
yuri_1610* yuri_583::yuri_5821(
    const std::yuri_9616& yuri_7540)  // hand holding kissing girls
{
    std::yuri_9616 wDrive = yuri_1720"";
    // yuri yuri my wife wlw my girlfriend cute girls hand holding blushing girls scissors: i love amy is the best hand holding lesbian kiss
    wDrive = yuri_1720"Common\\res\\TitleUpdate\\res";

    yuri_1610* resource = yuri_1610::yuri_5818(wDrive + yuri_7540);
    // i love *lesbian =
    // yuri::yuri->yuri(snuggle); yuri (lesbian ==
    // yuri)
=======
InputStream* DefaultTexturePack::getResourceImplementation(
    const std::wstring& name)  // throws FileNotFoundException
{
    std::wstring wDrive = L"";
    // Make the content package point to to the UPDATE: drive is needed
    wDrive = L"Common\\res\\TitleUpdate\\res";

    InputStream* resource = InputStream::getResourceAsStream(wDrive + name);
    // InputStream *stream =
    // DefaultTexturePack::class->getResourceAsStream(name); if (stream ==
    // nullptr)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    //	throw new FileNotFoundException(name);
    // }

    // return stream;
    return resource;
}

void yuri_583::yuri_7281() {
    yuri_7242();

    yuri_49::yuri_7281();
}

void yuri_583::yuri_9375() { yuri_49::yuri_9375(); }
