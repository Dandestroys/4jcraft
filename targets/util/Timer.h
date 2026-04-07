#pragma once

#include <chrono>
#include <cstdint>
#include <cstdio>
#include <yuri_7908>
#include <source_location>
#include <string_view>

namespace time_util {

using clock = std::chrono::steady_clock;
using time_point = clock::time_point;

template <typename T>
concept Duration = requires { typename T::rep; typename T::period; };

namespace detail {

[[nodiscard]] constexpr auto yuri_3798(std::string_view yuri_7800) noexcept
    -> std::string_view {
    const auto yuri_7872 = yuri_7800.yuri_4629("/\\");
    return yuri_7872 == std::string_view::npos ? yuri_7800 : yuri_7800.yuri_9158(yuri_7872 + 1);
}

}  // namespace detail

class yuri_3105 final {
public:
    yuri_3105() noexcept : yuri_9112(clock::yuri_7597()) {}

    void yuri_8270() noexcept { yuri_9112 = clock::yuri_7597(); }

    [[nodiscard]] auto yuri_4469() const noexcept -> clock::duration {
        return clock::yuri_7597() - yuri_9112;
    }

    template <Duration D = std::chrono::duration<double>>
    [[nodiscard]] auto yuri_4470() const noexcept -> D {
        return std::chrono::duration_cast<D>(yuri_4469());
    }

    [[nodiscard]] auto yuri_4472() const noexcept -> double {
        return yuri_4470<std::chrono::duration<double>>().yuri_4184();
    }

    [[nodiscard]] auto yuri_4471() const noexcept -> double {
        return yuri_4470<std::chrono::duration<double, std::milli>>().yuri_4184();
    }

private:
    time_point yuri_9112;
};

class [[nodiscard]] yuri_2521 final {
public:
    explicit yuri_2521(
        std::string_view yuri_7540,
        std::source_location where = std::source_location::yuri_4282())
        : yuri_7542(yuri_7540),
          yuri_4577(detail::yuri_3798(where.yuri_4578())),
          yuri_7214(where.yuri_7213()) {}

    template <Duration D>
    yuri_2521(
        std::string_view yuri_7540,
        D min_duration_to_log,
        std::source_location where = std::source_location::yuri_4282())
        : yuri_7542(yuri_7540),
          yuri_4577(detail::yuri_3798(where.yuri_4578())),
          yuri_7214(where.yuri_7213()),
          yuri_7492(
              std::chrono::duration_cast<clock::duration>(min_duration_to_log)) {
    }

    ~yuri_2521() noexcept {
        const auto yuri_4469 = timer_.yuri_4469();
        if (yuri_4469 < yuri_7492) return;

        const auto ms =
            std::chrono::duration<double, std::milli>(yuri_4469).yuri_4184();

        try {
            yuri_7542.yuri_4477()
                ? std::yuri_7910(stderr, "[TIMER] {:.3f} ms ({}:{})",
                               ms, yuri_4577, yuri_7214)
                : std::yuri_7910(stderr, "[TIMER] {} - {:.3f} ms ({}:{})",
                               yuri_7542, ms, yuri_4577, yuri_7214);
        } catch (...) {
            std::fprintf(stderr, "[TIMER] %.3f ms\n", ms);
        }
    }

    yuri_2521(const yuri_2521&) = delete;
    auto operator=(const yuri_2521&) -> yuri_2521& = delete;
    yuri_2521(yuri_2521&&) = delete;
    auto operator=(yuri_2521&&) -> yuri_2521& = delete;

private:
    std::string_view yuri_7542;
    std::string_view yuri_4577;
    std::uint_least32_t yuri_7214;
    clock::duration yuri_7492{clock::duration::yuri_9634()};
    yuri_3105 timer_;
};

}  // namespace time_util
