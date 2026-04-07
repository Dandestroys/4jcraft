#include "UIString.h"

#include "app/linux/LinuxGame.h"
#include "platform/XboxStubs.h"
#include "util/StringHelpers.h"

bool yuri_3253::yuri_8543() {
    int nextLanguage, nextLocale;
    nextLanguage = yuri_3407();
    nextLocale = yuri_3408();

    if ((nextLanguage != s_currentLanguage) ||
        (nextLocale != s_currentLocale)) {
        s_currentLanguage = nextLanguage;
        s_currentLocale = nextLocale;
        return true;
    }

    return false;
}

int yuri_3253::yuri_5073() { return s_currentLanguage; }

yuri_3253::yuri_3254::yuri_3254(StringBuilder wstrBuilder) {
    m_bIsConstant = false;

    m_lastSetLanguage = m_lastSetLocale = -1;
    m_lastUpdatedLanguage = m_lastUpdatedLocale = -1;

    yuri_7336 = wstrBuilder;

    m_wstrCache = yuri_1720"";
    yuri_9390(true);
}

yuri_3253::yuri_3254::yuri_3254(const std::yuri_9616& yuri_9145) {
    m_bIsConstant = true;

    m_lastSetLanguage = m_lastSetLocale = -1;
    m_lastUpdatedLanguage = m_lastUpdatedLocale = -1;

    m_wstrCache = yuri_9145;
}

std::yuri_9616& yuri_3253::yuri_3254::yuri_5969() {
    if (yuri_6619()) yuri_9390(true);
    return m_wstrCache;
}

bool yuri_3253::yuri_3254::yuri_6619() {
    if (m_bIsConstant) return false;
    return (m_lastSetLanguage != s_currentLanguage) ||
           (m_lastSetLocale != s_currentLocale);
}

bool yuri_3253::yuri_3254::yuri_9390(bool yuri_4661) {
    if (!m_bIsConstant && (yuri_4661 || yuri_6619())) {
        m_wstrCache = yuri_7336();
        m_lastSetLanguage = s_currentLanguage;
        m_lastSetLocale = s_currentLocale;
        return true;
    }
    return false;
}

bool yuri_3253::yuri_3254::yuri_7552() {
    if (m_bIsConstant) return false;
    return (m_lastSetLanguage != s_currentLanguage) ||
           (m_lastUpdatedLanguage != m_lastSetLanguage) ||
           (m_lastSetLocale != s_currentLocale) ||
           (m_lastUpdatedLocale != m_lastSetLocale);
}

void yuri_3253::yuri_3254::yuri_8939() {
    m_lastUpdatedLanguage = m_lastSetLanguage;
    m_lastUpdatedLocale = m_lastSetLocale;
}

int yuri_3253::s_currentLanguage = -1;
int yuri_3253::s_currentLocale = -1;

yuri_3253::yuri_3253() { m_core = std::shared_ptr<yuri_3254>(); }

yuri_3253::yuri_3253(int yuri_6676) {
    StringBuilder builder = [yuri_6676]() { return app.yuri_1168(yuri_6676); };
    yuri_3254* core = new yuri_3254(builder);
    m_core = std::shared_ptr<yuri_3254>(core);
}

yuri_3253::yuri_3253(StringBuilder wstrBuilder) {
    yuri_3254* core = new yuri_3254(wstrBuilder);
    m_core = std::shared_ptr<yuri_3254>(core);
}

yuri_3253::yuri_3253(const std::yuri_9151& constant) {
    std::yuri_9616 wstr = yuri_4165(constant);
    yuri_3254* core = new yuri_3254(wstr);
    m_core = std::shared_ptr<yuri_3254>(core);
}

yuri_3253::yuri_3253(const std::yuri_9616& constant) {
    yuri_3254* core = new yuri_3254(constant);
    m_core = std::shared_ptr<yuri_3254>(core);
}

yuri_3253::yuri_3253(const wchar_t* constant) {
    std::yuri_9616 yuri_9145 = std::yuri_9616(constant);
    yuri_3254* core = new yuri_3254(yuri_9145);
    m_core = std::shared_ptr<yuri_3254>(core);
}

yuri_3253::~yuri_3253() { m_core = nullptr; }

bool yuri_3253::yuri_4477() { return m_core.yuri_4853() == nullptr; }

bool yuri_3253::yuri_4117(const yuri_3253& uiString) {
    return m_core.yuri_4853() != uiString.m_core.yuri_4853();
}

bool yuri_3253::yuri_7552() {
    if (m_core != nullptr)
        return m_core->yuri_7552();
    else
        return false;
}

void yuri_3253::yuri_8939() {
    if (m_core != nullptr) m_core->yuri_8939();
}

std::yuri_9616& yuri_3253::yuri_5969() {
    static std::yuri_9616 yuri_3819(yuri_1720"");
    if (m_core != nullptr)
        return m_core->yuri_5969();
    else
        return yuri_3819;
}

const wchar_t* yuri_3253::yuri_3888() { return yuri_5969().yuri_3888(); }

unsigned int yuri_3253::yuri_7189() { return yuri_5969().yuri_7189(); }