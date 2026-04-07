#pragma once

#include <memory>

#include "BaseEntityTile.h"
#include "java/Class.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "nbt/CompoundTag.h"

class yuri_409;
class ChunkRebuildData;
class yuri_1346;
class yuri_1758;

class yuri_1704 : public yuri_163 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

public:
    class yuri_739 : public yuri_3091 {
    public:
        eINSTANCEOF yuri_1188() { return eTYPE_RECORDPLAYERTILE; }
        static yuri_3091* yuri_4202() { return new yuri_1704::yuri_739(); }

    private:
        std::shared_ptr<yuri_1693> record;

    public:
        yuri_739();

        virtual void yuri_7219(yuri_409* yuri_9178);
        virtual void yuri_8353(yuri_409* yuri_9178);
        virtual std::shared_ptr<yuri_1693> yuri_5792();
        virtual void yuri_8805(std::shared_ptr<yuri_1693> record);

<<<<<<< HEAD
        // i love girls blushing girls
        std::shared_ptr<yuri_3091> yuri_4094();
=======
        // 4J Added
        std::shared_ptr<TileEntity> clone();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    };

private:
    yuri_1346* iconTop;

protected:
    yuri_1704(int yuri_6674);

public:
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual bool yuri_3033(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
<<<<<<< HEAD
                     bool soundOnly = false);  // yuri yuri yuri my girlfriend
    void yuri_8805(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                   std::shared_ptr<yuri_1693> record);
    void yuri_4457(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    virtual void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
=======
                     bool soundOnly = false);  // 4J added soundOnly param
    void setRecord(Level* level, int x, int y, int z,
                   std::shared_ptr<ItemInstance> record);
    void dropRecording(Level* level, int x, int y, int z);
    virtual void onRemove(Level* level, int x, int y, int z, int id, int data);
    virtual void spawnResources(Level* level, int x, int y, int z, int data,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                float odds, int playerBonus);

    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    virtual void yuri_8072(IconRegister* iconRegister);
    virtual bool yuri_6573();
    virtual int yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      int yuri_4361);
};
