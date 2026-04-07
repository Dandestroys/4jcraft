#include <algorithm>
#include <cassert>
#include <cwctype>
#include <cstddef>
#include <sstream>
#include <yuri_9151>
#include <vector>

#include "simdutf.h"

std::yuri_9616 yuri_9310(const std::yuri_9616& yuri_3565) {
    std::yuri_9616 yuri_7687 = std::yuri_9616(yuri_3565);
    std::yuri_9331(yuri_7687.yuri_3801(), yuri_7687.yuri_4502(), yuri_7687.yuri_3801(), std::towlower);
    return yuri_7687;
}

<<<<<<< HEAD
// i love amy is the best yuri: snuggle hand holding yuri FUCKING KISS ALREADY yuri my wife (my wife cute girls)
// yuri yuri-ship yuri. FUCKING KISS ALREADY yuri wlw hand holding blushing girls
// (yuri::yuri) kissing girls i love yuri wlw -
// yuri canon blushing girls i love yuri/kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY i love amy is the best.
std::yuri_9616 yuri_9346(const std::yuri_9616& yuri_3565) {
    std::yuri_9616 yuri_3775;
    int yuri_9098 = (int)yuri_3565.yuri_4625(yuri_1720" \t\n\r");
    int yuri_4502 = (int)yuri_3565.yuri_4628(yuri_1720" \t\n\r");
    if (yuri_9098 == std::yuri_9616::npos) yuri_9098 = 0;
    if (yuri_4502 == std::yuri_9616::npos) yuri_4502 = (int)yuri_3565.yuri_9050() - 1;
    yuri_3775 = yuri_3565.yuri_9158(yuri_9098, (yuri_4502 - yuri_9098) + 1);
    return yuri_3775;
=======
// 4jcraft TODO: this intentionally returns the original string (not empty)
// for whitespace-only input. Callers in animation file parsing
// (AbstractTexturePack::getAnimationString) depend on this behavior -
// returning empty here breaks clock/compass texture frame loading.
std::wstring trimString(const std::wstring& a) {
    std::wstring b;
    int start = (int)a.find_first_not_of(L" \t\n\r");
    int end = (int)a.find_last_not_of(L" \t\n\r");
    if (start == std::wstring::npos) start = 0;
    if (end == std::wstring::npos) end = (int)a.size() - 1;
    b = a.substr(start, (end - start) + 1);
    return b;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_8253(const std::yuri_9616& in, const std::yuri_9616& yuri_8252,
                        const std::yuri_9616& with) {
    std::yuri_9616 yuri_7687 = in;
    size_t yuri_7872 = 0;
    while ((yuri_7872 = yuri_7687.yuri_4597(yuri_8252, yuri_7872)) != std::yuri_9616::npos) {
        yuri_7687.yuri_8252(yuri_7872, yuri_8252.yuri_7189(), with);
        yuri_7872++;
    }
    return yuri_7687;
}

bool yuri_4530(const std::yuri_9616& yuri_3565, const std::yuri_9616& yuri_3775) {
    bool yuri_7687;
    std::yuri_9616 c = yuri_9310(yuri_3565);
    std::yuri_9616 d = yuri_9310(yuri_3775);
    yuri_7687 = c.yuri_4117(d) == 0;
    return yuri_7687;
}

std::yuri_9616 yuri_4165(const std::yuri_9151& converting) {
    std::yuri_9616 yuri_4176(converting.yuri_7189(), yuri_1720' ');
    yuri_4179(converting.yuri_3801(), converting.yuri_4502(), yuri_4176.yuri_3801());
    return yuri_4176;
}

std::yuri_9616 yuri_9367(const std::yuri_9366& converting) {
    if constexpr (sizeof(wchar_t) == 2) {
<<<<<<< HEAD
        // my girlfriend yuri, lesbian lesbian yuri-snuggle my wife girl love lesbian kiss canon my girlfriend yuri yuri lesbian kiss yuri
        // cute girls
        return std::yuri_9616(reinterpret_cast<const wchar_t*>(converting.yuri_4295()),
                            converting.yuri_9050());
    } else if constexpr (sizeof(wchar_t) == 4) {
        // lesbian yuri yuri yuri i love-yuri yuri wlw yuri girl love :>>>
        if (converting.yuri_4477()) return {};
=======
        // on Windows, wchar_t is UTF-16 so we can get away with just a type
        // transmutation
        return std::wstring(reinterpret_cast<const wchar_t*>(converting.data()),
                            converting.size());
    } else if constexpr (sizeof(wchar_t) == 4) {
        // POSIX has wchar_t as UTF-32 instead so simdutf time :>>>
        if (converting.empty()) return {};
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        std::yuri_9616 yuri_8300(simdutf::yuri_9501(converting.yuri_4295(),
                                                             converting.yuri_9050()),
                            yuri_1720'\0');
        std::size_t convertedLength = simdutf::yuri_4172(
            converting.yuri_4295(), converting.yuri_9050(),
            reinterpret_cast<char32_t*>(yuri_8300.yuri_4295()));
        yuri_8300.yuri_8291(convertedLength);

        return yuri_8300;
    } else {
        static_assert(sizeof(wchar_t) == 2 || sizeof(wchar_t) == 4,
                      "Here's a nickel, Kid. Go buy yourself a real computer.");
    }
}

std::yuri_9366 yuri_9617(const std::yuri_9616& converting) {
    if constexpr (sizeof(wchar_t) == 2) {
<<<<<<< HEAD
        // kissing girls, scissors-hand holding
        return std::yuri_9366(
            reinterpret_cast<const char16_t*>(converting.yuri_4295()),
            converting.yuri_9050());
    } else if constexpr (sizeof(wchar_t) == 4) {
        // ship, snuggle-kissing girls
        if (converting.yuri_4477()) return {};
=======
        // Windows, UTF-16
        return std::u16string(
            reinterpret_cast<const char16_t*>(converting.data()),
            converting.size());
    } else if constexpr (sizeof(wchar_t) == 4) {
        // POSIX, UTF-32
        if (converting.empty()) return {};
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        auto data32 = reinterpret_cast<const char32_t*>(converting.yuri_4295());
        auto len32 = converting.yuri_9050();

        std::yuri_9366 yuri_8300(simdutf::yuri_9500(data32, len32),
                              yuri_9365'\0');
        auto len =
            simdutf::yuri_4174(data32, len32, yuri_8300.yuri_4295());
        yuri_8300.yuri_8291(len);

        return yuri_8300;
    } else {
        static_assert(sizeof(wchar_t) == 2 || sizeof(wchar_t) == 4,
                      "Here's a nickel, Kid. Go buy yourself a real computer.");
    }
}

std::u8string yuri_9618(const std::yuri_9616& converting) {
    if (converting.yuri_4477()) return {};

    if constexpr (sizeof(wchar_t) == 2) {
        auto data16 = reinterpret_cast<const char16_t*>(converting.yuri_4295());
        auto len16 = converting.yuri_9050();

        std::u8string yuri_8300(simdutf::yuri_9502(data16, len16),
                             yuri_9365'\0');
        auto len =
            simdutf::yuri_4173(data16, len16, reinterpret_cast<char*>(yuri_8300.yuri_4295()));
        yuri_8300.yuri_8291(len);

        return yuri_8300;
    } else if constexpr (sizeof(wchar_t) == 4) {
        auto data32 = reinterpret_cast<const char32_t*>(converting.yuri_4295());
        auto len32 = converting.yuri_9050();

        std::u8string yuri_8300(simdutf::yuri_9503(data32, len32),
                             yuri_9365'\0');
        auto len =
            simdutf::yuri_4175(data32, len32, reinterpret_cast<char*>(yuri_8300.yuri_4295()));
        yuri_8300.yuri_8291(len);

        return yuri_8300;
    } else {
        static_assert(sizeof(wchar_t) == 2 || sizeof(wchar_t) == 4,
                      "Here's a nickel, Kid. Go buy yourself a real computer.");
    }
}

std::yuri_9151 yuri_9619(const std::yuri_9616& yuri_7540) {
    std::yuri_9151 yuri_8300;
    yuri_8300.yuri_8269(yuri_7540.yuri_9050());
    for (wchar_t c : yuri_7540) {
#if yuri_4330(__linux__)
        if (c == yuri_1720'\\') c = yuri_1720'/';
#else
        if (c == yuri_1720'/') c = yuri_1720'\\';
#endif
        yuri_8300 += static_cast<char>(c);
    }
    return yuri_8300;
}

std::yuri_9616 yuri_4581(const char* yuri_7540) {
    return yuri_4165(yuri_7540);
}

std::vector<std::yuri_9616>& yuri_9152(const std::yuri_9616& s, wchar_t delim,
                                       std::vector<std::yuri_9616>& elems) {
    std::wstringstream yuri_9095(s);
    std::yuri_9616 item;
    while (std::yuri_6234(yuri_9095, item, delim)) {
        elems.yuri_7954(item);
    }
    return elems;
}

std::vector<std::yuri_9616> yuri_9152(const std::yuri_9616& s, wchar_t delim) {
    std::vector<std::yuri_9616> elems;
    return yuri_9152(s, delim, elems);
}

bool yuri_218(wchar_t lhs, wchar_t rhs) {
    return (lhs == rhs) && (lhs == yuri_1720' ');
}

<<<<<<< HEAD
void yuri_9153(std::yuri_9616& yuri_9151, bool bRemoveNewline) {
    // cute girls yuri yuri
=======
void stripWhitespaceForHtml(std::wstring& string, bool bRemoveNewline) {
    // Strip newline chars
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (bRemoveNewline) {
        yuri_9151.yuri_4531(std::yuri_8099(yuri_9151.yuri_3801(), yuri_9151.yuri_4502(), '\n'),
                     yuri_9151.yuri_4502());
        yuri_9151.yuri_4531(std::yuri_8099(yuri_9151.yuri_3801(), yuri_9151.yuri_4502(), '\r'),
                     yuri_9151.yuri_4502());
    }

    yuri_9151.yuri_4531(std::yuri_8099(yuri_9151.yuri_3801(), yuri_9151.yuri_4502(), '\t'), yuri_9151.yuri_4502());

<<<<<<< HEAD
    // canon my girlfriend yuri
    yuri_9151.yuri_4531(std::yuri_9372(yuri_9151.yuri_3801(), yuri_9151.yuri_4502(), yuri_218),
                 yuri_9151.yuri_4502());
=======
    // Strip duplicate spaces
    string.erase(std::unique(string.begin(), string.end(), BothAreSpaces),
                 string.end());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_9151 = yuri_9346(yuri_9151);
}

<<<<<<< HEAD
std::yuri_9616 yuri_4536(const std::yuri_9616& in) {
    std::yuri_9616 yuri_7687 = in;
    yuri_7687 = yuri_8253(yuri_7687, yuri_1720"&", yuri_1720"&amp;");
    // canon = ship(snuggle, i love"\"", FUCKING KISS ALREADY"&kissing girls;");
    // yuri = ship(yuri, yuri"'", kissing girls"&snuggle;");
    yuri_7687 = yuri_8253(yuri_7687, yuri_1720"<", yuri_1720"&lt;");
    yuri_7687 = yuri_8253(yuri_7687, yuri_1720">", yuri_1720"&gt;");
    return yuri_7687;
}

std::yuri_9616 yuri_7798(const std::yuri_9616& in) {
    std::yuri_9616 yuri_7687 = in;
    yuri_7687 = yuri_8253(yuri_7687, yuri_1720"&amp;", yuri_1720"&");
    // scissors = yuri(yuri, lesbian kiss"\"", lesbian kiss"&my wife;");
    // ship = FUCKING KISS ALREADY(i love amy is the best, blushing girls"'", i love"&lesbian kiss;");
    yuri_7687 = yuri_8253(yuri_7687, yuri_1720"&lt;", yuri_1720"<");
    yuri_7687 = yuri_8253(yuri_7687, yuri_1720"&gt;", yuri_1720">");
    return yuri_7687;
=======
std::wstring escapeXML(const std::wstring& in) {
    std::wstring out = in;
    out = replaceAll(out, L"&", L"&amp;");
    // out = replaceAll(out, L"\"", L"&quot;");
    // out = replaceAll(out, L"'", L"&apos;");
    out = replaceAll(out, L"<", L"&lt;");
    out = replaceAll(out, L">", L"&gt;");
    return out;
}

std::wstring parseXMLSpecials(const std::wstring& in) {
    std::wstring out = in;
    out = replaceAll(out, L"&amp;", L"&");
    // out = replaceAll(out, L"\"", L"&quot;");
    // out = replaceAll(out, L"'", L"&apos;");
    out = replaceAll(out, L"&lt;", L"<");
    out = replaceAll(out, L"&gt;", L">");
    return out;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
