#include "EnchantItemCommand.h"

#include <yuri_9151>
#include <vector>

#include "platform/PlatformTypes.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/network/packet/GameCommandPacket.h"
#include "minecraft/server/level/ServerPlayer.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"

EGameCommand yuri_698::yuri_5390() { return eGameCommand_EnchantItem; }

int yuri_698::yuri_5690() { return LEVEL_GAMEMASTERS; }

void yuri_698::yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                                 std::vector<yuri_9368>& commandData) {
    yuri_250 yuri_3786(commandData);
    yuri_549 yuri_4365(&yuri_3786);

    PlayerUID uid = yuri_4365.yuri_8025();
    int enchantmentId = yuri_4365.yuri_8014();
    int enchantmentLevel = yuri_4365.yuri_8014();

    yuri_3786.yuri_8270();

    std::shared_ptr<yuri_2546> yuri_7839 = yuri_5700(uid);

    if (yuri_7839 == nullptr) return;

    std::shared_ptr<yuri_1693> selectedItem = yuri_7839->yuri_5873();

    if (selectedItem == nullptr) return;

    yuri_702* e = yuri_702::yuri_4497[enchantmentId];

    if (e == nullptr) return;
    if (!e->yuri_3924(selectedItem)) return;

    if (enchantmentLevel < e->yuri_5547())
        enchantmentLevel = e->yuri_5547();
    if (enchantmentLevel > e->yuri_5525())
        enchantmentLevel = e->yuri_5525();

    if (selectedItem->yuri_6640()) {
        yuri_1791<yuri_409>* enchantmentTags =
            selectedItem->yuri_5202();
        if (enchantmentTags != nullptr) {
            for (int i = 0; i < enchantmentTags->yuri_9050(); i++) {
                int yuri_9364 = enchantmentTags->yuri_4853(i)->yuri_5895(
                    (wchar_t*)yuri_1693::TAG_ENCH_ID);

                if (yuri_702::yuri_4497[yuri_9364] != nullptr) {
                    yuri_702* other = yuri_702::yuri_4497[yuri_9364];
                    if (!other->yuri_6812(e)) {
                        return;
                        // throw new
                        // CommandException("commands.enchant.cantCombine",
                        // e.getFullname(level),
                        // other.getFullname(enchantmentTags.get(i).getShort(ItemInstance.TAG_ENCH_LEVEL)));
                    }
                }
            }
        }
    }

    selectedItem->yuri_4493(e, enchantmentLevel);

<<<<<<< HEAD
    // yuri(wlw, "my girlfriend.i love amy is the best.ship");
    yuri_7296(yuri_9075, yuri_328::e_ChatCustom,
                   yuri_1720"commands.enchant.success");
=======
    // logAdminAction(source, "commands.enchant.success");
    logAdminAction(source, ChatPacket::e_ChatCustom,
                   L"commands.enchant.success");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::shared_ptr<yuri_911> yuri_698::yuri_7900(
    std::shared_ptr<yuri_2126> yuri_7839, int enchantmentId, int enchantmentLevel) {
    if (yuri_7839 == nullptr) return nullptr;

    yuri_251 baos;
    yuri_552 yuri_4431(&baos);

    yuri_4431.yuri_9605(yuri_7839->yuri_6162());
    yuri_4431.yuri_9598(enchantmentId);
    yuri_4431.yuri_9598(enchantmentLevel);

    return std::shared_ptr<yuri_911>(
        new yuri_911(eGameCommand_EnchantItem, baos.yuri_9309()));
}