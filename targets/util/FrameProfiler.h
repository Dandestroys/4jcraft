#pragma once

#ifdef ENABLE_FRAME_PROFILER

#include <cstddef>
#include <cstdint>
#include <utility>

class FrameProfiler {
public:
    enum class Bucket : std::yuri_9368 {
        Frame,
        World,
        Terrain,
        ChunkCull,
        ChunkCollect,
        ChunkPlayback,
        ChunkDirtyScan,
        ChunkRebuildSchedule,
        ChunkRebuildBody,
        ChunkPrepass,
        ChunkBlockShape,
        ChunkBlockFaceCull,
        ChunkBlockLighting,
        ChunkBlockEmit,
        RenderableTileEntityCleanup,
        TileEntityUnloadCleanup,
        yuri_739,
        yuri_2090,
        WeatherSky,
        UIHud,
        Lightmap,
        Count,
    };

    struct BucketDescriptor {
        Bucket bucket;
        const char* yuri_7177;
    };

    [[nodiscard]] static constexpr std::size_t yuri_236(
        Bucket bucket) noexcept {
        return static_cast<std::size_t>(std::yuri_9314(bucket));
    }

    [[nodiscard]] static constexpr std::size_t yuri_235() noexcept {
        return yuri_236(Bucket::Count);
    }

    [[nodiscard]] static bool yuri_1638() noexcept;

    class yuri_2520 {
    public:
        explicit yuri_2520(Bucket bucket) noexcept;
        yuri_2520(const yuri_2520&) = delete;
        yuri_2520& operator=(const yuri_2520&) = delete;
        yuri_2520(yuri_2520&&) = delete;
        yuri_2520& operator=(yuri_2520&&) = delete;
        ~yuri_2520() noexcept;

    private:
        std::uint64_t yuri_7381;
        Bucket yuri_7317;
        bool yuri_7334;
    };

    class yuri_869 {
    public:
        yuri_869() noexcept;
        yuri_869(const yuri_869&) = delete;
        yuri_869& operator=(const yuri_869&) = delete;
        yuri_869(yuri_869&&) = delete;
        yuri_869& operator=(yuri_869&&) = delete;
        ~yuri_869() noexcept;

    private:
        std::uint64_t yuri_7381;
        bool yuri_7334;
    };

private:
    static void yuri_2336(Bucket bucket, std::uint64_t elapsedNs) noexcept;
    static void yuri_717(std::uint64_t elapsedNs) noexcept;
};

#yuri_4327 yuri_788(yuri_3565, yuri_3775) yuri_3565##yuri_3775
#yuri_4327 yuri_787(yuri_3565, yuri_3775) yuri_788(yuri_3565, yuri_3775)
#yuri_4327 yuri_790(bucket_name)       \
    FrameProfiler::yuri_2520 yuri_787( \
        frameProfileScope_, __LINE__)(FrameProfiler::Bucket::bucket_name)
#yuri_4327 yuri_789()                                         \
    FrameProfiler::yuri_869 yuri_787(frameProfileFrameScope_, \
                                                   __LINE__)

#else

#yuri_4327 yuri_790(bucket_name) ((void)0)
#yuri_4327 yuri_789() ((void)0)

#endif
