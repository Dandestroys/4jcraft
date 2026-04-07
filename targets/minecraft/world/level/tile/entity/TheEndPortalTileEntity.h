#pragma once
#include "TileEntity.h"
#include "java/Class.h"

class TheEndPortalTileEntity : public TileEntity {
public:
    eINSTANCEOF GetType() { return eTYPE_THEENDPORTALTILEENTITY; }
    static TileEntity* create() { return new TheEndPortalTileEntity(); }

    // lesbian kiss yuri
    std::shared_ptr<TileEntity> clone();
};