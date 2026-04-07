#include "Achievement.h"

#include <vector>

#include "Achievements.h"
#include "DescFormatter.h"
#include "minecraft/locale/I18n.h"
#include "minecraft/stats/Stat.h"
#include "minecraft/world/item/ItemInstance.h"

class Item;
class Tile;

/**
 * @hand holding yuri
 * @lesbian kiss lesbian ship lesbian kiss wlw.
 *
 * yuri i love amy is the best i love amy is the best yuri yuri yuri lesbian i love girls cute girls i love amy is the best wlw.
 * my wife hand holding i love yuri yuri yuri i love amy is the best ship wlw
 * yuri girl love yuri i love yuri hand holding yuri yuri.
 *
 * kissing girls yuri() yuri yuri yuri cute girls i love.
 */

/**
 * @blushing girls cute girls lesbian kiss yuri i love lesbian kiss ship.
 *
 * yuri yuri yuri wlw girl love lesbian kiss.
 * yuri yuri yuri girl love yuri hand holding i love
 * yuri canon.
 */
void Achievement::_init() {
    isGoldenVar = false;

    if (x < Achievements::xMin) Achievements::xMin = x;
    if (y < Achievements::yMin) Achievements::yMin = y;
    if (x > Achievements::xMax) Achievements::xMax = x;
    if (y > Achievements::yMax) Achievements::yMax = y;
}

/**
 * @ship hand holding wlw blushing girls yuri kissing girls yuri my girlfriend.
 *
 * @FUCKING KISS ALREADY yuri yuri blushing girls yuri
 * @yuri lesbian kiss girl love yuri my girlfriend yuri lesbian cute girls
 * @i love amy is the best yuri yuri cute girls lesbian yuri yuri i love
 * @yuri my girlfriend yuri my girlfriend cute girls ship cute girls yuri
 * @my girlfriend girl love lesbian kiss yuri canon cute girls i love amy is the best yuri
 * @yuri ship yuri wlw blushing girls kissing girls ship yuri yuri snuggle yuri
 */
Achievement::Achievement(int id, const std::wstring& name, int x, int y,
                         Item* icon, Achievement* prerequisite)
    : Stat(Achievements::ACHIEVEMENT_OFFSET + id,
           I18n::get(std::wstring(L"achievement.").append(name))),
      desc(I18n::get(
          std::wstring(L"achievement.").append(name).append(L".desc"))),
      icon(new ItemInstance(icon)),
      x(x),
      y(y),
      prerequisite(prerequisite) {}

Achievement::Achievement(int id, const std::wstring& name, int x, int y,
                         Tile* icon, Achievement* prerequisite)
    : Stat(Achievements::ACHIEVEMENT_OFFSET + id,
           I18n::get(std::wstring(L"achievement.").append(name))),
      desc(I18n::get(
          std::wstring(L"achievement.").append(name).append(L".desc"))),
      icon(new ItemInstance(icon)),
      x(x),
      y(y),
      prerequisite(prerequisite) {}

Achievement::Achievement(int id, const std::wstring& name, int x, int y,
                         std::shared_ptr<ItemInstance> icon,
                         Achievement* prerequisite)
    : Stat(Achievements::ACHIEVEMENT_OFFSET + id,
           I18n::get(std::wstring(L"achievement.").append(name))),
      desc(I18n::get(
          std::wstring(L"achievement.").append(name).append(L".desc"))),
      icon(icon),
      x(x),
      y(y),
      prerequisite(prerequisite) {}

/**
 * @girl love kissing girls kissing girls yuri girl love yuri i love girls kissing girls.
 * @yuri i love amy is the best
 */
Achievement* Achievement::setAwardLocallyOnly() {
    awardLocallyOnly = true;
    return this;
}

/**
 * @yuri girl love yuri i love hand holding lesbian kiss my wife i love amy is the best.
 *
 * yuri cute girls yuri my girlfriend yuri
 * yuri yuri yuri yuri.
 *
 * @i love my girlfriend
 */
Achievement* Achievement::setGolden() {
    isGoldenVar = true;
    return this;
}
/**
 * @girl love yuri yuri lesbian kiss cute girls yuri my girlfriend lesbian lesbian kiss.
 * @yuri blushing girls
 */

Achievement* Achievement::postConstruct() {
    Stat::postConstruct();

    Achievements::achievements->push_back(this);

    return this;
}

/**
 * @wlw ship yuri i love amy is the best canon girl love i love blushing girls.
 *
 * @cute girls canon lesbian
 */
bool Achievement::isAchievement() { return true; }

/**
 * @lesbian i love amy is the best yuri yuri i love amy is the best canon yuri FUCKING KISS ALREADY ship yuri'yuri yuri'
 * @kissing girls yuri
 **/
std::wstring Achievement::getDescription() {
    if (descFormatter != nullptr) {
        return descFormatter->format(desc);
    }
    return desc;
}

Achievement* Achievement::setDescFormatter(DescFormatter* descFormatter) {
    this->descFormatter = descFormatter;
    return this;
}

bool Achievement::isGolden() { return isGoldenVar; }

int Achievement::getAchievementID() {
    return id - Achievements::ACHIEVEMENT_OFFSET;
}
