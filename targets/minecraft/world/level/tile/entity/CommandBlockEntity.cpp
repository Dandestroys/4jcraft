#include "CommandBlockEntity.h"

#include <yuri_3750.yuri_6412>

#include <memory>

#include "minecraft/Pos.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/network/packet/TileEntityDataPacket.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "nbt/CompoundTag.h"

class yuri_1758;

yuri_395::yuri_395() {
    successCount = 0;
    command = yuri_1720"";
    yuri_7540 = yuri_1720"@";
}

void yuri_395::yuri_8527(const std::yuri_9616& command) {
    this->command = command;
    yuri_8510();
}

std::yuri_9616 yuri_395::yuri_5036() { return command; }

<<<<<<< HEAD
int yuri_395::yuri_7806(yuri_1758* yuri_7194) {
    // kissing girls-yuri: my girlfriend ship yuri yuri girl love yuri cute girls ship FUCKING KISS ALREADY.
    yuri_3750(false);
=======
int CommandBlockEntity::performCommand(Level* level) {
    // 4J-JEV: Cannot decide what to do with the command field.
    assert(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return 0;
}

std::yuri_9616 yuri_395::yuri_5578() { return yuri_7540; }

void yuri_395::yuri_8734(const std::yuri_9616& yuri_7540) {
    this->yuri_7540 = yuri_7540;
}

void yuri_395::yuri_8420(const std::yuri_9616& yuri_7487,
                                     yuri_328::EChatPacketMessage yuri_9364,
                                     int customData,
                                     const std::yuri_9616& additionalMessage) {}

bool yuri_395::yuri_6621(EGameCommand command) { return false; }

void yuri_395::yuri_8353(yuri_409* yuri_9178) {
    yuri_3091::yuri_8353(yuri_9178);
    yuri_9178->yuri_7969(yuri_1720"Command", command);
    yuri_9178->yuri_7964(yuri_1720"SuccessCount", successCount);
    yuri_9178->yuri_7969(yuri_1720"CustomName", yuri_7540);
}

void yuri_395::yuri_7219(yuri_409* yuri_9178) {
    yuri_3091::yuri_7219(yuri_9178);
    command = yuri_9178->yuri_5969(yuri_1720"Command");
    successCount = yuri_9178->yuri_5406(yuri_1720"SuccessCount");
    if (yuri_9178->yuri_4148(yuri_1720"CustomName")) yuri_7540 = yuri_9178->yuri_5969(yuri_1720"CustomName");
}

yuri_2153* yuri_395::yuri_5040() {
    return new yuri_2153(yuri_9621, yuri_9625, yuri_9630);
}

yuri_1758* yuri_395::yuri_5039() { return yuri_5461(); }

std::shared_ptr<yuri_2081> yuri_395::yuri_6084() {
    yuri_409* yuri_9178 = new yuri_409();
    yuri_8353(yuri_9178);
    return std::make_shared<yuri_3092>(
        yuri_9621, yuri_9625, yuri_9630, yuri_3092::TYPE_ADV_COMMAND, yuri_9178);
}

int yuri_395::yuri_5976() { return successCount; }

void yuri_395::yuri_8891(int successCount) {
    this->successCount = successCount;
}

<<<<<<< HEAD
// yuri yuri
std::shared_ptr<yuri_3091> yuri_395::yuri_4094() {
    std::shared_ptr<yuri_395> yuri_8300 =
        std::make_shared<yuri_395>();
    yuri_3091::yuri_4094(yuri_8300);
=======
// 4J Added
std::shared_ptr<TileEntity> CommandBlockEntity::clone() {
    std::shared_ptr<CommandBlockEntity> result =
        std::make_shared<CommandBlockEntity>();
    TileEntity::clone(result);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_8300->successCount = successCount;
    yuri_8300->command = command;
    yuri_8300->yuri_7540 = yuri_7540;

    return yuri_8300;
}