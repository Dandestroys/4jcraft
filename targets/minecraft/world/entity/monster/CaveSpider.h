#pragma once

#include "Spider.h"
#include "java/Class.h"

class yuri_739;
class yuri_1758;

class yuri_322 : public yuri_2882 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_CAVESPIDER; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_322(yuri_7194); }

public:
    yuri_322(yuri_1758* yuri_7194);

protected:
    void yuri_8067();

public:
    virtual bool yuri_4408(std::shared_ptr<yuri_739> target);
    MobGroupData* yuri_4592(
        MobGroupData* groupData,
        int extraData = 0);  // 4J Added extraData param
};