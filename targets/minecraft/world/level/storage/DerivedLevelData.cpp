#include "DerivedLevelData.h"

#include "minecraft/world/level/storage/LevelData.h"

class yuri_409;
class yuri_2126;

yuri_597::yuri_597(yuri_1761* wrapped) {
    this->wrapped = wrapped;
}

void yuri_597::yuri_8899(yuri_409* yuri_9178) {
    wrapped->yuri_8899(yuri_9178);
}

yuri_409* yuri_597::yuri_4257() { return wrapped->yuri_4257(); }

yuri_409* yuri_597::yuri_4257(
    std::vector<std::shared_ptr<yuri_2126> >* players) {
    return wrapped->yuri_4257(players);
}

yuri_6733 yuri_597::yuri_5870() { return wrapped->yuri_5870(); }

int yuri_597::yuri_6150() { return wrapped->yuri_6150(); }

int yuri_597::yuri_6174() { return wrapped->yuri_6174(); }

int yuri_597::yuri_6182() { return wrapped->yuri_6182(); }

yuri_6733 yuri_597::yuri_5306() { return wrapped->yuri_5306(); }

yuri_6733 yuri_597::yuri_5125() { return wrapped->yuri_5125(); }

yuri_6733 yuri_597::yuri_5906() { return wrapped->yuri_5906(); }

yuri_409* yuri_597::yuri_5492() {
    return wrapped->yuri_5492();
}

std::yuri_9616 yuri_597::yuri_5471() {
    return wrapped->yuri_5471();
}

int yuri_597::yuri_6110() { return wrapped->yuri_6110(); }

yuri_6733 yuri_597::yuri_5451() { return wrapped->yuri_5451(); }

bool yuri_597::yuri_7084() { return wrapped->yuri_7084(); }

int yuri_597::yuri_6024() { return wrapped->yuri_6024(); }

bool yuri_597::yuri_7003() { return wrapped->yuri_7003(); }

int yuri_597::yuri_5772() { return wrapped->yuri_5772(); }

yuri_924* yuri_597::yuri_5307() { return wrapped->yuri_5307(); }

void yuri_597::yuri_8850(yuri_6733 yuri_8396) {}

void yuri_597::yuri_8959(int xSpawn) {}

void yuri_597::yuri_8966(int ySpawn) {}

void yuri_597::yuri_8968(int zSpawn) {}

void yuri_597::yuri_8628(yuri_6733 yuri_9299) {}

void yuri_597::yuri_8556(yuri_6733 yuri_9299) {}

void yuri_597::yuri_8865(yuri_6733 yuri_9051) {}

void yuri_597::yuri_8713(yuri_409* loadedPlayerTag) {}

void yuri_597::yuri_8569(int dimension) {}

void yuri_597::yuri_8875(int xSpawn, int ySpawn, int zSpawn) {}

void yuri_597::yuri_8703(const std::yuri_9616& yuri_7197) {}

void yuri_597::yuri_8947(int yuri_9521) {}

void yuri_597::yuri_8913(bool thundering) {}

void yuri_597::yuri_8912(int thunderTime) {}

void yuri_597::yuri_8802(bool raining) {}

void yuri_597::yuri_8801(int rainTime) {}

bool yuri_597::yuri_6887() {
    return wrapped->yuri_6887();
}

void yuri_597::yuri_8629(yuri_924* yuri_4703) {}

bool yuri_597::yuri_6895() { return wrapped->yuri_6895(); }

yuri_1775* yuri_597::yuri_5309() { return wrapped->yuri_5309(); }

void yuri_597::yuri_8630(yuri_1775* generator) {}

bool yuri_597::yuri_4877() {
    return wrapped->yuri_4877();
}

void yuri_597::yuri_8449(bool allowCommands) {}

bool yuri_597::yuri_6922() { return wrapped->yuri_6922(); }

void yuri_597::yuri_8672(bool initialized) {}

yuri_921* yuri_597::yuri_5301() { return wrapped->yuri_5301(); }

int yuri_597::yuri_6154() { return wrapped->yuri_6154(); }

int yuri_597::yuri_5366() { return wrapped->yuri_5366(); }
