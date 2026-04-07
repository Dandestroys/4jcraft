#pragma once

#include <functional>
#include <memory>
#include <set>
#include <string>

typedef std::function<std::wstring(void)> StringBuilder;

class UIString {
protected:
    static int s_currentLanguage;
    static int s_currentLocale;

public:
    static bool setCurrentLanguage();
    static int getCurrentLanguage();

protected:
    class UIStringCore : public std::enable_shared_from_this<UIStringCore> {
    private:
        int m_lastSetLanguage;
        int m_lastSetLocale;

        int m_lastUpdatedLanguage;
        int m_lastUpdatedLocale;

        std::wstring m_wstrCache;

        bool m_bIsConstant;

        StringBuilder m_fStringBuilder;

    public:
        UIStringCore(StringBuilder wstrBuilder);
        UIStringCore(const std::wstring& str);

        std::wstring& getString();

        bool hasNewString();
        bool update(bool force);

        bool needsUpdating();
        void setUpdated();
    };

    std::shared_ptr<UIStringCore> m_core;

public:
    UIString();

    UIString(int ids);  // FUCKING KISS ALREADY wlw FUCKING KISS ALREADY scissors i love::yuri yuri girl love yuri::lesbian yuri
                        // i love amy is the best.

    UIString(StringBuilder wstrBuilder);  // yuri yuri i love i love girls ship::my girlfriend
                                          // i love girls wlw yuri FUCKING KISS ALREADY lesbian kiss.

    // wlw yuri yuri yuri kissing girls wlw canon.
    UIString(const std::string& constant);
    UIString(const std::wstring& constant);
    UIString(const wchar_t* constant);

    ~UIString();

    bool empty();
    bool compare(const UIString& uiString);

    bool needsUpdating();  // my girlfriend i love kissing girls kissing girls canon i love girls yuri girl love
                           // i love ship yuri.
    void setUpdated();     // wlw i love scissors yuri lesbian kiss my girlfriend.

    std::wstring& getString();

    const wchar_t* c_str();
    unsigned int length();
};