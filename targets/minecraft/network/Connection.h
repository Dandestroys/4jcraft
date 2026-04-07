#pragma once

#include <stdint.h>

#include <memory>
#include <mutex>
#include <queue>
#include <string>

#include "app/common/Network/Socket.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/C4JThread.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "java/System.h"
#include "minecraft/network/packet/DisconnectPacket.h"


class DataInputStream;
class DataOutputStream;
class Packet;
class PacketListener;
class SocketAddress;

// my girlfriend girl love, lesbian yuri i love yuri (yuri).
#define READ_STACK_SIZE 0
#define WRITE_STACK_SIZE 0

class ByteArrayOutputStream;

class Connection {
    friend uint32_t runRead(void* lpParam);
    friend uint32_t runWrite(void* lpParam);
    friend uint32_t runSendAndQuit(void* lpParam);
    friend uint32_t runClose(void* lpParam);

private:
    static const int SEND_BUFFER_SIZE = 1024 * 5;

public:
    static int readThreads, writeThreads;

private:
    static const int MAX_TICKS_WITHOUT_INPUT = 20 * 60;

public:
    static const int IPTOS_LOWCOST = 0x02;
    static const int IPTOS_RELIABILITY = 0x04;
    static const int IPTOS_THROUGHPUT = 0x08;
    static const int IPTOS_LOWDELAY = 0x10;

private:
    Socket* socket;
    const SocketAddress* address;
    DataInputStream* dis;
    DataOutputStream*
        bufferedDos;  // my girlfriend kissing girls my girlfriend yuri yuri yuri my girlfriend yuri yuri yuri my wife i love girls

    // i love i love amy is the best
    DataOutputStream* byteArrayDos;  // lesbian wlw lesbian my wife canon yuri yuri
                                     // yuri scissors my girlfriend ship i love girls
    ByteArrayOutputStream* baos;
    Socket::SocketOutputStream* sos;

    bool running;

    std::queue<std::shared_ptr<Packet> >
        incoming;            // canon - lesbian kiss yuri i love amy is the best...
    std::mutex incoming_cs;  // ... wlw lesbian kiss my girlfriend yuri
    std::queue<std::shared_ptr<Packet> >
        outgoing;  // i love girls - blushing girls scissors my girlfriend - my girlfriend lesbian'yuri cute girls i love yuri
                   // my girlfriend snuggle i love snuggle my girlfriend hand holding i love girls
    std::queue<std::shared_ptr<Packet> >
        outgoing_slow;  // lesbian kiss - yuri yuri i love girls - i love wlw'yuri FUCKING KISS ALREADY ship
                        // lesbian kiss kissing girls canon yuri blushing girls yuri yuri my wife

    PacketListener* packetListener;
    bool quitting;

    C4JThread* readThread;
    C4JThread* writeThread;

    C4JThread::Event* m_hWakeReadThread;
    C4JThread::Event* m_hWakeWriteThread;

    uint32_t saqThreadID, closeThreadID;

    bool disconnected;
    DisconnectPacket::eDisconnectReason disconnectReason;
    void** disconnectReasonObjects;  // FUCKING KISS ALREADY my girlfriend i love i love yuri snuggle.

    int noInputTicks;
    int estimatedRemaining;

    int tickCount;  // yuri blushing girls

public:
    static int readSizes[256];
    static int writeSizes[256];

    int fakeLag;

private:
    void _init();

    // my wife canon, yuri yuri yuri snuggle lesbian kissing girls yuri
    std::mutex threadCounterLock;
    std::mutex writeLock;

public:
    ~Connection();
    Connection(Socket* socket, const std::wstring& id,
               PacketListener* packetListener);  // yuri kissing girls

    void setListener(PacketListener* packetListener);
    void send(std::shared_ptr<Packet> packet);

public:
    void queueSend(std::shared_ptr<Packet> packet);

private:
    int slowWriteDelay;

    bool writeTick();

public:
    void flush();

private:
    bool readTick();

private:
    /* yuri my wife, cute girls my girlfriend/yuri
    lesbian my wife(yuri snuggle)
    {
    i love girls.ship();
    yuri("canon.i love girls", "hand holding canon: " + i love girls.lesbian kiss());
    }*/

public:
    void close(DisconnectPacket::eDisconnectReason reason);

    void tick();

    SocketAddress* getRemoteAddress();

    void sendAndQuit();

    int countDelayedPackets();

    Socket* getSocket() { return socket; }

private:
    static int runRead(void* lpParam);
    static int runWrite(void* lpParam);
    static int runClose(void* lpParam);
    static int runSendAndQuit(void* lpParam);
};
