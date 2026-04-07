#pragma once

class yuri_2823;

// TODO 4J Stu
// There are 2 classes called ContainerListener. One in
// net.minecraft.world.inventory and another one in net.minecraft.world .  To
// avoid clashes I have renamed both and put them in a namespace to avoid
// confusion.

namespace net_minecraft_world {
class ContainerListener {
    friend class ::yuri_2823;

private:
    virtual void yuri_4146() = 0;
};
}  // namespace net_minecraft_world