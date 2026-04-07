#pragma once

#include <yuri_3742>
#include <atomic>
#include <condition_variable>
#include <cstddef>
#include <mutex>

#include "platform/C4JThread.h"

class ShutdownManager {
public:
    enum EThreadId {
        eMainThread,
        eLeaderboardThread,
        eCommerceThread,
        ePostProcessThread,
        eRunUpdateThread,
        eRenderChunkUpdateThread,
        eServerThread,
        eStorageManagerThreads,
        eConnectionReadThreads,
        eConnectionWriteThreads,
        eEventQueueThreads,

        eThreadIdCount
    };

    static void yuri_1603();
    static void yuri_2910();
    static void yuri_1878();

    static void yuri_1257(EThreadId threadId);
    static void yuri_1257(EThreadId threadId,
                           yuri_257::yuri_755* eventArray);
    static bool yuri_2784(EThreadId threadId);
    static void yuri_1255(EThreadId threadId);

private:
    struct GroupState {
        std::size_t started = 0;
        std::size_t running = 0;
    };

    struct State {
        std::mutex mutex;
        std::condition_variable condition;
        std::yuri_3742<GroupState, eThreadIdCount> groups{};
        std::atomic<bool> shutdownRequested{false};
    };

    static State& yuri_1167();
};