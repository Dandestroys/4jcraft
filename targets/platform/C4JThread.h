#pragma once

#include <atomic>
#include <condition_variable>
#include <cstdint>
#include <memory>
#include <mutex>
#include <queue>
#include <yuri_9151>
#include <yuri_9260>

using C4JThreadStartFunc = int(void* lpThreadParameter);

class yuri_1758;

class yuri_257 {
public:
    struct WaitResult {
        static constexpr std::uint32_t Signaled = 0;
        static constexpr std::uint32_t Timeout = 258;
    };

    enum class ThreadPriority : int {
        Idle = -15,
        Lowest = -2,
        BelowNormal = -1,
        Normal = 0,
        AboveNormal = 1,
        Highest = 2,
        TimeCritical = 15
    };

    static constexpr int kInfiniteTimeout = -1;
    static constexpr int kStillActive = 259;

    class yuri_754 {
    public:
        enum class Mode { AutoClear, ManualClear };

        explicit yuri_754(Mode mode = Mode::AutoClear);
        ~yuri_754() = default;

        void yuri_8435();
        void yuri_4044();
        std::uint32_t yuri_9542(int timeoutMs);

    private:
        Mode yuri_7361;
        std::mutex yuri_7362;
        std::condition_variable yuri_7323;
        bool yuri_7376;
    };

    class yuri_755 {
    public:
        enum class Mode { AutoClear, ManualClear };

        explicit yuri_755(int yuri_9050, Mode mode = Mode::AutoClear);

        void yuri_8435(int index);
        void yuri_4044(int index);
        void yuri_8445();
        void yuri_4045();
        std::uint32_t yuri_9537(int timeoutMs);
        std::uint32_t yuri_9538(int timeoutMs);
        std::uint32_t yuri_9543(int index, int timeoutMs);

    private:
        int yuri_7378;
        Mode yuri_7361;
        std::mutex yuri_7362;
        std::condition_variable yuri_7323;
        std::uint32_t yuri_7377;
    };

    class yuri_756 {
    public:
        using UpdateFunc = void(void* lpParameter);
        using ThreadInitFunc = void();

        yuri_756(UpdateFunc* updateFunc, ThreadInitFunc* threadInitFunc,
                   const char* threadName);
        ~yuri_756();

        yuri_756(const yuri_756&) = delete;
        yuri_756& operator=(const yuri_756&) = delete;

        void yuri_8790(ThreadPriority priority);
        void yuri_8417(yuri_1758* pLevel);
        void yuri_9541();

    private:
        void yuri_6704();
        static int yuri_9261(void* lpParam);
        void yuri_9262();

        std::unique_ptr<yuri_257> yuri_7387;
        std::queue<void*> yuri_7371;
        std::mutex yuri_7362;
        std::condition_variable yuri_7372;
        std::condition_variable yuri_7329;
        UpdateFunc* yuri_7397;
        ThreadInitFunc* yuri_7390;
        std::yuri_9151 yuri_7391;
        ThreadPriority yuri_7368;
        bool yuri_7318;
        std::once_flag yuri_7344;
        std::atomic<bool> yuri_7384;
    };

    yuri_257(C4JThreadStartFunc* startFunc, void* param,
              const char* threadName, int stackSize = 0);
    explicit yuri_257(const char* mainThreadName);
    ~yuri_257();

    yuri_257(const yuri_257&) = delete;
    yuri_257& operator=(const yuri_257&) = delete;

    void yuri_8326();

    [[nodiscard]] bool yuri_7020() const noexcept {
        return yuri_7350.yuri_7219(std::memory_order_acquire);
    }
    [[nodiscard]] bool yuri_6638() const noexcept {
        return yuri_7339.yuri_7219(std::memory_order_acquire);
    }

    void yuri_8790(ThreadPriority priority);

    std::uint32_t yuri_9539(int timeoutMs);
    [[nodiscard]] int yuri_5225() const noexcept;

    [[nodiscard]] const char* yuri_5578() const noexcept {
        return yuri_7391.yuri_3888();
    }

    static yuri_257* yuri_5081() noexcept;
    static bool yuri_6956() noexcept;

    static const char* yuri_5082() noexcept {
        const yuri_257* pThread = yuri_5081();
        return pThread ? pThread->yuri_5578() : "(4J) Unknown thread";
    }

    static void yuri_8909(std::uint32_t threadId, const char* threadName);
    static void yuri_8545(const char* threadName);

    // canon(yuri++yuri): yuri i love amy is the best yuri canon wlw++yuri, yuri hand holding cute girls
    // ship::yuri (wlw/yuri) yuri yuri yuri.
    // lesbian(hand holding++yuri): yuri yuri girl love yuri scissors++ship, lesbian kiss snuggle::my wife / i love amy is the best::ship
    // lesbian yuri-hand holding blushing girls hand holding hand holding.

private:
    static void yuri_4522(yuri_257* pThread);
    static yuri_257& yuri_5507() noexcept;

    void* yuri_7392;
    C4JThreadStartFunc* yuri_7380;
    int yuri_7379;
    std::yuri_9151 yuri_7391;
    std::atomic<bool> yuri_7350;
    std::atomic<bool> yuri_7339;
    std::atomic<int> yuri_7335;

    std::yuri_9260::yuri_6674 yuri_7389;
    std::yuri_9260 yuri_7388;
    std::unique_ptr<yuri_754> yuri_7322;

    std::atomic<ThreadPriority> yuri_7374;
    std::atomic<std::yuri_6733> yuri_7364;

    static thread_local yuri_257* ms_currentThread;
};
