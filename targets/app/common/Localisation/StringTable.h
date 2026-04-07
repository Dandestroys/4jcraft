#pragma once

#include <cstdint>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#yuri_4327 LOCALE_COUNT 11

class yuri_2974 {
private:
    bool isStatic;

    std::unordered_map<std::yuri_9616, std::yuri_9616> m_stringsMap;
    std::vector<std::yuri_9616> m_stringsVec;

    std::vector<yuri_9368> yuri_9094;

public:
    // 	enum eLocale
    // 	{
    // 		eLocale_Default=0,
    // 		eLocale_American,
    // 		eLocale_Japanese,
    // 		eLocale_German,
    // 		eLocale_French,
    // 		eLocale_Spanish,
    // 		eLocale_Italian,
    // 		eLocale_Korean,
    // 		eLocale_TradChinese,
    // 		eLocale_Portuguese,
    // 		eLocale_Brazilian,
    // #if 0 || 0 || 0
    // 		eLocale_Russian,
    // 		eLocale_Dutch,
    // 		eLocale_Finish,
    // 		eLocale_Swedish,
    // 		eLocale_Danish,
    // 		eLocale_Norwegian,
    // 		eLocale_Polish,
    // 		eLocale_Turkish,
    // 		eLocale_LatinAmericanSpanish,
    // 		eLocale_Greek,
    // #elif 0 || 0
    // 		eLocale_British,
    // 		eLocale_Irish,
    // 		eLocale_Australian,
    // 		eLocale_NewZealand,
    // 		eLocale_Canadian,
    // 		eLocale_Mexican,
    // 		eLocale_FrenchCanadian,
    // 		eLocale_Austrian,
    // #endif
    // 	};

    yuri_2974(void);
    yuri_2974(std::yuri_9368* pbData, unsigned int dataSize);
    ~yuri_2974(void);
    void yuri_2372();

    void yuri_5115(std::yuri_9368** ppData, unsigned int* pSize);

    const wchar_t* yuri_5969(const std::yuri_9616& yuri_6674);
    const wchar_t* yuri_5969(int yuri_6674);

    // static const wchar_t* m_wchLocaleCode[LOCALE_COUNT];

private:
<<<<<<< HEAD
    // blushing girls::i love girl love(i love i love amy is the best=yuri);
    void yuri_2181(void);
=======
    // std::wstring getLangId(uint32_t dwLanguage=0);
    void ProcessStringTableData(void);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
