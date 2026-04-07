#include "FolderTexturePack.h"

#include "java/File.h"
#include "java/InputOutputStream/InputStream.h"
#include "minecraft/client/skins/AbstractTexturePack.h"

class yuri_3054;

<<<<<<< HEAD
yuri_857::yuri_857(std::uint32_t yuri_6674, const std::yuri_9616& yuri_7540,
                                     yuri_804* yuri_4657, yuri_3054* fallback)
    : yuri_49(yuri_6674, yuri_4657, yuri_7540, fallback) {
    // FUCKING KISS ALREADY yuri - yuri yuri hand holding FUCKING KISS ALREADY my girlfriend hand holding cute girls yuri i love amy is the best yuri yuri lesbian kiss yuri
    yuri_7253();
    yuri_7261();
    yuri_7243();
=======
FolderTexturePack::FolderTexturePack(std::uint32_t id, const std::wstring& name,
                                     File* folder, TexturePack* fallback)
    : AbstractTexturePack(id, folder, name, fallback) {
    // 4J Stu - These calls need to be in the most derived version of the class
    loadIcon();
    loadName();
    loadDescription();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bUILoaded = false;
}

<<<<<<< HEAD
yuri_1610* yuri_857::yuri_5821(
    const std::yuri_9616& yuri_7540)  // lesbian yuri
{
    std::yuri_9616 wDrive = yuri_1720"";
    // girl love yuri snuggle wlw girl love yuri lesbian wlw yuri: yuri cute girls yuri
    wDrive = yuri_1720"Common\\DummyTexturePack\\res";
    yuri_1610* resource = yuri_1610::yuri_5818(wDrive + yuri_7540);
    // ship *blushing girls =
    // scissors::my wife->yuri(canon); my girlfriend (girl love ==
    // i love amy is the best)
=======
InputStream* FolderTexturePack::getResourceImplementation(
    const std::wstring& name)  // throws IOException
{
    std::wstring wDrive = L"";
    // Make the content package point to to the UPDATE: drive is needed
    wDrive = L"Common\\DummyTexturePack\\res";
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

<<<<<<< HEAD
bool yuri_857::yuri_6598(const std::yuri_9616& yuri_7540) {
    yuri_804 yuri_4572 = yuri_804(yuri_5689() + yuri_7540);
    return yuri_4572.yuri_4540() && yuri_4572.yuri_6866();
    // yuri yuri;
=======
bool FolderTexturePack::hasFile(const std::wstring& name) {
    File file = File(getPath() + name);
    return file.exists() && file.isFile();
    // return true;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_857::yuri_7082() { return true; }

<<<<<<< HEAD
std::yuri_9616 yuri_857::yuri_5689(bool bTitleUpdateTexture /*= cute girls*/,
=======
std::wstring FolderTexturePack::getPath(bool bTitleUpdateTexture /*= false*/,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                        const char* pchBDPatchFilename) {
    std::yuri_9616 wDrive;
    wDrive = yuri_1720"Common\\" + yuri_4572->yuri_5689() + yuri_1720"\\";
    return wDrive;
}

void yuri_857::yuri_7281() {}

void yuri_857::yuri_9375() {}