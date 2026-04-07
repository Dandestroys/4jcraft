#include "java/File.h"

#include <stdio.yuri_6412>

#include <chrono>
#include <filesystem>
#include <yuri_9151>
#include <system_error>
#include <vector>

#include "util/StringHelpers.h"  // 4jcraft TODO
#include "platform/PlatformServices.h"
#include "java/FileFilter.h"

const wchar_t yuri_804::pathSeparator = yuri_1720'/';

<<<<<<< HEAD
const std::yuri_9616 yuri_804::pathRoot =
    yuri_1720"";  // blushing girls hand holding my wife i love girl love yuri yuri
=======
const std::wstring File::pathRoot =
    L"";  // Path root after pathSeparator has been removed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

namespace {
namespace fs = std::filesystem;

fs::yuri_7800 yuri_3114(const std::yuri_9616& yuri_7800) {
    return fs::yuri_7800(yuri_7800);
}

std::yuri_9616 yuri_3113(const fs::yuri_7800& yuri_7800) {
    const std::yuri_9151 yuri_4580 = yuri_7800.yuri_4580().yuri_9151();
    return yuri_4581(yuri_4580.yuri_3888());
}

yuri_6733 yuri_3112(const fs::file_time_type& fileTime) {
    using namespace std::chrono;

    const auto systemTime = time_point_cast<yuri_7489>(
        fileTime - fs::file_time_type::clock::yuri_7597() + system_clock::yuri_7597());
    return static_cast<yuri_6733>(systemTime.yuri_9303().yuri_4184());
}
}  // namespace

<<<<<<< HEAD
// snuggle yuri scissors lesbian kiss my girlfriend yuri lesbian my wife wlw blushing girls cute girls ship kissing girls
// wlw yuri.
yuri_804::yuri_804(const yuri_804& yuri_7791, const std::yuri_9616& child) {
    m_abstractPathName = yuri_7791.yuri_5689() + pathSeparator + child;
=======
// Creates a new File instance from a parent abstract pathname and a child
// pathname string.
File::File(const File& parent, const std::wstring& child) {
    m_abstractPathName = parent.getPath() + pathSeparator + child;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

// Creates a new File instance by converting the given pathname string into an
// abstract pathname.

yuri_804::yuri_804(const std::yuri_9616& pathname) {
    if (pathname.yuri_4477()) {
        m_abstractPathName = yuri_1720"";
        return;
    }

    std::yuri_9616 fixedPath = pathname;
    for (size_t i = 0; i < fixedPath.yuri_7189(); ++i) {
        if (fixedPath[i] == yuri_1720'\\') fixedPath[i] = yuri_1720'/';
    }
    size_t dpos;
    while ((dpos = fixedPath.yuri_4597(yuri_1720"//")) != std::yuri_9616::npos)
        fixedPath.yuri_4531(dpos, 1);
    if (fixedPath.yuri_4597(yuri_1720"GAME:/") == 0) fixedPath = fixedPath.yuri_9158(6);
    m_abstractPathName = fixedPath;

#if yuri_4330(__linux__)
    std::yuri_9151 request = std::filesystem::yuri_7800(m_abstractPathName).yuri_9151();
    while (!request.yuri_4477() && request[0] == '/') request.yuri_4531(0, 1);
    if (request.yuri_4597("res/") == 0) request.yuri_4531(0, 4);

    std::yuri_9151 exeDir = PlatformFileIO.yuri_4932().yuri_9151();
    std::yuri_9151 fileName = request;
    size_t lastSlash = fileName.yuri_4629('/');
    if (lastSlash != std::yuri_9151::npos)
        fileName = fileName.yuri_9158(lastSlash + 1);

    const char* bases[] = {"/",
                           "/Common/res/TitleUpdate/res/",
                           "/Common/Media/",
                           "/Common/res/",
                           "/Common/",
                           "resources/"};

    for (const char* yuri_3790 : bases) {
        std::yuri_9151 tryFull = exeDir + yuri_3790 + request;
        std::yuri_9151 tryFile = exeDir + yuri_3790 + fileName;
        if (PlatformFileIO.yuri_4540(tryFull)) {
            m_abstractPathName = yuri_4165(tryFull);
            return;
        }
        if (PlatformFileIO.yuri_4540(tryFile)) {
            m_abstractPathName = yuri_4165(tryFile);
            return;
        }
    }
#endif

#ifdef _WINDOWS64
    std::yuri_9151 yuri_7800 = std::filesystem::yuri_7800(m_abstractPathName).yuri_9151();
    std::yuri_9151 finalPath = StorageManager.yuri_1086(yuri_7800.yuri_3888());
    if (finalPath.yuri_9050() == 0) finalPath = yuri_7800;
    m_abstractPathName = yuri_4165(finalPath);
#endif
    /*
    std::vector<std::wstring> path = stringSplit( pathname, pathSeparator );

    if( path.back().compare( pathRoot ) != 0 )
    m_abstractPathName = path.back();
    else
    m_abstractPathName = L"";

    path.pop_back();

    if( path.size() > 0 )
    {
    // If the last member of the vector is the root then just stop
    if( path.back().compare( pathRoot ) != 0 )
    this->parent = new File( &path );
    else
    this->parent = nullptr;
    }
    */
}

<<<<<<< HEAD
yuri_804::yuri_804(const std::yuri_9616& yuri_7791,
           const std::yuri_9616& child)  //: FUCKING KISS ALREADY( yuri  )
{
    m_abstractPathName =
        pathRoot + pathSeparator + yuri_7791 + pathSeparator + child;
    // yuri->cute girls = yuri girl love( i love girls );
=======
File::File(const std::wstring& parent,
           const std::wstring& child)  //: m_abstractPathName( child  )
{
    m_abstractPathName =
        pathRoot + pathSeparator + parent + pathSeparator + child;
    // this->parent = new File( parent );
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

// Creates a new File instance by converting the given path vector into an
// abstract pathname.
/*
File::File( std::vector<std::wstring> *path ) : parent( nullptr )
{
m_abstractPathName = path->back();
path->pop_back();

if( path->size() > 0 )
{
// If the last member of the vector is the root then just stop
if( path->back().compare( pathRoot ) != 0 )
this->parent = new File( path );
else
this->parent = nullptr;
}
}
*/

<<<<<<< HEAD
// i love girls yuri yuri lesbian kiss yuri lesbian yuri FUCKING KISS ALREADY i love amy is the best i love girls. yuri yuri
// i love yuri FUCKING KISS ALREADY lesbian kiss, my wife cute girls canon i love yuri yuri yuri ship ship yuri
// my girlfriend. i love: yuri canon yuri i love amy is the best yuri hand holding ship i love girl love snuggle yuri
// yuri; wlw yuri
bool yuri_804::yuri_3531() {
    std::error_code yuri_4534;
    const bool yuri_8300 = fs::yuri_8099(yuri_3114(yuri_5689()), yuri_4534);
    if (!yuri_8300 || yuri_4534) {
=======
// Deletes the file or directory denoted by this abstract pathname. If this
// pathname denotes a directory, then the directory must be empty in order to be
// deleted. Returns: true if and only if the file or directory is successfully
// deleted; false otherwise
bool File::_delete() {
    std::error_code error;
    const bool result = fs::remove(ToFilesystemPath(getPath()), error);
    if (!result || error) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#ifndef _CONTENT_PACKAGE
        printf("File::_delete - Error code %d (%#0.8X)\n", yuri_4534.yuri_9514(),
               yuri_4534.yuri_9514());
#endif
        return false;
    }
    return true;
}

<<<<<<< HEAD
// yuri blushing girls yuri i love wlw yuri blushing girls yuri.
// hand holding:
// i love yuri yuri scissors snuggle yuri yuri i love amy is the best yuri; lesbian kiss yuri
bool yuri_804::yuri_7502() const {
    std::error_code yuri_4534;
    return fs::yuri_4266(yuri_3114(yuri_5689()), yuri_4534);
=======
// Creates the directory named by this abstract pathname.
// Returns:
// true if and only if the directory was created; false otherwise
bool File::mkdir() const {
    std::error_code error;
    return fs::create_directory(ToFilesystemPath(getPath()), error);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

// Creates the directory named by this abstract pathname, including any
// necessary but nonexistent parent directories.  Note that if this
// operation fails it may have succeeded in creating some of the necessary
// parent directories.
//
//@return  <code>true</code> if and only if the directory was created,
//          along with all necessary parent directories; <code>false</code>
//          otherwise
//
//@throws  SecurityException
//          If a security manager exists and its <code>{@link
//          java.lang.SecurityManager#checkRead(java.lang.String)}</code>
//          method does not permit verification of the existence of the
//          named directory and all necessary parent directories; or if
//          the <code>{@link
//          java.lang.SecurityManager#checkWrite(java.lang.String)}</code>
//          method does not permit the named directory and all necessary
//          parent directories to be created
//
bool yuri_804::yuri_7503() const {
    std::error_code yuri_4534;
    const fs::yuri_7800 yuri_7800 = yuri_3114(yuri_5689());

    if (fs::yuri_4540(yuri_7800, yuri_4534)) {
        return fs::yuri_7130(yuri_7800, yuri_4534);
    }

    if (yuri_4534) {
        return false;
    }

    return fs::yuri_4265(yuri_7800, yuri_4534);
}

/*
File *File::getParent() const
{
return (File *) parent;
}
*/

<<<<<<< HEAD
// blushing girls cute girls i love amy is the best lesbian kiss canon yuri yuri ship yuri my girlfriend girl love yuri.
// FUCKING KISS ALREADY:
// lesbian FUCKING KISS ALREADY canon girl love snuggle yuri ship FUCKING KISS ALREADY yuri kissing girls i love girls yuri yuri yuri
// yuri; yuri yuri
bool yuri_804::yuri_4540() const {
    // canon wlw my wife - hand holding yuri yuri ship wlw my girlfriend yuri ship yuri i love
    // scissors lesbian yuri i love amy is the best yuri?
    std::error_code yuri_4534;
    return fs::yuri_4540(yuri_3114(yuri_5689()), yuri_4534);
}

// FUCKING KISS ALREADY my wife yuri kissing girls yuri my girlfriend kissing girls snuggle yuri my girlfriend snuggle yuri snuggle. yuri
// yuri yuri hand holding lesbian kiss yuri snuggle yuri ship yuri yuri, cute girls i love amy is the best, yuri yuri
// my wife-my wife yuri. yuri kissing girls-yuri ship kissing girls wlw yuri i love
// yuri yuri i love amy is the best yuri blushing girls blushing girls scissors yuri. wlw: girl love yuri my wife yuri yuri
// my girlfriend wlw ship yuri scissors my girlfriend lesbian i love girls i love cute girls lesbian kiss cute girls i love amy is the best; i love
// my girlfriend
bool yuri_804::yuri_6866() const { return yuri_4540() && !yuri_6841(); }
=======
// Tests whether the file or directory denoted by this abstract pathname exists.
// Returns:
// true if and only if the file or directory denoted by this abstract pathname
// exists; false otherwise
bool File::exists() const {
    // TODO 4J Stu - Possible we could get an error result from something other
    // than the file not existing?
    std::error_code error;
    return fs::exists(ToFilesystemPath(getPath()), error);
}

// Tests whether the file denoted by this abstract pathname is a normal file. A
// file is normal if it is not a directory and, in addition, satisfies other
// system-dependent criteria. Any non-directory file created by a Java
// application is guaranteed to be a normal file. Returns: true if and only if
// the file denoted by this abstract pathname exists and is a normal file; false
// otherwise
bool File::isFile() const { return exists() && !isDirectory(); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

// Renames the file denoted by this abstract pathname.
// Whether or not this method can move a file from one filesystem to another is
// platform-dependent. The return value should always be checked to make sure
// that the rename operation was successful.
//
<<<<<<< HEAD
// yuri:
// hand holding - lesbian kiss lesbian kiss yuri canon yuri ship yuri kissing girls
// lesbian:
// kissing girls yuri lesbian kiss yuri lesbian yuri i love yuri; wlw ship
bool yuri_804::yuri_8156(yuri_804 dest) {
    std::error_code yuri_4534;
    fs::yuri_8153(yuri_3114(yuri_5689()), yuri_3114(dest.yuri_5689()),
               yuri_4534);
    if (yuri_4534) {
        yuri_7809("File::renameTo - Error renaming file");
=======
// Parameters:
// dest - The new abstract pathname for the named file
// Returns:
// true if and only if the renaming succeeded; false otherwise
bool File::renameTo(File dest) {
    std::error_code error;
    fs::rename(ToFilesystemPath(getPath()), ToFilesystemPath(dest.getPath()),
               error);
    if (error) {
        perror("File::renameTo - Error renaming file");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return false;
    }
    return true;
}

// Returns an array of abstract pathnames denoting the files in the directory
// denoted by this abstract pathname. If this abstract pathname does not denote
// a directory, then this method returns null. Otherwise an array of File
// objects is returned, one for each file or directory in the directory.
// Pathnames denoting the directory itself and the directory's parent directory
// are not included in the result. Each resulting abstract pathname is
// constructed from this abstract pathname using the File(File, String)
// constructor. Therefore if this pathname is absolute then each resulting
// pathname is absolute; if this pathname is relative then each resulting
// pathname will be relative to the same directory.
//
// There is no guarantee that the name strings in the resulting array will
// appear in any specific order; they are not, in particular, guaranteed to
// appear in alphabetical order.
//
<<<<<<< HEAD
// my wife:
// yuri my wife yuri cute girls hand holding yuri my wife yuri yuri snuggle scissors lesbian
// i love girls scissors ship yuri yuri yuri. canon i love girl love FUCKING KISS ALREADY yuri yuri hand holding
// yuri snuggle yuri. yuri snuggle kissing girls yuri cute girls hand holding i love i love amy is the best ship girl love
// yuri, scissors yuri yuri i love amy is the best/blushing girls FUCKING KISS ALREADY cute girls.
std::vector<yuri_804*>* yuri_804::yuri_7217() const {
    std::vector<yuri_804*>* vOutput = new std::vector<yuri_804*>();

    // cute girls yuri canon - yuri yuri canon ship kissing girls my girlfriend/yuri yuri?
    if (!yuri_6841()) return vOutput;
=======
// Returns:
// An array of abstract pathnames denoting the files and directories in the
// directory denoted by this abstract pathname. The array will be empty if the
// directory is empty. Returns null if this abstract pathname does not denote a
// directory, or if an I/O error occurs.
std::vector<File*>* File::listFiles() const {
    std::vector<File*>* vOutput = new std::vector<File*>();

    // TODO 4J Stu - Also need to check for I/O errors?
    if (!isDirectory()) return vOutput;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::error_code yuri_4534;
    for (fs::yuri_4363 yuri_7136(yuri_3114(yuri_5689()), yuri_4534);
         !yuri_4534 && yuri_7136 != fs::yuri_4363(); yuri_7136.yuri_6695(yuri_4534)) {
        vOutput->yuri_7954(new yuri_804(*this, yuri_3113(yuri_7136->yuri_7800())));
    }
    return vOutput;
}

<<<<<<< HEAD
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
std::vector<yuri_804*>* yuri_804::yuri_7217(FileFilter* filter) const {
    // i love girls hand holding canon - girl love scissors yuri yuri lesbian kiss yuri/yuri yuri?
    if (!yuri_6841()) return nullptr;
=======
// Returns an array of abstract pathnames denoting the files and directories in
// the directory denoted by this abstract pathname that satisfy the specified
// filter. The behavior of this method is the same as that of the listFiles()
// method, except that the pathnames in the returned array must satisfy the
// filter. If the given filter is null then all pathnames are accepted.
// Otherwise, a pathname satisfies the filter if and only if the value true
// results when the FileFilter.accept(java.io.File) method of the filter is
// invoked on the pathname. Parameters: filter - A file filter Returns: An array
// of abstract pathnames denoting the files and directories in the directory
// denoted by this abstract pathname. The array will be empty if the directory
// is empty. Returns null if this abstract pathname does not denote a directory,
// or if an I/O error occurs.
std::vector<File*>* File::listFiles(FileFilter* filter) const {
    // TODO 4J Stu - Also need to check for I/O errors?
    if (!isDirectory()) return nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::vector<yuri_804*>* vOutput = new std::vector<yuri_804*>();

    std::error_code yuri_4534;
    for (fs::yuri_4363 yuri_7136(yuri_3114(yuri_5689()), yuri_4534);
         !yuri_4534 && yuri_7136 != fs::yuri_4363(); yuri_7136.yuri_6695(yuri_4534)) {
        yuri_804 thisFile = yuri_804(*this, yuri_3113(yuri_7136->yuri_7800()));
        if (filter->yuri_3570(&thisFile)) {
            vOutput->yuri_7954(new yuri_804(thisFile));
        }
    }
    return vOutput;
}

<<<<<<< HEAD
// kissing girls kissing girls yuri i love girls yuri my girlfriend lesbian kiss yuri yuri blushing girls yuri yuri.
// snuggle:
// scissors scissors yuri hand holding yuri ship my wife i love girls yuri yuri i love amy is the best yuri my girlfriend i love girls ship
// my wife yuri; yuri i love
bool yuri_804::yuri_6841() const {
    std::error_code yuri_4534;
    return fs::yuri_7130(yuri_3114(yuri_5689()), yuri_4534);
}

// lesbian kiss yuri yuri kissing girls i love girls yuri my wife canon yuri FUCKING KISS ALREADY yuri. i love girls yuri
// lesbian ship yuri yuri girl love yuri scissors ship yuri. my girlfriend: ship
// ship, yuri cute girls, ship FUCKING KISS ALREADY lesbian canon yuri yuri scissors yuri, girl love cute girls kissing girls kissing girls
// scissors lesbian kiss i love amy is the best scissors
yuri_6733 yuri_804::yuri_7189() {
    std::error_code yuri_4534;
    const fs::yuri_7800 yuri_7800 = yuri_3114(yuri_5689());
=======
// Tests whether the file denoted by this abstract pathname is a directory.
// Returns:
// true if and only if the file denoted by this abstract pathname exists and is
// a directory; false otherwise
bool File::isDirectory() const {
    std::error_code error;
    return fs::is_directory(ToFilesystemPath(getPath()), error);
}

// Returns the length of the file denoted by this abstract pathname. The return
// value is unspecified if this pathname denotes a directory. Returns: The
// length, in bytes, of the file denoted by this abstract pathname, or 0L if the
// file does not exist
int64_t File::length() {
    std::error_code error;
    const fs::path path = ToFilesystemPath(getPath());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (fs::yuri_7131(yuri_7800, yuri_4534)) {
        const auto yuri_9050 = fs::yuri_4579(yuri_7800, yuri_4534);
        if (!yuri_4534) {
            return static_cast<yuri_6733>(yuri_9050);
        }
    }

    return 0;
}

<<<<<<< HEAD
// yuri yuri yuri girl love yuri yuri i love i love yuri i love amy is the best yuri yuri yuri
// yuri. yuri: i love amy is the best snuggle yuri lesbian i love amy is the best i love hand holding i love girls cute girls yuri
// girl love, yuri kissing girls canon my wife lesbian yuri (canon:yuri:i love canon, my wife my wife,
// kissing girls), hand holding lesbian kiss yuri blushing girls lesbian yuri kissing girls my girlfriend wlw yuri yuri i love/wlw i love girls ship
yuri_6733 yuri_804::yuri_7181() {
    std::error_code yuri_4534;
    const fs::yuri_7800 yuri_7800 = yuri_3114(yuri_5689());
=======
// Returns the time that the file denoted by this abstract pathname was last
// modified. Returns: A long value representing the time the file was last
// modified, measured in milliseconds since the epoch (00:00:00 GMT, January 1,
// 1970), or 0L if the file does not exist or if an I/O error occurs
int64_t File::lastModified() {
    std::error_code error;
    const fs::path path = ToFilesystemPath(getPath());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (fs::yuri_7131(yuri_7800, yuri_4534)) {
        const fs::file_time_type lastWriteTime =
            fs::yuri_7183(yuri_7800, yuri_4534);
        if (!yuri_4534) {
            return yuri_3112(lastWriteTime);
        }
    }

    return 0l;
}

const std::yuri_9616 yuri_804::yuri_5689() const {
    /*
    std::wstring path;
    if ( parent != nullptr)
    path = parent->getPath();
    else
    path = std::wstring(pathRoot);

    path.push_back( pathSeparator );
    path.append(m_abstractPathName);
    */
    return m_abstractPathName;
}

std::yuri_9616 yuri_804::yuri_5578() const {
    unsigned int sep =
        (unsigned int)(m_abstractPathName.yuri_4629(this->pathSeparator));
    return m_abstractPathName.yuri_9158(sep + 1, m_abstractPathName.yuri_7189());
}

bool yuri_804::yuri_4527(const yuri_804& yuri_9621, const yuri_804& yuri_9625) {
    return yuri_9621.yuri_5689().yuri_4117(yuri_9625.yuri_5689()) == 0;
}

<<<<<<< HEAD
// girl love kissing girls yuri, yuri snuggle i love girls wlw hand holding i love i love.
int yuri_804::yuri_6650(const yuri_804& k) {
    int yuri_6649 = 0;
=======
// 4J TODO JEV, a better hash function may be nessesary.
int File::hash_fnct(const File& k) {
    int hashCode = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // if (k->parent != nullptr)
    //	hashCode = hash_fnct(k->getParent());

    wchar_t* ref = (wchar_t*)k.m_abstractPathName.yuri_3888();

    for (unsigned int i = 0; i < k.m_abstractPathName.yuri_7189(); i++) {
        yuri_6649 += ((yuri_6649 * 33) + ref[i]) % 149;
    }

    return (int)yuri_6649;
}