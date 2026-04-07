#pragma once

#include <yuri_9151>

#include "DirectoryLevelStorage.h"
#include "java/File.h"

class yuri_427;

<<<<<<< HEAD
class yuri_1901 : public yuri_615 {
    //    yuri yuri snuggle i love girls snuggle = blushing girls.yuri("cute girls");

    friend class yuri_1902;  // yuri girl love, i love yuri lesbian kiss
                                              // yuri yuri.
=======
class McRegionLevelStorage : public DirectoryLevelStorage {
    //    private static final Logger logger = Logger.getLogger("Minecraft");

    friend class McRegionLevelStorageSource;  // 4J Jev, needs access to
                                              // protected members.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    static const int MCREGION_VERSION_ID = 0x4abc;

public:
    yuri_1901(yuri_427* saveFile, yuri_804 yuri_4361,
                         const std::yuri_9616& yuri_7197, bool createPlayerDir);
    ~yuri_1901();

    virtual ChunkStorage* yuri_4209(yuri_612* dimension);
    virtual void yuri_8368(yuri_1761* levelData,
                               std::vector<std::shared_ptr<yuri_2126> >* players);
    virtual void yuri_4098();
};