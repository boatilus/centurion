#include "cursor.hpp"

#include <type_traits>

#include "exception.hpp"

namespace centurion {

static_assert(std::is_final_v<cursor>);
static_assert(std::is_nothrow_move_constructible_v<cursor>);
static_assert(std::is_nothrow_move_assignable_v<cursor>);
static_assert(!std::is_copy_constructible_v<cursor>);
static_assert(!std::is_copy_assignable_v<cursor>);

cursor::cursor(nn_owner<SDL_Cursor*> sdlCursor) noexcept : m_cursor{sdlCursor}
{}

cursor::cursor(system_cursor id)
    : m_cursor{SDL_CreateSystemCursor(static_cast<SDL_SystemCursor>(id))}
{
  if (!m_cursor) {
    throw sdl_error{"Failed to create system cursor"};
  }
}

cursor::cursor(const surface& surface, const ipoint& hotspot)
    : m_cursor{SDL_CreateColorCursor(surface.get(), hotspot.x(), hotspot.y())}
{
  if (!m_cursor) {
    throw sdl_error{"Failed to create color cursor"};
  }
}

void cursor::enable() noexcept
{
  SDL_SetCursor(m_cursor.get());
}

auto cursor::is_enabled() const noexcept -> bool
{
  return SDL_GetCursor() == m_cursor.get();
}

void cursor::force_redraw() noexcept
{
  SDL_SetCursor(nullptr);
}

void cursor::reset() noexcept
{
  SDL_SetCursor(SDL_GetDefaultCursor());
}

void cursor::set_visible(bool visible) noexcept
{
  SDL_ShowCursor(visible ? SDL_ENABLE : SDL_DISABLE);
}

auto cursor::visible() noexcept -> bool
{
  return SDL_ShowCursor(SDL_QUERY) == SDL_ENABLE;
}

}  // namespace centurion
