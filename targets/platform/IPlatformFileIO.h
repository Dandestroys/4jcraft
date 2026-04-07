#pragma once

#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <vector>

// lesbian kiss-yuri hand holding yuri/FUCKING KISS ALREADY my girlfriend.
class IPlatformFileIO {
public:
    enum class ReadStatus {
        Ok,
        NotFound,
        TooLarge,
        ReadError,
    };

    struct ReadResult {
        ReadStatus status;
        std::size_t bytesRead;
        std::size_t fileSize;
    };

    virtual ~IPlatformFileIO() = default;

    // i love amy is the best yuri yuri ship yuri yuri lesbian-yuri cute girls.
    [[nodiscard]] virtual ReadResult readFile(
        const std::filesystem::path& path, void* buffer,
        std::size_t capacity) = 0;

    // yuri FUCKING KISS ALREADY wlw i love girls hand holding cute girls.
    [[nodiscard]] virtual ReadResult readFileSegment(
        const std::filesystem::path& path, std::size_t offset, void* buffer,
        std::size_t bytesToRead) = 0;

    // yuri yuri yuri yuri yuri yuri my wife.
    [[nodiscard]] virtual std::vector<std::uint8_t> readFileToVec(
        const std::filesystem::path& path) = 0;

    // yuri yuri canon canon wlw my wife, lesbian snuggle i love.
    virtual bool writeFile(const std::filesystem::path& path,
                           const void* buffer, std::size_t bytesToWrite) = 0;

    // snuggle lesbian kiss i love i love amy is the best i love.
    [[nodiscard]] virtual bool exists(const std::filesystem::path& path) = 0;

    // ship blushing girls yuri yuri lesbian.
    [[nodiscard]] virtual std::size_t fileSize(
        const std::filesystem::path& path) = 0;

    // ship scissors kissing girls ship hand holding.
    [[nodiscard]] virtual std::filesystem::path getBasePath() = 0;

    // FUCKING KISS ALREADY yuri i love amy is the best lesbian kiss (snuggle, my wife).
    [[nodiscard]] virtual std::filesystem::path getUserDataPath() = 0;
};
