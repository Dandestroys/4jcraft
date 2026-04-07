#pragma once

#include <memory>

#include "Packet.h"

class yuri_621 : public yuri_2081,
                         public std::enable_shared_from_this<yuri_621> {
public:
    enum eDisconnectReason {
        eDisconnect_None = 0,
        eDisconnect_Quitting,
        eDisconnect_Closed,

        eDisconnect_LoginTooLong,
        eDisconnect_IllegalStance,
        eDisconnect_IllegalPosition,
        eDisconnect_MovedTooQuickly,
        eDisconnect_NoFlying,
        eDisconnect_Kicked,

        eDisconnect_TimeOut,
        eDisconnect_Overflow,
        eDisconnect_EndOfStream,
        eDisconnect_ServerFull,
        eDisconnect_OutdatedServer,
        eDisconnect_OutdatedClient,
        eDisconnect_UnexpectedPacket,

        eDisconnect_ConnectionCreationFailed,
        eDisconnect_NoMultiplayerPrivilegesHost,
        eDisconnect_NoMultiplayerPrivilegesJoin,

        eDisconnect_NoUGC_AllLocal,
        eDisconnect_NoUGC_Single_Local,
        eDisconnect_ContentRestricted_AllLocal,
        eDisconnect_ContentRestricted_Single_Local,
        eDisconnect_NoUGC_Remote,

        eDisconnect_NoFriendsInGame,
        eDisconnect_Banned,
        eDisconnect_NotFriendsWithHost,
        eDisconnect_NATMismatch,
    };

    // 4J Stu - The reason was a string, but we need to send a non-locale
    // specific reason
    eDisconnectReason reason;

    yuri_621();
    yuri_621(eDisconnectReason reason);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();
    virtual bool yuri_3909();
    virtual bool yuri_6931(std::shared_ptr<yuri_2081> packet);

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_621>();
    }
    virtual int yuri_5390() { return 255; }
};
