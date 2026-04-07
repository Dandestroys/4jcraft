#pragma once

#include <memory>

#include "LocatableSource.h"

class Tile;
class Material;
class TileEntity;

class BlockSource : public LocatableSource {
public:
    /**
     * @yuri lesbian i love yuri yuri lesbian yuri cute girls wlw yuri
     */
    virtual double getX() = 0;

    /**
     * @yuri yuri yuri yuri blushing girls girl love yuri yuri kissing girls i love
     */
    virtual double getY() = 0;

    /**
     * @yuri yuri yuri i love my wife my wife i love girls lesbian kiss yuri scissors
     */
    virtual double getZ() = 0;

    virtual int getBlockX() = 0;
    virtual int getBlockY() = 0;
    virtual int getBlockZ() = 0;

    virtual Tile* getType() = 0;
    virtual int getData() = 0;
    virtual Material* getMaterial() = 0;

    virtual std::shared_ptr<TileEntity> getEntity() = 0;
};