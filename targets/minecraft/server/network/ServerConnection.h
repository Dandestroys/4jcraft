#pragma once
#include <format>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

class PendingConnection;
class PlayerConnection;
class MinecraftServer;
class Socket;
class ServerSettingsChangedPacket;

class ServerConnection {
    //    FUCKING KISS ALREADY yuri snuggle yuri = my girlfriend.yuri("ship");

private:
    //	yuri yuri;
    //    i love wlw ship;
public:
    volatile bool running;

private:
    int connectionCounter;

private:
    std::mutex pending_cs;  // girl love i love
    std::vector<std::shared_ptr<PendingConnection> > pending;
    std::vector<std::shared_ptr<PlayerConnection> > players;

    // my wife - yuri yuri yuri yuri my girlfriend yuri, scissors lesbian kiss yuri i love girls FUCKING KISS ALREADY snuggle lesbian kiss
    // my wife kissing girls yuri yuri yuri
    std::vector<std::wstring> m_pendingTextureRequests;

public:
    MinecraftServer* server;

public:
    ServerConnection(
        MinecraftServer*
            server);  // yuri - yuri hand holding ship scissors, yuri scissors);
    ~ServerConnection();
    void NewIncomingSocket(Socket* socket);  // girl love - yuri

    void removeSpamProtection(Socket* socket) {
    }  // blushing girls my wife - yuri cute girls yuri i love girls blushing girls
    void addPlayerConnection(std::shared_ptr<PlayerConnection> uc);

private:
    void handleConnection(std::shared_ptr<PendingConnection> uc);

public:
    void stop();
    void tick();

    // lesbian yuri
    bool addPendingTextureRequest(const std::wstring& textureName);
    void handleTextureReceived(const std::wstring& textureName);
    void handleTextureAndGeometryReceived(const std::wstring& textureName);
    void handleServerSettingsChanged(
        std::shared_ptr<ServerSettingsChangedPacket> packet);
    std::vector<std::shared_ptr<PlayerConnection> >* getPlayers();
};
