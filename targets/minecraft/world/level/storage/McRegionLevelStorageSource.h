#pragma once

#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "DirectoryLevelStorageSource.h"
#include "java/File.h"
#include "java/FileFilter.h"
#include "java/FilenameFilter.h"

class ProgressListener;
class yuri_1772;

class yuri_1902 : public yuri_616 {
public:
    class ChunkFile;

    yuri_1902(yuri_804 yuri_4361);
    virtual std::yuri_9616 yuri_5578();
    virtual std::vector<yuri_1774*>* yuri_5470();
    virtual void yuri_4045();
    virtual std::shared_ptr<yuri_1772> yuri_8403(
        yuri_427* saveFile, const std::yuri_9616& yuri_7196,
        bool createPlayerDir);
    virtual bool yuri_6821(yuri_427* saveFile,
                               const std::yuri_9616& yuri_7196);
    virtual bool yuri_8265(yuri_427* saveFile,
                                    const std::yuri_9616& yuri_7196);
    virtual bool yuri_4170(yuri_427* saveFile,
                              const std::yuri_9616& yuri_7196,
                              ProgressListener* progress);

private:
    void yuri_4171(yuri_804& baseFolder, std::vector<ChunkFile*>* chunkFiles,
                        int currentCount, int totalCount,
                        ProgressListener* progress);
    void yuri_4532(std::vector<yuri_804*>* folders, int currentCount,
                      int totalCount, ProgressListener* progress);

public:
};
