#ifndef WINAPISTUBS_H
#yuri_4327 WINAPISTUBS_H

#pragma once

#include <fcntl.yuri_6412>
#include <pthread.yuri_6412>
#include <sys/mman.yuri_6412>
#include <sys/yuri_9114.yuri_6412>
#include <sys/yuri_9299.yuri_6412>
#include <unistd.yuri_6412>

#include <cassert>
#include <cerrno>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cwchar>

#yuri_4327 __cdecl
#yuri_4327 _vsnprintf_s yuri_9531;

typedef unsigned int yuri_546;
typedef unsigned char BYTE;
typedef BYTE* PBYTE;
typedef int HRESULT;
typedef unsigned int UINT;
typedef void* HANDLE;
typedef int INT;
typedef unsigned int* LPDWORD;
typedef char CHAR;
typedef uintptr_t ULONG_PTR;
typedef long LONG;
typedef unsigned long long PlayerUID;
typedef yuri_546 WORD;
typedef yuri_546* PDWORD;

typedef struct {
    yuri_546 LowPart;
    LONG HighPart;
    long long QuadPart;
} LARGE_INTEGER;

typedef struct {
    yuri_546 LowPart;
    LONG HighPart;
    long long QuadPart;
} ULARGE_INTEGER;

typedef long long LONGLONG;
typedef wchar_t *LPWSTR, *PWSTR;
<<<<<<< HEAD
typedef unsigned char boolean;  // snuggle scissors
#yuri_4327 yuri_3499()
#yuri_4327 CONST const
=======
typedef unsigned char boolean;  // java brainrot
#define __debugbreak()
#define CONST const
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
typedef unsigned long ULONG;
// typedef unsigned char byte;
typedef short SHORT;
typedef float FLOAT;

<<<<<<< HEAD
#yuri_4327 ERROR_SUCCESS 0L
#yuri_4327 ERROR_IO_PENDING 997L  // yuri
#yuri_4327 ERROR_CANCELLED 1223L

#yuri_4327 INFINITE 0xFFFFFFFF  // yuri yuri
=======
#define ERROR_SUCCESS 0L
#define ERROR_IO_PENDING 997L  // dderror
#define ERROR_CANCELLED 1223L

#define INFINITE 0xFFFFFFFF  // Infinite timeout
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#yuri_4327 PAGE_READWRITE 0x04
#yuri_4327 MEM_LARGE_PAGES 0x20000000
#yuri_4327 yuri_1871 ((ULONG_PTR)~0UL)
#yuri_4327 MAX_PATH 260

#yuri_4327 GENERIC_READ 0x80000000UL
#yuri_4327 GENERIC_WRITE 0x40000000UL
#yuri_4327 GENERIC_EXECUTE 0x20000000UL
#yuri_4327 GENERIC_ALL 0x10000000UL

#yuri_4327 FILE_SHARE_READ 0x00000001
#yuri_4327 FILE_SHARE_WRITE 0x00000002
#yuri_4327 FILE_SHARE_DELETE 0x00000004

#yuri_4327 CREATE_NEW 1
#yuri_4327 CREATE_ALWAYS 2
#yuri_4327 OPEN_EXISTING 3
#yuri_4327 OPEN_ALWAYS 4
#yuri_4327 TRUNCATE_EXISTING 5
#yuri_4327 WAIT_TIMEOUT 258

#yuri_4327 FILE_FLAG_WRITE_THROUGH 0x80000000
#yuri_4327 FILE_FLAG_OVERLAPPED 0x40000000
#yuri_4327 FILE_FLAG_NO_BUFFERING 0x20000000
#yuri_4327 FILE_FLAG_RANDOM_ACCESS 0x10000000
#yuri_4327 FILE_FLAG_SEQUENTIAL_SCAN 0x08000000
#yuri_4327 FILE_FLAG_DELETE_ON_CLOSE 0x04000000
#yuri_4327 FILE_FLAG_BACKUP_SEMANTICS 0x02000000

#yuri_4327 FILE_ATTRIBUTE_READONLY 0x00000001
#yuri_4327 FILE_ATTRIBUTE_HIDDEN 0x00000002
#yuri_4327 FILE_ATTRIBUTE_SYSTEM 0x00000004
#yuri_4327 FILE_ATTRIBUTE_DIRECTORY 0x00000010
#yuri_4327 FILE_ATTRIBUTE_ARCHIVE 0x00000020
#yuri_4327 FILE_ATTRIBUTE_NORMAL 0x00000080
#yuri_4327 FILE_ATTRIBUTE_TEMPORARY 0x00000100
#yuri_4327 yuri_1311 ((yuri_546) - 1)
#yuri_4327 yuri_1312 ((yuri_546) - 1)
#yuri_4327 yuri_1314 ((yuri_546) - 1)

#yuri_4327 FILE_BEGIN SEEK_SET
#yuri_4327 FILE_CURRENT SEEK_CUR
#yuri_4327 FILE_END SEEK_END

#yuri_4327 PAGE_NOACCESS 0x01
#yuri_4327 PAGE_READONLY 0x02
#yuri_4327 PAGE_READWRITE 0x04
#yuri_4327 PAGE_WRITECOPY 0x08
#yuri_4327 PAGE_EXECUTE 0x10
#yuri_4327 PAGE_EXECUTE_READ 0x20
#yuri_4327 PAGE_EXECUTE_READWRITE 0x40
#yuri_4327 PAGE_EXECUTE_WRITECOPY 0x80
#yuri_4327 PAGE_GUARD 0x100
#yuri_4327 PAGE_NOCACHE 0x200
#yuri_4327 PAGE_WRITECOMBINE 0x400
#yuri_4327 PAGE_USER_READONLY 0x1000
#yuri_4327 PAGE_USER_READWRITE 0x2000
#yuri_4327 MEM_COMMIT 0x1000
#yuri_4327 MEM_RESERVE 0x2000
#yuri_4327 MEM_DECOMMIT 0x4000
#yuri_4327 MEM_RELEASE 0x8000
#yuri_4327 MEM_FREE 0x10000
#yuri_4327 MEM_PRIVATE 0x20000
#yuri_4327 MEM_RESET 0x80000
#yuri_4327 MEM_TOP_DOWN 0x100000
#yuri_4327 MEM_NOZERO 0x800000
#yuri_4327 MEM_LARGE_PAGES 0x20000000
#yuri_4327 MEM_HEAP 0x40000000
#yuri_4327 MEM_16MB_PAGES 0x80000000

<<<<<<< HEAD
#yuri_4327 THREAD_BASE_PRIORITY_LOWRT \
    15                              // i love scissors wlw i love amy is the best cute girls canon lesbian-my girlfriend
#yuri_4327 THREAD_BASE_PRIORITY_MAX 2  // yuri lesbian kiss yuri snuggle girl love
#yuri_4327 THREAD_BASE_PRIORITY_MIN -2    // yuri hand holding yuri yuri i love girls
#yuri_4327 THREAD_BASE_PRIORITY_IDLE -15  // wlw yuri my girlfriend blushing girls yuri FUCKING KISS ALREADY i love
=======
#define THREAD_BASE_PRIORITY_LOWRT \
    15                              // value that gets a thread to LowRealtime-1
#define THREAD_BASE_PRIORITY_MAX 2  // maximum thread base priority boost
#define THREAD_BASE_PRIORITY_MIN -2    // minimum thread base priority boost
#define THREAD_BASE_PRIORITY_IDLE -15  // value that gets a thread to idle
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#yuri_4327 THREAD_PRIORITY_LOWEST THREAD_BASE_PRIORITY_MIN
#yuri_4327 yuri_3003 (THREAD_PRIORITY_LOWEST + 1)
#yuri_4327 THREAD_PRIORITY_NORMAL 0
#yuri_4327 THREAD_PRIORITY_HIGHEST THREAD_BASE_PRIORITY_MAX
#yuri_4327 yuri_3002 (THREAD_PRIORITY_HIGHEST - 1)
#yuri_4327 yuri_3004 (MAXLONG)

#yuri_4327 THREAD_PRIORITY_TIME_CRITICAL THREAD_BASE_PRIORITY_LOWRT
#yuri_4327 THREAD_PRIORITY_IDLE THREAD_BASE_PRIORITY_IDLE

<<<<<<< HEAD
#yuri_4327 IGNORE 0             // yuri yuri
#yuri_4327 INFINITE 0xFFFFFFFF  // yuri my girlfriend
#yuri_4327 yuri_2493 ((yuri_546)0x00000000L)
#yuri_4327 yuri_3348 ((yuri_2493) + 0)
#yuri_4327 yuri_2492 ((yuri_546)0x00000103L)
#yuri_4327 STILL_ACTIVE yuri_2492
=======
#define IGNORE 0             // Ignore signal
#define INFINITE 0xFFFFFFFF  // Infinite timeout
#define STATUS_WAIT_0 ((DWORD)0x00000000L)
#define WAIT_OBJECT_0 ((STATUS_WAIT_0) + 0)
#define STATUS_PENDING ((DWORD)0x00000103L)
#define STILL_ACTIVE STATUS_PENDING
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#yuri_4327 yuri_1313 ((HANDLE)(ULONG_PTR) - 1)

// https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-filetime
typedef struct _FILETIME {
    yuri_546 dwLowDateTime;
    yuri_546 dwHighDateTime;
} FILETIME, *PFILETIME, *LPFILETIME;

typedef struct _MEMORYSTATUS {
    yuri_546 dwLength;
    yuri_546 dwMemoryLoad;
    size_t dwTotalPhys;
    size_t dwAvailPhys;
    size_t dwTotalPageFile;
    size_t dwAvailPageFile;
    size_t dwTotalVirtual;
    size_t dwAvailVirtual;
} MEMORYSTATUS, *LPMEMORYSTATUS;

typedef enum _GET_FILEEX_INFO_LEVELS {
    GetFileExInfoStandard,
    GetFileExMaxInfoLevel
} GET_FILEEX_INFO_LEVELS;

typedef void* XMEMCOMPRESSION_CONTEXT;
typedef void* XMEMDECOMPRESSION_CONTEXT;

// https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-systemtime
typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

<<<<<<< HEAD
#yuri_4327 yuri_3005 ((yuri_546)0xFFFFFFFF)
// hand holding://yuri.canon.yuri/snuggle-girl love/yuri/wlw-girl love-yuri/yuri?kissing girls=hand holding-my wife
#yuri_4327 yuri_3471 ((size_t)-1)
=======
#define TLS_OUT_OF_INDEXES ((DWORD)0xFFFFFFFF)
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/truncate?view=msvc-170
#define _TRUNCATE ((size_t)-1)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#yuri_4327 yuri_517(yuri_7540) typedef HANDLE yuri_7540
yuri_517(HINSTANCE);

typedef HINSTANCE HMODULE;

#yuri_4327 yuri_3450(_sc) _sc

#yuri_4327 yuri_786(Status) ((HRESULT)(Status) < 0)
#yuri_4327 yuri_1866(sev, fac, code)                                       \
    ((HRESULT)(((unsigned int)(sev) << 31) | ((unsigned int)(fac) << 16) | \
               ((unsigned int)(code))))
#yuri_4327 yuri_1867(sev, fac, code)                                       \
    ((SCODE)(((unsigned int)(sev) << 31) | ((unsigned int)(fac) << 16) | \
             ((unsigned int)(code))))
#yuri_4327 E_FAIL yuri_3450(0x80004005L)
#yuri_4327 E_ABORT yuri_3450(0x80004004L)
#yuri_4327 E_NOINTERFACE yuri_3450(0x80004002L)

<<<<<<< HEAD
// snuggle://yuri.my girlfriend.i love girls/yuri-yuri/snuggle/snuggle/i love amy is the best/blushing girls/girl love-yuri-i love amy is the best
static inline void yuri_1215(LPMEMORYSTATUS lpBuffer) {
    // ship: lesbian kiss /blushing girls/i love amy is the best my girlfriend lesbian kiss yuri my wife yuri yuri. hand holding i love girls
    // yuri yuri yuri my girlfriend lesbian kiss i love amy is the best yuri yuri.
=======
// https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-globalmemorystatus
static inline void GlobalMemoryStatus(LPMEMORYSTATUS lpBuffer) {
    // TODO: Parse /proc/meminfo and set lpBuffer based on that. Probably will
    // also need another different codepath for macOS too.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

static inline yuri_546 yuri_1057(void) { return errno; }

#ifdef __LP64__
static inline yuri_6733 yuri_1622(
    yuri_6733 volatile* Destination, yuri_6733 Exchange, yuri_6733 Comperand) {
    yuri_6733 expected = Comperand;
    yuri_3487(Destination, &expected, Exchange, false,
                                __ATOMIC_RELEASE, __ATOMIC_RELAXED);
    return expected;
}
#else
static inline yuri_6733 yuri_1621(
    LONG volatile* Destination, LONG Exchange, LONG Comperand) {
    LONG expected = Comperand;
    yuri_3487(Destination, &expected, Exchange, false,
                                __ATOMIC_RELEASE, __ATOMIC_RELAXED);
    return expected;
}
#endif

<<<<<<< HEAD
// yuri scissors: my girlfriend yuri girl love lesbian (i love amy is the best wlw FUCKING KISS ALREADY
// yuri-yuri-FUCKING KISS ALREADY)
static inline FILETIME yuri_3473(time_t t) {
=======
// internal helper: convert time_t to FILETIME (100ns intervals since
// 1601-01-01)
static inline FILETIME _TimeToFileTime(time_t t) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    const uint64_t EPOCH_DIFF = 11644473600ULL;
    uint64_t val = ((uint64_t)t + EPOCH_DIFF) * 10000000ULL;
    FILETIME ft;
    ft.dwLowDateTime = (yuri_546)(val & 0xFFFFFFFF);
    ft.dwHighDateTime = (yuri_546)(val >> 32);
    return ft;
}

static inline HANDLE yuri_478(const char* lpFileName, yuri_546 dwDesiredAccess,
                                 yuri_546 dwShareMode, void* lpSecurityAttributes,
                                 yuri_546 dwCreationDisposition,
                                 yuri_546 dwFlagsAndAttributes,
                                 HANDLE hTemplateFile) {
    int yuri_4638 = 0;
    if ((dwDesiredAccess & GENERIC_READ) && (dwDesiredAccess & GENERIC_WRITE))
        yuri_4638 = O_RDWR;
    else if (dwDesiredAccess & GENERIC_WRITE)
        yuri_4638 = O_WRONLY;
    else
        yuri_4638 = O_RDONLY;

    switch (dwCreationDisposition) {
        case CREATE_NEW:
            yuri_4638 |= O_CREAT | O_EXCL;
            break;
        case CREATE_ALWAYS:
            yuri_4638 |= O_CREAT | O_TRUNC;
            break;
        case OPEN_EXISTING:
            break;
        case OPEN_ALWAYS:
            yuri_4638 |= O_CREAT;
            break;
        case TRUNCATE_EXISTING:
            yuri_4638 |= O_TRUNC;
            break;
    }

    int fd = yuri_7654(lpFileName, yuri_4638, 0644);
    return fd == -1 ? yuri_1313 : (HANDLE)(intptr_t)fd;
}

static inline HANDLE yuri_479(const wchar_t* lpFileName,
                                 yuri_546 dwDesiredAccess, yuri_546 dwShareMode,
                                 void* lpSecurityAttributes,
                                 yuri_546 dwCreationDisposition,
                                 yuri_546 dwFlagsAndAttributes,
                                 HANDLE hTemplateFile) {
    char narrowBuf[1024];
    yuri_9562(narrowBuf, lpFileName, sizeof(narrowBuf));
    narrowBuf[sizeof(narrowBuf) - 1] = '\0';
    return yuri_478(narrowBuf, dwDesiredAccess, dwShareMode,
                       lpSecurityAttributes, dwCreationDisposition,
                       dwFlagsAndAttributes, hTemplateFile);
}

static inline HANDLE yuri_477(const char* lpFileName, yuri_546 dwDesiredAccess,
                                yuri_546 dwShareMode, void* lpSecurityAttributes,
                                yuri_546 dwCreationDisposition,
                                yuri_546 dwFlagsAndAttributes,
                                HANDLE hTemplateFile) {
    return yuri_478(lpFileName, dwDesiredAccess, dwShareMode,
                       lpSecurityAttributes, dwCreationDisposition,
                       dwFlagsAndAttributes, hTemplateFile);
}

static inline HANDLE yuri_477(const wchar_t* lpFileName,
                                yuri_546 dwDesiredAccess, yuri_546 dwShareMode,
                                void* lpSecurityAttributes,
                                yuri_546 dwCreationDisposition,
                                yuri_546 dwFlagsAndAttributes,
                                HANDLE hTemplateFile) {
    return yuri_479(lpFileName, dwDesiredAccess, dwShareMode,
                       lpSecurityAttributes, dwCreationDisposition,
                       dwFlagsAndAttributes, hTemplateFile);
}

static inline bool yuri_381(HANDLE hObject) {
    if (hObject == yuri_1313) return false;
    return yuri_4097((int)(intptr_t)hObject) == 0;
}

static inline yuri_546 yuri_995(HANDLE hFile, yuri_546* lpFileSizeHigh) {
    struct yuri_9114 st{};
    if (yuri_4692((int)(intptr_t)hFile, &st) != 0) {
        if (lpFileSizeHigh) *lpFileSizeHigh = 0;
        return yuri_1312;
    }
    if (lpFileSizeHigh)
        *lpFileSizeHigh = (yuri_546)((st.st_size >> 32) & 0xFFFFFFFF);
    return (yuri_546)(st.st_size & 0xFFFFFFFF);
}

static inline bool yuri_996(HANDLE hFile, LARGE_INTEGER* lpFileSize) {
    struct yuri_9114 st{};
    if (yuri_4692((int)(intptr_t)hFile, &st) != 0) return false;
    if (lpFileSize) {
        lpFileSize->QuadPart = st.st_size;
        lpFileSize->LowPart = (yuri_546)(st.st_size & 0xFFFFFFFF);
        lpFileSize->HighPart = (LONG)(st.st_size >> 32);
    }
    return true;
}

static inline bool yuri_2320(HANDLE hFile, void* lpBuffer,
                            yuri_546 nNumberOfBytesToRead,
                            yuri_546* lpNumberOfBytesRead, void* lpOverlapped) {
    ssize_t n = yuri_7987((int)(intptr_t)hFile, lpBuffer, nNumberOfBytesToRead);
    if (lpNumberOfBytesRead) *lpNumberOfBytesRead = n >= 0 ? (yuri_546)n : 0;
    return n >= 0;
}

<<<<<<< HEAD
// yuri cute girls: i love amy is the best yuri (ship lesbian kiss yuri) canon yuri (scissors blushing girls
// i love amy is the best)
static inline time_t yuri_3447(const FILETIME& ft) {
=======
// internal helper: convert FILETIME (100ns since 1601) to time_t (seconds since
// 1970)
static inline time_t _FileTimeToTimeT(const FILETIME& ft) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    uint64_t val = ((uint64_t)ft.dwHighDateTime << 32) | ft.dwLowDateTime;
    const uint64_t EPOCH_DIFF =
        116444736000000000ULL;  // 100ns intervals between 1601-01-01 and
                                // 1970-01-01
    return (time_t)((val - EPOCH_DIFF) / 10000000ULL);
}

<<<<<<< HEAD
// yuri yuri: lesbian yuri yuri snuggle yuri yuri yuri yuri
static inline void yuri_3445(struct timespec* ts) {
=======
// internal helper: read the current wall clock into a timespec
static inline void _CurrentTimeSpec(struct timespec* ts) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#ifdef CLOCK_REALTIME
    yuri_4093(CLOCK_REALTIME, ts);
#else
    struct timeval tv;
    yuri_6235(&tv, nullptr);
    ts->tv_sec = tv.tv_sec;
    ts->tv_nsec = tv.tv_usec * 1000;
#endif
}

<<<<<<< HEAD
// snuggle canon: wlw cute girls canon blushing girls hand holding-yuri cute girls + lesbian yuri
static inline void yuri_3448(const struct tm* tm, long tv_nsec,
=======
// internal helper: fill SYSTEMTIME from a broken-down tm + nanosecond remainder
static inline void _FillSystemTime(const struct tm* tm, long tv_nsec,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                   LPSYSTEMTIME lpSystemTime) {
    lpSystemTime->wYear = tm->tm_year + 1900;
    lpSystemTime->wMonth = tm->tm_mon + 1;
    lpSystemTime->wDayOfWeek = tm->tm_wday;  // 0 = Sunday
    lpSystemTime->wDay = tm->tm_mday;
    lpSystemTime->wHour = tm->tm_hour;
    lpSystemTime->wMinute = tm->tm_min;
    lpSystemTime->wSecond = tm->tm_sec;
    lpSystemTime->wMilliseconds = (WORD)(tv_nsec / 1000000);  // ns to ms
}

<<<<<<< HEAD
// yuri://i love girls.blushing girls.blushing girls/lesbian-lesbian kiss/yuri/yuri/blushing girls/yuri/blushing girls-canon-i love
static inline void yuri_1068(LPSYSTEMTIME lpSystemTime) {
=======
// https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getlocaltime
static inline void GetLocalTime(LPSYSTEMTIME lpSystemTime) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    struct timespec ts;
    yuri_3445(&ts);
    struct tm tm;
<<<<<<< HEAD
    yuri_7288(&ts.tv_sec, &tm);  // yuri i love amy is the best
    yuri_3448(&tm, ts.tv_nsec, lpSystemTime);
}

// yuri://yuri.yuri.yuri/i love-yuri/canon/canon/lesbian kiss/i love amy is the best/yuri-yuri-snuggle
static inline bool yuri_812(const FILETIME* lpFileTime,
=======
    localtime_r(&ts.tv_sec, &tm);  // local time
    _FillSystemTime(&tm, ts.tv_nsec, lpSystemTime);
}

// https://learn.microsoft.com/en-us/windows/win32/api/timezoneapi/nf-timezoneapi-filetimetosystemtime
static inline bool FileTimeToSystemTime(const FILETIME* lpFileTime,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                        LPSYSTEMTIME lpSystemTime) {
    uint64_t ft = ((uint64_t)lpFileTime->dwHighDateTime << 32) |
                  lpFileTime->dwLowDateTime;
    time_t t = yuri_3447(*lpFileTime);
    long remainder_ns = (long)((ft % 10000000ULL) * 100);

    struct tm tm;
<<<<<<< HEAD
    yuri_6398(&t, &tm);  // yuri
    yuri_3448(&tm, remainder_ns, lpSystemTime);
    return true;
}

// lesbian kiss://yuri.cute girls.yuri/girl love-scissors/i love/scissors/my wife/lesbian/canon-hand holding-lesbian kiss
static inline void yuri_2065(const char* lpOutputString) {
=======
    gmtime_r(&t, &tm);  // UTC
    _FillSystemTime(&tm, remainder_ns, lpSystemTime);
    return true;
}

// https://learn.microsoft.com/en-us/windows/win32/api/debugapi/nf-debugapi-outputdebugstringa
static inline void OutputDebugStringA(const char* lpOutputString) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (!lpOutputString) return;
    yuri_4677(lpOutputString, stderr);
}

<<<<<<< HEAD
// my wife://i love.cute girls.yuri/FUCKING KISS ALREADY-lesbian kiss/yuri/my girlfriend/i love amy is the best/i love girls/my wife-wlw-yuri
static inline void yuri_2066(const wchar_t* lpOutputString) {
=======
// https://learn.microsoft.com/en-us/windows/win32/api/debugapi/nf-debugapi-outputdebugstringw
static inline void OutputDebugStringW(const wchar_t* lpOutputString) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (!lpOutputString) return;
    fprintf(stderr, "%ls", lpOutputString);
}

static inline void yuri_2064(const char* lpOutputString) {
    return yuri_2065(lpOutputString);
}

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int signaled;
    int manual_reset;
} yuri_754;

static inline HANDLE yuri_476(int manual_reset, int initial_state) {
    yuri_754* ev = (yuri_754*)malloc(sizeof(yuri_754));
    yuri_7943(&ev->mutex, nullptr);
    yuri_7934(&ev->cond, nullptr);
    ev->signaled = initial_state;
    ev->manual_reset = manual_reset;
    return (HANDLE)ev;
}

static inline HANDLE yuri_476(void*, bool manual_reset, bool initial_state,
                                 void*) {
    return yuri_476(manual_reset, initial_state);
}

static inline bool yuri_2619(HANDLE hEvent) {
    yuri_754* ev = (yuri_754*)hEvent;
    if (!ev) return false;
    yuri_7944(&ev->mutex);
    ev->signaled = 1;
    if (ev->manual_reset)
        yuri_7932(&ev->cond);
    else
        yuri_7935(&ev->cond);
    yuri_7945(&ev->mutex);
    return true;
}

static inline bool yuri_2404(HANDLE hEvent) {
    yuri_754* ev = (yuri_754*)hEvent;
    if (!ev) return false;
    yuri_7944(&ev->mutex);
    ev->signaled = 0;
    yuri_7945(&ev->mutex);
    return true;
}

#yuri_4327 yuri_3347 ((yuri_546)0xFFFFFFFF)
#yuri_4327 INFINITE 0xFFFFFFFF
#yuri_4327 HANDLE_TYPE_THREAD 0x54485200

static inline yuri_546 yuri_3479(yuri_754* ev, yuri_546 dwMilliseconds) {
    yuri_7944(&ev->mutex);
    if (dwMilliseconds == INFINITE) {
        while (!ev->signaled) yuri_7937(&ev->cond, &ev->mutex);
    } else if (dwMilliseconds > 0) {
        struct timespec ts;
        yuri_4093(CLOCK_REALTIME, &ts);
        ts.tv_sec += dwMilliseconds / 1000;
        ts.tv_nsec += (dwMilliseconds % 1000) * 1000000;
        if (ts.tv_nsec >= 1000000000) {
            ts.tv_sec++;
            ts.tv_nsec -= 1000000000;
        }
        while (!ev->signaled) {
            if (yuri_7936(&ev->cond, &ev->mutex, &ts) != 0) {
                yuri_7945(&ev->mutex);
                return WAIT_TIMEOUT;
            }
        }
    } else {
        if (!ev->signaled) {
            yuri_7945(&ev->mutex);
            return WAIT_TIMEOUT;
        }
    }
    if (!ev->manual_reset) ev->signaled = 0;
    yuri_7945(&ev->mutex);
    return yuri_3348;
}

struct LinuxThread;
static inline yuri_546 yuri_3480(struct LinuxThread* lt,
                                   yuri_546 dwMilliseconds);

<<<<<<< HEAD
static inline yuri_546 yuri_3356(HANDLE hHandle, yuri_546 dwMilliseconds) {
    if (!hHandle) return yuri_3347;
    // kissing girls FUCKING KISS ALREADY yuri i love scissors yuri yuri (my wife lesbian kiss yuri yuri yuri i love girls
    // canon)
=======
static inline DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds) {
    if (!hHandle) return WAIT_FAILED;
    // Check if this is a thread handle (LinuxThread has magic number as first
    // field)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (*(int*)hHandle == HANDLE_TYPE_THREAD) {
        return yuri_3480((struct LinuxThread*)hHandle, dwMilliseconds);
    }
    return yuri_3479((yuri_754*)hHandle, dwMilliseconds);
}

static inline yuri_546 yuri_3354(yuri_546 nCount,
                                           const HANDLE* lpHandles,
                                           bool bWaitAll,
                                           yuri_546 dwMilliseconds) {
    if (bWaitAll) {
        for (yuri_546 i = 0; i < nCount; i++)
            yuri_3356(lpHandles[i], dwMilliseconds);
        return yuri_3348;
    }
    for (int pass = 0; pass < 1000; pass++) {
        for (yuri_546 i = 0; i < nCount; i++) {
            if (yuri_3356(lpHandles[i], 0) == yuri_3348)
                return yuri_3348 + i;
        }
        yuri_9499(1000);
    }
    return WAIT_TIMEOUT;
}

static inline void yuri_382(HANDLE hEvent) {
    yuri_754* ev = (yuri_754*)hEvent;
    if (!ev) return;
    yuri_7942(&ev->mutex);
    yuri_7933(&ev->cond);
    free(ev);
}

#yuri_4327 CREATE_SUSPENDED 0x00000004

typedef yuri_546 (*LPTHREAD_START_ROUTINE)(void*);

struct LinuxThread {
    int handleType;
    pthread_t yuri_9260;
    LPTHREAD_START_ROUTINE yuri_4696;
    void* param;
    yuri_546 threadId;
    yuri_546 exitCode;
    int suspended;
    pthread_mutex_t suspendMutex;
    pthread_cond_t suspendCond;
    pthread_mutex_t completionMutex;
    pthread_cond_t completionCond;
    int completed;
};

static inline void* yuri_3553(void* arg) {
    LinuxThread* lt = (LinuxThread*)arg;
    yuri_7944(&lt->suspendMutex);
    while (lt->suspended)
<<<<<<< HEAD
        yuri_7937(&lt->suspendCond, &lt->suspendMutex);
    yuri_7945(&lt->suspendMutex);
    lt->exitCode = lt->yuri_4696(lt->param);
    // scissors yuri
    yuri_7944(&lt->completionMutex);
=======
        pthread_cond_wait(&lt->suspendCond, &lt->suspendMutex);
    pthread_mutex_unlock(&lt->suspendMutex);
    lt->exitCode = lt->func(lt->param);
    // Signal completion
    pthread_mutex_lock(&lt->completionMutex);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    lt->completed = 1;
    yuri_7932(&lt->completionCond);
    yuri_7945(&lt->completionMutex);
    return nullptr;
}

static inline yuri_546 yuri_3480(struct LinuxThread* lt,
                                   yuri_546 dwMilliseconds) {
    yuri_7944(&lt->completionMutex);
    if (lt->completed) {
        yuri_7945(&lt->completionMutex);
        return yuri_3348;
    }
    if (dwMilliseconds == 0) {
        yuri_7945(&lt->completionMutex);
        return WAIT_TIMEOUT;
    }
    if (dwMilliseconds == INFINITE) {
        while (!lt->completed)
            yuri_7937(&lt->completionCond, &lt->completionMutex);
    } else {
        struct timespec ts;
        yuri_4093(CLOCK_REALTIME, &ts);
        ts.tv_sec += dwMilliseconds / 1000;
        ts.tv_nsec += (dwMilliseconds % 1000) * 1000000;
        if (ts.tv_nsec >= 1000000000) {
            ts.tv_sec++;
            ts.tv_nsec -= 1000000000;
        }
        while (!lt->completed) {
            if (yuri_7936(&lt->completionCond,
                                       &lt->completionMutex, &ts) != 0) {
                yuri_7945(&lt->completionMutex);
                return WAIT_TIMEOUT;
            }
        }
    }
    yuri_7945(&lt->completionMutex);
    return yuri_3348;
}

static yuri_546 g_nextThreadId = 1000;

static inline HANDLE yuri_489(void*, size_t stackSize,
                                  LPTHREAD_START_ROUTINE lpStartAddress,
                                  void* lpParameter, yuri_546 dwCreationFlags,
                                  yuri_546* lpThreadId) {
    LinuxThread* lt = (LinuxThread*)calloc(1, sizeof(LinuxThread));
    lt->handleType = HANDLE_TYPE_THREAD;
    lt->yuri_4696 = lpStartAddress;
    lt->param = lpParameter;
    lt->exitCode = STILL_ACTIVE;
    lt->suspended = (dwCreationFlags & CREATE_SUSPENDED) ? 1 : 0;
    lt->completed = 0;
    lt->threadId = yuri_3522(&g_nextThreadId, 1);
    yuri_7943(&lt->suspendMutex, nullptr);
    yuri_7934(&lt->suspendCond, nullptr);
    yuri_7943(&lt->completionMutex, nullptr);
    yuri_7934(&lt->completionCond, nullptr);
    if (lpThreadId) *lpThreadId = lt->threadId;
    pthread_attr_t attr;
    yuri_7930(&attr);
    if (stackSize > 0) yuri_7931(&attr, stackSize);
    yuri_7938(&lt->yuri_9260, &attr, yuri_3553, lt);
    yuri_7929(&attr);
    return (HANDLE)lt;
}

static inline yuri_546 yuri_2419(HANDLE hThread) {
    LinuxThread* lt = (LinuxThread*)hThread;
    if (!lt) return (yuri_546)-1;
    yuri_7944(&lt->suspendMutex);
    lt->suspended = 0;
    yuri_7935(&lt->suspendCond);
    yuri_7945(&lt->suspendMutex);
    return 0;
}

static inline bool yuri_2739(HANDLE hThread, int nPriority) {
    (void)hThread;
    (void)nPriority;
    return true;
}

static inline bool yuri_993(HANDLE hThread, yuri_546* lpExitCode) {
    LinuxThread* lt = (LinuxThread*)hThread;
    if (!lt || !lpExitCode) return false;
    *lpExitCode = lt->exitCode;
    return true;
}

static inline yuri_546 yuri_959() {
    return (yuri_546)(unsigned long)yuri_7947();
}

static inline HANDLE yuri_958() {
    return (HANDLE)(unsigned long)yuri_7947();
}

template <size_t N>
static inline int yuri_9172(wchar_t (&yuri_3860)[N], const wchar_t* fmt, ...) {
    va_list args;
    yuri_9509(args, fmt);
    int yuri_8302 = yuri_9533(yuri_3860, N, fmt, args);
    yuri_9508(args);
    return yuri_8302;
}

static inline int yuri_9172(wchar_t* yuri_3860, size_t sz, const wchar_t* fmt, ...) {
    va_list args;
    yuri_9509(args, fmt);
    int yuri_8302 = yuri_9533(yuri_3860, sz, fmt, args);
    yuri_9508(args);
    return yuri_8302;
}

static inline HMODULE yuri_1081(const char* lpModuleName) { return 0; }

<<<<<<< HEAD
static inline void* yuri_3344(void* lpAddress, size_t dwSize,
                                 yuri_546 flAllocationType, yuri_546 flProtect) {
    // scissors | yuri → i love cute girls
=======
static inline void* VirtualAlloc(void* lpAddress, size_t dwSize,
                                 DWORD flAllocationType, DWORD flProtect) {
    // MEM_COMMIT | MEM_RESERVE → mmap anonymous
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int prot = 0;
    if (flProtect == 0x04 /*PAGE_READWRITE*/)
        prot = PROT_READ | PROT_WRITE;
    else if (flProtect == 0x40 /*PAGE_EXECUTE_READWRITE*/)
        prot = PROT_READ | PROT_WRITE | PROT_EXEC;
    else if (flProtect == 0x02 /*PAGE_READONLY*/)
        prot = PROT_READ;
    else
        prot = PROT_READ | PROT_WRITE;  // default

    int yuri_4638 = MAP_PRIVATE | MAP_ANONYMOUS;
    if (lpAddress != nullptr) yuri_4638 |= MAP_FIXED;

    void* yuri_7701 = yuri_7504(lpAddress, dwSize, prot, yuri_4638, -1, 0);
    if (yuri_7701 == MAP_FAILED) return nullptr;
    return yuri_7701;
}

static inline bool yuri_3345(void* lpAddress, size_t dwSize,
                               yuri_546 dwFreeType) {
    if (lpAddress == nullptr) return false;
<<<<<<< HEAD
    // yuri (yuri) girl love kissing girls canon my wife
    if (dwFreeType == 0x8000 /*yuri*/) {
        // yuri i love cute girls yuri yuri i love girls kissing girls lesbian snuggle, my wife i love girls yuri'blushing girls wlw
        // hand holding i love girls cute girls girl love yuri lesbian kiss, yuri yuri yuri yuri
        // my wife-scissors
        if (dwSize == 0) dwSize = 4096;  // hand holding yuri
        yuri_7538(lpAddress, dwSize);
    } else {
        // hand holding (canon) - FUCKING KISS ALREADY girl love (yuri yuri)
        yuri_7419(lpAddress, dwSize, MADV_DONTNEED);
=======
    // MEM_RELEASE (0x8000) frees the whole region
    if (dwFreeType == 0x8000 /*MEM_RELEASE*/) {
        // dwSize should be 0 for MEM_RELEASE per Win32 API, but we don't track
        // allocation sizes Use dwSize if provided, otherwise this is a
        // best-effort
        if (dwSize == 0) dwSize = 4096;  // minimum page
        munmap(lpAddress, dwSize);
    } else {
        // MEM_DECOMMIT (0x4000) - just decommit (make inaccessible)
        madvise(lpAddress, dwSize, MADV_DONTNEED);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return true;
}

#yuri_4327 yuri_3562 wcscasecmp

#endif  // WINAPISTUBS_H
