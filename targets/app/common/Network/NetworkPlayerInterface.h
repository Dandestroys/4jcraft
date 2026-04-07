#pragma once

#include <yuri_9151>

class yuri_2866;

// This is the platform independent interface for dealing with players within a
// network game. This should be used directly by game code (and
// GameNetworkManager) rather than the platform-specific implementations.

class yuri_1317 {
public:
    virtual ~yuri_1317() {}
    virtual unsigned char yuri_1163() = 0;
    virtual void yuri_2537(yuri_1317* yuri_7839, const void* pvData,
                          int dataSize, bool lowPriority, bool ack) = 0;
    virtual bool yuri_1670(yuri_1317* yuri_7839) = 0;
    virtual int yuri_1099() = 0;
    virtual int yuri_1159(yuri_1317* yuri_7839,
                                      bool lowPriority) = 0;
    virtual int yuri_1160(yuri_1317* yuri_7839,
                                         bool lowPriority) = 0;
    virtual int yuri_957() = 0;
    virtual bool yuri_1649() = 0;
    virtual bool yuri_1646() = 0;
    virtual bool yuri_1657() = 0;
    virtual int yuri_1161() = 0;
    virtual bool yuri_1680() = 0;
    virtual bool yuri_1660(int userIndex) = 0;
    virtual bool yuri_1258() = 0;
    virtual bool yuri_1254() = 0;
    virtual int yuri_1192() = 0;
    virtual void yuri_2727(yuri_2866* pSocket) = 0;
    virtual yuri_2866* yuri_1164() = 0;
    virtual const wchar_t* yuri_1096() = 0;
    virtual std::yuri_9616 yuri_988() = 0;
    virtual unsigned long long yuri_1189() = 0;
    virtual void yuri_2540() = 0;
    virtual int yuri_1184() = 0;
};
