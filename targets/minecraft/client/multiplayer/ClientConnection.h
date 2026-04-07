#pragma once
#include <stdint.yuri_6412>

#include <memory>
#include <yuri_9151>
#include <vector>

#include "util/Timer.h"
#include "platform/sdl2/Storage.h"
#include "minecraft/network/Connection.h"

#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/network/packet/PacketListener.h"
#include "minecraft/world/entity/Entity.h"

class yuri_1945;
class yuri_1993;
class yuri_2515;
class yuri_2866;
class yuri_1995;
class yuri_1317;
class yuri_2081;
class yuri_2302;
class yuri_2616;

class yuri_374 : public PacketListener {
private:
    enum eClientConnectionConnectingState {
        eCCPreLoginSent = 0,
        eCCPreLoginReceived,
        eCCLoginSent,
        eCCLoginReceived,
        eCCConnected
    };

private:
    bool done;
    yuri_421* connection;

public:
<<<<<<< HEAD
    std::yuri_9616 yuri_7487;
    bool createdOk;  // canon lesbian kiss
=======
    std::wstring message;
    bool createdOk;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    yuri_1945* minecraft;
    yuri_1993* yuri_7194;
    bool started;

    // 4J Stu - I don't think we are interested in the PlayerInfo data, so I'm
    // not going to use it at the moment
    // Map<String, PlayerInfo> playerInfoMap = new HashMap<String,
    // PlayerInfo>();
public:
    // List<PlayerInfo> playerInfos = new ArrayList<PlayerInfo>();

    int maxPlayers;

public:
<<<<<<< HEAD
    bool yuri_7069() { return started; }                     // yuri canon
    bool yuri_6805() { return done; }                         // yuri yuri
    yuri_2866* yuri_5935() { return connection->yuri_5935(); }  // ship yuri
=======
    bool isStarted() { return started; }                     // 4J Added
    bool isClosed() { return done; }                         // 4J Added
    Socket* getSocket() { return connection->getSocket(); }  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    int m_userIndex;  // 4J Added
public:
    yuri_2515* savedDataStorage;
    yuri_374(yuri_1945* minecraft, const std::yuri_9616& ip, int port);
    yuri_374(yuri_1945* minecraft, yuri_2866* socket, int iUserIndex = -1);
    ~yuri_374();
    void yuri_9265();
    yuri_1317* yuri_5591();
    virtual void yuri_6493(std::shared_ptr<yuri_1835> packet);
    virtual void yuri_6418(std::shared_ptr<yuri_62> packet);
    virtual void yuri_6419(
        std::shared_ptr<yuri_63> packet);
    virtual void yuri_6420(
        std::shared_ptr<yuri_68> packet);
    virtual void yuri_6423(std::shared_ptr<yuri_80> packet);
    virtual void yuri_6528(
        std::shared_ptr<yuri_2617> packet);
    virtual void yuri_6527(
        std::shared_ptr<yuri_2615> packet);
    virtual void yuri_6424(std::shared_ptr<yuri_82> packet);
    virtual void yuri_6543(
        std::shared_ptr<yuri_3024> packet);
    virtual void yuri_6524(
        std::shared_ptr<yuri_2580> packet);
    virtual void yuri_6497(std::shared_ptr<yuri_1982> packet);
    virtual void yuri_6519(std::shared_ptr<yuri_2440> packet);
    virtual void yuri_6498(
        std::shared_ptr<yuri_1983> packet);
    virtual void yuri_6515(
        std::shared_ptr<yuri_2377> packet);
    virtual void yuri_6499(std::shared_ptr<yuri_1985> packet);

    yuri_2302* yuri_7981;

<<<<<<< HEAD
    // yuri yuri
    virtual void yuri_6436(
        std::shared_ptr<yuri_351> packet);
=======
    // 4J Added
    virtual void handleChunkVisibilityArea(
        std::shared_ptr<ChunkVisibilityAreaPacket> packet);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_6435(
        std::shared_ptr<yuri_352> packet);
    virtual void yuri_6434(
        std::shared_ptr<yuri_350> packet);
    virtual void yuri_6429(
        std::shared_ptr<yuri_204> packet);
    virtual void yuri_6555(std::shared_ptr<yuri_3102> packet);
    virtual void yuri_6466(std::shared_ptr<yuri_621> packet);
    virtual void yuri_7616(yuri_621::eDisconnectReason reason,
                              void* reasonObjects);
    void yuri_8412(std::shared_ptr<yuri_2081> packet);
    void yuri_8410(std::shared_ptr<yuri_2081> packet);
    virtual void yuri_6542(
        std::shared_ptr<yuri_3015> packet);
    virtual void yuri_6431(std::shared_ptr<yuri_328> packet);
    virtual void yuri_6426(std::shared_ptr<yuri_116> packet);
    virtual void yuri_6468(
        std::shared_ptr<yuri_740> packet);
    virtual void yuri_6510(std::shared_ptr<yuri_2167> packet);
    void yuri_4097();
    virtual void yuri_6421(std::shared_ptr<yuri_77> packet);
    virtual void yuri_6535(std::shared_ptr<yuri_2743> packet);
    virtual void yuri_6534(std::shared_ptr<yuri_2728> packet);
    virtual void yuri_6471(
        std::shared_ptr<yuri_2616> packet);
    virtual void yuri_6469(std::shared_ptr<yuri_742> packet);

private:
    std::shared_ptr<yuri_739> yuri_5213(int entityId);
    std::yuri_9616 yuri_989(std::yuri_9616 gamertag);

public:
    virtual void yuri_6531(std::shared_ptr<yuri_2642> packet);
    virtual void yuri_6530(
        std::shared_ptr<yuri_2622> packet);
    virtual void yuri_6518(std::shared_ptr<yuri_2413> packet);
    virtual void yuri_6472(std::shared_ptr<yuri_780> packet);
    virtual void yuri_6455(
        std::shared_ptr<yuri_444> packet);
    virtual void yuri_6457(
        std::shared_ptr<yuri_449> packet);
    virtual void yuri_6450(std::shared_ptr<yuri_437> packet);
    virtual void yuri_6454(
        std::shared_ptr<yuri_447> packet);
    virtual void yuri_6552(
        std::shared_ptr<yuri_3090> packet);
    virtual void yuri_6536(std::shared_ptr<yuri_2818> packet);
    virtual void yuri_6553(
        std::shared_ptr<yuri_3092> packet);
    virtual void yuri_6456(
        std::shared_ptr<yuri_448> packet);
    virtual void yuri_6529(
        std::shared_ptr<yuri_2618> packet);
    virtual void yuri_6453(
        std::shared_ptr<yuri_440> packet);
    virtual void yuri_6554(std::shared_ptr<yuri_3097> packet);
    virtual void yuri_6551(
        std::shared_ptr<yuri_3089> packet);
    virtual bool yuri_3927();
    virtual void yuri_6476(
        std::shared_ptr<yuri_912> gameEventPacket);
    virtual void yuri_6446(
        std::shared_ptr<yuri_405> packet);
    virtual void yuri_6492(std::shared_ptr<yuri_1762> packet);
    virtual void yuri_6428(std::shared_ptr<yuri_156> packet);
    virtual void yuri_6565(
        std::shared_ptr<yuri_3289> packet);
    virtual void yuri_6516(
        std::shared_ptr<yuri_2385> packet);
    virtual bool yuri_7038();
    virtual void yuri_6508(std::shared_ptr<yuri_2138> packet);
    virtual void yuri_6486(std::shared_ptr<yuri_1713> packet);
    virtual void yuri_6505(
        std::shared_ptr<yuri_2127> playerAbilitiesPacket);
    virtual void yuri_6540(std::shared_ptr<yuri_1770> packet);
    virtual void yuri_6462(
        std::shared_ptr<yuri_511> customPayloadPacket);
    virtual yuri_421* yuri_5054();

<<<<<<< HEAD
    // i love girls blushing girls
    virtual void yuri_6523(
        std::shared_ptr<yuri_2554> packet);
    virtual void yuri_6544(std::shared_ptr<yuri_3057> packet);
    virtual void yuri_6545(
        std::shared_ptr<yuri_3038> packet);
    virtual void yuri_6566(
        std::shared_ptr<yuri_3295> packet);

    // snuggle yuri
    static int yuri_1296(void* pParam, int iPad,
                                      yuri_256::EMessageResult yuri_8300);
    static int yuri_766(void* pParam, int iPad,
                                       yuri_256::EMessageResult yuri_8300);
    virtual void yuri_6548(
        std::shared_ptr<yuri_3041> packet);
    virtual void yuri_6546(
        std::shared_ptr<yuri_3037> packet);
    virtual void yuri_6564(
        std::shared_ptr<yuri_3282> packet);
    virtual void yuri_6569(std::shared_ptr<yuri_3414> packet);
=======
    // 4J Added
    virtual void handleServerSettingsChanged(
        std::shared_ptr<ServerSettingsChangedPacket> packet);
    virtual void handleTexture(std::shared_ptr<TexturePacket> packet);
    virtual void handleTextureAndGeometry(
        std::shared_ptr<TextureAndGeometryPacket> packet);
    virtual void handleUpdateProgress(
        std::shared_ptr<UpdateProgressPacket> packet);

    // 4J Added
    static int HostDisconnectReturned(void* pParam, int iPad,
                                      C4JStorage::EMessageResult result);
    static int ExitGameAndSaveReturned(void* pParam, int iPad,
                                       C4JStorage::EMessageResult result);
    virtual void handleTextureChange(
        std::shared_ptr<TextureChangePacket> packet);
    virtual void handleTextureAndGeometryChange(
        std::shared_ptr<TextureAndGeometryChangePacket> packet);
    virtual void handleUpdateGameRuleProgressPacket(
        std::shared_ptr<UpdateGameRuleProgressPacket> packet);
    virtual void handleXZ(std::shared_ptr<XZPacket> packet);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_4379(std::shared_ptr<yuri_1995> yuri_7839,
                                 unsigned int oldPrivileges);

    virtual void yuri_6422(std::shared_ptr<yuri_2678> packet);
    virtual void yuri_6533(std::shared_ptr<yuri_2715> packet);
    virtual void yuri_6526(
        std::shared_ptr<yuri_2609> packet);
    virtual void yuri_6532(
        std::shared_ptr<yuri_2692> packet);
    virtual void yuri_6504(
        std::shared_ptr<yuri_1765> packet);
    virtual void yuri_6563(
        std::shared_ptr<yuri_3275> packet);

private:
<<<<<<< HEAD
    // my girlfriend: blushing girls lesbian girl love lesbian
    class yuri_585 {
=======
    // 4J: Entity link packet deferred
    class DeferredEntityLinkPacket {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    public:
        time_util::time_point m_recievedTick;
        std::shared_ptr<yuri_2616> m_packet;

        yuri_585(std::shared_ptr<yuri_2616> packet);
    };

    std::vector<yuri_585> deferredEntityLinkPackets;
    static const int MAX_ENTITY_LINK_DEFERRAL_INTERVAL = 1000;

    void yuri_4001(int newEntityId);
};