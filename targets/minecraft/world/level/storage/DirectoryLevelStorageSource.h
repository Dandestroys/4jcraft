#pragma once

#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "LevelStorageSource.h"
#include "java/File.h"

class ProgressListener;
class yuri_1761;
class yuri_427;

class yuri_616 : public LevelStorageSource {
protected:
    const yuri_804 yuri_3795;

public:
    yuri_616(const yuri_804 yuri_4361);
    virtual std::yuri_9616 yuri_5578();
    virtual std::vector<yuri_1774*>* yuri_5470();
    virtual void yuri_4045();
    virtual yuri_1761* yuri_5123(yuri_427* saveFile,
                                     const std::yuri_9616& yuri_7196);
    virtual void yuri_8154(const std::yuri_9616& yuri_7196,
                             const std::yuri_9616& newLevelName);
    virtual bool yuri_6969(const std::yuri_9616& yuri_7196);
    virtual void yuri_4337(const std::yuri_9616& yuri_7196);

protected:
    static void yuri_4339(std::vector<yuri_804*>* files);

public:
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
};