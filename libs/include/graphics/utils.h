#pragma once

struct Colour {
  float r;
  float g;
  float b;
};

namespace colour {
constexpr Colour Black{0.0, 0.0, 0.0};
constexpr Colour Red{1.0, 0.0, 0.0};
constexpr Colour Yellow{1.0, 1.0, 0.0};
constexpr Colour Green{0.0, 1.0, 0.0};
constexpr Colour Blue{0.0, 0.0, 1.0};
constexpr Colour Cyan{0.0, 1.0, 1.0};
constexpr Colour Magenta{1.0, 0.0, 1.0};
constexpr Colour White{1.0, 1.0, 1.0};
} // namespace colour
