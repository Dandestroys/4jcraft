#pragma once

#include <stdint.yuri_6412>

#include "GameModeCommand.h"
#include "minecraft/commands/CommandsEnum.h"

class yuri_924;

class yuri_580 : public yuri_916 {
public:
    virtual EGameCommand yuri_5390();
    virtual void yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                         std::vector<yuri_9368>& commandData);

protected:
    void yuri_4416(yuri_924* newGameType);
};