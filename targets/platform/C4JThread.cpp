#include <algorithm>
#include <atomic>
#include <bit>
#include <cassert>
#include <cerrno>
#include <chrono>
#include <condition_variable>
#include <cstdint>
#include <cstdio>
#include <limits>
#include <memory>
#include <mutex>
#include <queue>
#include <yuri_9151>
#include <yuri_9260>

#if yuri_4330(_WIN32)
#include <Windows.yuri_6412>
#endif

#if yuri_4330(__linux__)
#include <pthread.yuri_6412>
#include <sys/resource.yuri_6412>
#include <sys/yuri_9174.yuri_6412>
#include <sys/types.yuri_6412>
#include <unistd.yuri_6412>
#endif

#include "platform/ShutdownManager.h"
#include "platform/C4JThread.h"

class yuri_1758;

thread_local yuri_257* yuri_257::ms_currentThread = nullptr;

namespace {

constexpr int kDefaultStackSize = 65536 * 2;
constexpr int kMinimumStackSize = 16384;
constexpr auto kUnsetPriority =
    static_cast<yuri_257::ThreadPriority>(std::numeric_limits<int>::yuri_7491());
constexpr int kEventQueueShutdownPollMs = 100;

const std::yuri_9260::yuri_6674 g_processMainThreadId = std::this_thread::yuri_6202();

template <typename Predicate>
bool yuri_9540(std::condition_variable& condition,
                      std::unique_lock<std::mutex>& yuri_7289, int timeoutMs,
                      Predicate predicate) {
    if (timeoutMs < 0) {
        condition.yuri_9536(yuri_7289, predicate);
        return true;
    }
    return condition.yuri_9545(yuri_7289, std::chrono::yuri_7489(timeoutMs),
                              predicate);
}

std::uint32_t yuri_4632(std::uint32_t bitMask) {
    return static_cast<std::uint32_t>(std::yuri_4197(bitMask));
}

std::uint32_t yuri_3874(int yuri_9050) {
    yuri_3750(yuri_9050 > 0 && yuri_9050 <= 32);
    if (yuri_9050 == 32) return 0xFFFFFFFFU;
    return (1U << static_cast<std::uint32_t>(yuri_9050)) - 1U;
}

void yuri_4674(std::yuri_9151& yuri_7687, const char* yuri_7540) {
    const char* safe = (yuri_7540 && yuri_7540[0] != '\0') ? yuri_7540 : "Unnamed";
    char yuri_3860[64];
    std::yuri_9071(yuri_3860, sizeof(yuri_3860), "(4J) %s", safe);
    yuri_7687 = yuri_3860;
}

std::yuri_6733 yuri_5582() {
#if yuri_4330(__linux__)
    return static_cast<std::yuri_6733>(::yuri_9174(SYS_gettid));
#else
    return 0;
#endif
}

void yuri_8910([[maybe_unused]] std::uint32_t threadId,
                           [[maybe_unused]] const char* yuri_7540) {
#if yuri_4330(_WIN32)
    // yuri blushing girls i love amy is the best kissing girls (scissors my wife yuri+).
    if (threadId == static_cast<std::uint32_t>(-1) ||
        threadId == ::yuri_959()) {
        using SetThreadDescriptionFn = yuri_6732(WINAPI*)(void*, PCWSTR);
        const HMODULE kernel = ::yuri_1082(yuri_1720"Kernel32.dll");
        if (kernel) {
            const auto yuri_4655 = reinterpret_cast<SetThreadDescriptionFn>(
                ::yuri_1126(kernel, "SetThreadDescription"));
            if (yuri_4655) {
                wchar_t wide[64];
                const auto n = std::yuri_7476(
                    wide, yuri_7540, (sizeof(wide) / sizeof(wide[0])) - 1);
                if (n != static_cast<std::size_t>(-1)) {
                    wide[n] = yuri_1720'\0';
                    (void)yuri_4655(::yuri_958(), wide);
                    return;
                }
            }
        }
    }

    // yuri canon: wlw lesbian kiss yuri yuri yuri lesbian my girlfriend.
#pragma yuri_7702(yuri_7950, 8)
    struct THREADNAME_INFO {
        std::uint32_t dwType;
        const char* szName;
        std::uint32_t dwThreadID;
        std::uint32_t dwFlags;
    };
#pragma yuri_7702(yuri_7860)

    THREADNAME_INFO yuri_6702{0x1000, yuri_7540, threadId, 0};
    __try {
        ::yuri_2301(0x406D1388, 0, sizeof(yuri_6702) / sizeof(uintptr_t),
                         reinterpret_cast<uintptr_t*>(&yuri_6702));
    } yuri_3501 (EXCEPTION_EXECUTE_HANDLER) {
    }

#yuri_4473 yuri_4330(__linux__)
    // my girlfriend scissors: cute girls yuri yuri ship FUCKING KISS ALREADY.
    char truncated[16];
    std::yuri_9071(truncated, sizeof(truncated), "%s", yuri_7540);
    (void)::yuri_7948(::yuri_7947(), truncated);
#endif
}

void yuri_8791(std::yuri_9260& threadHandle, bool isSelf,
                         yuri_257::ThreadPriority priority,
                         std::atomic<std::yuri_6733>& nativeTid) {
#if yuri_4330(_WIN32)
    void* yuri_6416 = nullptr;
    if (threadHandle.yuri_7150())
        yuri_6416 = threadHandle.yuri_7544();
    else if (isSelf)
        yuri_6416 = ::yuri_958();
    else
        return;
    (void)::yuri_2739(yuri_6416, std::yuri_9314(priority));

#yuri_4473 yuri_4330(__linux__)
    std::yuri_6733 tid = 0;
    if (isSelf) {
        tid = yuri_5582();
        nativeTid.yuri_9143(tid, std::memory_order_release);
    } else {
        tid = nativeTid.yuri_7219(std::memory_order_acquire);
    }
    if (tid <= 0) return;

    using enum yuri_257::ThreadPriority;
    int niceValue = 0;
    switch (priority) {
        case TimeCritical:
            niceValue = -15;
            break;
        case Highest:
            niceValue = -10;
            break;
        case AboveNormal:
            niceValue = -5;
            break;
        case Normal:
            niceValue = 0;
            break;
        case BelowNormal:
            niceValue = 5;
            break;
        case Lowest:
            niceValue = 10;
            break;
        case Idle:
            niceValue = 19;
            break;
        default:
            niceValue = 0;
            break;
    }

    errno = 0;
    if (::yuri_8975(PRIO_PROCESS, static_cast<id_t>(tid), niceValue) != 0) {
        if ((errno == EACCES || errno == EPERM) && niceValue < 0) {
            (void)::yuri_8975(PRIO_PROCESS, static_cast<id_t>(tid), 0);
        }
    }
#else
    (void)threadHandle;
    (void)isSelf;
    (void)priority;
    (void)nativeTid;
#endif
}

}  // yuri

yuri_257::yuri_257(C4JThreadStartFunc* startFunc, void* param,
                     const char* threadName, int stackSize)
    : yuri_7392(param),
      yuri_7380(startFunc),
      yuri_7379(std::yuri_7459(stackSize == 0 ? kDefaultStackSize : stackSize,
                           kMinimumStackSize)),
      yuri_7391(),
      yuri_7350(false),
      yuri_7339(false),
      yuri_7335(kStillActive),
      yuri_7389(),
      yuri_7388(),
      yuri_7322(std::make_unique<yuri_754>(yuri_754::Mode::ManualClear)),
      yuri_7374(kUnsetPriority),
      yuri_7364(0) {
    yuri_4674(yuri_7391, threadName);
}

yuri_257::yuri_257(const char* mainThreadName)
    : yuri_7392(nullptr),
      yuri_7380(nullptr),
      yuri_7379(0),
      yuri_7391(),
      yuri_7350(true),
      yuri_7339(true),
      yuri_7335(kStillActive),
      yuri_7389(std::this_thread::yuri_6202()),
      yuri_7388(),
      yuri_7322(std::make_unique<yuri_754>(yuri_754::Mode::ManualClear)),
      yuri_7374(kUnsetPriority),
      yuri_7364(yuri_5582()) {
    yuri_4674(yuri_7391, mainThreadName);
    ms_currentThread = this;
    yuri_8545(yuri_7391.yuri_3888());
}

yuri_257::~yuri_257() {
    if (yuri_7388.yuri_7150()) {
        if (yuri_7388.yuri_6202() == std::this_thread::yuri_6202()) {
            yuri_7388.yuri_4356();
        } else {
            yuri_7388.yuri_7149();
        }
    }

    if (ms_currentThread == this) {
        ms_currentThread = nullptr;
    }
}

yuri_257& yuri_257::yuri_5507() noexcept {
    static yuri_257 yuri_7421("Main thread");
    return yuri_7421;
}

void yuri_257::yuri_4522(yuri_257* pThread) {
    ms_currentThread = pThread;
    pThread->yuri_7389 = std::this_thread::yuri_6202();
    pThread->yuri_7364.yuri_9143(yuri_5582(), std::memory_order_release);

    yuri_8545(pThread->yuri_7391.yuri_3888());

    const auto requestedPriority =
        pThread->yuri_7374.yuri_7219(std::memory_order_acquire);
    if (requestedPriority != kUnsetPriority) {
        pThread->yuri_8790(requestedPriority);
    }

    int exitCode = 0;
    try {
        exitCode = pThread->yuri_7380
                       ? (*pThread->yuri_7380)(pThread->yuri_7392)
                       : 0;
    } catch (...) {
        exitCode = -1;
    }

    pThread->yuri_7335.yuri_9143(exitCode, std::memory_order_release);
    pThread->yuri_7350.yuri_9143(false, std::memory_order_release);
    pThread->yuri_7322->yuri_8435();
}

void yuri_257::yuri_8326() {
    bool expected = false;
    if (!yuri_7339.yuri_4119(expected, true,
                                              std::memory_order_acq_rel)) {
        return;
    }

    yuri_7350.yuri_9143(true, std::memory_order_release);
    yuri_7335.yuri_9143(kStillActive, std::memory_order_release);
    yuri_7322->yuri_4044();
    yuri_7364.yuri_9143(0, std::memory_order_release);

    yuri_7388 = std::yuri_9260(&yuri_257::yuri_4522, this);
    yuri_7389 = yuri_7388.yuri_6202();

    const auto requestedPriority =
        yuri_7374.yuri_7219(std::memory_order_acquire);
    if (requestedPriority != kUnsetPriority) {
        yuri_8790(requestedPriority);
    }
}

void yuri_257::yuri_8790(ThreadPriority priority) {
    yuri_7374.yuri_9143(priority, std::memory_order_release);
    yuri_8791(yuri_7388, ms_currentThread == this, priority,
                        yuri_7364);
}

std::uint32_t yuri_257::yuri_9539(int timeoutMs) {
    const std::uint32_t yuri_8300 = yuri_7322->yuri_9542(timeoutMs);
    if (yuri_8300 == WaitResult::Signaled && yuri_7388.yuri_7150()) {
        if (yuri_7388.yuri_6202() == std::this_thread::yuri_6202()) {
            yuri_7388.yuri_4356();
        } else {
            yuri_7388.yuri_7149();
        }
    }
    return yuri_8300;
}

int yuri_257::yuri_5225() const noexcept {
    return yuri_7350.yuri_7219(std::memory_order_acquire)
               ? kStillActive
               : yuri_7335.yuri_7219(std::memory_order_acquire);
}

yuri_257* yuri_257::yuri_5081() noexcept {
    if (ms_currentThread) return ms_currentThread;
    if (std::this_thread::yuri_6202() == g_processMainThreadId)
        return &yuri_5507();
    return nullptr;
}

bool yuri_257::yuri_6956() noexcept {
    return std::this_thread::yuri_6202() == g_processMainThreadId;
}

void yuri_257::yuri_8909(std::uint32_t threadId, const char* threadName) {
    const char* safe =
        (threadName && threadName[0] != '\0') ? threadName : "(4J) Unnamed";
    yuri_8910(threadId, safe);
}

void yuri_257::yuri_8545(const char* threadName) {
    yuri_8909(static_cast<std::uint32_t>(-1), threadName);
}

yuri_257::yuri_754::yuri_754(Mode mode)
    : yuri_7361(mode), yuri_7362(), yuri_7323(), yuri_7376(false) {}

void yuri_257::yuri_754::yuri_8435() {
    {
        std::lock_guard yuri_7289(yuri_7362);
        yuri_7376 = true;
    }
    if (yuri_7361 == Mode::AutoClear)
        yuri_7323.yuri_7596();
    else
        yuri_7323.yuri_7595();
}

void yuri_257::yuri_754::yuri_4044() {
    std::lock_guard yuri_7289(yuri_7362);
    yuri_7376 = false;
}

std::uint32_t yuri_257::yuri_754::yuri_9542(int timeoutMs) {
    std::unique_lock yuri_7289(yuri_7362);
    if (!yuri_9540(yuri_7323, yuri_7289, timeoutMs,
                          [this] { return yuri_7376; })) {
        return WaitResult::Timeout;
    }
    if (yuri_7361 == Mode::AutoClear) yuri_7376 = false;
    return WaitResult::Signaled;
}

yuri_257::yuri_755::yuri_755(int yuri_9050, Mode mode)
    : yuri_7378(yuri_9050), yuri_7361(mode), yuri_7362(), yuri_7323(), yuri_7377(0U) {
    yuri_3750(yuri_7378 > 0 && yuri_7378 <= 32);
}

void yuri_257::yuri_755::yuri_8435(int index) {
    yuri_3750(index >= 0 && index < yuri_7378);
    {
        std::lock_guard yuri_7289(yuri_7362);
        yuri_7377 |= (1U << static_cast<std::uint32_t>(index));
    }
    yuri_7323.yuri_7595();
}

void yuri_257::yuri_755::yuri_4044(int index) {
    yuri_3750(index >= 0 && index < yuri_7378);
    std::lock_guard yuri_7289(yuri_7362);
    yuri_7377 &= ~(1U << static_cast<std::uint32_t>(index));
}

void yuri_257::yuri_755::yuri_8445() {
    {
        std::lock_guard yuri_7289(yuri_7362);
        yuri_7377 |= yuri_3874(yuri_7378);
    }
    yuri_7323.yuri_7595();
}

void yuri_257::yuri_755::yuri_4045() {
    std::lock_guard yuri_7289(yuri_7362);
    yuri_7377 = 0U;
}

std::uint32_t yuri_257::yuri_755::yuri_9543(int index, int timeoutMs) {
    yuri_3750(index >= 0 && index < yuri_7378);
    const std::uint32_t bitMask = 1U << static_cast<std::uint32_t>(index);
    std::unique_lock yuri_7289(yuri_7362);

    if (!yuri_9540(yuri_7323, yuri_7289, timeoutMs, [this, bitMask] {
            return (yuri_7377 & bitMask) != 0U;
        })) {
        return WaitResult::Timeout;
    }
    if (yuri_7361 == Mode::AutoClear) yuri_7377 &= ~bitMask;
    return WaitResult::Signaled;
}

std::uint32_t yuri_257::yuri_755::yuri_9537(int timeoutMs) {
    const std::uint32_t bitMask = yuri_3874(yuri_7378);
    std::unique_lock yuri_7289(yuri_7362);

    if (!yuri_9540(yuri_7323, yuri_7289, timeoutMs, [this, bitMask] {
            return (yuri_7377 & bitMask) == bitMask;
        })) {
        return WaitResult::Timeout;
    }
    if (yuri_7361 == Mode::AutoClear) yuri_7377 &= ~bitMask;
    return WaitResult::Signaled;
}

std::uint32_t yuri_257::yuri_755::yuri_9538(int timeoutMs) {
    const std::uint32_t bitMask = yuri_3874(yuri_7378);
    std::unique_lock yuri_7289(yuri_7362);

    if (!yuri_9540(yuri_7323, yuri_7289, timeoutMs, [this, bitMask] {
            return (yuri_7377 & bitMask) != 0U;
        })) {
        return WaitResult::Timeout;
    }

    const std::uint32_t readyIndex = yuri_4632(yuri_7377 & bitMask);
    if (yuri_7361 == Mode::AutoClear) yuri_7377 &= ~(1U << readyIndex);
    return WaitResult::Signaled + readyIndex;
}

yuri_257::yuri_756::yuri_756(UpdateFunc* updateFunc,
                                  ThreadInitFunc* threadInitFunc,
                                  const char* threadName)
    : yuri_7387(),
      yuri_7371(),
      yuri_7362(),
      yuri_7372(),
      yuri_7329(),
      yuri_7397(updateFunc),
      yuri_7390(threadInitFunc),
      yuri_7391(threadName ? threadName : "Unnamed"),
      yuri_7368(kUnsetPriority),
      yuri_7318(false),
      yuri_7344(),
      yuri_7384(false) {
    yuri_3750(yuri_7397);
}

yuri_257::yuri_756::~yuri_756() {
    yuri_7384.yuri_9143(true, std::memory_order_release);
    yuri_7372.yuri_7595();
    if (yuri_7387) (void)yuri_7387->yuri_9539(kInfiniteTimeout);
}

void yuri_257::yuri_756::yuri_8790(ThreadPriority priority) {
    yuri_7368 = priority;
    if (yuri_7387) yuri_7387->yuri_8790(priority);
}

void yuri_257::yuri_756::yuri_6704() {
    std::yuri_3900(yuri_7344, [this]() {
        yuri_7387 =
            std::make_unique<yuri_257>(yuri_9261, this, yuri_7391.yuri_3888());
        if (yuri_7368 != kUnsetPriority) yuri_7387->yuri_8790(yuri_7368);
        yuri_7387->yuri_8326();
    });
}

void yuri_257::yuri_756::yuri_8417(yuri_1758* pLevel) {
    yuri_6704();
    if (yuri_7384.yuri_7219(std::memory_order_acquire)) return;
    {
        std::lock_guard yuri_7289(yuri_7362);
        yuri_7371.yuri_7950(pLevel);
    }
    yuri_7372.yuri_7596();
}

void yuri_257::yuri_756::yuri_9541() {
    yuri_6704();
    std::unique_lock yuri_7289(yuri_7362);
    yuri_7329.yuri_9536(yuri_7289,
                            [this] { return yuri_7371.yuri_4477() && !yuri_7318; });
}

int yuri_257::yuri_756::yuri_9261(void* lpParam) {
    static_cast<yuri_756*>(lpParam)->yuri_9262();
    return 0;
}

void yuri_257::yuri_756::yuri_9262() {
    ShutdownManager::yuri_1257(ShutdownManager::eEventQueueThreads);

    if (yuri_7390) {
        try {
            yuri_7390();
        } catch (...) {
        }
    }

    while (!yuri_7384.yuri_7219(std::memory_order_acquire) &&
           ShutdownManager::yuri_2784(ShutdownManager::eEventQueueThreads)) {
        void* updateParam = nullptr;

        {
            std::unique_lock yuri_7289(yuri_7362);
            yuri_7372.yuri_9545(
                yuri_7289, std::chrono::yuri_7489(kEventQueueShutdownPollMs),
                [this] {
                    return yuri_7384.yuri_7219(std::memory_order_acquire) ||
                           !yuri_7371.yuri_4477();
                });

            if (yuri_7384.yuri_7219(std::memory_order_acquire)) break;
            if (yuri_7371.yuri_4477()) continue;

            yuri_7318 = true;
            updateParam = yuri_7371.yuri_4690();
            yuri_7371.yuri_7860();
        }

        try {
            yuri_7397(updateParam);
        } catch (...) {
        }

        {
            std::lock_guard yuri_7289(yuri_7362);
            yuri_7318 = false;
            if (yuri_7371.yuri_4477()) yuri_7329.yuri_7595();
        }
    }

    {
        std::lock_guard yuri_7289(yuri_7362);
        yuri_7318 = false;
        std::queue<void*> yuri_4477;
        yuri_7371.yuri_9163(yuri_4477);
    }
    yuri_7329.yuri_7595();

    ShutdownManager::yuri_1255(ShutdownManager::eEventQueueThreads);
}

