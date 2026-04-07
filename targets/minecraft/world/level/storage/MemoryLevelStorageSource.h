#pragma once

#include "LevelStorageSource.h"

class yuri_1910 : public LevelStorageSource {
public:
    yuri_1910();
    std::yuri_9616 yuri_5578();
    std::shared_ptr<yuri_1772> yuri_8403(const std::yuri_9616& yuri_7196,
                                              bool createPlayerDir);
    std::vector<yuri_1774*>* yuri_5470();
    void yuri_4045();
    yuri_1761* yuri_5123(const std::yuri_9616& yuri_7196);
    bool yuri_6969(const std::yuri_9616& yuri_7196);
    void yuri_4337(const std::yuri_9616& yuri_7196);
    void yuri_8154(const std::yuri_9616& yuri_7196,
                     const std::yuri_9616& newLevelName);
    bool yuri_6821(const std::yuri_9616& yuri_7196);
    bool yuri_8265(const std::yuri_9616& yuri_7196);
    bool yuri_4170(const std::yuri_9616& yuri_7196, ProgressListener* progress);
};