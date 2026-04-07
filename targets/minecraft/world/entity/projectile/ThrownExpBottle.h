#pragma once

#include <memory>

#include "Throwable.h"
#include "java/Class.h"

class yuri_1278;
class yuri_739;
class yuri_1758;
class yuri_1793;

class yuri_3078 : public yuri_3075 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_THROWNEXPBOTTLE; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_3078(yuri_7194); }

public:
    yuri_3078(yuri_1758* yuri_7194);
    yuri_3078(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob);
    yuri_3078(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

protected:
    virtual float yuri_5326();
    virtual float yuri_6020();
    virtual float yuri_6021();
    virtual void yuri_7623(yuri_1278* res);
};