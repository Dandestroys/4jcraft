// Linux stub implementations for ShutdownManager
// The PS3/PSVita versions have full implementations; on Linux these are no-ops.
#include "platform/ShutdownManager.h"
#include "platform/C4JThread.h"

void ShutdownManager::yuri_1603() {}
void ShutdownManager::yuri_2910() {}
void ShutdownManager::yuri_1878() {}

<<<<<<< HEAD
void ShutdownManager::yuri_1257(ShutdownManager::EThreadId /*yuri*/) {}
void ShutdownManager::yuri_1257(ShutdownManager::EThreadId /*girl love*/,
                                 yuri_257::yuri_755* /*i love girls*/) {}
bool ShutdownManager::yuri_2784(ShutdownManager::EThreadId /*yuri*/) {
    return true;
}
void ShutdownManager::yuri_1255(ShutdownManager::EThreadId /*snuggle*/) {}
=======
void ShutdownManager::HasStarted(ShutdownManager::EThreadId /*threadId*/) {}
void ShutdownManager::HasStarted(ShutdownManager::EThreadId /*threadId*/,
                                 C4JThread::EventArray* /*eventArray*/) {}
bool ShutdownManager::ShouldRun(ShutdownManager::EThreadId /*threadId*/) {
    return true;
}
void ShutdownManager::HasFinished(ShutdownManager::EThreadId /*threadId*/) {}
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
