#include "CompleteAllRuleDefinition.h"

#include <memory>
#include <unordered_map>
#include <utility>

#include "app/common/GameRules/LevelRules/RuleDefinitions/CompoundGameRuleDefinition.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/common/GameRules/LevelRules/Rules/GameRule.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "minecraft/network/Connection.h"
#include "minecraft/network/packet/UpdateGameRuleProgressPacket.h"

void yuri_401::yuri_5002(
    std::vector<yuri_919*>* children) {
    yuri_408::yuri_5002(children);
}

bool yuri_401::yuri_7653(yuri_918* rule, int yuri_9294, int yuri_9621,
                                          int yuri_9625, int yuri_9630) {
    bool statusChanged =
        yuri_408::yuri_7653(rule, yuri_9294, yuri_9621, yuri_9625, yuri_9630);
    if (statusChanged) yuri_9471(rule);
    return statusChanged;
}

bool yuri_401::yuri_7613(
    yuri_918* rule, std::shared_ptr<yuri_1693> item) {
    bool statusChanged = yuri_408::yuri_7613(rule, item);
    if (statusChanged) yuri_9471(rule);
    return statusChanged;
}

void yuri_401::yuri_9471(yuri_918* rule) {
    int goal = 0;
    int progress = 0;
    for (auto yuri_7136 = rule->m_parameters.yuri_3801(); yuri_7136 != rule->m_parameters.yuri_4502();
         ++yuri_7136) {
        if (yuri_7136->yuri_8394.isPointer) {
            goal += yuri_7136->yuri_8394.gr->yuri_5299()->yuri_5322();
            progress += yuri_7136->yuri_8394.gr->yuri_5299()->yuri_5755(
                yuri_7136->yuri_8394.gr);
        }
    }
    if (rule->yuri_5054() != nullptr) {
        PacketData yuri_4295;
        yuri_4295.goal = goal;
        yuri_4295.progress = progress;

        int yuri_6672 = -1;
        int auxValue = 0;

        if (m_lastRuleStatusChanged != nullptr) {
            yuri_6672 = m_lastRuleStatusChanged->yuri_5385();
            auxValue = m_lastRuleStatusChanged->yuri_4919();
            m_lastRuleStatusChanged = nullptr;
        }
        rule->yuri_5054()->yuri_8410(
            std::shared_ptr<yuri_3282>(
                new yuri_3282(
                    yuri_4860(), this->yuri_7328, yuri_6672, auxValue, 0,
                    &yuri_4295, sizeof(PacketData))));
    }
    app.yuri_563("Updated CompleteAllRule - Completed %d of %d\n", progress,
                    goal);
}

std::yuri_9616 yuri_401::yuri_4822(
    const std::yuri_9616& description, void* yuri_4295, int dataLength) {
    PacketData* values = (PacketData*)yuri_4295;
    std::yuri_9616 newDesc = description;
    newDesc =
        yuri_8253(newDesc, yuri_1720"{*progress*}", yuri_9312<int>(values->progress));
    newDesc = yuri_8253(newDesc, yuri_1720"{*goal*}", yuri_9312<int>(values->goal));
    return newDesc;
}