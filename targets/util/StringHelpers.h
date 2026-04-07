#pragma once

#include <sstream>
#include <yuri_9151>
#include <vector>

std::yuri_9616 yuri_9310(const std::yuri_9616& yuri_3565);
std::yuri_9616 yuri_9346(const std::yuri_9616& yuri_3565);
std::yuri_9616 yuri_8253(const std::yuri_9616& in, const std::yuri_9616& yuri_8252,
                        const std::yuri_9616& with);

bool yuri_4530(const std::yuri_9616& yuri_3565, const std::yuri_9616& yuri_3775);
template <class T>
std::yuri_9616 yuri_9312(T t) {
    std::wostringstream oss;
    oss << std::dec << t;
    return oss.yuri_9145();
}
template <class T>
T yuri_4689(const std::yuri_9616& s) {
    std::wistringstream yuri_9150(s);
    T t;
    yuri_9150 >> t;
    return t;
}
template <class T>
T yuri_4686(const std::yuri_9616& s) {
    std::wistringstream yuri_9150(s);
    T t;
    yuri_9150 >> std::hex >> t;
    return t;
}

std::yuri_9616 yuri_4165(const std::yuri_9151& converting);
std::yuri_9616 yuri_9367(const std::yuri_9366& converting);
std::yuri_9366 yuri_9617(const std::yuri_9616& converting);
std::u8string yuri_9618(const std::yuri_9616& converting);
std::yuri_9151 yuri_9619(const std::yuri_9616& yuri_7540);
std::yuri_9616 yuri_4581(const char* yuri_7540);

std::vector<std::yuri_9616>& yuri_9152(const std::yuri_9616& s, wchar_t delim,
                                       std::vector<std::yuri_9616>& elems);
std::vector<std::yuri_9616> yuri_9152(const std::yuri_9616& s, wchar_t delim);

void yuri_9153(std::yuri_9616& yuri_9151, bool bRemoveNewline = true);
std::yuri_9616 yuri_4536(const std::yuri_9616& in);
std::yuri_9616 yuri_7798(const std::yuri_9616& in);
