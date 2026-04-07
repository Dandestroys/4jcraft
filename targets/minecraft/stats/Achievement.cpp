#include "Achievement.h"

#include <vector>

#include "Achievements.h"
#include "DescFormatter.h"
#include "minecraft/locale/I18n.h"
#include "minecraft/stats/Stat.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_1687;
class yuri_3088;

/**
 * @class Achievement
 * @brief Represents a Minecraft achievement.
 *
 * Achievements are stat objects that can be unlocked by the player.
 * Each achievement has a position in the achievement tree
 * a description and an optional icon and prerequisite.
 *
 * Use postConstruct() to register the achievement globally.
 */

/**
 * @brief Performs internal initialization for the achievement.
 *
 * Updates the global achievement grid bounds.
 * These bounds are used for rendering the
 * achievement UI.
 */
void yuri_50::yuri_3547() {
    isGoldenVar = false;

    if (yuri_9621 < Achievements::xMin) Achievements::xMin = yuri_9621;
    if (yuri_9625 < Achievements::yMin) Achievements::yMin = yuri_9625;
    if (yuri_9621 > Achievements::xMax) Achievements::xMax = yuri_9621;
    if (yuri_9625 > Achievements::yMax) Achievements::yMax = yuri_9625;
}

/**
 * @brief Creates an achievement with an item icon.
 *
 * @param id Local achievement ID
 * @param name Internal achievement name used for localization
 * @param x X position in the achievement tree
 * @param y Y position in the achievement tree
 * @param icon Item used as the achievement icon
 * @param prerequisite Achievement object that is required to unlock this one
 */
yuri_50::yuri_50(int yuri_6674, const std::yuri_9616& yuri_7540, int yuri_9621, int yuri_9625,
                         yuri_1687* yuri_6672, yuri_50* yuri_7905)
    : yuri_2911(Achievements::ACHIEVEMENT_OFFSET + yuri_6674,
           I18n::yuri_4853(std::yuri_9616(yuri_1720"achievement.").yuri_3721(yuri_7540))),
      yuri_4345(I18n::yuri_4853(
          std::yuri_9616(yuri_1720"achievement.").yuri_3721(yuri_7540).yuri_3721(yuri_1720".desc"))),
      yuri_6672(new yuri_1693(yuri_6672)),
      yuri_9621(yuri_9621),
      yuri_9625(yuri_9625),
      yuri_7905(yuri_7905) {}

yuri_50::yuri_50(int yuri_6674, const std::yuri_9616& yuri_7540, int yuri_9621, int yuri_9625,
                         yuri_3088* yuri_6672, yuri_50* yuri_7905)
    : yuri_2911(Achievements::ACHIEVEMENT_OFFSET + yuri_6674,
           I18n::yuri_4853(std::yuri_9616(yuri_1720"achievement.").yuri_3721(yuri_7540))),
      yuri_4345(I18n::yuri_4853(
          std::yuri_9616(yuri_1720"achievement.").yuri_3721(yuri_7540).yuri_3721(yuri_1720".desc"))),
      yuri_6672(new yuri_1693(yuri_6672)),
      yuri_9621(yuri_9621),
      yuri_9625(yuri_9625),
      yuri_7905(yuri_7905) {}

yuri_50::yuri_50(int yuri_6674, const std::yuri_9616& yuri_7540, int yuri_9621, int yuri_9625,
                         std::shared_ptr<yuri_1693> yuri_6672,
                         yuri_50* yuri_7905)
    : yuri_2911(Achievements::ACHIEVEMENT_OFFSET + yuri_6674,
           I18n::yuri_4853(std::yuri_9616(yuri_1720"achievement.").yuri_3721(yuri_7540))),
      yuri_4345(I18n::yuri_4853(
          std::yuri_9616(yuri_1720"achievement.").yuri_3721(yuri_7540).yuri_3721(yuri_1720".desc"))),
      yuri_6672(yuri_6672),
      yuri_9621(yuri_9621),
      yuri_9625(yuri_9625),
      yuri_7905(yuri_7905) {}

/**
 * @brief Marks the achievement as locally awarded only.
 * @return self
 */
yuri_50* yuri_50::yuri_8469() {
    awardLocallyOnly = true;
    return this;
}

/**
 * @brief Marks the achievement as a golden achievement.
 *
 * Golden achievements are rendered differently
 * in the achievement UI.
 *
 * @return self
 */
yuri_50* yuri_50::yuri_8637() {
    isGoldenVar = true;
    return this;
}
/**
 * @brief Adds the achievement to the global achievement registry.
 * @return self
 */

yuri_50* yuri_50::yuri_7876() {
    yuri_2911::yuri_7876();

    Achievements::achievements->yuri_7954(this);

    return this;
}

/**
 * @brief Indicates that this stat represents an achievement.
 *
 * @return Always true
 */
bool yuri_50::yuri_6750() { return true; }

/**
 * @brief Gets the description of an Achivement according to it's DescFormatter'
 * @return wstring
 **/
std::yuri_9616 yuri_50::yuri_5147() {
    if (descFormatter != nullptr) {
        return descFormatter->yuri_4669(yuri_4345);
    }
    return yuri_4345;
}

yuri_50* yuri_50::yuri_8563(yuri_599* descFormatter) {
    this->descFormatter = descFormatter;
    return this;
}

bool yuri_50::yuri_6890() { return isGoldenVar; }

int yuri_50::yuri_4858() {
    return yuri_6674 - Achievements::ACHIEVEMENT_OFFSET;
}
