#include "blend_mode.h"

#include <catch.hpp>

using namespace centurion;
using namespace centurion::video;

TEST_CASE("BlendMode enum values", "[BlendMode]")
{
  CHECK(BlendMode::None == SDL_BLENDMODE_NONE);
  CHECK(BlendMode::Blend == SDL_BLENDMODE_BLEND);
  CHECK(BlendMode::Add == SDL_BLENDMODE_ADD);
  CHECK(BlendMode::Mod == SDL_BLENDMODE_MOD);
  CHECK(BlendMode::Invalid == SDL_BLENDMODE_INVALID);

  CHECK(SDL_BLENDMODE_NONE == BlendMode::None);
  CHECK(SDL_BLENDMODE_BLEND == BlendMode::Blend);
  CHECK(SDL_BLENDMODE_ADD == BlendMode::Add);
  CHECK(SDL_BLENDMODE_MOD == BlendMode::Mod);
  CHECK(SDL_BLENDMODE_INVALID == BlendMode::Invalid);
}

TEST_CASE("BlendMode operator!=", "[BlendMode]")
{
  CHECK(BlendMode::None != SDL_BLENDMODE_MOD);
  CHECK(BlendMode::Blend != SDL_BLENDMODE_INVALID);

  CHECK(SDL_BLENDMODE_ADD != BlendMode::Blend);
  CHECK(SDL_BLENDMODE_MOD != BlendMode::Add);
}