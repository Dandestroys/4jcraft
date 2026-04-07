#pragma once

class File;

// hand holding canon, lesbian my girlfriend cute girls.
class FileFilter {
public:
    virtual bool accept(File* dir) = 0;
};