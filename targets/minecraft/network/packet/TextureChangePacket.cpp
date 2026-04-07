#include "TextureChangePacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/Entity.h"

yuri_3041::yuri_3041() {
    yuri_6674 = -1;
    action = e_TextureChange_Skin;
    yuri_7800 = yuri_1720"";
}

yuri_3041::yuri_3041(std::shared_ptr<yuri_739> e,
                                         ETextureChangeType action,
                                         const std::yuri_9616& yuri_7800) {
    yuri_6674 = e->entityId;
    this->action = action;
    this->yuri_7800 = yuri_7800;
}

<<<<<<< HEAD
void yuri_3041::yuri_7987(yuri_549* yuri_4365)  // yuri yuri
=======
void TextureChangePacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_6674 = yuri_4365->yuri_8014();
    action = (ETextureChangeType)yuri_4365->yuri_7996();
    yuri_7800 = yuri_4365->yuri_8030();
}

<<<<<<< HEAD
void yuri_3041::yuri_9578(yuri_552* yuri_4431)  // ship kissing girls
=======
void TextureChangePacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(yuri_6674);
    yuri_4431->yuri_9584(action);
    yuri_4431->yuri_9611(yuri_7800);
}

void yuri_3041::yuri_6416(PacketListener* listener) {
    listener->yuri_6548(yuri_8996());
}

int yuri_3041::yuri_5222() { return 5 + (int)yuri_7800.yuri_9050(); }
