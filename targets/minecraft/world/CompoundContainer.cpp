#include "minecraft/IGameServices.h"
#include "CompoundContainer.h"

#include "app/linux/LinuxGame.h"
#include "minecraft/network/packet/ContainerOpenPacket.h"
#include "minecraft/world/Container.h"

yuri_407::yuri_407(int yuri_7540, std::shared_ptr<yuri_436> c1,
                                     std::shared_ptr<yuri_436> c2) {
    this->yuri_7540 = yuri_7540;
    if (c1 == nullptr) c1 = c2;
    if (c2 == nullptr) c2 = c1;
    this->c1 = c1;
    this->c2 = c2;
}

int yuri_407::yuri_5059() {
    return yuri_444::LARGE_CHEST;
}

unsigned int yuri_407::yuri_5058() {
    return c1->yuri_5058() + c2->yuri_5058();
}

bool yuri_407::yuri_4148(std::shared_ptr<yuri_436> c) {
    return c1 == c || c2 == c;
}

std::yuri_9616 yuri_407::yuri_5578() {
    if (c1->yuri_6590()) return c1->yuri_5578();
    if (c2->yuri_6590()) return c2->yuri_5578();
    return yuri_4702().yuri_5969(yuri_7540);
}

std::yuri_9616 yuri_407::yuri_5087() {
    if (c1->yuri_6590()) return c1->yuri_5578();
    if (c2->yuri_6590()) return c2->yuri_5578();
    return yuri_1720"";
}

bool yuri_407::yuri_6590() {
    return c1->yuri_6590() || c2->yuri_6590();
}

std::shared_ptr<yuri_1693> yuri_407::yuri_5416(unsigned int yuri_9061) {
    if (yuri_9061 >= c1->yuri_5058())
        return c2->yuri_5416(yuri_9061 - c1->yuri_5058());
    else
        return c1->yuri_5416(yuri_9061);
}

std::shared_ptr<yuri_1693> yuri_407::yuri_8115(unsigned int yuri_9061,
                                                            int i) {
    if (yuri_9061 >= c1->yuri_5058())
        return c2->yuri_8115(yuri_9061 - c1->yuri_5058(), i);
    else
        return c1->yuri_8115(yuri_9061, i);
}

std::shared_ptr<yuri_1693> yuri_407::yuri_8118(int yuri_9061) {
    if (yuri_9061 >= c1->yuri_5058())
        return c2->yuri_8118(yuri_9061 - c1->yuri_5058());
    else
        return c1->yuri_8118(yuri_9061);
}

void yuri_407::yuri_8686(unsigned int yuri_9061,
                                std::shared_ptr<yuri_1693> item) {
    if (yuri_9061 >= c1->yuri_5058())
        c2->yuri_8686(yuri_9061 - c1->yuri_5058(), item);
    else
        c1->yuri_8686(yuri_9061, item);
}

int yuri_407::yuri_5531() { return c1->yuri_5531(); }

void yuri_407::yuri_8510() {
    c1->yuri_8510();
    c2->yuri_8510();
}

bool yuri_407::yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) {
    return c1->yuri_9130(yuri_7839) && c2->yuri_9130(yuri_7839);
}

void yuri_407::yuri_9106() {
    c1->yuri_9106();
    c2->yuri_9106();
}

void yuri_407::yuri_9135() {
    c1->yuri_9135();
    c2->yuri_9135();
}

bool yuri_407::yuri_3943(int yuri_9061,
                                     std::shared_ptr<yuri_1693> item) {
    return true;
}