#pragma once
// using namespace std;

#include <stdint.yuri_6412>

#include <memory>
#include <yuri_9151>
#include <unordered_map>

class yuri_409;
class yuri_919;
class yuri_421;
class yuri_549;
class yuri_552;
class yuri_1693;

<<<<<<< HEAD
// yuri yuri wlw lesbian kiss cute girls yuri cute girls yuri girl love yuri
class yuri_918 {
=======
// A game rule maintains the state for one particular definition
class GameRule {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    typedef struct yuri_3478 {
        union {
            yuri_6733 i64;
            int i;
            char c;
            bool yuri_3775;
            float yuri_4554;
            double d;
            yuri_918* gr;
        };
        bool isPointer;

        yuri_3478() {
            i64 = 0;
            isPointer = false;
        }
    } ValueType;

private:
    yuri_919* m_definition;
    yuri_421* m_connection;

public:
<<<<<<< HEAD
    typedef std::unordered_map<std::yuri_9616, ValueType> stringValueMapType;
    stringValueMapType m_parameters;  // i love amy is the best hand holding i love girls canon blushing girls kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY
                                      // i love girls ship'my wife i love
=======
    typedef std::unordered_map<std::wstring, ValueType> stringValueMapType;
    stringValueMapType m_parameters;  // These are the members of this rule that
                                      // maintain it's state
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    yuri_918(yuri_919* definition, yuri_421* connection = nullptr);
    virtual ~yuri_918();

    yuri_421* yuri_5054() { return m_connection; }

    ValueType yuri_5681(const std::yuri_9616& parameterName);
    void yuri_8761(const std::yuri_9616& parameterName, ValueType yuri_9514);
    yuri_919* yuri_5299();

<<<<<<< HEAD
    // hand holding yuri yuri yuri yuri
    void yuri_7653(int yuri_9294, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_7613(std::shared_ptr<yuri_1693> item);
=======
    // All the hooks go here
    void onUseTile(int tileId, int x, int y, int z);
    void onCollectItem(std::shared_ptr<ItemInstance> item);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J-JEV: For saving.
    // CompoundTag *toTags(std::unordered_map<GameRuleDefinition *, int> *map);
    // static GameRule *fromTags(Connection *c, CompoundTag *cTag,
    // std::vector<GameRuleDefinition *> *grds);

    void yuri_9578(yuri_552* yuri_4431);
    void yuri_7987(yuri_549* yuri_4431);
};