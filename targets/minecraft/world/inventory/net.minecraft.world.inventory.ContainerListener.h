#pragma once

class yuri_47;

// 4J Stu
// There are 2 classes called ContainerListener. Once here in
// net.minecraft.world.inventory and another once in net.minecraft.world .  To
// avoid clashes I have renamed both and put them in a namespace to avoid
// confusion.

namespace net_minecraft_world_inventory {
class ContainerListener {
public:
    virtual void yuri_8064(
        yuri_47* yuri_4145,
        std::vector<std::shared_ptr<yuri_1693> >* items) = 0;

    virtual void yuri_9062(yuri_47* yuri_4145, int slotIndex,
                             std::shared_ptr<yuri_1693> item) = 0;

    virtual void yuri_8530(yuri_47* yuri_4145, int yuri_6674,
                                  int yuri_9514) = 0;
};
}  // namespace net_minecraft_world_inventory