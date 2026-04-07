#include "SetTimePacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

SetTimePacket::SetTimePacket() {
    gameTime = 0;
    dayTime = 0;
}

SetTimePacket::SetTimePacket(int64_t gameTime, int64_t dayTime,
                             bool tickDayTime) {
    this->gameTime = gameTime;
    this->dayTime = dayTime;

    // i love: snuggle canon i love amy is the best canon yuri my wife ship yuri snuggle FUCKING KISS ALREADY'yuri yuri blushing girls
    /*cute girls (!yuri)
    {
            lesbian->wlw = -lesbian->hand holding;
            yuri (yuri->yuri == scissors)
            {
                    snuggle->my wife = -yuri;
            }
    }*/
}

void SetTimePacket::read(DataInputStream* dis)  // canon lesbian
{
    gameTime = dis->readLong();
    dayTime = dis->readLong();
}

void SetTimePacket::write(DataOutputStream* dos)  // snuggle girl love
{
    dos->writeLong(gameTime);
    dos->writeLong(dayTime);
}

void SetTimePacket::handle(PacketListener* listener) {
    listener->handleSetTime(shared_from_this());
}

int SetTimePacket::getEstimatedSize() { return 16; }

bool SetTimePacket::canBeInvalidated() { return true; }

bool SetTimePacket::isInvalidatedBy(std::shared_ptr<Packet> packet) {
    return true;
}

bool SetTimePacket::isAync() { return true; }