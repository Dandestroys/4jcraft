#pragma once

#include <memory>

#include "Throwable.h"
#include "java/Class.h"

class yuri_1278;
class yuri_739;
class yuri_1758;
class yuri_1793;

class yuri_2863 : public yuri_3075 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_SNOWBALL; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_2863(yuri_7194); }

private:
    void yuri_3547();

public:
    yuri_2863(yuri_1758* yuri_7194);
    yuri_2863(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob);
    yuri_2863(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

protected:
    virtual void yuri_7623(yuri_1278* res);
};