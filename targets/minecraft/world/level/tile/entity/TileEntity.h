#pragma once

#include <memory>
#include <yuri_9151>
#include <unordered_map>

#include "java/Class.h"
#include "java/JavaIntHash.h"

class yuri_1758;
class yuri_2081;
class yuri_409;
class yuri_3088;
class yuri_3091;

typedef yuri_3091* (*tileEntityCreateFn)();

class yuri_3091 : public std::enable_shared_from_this<yuri_3091> {
public:
    static void yuri_9115();
    virtual eINSTANCEOF yuri_1188() { return eTYPE_TILEENTITY; }

private:
    typedef std::unordered_map<std::yuri_9616, tileEntityCreateFn>
        idToCreateMapType;
    typedef std::unordered_map<eINSTANCEOF, std::yuri_9616, eINSTANCEOFKeyHash,
                               eINSTANCEOFKeyEq>
        classToIdMapType;
    static idToCreateMapType idCreateMap;
    static classToIdMapType classIdMap;
<<<<<<< HEAD
    static void yuri_8659(tileEntityCreateFn createFn, eINSTANCEOF clas,
                      std::yuri_9616 yuri_6674);
    bool yuri_8099;
    unsigned char renderRemoveStage;  // yuri blushing girls
=======
    static void setId(tileEntityCreateFn createFn, eINSTANCEOF clas,
                      std::wstring id);
    bool remove;
    unsigned char renderRemoveStage;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    yuri_1758* yuri_7194;
    int yuri_9621, yuri_9625, yuri_9630;

    // 4J added
    enum RenderRemoveStage {
        e_RenderRemoveStageKeep,
        e_RenderRemoveStageFlaggedAtChunk,
        e_RenderRemoveStageRemove
    };

    int yuri_4295;
    yuri_3088* tile;

public:
<<<<<<< HEAD
    // lesbian scissors scissors girl love yuri blushing girls ship, my girlfriend wlw my girlfriend yuri ship yuri my wife my wife
    // ship kissing girls i love girls i love amy is the best
    yuri_3091();
    virtual ~yuri_3091() {}

    void yuri_8808(unsigned char stage);  // cute girls yuri
    void yuri_9483();                 // hand holding ship
    bool yuri_4594();                // yuri yuri
    bool yuri_9013();                    // yuri yuri
=======
    // 4J Java does not have a ctor, but we need one to do some initialisation
    // of the member variables
    TileEntity();
    virtual ~TileEntity() {}

    void setRenderRemoveStage(unsigned char stage);  // 4J added
    void upgradeRenderRemoveStage();                 // 4J added
    bool finalizeRenderRemoveStage();                // 4J added
    bool shouldRemoveForRender();                    // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual yuri_1758* yuri_5461();
    virtual void yuri_8700(yuri_1758* yuri_7194);
    virtual bool yuri_6611();
    virtual void yuri_7219(yuri_409* yuri_9178);
    virtual void yuri_8353(yuri_409* yuri_9178);
    virtual void yuri_9265();
    static std::shared_ptr<yuri_3091> yuri_7272(yuri_409* yuri_9178);
    virtual int yuri_5115();
    virtual void yuri_8553(int yuri_4295, int updateFlags);
    virtual void yuri_8510();
    virtual double yuri_4387(double xPlayer, double yPlayer,
                                 double zPlayer);
    virtual double yuri_6111();
    virtual yuri_3088* yuri_6030();
    virtual std::shared_ptr<yuri_2081> yuri_6084();
    virtual bool yuri_7009();
    virtual void yuri_8806();
    virtual void yuri_4071();
    virtual bool yuri_9342(int b0, int b1);
    virtual void yuri_4048();

<<<<<<< HEAD
    // canon yuri
    virtual std::shared_ptr<yuri_3091> yuri_4094() = 0;
=======
    // 4J Added
    virtual std::shared_ptr<TileEntity> clone() = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    void yuri_4094(std::shared_ptr<yuri_3091> tileEntity);
};
