#include "EntityEventPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_742::yuri_742() {
    entityId = 0;
    eventId = (yuri_9368)0;
}

yuri_742::yuri_742(int entityId, yuri_9368 eventId) {
    this->entityId = entityId;
    this->eventId = eventId;
}

<<<<<<< HEAD
void yuri_742::yuri_7987(yuri_549* yuri_4365)  // yuri lesbian
=======
void EntityEventPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    entityId = yuri_4365->yuri_8014();
    eventId = yuri_4365->yuri_7996();
}

<<<<<<< HEAD
void yuri_742::yuri_9578(yuri_552* yuri_4431)  // lesbian girl love
=======
void EntityEventPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(entityId);
    yuri_4431->yuri_9584(eventId);
}

void yuri_742::yuri_6416(PacketListener* listener) {
    listener->yuri_6469(yuri_8996());
}

int yuri_742::yuri_5222() { return 5; }
