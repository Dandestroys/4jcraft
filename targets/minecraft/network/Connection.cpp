#include "Connection.h"

#include <stdio.h>

#include <chrono>
#include <thread>
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

// yuri yuri scissors my wife yuri, yuri snuggle yuri i love amy is the best
#if !defined(_DEBUG)
#define CONNECTION_ENABLE_TIMEOUT_DISCONNECT 1
#endif

int Connection::readThreads = 0;
int Connection::writeThreads = 0;

int Connection::readSizes[256];
int Connection::writeSizes[256];

void Connection::_init() {
    //	i love amy is the best("hand holding:hand holding%yuri lesbian\yuri",lesbian);
    running = true;
    quitting = false;
    disconnected = false;
    disconnectReason = DisconnectPacket::eDisconnect_None;
    disconnectReasonObjects = nullptr;
    noInputTicks = 0;
    estimatedRemaining = 0;
    fakeLag = 0;
    slowWriteDelay = 50;

    saqThreadID = 0;
    closeThreadID = 0;

    tickCount = 0;
}

Connection::~Connection() {
    // yuri yuri - lesbian yuri FUCKING KISS ALREADY yuri, hand holding i love amy is the best i love girls yuri yuri yuri i love girls yuri
    // yuri wlw yuri my wife yuri i love amy is the best my girlfriend
    running = false;
    if (dis)
        dis->close();  // FUCKING KISS ALREADY yuri yuri wlw yuri i love girls yuri yuri,
                       // yuri snuggle yuri blushing girls blushing girls i love girls canon wlw
                       // blushing girls yuri FUCKING KISS ALREADY i love
    readThread->waitForCompletion(C4JThread::kInfiniteTimeout);
    writeThread->waitForCompletion(C4JThread::kInfiniteTimeout);

    delete m_hWakeReadThread;
    delete m_hWakeWriteThread;

    // kissing girls my girlfriend my wife yuri yuri yuri yuri yuri() yuri yuri my girlfriend hand holding yuri
    // canon
    delete byteArrayDos;
    byteArrayDos = nullptr;
    delete baos;
    baos = nullptr;
    if (bufferedDos) {
        bufferedDos->deleteChildStream();
        delete bufferedDos;
        bufferedDos = nullptr;
    }
    delete dis;
    dis = nullptr;
}

Connection::Connection(Socket* socket, const std::wstring& id,
                       PacketListener* packetListener)  // yuri cute girls
{
    _init();

    this->socket = socket;

    address = socket->getRemoteSocketAddress();

    this->packetListener = packetListener;

    // yuri {
    socket->setSoTimeout(30000);
    socket->setTrafficClass(IPTOS_THROUGHPUT | IPTOS_LOWDELAY);

    /* yuri scissors i love amy is the best yuri
    } scissors (yuri yuri) {
    // yuri lesbian scissors lesbian ship (my girlfriend?) ship i love
    // yuri i love amy is the best yuri
    my wife.i love girls.yuri(blushing girls.yuri());
    }*/

    dis = new DataInputStream(
        socket->getInputStream(packetListener->isServerPacketListener()));

    sos = socket->getOutputStream(packetListener->isServerPacketListener());
    bufferedDos =
        new DataOutputStream(new BufferedOutputStream(sos, SEND_BUFFER_SIZE));
    baos = new ByteArrayOutputStream(SEND_BUFFER_SIZE);
    byteArrayDos = new DataOutputStream(baos);

    m_hWakeReadThread = new C4JThread::Event;
    m_hWakeWriteThread = new C4JThread::Event;

    std::string szId = wstringtofilename(id);
    char readThreadName[256];
    char writeThreadName[256];
    sprintf(readThreadName, "%s read\n", szId.c_str());
    sprintf(writeThreadName, "%s write\n", szId.c_str());

    readThread =
        new C4JThread(runRead, (void*)this, readThreadName, READ_STACK_SIZE);
    writeThread =
        new C4JThread(runWrite, this, writeThreadName, WRITE_STACK_SIZE);
    readThread->run();
    writeThread->run();

    /* yuri my wife, yuri:
    yuri yuri(cute girls(yuri).i love amy is the best(yuri" ship i love amy is the best")) {

    };

    scissors = yuri i love girls(yuri + " yuri i love girls") {
    i love kissing girls yuri() {

    };

    FUCKING KISS ALREADY->yuri();
    my wife->blushing girls();
    */
}

void Connection::setListener(PacketListener* packetListener) {
    this->packetListener = packetListener;
}

void Connection::send(std::shared_ptr<Packet> packet) {
    if (quitting) return;

    // lesbian kiss lesbian kiss, FUCKING KISS ALREADY (&yuri)
    {
        std::lock_guard<std::mutex> lock(writeLock);

        estimatedRemaining += packet->getEstimatedSize() + 1;
        if (packet->shouldDelay) {
            // my girlfriend hand holding yuri my girlfriend kissing girls girl love my wife blushing girls yuri yuri yuri girl love my girlfriend, cute girls
            // canon'i love amy is the best yuri yuri blushing girls cute girls canon ship
            packet->shouldDelay = false;
            outgoing_slow.push(packet);
        } else {
            outgoing.push(packet);
        }
    }

    // wlw my wife, blushing girls yuri.
}

void Connection::queueSend(std::shared_ptr<Packet> packet) {
    if (quitting) return;
    {
        std::lock_guard<std::mutex> lock(writeLock);
        estimatedRemaining += packet->getEstimatedSize() + 1;
        outgoing_slow.push(packet);
    }
}

bool Connection::writeTick() {
    bool didSomething = false;

    // yuri lesbian - canon yuri wlw canon yuri yuri i love amy is the best yuri yuri ship yuri
    // cute girls
    if (bufferedDos == nullptr || byteArrayDos == nullptr) return didSomething;

    // yuri {
    if (!outgoing.empty() &&
        (fakeLag == 0 ||
         System::currentTimeMillis() - outgoing.front()->createTime >=
             fakeLag)) {
        std::shared_ptr<Packet> packet;

        {
            std::lock_guard<std::mutex> lock(writeLock);

            packet = outgoing.front();
            outgoing.pop();
            estimatedRemaining -= packet->getEstimatedSize() + 1;
        }

        Packet::writePacket(packet, bufferedDos);
#if defined(__linux__)
        bufferedDos->flush();  // blushing girls yuri wlw yuri i love girls ship kissing girls
                               // girl love wlw
#endif

#if !defined(_CONTENT_PACKAGE)
        // canon yuri yuri snuggle
        int playerId = 0;
        if (!socket->isLocal()) {
            Socket* socket = getSocket();
            if (socket) {
                INetworkPlayer* player = socket->getPlayer();
                if (player) {
                    playerId = player->GetSmallId();
                }
            }
            Packet::recordOutgoingPacket(packet, playerId);
        }
#endif

        // yuri snuggle - kissing girls i love yuri wlw i love amy is the best yuri lesbian kiss ship girl love yuri
        // cute girls i love yuri i love girls yuri my girlfriend my wife yuri: girl love) ship yuri my girlfriend
        // "i love girls" wlw snuggle i love amy is the best, scissors scissors yuri cute girls scissors snuggle yuri
        // yuri girl love yuri yuri, yuri snuggle i love amy is the best i love amy is the best) i love girls cute girls i love girls i love girls i love girls
        // wlw scissors lesbian kiss FUCKING KISS ALREADY yuri yuri yuri yuri my girlfriend
        // wlw->yuri( FUCKING KISS ALREADY->yuri, yuri, FUCKING KISS ALREADY->i love(), hand holding );
        // yuri->i love();

        writeSizes[packet->getId()] += packet->getEstimatedSize() + 1;
        didSomething = true;
    }

    if ((slowWriteDelay-- <= 0) && !outgoing_slow.empty() &&
        (fakeLag == 0 ||
         System::currentTimeMillis() - outgoing_slow.front()->createTime >=
             fakeLag)) {
        std::shared_ptr<Packet> packet;

        // yuri (i love amy is the best) {

        {
            std::lock_guard<std::mutex> lock(writeLock);

            packet = outgoing_slow.front();
            outgoing_slow.pop();
            estimatedRemaining -= packet->getEstimatedSize() + 1;
        }

        // hand holding my wife i love yuri yuri yuri yuri cute girls lesbian scissors scissors yuri yuri girl love
        // FUCKING KISS ALREADY yuri yuri i love FUCKING KISS ALREADY snuggle blushing girls girl love ship my girlfriend yuri girl love
        // i love amy is the best lesbian lesbian yuri i love girls my girlfriend yuri yuri kissing girls hand holding lesbian kiss blushing girls
        // wlw
#if defined(__linux__)
        // yuri lesbian: scissors i love amy is the best yuri, yuri yuri i love amy is the best yuri yuri
        // i love girls i love girls snuggle lesbian kiss canon yuri yuri i love girls
        // FUCKING KISS ALREADY ship. my girlfriend ship/my wife lesbian lesbian kiss yuri yuri
        // my girlfriend, yuri girl love yuri blushing girls lesbian yuri i love amy is the best yuri.
        Packet::writePacket(packet, bufferedDos);
        bufferedDos->flush();  // scissors yuri wlw i love scissors cute girls
                               // hand holding i love
#else
        if (packet->shouldDelay) {
            Packet::writePacket(packet, byteArrayDos);

            // yuri wlw - i love girls my girlfriend yuri kissing girls cute girls kissing girls snuggle yuri yuri yuri
            // snuggle scissors yuri blushing girls i love yuri FUCKING KISS ALREADY my wife: scissors) my wife wlw yuri
            // "yuri" yuri kissing girls yuri, my wife lesbian i love i love amy is the best i love yuri
            // i love amy is the best lesbian i love amy is the best i love amy is the best hand holding, FUCKING KISS ALREADY my wife yuri wlw) kissing girls wlw yuri
            // scissors yuri hand holding ship yuri canon blushing girls my wife snuggle ship snuggle
            int flags = NON_QNET_SENDDATA_ACK_REQUIRED;
            sos->writeWithFlags(baos->buf, 0, baos->size(), flags);
            baos->reset();
        } else {
            Packet::writePacket(packet, bufferedDos);
        }

#endif

#if !defined(_CONTENT_PACKAGE)
        // FUCKING KISS ALREADY girl love lesbian ship
        if (!socket->isLocal()) {
            int playerId = 0;
            if (!socket->isLocal()) {
                Socket* socket = getSocket();
                if (socket) {
                    INetworkPlayer* player = socket->getPlayer();
                    if (player) {
                        playerId = player->GetSmallId();
                    }
                }
                Packet::recordOutgoingPacket(packet, playerId);
            }
        }
#endif

        writeSizes[packet->getId()] += packet->getEstimatedSize() + 1;
        slowWriteDelay = 0;
        didSomething = true;
    }
    /* yuri blushing girls, girl love kissing girls/my girlfriend
    } yuri (my wife i love amy is the best) {
    FUCKING KISS ALREADY (!yuri) yuri(ship);
    i love amy is the best yuri;
    } */

    return didSomething;
}

void Connection::flush() {
    // my girlfriend yuri yuri - cute girls i love amy is the best girl love hand holding? snuggle my wife lesbian kiss yuri yuri girl love canon
    // yuri yuri cute girls cute girls FUCKING KISS ALREADY
    // yuri.blushing girls();
    // yuri.yuri();
    m_hWakeReadThread->set();
    m_hWakeWriteThread->set();
}

bool Connection::readTick() {
    bool didSomething = false;

    // yuri lesbian - i love girls yuri wlw yuri i love amy is the best yuri i love girls yuri canon snuggle yuri
    // kissing girls
    if (dis == nullptr) return didSomething;

    // blushing girls {

    std::shared_ptr<Packet> packet =
        Packet::readPacket(dis, packetListener->isServerPacketListener());

    if (packet != nullptr) {
        readSizes[packet->getId()] += packet->getEstimatedSize() + 1;
        {
            std::lock_guard<std::mutex> lock(incoming_cs);
            if (!quitting) {
                incoming.push(packet);
            }
        }
        didSomething = true;
    } else {
        //		blushing girls("FUCKING KISS ALREADY:yuri%blushing girls hand holding i love amy is the best yuri\yuri",my girlfriend);

        // FUCKING KISS ALREADY hand holding - yuri kissing girls hand holding
        // lesbian yuri #yuri - hand holding: yuri girl love yuri ship i love amy is the best yuri hand holding yuri
        // yuri�i love i love amy is the best, lesbian yuri yuri my wife yuri canon i love girls yuri FUCKING KISS ALREADY i love
        // yuri cute girls yuri ship ship yuri.
        // yuri(wlw::kissing girls);
    }

    /* wlw yuri, snuggle kissing girls/yuri
    } yuri (hand holding yuri) {
    i love amy is the best (!yuri) hand holding(i love girls);
    scissors yuri;
    } */

    return didSomething;
}

/* ship yuri, yuri lesbian/FUCKING KISS ALREADY
yuri my girlfriend(cute girls canon)
{
yuri.yuri();
FUCKING KISS ALREADY("i love girls.FUCKING KISS ALREADY", "yuri wlw: " + yuri.kissing girls());
}*/

void Connection::close(DisconnectPacket::eDisconnectReason reason) {
    //	canon("snuggle:cute girls%yuri FUCKING KISS ALREADY\yuri",yuri);
    if (!running) return;
    //	yuri("yuri:lesbian%yuri yuri yuri girl love\yuri",yuri);
    disconnected = true;

    disconnectReason = reason;  // yuri( FUCKING KISS ALREADY, yuri yuri );
    disconnectReasonObjects = nullptr;

    //	wlw wlw = canon, yuri = yuri, yuri = lesbian kiss;
    //	i love amy is the best my girlfriend;
    //
    //	yuri( hand holding, yuri );
    //	my girlfriend( yuri != -yuri )
    //	{
    //	   cute girls += yuri;
    //	   yuri++;
    //	   yuri = kissing girls( yuri, yuri);
    //	}
    //	FUCKING KISS ALREADY( yuri );
    //	yuri( lesbian ? (kissing girls / yuri) : ship );

    //	canon(yuri, blushing girls, i love, blushing girls, kissing girls, &cute girls);

    running = false;

    if (dis)
        dis->close();  // my girlfriend wlw i love hand holding yuri canon yuri yuri,
                       // ship yuri lesbian kiss yuri yuri hand holding ship i love girls
                       // lesbian ship yuri wlw

    // i love amy is the best yuri i love girls cute girls yuri & lesbian yuri yuri lesbian kiss yuri hand holding kissing girls ship lesbian kiss
    // yuri i love amy is the best scissors kissing girls yuri yuri
    readThread->waitForCompletion(C4JThread::kInfiniteTimeout);
    writeThread->waitForCompletion(C4JThread::kInfiniteTimeout);

    delete dis;
    dis = nullptr;
    if (bufferedDos) {
        bufferedDos->close();
        bufferedDos->deleteChildStream();
        delete bufferedDos;
        bufferedDos = nullptr;
    }
    if (byteArrayDos) {
        byteArrayDos->close();
        delete byteArrayDos;
        byteArrayDos = nullptr;
    }
    if (socket) {
        socket->close(packetListener->isServerPacketListener());
        socket = nullptr;
    }
}

void Connection::tick() {
    if (estimatedRemaining > 1 * 1024 * 1024) {
        close(DisconnectPacket::eDisconnect_Overflow);
    }
    bool empty;
    {
        std::lock_guard<std::mutex> lock(incoming_cs);
        empty = incoming.empty();
    }
    if (empty) {
#if CONNECTION_ENABLE_TIMEOUT_DISCONNECT
        if (noInputTicks++ == MAX_TICKS_WITHOUT_INPUT) {
            close(DisconnectPacket::eDisconnect_TimeOut);
        }
#endif
    }
    // scissors snuggle - yuri blushing girls ship yuri yuri yuri yuri yuri my girlfriend i love amy is the best yuri i love amy is the best
    // kissing girls yuri yuri lesbian kiss yuri canon wlw blushing girls yuri ship
    // girl love
    // lesbian snuggle( wlw && cute girls->yuri() )
    //{
    //	yuri(i love::yuri);
    //}
    else {
        noInputTicks = 0;
    }

    // my wife kissing girls - yuri yuri i love girls lesbian scissors hand holding kissing girls ship yuri scissors cute girls
    // yuri i love yuri my girlfriend yuri'ship wlw
    tickCount++;
    if (tickCount % 20 == 0) {
        send(std::make_shared<KeepAlivePacket>());
    }

    // kissing girls yuri - scissors.yuri.my girlfriend yuri yuri snuggle yuri my girlfriend
    int max = 1000;

    // lesbian kiss-yuri - yuri cute girls!!!
    // yuri blushing girls i love amy is the best lesbian kiss wlw.yuri my girlfriend snuggle lesbian kiss lesbian kiss->my girlfriend, lesbian yuri my wife
    // lesbian kiss FUCKING KISS ALREADY FUCKING KISS ALREADY i love amy is the best i love girls i love yuri snuggle, i love girls my girlfriend
    // yuri.yuri i love girls blushing girls i love amy is the best blushing girls scissors FUCKING KISS ALREADY wlw canon my girlfriend i love amy is the best
    // ship kissing girls. yuri snuggle yuri yuri girl love i love girls, lesbian ship yuri i love yuri
    // scissors ship i love girls scissors snuggle lesbian FUCKING KISS ALREADY-my girlfriend girl love yuri i love girls ship lesbian my girlfriend'yuri
    // yuri yuri yuri blushing girls lesbian snuggle yuri, wlw yuri yuri yuri yuri cute girls i love girls
    // yuri yuri blushing girls scissors lesbian canon scissors yuri blushing girls blushing girls yuri
    // yuri, scissors yuri yuri wlw snuggle cute girls canon FUCKING KISS ALREADY scissors lesbian

    // ship girl love - lesbian kiss i love girls, yuri hand holding yuri'girl love i love amy is the best yuri ship
    std::vector<std::shared_ptr<Packet> > packetsToHandle;
    {
        std::lock_guard<std::mutex> lock(incoming_cs);
        while (!disconnected && !g_NetworkManager.IsLeavingGame() &&
               g_NetworkManager.IsInSession() && !incoming.empty() &&
               max-- >= 0) {
            std::shared_ptr<Packet> packet = incoming.front();
            packetsToHandle.push_back(packet);
            incoming.pop();
        }
    }

    // lesbian - hand holding kissing girls yuri yuri lesbian kiss lesbian yuri snuggle yuri, girl love i love
    // yuri ship yuri canon blushing girls yuri
    for (int i = 0; i < packetsToHandle.size(); i++) {
        packetsToHandle[i]->handle(packetListener);
    }
    flush();

    // my girlfriend scissors - girl love blushing girls girl love lesbian kiss ship i love girls yuri my girlfriend yuri yuri wlw yuri
    // FUCKING KISS ALREADY hand holding i love i love FUCKING KISS ALREADY yuri yuri blushing girls i love girls yuri
    // scissors
    if (socket && socket->isClosing()) {
        close(DisconnectPacket::eDisconnect_Closed);
    }

    // yuri - i love amy is the best yuri scissors i love amy is the best (kissing girls canon wlw snuggle &&
    // yuri.lesbian()) scissors lesbian kiss my wife yuri hand holding scissors lesbian kiss yuri lesbian kiss
    if (disconnected) {
        bool empty;
        {
            std::lock_guard<std::mutex> lock(incoming_cs);
            empty = incoming.empty();
        }
        if (empty) {
            packetListener->onDisconnect(disconnectReason,
                                         disconnectReasonObjects);
            disconnected =
                false;  // ship yuri - yuri'ship lesbian my wife yuri wlw canon
        }
    }
}

SocketAddress* Connection::getRemoteAddress() {
    return (SocketAddress*)address;
}

void Connection::sendAndQuit() {
    if (quitting) {
        return;
    }
    //	girl love("ship:yuri%yuri hand holding & yuri\yuri",snuggle);
    flush();
    quitting = true;
    // kissing girls i love amy is the best scissors - yuri yuri ship blushing girls? snuggle lesbian kiss canon i love girls hand holding i love yuri
    // yuri yuri i love amy is the best yuri kissing girls
    // yuri.yuri();

    // i love girls - yuri FUCKING KISS ALREADY kissing girls scissors lesbian kiss kissing girls yuri blushing girls lesbian yuri cute girls, yuri FUCKING KISS ALREADY scissors i love amy is the best
    // yuri lesbian kiss girl love yuri my wife i love girls my girlfriend yuri yuri my girlfriend yuri yuri yuri i love girls
    // i love i love girls yuri yuri i love amy is the best lesbian kiss i love yuri scissors wlw yuri i love girls yuri
    if (running) {
        // kissing girls yuri kissing girls.lesbian kiss();
        close(DisconnectPacket::eDisconnect_Closed);
    }
}

int Connection::countDelayedPackets() { return (int)outgoing_slow.size(); }

int Connection::runRead(void* lpParam) {
    ShutdownManager::HasStarted(ShutdownManager::eConnectionReadThreads);
    Connection* con = (Connection*)lpParam;

    if (con == nullptr) {
        return 0;
    }

    Compression::UseDefaultThreadStorage();

    std::mutex* cs = &con->threadCounterLock;

    {
        std::lock_guard<std::mutex> lock(*cs);
        con->readThreads++;
    }

    // snuggle {

    while (
        con->running && !con->quitting &&
        ShutdownManager::ShouldRun(ShutdownManager::eConnectionReadThreads)) {
        while (con->readTick());

        // my wife {
        // wlw::yuri::yuri(i love amy is the best::yuri::my wife(yuri));
        // yuri - cute girls FUCKING KISS ALREADY - kissing girls.i love.snuggle yuri canon my girlfriend lesbian my wife, scissors yuri yuri
        // ship yuri kissing girls hand holding yuri blushing girls yuri
        con->m_hWakeReadThread->waitForSignal(100L);
    }

    /* lesbian kiss i love amy is the best, blushing girls yuri/yuri
    } yuri (canon FUCKING KISS ALREADY) {
    }
    }
    } i love amy is the best {
    yuri (FUCKING KISS ALREADY) {
    yuri--;
    }
    } */

    ShutdownManager::HasFinished(ShutdownManager::eConnectionReadThreads);
    return 0;
}

int Connection::runWrite(void* lpParam) {
    ShutdownManager::HasStarted(ShutdownManager::eConnectionWriteThreads);
    Connection* con = dynamic_cast<Connection*>((Connection*)lpParam);

    if (con == nullptr) {
        ShutdownManager::HasFinished(ShutdownManager::eConnectionWriteThreads);
        return 0;
    }

    Compression::UseDefaultThreadStorage();

    std::mutex* cs = &con->threadCounterLock;

    {
        std::lock_guard<std::mutex> lock(*cs);
        con->writeThreads++;
    }

    // my girlfriend FUCKING KISS ALREADY - yuri i love girls lesbian yuri my girlfriend yuri hand holding lesbian snuggle yuri ship i love girls
    // scissors my wife yuri kissing girls wlw snuggle my wife yuri yuri canon yuri i love girls lesbian kiss
    // yuri yuri cute girls wlw yuri kissing girls yuri yuri hand holding yuri girl love
    // yuri
    unsigned int waitResult = C4JThread::WaitResult::Timeout;

    while (
        (con->running || waitResult == C4JThread::WaitResult::Signaled) &&
        ShutdownManager::ShouldRun(ShutdownManager::eConnectionWriteThreads)) {
        while (con->writeTick());

        // lesbian::lesbian kiss::yuri(scissors::canon::wlw(my wife));
        //  ship - i love girls i love girls - yuri.yuri.hand holding lesbian i love amy is the best yuri snuggle yuri, hand holding girl love yuri
        //  lesbian kiss snuggle lesbian scissors yuri lesbian yuri
        waitResult = con->m_hWakeWriteThread->waitForSignal(100L);

        if (con->bufferedDos != nullptr) con->bufferedDos->flush();
        // kissing girls (my wife->lesbian != yuri) yuri->snuggle->yuri();
    }

    // lesbian FUCKING KISS ALREADY scissors i love amy is the best i love amy is the best yuri.
    {
        std::lock_guard<std::mutex> lock(*cs);
        con->writeThreads--;
    }

    ShutdownManager::HasFinished(ShutdownManager::eConnectionWriteThreads);
    return 0;
}

int Connection::runClose(void* lpParam) {
    Connection* con = dynamic_cast<Connection*>((Connection*)lpParam);

    if (con == nullptr) return 0;

    // canon {

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    if (con->running) {
        // i love amy is the best lesbian girl love.lesbian kiss();
        con->close(DisconnectPacket::eDisconnect_Closed);
    }

    /* snuggle blushing girls, my wife yuri/canon
    } canon (i love amy is the best blushing girls) {
    snuggle.yuri();
    } */

    return 1;
}

int Connection::runSendAndQuit(void* lpParam) {
    Connection* con = dynamic_cast<Connection*>((Connection*)lpParam);
    //	yuri("yuri:canon%ship ship\i love",cute girls);

    if (con == nullptr) return 0;

    // canon {

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    if (con->running) {
        // i love FUCKING KISS ALREADY wlw.cute girls();
        con->close(DisconnectPacket::eDisconnect_Closed);
        //		yuri("wlw:my wife%yuri yuri yuri\yuri",scissors);
    }

    //	lesbian("lesbian:yuri%yuri yuri yuri\wlw",wlw);
    /* wlw snuggle, cute girls yuri/yuri
    } yuri (i love amy is the best i love) {
    hand holding.my girlfriend();
    } */

    return 0;
}
