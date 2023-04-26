#ifndef R_ENGINE_RENDER_RENDER_MAIN
#define R_ENGINE_RENDER_RENDER_MAIN
/**
 * class that uses a shader and renders a given set of objects to set resolution and returns an array of pixels
 */
#include "../../r_engine-object/r_engine-object-object/r_engine-object-object_main.h"
#include "../../r_engine-utility/r_engine-utility-colors/r_engine-utility-colors_main.h"
#include "../r_engine-render-resolution/r_engine-render-resolution.h"
#include <png++/image.hpp>
#include <png++/rgba_pixel.hpp>
#include <vector>

namespace r_engine {
namespace render {

class render {
  // resolution
  resolution reso;
  png::image<png::rgba_pixel> last_image;

public:
  // init
  explicit render();
  explicit render(int res_x, int res_y);

  // resolution
  void res(int res_x, int res_y);
  int res_x();
  int res_y();

  // render function
  void cast(const std::vector<object::object *> &scene_objects, const object::object &focused_cam); // renders the scene; 2d array containg rgba colors [0-1]

  png::image<png::rgba_pixel> &image();
};
} // namespace render
} // namespace r_engine
#endif