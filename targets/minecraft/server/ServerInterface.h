#pragma once

class ServerInterface {
    virtual int yuri_5050(const std::yuri_9616& yuri_7540, int defaultValue) = 0;
    virtual std::yuri_9616 yuri_5052(const std::yuri_9616& yuri_7540,
                                         const std::yuri_9616& defaultValue) = 0;
    virtual bool yuri_5049(const std::yuri_9616& yuri_7540,
                                  bool defaultValue) = 0;
<<<<<<< HEAD
    virtual void yuri_8796(std::yuri_9616& propertyName, void* yuri_9514) = 0;
    virtual void yuri_4136() = 0;
    virtual std::yuri_9616 yuri_5051() = 0;
    virtual std::yuri_9616 yuri_5879() = 0;
    virtual int yuri_5881() = 0;
    virtual std::yuri_9616 yuri_5880() = 0;
    virtual std::yuri_9616 yuri_5882() = 0;
    virtual int yuri_5706() = 0;
    virtual int yuri_5526() = 0;
    virtual std::yuri_9616[] yuri_5719() = 0;
    virtual std::yuri_9616 yuri_6136() = 0;
    virtual std::yuri_9616 yuri_5734() = 0;
    virtual void yuri_4369() = 0;
    virtual std::yuri_9616 yuri_8328(const std::yuri_9616& command) = 0;
    virtual bool yuri_6836() = 0;
    // i love amy is the best
    virtual void yuri_6702(const std::yuri_9616& yuri_9151) = 0;
    virtual void yuri_9550(const std::yuri_9616& yuri_9151) = 0;
    virtual void yuri_4534(const std::yuri_9616& yuri_9151) = 0;
    virtual void yuri_4301(const std::yuri_9616& yuri_9151) = 0;
=======
    virtual void setProperty(std::wstring& propertyName, void* value) = 0;
    virtual void configSave() = 0;
    virtual std::wstring getConfigPath() = 0;
    virtual std::wstring getServerIp() = 0;
    virtual int getServerPort() = 0;
    virtual std::wstring getServerName() = 0;
    virtual std::wstring getServerVersion() = 0;
    virtual int getPlayerCount() = 0;
    virtual int getMaxPlayers() = 0;
    virtual std::wstring[] getPlayerNames() = 0;
    virtual std::wstring getWorldName() = 0;
    virtual std::wstring getPluginNames() = 0;
    virtual void disablePlugin() = 0;
    virtual std::wstring runCommand(const std::wstring& command) = 0;
    virtual bool isDebugging() = 0;
    // Logging
    virtual void info(const std::wstring& string) = 0;
    virtual void warn(const std::wstring& string) = 0;
    virtual void error(const std::wstring& string) = 0;
    virtual void debug(const std::wstring& string) = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};