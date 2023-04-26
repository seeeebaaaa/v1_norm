#include "r_engine-render-render_main.hpp"
#include "../../r_engine-utility/r_engine-utility-colors/r_engine-utility-colors_main.h"
#include <cassert>
#include <png++/image.hpp>
#include <png++/rgba_pixel.hpp>

namespace r_engine {
namespace render {
render::render() {
  reso.res_x(100);
  reso.res_y(100);
}
render::render(int res_x, int res_y) {
  assert(res_x > 0 && res_y > 0 && "The resolution need to be at least 1!");
  reso.res_x(res_x);
  reso.res_y(res_y);
}
void render::res(int res_x, int res_y) {
  assert(res_x > 0 && res_y > 0 && "The resolution need to be at least 1!");
  reso.res_x(res_x);
  reso.res_y(res_y);
}
int render::res_x() {
  return reso.res_x();
}
int render::res_y() {
  return reso.res_y();
}

png::image<png::rgba_pixel> &render::image() {
  return last_image;
}

void render::cast(const std::vector<object::object *> &scene_objects, const object::object &focused_cam) {
  // just some garbage so that i can return sth and compile
  png::image<png::rgba_pixel> a(reso.res_x(), reso.res_y());
  // for test purpose fill with test data
  std::cout << "Using canvas " << reso.res_x() << "x" << reso.res_y() << std::endl;
  std::cout << "Using img " << a.get_width() << "x" << a.get_height() << std::endl;
  for (int x = 0; x < int(a.get_width()); x++) {
    for (int y = 0; y < int(a.get_height()); y++) {
      // always remember to convert to double when doing operations with colors/size, cause uint_32 will cause overflows and not good stuff
      double height = double(a.get_height());
      double width = double(a.get_width());
      png::rgba_pixel pixel;
      pixel.red = x * (255 / width);
      pixel.green = y * (255 / height);
      pixel.blue = x * y * (255 / (width * height));
      pixel.alpha = 255;
      a[y][x] = pixel;
    }
    last_image = a;
  }
}
} // namespace render
} // namespace r_engine