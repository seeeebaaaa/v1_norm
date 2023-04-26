#ifndef R_ENGINE_SCENE_SCENE_MAIN
#define R_ENGINE_SCENE_SCENE_MAIN
/**
 * Main scene class. Contains everything
 */
#include "../r_engine-object/r_engine-object-object/r_engine-object-object_main.h"
#include "../r_engine-render/r_engine-render-render/r_engine-render-render_main.hpp"
#include <png++/image.hpp>
#include <png++/rgba_pixel.hpp>
#include <string>
#include <vector>

namespace r_engine {
class scene {
  // info:
  std::string scene_name;

  // objects
  int object_id = 0;
  object::object *focused_cam;
  std::vector<object::object *> *objects;

  // rendering:
  render::render rendering;

public:
  // inits
  explicit scene();
  explicit scene(const std::string &name); // creates scene with given name

  // destruct
  ~scene();

  // scene information
  std::string &name();                // get scene name
  void name(const std::string &name); // set scene name

  // object control
  object::object &object_new(std::string name, object::object_type type); // creates a new object and returns reference + type [t_Mesh, t_Light, t_Camera]
  object::object object_delete(object::object &obj);                      // returns refernced object and returns as value

  // rendering
  void render_resolution(int width, int height);
  png::image<png::rgba_pixel> &render();
};

} // namespace r_engine
#endif