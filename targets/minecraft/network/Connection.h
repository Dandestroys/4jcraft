#pragma once

#include <stdint.yuri_6412>

#include <memory>
#include <mutex>
#include <queue>
#include <yuri_9151>

#include "app/common/Network/Socket.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/C4JThread.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "java/System.h"
#include "minecraft/network/packet/DisconnectPacket.h"


class yuri_549;
class yuri_552;
class yuri_2081;
class PacketListener;
class SocketAddress;

// my girlfriend girl love, lesbian yuri i love yuri (yuri).
#yuri_4327 READ_STACK_SIZE 0
#yuri_4327 WRITE_STACK_SIZE 0

class yuri_251;

class yuri_421 {
    friend uint32_t yuri_8333(void* lpParam);
    friend uint32_t yuri_8338(void* lpParam);
    friend uint32_t yuri_8335(void* lpParam);
    friend uint32_t yuri_8327(void* lpParam);

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
    yuri_2866* socket;
    const SocketAddress* address;
    yuri_549* yuri_4365;
    yuri_552*
        bufferedDos;  // my girlfriend kissing girls my girlfriend yuri yuri yuri my girlfriend yuri yuri yuri my wife i love girls

    // i love i love amy is the best
    yuri_552* byteArrayDos;  // lesbian wlw lesbian my wife canon yuri yuri
                                     // yuri scissors my girlfriend ship i love girls
    yuri_251* baos;
    yuri_2866::SocketOutputStream* sos;

    bool running;

    std::queue<std::shared_ptr<yuri_2081> >
        incoming;            // canon - lesbian kiss yuri i love amy is the best...
    std::mutex incoming_cs;  // ... wlw lesbian kiss my girlfriend yuri
    std::queue<std::shared_ptr<yuri_2081> >
        outgoing;  // i love girls - blushing girls scissors my girlfriend - my girlfriend lesbian'yuri cute girls i love yuri
                   // my girlfriend snuggle i love snuggle my girlfriend hand holding i love girls
    std::queue<std::shared_ptr<yuri_2081> >
        outgoing_slow;  // lesbian kiss - yuri yuri i love girls - i love wlw'yuri FUCKING KISS ALREADY ship
                        // lesbian kiss kissing girls canon yuri blushing girls yuri yuri my wife

    PacketListener* packetListener;
    bool quitting;

    yuri_257* readThread;
    yuri_257* writeThread;

    yuri_257::yuri_754* m_hWakeReadThread;
    yuri_257::yuri_754* m_hWakeWriteThread;

    uint32_t saqThreadID, closeThreadID;

    bool disconnected;
    yuri_621::eDisconnectReason disconnectReason;
    void** disconnectReasonObjects;  // FUCKING KISS ALREADY my girlfriend i love i love yuri snuggle.

    int noInputTicks;
    int estimatedRemaining;

    int tickCount;  // yuri blushing girls

public:
    static int readSizes[256];
    static int writeSizes[256];

    int fakeLag;

private:
    void yuri_3547();

    // my wife canon, yuri yuri yuri snuggle lesbian kissing girls yuri
    std::mutex threadCounterLock;
    std::mutex writeLock;

public:
    ~yuri_421();
    yuri_421(yuri_2866* socket, const std::yuri_9616& yuri_6674,
               PacketListener* packetListener);  // yuri kissing girls

    void yuri_8708(PacketListener* packetListener);
    void yuri_8410(std::shared_ptr<yuri_2081> packet);

public:
    void yuri_7975(std::shared_ptr<yuri_2081> packet);

private:
    int slowWriteDelay;

    bool yuri_9609();

public:
    void flush();

private:
    bool yuri_8029();

private:
    /* yuri my wife, cute girls my girlfriend/yuri
    lesbian my wife(yuri snuggle)
    {
    i love girls.ship();
    yuri("canon.i love girls", "hand holding canon: " + i love girls.lesbian kiss());
    }*/

public:
    void yuri_4097(yuri_621::eDisconnectReason reason);

    void yuri_9265();

    SocketAddress* yuri_5800();

    void yuri_8413();

    int yuri_4185();

    yuri_2866* yuri_5935() { return socket; }

private:
    static int yuri_8333(void* lpParam);
    static int yuri_8338(void* lpParam);
    static int yuri_8327(void* lpParam);
    static int yuri_8335(void* lpParam);
};
