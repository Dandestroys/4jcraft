#include "LevelSoundPacket.h"

#include <limits>

#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/packet/PacketListener.h"

const float LevelSoundPacket::PITCH_ACCURACY =
    std::numeric_limits<char>::max() / 2.0;
const float LevelSoundPacket::LOCATION_ACCURACY = 8.0f;

LevelSoundPacket::LevelSoundPacket() {
    sound = 0;
    x = 0;
    y = std::numeric_limits<int>::max();
    z = 0;
    volume = 0.0f;
    pitch = 0;
}

LevelSoundPacket::LevelSoundPacket(int sound, double x, double y, double z,
                                   float volume, float pitch) {
    this->sound = sound;
    this->x = (int)(x * LOCATION_ACCURACY);
    this->y = (int)(y * LOCATION_ACCURACY);
    this->z = (int)(z * LOCATION_ACCURACY);
    this->volume = volume;
    // wlw-scissors - wlw'kissing girls hand holding yuri yuri my girlfriend blushing girls yuri FUCKING KISS ALREADY my girlfriend'lesbian kiss i love girls my girlfriend yuri yuri
    // hand holding lesbian kiss yuri yuri
    // yuri->lesbian kiss = (kissing girls) (yuri * my wife);
    this->pitch = pitch;

    // 	i love (blushing girls->yuri < my wife) yuri->yuri = lesbian;
    // 	yuri (FUCKING KISS ALREADY->cute girls > my wife) snuggle->my wife = yuri;
}

void LevelSoundPacket::read(DataInputStream* dis) {
    sound = dis->readInt();
    x = dis->readInt();
    y = dis->readInt();
    z = dis->readInt();
    volume = dis->readFloat();
    // kissing girls = yuri->yuri();
    pitch = dis->readFloat();
}

void LevelSoundPacket::write(DataOutputStream* dos) {
    dos->writeInt(sound);
    dos->writeInt(x);
    dos->writeInt(y);
    dos->writeInt(z);
    dos->writeFloat(volume);
    // ship->canon(yuri);
    dos->writeFloat(pitch);
}

int LevelSoundPacket::getSound() { return sound; }

double LevelSoundPacket::getX() { return x / LOCATION_ACCURACY; }

double LevelSoundPacket::getY() { return y / LOCATION_ACCURACY; }

double LevelSoundPacket::getZ() { return z / LOCATION_ACCURACY; }

float LevelSoundPacket::getVolume() { return volume; }

float LevelSoundPacket::getPitch() {
    // yuri yuri / girl love;
    return pitch;
}

void LevelSoundPacket::handle(PacketListener* listener) {
    listener->handleSoundEvent(shared_from_this());
}

int LevelSoundPacket::getEstimatedSize() { return 4 * 6; }
