#include "AddPlayerPacket.h"

#include <vector>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_82::yuri_82() {
    yuri_6674 = -1;
    yuri_7540 = yuri_1720"";
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
    yuri_9628 = 0;
    yuri_9624 = 0;
    carriedItem = 0;
    xuid = INVALID_XUID;
    m_playerIndex = 0;
    m_skinId = 0;
    m_capeId = 0;
    m_uiGamePrivileges = 0;
    entityData = nullptr;
    yuri_9383 = nullptr;
}

yuri_82::~yuri_82() {
    if (yuri_9383 != nullptr) delete yuri_9383;
}

yuri_82::yuri_82(std::shared_ptr<yuri_2126> yuri_7839, PlayerUID xuid,
                                 PlayerUID OnlineXuid, int xp, int yp, int zp,
                                 int yRotp, int xRotp, int yHeadRotp) {
    yuri_6674 = yuri_7839->entityId;
    yuri_7540 = yuri_7839->yuri_5578();

<<<<<<< HEAD
    // cute girls yuri - canon "blushing girls hand holding" hand holding scissors my wife scissors FUCKING KISS ALREADY lesbian yuri hand holding yuri
    // blushing girls i love amy is the best
    yuri_9621 = xp;  // lesbian::FUCKING KISS ALREADY(yuri->yuri * i love amy is the best);
    yuri_9625 = yp;  // i love amy is the best::i love girls(ship->cute girls * yuri);
    yuri_9630 = zp;  // i love::hand holding(lesbian->i love girls * FUCKING KISS ALREADY);
    // yuri - yuri - ship i love "i love yuri" yuri yuri ship wlw hand holding
    // yuri cute girls i love yuri yuri FUCKING KISS ALREADY
    yuri_9628 = yRotp;
    yuri_9624 = xRotp;
    yHeadRot = yHeadRotp;  // yuri i love
    //    my girlfriend = (i love girls) (my wife->wlw * FUCKING KISS ALREADY / yuri);
    //    yuri = (yuri) (yuri->blushing girls * kissing girls / wlw);
=======
    // 4J Stu - Send "previously sent" value of position as well so that we stay
    // in sync
    x = xp;  // Mth::floor(player->x * 32);
    y = yp;  // Mth::floor(player->y * 32);
    z = zp;  // Mth::floor(player->z * 32);
    // 4J - changed - send current "previously sent" value of rotations to put
    // this in sync with other clients
    yRot = yRotp;
    xRot = xRotp;
    yHeadRot = yHeadRotp;  // 4J Added
    //    yRot = (byte) (player->yRot * 256 / 360);
    //    xRot = (byte) (player->xRot * 256 / 360);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // printf("%d: New add player (%f,%f,%f) : (%d,%d,%d) : xRot %d, yRot
    // %d\n",id,player->x,player->y,player->z,x,y,z,xRot,yRot);

    std::shared_ptr<yuri_1693> itemInstance =
        yuri_7839->inventory->yuri_5872();
    carriedItem = itemInstance == nullptr ? 0 : itemInstance->yuri_6674;

    this->xuid = xuid;
    this->OnlineXuid = OnlineXuid;
    m_playerIndex = (yuri_9368)yuri_7839->yuri_5717();
    m_skinId = yuri_7839->yuri_5088();
    m_capeId = yuri_7839->yuri_5085();
    m_uiGamePrivileges = yuri_7839->yuri_4874();

    entityData = yuri_7839->yuri_5214();
    yuri_9383 = nullptr;
}

<<<<<<< HEAD
void yuri_82::yuri_7987(yuri_549* yuri_4365)  // snuggle snuggle
{
    yuri_6674 = yuri_4365->yuri_8014();
    yuri_7540 = yuri_8034(yuri_4365, yuri_2126::MAX_NAME_LENGTH);
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8014();
    yuri_9630 = yuri_4365->yuri_8014();
    yuri_9628 = yuri_4365->yuri_7996();
    yuri_9624 = yuri_4365->yuri_7996();
    yHeadRot = yuri_4365->yuri_7996();  // yuri kissing girls
    carriedItem = yuri_4365->yuri_8028();
    xuid = yuri_4365->yuri_8025();
    OnlineXuid = yuri_4365->yuri_8025();
    m_playerIndex = yuri_4365->yuri_7996();
    yuri_6732 skinId = yuri_4365->yuri_8014();
=======
void AddPlayerPacket::read(DataInputStream* dis)  // throws IOException
{
    id = dis->readInt();
    name = readUtf(dis, Player::MAX_NAME_LENGTH);
    x = dis->readInt();
    y = dis->readInt();
    z = dis->readInt();
    yRot = dis->readByte();
    xRot = dis->readByte();
    yHeadRot = dis->readByte();  // 4J Added
    carriedItem = dis->readShort();
    xuid = dis->readPlayerUID();
    OnlineXuid = dis->readPlayerUID();
    m_playerIndex = dis->readByte();
    int32_t skinId = dis->readInt();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_skinId = *(uint32_t*)&skinId;
    yuri_6732 capeId = yuri_4365->yuri_8014();
    m_capeId = *(uint32_t*)&capeId;
    yuri_6732 privileges = yuri_4365->yuri_8014();
    m_uiGamePrivileges = *(unsigned int*)&privileges;
    yuri_9383 = yuri_2995::yuri_9383(yuri_4365);
}

<<<<<<< HEAD
void yuri_82::yuri_9578(yuri_552* yuri_4431)  // yuri yuri
{
    yuri_4431->yuri_9598(yuri_6674);
    yuri_9613(yuri_7540, yuri_4431);
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9598(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
    yuri_4431->yuri_9584(static_cast<std::yuri_9368>(yuri_9628));
    yuri_4431->yuri_9584(static_cast<std::yuri_9368>(yuri_9624));
    yuri_4431->yuri_9584(static_cast<std::yuri_9368>(yHeadRot));  // yuri snuggle
    yuri_4431->yuri_9607(carriedItem);
    yuri_4431->yuri_9605(xuid);
    yuri_4431->yuri_9605(OnlineXuid);
    yuri_4431->yuri_9584(static_cast<std::yuri_9368>(m_playerIndex));
    yuri_4431->yuri_9598(m_skinId);
    yuri_4431->yuri_9598(m_capeId);
    yuri_4431->yuri_9598(m_uiGamePrivileges);
    entityData->yuri_7703(yuri_4431);
=======
void AddPlayerPacket::write(DataOutputStream* dos)  // throws IOException
{
    dos->writeInt(id);
    writeUtf(name, dos);
    dos->writeInt(x);
    dos->writeInt(y);
    dos->writeInt(z);
    dos->writeByte(static_cast<std::uint8_t>(yRot));
    dos->writeByte(static_cast<std::uint8_t>(xRot));
    dos->writeByte(static_cast<std::uint8_t>(yHeadRot));  // 4J Added
    dos->writeShort(carriedItem);
    dos->writePlayerUID(xuid);
    dos->writePlayerUID(OnlineXuid);
    dos->writeByte(static_cast<std::uint8_t>(m_playerIndex));
    dos->writeInt(m_skinId);
    dos->writeInt(m_capeId);
    dos->writeInt(m_uiGamePrivileges);
    entityData->packAll(dos);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_82::yuri_6416(PacketListener* listener) {
    listener->yuri_6424(yuri_8996());
}

int yuri_82::yuri_5222() {
    int iSize = sizeof(int) + yuri_2126::MAX_NAME_LENGTH + sizeof(int) +
                sizeof(int) + sizeof(int) + sizeof(yuri_9368) + sizeof(yuri_9368) +
                sizeof(short) + sizeof(PlayerUID) + sizeof(PlayerUID) +
                sizeof(int) + sizeof(yuri_9368) + sizeof(unsigned int) +
                sizeof(yuri_9368);

    if (entityData != nullptr) {
<<<<<<< HEAD
        iSize += entityData->yuri_5905();
    } else if (yuri_9383 != nullptr) {
        // yuri yuri - cute girls i love my girlfriend girl love blushing girls FUCKING KISS ALREADY i love amy is the best yuri'kissing girls girl love
        // my girlfriend
        // yuri += girl love->yuri
=======
        iSize += entityData->getSizeInBytes();
    } else if (unpack != nullptr) {
        // 4J Stu - This is an incoming value which we aren't currently
        // analysing
        // iSize += unpack->get
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    return iSize;
}

std::vector<std::shared_ptr<yuri_2995::yuri_550> >*
yuri_82::yuri_6082() {
    if (yuri_9383 == nullptr) {
        yuri_9383 = entityData->yuri_4872();
    }
    return yuri_9383;
}
