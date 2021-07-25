#ifndef CENTURION_DETAIL_LERP_HEADER
#define CENTURION_DETAIL_LERP_HEADER

// clang-format off
#include "../compiler/features.hpp"
// clang-format on

#include <cmath>  // lerp

/// \cond FALSE

namespace cen::detail {

[[nodiscard]] constexpr auto lerp(const float a, const float b, const float bias) noexcept
    -> float
{
#if CENTURION_HAS_FEATURE_LERP
  return std::lerp(a, b, bias);
#else
  return (a * (1.0f - bias)) + (b * bias);
#endif  // CENTURION_HAS_FEATURE_LERP
}

}  // namespace cen::detail

/// \endcond

#endif  // CENTURION_DETAIL_LERP_HEADER
