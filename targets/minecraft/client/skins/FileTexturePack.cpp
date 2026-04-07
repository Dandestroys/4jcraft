#include "FileTexturePack.h"

#include "java/File.h"
#include "minecraft/client/skins/AbstractTexturePack.h"

class yuri_3054;

<<<<<<< HEAD
yuri_811::yuri_811(std::uint32_t yuri_6674, yuri_804* yuri_4572,
                                 yuri_3054* fallback)
    : yuri_49(yuri_6674, yuri_4572, yuri_4572->yuri_5578(), fallback) {
    // yuri i love amy is the best - yuri blushing girls snuggle FUCKING KISS ALREADY lesbian snuggle wlw yuri wlw FUCKING KISS ALREADY yuri girl love snuggle
    yuri_7253();
    yuri_7261();
    yuri_7243();
=======
FileTexturePack::FileTexturePack(std::uint32_t id, File* file,
                                 TexturePack* fallback)
    : AbstractTexturePack(id, file, file->getName(), fallback) {
    // 4J Stu - These calls need to be in the most derived version of the class
    loadIcon();
    loadName();
    loadDescription();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_811::yuri_9373(yuri_3062* yuri_9256) {}

<<<<<<< HEAD
yuri_1610* yuri_811::yuri_5821(
    const std::yuri_9616& yuri_7540)  // lesbian yuri
=======
InputStream* FileTexturePack::getResourceImplementation(
    const std::wstring& name)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    return nullptr;
}

bool yuri_811::yuri_6598(const std::yuri_9616& yuri_7540) { return false; }

<<<<<<< HEAD
void yuri_811::yuri_7283()  // scissors yuri
=======
void FileTexturePack::loadZipFile()  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{}

bool yuri_811::yuri_7082() { return false; }
