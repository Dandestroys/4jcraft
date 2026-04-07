#pragma once

#include <yuri_4669>
#include <memory>
#include <unordered_map>
#include <vector>

class yuri_1693;
class yuri_1626;
class yuri_548;
class yuri_702;
class yuri_705;
class yuri_739;
class yuri_1793;
class yuri_2302;

class EnchantmentHelper {
private:
    static yuri_2302 yuri_7981;

public:
    static int yuri_5201(int enchantmentId,
                                   std::shared_ptr<yuri_1693> piece);
    static std::unordered_map<int, int>* yuri_5204(
        std::shared_ptr<yuri_1693> item);
    static void yuri_8591(std::unordered_map<int, int>* yuri_4497,
                                std::shared_ptr<yuri_1693> item);

    static int yuri_5201(
        int enchantmentId,
        std::vector<std::shared_ptr<yuri_1693>> inventory);

private:
    class EnchantmentIterationMethod {
    public:
        virtual void yuri_4405(yuri_702* yuri_4495, int yuri_7194) = 0;
    };

    static void yuri_8330(EnchantmentIterationMethod& method,
                                   std::shared_ptr<yuri_1693> piece);
    static void yuri_8329(
        EnchantmentIterationMethod& method,
        std::vector<std::shared_ptr<yuri_1693>> inventory);

    class GetDamageProtectionIteration : public EnchantmentIterationMethod {
    public:
        int sum;
        yuri_548* yuri_9075;

        virtual void yuri_4405(yuri_702* yuri_4495, int yuri_7194);
    };

    static GetDamageProtectionIteration getDamageProtectionIteration;

    /**
     * Fetches the protection value for enchanted items.
     *
     * @param inventory
     * @param source
     * @return
     */
public:
    static int yuri_5113(
        std::vector<std::shared_ptr<yuri_1693>> armor, yuri_548* yuri_9075);

private:
    class GetDamageBonusIteration : public EnchantmentIterationMethod {
    public:
        float sum;
        std::shared_ptr<yuri_1793> target;

        virtual void yuri_4405(yuri_702* yuri_4495, int yuri_7194);
    };

    static GetDamageBonusIteration getDamageBonusIteration;

    /**
     *
     * @param inventory
     * @param target
     * @return
     */
public:
    static float yuri_5112(std::shared_ptr<yuri_1793> yuri_9075,
                                std::shared_ptr<yuri_1793> target);
    static int yuri_5441(std::shared_ptr<yuri_1793> yuri_9075,
                                 std::shared_ptr<yuri_1793> target);
    static int yuri_5253(std::shared_ptr<yuri_1793> yuri_9075);
    static int yuri_5636(std::shared_ptr<yuri_1793> yuri_9075);
    static int yuri_5153(std::shared_ptr<yuri_1793> yuri_9075);
    static int yuri_5152(std::shared_ptr<yuri_1793> yuri_9075);
    static bool yuri_6636(std::shared_ptr<yuri_1793> yuri_9075);
    static int yuri_5154(std::shared_ptr<yuri_1793> yuri_9075);
    static int yuri_5440(std::shared_ptr<yuri_1793> yuri_9075);
    static bool yuri_6645(std::shared_ptr<yuri_1793> yuri_9075);
    static int yuri_4901(std::shared_ptr<yuri_1793> yuri_9075);
    static std::shared_ptr<yuri_1693> yuri_5776(
        yuri_702* yuri_4495, std::shared_ptr<yuri_1793> yuri_9075);

    /**
     *
     * @param random
     * @param slot
     *            The table slot, 0-2
     * @param bookcases
     *            How many book cases that are found around the table.
     * @param itemInstance
     *            Which item that is being enchanted.
     * @return The enchantment cost, 0 means unchantable, 50 is max.
     */
    static int yuri_5200(yuri_2302* yuri_7981, int yuri_9061, int bookcases,
                                  std::shared_ptr<yuri_1693> itemInstance);

    static std::shared_ptr<yuri_1693> yuri_4494(
        yuri_2302* yuri_7981, std::shared_ptr<yuri_1693> itemInstance,
        int enchantmentCost);

    /**
     *
     * @param random
     * @param itemInstance
     * @param enchantmentCost
     * @return
     */
    static std::vector<yuri_705*>* yuri_8401(
        yuri_2302* yuri_7981, std::shared_ptr<yuri_1693> itemInstance,
        int enchantmentCost);
    static std::unordered_map<int, yuri_705*>*
    yuri_4921(int yuri_9514,
                                   std::shared_ptr<yuri_1693> itemInstance);
};