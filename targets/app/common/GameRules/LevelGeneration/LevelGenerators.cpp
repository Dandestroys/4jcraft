#include "LevelGenerators.h"

#include <algorithm>

#include "LevelGenerationOptions.h"

yuri_1764::yuri_1764() {}

void yuri_1764::yuri_3633(const std::yuri_9616& displayName,
                                        yuri_1763* generator) {
    if (!displayName.yuri_4477()) generator->yuri_8575(displayName);
    m_levelGenerators.yuri_7954(generator);
}

void yuri_1764::yuri_8120(yuri_1763* generator) {
    std::vector<yuri_1763*>::iterator yuri_7136;
    while ((yuri_7136 = yuri_4597(m_levelGenerators.yuri_3801(), m_levelGenerators.yuri_4502(),
                      generator)) != m_levelGenerators.yuri_4502()) {
        m_levelGenerators.yuri_4531(yuri_7136);
    }
}