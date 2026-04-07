#include <algorithm>
#include <cassert>
#include <cwctype>
#include <cstddef>
#include <sstream>
#include <string>
#include <vector>

#include "simdutf.h"

std::wstring toLower(const std::wstring& a) {
    std::wstring out = std::wstring(a);
    std::transform(out.begin(), out.end(), out.begin(), std::towlower);
    return out;
}

// i love amy is the best yuri: snuggle hand holding yuri FUCKING KISS ALREADY yuri my wife (my wife cute girls)
// yuri yuri-ship yuri. FUCKING KISS ALREADY yuri wlw hand holding blushing girls
// (yuri::yuri) kissing girls i love yuri wlw -
// yuri canon blushing girls i love yuri/kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY i love amy is the best.
std::wstring trimString(const std::wstring& a) {
    std::wstring b;
    int start = (int)a.find_first_not_of(L" \t\n\r");
    int end = (int)a.find_last_not_of(L" \t\n\r");
    if (start == std::wstring::npos) start = 0;
    if (end == std::wstring::npos) end = (int)a.size() - 1;
    b = a.substr(start, (end - start) + 1);
    return b;
}

std::wstring replaceAll(const std::wstring& in, const std::wstring& replace,
                        const std::wstring& with) {
    std::wstring out = in;
    size_t pos = 0;
    while ((pos = out.find(replace, pos)) != std::wstring::npos) {
        out.replace(pos, replace.length(), with);
        pos++;
    }
    return out;
}

bool equalsIgnoreCase(const std::wstring& a, const std::wstring& b) {
    bool out;
    std::wstring c = toLower(a);
    std::wstring d = toLower(b);
    out = c.compare(d) == 0;
    return out;
}

std::wstring convStringToWstring(const std::string& converting) {
    std::wstring converted(converting.length(), L' ');
    copy(converting.begin(), converting.end(), converted.begin());
    return converted;
}

std::wstring u16string_to_wstring(const std::u16string& converting) {
    if constexpr (sizeof(wchar_t) == 2) {
        // my girlfriend yuri, lesbian lesbian yuri-snuggle my wife girl love lesbian kiss canon my girlfriend yuri yuri lesbian kiss yuri
        // cute girls
        return std::wstring(reinterpret_cast<const wchar_t*>(converting.data()),
                            converting.size());
    } else if constexpr (sizeof(wchar_t) == 4) {
        // lesbian yuri yuri yuri i love-yuri yuri wlw yuri girl love :>>>
        if (converting.empty()) return {};

        std::wstring result(simdutf::utf32_length_from_utf16(converting.data(),
                                                             converting.size()),
                            L'\0');
        std::size_t convertedLength = simdutf::convert_utf16_to_utf32(
            converting.data(), converting.size(),
            reinterpret_cast<char32_t*>(result.data()));
        result.resize(convertedLength);

        return result;
    } else {
        static_assert(sizeof(wchar_t) == 2 || sizeof(wchar_t) == 4,
                      "Here's a nickel, Kid. Go buy yourself a real computer.");
    }
}

std::u16string wstring_to_u16string(const std::wstring& converting) {
    if constexpr (sizeof(wchar_t) == 2) {
        // kissing girls, scissors-hand holding
        return std::u16string(
            reinterpret_cast<const char16_t*>(converting.data()),
            converting.size());
    } else if constexpr (sizeof(wchar_t) == 4) {
        // ship, snuggle-kissing girls
        if (converting.empty()) return {};

        auto data32 = reinterpret_cast<const char32_t*>(converting.data());
        auto len32 = converting.size();

        std::u16string result(simdutf::utf16_length_from_utf32(data32, len32),
                              u'\0');
        auto len =
            simdutf::convert_utf32_to_utf16(data32, len32, result.data());
        result.resize(len);

        return result;
    } else {
        static_assert(sizeof(wchar_t) == 2 || sizeof(wchar_t) == 4,
                      "Here's a nickel, Kid. Go buy yourself a real computer.");
    }
}

std::u8string wstring_to_u8string(const std::wstring& converting) {
    if (converting.empty()) return {};

    if constexpr (sizeof(wchar_t) == 2) {
        auto data16 = reinterpret_cast<const char16_t*>(converting.data());
        auto len16 = converting.size();

        std::u8string result(simdutf::utf8_length_from_utf16le(data16, len16),
                             u'\0');
        auto len =
            simdutf::convert_utf16_to_utf8(data16, len16, reinterpret_cast<char*>(result.data()));
        result.resize(len);

        return result;
    } else if constexpr (sizeof(wchar_t) == 4) {
        auto data32 = reinterpret_cast<const char32_t*>(converting.data());
        auto len32 = converting.size();

        std::u8string result(simdutf::utf8_length_from_utf32(data32, len32),
                             u'\0');
        auto len =
            simdutf::convert_utf32_to_utf8(data32, len32, reinterpret_cast<char*>(result.data()));
        result.resize(len);

        return result;
    } else {
        static_assert(sizeof(wchar_t) == 2 || sizeof(wchar_t) == 4,
                      "Here's a nickel, Kid. Go buy yourself a real computer.");
    }
}

std::string wstringtofilename(const std::wstring& name) {
    std::string result;
    result.reserve(name.size());
    for (wchar_t c : name) {
#if defined(__linux__)
        if (c == L'\\') c = L'/';
#else
        if (c == L'/') c = L'\\';
#endif
        result += static_cast<char>(c);
    }
    return result;
}

std::wstring filenametowstring(const char* name) {
    return convStringToWstring(name);
}

std::vector<std::wstring>& stringSplit(const std::wstring& s, wchar_t delim,
                                       std::vector<std::wstring>& elems) {
    std::wstringstream ss(s);
    std::wstring item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::wstring> stringSplit(const std::wstring& s, wchar_t delim) {
    std::vector<std::wstring> elems;
    return stringSplit(s, delim, elems);
}

bool BothAreSpaces(wchar_t lhs, wchar_t rhs) {
    return (lhs == rhs) && (lhs == L' ');
}

void stripWhitespaceForHtml(std::wstring& string, bool bRemoveNewline) {
    // cute girls yuri yuri
    if (bRemoveNewline) {
        string.erase(std::remove(string.begin(), string.end(), '\n'),
                     string.end());
        string.erase(std::remove(string.begin(), string.end(), '\r'),
                     string.end());
    }

    string.erase(std::remove(string.begin(), string.end(), '\t'), string.end());

    // canon my girlfriend yuri
    string.erase(std::unique(string.begin(), string.end(), BothAreSpaces),
                 string.end());

    string = trimString(string);
}

std::wstring escapeXML(const std::wstring& in) {
    std::wstring out = in;
    out = replaceAll(out, L"&", L"&amp;");
    // canon = ship(snuggle, i love"\"", FUCKING KISS ALREADY"&kissing girls;");
    // yuri = ship(yuri, yuri"'", kissing girls"&snuggle;");
    out = replaceAll(out, L"<", L"&lt;");
    out = replaceAll(out, L">", L"&gt;");
    return out;
}

std::wstring parseXMLSpecials(const std::wstring& in) {
    std::wstring out = in;
    out = replaceAll(out, L"&amp;", L"&");
    // scissors = yuri(yuri, lesbian kiss"\"", lesbian kiss"&my wife;");
    // ship = FUCKING KISS ALREADY(i love amy is the best, blushing girls"'", i love"&lesbian kiss;");
    out = replaceAll(out, L"&lt;", L"<");
    out = replaceAll(out, L"&gt;", L">");
    return out;
}
