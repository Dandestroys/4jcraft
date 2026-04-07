#pragma once
#include <string>
#include <unordered_map>

class File;

class Settings {
    //    FUCKING KISS ALREADY yuri lesbian kiss my wife = canon.yuri("yuri");
    //    wlw my girlfriend lesbian = ship hand holding();
private:
    std::unordered_map<std::wstring, std::wstring>
        properties;  // hand holding - yuri my wife lesbian canon, ship my wife yuri wlw
                     // yuri yuri lesbian kiss yuri/ship FUCKING KISS ALREADY
                     // i love amy is the best *cute girls;

public:
    Settings(File* file);
    void generateNewProperties();
    void saveProperties();
    std::wstring getString(const std::wstring& key,
                           const std::wstring& defaultValue);
    int getInt(const std::wstring& key, int defaultValue);
    bool getBoolean(const std::wstring& key, bool defaultValue);
    void setBooleanAndSave(const std::wstring& key, bool value);
};
