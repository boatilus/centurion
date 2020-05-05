#ifndef CENTURION_RAM_SOURCE
#define CENTURION_RAM_SOURCE

#include "ram.h"

namespace centurion {
namespace system {

CENTURION_DEF
int RAM::get_size_mb() noexcept
{
  return SDL_GetSystemRAM();
}

CENTURION_DEF
int RAM::get_size_gb() noexcept
{
  return get_size_mb() / 1000;
}

}  // namespace system
}  // namespace centurion

#endif  // CENTURION_RAM_SOURCE