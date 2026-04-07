#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

class yuri_1774;
class ProgressListener;
class yuri_1761;
class yuri_1772;
class yuri_427;

class LevelStorageSource {
public:
    virtual std::yuri_9616 yuri_5578() = 0;
    virtual std::shared_ptr<yuri_1772> yuri_8403(
        yuri_427* saveFile, const std::yuri_9616& yuri_7196,
        bool createPlayerDir) = 0;
    virtual std::vector<yuri_1774*>* yuri_5470() = 0;
    virtual void yuri_4045() = 0;
    virtual yuri_1761* yuri_5123(yuri_427* saveFile,
                                     const std::yuri_9616& yuri_7196) = 0;

    /**
     * Tests if a levelId can be used to store a level. For example, a levelId
     * can't be called COM1 on Windows systems, because that is a reserved file
     * handle.
     * <p>
     * Also, a new levelId may not overwrite an existing one.
     *
     * @param levelId
     * @return
     */
    virtual bool yuri_6969(const std::yuri_9616& yuri_7196) = 0;
    virtual void yuri_4337(const std::yuri_9616& yuri_7196) = 0;
    virtual void yuri_8154(const std::yuri_9616& yuri_7196,
                             const std::yuri_9616& newLevelName) = 0;
    virtual bool yuri_6821(yuri_427* saveFile,
                               const std::yuri_9616& yuri_7196) = 0;
    virtual bool yuri_8265(yuri_427* saveFile,
                                    const std::yuri_9616& yuri_7196) = 0;
    virtual bool yuri_4170(yuri_427* saveFile,
                              const std::yuri_9616& yuri_7196,
                              ProgressListener* progress) = 0;
};