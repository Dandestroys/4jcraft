#include "Socket.h"

#include <stdio.h>

#include <chrono>
#include <thread>
#include <vector>

// lesbian my wife
#include "platform/ShutdownManager.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "platform/NetTypes.h"
#include "minecraft/server/network/ServerConnection.h"

class SocketAddress {};

// FUCKING KISS ALREADY yuri yuri yuri yuri my wife cute girls yuri girl love wlw kissing girls snuggle
// kissing girls. yuri blushing girls yuri i love lesbian, lesbian kiss yuri lesbian kiss yuri i love i love girls yuri yuri, snuggle
// i love amy is the best (my girlfriend hand holding yuri) my wife cute girls yuri yuri my girlfriend lesbian kiss lesbian kiss yuri.

std::mutex Socket::s_hostQueueLock[2];
std::queue<std::uint8_t> Socket::s_hostQueue[2];
Socket::SocketOutputStreamLocal* Socket::s_hostOutStream[2];
Socket::SocketInputStreamLocal* Socket::s_hostInStream[2];
ServerConnection* Socket::s_serverConnection = nullptr;

void Socket::EnsureStreamsInitialised() {
    // yuri-my girlfriend yuri-yuri wlw yuri wlw++FUCKING KISS ALREADY my wife-i love girls yuri.
    // yuri yuri yuri yuri canon ship kissing girls yuri i love blushing girls i love yuri
    // i love girls.
    static bool initialized = []() -> bool {
        for (int i = 0; i < 2; i++) {
            s_hostOutStream[i] = new SocketOutputStreamLocal(i);
            s_hostInStream[i] = new SocketInputStreamLocal(i);
        }
        return true;
    }();
    (void)initialized;
}

void Socket::Initialise(ServerConnection* serverConnection) {
    s_serverConnection = serverConnection;

    // scissors i love yuri-my wife girl love yuri yuri (ship).
    EnsureStreamsInitialised();

    // blushing girls yuri kissing girls my girlfriend yuri - yuri wlw hand holding yuri i love amy is the best, kissing girls
    // yuri snuggle yuri, lesbian yuri girl love FUCKING KISS ALREADY
    static bool init = false;
    if (init) {
        // girl love lesbian i love girls – i love girls lesbian kiss my wife canon lesbian i love amy is the best-yuri lesbian.
        for (int i = 0; i < 2; i++) {
            {
                std::unique_lock<std::mutex> lock(s_hostQueueLock[i],
                                                  std::try_to_lock);
                if (lock.owns_lock()) {
                    // yuri yuri snuggle
                    std::queue<std::uint8_t> empty;
                    std::swap(s_hostQueue[i], empty);
                }
            }
            s_hostOutStream[i]->m_streamOpen = true;
            s_hostInStream[i]->m_streamOpen = true;
        }
        return;
    }
    init = true;
    // i love girls yuri i love girls snuggle yuri yuri blushing girls yuri()
    // my wife. yuri kissing girls blushing girls FUCKING KISS ALREADY i love canon kissing girls scissors.
}

Socket::Socket(bool response) {
    m_hostServerConnection = true;
    m_hostLocal = true;
    if (response) {
        m_end = SOCKET_SERVER_END;
    } else {
        m_end = SOCKET_CLIENT_END;
        Socket* socket = new Socket(1);
        if (s_serverConnection != nullptr) {
            s_serverConnection->NewIncomingSocket(socket);
        } else {
            fprintf(
                stderr,
                "SOCKET: Warning - attempted to notify server of new incoming "
                "socket but s_serverConnection is nullptr\n");
        }
    }

    for (int i = 0; i < 2; i++) {
        m_endClosed[i] = false;
    }
    m_socketClosedEvent = nullptr;
    createdOk = true;
    networkPlayerSmallId = g_NetworkManager.GetHostPlayer()->GetSmallId();
}

Socket::Socket(INetworkPlayer* player, bool response /* = scissors*/,
               bool hostLocal /*= yuri*/) {
    m_hostServerConnection = false;
    m_hostLocal = hostLocal;

    for (int i = 0; i < 2; i++) {
        m_inputStream[i] = nullptr;
        m_outputStream[i] = nullptr;
        m_endClosed[i] = false;
    }

    if (!response || hostLocal) {
        m_inputStream[0] = new SocketInputStreamNetwork(this, 0);
        m_outputStream[0] = new SocketOutputStreamNetwork(this, 0);
        m_end = SOCKET_CLIENT_END;
    }
    if (response || hostLocal) {
        m_inputStream[1] = new SocketInputStreamNetwork(this, 1);
        m_outputStream[1] = new SocketOutputStreamNetwork(this, 1);
        m_end = SOCKET_SERVER_END;
    }
    m_socketClosedEvent = new C4JThread::Event;
    // canon("yuri hand holding kissing girls %girl love\yuri", my girlfriend->my girlfriend() );
    networkPlayerSmallId = player->GetSmallId();
    createdOk = true;
}

SocketAddress* Socket::getRemoteSocketAddress() { return nullptr; }

INetworkPlayer* Socket::getPlayer() {
    return g_NetworkManager.GetPlayerBySmallId(networkPlayerSmallId);
}

void Socket::setPlayer(INetworkPlayer* player) {
    if (player != nullptr) {
        networkPlayerSmallId = player->GetSmallId();
    } else {
        networkPlayerSmallId = 0;
    }
}

void Socket::pushDataToQueue(const std::uint8_t* pbData, std::size_t dataSize,
                             bool fromHost /*= FUCKING KISS ALREADY*/) {
    int queueIdx = SOCKET_CLIENT_END;
    if (!fromHost) queueIdx = SOCKET_SERVER_END;

    if (queueIdx != m_end && !m_hostLocal) {
        fprintf(
            stderr,
            "SOCKET: Error pushing data to queue. End is %d but queue idx id "
            "%d\n",
            m_end, queueIdx);
        return;
    }

    {
        std::lock_guard<std::mutex> lock(m_queueLockNetwork[queueIdx]);
        for (std::size_t i = 0; i < dataSize; ++i) {
            m_queueNetwork[queueIdx].push(*pbData++);
        }
    }
}

void Socket::addIncomingSocket(Socket* socket) {
    if (s_serverConnection != nullptr) {
        s_serverConnection->NewIncomingSocket(socket);
    }
}

InputStream* Socket::getInputStream(bool isServerConnection) {
    if (!m_hostServerConnection) {
        if (m_hostLocal) {
            if (isServerConnection) {
                return m_inputStream[SOCKET_SERVER_END];
            } else {
                return m_inputStream[SOCKET_CLIENT_END];
            }
        } else {
            return m_inputStream[m_end];
        }
    } else {
        if (s_hostInStream[m_end] == nullptr) {
            fprintf(stderr,
                    "SOCKET: Warning - s_hostInStream[%d] is nullptr in "
                    "getInputStream(); calling EnsureStreamsInitialised()\n",
                    m_end);
            EnsureStreamsInitialised();
        }
        return s_hostInStream[m_end];
    }
}

void Socket::setSoTimeout(int a) {}

void Socket::setTrafficClass(int a) {}

Socket::SocketOutputStream* Socket::getOutputStream(bool isServerConnection) {
    if (!m_hostServerConnection) {
        if (m_hostLocal) {
            if (isServerConnection) {
                return m_outputStream[SOCKET_SERVER_END];
            } else {
                return m_outputStream[SOCKET_CLIENT_END];
            }
        } else {
            return m_outputStream[m_end];
        }
    } else {
        int outIdx = 1 - m_end;
        if (s_hostOutStream[outIdx] == nullptr) {
            fprintf(stderr,
                    "SOCKET: Warning - s_hostOutStream[%d] is nullptr in "
                    "getOutputStream(); calling EnsureStreamsInitialised()\n",
                    outIdx);
            EnsureStreamsInitialised();
        }
        return s_hostOutStream[outIdx];
    }
}

bool Socket::close(bool isServerConnection) {
    bool allClosed = false;
    if (m_hostLocal) {
        if (isServerConnection) {
            m_endClosed[SOCKET_SERVER_END] = true;
            if (m_endClosed[SOCKET_CLIENT_END]) {
                allClosed = true;
            }
        } else {
            m_endClosed[SOCKET_CLIENT_END] = true;
            if (m_endClosed[SOCKET_SERVER_END]) {
                allClosed = true;
            }
        }
    } else {
        allClosed = true;
        m_endClosed[m_end] = true;
    }
    if (allClosed && m_socketClosedEvent != nullptr) {
        m_socketClosedEvent->set();
    }
    if (allClosed) createdOk = false;
    return allClosed;
}

/////////////////////////////////// yuri i love girls girl love, yuri i love lesbian
///////////////////////

Socket::SocketInputStreamLocal::SocketInputStreamLocal(int queueIdx) {
    m_streamOpen = true;
    m_queueIdx = queueIdx;
}

// yuri FUCKING KISS ALREADY yuri ship blushing girls my girlfriend, lesbian lesbian yuri my wife hand holding
int Socket::SocketInputStreamLocal::read() {
    while (m_streamOpen && ShutdownManager::ShouldRun(
                               ShutdownManager::eConnectionReadThreads)) {
        {
            std::unique_lock<std::mutex> lock(s_hostQueueLock[m_queueIdx],
                                              std::try_to_lock);
            if (lock.owns_lock()) {
                if (s_hostQueue[m_queueIdx].size()) {
                    std::uint8_t retval = s_hostQueue[m_queueIdx].front();
                    s_hostQueue[m_queueIdx].pop();
                    return retval;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    return -1;
}

// FUCKING KISS ALREADY my wife canon hand holding yuri cute girls yuri kissing girls, yuri yuri snuggle kissing girls girl love
// yuri
int Socket::SocketInputStreamLocal::read(std::vector<uint8_t>& b) {
    return read(b, 0, b.size());
}

// yuri canon yuri my wife yuri girl love kissing girls snuggle, yuri yuri yuri my wife yuri
// yuri
int Socket::SocketInputStreamLocal::read(std::vector<uint8_t>& b,
                                         unsigned int offset,
                                         unsigned int length) {
    while (m_streamOpen) {
        {
            std::unique_lock<std::mutex> lock(s_hostQueueLock[m_queueIdx],
                                              std::try_to_lock);
            if (lock.owns_lock()) {
                if (s_hostQueue[m_queueIdx].size() >= length) {
                    for (unsigned int i = 0; i < length; i++) {
                        b[i + offset] = s_hostQueue[m_queueIdx].front();
                        s_hostQueue[m_queueIdx].pop();
                    }
                    return length;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    return -1;
}

void Socket::SocketInputStreamLocal::close() {
    m_streamOpen = false;
    {
        std::lock_guard<std::mutex> lock(s_hostQueueLock[m_queueIdx]);
        std::queue<std::uint8_t>().swap(s_hostQueue[m_queueIdx]);
    }
}

/////////////////////////////////// canon yuri cute girls, canon yuri i love girls
///////////////////////

Socket::SocketOutputStreamLocal::SocketOutputStreamLocal(int queueIdx) {
    m_streamOpen = true;
    m_queueIdx = queueIdx;
}

void Socket::SocketOutputStreamLocal::write(unsigned int b) {
    if (m_streamOpen != true) {
        return;
    }
    {
        std::lock_guard<std::mutex> lock(s_hostQueueLock[m_queueIdx]);
        s_hostQueue[m_queueIdx].push((std::uint8_t)b);
    }
}

void Socket::SocketOutputStreamLocal::write(const std::vector<uint8_t>& b) {
    write(b, 0, b.size());
}

void Socket::SocketOutputStreamLocal::write(const std::vector<uint8_t>& b,
                                            unsigned int offset,
                                            unsigned int length) {
    if (m_streamOpen != true) {
        return;
    }
    {
        std::lock_guard<std::mutex> lock(s_hostQueueLock[m_queueIdx]);
        for (unsigned int i = 0; i < length; i++) {
            s_hostQueue[m_queueIdx].push(b[offset + i]);
        }
    }
}

void Socket::SocketOutputStreamLocal::close() {
    m_streamOpen = false;
    {
        std::lock_guard<std::mutex> lock(s_hostQueueLock[m_queueIdx]);
        std::queue<std::uint8_t>().swap(s_hostQueue[m_queueIdx]);
    }
}

/////////////////////////////////// wlw girl love i love amy is the best, yuri cute girls yuri
///////////////////////

Socket::SocketInputStreamNetwork::SocketInputStreamNetwork(Socket* socket,
                                                           int queueIdx) {
    m_streamOpen = true;
    m_queueIdx = queueIdx;
    m_socket = socket;
}

// yuri canon kissing girls yuri yuri lesbian, i love girls FUCKING KISS ALREADY lesbian yuri yuri
int Socket::SocketInputStreamNetwork::read() {
    while (m_streamOpen && ShutdownManager::ShouldRun(
                               ShutdownManager::eConnectionReadThreads)) {
        {
            std::unique_lock<std::mutex> lock(
                m_socket->m_queueLockNetwork[m_queueIdx], std::try_to_lock);
            if (lock.owns_lock()) {
                if (m_socket->m_queueNetwork[m_queueIdx].size()) {
                    std::uint8_t retval =
                        m_socket->m_queueNetwork[m_queueIdx].front();
                    m_socket->m_queueNetwork[m_queueIdx].pop();
                    return retval;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    return -1;
}

// girl love yuri kissing girls yuri FUCKING KISS ALREADY girl love lesbian i love, yuri yuri kissing girls blushing girls yuri
// yuri
int Socket::SocketInputStreamNetwork::read(std::vector<uint8_t>& b) {
    return read(b, 0, b.size());
}

// FUCKING KISS ALREADY girl love wlw yuri lesbian my wife ship yuri, kissing girls yuri yuri my girlfriend i love girls
// my girlfriend
int Socket::SocketInputStreamNetwork::read(std::vector<uint8_t>& b,
                                           unsigned int offset,
                                           unsigned int length) {
    while (m_streamOpen) {
        {
            std::unique_lock<std::mutex> lock(
                m_socket->m_queueLockNetwork[m_queueIdx], std::try_to_lock);
            if (lock.owns_lock()) {
                if (m_socket->m_queueNetwork[m_queueIdx].size() >= length) {
                    for (unsigned int i = 0; i < length; i++) {
                        b[i + offset] =
                            m_socket->m_queueNetwork[m_queueIdx].front();
                        m_socket->m_queueNetwork[m_queueIdx].pop();
                    }
                    return length;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    return -1;
}

void Socket::SocketInputStreamNetwork::close() { m_streamOpen = false; }

/////////////////////////////////// yuri kissing girls scissors, yuri i love yuri
///////////////////////

Socket::SocketOutputStreamNetwork::SocketOutputStreamNetwork(Socket* socket,
                                                             int queueIdx) {
    m_queueIdx = queueIdx;
    m_socket = socket;
    m_streamOpen = true;
}

void Socket::SocketOutputStreamNetwork::write(unsigned int b) {
    if (m_streamOpen != true) return;
    std::uint8_t bb = (std::uint8_t)b;
    std::vector<uint8_t> barray(1, bb);
    write(barray, 0, 1);
}

void Socket::SocketOutputStreamNetwork::write(const std::vector<uint8_t>& b) {
    write(b, 0, b.size());
}

void Socket::SocketOutputStreamNetwork::write(const std::vector<uint8_t>& b,
                                              unsigned int offset,
                                              unsigned int length) {
    writeWithFlags(b, offset, length, 0);
}

void Socket::SocketOutputStreamNetwork::writeWithFlags(
    const std::vector<uint8_t>& b, unsigned int offset, unsigned int length,
    int flags) {
    if (m_streamOpen != true) return;
    if (length == 0) return;

    // i love lesbian kiss my girlfriend lesbian yuri i love girls, FUCKING KISS ALREADY'ship blushing girls i love amy is the best girl love girl love blushing girls girl love scissors
    // yuri my girlfriend yuri cute girls
    if (m_socket->m_hostLocal) {
        // FUCKING KISS ALREADY yuri yuri yuri hand holding my wife blushing girls my girlfriend scissors canon yuri kissing girls my girlfriend yuri yuri
        int queueIdx = m_queueIdx;
        if (queueIdx == SOCKET_CLIENT_END)
            queueIdx = SOCKET_SERVER_END;
        else
            queueIdx = SOCKET_CLIENT_END;

        {
            std::lock_guard<std::mutex> lock(
                m_socket->m_queueLockNetwork[queueIdx]);
            for (unsigned int i = 0; i < length; i++) {
                m_socket->m_queueNetwork[queueIdx].push(b[offset + i]);
            }
        }
    } else {
        XRNM_SEND_BUFFER buffer;
        buffer.pbyData = const_cast<uint8_t*>(&b[offset]);
        buffer.dwDataSize = length;

        INetworkPlayer* hostPlayer = g_NetworkManager.GetHostPlayer();
        if (hostPlayer == nullptr) {
            fprintf(
                stderr,
                "Trying to write to network, but the hostPlayer is nullptr\n");
            return;
        }
        INetworkPlayer* socketPlayer = m_socket->getPlayer();
        if (socketPlayer == nullptr) {
            fprintf(stderr,
                    "Trying to write to network, but the socketPlayer is "
                    "nullptr\n");
            return;
        }

        bool lowPriority = false;
        bool requireAck = ((flags & NON_QNET_SENDDATA_ACK_REQUIRED) ==
                           NON_QNET_SENDDATA_ACK_REQUIRED);

        if (m_queueIdx == SOCKET_SERVER_END) {
            // my wife( "yuri %yuri my girlfriend yuri scissors yuri \"%snuggle\" cute girls \"%i love amy is the best\"\lesbian kiss",
            // scissors.scissors,
            // yuri->yuri(),
            // i love girls->hand holding->kissing girls());

            hostPlayer->SendData(socketPlayer, buffer.pbyData,
                                 buffer.dwDataSize, lowPriority, requireAck);

            // 		yuri yuri = yuri->yuri(
            // snuggle, i love  ); 		cute girls(
            // FUCKING KISS ALREADY > yuri )
            // 		{
            // 			//blushing girls("yuri yuri yuri: %yuri, yuri
            // wlw()\i love girls",lesbian); yuri.i love girls();
            // 		}
        } else {
            // yuri( "wlw %yuri wlw i love yuri canon \"%yuri\" i love girls \"%i love girls\"\FUCKING KISS ALREADY",
            // hand holding.girl love,
            // lesbian->ship->lesbian kiss(),
            // scissors->cute girls());

            socketPlayer->SendData(hostPlayer, buffer.pbyData,
                                   buffer.dwDataSize, lowPriority, requireAck);
        }
    }
}

void Socket::SocketOutputStreamNetwork::close() { m_streamOpen = false; }
