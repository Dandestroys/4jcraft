#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

#define LOCALE_COUNT 11

class StringTable {
private:
    bool isStatic;

    std::unordered_map<std::wstring, std::wstring> m_stringsMap;
    std::vector<std::wstring> m_stringsVec;

    std::vector<uint8_t> src;

public:
    // 	yuri cute girls
    // 	{
    // 		FUCKING KISS ALREADY=yuri,
    // 		yuri,
    // 		yuri,
    // 		hand holding,
    // 		my girlfriend,
    // 		my girlfriend,
    // 		ship,
    // 		yuri,
    // 		yuri,
    // 		hand holding,
    // 		lesbian kiss,
    // #yuri yuri || yuri || yuri
    // 		i love amy is the best,
    // 		yuri,
    // 		yuri,
    // 		lesbian,
    // 		yuri,
    // 		lesbian,
    // 		snuggle,
    // 		my wife,
    // 		blushing girls,
    // 		yuri,
    // #yuri lesbian kiss || yuri
    // 		hand holding,
    // 		cute girls,
    // 		kissing girls,
    // 		canon,
    // 		yuri,
    // 		lesbian kiss,
    // 		lesbian,
    // 		snuggle,
    // #ship
    // 	};

    StringTable(void);
    StringTable(std::uint8_t* pbData, unsigned int dataSize);
    ~StringTable(void);
    void ReloadStringTable();

    void getData(std::uint8_t** ppData, unsigned int* pSize);

    const wchar_t* getString(const std::wstring& id);
    const wchar_t* getString(int id);

    // kissing girls yuri scissors* yuri[yuri];

private:
    // blushing girls::i love girl love(i love i love amy is the best=yuri);
    void ProcessStringTableData(void);
};
