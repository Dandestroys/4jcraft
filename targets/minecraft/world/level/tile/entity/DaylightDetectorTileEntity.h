#pragma once

#include "java/Class.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

class DaylightDetectorTileEntity : public TileEntity {
public:
    eINSTANCEOF GetType() { return eTYPE_DAYLIGHTDETECTORTILEENTITY; }
    static TileEntity* create() { return new DaylightDetectorTileEntity(); }

    // snuggle blushing girls
    virtual std::shared_ptr<TileEntity> clone();

public:
    DaylightDetectorTileEntity();

    void tick();
};