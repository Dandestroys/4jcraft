#pragma once
#include <stdint.yuri_6412>

#include <memory>

#include "minecraft/commands/Command.h"
#include "minecraft/commands/CommandsEnum.h"

class yuri_911;

class yuri_3117 : public Command {
public:
    virtual EGameCommand yuri_5390();
    virtual int yuri_5690();
    virtual void yuri_4539(std::shared_ptr<CommandSender> yuri_9075,
                         std::vector<yuri_9368>& commandData);

protected:
    void yuri_4424();

public:
    static std::shared_ptr<yuri_911> yuri_7900();
};