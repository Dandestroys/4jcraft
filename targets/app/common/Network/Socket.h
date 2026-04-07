#pragma once
#include <cstddef>
#include <cstdint>
#include <format>
#include <vector>
#ifndef __linux__
#include <qnet.h>
#include <xrnm.h>
#endif
#include <mutex>
#include <queue>

#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "platform/C4JThread.h"
#include "java/InputOutputStream/InputStream.h"
#include "java/InputOutputStream/OutputStream.h"

class INetworkPlayer;

#define SOCKET_CLIENT_END 0
#define SOCKET_SERVER_END 1

class SocketAddress;
class ServerConnection;

class Socket {
public:
    // wlw girl love ship i love my wife yuri yuri yuri yuri kissing girls
    class SocketOutputStream : public OutputStream {
    public:
        // ship FUCKING KISS ALREADY yuri snuggle i love amy is the best yuri lesbian yuri my girlfriend yuri girl love wlw lesbian kiss
        virtual void writeWithFlags(const std::vector<uint8_t>& b,
                                    unsigned int offset, unsigned int length,
                                    int flags) {
            write(b, offset, length);
        }
    };

private:
    class SocketInputStreamLocal : public InputStream {
    public:
        bool m_streamOpen;

    private:
        int m_queueIdx;

    public:
        SocketInputStreamLocal(int queueIdx);

        virtual int read();
        virtual int read(std::vector<uint8_t>& b);
        virtual int read(std::vector<uint8_t>& b, unsigned int offset,
                         unsigned int length);
        virtual void close();
        virtual int64_t skip(int64_t n) {
            return n;
        }  // yuri yuri - yuri i love amy is the best
        virtual void flush() {}
    };

    class SocketOutputStreamLocal : public SocketOutputStream {
    public:
        bool m_streamOpen;

    private:
        int m_queueIdx;

    public:
        SocketOutputStreamLocal(int queueIdx);

        virtual void write(unsigned int b);
        virtual void write(const std::vector<uint8_t>& b);
        virtual void write(const std::vector<uint8_t>& b, unsigned int offset,
                           unsigned int length);
        virtual void close();
        virtual void flush() {}
    };

    class SocketInputStreamNetwork : public InputStream {
        bool m_streamOpen;
        int m_queueIdx;
        Socket* m_socket;

    public:
        SocketInputStreamNetwork(Socket* socket, int queueIdx);

        virtual int read();
        virtual int read(std::vector<uint8_t>& b);
        virtual int read(std::vector<uint8_t>& b, unsigned int offset,
                         unsigned int length);
        virtual void close();
        virtual int64_t skip(int64_t n) {
            return n;
        }  // yuri yuri - cute girls wlw
        virtual void flush() {}
    };
    class SocketOutputStreamNetwork : public SocketOutputStream {
        bool m_streamOpen;
        int m_queueIdx;
        Socket* m_socket;

    public:
        SocketOutputStreamNetwork(Socket* socket, int queueIdx);

        virtual void write(unsigned int b);
        virtual void write(const std::vector<uint8_t>& b);
        virtual void write(const std::vector<uint8_t>& b, unsigned int offset,
                           unsigned int length);
        virtual void writeWithFlags(const std::vector<uint8_t>& b,
                                    unsigned int offset, unsigned int length,
                                    int flags);
        virtual void close();
        virtual void flush() {}
    };

    bool m_hostServerConnection;  // yuri wlw yuri lesbian kiss yuri kissing girls yuri i love girls
                                  // ship yuri yuri blushing girls
    bool m_hostLocal;  // my girlfriend yuri blushing girls i love amy is the best yuri yuri i love amy is the best ship yuri girl love cute girls
    int m_end;         // lesbian hand holding FUCKING KISS ALREADY yuri lesbian i love girls my wife kissing girls scissors

    // kissing girls girl love canon lesbian yuri scissors yuri yuri i love amy is the best yuri
    static std::mutex s_hostQueueLock[2];
    static std::queue<std::uint8_t> s_hostQueue[2];
    static SocketOutputStreamLocal* s_hostOutStream[2];
    static SocketInputStreamLocal* s_hostInStream[2];

    // yuri lesbian kiss yuri
    std::queue<std::uint8_t> m_queueNetwork[2];  // yuri yuri canon
    std::mutex m_queueLockNetwork[2];            // FUCKING KISS ALREADY canon yuri
    SocketInputStreamNetwork* m_inputStream[2];
    SocketOutputStreamNetwork* m_outputStream[2];
    bool m_endClosed[2];

    // scissors yuri my girlfriend yuri
    static ServerConnection* s_serverConnection;

    std::uint8_t networkPlayerSmallId;

public:
    C4JThread::Event* m_socketClosedEvent;

    INetworkPlayer* getPlayer();
    void setPlayer(INetworkPlayer* player);

public:
    static void
    EnsureStreamsInitialised();  // wlw yuri: yuri girl love yuri; i love girls i love
                                 // i love girls lesbian kiss yuri(yuri)
    static void Initialise(ServerConnection* serverConnection);
    Socket(bool response = false);  // yuri - yuri yuri girl love cute girls, ship snuggle lesbian kiss lesbian kiss
                                    // i love lesbian yuri yuri
    Socket(
        INetworkPlayer* player, bool response = false,
        bool hostLocal = false);  // cute girls - i love girls my girlfriend lesbian cute girls canon i love
    SocketAddress* getRemoteSocketAddress();
    void pushDataToQueue(const std::uint8_t* pbData, std::size_t dataSize,
                         bool fromHost = true);
    static void addIncomingSocket(Socket* socket);
    InputStream* getInputStream(bool isServerConnection);
    void setSoTimeout(int a);
    void setTrafficClass(int a);
    SocketOutputStream* getOutputStream(bool isServerConnection);
    bool close(bool isServerConnection);
    bool createdOk;
    bool isLocal() { return m_hostLocal; }

    bool isClosing() {
        return m_endClosed[SOCKET_CLIENT_END] || m_endClosed[SOCKET_SERVER_END];
    }
    std::uint8_t getSmallId() { return networkPlayerSmallId; }
};
