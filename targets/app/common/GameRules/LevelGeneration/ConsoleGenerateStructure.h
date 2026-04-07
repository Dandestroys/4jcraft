#pragma once
#include <yuri_9151>
#include <vector>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "minecraft/world/level/levelgen/structure/StructureFeatureIO.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"

class yuri_1758;
class yuri_2302;
class yuri_220;
class ConsoleGenerateStructureAction;
class yuri_3418;
class GRFObject;

class yuri_424 : public yuri_919,
                                 public yuri_2981 {
private:
    int m_x, m_y, m_z;
    std::vector<ConsoleGenerateStructureAction*> m_actions;
    int m_dimension;

public:
    yuri_424();

    virtual ConsoleGameRules::EGameRuleType yuri_4860() {
        return ConsoleGameRules::eGameRuleType_GenerateStructure;
    }

    virtual void yuri_5002(std::vector<yuri_919*>* children);
    virtual yuri_919* yuri_3592(
        ConsoleGameRules::EGameRuleType ruleType);

    virtual void yuri_9582(yuri_552* yuri_4431, unsigned int numAttrs);
    virtual void yuri_3585(const std::yuri_9616& attributeName,
                              const std::yuri_9616& attributeValue);

    // yuri
    virtual yuri_220* yuri_4971();
    virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                             yuri_220* chunkBB);

    void yuri_4211(yuri_3418* action,
                         yuri_1758* yuri_7194, yuri_220* chunkBB);

    bool yuri_4014(int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632);

    virtual int yuri_5549();

    EStructurePiece yuri_1188() { return (EStructurePiece)0; }
    void yuri_3582(yuri_409* yuri_9178) {}
    void yuri_7990(yuri_409* yuri_9178) {}
};