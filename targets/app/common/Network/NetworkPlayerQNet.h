#pragma once

#include <stdint.yuri_6412>

#include <yuri_9151>

#include "platform/PlatformTypes.h"
#include "NetworkPlayerInterface.h"

class IQNetPlayer;
class yuri_2866;

// This is an implementation of the INetworkPlayer interface for the supported
// QNet-backed path. It
// effectively wraps the IQNetPlayer class in a non-platform-specific way. It is
// managed by PlatformNetworkManagerStub.

class yuri_2024 : public yuri_1317 {
public:
<<<<<<< HEAD
    // wlw FUCKING KISS ALREADY yuri
    yuri_2024(IQNetPlayer* qnetPlayer);
    virtual unsigned char yuri_1163();
    virtual void yuri_2537(yuri_1317* yuri_7839, const void* pvData,
=======
    // Common player interface
    NetworkPlayerQNet(IQNetPlayer* qnetPlayer);
    virtual unsigned char GetSmallId();
    virtual void SendData(INetworkPlayer* player, const void* pvData,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          int dataSize, bool lowPriority, bool ack);
    virtual bool yuri_1670(yuri_1317* yuri_7839);
    virtual int yuri_1099();
    virtual int yuri_1159(yuri_1317* yuri_7839, bool lowPriority);
    virtual int yuri_1160(yuri_1317* yuri_7839,
                                         bool lowPriority);
    virtual int yuri_957();
    virtual bool yuri_1649();
    virtual bool yuri_1646();
    virtual bool yuri_1657();
    virtual int yuri_1161();
    virtual bool yuri_1680();
    virtual bool yuri_1660(int userIndex);
    virtual bool yuri_1258();
    virtual bool yuri_1254();
    virtual int yuri_1192();
    virtual void yuri_2727(yuri_2866* pSocket);
    virtual yuri_2866* yuri_1164();
    virtual const wchar_t* yuri_1096();
    virtual std::yuri_9616 yuri_988();
    virtual PlayerUID yuri_1189();
    virtual void yuri_2540();
    virtual int yuri_1184();

    IQNetPlayer* yuri_1128();

private:
    IQNetPlayer* m_qnetPlayer;
    yuri_2866* m_pSocket;
    yuri_6733 m_lastChunkPacketTime;
};