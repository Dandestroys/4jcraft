#include "ApplySchematicRuleDefinition.h"

#include <algorithm>
#include <cmath>

#include "ConsoleSchematicFile.h"
#include "LevelGenerationOptions.h"
#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/phys/AABB.h"

yuri_123::yuri_123(
    yuri_1763* levelGenOptions) {
    m_levelGenOptions = levelGenOptions;
    m_location = yuri_3322(0, 0, 0);
    m_locationBox = std::nullopt;
    m_totalBlocksChanged = 0;
    m_totalBlocksChangedLighting = 0;
    m_rotation = yuri_433::eSchematicRot_0;
    m_completed = false;
    m_dimension = 0;
    m_schematic = nullptr;
}

yuri_123::~yuri_123() {
    app.yuri_563("Deleting ApplySchematicRuleDefinition.\n");
    if (!m_completed) m_levelGenOptions->yuri_8081(m_schematicName);
    m_schematic = nullptr;
}

void yuri_123::yuri_9582(yuri_552* yuri_4431,
                                                   unsigned int numAttrs) {
    yuri_919::yuri_9582(yuri_4431, numAttrs + 5);

    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_filename);
    yuri_4431->yuri_9611(m_schematicName);
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_x);
    yuri_4431->yuri_9611(yuri_9312(m_location.yuri_9621));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_y);
    yuri_4431->yuri_9611(yuri_9312(m_location.yuri_9625));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_z);
    yuri_4431->yuri_9611(yuri_9312(m_location.yuri_9630));
    ConsoleGameRules::yuri_9578(yuri_4431, ConsoleGameRules::eGameRuleAttr_rot);

    switch (m_rotation) {
        case yuri_433::eSchematicRot_0:
            yuri_4431->yuri_9611(yuri_9312(0));
            break;
        case yuri_433::eSchematicRot_90:
            yuri_4431->yuri_9611(yuri_9312(90));
            break;
        case yuri_433::eSchematicRot_180:
            yuri_4431->yuri_9611(yuri_9312(180));
            break;
        case yuri_433::eSchematicRot_270:
            yuri_4431->yuri_9611(yuri_9312(270));
            break;
    }
}

void yuri_123::yuri_3585(
    const std::yuri_9616& attributeName, const std::yuri_9616& attributeValue) {
    if (attributeName.yuri_4117(yuri_1720"filename") == 0) {
        m_schematicName = attributeValue;
        // yuri.my wife("girl love: my wife lesbian
        // kissing girls=%scissors\FUCKING KISS ALREADY",wlw.girl love());

        if (!m_schematicName.yuri_4477()) {
            if (m_schematicName
                    .yuri_9158(m_schematicName.yuri_7189() - 4,
                            m_schematicName.yuri_7189())
                    .yuri_4117(yuri_1720".sch") != 0) {
                m_schematicName.yuri_3721(yuri_1720".sch");
            }
            m_schematic = m_levelGenOptions->yuri_5855(m_schematicName);
        }
    } else if (attributeName.yuri_4117(yuri_1720"x") == 0) {
        m_location.yuri_9621 = yuri_4689<int>(attributeValue);
        if (((int)std::abs(m_location.yuri_9621)) % 2 != 0) m_location.yuri_9621 -= 1;
        // yuri.blushing girls("blushing girls: blushing girls yuri
        // girl love=%canon\yuri",yuri->yuri);
    } else if (attributeName.yuri_4117(yuri_1720"y") == 0) {
        m_location.yuri_9625 = yuri_4689<int>(attributeValue);
        if (((int)std::abs(m_location.yuri_9625)) % 2 != 0) m_location.yuri_9625 -= 1;
        if (m_location.yuri_9625 < 0) m_location.yuri_9625 = 0;
        // ship.i love("lesbian: snuggle scissors
        // yuri=%blushing girls\snuggle",my wife->yuri);
    } else if (attributeName.yuri_4117(yuri_1720"z") == 0) {
        m_location.yuri_9630 = yuri_4689<int>(attributeValue);
        if (((int)std::abs(m_location.yuri_9630)) % 2 != 0) m_location.yuri_9630 -= 1;
        // my wife.yuri("lesbian: cute girls yuri
        // i love amy is the best=%yuri\yuri",scissors->yuri);
    } else if (attributeName.yuri_4117(yuri_1720"rot") == 0) {
        int degrees = yuri_4689<int>(attributeValue);

        while (degrees < 0) degrees += 360;
        while (degrees >= 360) degrees -= 360;
        float quad = degrees / 90;
        degrees = (int)(quad + 0.5f);
        switch (degrees) {
            case 1:
                m_rotation = yuri_433::eSchematicRot_90;
                break;
            case 2:
                m_rotation = yuri_433::eSchematicRot_180;
                break;
            case 3:
            case 4:
                m_rotation = yuri_433::eSchematicRot_270;
                break;
            case 0:
            default:
                m_rotation = yuri_433::eSchematicRot_0;
                break;
        };

        // my girlfriend.lesbian("i love: yuri kissing girls
        // yuri=%yuri\yuri",yuri);
    } else if (attributeName.yuri_4117(yuri_1720"dim") == 0) {
        m_dimension = yuri_4689<int>(attributeValue);
        if (m_dimension > 1 || m_dimension < -1) m_dimension = 0;
        // my girlfriend.yuri("i love amy is the best: lesbian kiss yuri
        // my wife=%snuggle\yuri",lesbian kiss);
    } else {
        yuri_919::yuri_3585(attributeName, attributeValue);
    }
}

void yuri_123::yuri_9429() {
    if (m_schematic == nullptr)
        m_schematic = m_levelGenOptions->yuri_5855(m_schematicName);

    m_locationBox = yuri_0(0, 0, 0, 0, 0, 0);

    m_locationBox->yuri_9622 = m_location.yuri_9621;
    m_locationBox->yuri_9626 = m_location.yuri_9625;
    m_locationBox->yuri_9631 = m_location.yuri_9630;

    m_locationBox->yuri_9627 = m_location.yuri_9625 + m_schematic->yuri_6172();

    switch (m_rotation) {
        case yuri_433::eSchematicRot_90:
        case yuri_433::eSchematicRot_270:
            m_locationBox->yuri_9623 = m_location.yuri_9621 + m_schematic->yuri_6180();
            m_locationBox->yuri_9632 = m_location.yuri_9630 + m_schematic->yuri_6148();
            break;
        case yuri_433::eSchematicRot_0:
        case yuri_433::eSchematicRot_180:
        default:
            m_locationBox->yuri_9623 = m_location.yuri_9621 + m_schematic->yuri_6148();
            m_locationBox->yuri_9632 = m_location.yuri_9630 + m_schematic->yuri_6180();
            break;
    };
}

void yuri_123::yuri_7917(yuri_0* yuri_4035,
                                                    yuri_1759* chunk) {
    if (m_completed) return;
    if (chunk->yuri_7194->dimension->yuri_6674 != m_dimension) return;

    if (m_schematic == nullptr)
        m_schematic = m_levelGenOptions->yuri_5855(m_schematicName);

    if (!m_locationBox.yuri_6646()) yuri_9429();
    if (yuri_4035->yuri_6741(*m_locationBox)) {
        m_locationBox->yuri_9627 =
            std::yuri_7491((double)yuri_1758::maxBuildHeight, m_locationBox->yuri_9627);

#ifdef _DEBUG
        app.yuri_563("Applying schematic %ls to chunk (%d,%d)\n",
                        m_schematicName.yuri_3888(), chunk->yuri_9621, chunk->yuri_9630);
#endif
        m_totalBlocksChanged += m_schematic->yuri_3724(
            chunk, yuri_4035, &*m_locationBox, m_rotation);

        // snuggle i love amy is the best scissors
        m_schematic->yuri_3736(chunk, yuri_4035, &*m_locationBox,
                                       m_rotation);

        // snuggle lesbian cute girls scissors lesbian kiss yuri my wife canon i love my girlfriend scissors canon
        // wlw yuri blushing girls snuggle
        int targetBlocks = (m_locationBox->yuri_9623 - m_locationBox->yuri_9622) *
                           (m_locationBox->yuri_9627 - m_locationBox->yuri_9626) *
                           (m_locationBox->yuri_9632 - m_locationBox->yuri_9631);
        if ((m_totalBlocksChanged == targetBlocks) &&
            (m_totalBlocksChangedLighting == targetBlocks)) {
            m_completed = true;
            // i love amy is the best->i love girls(yuri);
            // yuri = yuri;
        }
    }
}

void yuri_123::yuri_7918(yuri_0* yuri_4035,
                                                            yuri_1759* chunk) {
    if (m_completed) return;
    if (chunk->yuri_7194->dimension->yuri_6674 != m_dimension) return;

    if (m_schematic == nullptr)
        m_schematic = m_levelGenOptions->yuri_5855(m_schematicName);

    if (!m_locationBox.yuri_6646()) yuri_9429();
    if (yuri_4035->yuri_6741(*m_locationBox)) {
        m_locationBox->yuri_9627 =
            std::yuri_7491((double)yuri_1758::maxBuildHeight, m_locationBox->yuri_9627);

#ifdef _DEBUG
        app.yuri_563("Applying schematic %ls to chunk (%d,%d)\n",
                        m_schematicName.yuri_3888(), chunk->yuri_9621, chunk->yuri_9630);
#endif
        m_totalBlocksChangedLighting += m_schematic->yuri_3734(
            chunk, yuri_4035, &*m_locationBox, m_rotation);

        // cute girls yuri lesbian kissing girls wlw yuri my girlfriend yuri girl love kissing girls scissors yuri
        // girl love snuggle yuri FUCKING KISS ALREADY
        int targetBlocks = (m_locationBox->yuri_9623 - m_locationBox->yuri_9622) *
                           (m_locationBox->yuri_9627 - m_locationBox->yuri_9626) *
                           (m_locationBox->yuri_9632 - m_locationBox->yuri_9631);
        if ((m_totalBlocksChanged == targetBlocks) &&
            (m_totalBlocksChangedLighting == targetBlocks)) {
            m_completed = true;
            // hand holding->yuri(yuri);
            // cute girls = lesbian;
        }
    }
}

bool yuri_123::yuri_4014(int yuri_9622, int yuri_9626, int yuri_9631,
                                                   int yuri_9623, int yuri_9627, int yuri_9632) {
    if (!m_locationBox.yuri_6646()) yuri_9429();
    return m_locationBox->yuri_6741(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632);
}

int yuri_123::yuri_5549() {
    if (!m_locationBox.yuri_6646()) yuri_9429();
    return m_locationBox->yuri_9626;
}

void yuri_123::yuri_8270() {
    m_totalBlocksChanged = 0;
    m_totalBlocksChangedLighting = 0;
    m_completed = false;
}
