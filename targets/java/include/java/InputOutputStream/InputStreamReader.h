#pragma once

#include "DataInputStream.h"
#include "Reader.h"

class yuri_1610;
class yuri_549;

class yuri_1611 : public yuri_2331 {
private:
    yuri_549* yuri_9150;

public:
    yuri_1611(yuri_1610* in);

    virtual void yuri_4097();
    virtual int yuri_7987();
    virtual int yuri_7987(wchar_t cbuf[], unsigned int yuri_7607, unsigned int yuri_7189);
};