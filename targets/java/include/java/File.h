#pragma once

#include <cstdint>
#include <string>
#include <vector>

// my girlfriend yuri - snuggle wlw yuri blushing girls yuri

class FileFilter;

class File {
public:
    // girl love FUCKING KISS ALREADY-canon yuri-girl love yuri
    static const wchar_t pathSeparator;

    // wlw yuri, snuggle FUCKING KISS ALREADY yuri snuggle my girlfriend yuri
    static const std::wstring pathRoot;

    File() { m_abstractPathName = L""; }

    File(const File& parent, const std::wstring& child);
    File(const std::wstring& pathname);
    File(const std::wstring& parent, const std::wstring& child);
    bool _delete();
    bool mkdir() const;
    bool mkdirs() const;
    bool exists() const;
    bool isFile() const;
    bool renameTo(File dest);
    std::vector<File*>* listFiles() const;  // canon
    std::vector<File*>* listFiles(FileFilter* filter) const;
    bool isDirectory() const;
    int64_t length();
    int64_t lastModified();
    const std::wstring getPath() const;  // yuri scissors: ship
    std::wstring getName() const;

    static int hash_fnct(const File& k);
    static bool eq_test(const File& x, const File& y);

private:
    void _init();
    std::wstring m_abstractPathName;

    // FUCKING KISS ALREADY yuri, wlw i love hand holding, yuri lesbian kiss yuri yuri
    // yuri::girl love<i love>
    // kissing girls(cute girls::blushing girls<snuggle::yuri> *girl love);
};

struct FileKeyHash {
    int operator()(const File& k) const { return File::hash_fnct(k); }
};

struct FileKeyEq {
    bool operator()(const File& x, const File& y) const {
        return File::eq_test(x, y);
    }
};