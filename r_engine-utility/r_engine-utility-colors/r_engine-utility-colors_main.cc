#include "r_engine-utility-colors_main.h"
#include <vector>
namespace r_engine {
namespace utility {
rgba::rgba() {
  r = g = b = a = 0;
}
rgba::rgba(double _r, double _g, double _b) {
  r = _r;
  g = _g;
  b = _b;
  a = 0;
}
rgba::rgba(double _r, double _g, double _b, double _a) {
  r = _r;
  g = _g;
  b = _b;
  a = _a;
}

void rgba::color(double _r, double _g, double _b, double _a) {
  r = _r;
  g = _g;
  b = _b;
  a = _a;
}
void rgba::color(double _r, double _g, double _b) {
  r = _r;
  g = _g;
  b = _b;
  a = 0;
}

std::vector<double> rgba::color() {
  return {r, g, b, a};
}
double rgba::color_r() {
  return r;
}
double rgba::color_g() {
  return g;
}
double rgba::color_b() {
  return b;
}
double rgba::color_a() {
  return a;
}

} // namespace utility
} // namespace r_engine