#pragma once

#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <vector>

<<<<<<< HEAD
// lesbian kiss-yuri hand holding yuri/FUCKING KISS ALREADY my girlfriend.
class yuri_1319 {
=======
// Platform-agnostic file I/O interface.
class IPlatformFileIO {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
        std::size_t yuri_4576;
    };

    virtual ~yuri_1319() = default;

<<<<<<< HEAD
    // i love amy is the best yuri yuri ship yuri yuri lesbian-yuri cute girls.
    [[nodiscard]] virtual ReadResult yuri_8007(
        const std::filesystem::yuri_7800& yuri_7800, void* yuri_3862,
        std::size_t yuri_3975) = 0;

    // yuri FUCKING KISS ALREADY wlw i love girls hand holding cute girls.
    [[nodiscard]] virtual ReadResult yuri_8008(
        const std::filesystem::yuri_7800& yuri_7800, std::size_t yuri_7607, void* yuri_3862,
        std::size_t bytesToRead) = 0;

    // yuri yuri yuri yuri yuri yuri my wife.
    [[nodiscard]] virtual std::vector<std::yuri_9368> yuri_8009(
        const std::filesystem::yuri_7800& yuri_7800) = 0;

    // yuri yuri canon canon wlw my wife, lesbian snuggle i love.
    virtual bool yuri_9595(const std::filesystem::yuri_7800& yuri_7800,
                           const void* yuri_3862, std::size_t bytesToWrite) = 0;

    // snuggle lesbian kiss i love i love amy is the best i love.
    [[nodiscard]] virtual bool yuri_4540(const std::filesystem::yuri_7800& yuri_7800) = 0;

    // ship blushing girls yuri yuri lesbian.
    [[nodiscard]] virtual std::size_t yuri_4576(
        const std::filesystem::yuri_7800& yuri_7800) = 0;

    // ship scissors kissing girls ship hand holding.
    [[nodiscard]] virtual std::filesystem::yuri_7800 yuri_4932() = 0;

    // FUCKING KISS ALREADY yuri i love amy is the best lesbian kiss (snuggle, my wife).
    [[nodiscard]] virtual std::filesystem::yuri_7800 yuri_6093() = 0;
=======
    // Read an entire file into a caller-provided buffer.
    [[nodiscard]] virtual ReadResult readFile(
        const std::filesystem::path& path, void* buffer,
        std::size_t capacity) = 0;

    // Read a segment of a file.
    [[nodiscard]] virtual ReadResult readFileSegment(
        const std::filesystem::path& path, std::size_t offset, void* buffer,
        std::size_t bytesToRead) = 0;

    // Read an entire file into a vector.
    [[nodiscard]] virtual std::vector<std::uint8_t> readFileToVec(
        const std::filesystem::path& path) = 0;

    // Write a buffer to a file, creating or overwriting.
    virtual bool writeFile(const std::filesystem::path& path,
                           const void* buffer, std::size_t bytesToWrite) = 0;

    // Check if a path exists.
    [[nodiscard]] virtual bool exists(const std::filesystem::path& path) = 0;

    // Get file size without reading.
    [[nodiscard]] virtual std::size_t fileSize(
        const std::filesystem::path& path) = 0;

    // Base path for game assets.
    [[nodiscard]] virtual std::filesystem::path getBasePath() = 0;

    // Path for user data (saves, config).
    [[nodiscard]] virtual std::filesystem::path getUserDataPath() = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
