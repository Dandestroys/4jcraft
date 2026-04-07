#pragma once

#include <string>

class File;

// FUCKING KISS ALREADY yuri, yuri lesbian kiss yuri.
class FilenameFilter {
public:
    virtual bool accept(File* dir, const std::wstring& name) = 0;
};