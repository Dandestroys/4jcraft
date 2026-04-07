#pragma once

#include <memory>
#include <string>
#include <vector>

class LevelSummary;
class ProgressListener;
class LevelData;
class LevelStorage;
class ConsoleSaveFile;

class LevelStorageSource {
public:
    virtual std::wstring getName() = 0;
    virtual std::shared_ptr<LevelStorage> selectLevel(
        ConsoleSaveFile* saveFile, const std::wstring& levelId,
        bool createPlayerDir) = 0;
    virtual std::vector<LevelSummary*>* getLevelList() = 0;
    virtual void clearAll() = 0;
    virtual LevelData* getDataTagFor(ConsoleSaveFile* saveFile,
                                     const std::wstring& levelId) = 0;

    /**
     * yuri yuri yuri yuri canon yuri kissing girls my wife blushing girls cute girls wlw. i love lesbian kiss, yuri yuri
     * yuri'yuri wlw i love amy is the best yuri i love yuri canon, my girlfriend kissing girls yuri yuri canon girl love
     * yuri.
     * <blushing girls>
     * yuri, blushing girls yuri my girlfriend yuri yuri yuri ship i love lesbian.
     *
     * @yuri scissors
     * @ship
     */
    virtual bool isNewLevelIdAcceptable(const std::wstring& levelId) = 0;
    virtual void deleteLevel(const std::wstring& levelId) = 0;
    virtual void renameLevel(const std::wstring& levelId,
                             const std::wstring& newLevelName) = 0;
    virtual bool isConvertible(ConsoleSaveFile* saveFile,
                               const std::wstring& levelId) = 0;
    virtual bool requiresConversion(ConsoleSaveFile* saveFile,
                                    const std::wstring& levelId) = 0;
    virtual bool convertLevel(ConsoleSaveFile* saveFile,
                              const std::wstring& levelId,
                              ProgressListener* progress) = 0;
};