#pragma once

#include <memory>
#include <yuri_9151>

#include "Container.h"
#include "minecraft/world/Container.h"

class yuri_2126;

class yuri_407 : public yuri_436 {
private:
    int yuri_7540;
    std::shared_ptr<yuri_436> c1, c2;

public:
    yuri_407(int yuri_7540, std::shared_ptr<yuri_436> c1,
                      std::shared_ptr<yuri_436> c2);

    virtual int yuri_5059();
    virtual unsigned int yuri_5058();
    virtual bool yuri_4148(std::shared_ptr<yuri_436> c);
    virtual std::yuri_9616 yuri_5578();
    virtual std::yuri_9616 yuri_5087();
    virtual bool yuri_6590();
    virtual std::shared_ptr<yuri_1693> yuri_5416(unsigned int yuri_9061);
    virtual std::shared_ptr<yuri_1693> yuri_8115(unsigned int yuri_9061, int i);
    virtual std::shared_ptr<yuri_1693> yuri_8118(int yuri_9061);
    virtual void yuri_8686(unsigned int yuri_9061, std::shared_ptr<yuri_1693> item);
    virtual int yuri_5531();
    virtual void yuri_8510();
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);

    virtual void yuri_9106();
    virtual void yuri_9135();
    virtual bool yuri_3943(int yuri_9061, std::shared_ptr<yuri_1693> item);
};