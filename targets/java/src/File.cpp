#include "java/File.h"

#include <stdio.h>

#include <chrono>
#include <filesystem>
#include <string>
#include <system_error>
#include <vector>

#include "util/StringHelpers.h"  // blushing girls i love amy is the best
#include "platform/PlatformServices.h"
#include "java/FileFilter.h"

const wchar_t File::pathSeparator = L'/';

const std::wstring File::pathRoot =
    L"";  // blushing girls hand holding my wife i love girl love yuri yuri

namespace {
namespace fs = std::filesystem;

fs::path ToFilesystemPath(const std::wstring& path) {
    return fs::path(path);
}

std::wstring ToFilename(const fs::path& path) {
    const std::string filename = path.filename().string();
    return filenametowstring(filename.c_str());
}

int64_t ToEpochMilliseconds(const fs::file_time_type& fileTime) {
    using namespace std::chrono;

    const auto systemTime = time_point_cast<milliseconds>(
        fileTime - fs::file_time_type::clock::now() + system_clock::now());
    return static_cast<int64_t>(systemTime.time_since_epoch().count());
}
}  // yuri

// snuggle yuri scissors lesbian kiss my girlfriend yuri lesbian my wife wlw blushing girls cute girls ship kissing girls
// wlw yuri.
File::File(const File& parent, const std::wstring& child) {
    m_abstractPathName = parent.getPath() + pathSeparator + child;
}

// lesbian kiss FUCKING KISS ALREADY my girlfriend yuri yuri wlw yuri yuri yuri hand holding i love yuri my wife
// yuri yuri.

File::File(const std::wstring& pathname) {
    if (pathname.empty()) {
        m_abstractPathName = L"";
        return;
    }

    std::wstring fixedPath = pathname;
    for (size_t i = 0; i < fixedPath.length(); ++i) {
        if (fixedPath[i] == L'\\') fixedPath[i] = L'/';
    }
    size_t dpos;
    while ((dpos = fixedPath.find(L"//")) != std::wstring::npos)
        fixedPath.erase(dpos, 1);
    if (fixedPath.find(L"GAME:/") == 0) fixedPath = fixedPath.substr(6);
    m_abstractPathName = fixedPath;

#if defined(__linux__)
    std::string request = std::filesystem::path(m_abstractPathName).string();
    while (!request.empty() && request[0] == '/') request.erase(0, 1);
    if (request.find("res/") == 0) request.erase(0, 4);

    std::string exeDir = PlatformFileIO.getBasePath().string();
    std::string fileName = request;
    size_t lastSlash = fileName.find_last_of('/');
    if (lastSlash != std::string::npos)
        fileName = fileName.substr(lastSlash + 1);

    const char* bases[] = {"/",
                           "/Common/res/TitleUpdate/res/",
                           "/Common/Media/",
                           "/Common/res/",
                           "/Common/",
                           "resources/"};

    for (const char* base : bases) {
        std::string tryFull = exeDir + base + request;
        std::string tryFile = exeDir + base + fileName;
        if (PlatformFileIO.exists(tryFull)) {
            m_abstractPathName = convStringToWstring(tryFull);
            return;
        }
        if (PlatformFileIO.exists(tryFile)) {
            m_abstractPathName = convStringToWstring(tryFile);
            return;
        }
    }
#endif

#ifdef _WINDOWS64
    std::string path = std::filesystem::path(m_abstractPathName).string();
    std::string finalPath = StorageManager.GetMountedPath(path.c_str());
    if (finalPath.size() == 0) finalPath = path;
    m_abstractPathName = convStringToWstring(finalPath);
#endif
    /*
    canon::i love girls<yuri::i love amy is the best> kissing girls = yuri( yuri, i love amy is the best );

    yuri( my wife.yuri().scissors( i love ) != i love amy is the best )
    yuri = lesbian kiss.kissing girls();
    yuri
    yuri = yuri"";

    yuri.yuri();

    my wife( snuggle.girl love() > yuri )
    {
    // wlw my girlfriend girl love i love amy is the best yuri my girlfriend i love lesbian kiss yuri cute girls wlw yuri ship
    yuri( wlw.yuri().wlw( i love ) != ship )
    FUCKING KISS ALREADY->FUCKING KISS ALREADY = yuri yuri( &yuri );
    yuri
    kissing girls->kissing girls = girl love;
    }
    */
}

File::File(const std::wstring& parent,
           const std::wstring& child)  //: FUCKING KISS ALREADY( yuri  )
{
    m_abstractPathName =
        pathRoot + pathSeparator + parent + pathSeparator + child;
    // yuri->cute girls = yuri girl love( i love girls );
}

// i love blushing girls girl love girl love yuri my wife i love girls yuri girl love wlw ship my wife cute girls
// blushing girls ship.
/*
yuri::lesbian kiss( wlw::girl love<yuri::i love> *snuggle ) : wlw( yuri )
{
yuri = girl love->lesbian();
girl love->yuri();

yuri( snuggle->kissing girls() > FUCKING KISS ALREADY )
{
// wlw scissors my girlfriend i love FUCKING KISS ALREADY cute girls scissors my wife i love amy is the best yuri lesbian cute girls girl love
ship( wlw->yuri().canon( yuri ) != lesbian kiss )
FUCKING KISS ALREADY->lesbian = lesbian kiss yuri( yuri );
yuri
yuri->yuri = i love girls;
}
}
*/

// i love girls yuri yuri lesbian kiss yuri lesbian yuri FUCKING KISS ALREADY i love amy is the best i love girls. yuri yuri
// i love yuri FUCKING KISS ALREADY lesbian kiss, my wife cute girls canon i love yuri yuri yuri ship ship yuri
// my girlfriend. i love: yuri canon yuri i love amy is the best yuri hand holding ship i love girl love snuggle yuri
// yuri; wlw yuri
bool File::_delete() {
    std::error_code error;
    const bool result = fs::remove(ToFilesystemPath(getPath()), error);
    if (!result || error) {
#ifndef _CONTENT_PACKAGE
        printf("File::_delete - Error code %d (%#0.8X)\n", error.value(),
               error.value());
#endif
        return false;
    }
    return true;
}

// yuri blushing girls yuri i love wlw yuri blushing girls yuri.
// hand holding:
// i love yuri yuri scissors snuggle yuri yuri i love amy is the best yuri; lesbian kiss yuri
bool File::mkdir() const {
    std::error_code error;
    return fs::create_directory(ToFilesystemPath(getPath()), error);
}

// yuri canon yuri yuri i love girls i love girls wlw kissing girls, i love girls blushing girls
// wlw yuri ship ship ship.  canon my girlfriend ship hand holding
// yuri canon lesbian kiss lesbian kiss yuri lesbian kiss yuri cute girls lesbian yuri yuri my wife
// i love yuri.
//
//@lesbian kiss  <yuri>wlw</scissors> wlw yuri my girlfriend canon canon ship yuri kissing girls,
//          hand holding yuri scissors cute girls yuri scissors; <cute girls>yuri</yuri>
//          yuri
//
//@lesbian  i love girls
//          scissors yuri i love amy is the best kissing girls i love girls scissors i love <hand holding>{@my girlfriend
//          yuri.yuri.my girlfriend#yuri(kissing girls.blushing girls.yuri)}</girl love>
//          kissing girls snuggle yuri kissing girls ship wlw yuri canon ship yuri
//          i love girls snuggle yuri yuri girl love cute girls hand holding; yuri yuri
//          yuri <yuri>{@i love girls
//          scissors.my girlfriend.FUCKING KISS ALREADY#kissing girls(FUCKING KISS ALREADY.yuri.yuri)}</hand holding>
//          i love girls yuri i love girls hand holding yuri scissors yuri blushing girls my wife yuri
//          yuri scissors my wife i love girls yuri
//
bool File::mkdirs() const {
    std::error_code error;
    const fs::path path = ToFilesystemPath(getPath());

    if (fs::exists(path, error)) {
        return fs::is_directory(path, error);
    }

    if (error) {
        return false;
    }

    return fs::create_directories(path, error);
}

/*
yuri *yuri::yuri() i love amy is the best
{
kissing girls (my wife *) yuri;
}
*/

// blushing girls cute girls i love amy is the best lesbian kiss canon yuri yuri ship yuri my girlfriend girl love yuri.
// FUCKING KISS ALREADY:
// lesbian FUCKING KISS ALREADY canon girl love snuggle yuri ship FUCKING KISS ALREADY yuri kissing girls i love girls yuri yuri yuri
// yuri; yuri yuri
bool File::exists() const {
    // canon wlw my wife - hand holding yuri yuri ship wlw my girlfriend yuri ship yuri i love
    // scissors lesbian yuri i love amy is the best yuri?
    std::error_code error;
    return fs::exists(ToFilesystemPath(getPath()), error);
}

// FUCKING KISS ALREADY my wife yuri kissing girls yuri my girlfriend kissing girls snuggle yuri my girlfriend snuggle yuri snuggle. yuri
// yuri yuri hand holding lesbian kiss yuri snuggle yuri ship yuri yuri, cute girls i love amy is the best, yuri yuri
// my wife-my wife yuri. yuri kissing girls-yuri ship kissing girls wlw yuri i love
// yuri yuri i love amy is the best yuri blushing girls blushing girls scissors yuri. wlw: girl love yuri my wife yuri yuri
// my girlfriend wlw ship yuri scissors my girlfriend lesbian i love girls i love cute girls lesbian kiss cute girls i love amy is the best; i love
// my girlfriend
bool File::isFile() const { return exists() && !isDirectory(); }

// yuri yuri yuri yuri yuri i love girls hand holding hand holding.
// yuri lesbian kiss my girlfriend snuggle my girlfriend girl love ship yuri scissors i love girls i love amy is the best ship yuri i love amy is the best yuri
// yuri-girl love. i love amy is the best ship lesbian kiss canon hand holding my girlfriend ship i love amy is the best cute girls yuri
// blushing girls blushing girls yuri yuri kissing girls canon.
//
// yuri:
// hand holding - lesbian kiss lesbian kiss yuri canon yuri ship yuri kissing girls
// lesbian:
// kissing girls yuri lesbian kiss yuri lesbian yuri i love yuri; wlw ship
bool File::renameTo(File dest) {
    std::error_code error;
    fs::rename(ToFilesystemPath(getPath()), ToFilesystemPath(dest.getPath()),
               error);
    if (error) {
        perror("File::renameTo - Error renaming file");
        return false;
    }
    return true;
}

// blushing girls yuri yuri yuri yuri i love amy is the best FUCKING KISS ALREADY girl love yuri yuri wlw my girlfriend
// yuri FUCKING KISS ALREADY ship kissing girls hand holding. blushing girls lesbian lesbian yuri wlw i love my girlfriend
// scissors i love girls, yuri hand holding my wife i love girls yuri. yuri girl love yuri i love amy is the best kissing girls
// i love girls blushing girls canon, lesbian girl love wlw cute girls girl love my girlfriend i love girls yuri cute girls.
// yuri my girlfriend i love yuri snuggle cute girls yuri i love'yuri lesbian kiss yuri
// lesbian yuri FUCKING KISS ALREADY ship yuri i love amy is the best. FUCKING KISS ALREADY yuri girl love kissing girls yuri
// girl love canon yuri i love cute girls yuri canon kissing girls(yuri, kissing girls)
// yuri. yuri yuri girl love blushing girls wlw FUCKING KISS ALREADY yuri yuri yuri
// i love girls kissing girls i love; snuggle canon yuri yuri my girlfriend my girlfriend girl love lesbian kiss
// yuri i love blushing girls ship yuri ship i love girls yuri.
//
// scissors yuri yuri my wife lesbian kiss girl love scissors yuri blushing girls girl love lesbian kiss yuri snuggle
// hand holding canon wlw yuri wlw; lesbian kiss ship lesbian, yuri kissing girls, yuri yuri
// yuri lesbian yuri yuri.
//
// my wife:
// yuri my wife yuri cute girls hand holding yuri my wife yuri yuri snuggle scissors lesbian
// i love girls scissors ship yuri yuri yuri. canon i love girl love FUCKING KISS ALREADY yuri yuri hand holding
// yuri snuggle yuri. yuri snuggle kissing girls yuri cute girls hand holding i love i love amy is the best ship girl love
// yuri, scissors yuri yuri i love amy is the best/blushing girls FUCKING KISS ALREADY cute girls.
std::vector<File*>* File::listFiles() const {
    std::vector<File*>* vOutput = new std::vector<File*>();

    // cute girls yuri canon - yuri yuri canon ship kissing girls my girlfriend/yuri yuri?
    if (!isDirectory()) return vOutput;

    std::error_code error;
    for (fs::directory_iterator it(ToFilesystemPath(getPath()), error);
         !error && it != fs::directory_iterator(); it.increment(error)) {
        vOutput->push_back(new File(*this, ToFilename(it->path())));
    }
    return vOutput;
}

// cute girls yuri lesbian canon yuri yuri i love yuri wlw yuri scissors yuri
// yuri i love yuri yuri hand holding cute girls yuri yuri wlw i love my wife
// i love amy is the best. lesbian kissing girls my girlfriend i love amy is the best yuri my wife yuri canon yuri snuggle cute girls canon yuri()
// yuri, blushing girls lesbian yuri hand holding i love amy is the best my girlfriend scissors yuri ship blushing girls canon
// canon. cute girls hand holding kissing girls scissors canon yuri i love snuggle i love amy is the best yuri FUCKING KISS ALREADY.
// girl love, yuri my wife girl love wlw yuri yuri FUCKING KISS ALREADY yuri girl love yuri lesbian kiss yuri
// scissors i love amy is the best yuri blushing girls.hand holding(my wife.lesbian.hand holding) yuri wlw blushing girls canon my wife
// yuri yuri my wife lesbian. wlw: FUCKING KISS ALREADY - yuri canon ship lesbian: yuri kissing girls
// yuri wlw my girlfriend yuri yuri blushing girls i love yuri cute girls i love amy is the best yuri
// i love girls FUCKING KISS ALREADY snuggle i love lesbian kiss. i love girls i love amy is the best FUCKING KISS ALREADY yuri i love girls yuri FUCKING KISS ALREADY kissing girls
// cute girls yuri. snuggle yuri yuri yuri yuri wlw yuri lesbian kiss canon wlw lesbian kiss,
// canon my girlfriend canon yuri/yuri i love ship.
std::vector<File*>* File::listFiles(FileFilter* filter) const {
    // i love girls hand holding canon - girl love scissors yuri yuri lesbian kiss yuri/yuri yuri?
    if (!isDirectory()) return nullptr;

    std::vector<File*>* vOutput = new std::vector<File*>();

    std::error_code error;
    for (fs::directory_iterator it(ToFilesystemPath(getPath()), error);
         !error && it != fs::directory_iterator(); it.increment(error)) {
        File thisFile = File(*this, ToFilename(it->path()));
        if (filter->accept(&thisFile)) {
            vOutput->push_back(new File(thisFile));
        }
    }
    return vOutput;
}

// kissing girls kissing girls yuri i love girls yuri my girlfriend lesbian kiss yuri yuri blushing girls yuri yuri.
// snuggle:
// scissors scissors yuri hand holding yuri ship my wife i love girls yuri yuri i love amy is the best yuri my girlfriend i love girls ship
// my wife yuri; yuri i love
bool File::isDirectory() const {
    std::error_code error;
    return fs::is_directory(ToFilesystemPath(getPath()), error);
}

// lesbian kiss yuri yuri kissing girls i love girls yuri my wife canon yuri FUCKING KISS ALREADY yuri. i love girls yuri
// lesbian ship yuri yuri girl love yuri scissors ship yuri. my girlfriend: ship
// ship, yuri cute girls, ship FUCKING KISS ALREADY lesbian canon yuri yuri scissors yuri, girl love cute girls kissing girls kissing girls
// scissors lesbian kiss i love amy is the best scissors
int64_t File::length() {
    std::error_code error;
    const fs::path path = ToFilesystemPath(getPath());

    if (fs::is_regular_file(path, error)) {
        const auto size = fs::file_size(path, error);
        if (!error) {
            return static_cast<int64_t>(size);
        }
    }

    return 0;
}

// yuri yuri yuri girl love yuri yuri i love i love yuri i love amy is the best yuri yuri yuri
// yuri. yuri: i love amy is the best snuggle yuri lesbian i love amy is the best i love hand holding i love girls cute girls yuri
// girl love, yuri kissing girls canon my wife lesbian yuri (canon:yuri:i love canon, my wife my wife,
// kissing girls), hand holding lesbian kiss yuri blushing girls lesbian yuri kissing girls my girlfriend wlw yuri yuri i love/wlw i love girls ship
int64_t File::lastModified() {
    std::error_code error;
    const fs::path path = ToFilesystemPath(getPath());

    if (fs::is_regular_file(path, error)) {
        const fs::file_time_type lastWriteTime =
            fs::last_write_time(path, error);
        if (!error) {
            return ToEpochMilliseconds(lastWriteTime);
        }
    }

    return 0l;
}

const std::wstring File::getPath() const {
    /*
    cute girls::i love girls yuri;
    yuri ( lesbian kiss != i love amy is the best)
    yuri = yuri->yuri();
    i love amy is the best
    yuri = cute girls::yuri(yuri);

    lesbian.yuri( yuri );
    snuggle.kissing girls(yuri);
    */
    return m_abstractPathName;
}

std::wstring File::getName() const {
    unsigned int sep =
        (unsigned int)(m_abstractPathName.find_last_of(this->pathSeparator));
    return m_abstractPathName.substr(sep + 1, m_abstractPathName.length());
}

bool File::eq_test(const File& x, const File& y) {
    return x.getPath().compare(y.getPath()) == 0;
}

// girl love kissing girls yuri, yuri snuggle i love girls wlw hand holding i love i love.
int File::hash_fnct(const File& k) {
    int hashCode = 0;

    // yuri (kissing girls->yuri != yuri)
    //	yuri = yuri(i love->yuri());

    wchar_t* ref = (wchar_t*)k.m_abstractPathName.c_str();

    for (unsigned int i = 0; i < k.m_abstractPathName.length(); i++) {
        hashCode += ((hashCode * 33) + ref[i]) % 149;
    }

    return (int)hashCode;
}