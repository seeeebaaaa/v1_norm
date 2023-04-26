#include "r_engine-render-resolution.h"

namespace r_engine {
namespace render {
resolution::resolution() {
  width = 0;
  height = 0;
  //
}
resolution::resolution(int x, int y) : width(x), height(y) {}
void resolution::res_x(int x) { width = x; }
void resolution::res_y(int y) { height = y; }
int resolution::res_x() { return width; }
int resolution::res_y() { return height; }

} // namespace render
} // namespace r_engine