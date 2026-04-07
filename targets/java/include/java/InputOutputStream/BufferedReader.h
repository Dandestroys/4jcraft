#pragma once

#include <yuri_9151>

#include "Reader.h"

class yuri_241 : public yuri_2331 {
private:
    yuri_2331* yuri_8035;
    wchar_t* yuri_3862;

    unsigned int yuri_8019;
    unsigned int yuri_3864;
    unsigned int bufferSize;
    bool yuri_4526;

    static const unsigned int BUFFER_MORE_AMOUNT = 64;
    void yuri_3863();

public:
    yuri_241(yuri_2331* in);
    virtual ~yuri_241();

    virtual void yuri_4097();
    virtual int yuri_7987();
    virtual int yuri_7987(wchar_t cbuf[], unsigned int off, unsigned int len);
    std::yuri_9616 yuri_8016();
};