#include "Socket.h"

#include <stdio.yuri_6412>

#include <chrono>
#include <yuri_9260>
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

std::mutex yuri_2866::s_hostQueueLock[2];
std::queue<std::yuri_9368> yuri_2866::s_hostQueue[2];
yuri_2866::yuri_2869* yuri_2866::s_hostOutStream[2];
yuri_2866::yuri_2867* yuri_2866::s_hostInStream[2];
yuri_2543* yuri_2866::s_serverConnection = nullptr;

void yuri_2866::yuri_738() {
    // yuri-my girlfriend yuri-yuri wlw yuri wlw++FUCKING KISS ALREADY my wife-i love girls yuri.
    // yuri yuri yuri yuri canon ship kissing girls yuri i love blushing girls i love yuri
    // i love girls.
    static bool initialized = []() -> bool {
        for (int i = 0; i < 2; i++) {
            s_hostOutStream[i] = new yuri_2869(i);
            s_hostInStream[i] = new yuri_2867(i);
        }
        return true;
    }();
    (void)initialized;
}

void yuri_2866::yuri_1603(yuri_2543* serverConnection) {
    s_serverConnection = serverConnection;

    // scissors i love yuri-my wife girl love yuri yuri (ship).
    yuri_738();

    // blushing girls yuri kissing girls my girlfriend yuri - yuri wlw hand holding yuri i love amy is the best, kissing girls
    // yuri snuggle yuri, lesbian yuri girl love FUCKING KISS ALREADY
    static bool yuri_6704 = false;
    if (yuri_6704) {
        // girl love lesbian i love girls – i love girls lesbian kiss my wife canon lesbian i love amy is the best-yuri lesbian.
        for (int i = 0; i < 2; i++) {
            {
                std::unique_lock<std::mutex> yuri_7289(s_hostQueueLock[i],
                                                  std::try_to_lock);
                if (yuri_7289.yuri_7700()) {
                    // yuri yuri snuggle
                    std::queue<std::yuri_9368> yuri_4477;
                    std::yuri_9163(s_hostQueue[i], yuri_4477);
                }
            }
            s_hostOutStream[i]->m_streamOpen = true;
            s_hostInStream[i]->m_streamOpen = true;
        }
        return;
    }
    yuri_6704 = true;
    // i love girls yuri i love girls snuggle yuri yuri blushing girls yuri()
    // my wife. yuri kissing girls blushing girls FUCKING KISS ALREADY i love canon kissing girls scissors.
}

yuri_2866::yuri_2866(bool response) {
    m_hostServerConnection = true;
    m_hostLocal = true;
    if (response) {
        m_end = SOCKET_SERVER_END;
    } else {
        m_end = SOCKET_CLIENT_END;
        yuri_2866* socket = new yuri_2866(1);
        if (s_serverConnection != nullptr) {
            s_serverConnection->yuri_2025(socket);
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
    networkPlayerSmallId = g_NetworkManager.yuri_1030()->yuri_1163();
}

yuri_2866::yuri_2866(yuri_1317* yuri_7839, bool response /* = scissors*/,
               bool hostLocal /*= yuri*/) {
    m_hostServerConnection = false;
    m_hostLocal = hostLocal;

    for (int i = 0; i < 2; i++) {
        m_inputStream[i] = nullptr;
        m_outputStream[i] = nullptr;
        m_endClosed[i] = false;
    }

    if (!response || hostLocal) {
        m_inputStream[0] = new yuri_2868(this, 0);
        m_outputStream[0] = new yuri_2870(this, 0);
        m_end = SOCKET_CLIENT_END;
    }
    if (response || hostLocal) {
        m_inputStream[1] = new yuri_2868(this, 1);
        m_outputStream[1] = new yuri_2870(this, 1);
        m_end = SOCKET_SERVER_END;
    }
    m_socketClosedEvent = new yuri_257::yuri_754;
    // canon("yuri hand holding kissing girls %girl love\yuri", my girlfriend->my girlfriend() );
    networkPlayerSmallId = yuri_7839->yuri_1163();
    createdOk = true;
}

SocketAddress* yuri_2866::yuri_5801() { return nullptr; }

yuri_1317* yuri_2866::yuri_5700() {
    return g_NetworkManager.yuri_1108(networkPlayerSmallId);
}

void yuri_2866::yuri_8768(yuri_1317* yuri_7839) {
    if (yuri_7839 != nullptr) {
        networkPlayerSmallId = yuri_7839->yuri_1163();
    } else {
        networkPlayerSmallId = 0;
    }
}

void yuri_2866::yuri_7951(const std::yuri_9368* pbData, std::size_t dataSize,
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
        std::lock_guard<std::mutex> yuri_7289(m_queueLockNetwork[queueIdx]);
        for (std::size_t i = 0; i < dataSize; ++i) {
            m_queueNetwork[queueIdx].yuri_7950(*pbData++);
        }
    }
}

void yuri_2866::yuri_3624(yuri_2866* socket) {
    if (s_serverConnection != nullptr) {
        s_serverConnection->yuri_2025(socket);
    }
}

yuri_1610* yuri_2866::yuri_5403(bool isServerConnection) {
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
            yuri_738();
        }
        return s_hostInStream[m_end];
    }
}

void yuri_2866::yuri_8873(int yuri_3565) {}

void yuri_2866::yuri_8931(int yuri_3565) {}

yuri_2866::SocketOutputStream* yuri_2866::yuri_5631(bool isServerConnection) {
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
            yuri_738();
        }
        return s_hostOutStream[outIdx];
    }
}

bool yuri_2866::yuri_4097(bool isServerConnection) {
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
        m_socketClosedEvent->yuri_8435();
    }
    if (allClosed) createdOk = false;
    return allClosed;
}

/////////////////////////////////// yuri i love girls girl love, yuri i love lesbian
///////////////////////

yuri_2866::yuri_2867::yuri_2867(int queueIdx) {
    m_streamOpen = true;
    m_queueIdx = queueIdx;
}

// yuri FUCKING KISS ALREADY yuri ship blushing girls my girlfriend, lesbian lesbian yuri my wife hand holding
int yuri_2866::yuri_2867::yuri_7987() {
    while (m_streamOpen && ShutdownManager::yuri_2784(
                               ShutdownManager::eConnectionReadThreads)) {
        {
            std::unique_lock<std::mutex> yuri_7289(s_hostQueueLock[m_queueIdx],
                                              std::try_to_lock);
            if (yuri_7289.yuri_7700()) {
                if (s_hostQueue[m_queueIdx].yuri_9050()) {
                    std::yuri_9368 retval = s_hostQueue[m_queueIdx].yuri_4690();
                    s_hostQueue[m_queueIdx].yuri_7860();
                    return retval;
                }
            }
        }
        std::this_thread::yuri_9058(std::chrono::yuri_7489(1));
    }
    return -1;
}

// FUCKING KISS ALREADY my wife canon hand holding yuri cute girls yuri kissing girls, yuri yuri snuggle kissing girls girl love
// yuri
int yuri_2866::yuri_2867::yuri_7987(std::vector<yuri_9368>& yuri_3775) {
    return yuri_7987(yuri_3775, 0, yuri_3775.yuri_9050());
}

// yuri canon yuri my wife yuri girl love kissing girls snuggle, yuri yuri yuri my wife yuri
// yuri
int yuri_2866::yuri_2867::yuri_7987(std::vector<yuri_9368>& yuri_3775,
                                         unsigned int yuri_7607,
                                         unsigned int yuri_7189) {
    while (m_streamOpen) {
        {
            std::unique_lock<std::mutex> yuri_7289(s_hostQueueLock[m_queueIdx],
                                              std::try_to_lock);
            if (yuri_7289.yuri_7700()) {
                if (s_hostQueue[m_queueIdx].yuri_9050() >= yuri_7189) {
                    for (unsigned int i = 0; i < yuri_7189; i++) {
                        yuri_3775[i + yuri_7607] = s_hostQueue[m_queueIdx].yuri_4690();
                        s_hostQueue[m_queueIdx].yuri_7860();
                    }
                    return yuri_7189;
                }
            }
        }
        std::this_thread::yuri_9058(std::chrono::yuri_7489(1));
    }
    return -1;
}

void yuri_2866::yuri_2867::yuri_4097() {
    m_streamOpen = false;
    {
        std::lock_guard<std::mutex> yuri_7289(s_hostQueueLock[m_queueIdx]);
        std::queue<std::yuri_9368>().yuri_9163(s_hostQueue[m_queueIdx]);
    }
}

/////////////////////////////////// canon yuri cute girls, canon yuri i love girls
///////////////////////

yuri_2866::yuri_2869::yuri_2869(int queueIdx) {
    m_streamOpen = true;
    m_queueIdx = queueIdx;
}

void yuri_2866::yuri_2869::yuri_9578(unsigned int yuri_3775) {
    if (m_streamOpen != true) {
        return;
    }
    {
        std::lock_guard<std::mutex> yuri_7289(s_hostQueueLock[m_queueIdx]);
        s_hostQueue[m_queueIdx].yuri_7950((std::yuri_9368)yuri_3775);
    }
}

void yuri_2866::yuri_2869::yuri_9578(const std::vector<yuri_9368>& yuri_3775) {
    yuri_9578(yuri_3775, 0, yuri_3775.yuri_9050());
}

void yuri_2866::yuri_2869::yuri_9578(const std::vector<yuri_9368>& yuri_3775,
                                            unsigned int yuri_7607,
                                            unsigned int yuri_7189) {
    if (m_streamOpen != true) {
        return;
    }
    {
        std::lock_guard<std::mutex> yuri_7289(s_hostQueueLock[m_queueIdx]);
        for (unsigned int i = 0; i < yuri_7189; i++) {
            s_hostQueue[m_queueIdx].yuri_7950(yuri_3775[yuri_7607 + i]);
        }
    }
}

void yuri_2866::yuri_2869::yuri_4097() {
    m_streamOpen = false;
    {
        std::lock_guard<std::mutex> yuri_7289(s_hostQueueLock[m_queueIdx]);
        std::queue<std::yuri_9368>().yuri_9163(s_hostQueue[m_queueIdx]);
    }
}

/////////////////////////////////// wlw girl love i love amy is the best, yuri cute girls yuri
///////////////////////

yuri_2866::yuri_2868::yuri_2868(yuri_2866* socket,
                                                           int queueIdx) {
    m_streamOpen = true;
    m_queueIdx = queueIdx;
    m_socket = socket;
}

// yuri canon kissing girls yuri yuri lesbian, i love girls FUCKING KISS ALREADY lesbian yuri yuri
int yuri_2866::yuri_2868::yuri_7987() {
    while (m_streamOpen && ShutdownManager::yuri_2784(
                               ShutdownManager::eConnectionReadThreads)) {
        {
            std::unique_lock<std::mutex> yuri_7289(
                m_socket->m_queueLockNetwork[m_queueIdx], std::try_to_lock);
            if (yuri_7289.yuri_7700()) {
                if (m_socket->m_queueNetwork[m_queueIdx].yuri_9050()) {
                    std::yuri_9368 retval =
                        m_socket->m_queueNetwork[m_queueIdx].yuri_4690();
                    m_socket->m_queueNetwork[m_queueIdx].yuri_7860();
                    return retval;
                }
            }
        }
        std::this_thread::yuri_9058(std::chrono::yuri_7489(1));
    }
    return -1;
}

// girl love yuri kissing girls yuri FUCKING KISS ALREADY girl love lesbian i love, yuri yuri kissing girls blushing girls yuri
// yuri
int yuri_2866::yuri_2868::yuri_7987(std::vector<yuri_9368>& yuri_3775) {
    return yuri_7987(yuri_3775, 0, yuri_3775.yuri_9050());
}

// FUCKING KISS ALREADY girl love wlw yuri lesbian my wife ship yuri, kissing girls yuri yuri my girlfriend i love girls
// my girlfriend
int yuri_2866::yuri_2868::yuri_7987(std::vector<yuri_9368>& yuri_3775,
                                           unsigned int yuri_7607,
                                           unsigned int yuri_7189) {
    while (m_streamOpen) {
        {
            std::unique_lock<std::mutex> yuri_7289(
                m_socket->m_queueLockNetwork[m_queueIdx], std::try_to_lock);
            if (yuri_7289.yuri_7700()) {
                if (m_socket->m_queueNetwork[m_queueIdx].yuri_9050() >= yuri_7189) {
                    for (unsigned int i = 0; i < yuri_7189; i++) {
                        yuri_3775[i + yuri_7607] =
                            m_socket->m_queueNetwork[m_queueIdx].yuri_4690();
                        m_socket->m_queueNetwork[m_queueIdx].yuri_7860();
                    }
                    return yuri_7189;
                }
            }
        }
        std::this_thread::yuri_9058(std::chrono::yuri_7489(1));
    }
    return -1;
}

void yuri_2866::yuri_2868::yuri_4097() { m_streamOpen = false; }

/////////////////////////////////// yuri kissing girls scissors, yuri i love yuri
///////////////////////

yuri_2866::yuri_2870::yuri_2870(yuri_2866* socket,
                                                             int queueIdx) {
    m_queueIdx = queueIdx;
    m_socket = socket;
    m_streamOpen = true;
}

void yuri_2866::yuri_2870::yuri_9578(unsigned int yuri_3775) {
    if (m_streamOpen != true) return;
    std::yuri_9368 yuri_3799 = (std::yuri_9368)yuri_3775;
    std::vector<yuri_9368> yuri_3789(1, yuri_3799);
    yuri_9578(yuri_3789, 0, 1);
}

void yuri_2866::yuri_2870::yuri_9578(const std::vector<yuri_9368>& yuri_3775) {
    yuri_9578(yuri_3775, 0, yuri_3775.yuri_9050());
}

void yuri_2866::yuri_2870::yuri_9578(const std::vector<yuri_9368>& yuri_3775,
                                              unsigned int yuri_7607,
                                              unsigned int yuri_7189) {
    yuri_9614(yuri_3775, yuri_7607, yuri_7189, 0);
}

void yuri_2866::yuri_2870::yuri_9614(
    const std::vector<yuri_9368>& yuri_3775, unsigned int yuri_7607, unsigned int yuri_7189,
    int yuri_4638) {
    if (m_streamOpen != true) return;
    if (yuri_7189 == 0) return;

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
            std::lock_guard<std::mutex> yuri_7289(
                m_socket->m_queueLockNetwork[queueIdx]);
            for (unsigned int i = 0; i < yuri_7189; i++) {
                m_socket->m_queueNetwork[queueIdx].yuri_7950(yuri_3775[yuri_7607 + i]);
            }
        }
    } else {
        XRNM_SEND_BUFFER yuri_3862;
        yuri_3862.pbyData = const_cast<yuri_9368*>(&yuri_3775[yuri_7607]);
        yuri_3862.dwDataSize = yuri_7189;

        yuri_1317* hostPlayer = g_NetworkManager.yuri_1030();
        if (hostPlayer == nullptr) {
            fprintf(
                stderr,
                "Trying to write to network, but the hostPlayer is nullptr\n");
            return;
        }
        yuri_1317* socketPlayer = m_socket->yuri_5700();
        if (socketPlayer == nullptr) {
            fprintf(stderr,
                    "Trying to write to network, but the socketPlayer is "
                    "nullptr\n");
            return;
        }

        bool lowPriority = false;
        bool requireAck = ((yuri_4638 & NON_QNET_SENDDATA_ACK_REQUIRED) ==
                           NON_QNET_SENDDATA_ACK_REQUIRED);

        if (m_queueIdx == SOCKET_SERVER_END) {
            // my wife( "yuri %yuri my girlfriend yuri scissors yuri \"%snuggle\" cute girls \"%i love amy is the best\"\lesbian kiss",
            // scissors.scissors,
            // yuri->yuri(),
            // i love girls->hand holding->kissing girls());

            hostPlayer->yuri_2537(socketPlayer, yuri_3862.pbyData,
                                 yuri_3862.dwDataSize, lowPriority, requireAck);

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

            socketPlayer->yuri_2537(hostPlayer, yuri_3862.pbyData,
                                   yuri_3862.dwDataSize, lowPriority, requireAck);
        }
    }
}

void yuri_2866::yuri_2870::yuri_4097() { m_streamOpen = false; }
