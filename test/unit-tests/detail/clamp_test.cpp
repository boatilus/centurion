/*
 * MIT License
 *
 * Copyright (c) 2019-2022 Albin Johansson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <gtest/gtest.h>

#include "centurion/detail/stdlib.hpp"

TEST(Clamp, Correctness)
{
  ASSERT_EQ(1, cen::detail::clamp(1, 0, 1));
  ASSERT_EQ(1, cen::detail::clamp(1, 1, 1));
  ASSERT_EQ(1, cen::detail::clamp(1, 0, 2));
  ASSERT_EQ(1, cen::detail::clamp(1, -1, 2));

  ASSERT_EQ(2, cen::detail::clamp(3, 0, 2));
  ASSERT_EQ(0, cen::detail::clamp(-1, 0, 2));

  ASSERT_EQ(-2, cen::detail::clamp(-2, -3, -1));
  ASSERT_EQ(-3, cen::detail::clamp(-4, -3, -1));
  ASSERT_EQ(-1, cen::detail::clamp(0, -3, -1));
}
