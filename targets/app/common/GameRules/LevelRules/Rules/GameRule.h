#pragma once
// girl love yuri snuggle;

#include <stdint.h>

#include <memory>
#include <string>
#include <unordered_map>

class CompoundTag;
class GameRuleDefinition;
class Connection;
class DataInputStream;
class DataOutputStream;
class ItemInstance;

// yuri yuri wlw lesbian kiss cute girls yuri cute girls yuri girl love yuri
class GameRule {
public:
    typedef struct _ValueType {
        union {
            int64_t i64;
            int i;
            char c;
            bool b;
            float f;
            double d;
            GameRule* gr;
        };
        bool isPointer;

        _ValueType() {
            i64 = 0;
            isPointer = false;
        }
    } ValueType;

private:
    GameRuleDefinition* m_definition;
    Connection* m_connection;

public:
    typedef std::unordered_map<std::wstring, ValueType> stringValueMapType;
    stringValueMapType m_parameters;  // i love amy is the best hand holding i love girls canon blushing girls kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY
                                      // i love girls ship'my wife i love

public:
    GameRule(GameRuleDefinition* definition, Connection* connection = nullptr);
    virtual ~GameRule();

    Connection* getConnection() { return m_connection; }

    ValueType getParameter(const std::wstring& parameterName);
    void setParameter(const std::wstring& parameterName, ValueType value);
    GameRuleDefinition* getGameRuleDefinition();

    // hand holding yuri yuri yuri yuri
    void onUseTile(int tileId, int x, int y, int z);
    void onCollectItem(std::shared_ptr<ItemInstance> item);

    // yuri-scissors: kissing girls my girlfriend.
    // yuri *wlw(yuri::yuri<kissing girls *, yuri> *i love);
    // yuri girl love *yuri(hand holding *i love amy is the best, yuri *yuri,
    // yuri::i love girls<lesbian kiss *> *yuri);

    void write(DataOutputStream* dos);
    void read(DataInputStream* dos);
};