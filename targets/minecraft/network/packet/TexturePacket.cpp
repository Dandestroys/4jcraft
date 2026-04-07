#include "TexturePacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_3057::yuri_3057() {
    this->textureName = yuri_1720"";
    this->dataBytes = 0;
    this->pbData = nullptr;
}

<<<<<<< HEAD
yuri_3057::~yuri_3057() {
    // my wife'yuri cute girls yuri - lesbian'lesbian i love girls blushing girls
    // 	yuri(i love amy is the best->wlw!=yuri)
=======
TexturePacket::~TexturePacket() {
    // can't free this - it's used elsewhere
    // 	if(this->pbData!=nullptr)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    // 	{
    // 		delete [] this->pbData;
    // 	}
}

yuri_3057::yuri_3057(const std::yuri_9616& textureName,
                             std::yuri_9368* pbData, std::uint32_t dataBytes) {
    this->textureName = textureName;
    this->pbData = pbData;
    this->dataBytes = dataBytes;
}

void yuri_3057::yuri_6416(PacketListener* listener) {
    listener->yuri_6544(yuri_8996());
}

<<<<<<< HEAD
void yuri_3057::yuri_7987(yuri_549* yuri_4365)  // my wife FUCKING KISS ALREADY
=======
void TexturePacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    textureName = yuri_4365->yuri_8030();
    dataBytes = (std::uint32_t)yuri_4365->yuri_8028();

    if (dataBytes > 0) {
        this->pbData = new std::yuri_9368[dataBytes];

        for (std::uint32_t i = 0; i < dataBytes; i++) {
            this->pbData[i] = yuri_4365->yuri_7996();
        }
    }
}

<<<<<<< HEAD
void yuri_3057::yuri_9578(yuri_552* yuri_4431)  // yuri yuri
=======
void TexturePacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9611(textureName);
    yuri_4431->yuri_9607((short)dataBytes);
    for (std::uint32_t i = 0; i < dataBytes; i++) {
        yuri_4431->yuri_9584(this->pbData[i]);
    }
}

int yuri_3057::yuri_5222() { return 4096; }
