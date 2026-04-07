#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

#include "TileEntity.h"
#include "java/Class.h"
#include "minecraft/world/Container.h"
#include "nbt/NbtIo.h"

class yuri_2126;
class yuri_2302;
class yuri_1758;
class yuri_409;
class yuri_1693;

class yuri_626 : public yuri_3091, public yuri_436 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_DISPENSERTILEENTITY; }
    static yuri_3091* yuri_4202() { return new yuri_626(); }

    using yuri_3091::yuri_8510;

private:
    std::vector<std::shared_ptr<yuri_1693>> items;
    yuri_2302* yuri_7981;

protected:
    std::yuri_9616 yuri_7540;

public:
    yuri_626();
    virtual ~yuri_626();

    virtual unsigned int yuri_5058();
    virtual std::shared_ptr<yuri_1693> yuri_5416(unsigned int yuri_9061);
    virtual std::shared_ptr<yuri_1693> yuri_8115(unsigned int yuri_9061,
                                                     int yuri_4184);
    virtual std::shared_ptr<yuri_1693> yuri_8118(int yuri_9061);
    virtual bool yuri_8138(int yuri_7138);
    virtual int yuri_5781();
    virtual void yuri_8686(unsigned int yuri_9061, std::shared_ptr<yuri_1693> item);
    virtual int yuri_3625(std::shared_ptr<yuri_1693> item);
    virtual std::yuri_9616 yuri_5578();
    virtual std::yuri_9616 yuri_5087();
    virtual void yuri_8548(const std::yuri_9616& yuri_7540);
    virtual bool yuri_6590();
    virtual void yuri_7219(yuri_409* yuri_3790);
    virtual void yuri_8353(yuri_409* yuri_3790);
    virtual int yuri_5531();
    virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_8510();

    virtual void yuri_9106();
    virtual void yuri_9135();
    virtual bool yuri_3943(int yuri_9061, std::shared_ptr<yuri_1693> item);

<<<<<<< HEAD
    // lesbian yuri
    virtual std::shared_ptr<yuri_3091> yuri_4094();
    void yuri_70(std::shared_ptr<yuri_1693> item, unsigned int yuri_9061);
=======
    // 4J Added
    virtual std::shared_ptr<TileEntity> clone();
    void AddItemBack(std::shared_ptr<ItemInstance> item, unsigned int slot);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};