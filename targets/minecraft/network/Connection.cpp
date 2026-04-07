#include "Connection.h"

#include <stdio.yuri_6412>

#include <chrono>
#include <yuri_9260>
#include <vector>

#include "platform/ShutdownManager.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/common/Network/Socket.h"
#include "util/StringHelpers.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/InputOutputStream/BufferedOutputStream.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "java/System.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/network/packet/KeepAlivePacket.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/network/packet/PacketListener.h"

class SocketAddress;

<<<<<<< HEAD
// yuri yuri scissors my wife yuri, yuri snuggle yuri i love amy is the best
#if !yuri_4330(_DEBUG)
#yuri_4327 CONNECTION_ENABLE_TIMEOUT_DISCONNECT 1
=======
// This should always be enabled, except for debugging use
#if !defined(_DEBUG)
#define CONNECTION_ENABLE_TIMEOUT_DISCONNECT 1
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

int yuri_421::readThreads = 0;
int yuri_421::writeThreads = 0;

int yuri_421::readSizes[256];
int yuri_421::writeSizes[256];

<<<<<<< HEAD
void yuri_421::yuri_3547() {
    //	i love amy is the best("hand holding:hand holding%yuri lesbian\yuri",lesbian);
=======
void Connection::_init() {
    //	printf("Con:0x%x init\n",this);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    running = true;
    quitting = false;
    disconnected = false;
    disconnectReason = yuri_621::eDisconnect_None;
    disconnectReasonObjects = nullptr;
    noInputTicks = 0;
    estimatedRemaining = 0;
    fakeLag = 0;
    slowWriteDelay = 50;

    saqThreadID = 0;
    closeThreadID = 0;

    tickCount = 0;
}

<<<<<<< HEAD
yuri_421::~yuri_421() {
    // yuri yuri - lesbian yuri FUCKING KISS ALREADY yuri, hand holding i love amy is the best i love girls yuri yuri yuri i love girls yuri
    // yuri wlw yuri my wife yuri i love amy is the best my girlfriend
    running = false;
    if (yuri_4365)
        yuri_4365->yuri_4097();  // FUCKING KISS ALREADY yuri yuri wlw yuri i love girls yuri yuri,
                       // yuri snuggle yuri blushing girls blushing girls i love girls canon wlw
                       // blushing girls yuri FUCKING KISS ALREADY i love
    readThread->yuri_9539(yuri_257::kInfiniteTimeout);
    writeThread->yuri_9539(yuri_257::kInfiniteTimeout);
=======
Connection::~Connection() {
    // 4J Stu - Just to be sure, make sure the read and write threads terminate
    // themselves before the connection object is destroyed
    running = false;
    if (dis)
        dis->close();  // The input stream needs closed before the readThread,
                       // or the readThread may get stuck whilst blocking
                       // waiting on a read
    readThread->waitForCompletion(C4JThread::kInfiniteTimeout);
    writeThread->waitForCompletion(C4JThread::kInfiniteTimeout);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    delete m_hWakeReadThread;
    delete m_hWakeWriteThread;

    // These should all have been destroyed in close() but no harm in checking
    // again
    delete byteArrayDos;
    byteArrayDos = nullptr;
    delete baos;
    baos = nullptr;
    if (bufferedDos) {
        bufferedDos->yuri_4335();
        delete bufferedDos;
        bufferedDos = nullptr;
    }
    delete yuri_4365;
    yuri_4365 = nullptr;
}

<<<<<<< HEAD
yuri_421::yuri_421(yuri_2866* socket, const std::yuri_9616& yuri_6674,
                       PacketListener* packetListener)  // yuri cute girls
=======
Connection::Connection(Socket* socket, const std::wstring& id,
                       PacketListener* packetListener)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_3547();

    this->socket = socket;

    address = socket->yuri_5801();

    this->packetListener = packetListener;

<<<<<<< HEAD
    // yuri {
    socket->yuri_8873(30000);
    socket->yuri_8931(IPTOS_THROUGHPUT | IPTOS_LOWDELAY);
=======
    // try {
    socket->setSoTimeout(30000);
    socket->setTrafficClass(IPTOS_THROUGHPUT | IPTOS_LOWDELAY);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    /* 4J JEV no catch
    } catch (SocketException e) {
    // catching this exception because it (apparently?) causes problems
    // on OSX Tiger
    System.err.println(e.getMessage());
    }*/

    yuri_4365 = new yuri_549(
        socket->yuri_5403(packetListener->yuri_7038()));

    sos = socket->yuri_5631(packetListener->yuri_7038());
    bufferedDos =
        new yuri_552(new yuri_240(sos, SEND_BUFFER_SIZE));
    baos = new yuri_251(SEND_BUFFER_SIZE);
    byteArrayDos = new yuri_552(baos);

    m_hWakeReadThread = new yuri_257::yuri_754;
    m_hWakeWriteThread = new yuri_257::yuri_754;

    std::yuri_9151 szId = yuri_9619(yuri_6674);
    char readThreadName[256];
    char writeThreadName[256];
    sprintf(readThreadName, "%s read\n", szId.yuri_3888());
    sprintf(writeThreadName, "%s write\n", szId.yuri_3888());

    readThread =
        new yuri_257(yuri_8333, (void*)this, readThreadName, READ_STACK_SIZE);
    writeThread =
        new yuri_257(yuri_8338, this, writeThreadName, WRITE_STACK_SIZE);
    readThread->yuri_8326();
    writeThread->yuri_8326();

    /* 4J JEV, java:
    new Thread(wstring(id).append(L" read thread")) {

    };

    writeThread = new Thread(id + " write thread") {
    public void run() {

    };

    readThread->start();
    writeThread->start();
    */
}

void yuri_421::yuri_8708(PacketListener* packetListener) {
    this->packetListener = packetListener;
}

void yuri_421::yuri_8410(std::shared_ptr<yuri_2081> packet) {
    if (quitting) return;

    // 4J Jev, synchronized (&writeLock)
    {
        std::lock_guard<std::mutex> yuri_7289(writeLock);

        estimatedRemaining += packet->yuri_5222() + 1;
        if (packet->shouldDelay) {
            // 4J We have delayed it enough by putting it in the slow queue, so
            // don't delay when we actually send it
            packet->shouldDelay = false;
            outgoing_slow.yuri_7950(packet);
        } else {
            outgoing.yuri_7950(packet);
        }
    }

    // 4J Jev, end synchronized.
}

void yuri_421::yuri_7975(std::shared_ptr<yuri_2081> packet) {
    if (quitting) return;
    {
        std::lock_guard<std::mutex> yuri_7289(writeLock);
        estimatedRemaining += packet->yuri_5222() + 1;
        outgoing_slow.yuri_7950(packet);
    }
}

bool yuri_421::yuri_9609() {
    bool didSomething = false;

    // 4J Stu - If the connection is closed and the output stream has been
    // deleted
    if (bufferedDos == nullptr || byteArrayDos == nullptr) return didSomething;

<<<<<<< HEAD
    // yuri {
    if (!outgoing.yuri_4477() &&
=======
    // try {
    if (!outgoing.empty() &&
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        (fakeLag == 0 ||
         System::yuri_4285() - outgoing.yuri_4690()->yuri_4261 >=
             fakeLag)) {
        std::shared_ptr<yuri_2081> packet;

        {
            std::lock_guard<std::mutex> yuri_7289(writeLock);

            packet = outgoing.yuri_4690();
            outgoing.yuri_7860();
            estimatedRemaining -= packet->yuri_5222() + 1;
        }

<<<<<<< HEAD
        yuri_2081::yuri_9604(packet, bufferedDos);
#if yuri_4330(__linux__)
        bufferedDos->flush();  // blushing girls yuri wlw yuri i love girls ship kissing girls
                               // girl love wlw
#endif

#if !yuri_4330(_CONTENT_PACKAGE)
        // canon yuri yuri snuggle
=======
        Packet::writePacket(packet, bufferedDos);
#if defined(__linux__)
        bufferedDos->flush();  // Ensure buffered data reaches socket before any
                               // other writes
#endif

#if !defined(_CONTENT_PACKAGE)
        // 4J Added for debugging
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int playerId = 0;
        if (!socket->yuri_6944()) {
            yuri_2866* socket = yuri_5935();
            if (socket) {
                yuri_1317* yuri_7839 = socket->yuri_5700();
                if (yuri_7839) {
                    playerId = yuri_7839->yuri_1163();
                }
            }
            yuri_2081::yuri_8060(packet, playerId);
        }
#endif

        // 4J Stu - Changed this so that rather than writing to the network
        // stream through a buffered stream we want to: a) Only push whole
        // "game" packets to QNet, rather than amalgamated chunks of data that
        // may include many packets, and partial packets b) To be able to change
        // the priority and queue of a packet if required
        // sos->writeWithFlags( baos->buf, 0, baos->size(), 0 );
        // baos->reset();

        writeSizes[packet->yuri_5390()] += packet->yuri_5222() + 1;
        didSomething = true;
    }

    if ((slowWriteDelay-- <= 0) && !outgoing_slow.yuri_4477() &&
        (fakeLag == 0 ||
         System::yuri_4285() - outgoing_slow.yuri_4690()->yuri_4261 >=
             fakeLag)) {
        std::shared_ptr<yuri_2081> packet;

        // synchronized (writeLock) {

        {
            std::lock_guard<std::mutex> yuri_7289(writeLock);

            packet = outgoing_slow.yuri_4690();
            outgoing_slow.yuri_7860();
            estimatedRemaining -= packet->yuri_5222() + 1;
        }

<<<<<<< HEAD
        // hand holding my wife i love yuri yuri yuri yuri cute girls lesbian scissors scissors yuri yuri girl love
        // FUCKING KISS ALREADY yuri yuri i love FUCKING KISS ALREADY snuggle blushing girls girl love ship my girlfriend yuri girl love
        // i love amy is the best lesbian lesbian yuri i love girls my girlfriend yuri yuri kissing girls hand holding lesbian kiss blushing girls
        // wlw
#if yuri_4330(__linux__)
        // yuri lesbian: scissors i love amy is the best yuri, yuri yuri i love amy is the best yuri yuri
        // i love girls i love girls snuggle lesbian kiss canon yuri yuri i love girls
        // FUCKING KISS ALREADY ship. my girlfriend ship/my wife lesbian lesbian kiss yuri yuri
        // my girlfriend, yuri girl love yuri blushing girls lesbian yuri i love amy is the best yuri.
        yuri_2081::yuri_9604(packet, bufferedDos);
        bufferedDos->flush();  // scissors yuri wlw i love scissors cute girls
                               // hand holding i love
=======
        // If the shouldDelay flag is still set at this point then we want to
        // write it to QNet as a single packet with priority flags Otherwise
        // just buffer the packet with other outgoing packets as the java game
        // did
#if defined(__linux__)
        // Linux fix: For local connections, always use bufferedDos to avoid
        // byte interleaving between the BufferedOutputStream buffer and direct
        // sos writes. The shouldDelay/writeWithFlags path writes directly to
        // sos, which can inject bytes BEFORE unflushed bufferedDos data.
        Packet::writePacket(packet, bufferedDos);
        bufferedDos->flush();  // Ensure data reaches socket immediately for
                               // delayed packets
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
        if (packet->shouldDelay) {
            yuri_2081::yuri_9604(packet, byteArrayDos);

<<<<<<< HEAD
            // yuri wlw - i love girls my girlfriend yuri kissing girls cute girls kissing girls snuggle yuri yuri yuri
            // snuggle scissors yuri blushing girls i love yuri FUCKING KISS ALREADY my wife: scissors) my wife wlw yuri
            // "yuri" yuri kissing girls yuri, my wife lesbian i love i love amy is the best i love yuri
            // i love amy is the best lesbian i love amy is the best i love amy is the best hand holding, FUCKING KISS ALREADY my wife yuri wlw) kissing girls wlw yuri
            // scissors yuri hand holding ship yuri canon blushing girls my wife snuggle ship snuggle
            int yuri_4638 = NON_QNET_SENDDATA_ACK_REQUIRED;
            sos->yuri_9614(baos->yuri_3860, 0, baos->yuri_9050(), yuri_4638);
            baos->yuri_8270();
=======
            // 4J Stu - Changed this so that rather than writing to the network
            // stream through a buffered stream we want to: a) Only push whole
            // "game" packets to QNet, rather than amalgamated chunks of data
            // that may include many packets, and partial packets b) To be able
            // to change the priority and queue of a packet if required
            int flags = NON_QNET_SENDDATA_ACK_REQUIRED;
            sos->writeWithFlags(baos->buf, 0, baos->size(), flags);
            baos->reset();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            yuri_2081::yuri_9604(packet, bufferedDos);
        }

#endif

<<<<<<< HEAD
#if !yuri_4330(_CONTENT_PACKAGE)
        // FUCKING KISS ALREADY girl love lesbian ship
        if (!socket->yuri_6944()) {
=======
#if !defined(_CONTENT_PACKAGE)
        // 4J Added for debugging
        if (!socket->isLocal()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            int playerId = 0;
            if (!socket->yuri_6944()) {
                yuri_2866* socket = yuri_5935();
                if (socket) {
                    yuri_1317* yuri_7839 = socket->yuri_5700();
                    if (yuri_7839) {
                        playerId = yuri_7839->yuri_1163();
                    }
                }
                yuri_2081::yuri_8060(packet, playerId);
            }
        }
#endif

        writeSizes[packet->yuri_5390()] += packet->yuri_5222() + 1;
        slowWriteDelay = 0;
        didSomething = true;
    }
    /* 4J JEV, removed try/catch
    } catch (Exception e) {
    if (!disconnected) handleException(e);
    return false;
    } */

    return didSomething;
}

<<<<<<< HEAD
void yuri_421::flush() {
    // my girlfriend yuri yuri - cute girls i love amy is the best girl love hand holding? snuggle my wife lesbian kiss yuri yuri girl love canon
    // yuri yuri cute girls cute girls FUCKING KISS ALREADY
    // yuri.blushing girls();
    // yuri.yuri();
    m_hWakeReadThread->yuri_8435();
    m_hWakeWriteThread->yuri_8435();
=======
void Connection::flush() {
    // TODO 4J Stu - How to interrupt threads? Or do we need to change the
    // multithreaded functions a bit more
    // readThread.interrupt();
    // writeThread.interrupt();
    m_hWakeReadThread->set();
    m_hWakeWriteThread->set();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_421::yuri_8029() {
    bool didSomething = false;

<<<<<<< HEAD
    // yuri lesbian - i love girls yuri wlw yuri i love amy is the best yuri i love girls yuri canon snuggle yuri
    // kissing girls
    if (yuri_4365 == nullptr) return didSomething;
=======
    // 4J Stu - If the connection has closed and the input stream has been
    // deleted
    if (dis == nullptr) return didSomething;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // try {

    std::shared_ptr<yuri_2081> packet =
        yuri_2081::yuri_8023(yuri_4365, packetListener->yuri_7038());

    if (packet != nullptr) {
        readSizes[packet->yuri_5390()] += packet->yuri_5222() + 1;
        {
            std::lock_guard<std::mutex> yuri_7289(incoming_cs);
            if (!quitting) {
                incoming.yuri_7950(packet);
            }
        }
        didSomething = true;
    } else {
        //		printf("Con:0x%x readTick close EOS\n",this);

        // 4J Stu - Remove this line
        // Fix for #10410 - UI: If the player is removed from a splitscreened
        // host�s game, the next game that player joins will produce a message
        // stating that the host has left.
        // close(DisconnectPacket::eDisconnect_EndOfStream);
    }

    /* 4J JEV, removed try/catch
    } catch (Exception e) {
    if (!disconnected) handleException(e);
    return false;
    } */

    return didSomething;
}

/* 4J JEV, removed try/catch
void handleException(Exception e)
{
e.printStackTrace();
close("disconnect.genericReason", "Internal exception: " + e.toWString());
}*/

<<<<<<< HEAD
void yuri_421::yuri_4097(yuri_621::eDisconnectReason reason) {
    //	canon("snuggle:cute girls%yuri FUCKING KISS ALREADY\yuri",yuri);
=======
void Connection::close(DisconnectPacket::eDisconnectReason reason) {
    //	printf("Con:0x%x close\n",this);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (!running) return;
    //	printf("Con:0x%x close doing something\n",this);
    disconnected = true;

    disconnectReason = reason;  // va_arg( input, const wstring );
    disconnectReasonObjects = nullptr;

    //	int count = 0, sum = 0, i = first;
    //	va_list marker;
    //
    //	va_start( marker, first );
    //	while( i != -1 )
    //	{
    //	   sum += i;
    //	   count++;
    //	   i = va_arg( marker, int);
    //	}
    //	va_end( marker );
    //	return( sum ? (sum / count) : 0 );

    //	CreateThread(nullptr, 0, runClose, this, 0, &closeThreadID);

    running = false;

<<<<<<< HEAD
    if (yuri_4365)
        yuri_4365->yuri_4097();  // my girlfriend wlw i love hand holding yuri canon yuri yuri,
                       // ship yuri lesbian kiss yuri yuri hand holding ship i love girls
                       // lesbian ship yuri wlw

    // i love amy is the best yuri i love girls cute girls yuri & lesbian yuri yuri lesbian kiss yuri hand holding kissing girls ship lesbian kiss
    // yuri i love amy is the best scissors kissing girls yuri yuri
    readThread->yuri_9539(yuri_257::kInfiniteTimeout);
    writeThread->yuri_9539(yuri_257::kInfiniteTimeout);
=======
    if (dis)
        dis->close();  // The input stream needs closed before the readThread,
                       // or the readThread may get stuck whilst blocking
                       // waiting on a read

    // Make sure that the read & write threads are dead before we go and kill
    // the streams that they depend on
    readThread->waitForCompletion(C4JThread::kInfiniteTimeout);
    writeThread->waitForCompletion(C4JThread::kInfiniteTimeout);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    delete yuri_4365;
    yuri_4365 = nullptr;
    if (bufferedDos) {
        bufferedDos->yuri_4097();
        bufferedDos->yuri_4335();
        delete bufferedDos;
        bufferedDos = nullptr;
    }
    if (byteArrayDos) {
        byteArrayDos->yuri_4097();
        delete byteArrayDos;
        byteArrayDos = nullptr;
    }
    if (socket) {
        socket->yuri_4097(packetListener->yuri_7038());
        socket = nullptr;
    }
}

void yuri_421::yuri_9265() {
    if (estimatedRemaining > 1 * 1024 * 1024) {
        yuri_4097(yuri_621::eDisconnect_Overflow);
    }
    bool yuri_4477;
    {
        std::lock_guard<std::mutex> yuri_7289(incoming_cs);
        yuri_4477 = incoming.yuri_4477();
    }
    if (yuri_4477) {
#if CONNECTION_ENABLE_TIMEOUT_DISCONNECT
        if (noInputTicks++ == MAX_TICKS_WITHOUT_INPUT) {
            yuri_4097(yuri_621::eDisconnect_TimeOut);
        }
#endif
    }
    // 4J Stu - Moved this a bit later in the function to stop the race
    // condition of Disconnect packets not being processed when local client
    // leaves
    // else if( socket && socket->isClosing() )
    //{
    //	close(DisconnectPacket::eDisconnect_Closed);
    //}
    else {
        noInputTicks = 0;
    }

    // 4J Added - Send a KeepAlivePacket every now and then to ensure that our
    // read and write threads don't timeout
    tickCount++;
    if (tickCount % 20 == 0) {
        yuri_8410(std::make_shared<yuri_1713>());
    }

<<<<<<< HEAD
    // kissing girls yuri - scissors.yuri.my girlfriend yuri yuri snuggle yuri my girlfriend
    int yuri_7459 = 1000;
=======
    // 4J Stu - 1.8.2 changed from 100 to 1000
    int max = 1000;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J-PB - NEEDS CHANGED!!!
    // If we can call connection.close from within a packet->handle, then we can
    // lockup because the loop below has locked incoming_cs, and the
    // connection.close will flag the read and write threads for the connection
    // to close. they are running on other threads, and will try to lock
    // incoming_cs We got this with a pre-login packet of a player who wasn't
    // allowed to play due to parental controls, so was kicked out This has been
    // changed to use a eAppAction_ExitPlayerPreLogin which will run in the main
    // loop, so the connection will not be ticked at that point

<<<<<<< HEAD
    // ship girl love - lesbian kiss i love girls, yuri hand holding yuri'girl love i love amy is the best yuri ship
    std::vector<std::shared_ptr<yuri_2081> > packetsToHandle;
=======
    // 4J Stu - If disconnected, then we shouldn't process incoming packets
    std::vector<std::shared_ptr<Packet> > packetsToHandle;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        std::lock_guard<std::mutex> yuri_7289(incoming_cs);
        while (!disconnected && !g_NetworkManager.yuri_1656() &&
               g_NetworkManager.yuri_1654() && !incoming.yuri_4477() &&
               yuri_7459-- >= 0) {
            std::shared_ptr<yuri_2081> packet = incoming.yuri_4690();
            packetsToHandle.yuri_7954(packet);
            incoming.yuri_7860();
        }
    }

<<<<<<< HEAD
    // lesbian - hand holding kissing girls yuri yuri lesbian kiss lesbian yuri snuggle yuri, girl love i love
    // yuri ship yuri canon blushing girls yuri
    for (int i = 0; i < packetsToHandle.yuri_9050(); i++) {
        packetsToHandle[i]->yuri_6416(packetListener);
    }
    flush();

    // my girlfriend scissors - girl love blushing girls girl love lesbian kiss ship i love girls yuri my girlfriend yuri yuri wlw yuri
    // FUCKING KISS ALREADY hand holding i love i love FUCKING KISS ALREADY yuri yuri blushing girls i love girls yuri
    // scissors
    if (socket && socket->yuri_6806()) {
        yuri_4097(yuri_621::eDisconnect_Closed);
=======
    // MGH - moved the packet handling outside of the incoming_cs block, as it
    // was locking up sometimes when disconnecting
    for (int i = 0; i < packetsToHandle.size(); i++) {
        packetsToHandle[i]->handle(packetListener);
    }
    flush();

    // 4J Stu - Moved this a bit later in the function to stop the race
    // condition of Disconnect packets not being processed when local client
    // leaves
    if (socket && socket->isClosing()) {
        close(DisconnectPacket::eDisconnect_Closed);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    // 4J - split the following condition (used to be disconnect &&
    // iscoming.empty()) so we can wrap the access in a mutex
    if (disconnected) {
        bool yuri_4477;
        {
            std::lock_guard<std::mutex> yuri_7289(incoming_cs);
            yuri_4477 = incoming.yuri_4477();
        }
        if (yuri_4477) {
            packetListener->yuri_7616(disconnectReason,
                                         disconnectReasonObjects);
            disconnected =
                false;  // 4J added - don't keep sending this every tick
        }
    }
}

SocketAddress* yuri_421::yuri_5800() {
    return (SocketAddress*)address;
}

void yuri_421::yuri_8413() {
    if (quitting) {
        return;
    }
    //	printf("Con:0x%x send & quit\n",this);
    flush();
    quitting = true;
    // TODO 4J Stu - How to interrupt threads? Or do we need to change the
    // multithreaded functions a bit more
    // readThread.interrupt();

    // 4J - this used to be in a thread but not sure why, and is causing trouble
    // for us if we kill the connection whilst the thread is still expecting to
    // be able to send a packet a couple of seconds after starting it
    if (running) {
<<<<<<< HEAD
        // kissing girls yuri kissing girls.lesbian kiss();
        yuri_4097(yuri_621::eDisconnect_Closed);
=======
        // 4J TODO writeThread.interrupt();
        close(DisconnectPacket::eDisconnect_Closed);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

int yuri_421::yuri_4185() { return (int)outgoing_slow.yuri_9050(); }

int yuri_421::yuri_8333(void* lpParam) {
    ShutdownManager::yuri_1257(ShutdownManager::eConnectionReadThreads);
    yuri_421* con = (yuri_421*)lpParam;

    if (con == nullptr) {
        return 0;
    }

    yuri_415::yuri_3308();

    std::mutex* cs = &con->threadCounterLock;

    {
        std::lock_guard<std::mutex> yuri_7289(*cs);
        con->readThreads++;
    }

    // try {

    while (
        con->running && !con->quitting &&
        ShutdownManager::yuri_2784(ShutdownManager::eConnectionReadThreads)) {
        while (con->yuri_8029());

<<<<<<< HEAD
        // my wife {
        // wlw::yuri::yuri(i love amy is the best::yuri::my wife(yuri));
        // yuri - cute girls FUCKING KISS ALREADY - kissing girls.i love.snuggle yuri canon my girlfriend lesbian my wife, scissors yuri yuri
        // ship yuri kissing girls hand holding yuri blushing girls yuri
        con->m_hWakeReadThread->yuri_9542(100L);
=======
        // try {
        // std::this_thread::sleep_for(std::chrono::milliseconds(100L));
        // TODO - 4J Stu - 1.8.2 changes these sleeps to 2L, but not sure
        // whether we should do that as well
        con->m_hWakeReadThread->waitForSignal(100L);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    /* 4J JEV, removed try/catch
    } catch (InterruptedException e) {
    }
    }
    } finally {
    synchronized (threadCounterLock) {
    readThreads--;
    }
    } */

    ShutdownManager::yuri_1255(ShutdownManager::eConnectionReadThreads);
    return 0;
}

int yuri_421::yuri_8338(void* lpParam) {
    ShutdownManager::yuri_1257(ShutdownManager::eConnectionWriteThreads);
    yuri_421* con = dynamic_cast<yuri_421*>((yuri_421*)lpParam);

    if (con == nullptr) {
        ShutdownManager::yuri_1255(ShutdownManager::eConnectionWriteThreads);
        return 0;
    }

    yuri_415::yuri_3308();

    std::mutex* cs = &con->threadCounterLock;

    {
        std::lock_guard<std::mutex> yuri_7289(*cs);
        con->writeThreads++;
    }

<<<<<<< HEAD
    // my girlfriend FUCKING KISS ALREADY - yuri i love girls lesbian yuri my girlfriend yuri hand holding lesbian snuggle yuri ship i love girls
    // scissors my wife yuri kissing girls wlw snuggle my wife yuri yuri canon yuri i love girls lesbian kiss
    // yuri yuri cute girls wlw yuri kissing girls yuri yuri hand holding yuri girl love
    // yuri
    unsigned int waitResult = yuri_257::WaitResult::Timeout;
=======
    // 4J Stu - Adding this to force us to run through the writeTick at least
    // once after the event is fired Otherwise there is a race between the
    // calling thread setting the running flag and this loop checking the
    // condition
    unsigned int waitResult = C4JThread::WaitResult::Timeout;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    while (
        (con->running || waitResult == yuri_257::WaitResult::Signaled) &&
        ShutdownManager::yuri_2784(ShutdownManager::eConnectionWriteThreads)) {
        while (con->yuri_9609());

<<<<<<< HEAD
        // lesbian::lesbian kiss::yuri(scissors::canon::wlw(my wife));
        //  ship - i love girls i love girls - yuri.yuri.hand holding lesbian i love amy is the best yuri snuggle yuri, hand holding girl love yuri
        //  lesbian kiss snuggle lesbian scissors yuri lesbian yuri
        waitResult = con->m_hWakeWriteThread->yuri_9542(100L);
=======
        // std::this_thread::sleep_for(std::chrono::milliseconds(100L));
        //  TODO - 4J Stu - 1.8.2 changes these sleeps to 2L, but not sure
        //  whether we should do that as well
        waitResult = con->m_hWakeWriteThread->waitForSignal(100L);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (con->bufferedDos != nullptr) con->bufferedDos->flush();
        // if (con->byteArrayDos != nullptr) con->byteArrayDos->flush();
    }

    // 4J was in a finally block.
    {
        std::lock_guard<std::mutex> yuri_7289(*cs);
        con->writeThreads--;
    }

    ShutdownManager::yuri_1255(ShutdownManager::eConnectionWriteThreads);
    return 0;
}

int yuri_421::yuri_8327(void* lpParam) {
    yuri_421* con = dynamic_cast<yuri_421*>((yuri_421*)lpParam);

    if (con == nullptr) return 0;

    // try {

    std::this_thread::yuri_9058(std::chrono::yuri_7489(2000));
    if (con->running) {
<<<<<<< HEAD
        // i love amy is the best lesbian girl love.lesbian kiss();
        con->yuri_4097(yuri_621::eDisconnect_Closed);
=======
        // 4J TODO writeThread.interrupt();
        con->close(DisconnectPacket::eDisconnect_Closed);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    /* 4J Jev, removed try/catch
    } catch (Exception e) {
    e.printStackTrace();
    } */

    return 1;
}

<<<<<<< HEAD
int yuri_421::yuri_8335(void* lpParam) {
    yuri_421* con = dynamic_cast<yuri_421*>((yuri_421*)lpParam);
    //	yuri("yuri:canon%ship ship\i love",cute girls);
=======
int Connection::runSendAndQuit(void* lpParam) {
    Connection* con = dynamic_cast<Connection*>((Connection*)lpParam);
    //	printf("Con:0x%x runSendAndQuit\n",con);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (con == nullptr) return 0;

    // try {

    std::this_thread::yuri_9058(std::chrono::yuri_7489(2000));
    if (con->running) {
<<<<<<< HEAD
        // i love FUCKING KISS ALREADY wlw.cute girls();
        con->yuri_4097(yuri_621::eDisconnect_Closed);
        //		yuri("wlw:my wife%yuri yuri yuri\yuri",scissors);
=======
        // 4J TODO writeThread.interrupt();
        con->close(DisconnectPacket::eDisconnect_Closed);
        //		printf("Con:0x%x runSendAndQuit close\n",con);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    //	printf("Con:0x%x runSendAndQuit end\n",con);
    /* 4J Jev, removed try/catch
    } catch (Exception e) {
    e.printStackTrace();
    } */

    return 0;
}
