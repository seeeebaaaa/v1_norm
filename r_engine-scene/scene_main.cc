#include "scene_main.h"
#include "../r_engine-object/r_engine-object-object/r_engine-object-object_main.h"
#include "../r_engine-render/r_engine-render-render/r_engine-render-render_main.hpp"
#include "../r_engine-utility/r_engine-utility-colors/r_engine-utility-colors_main.h"
#include <iostream>
#include <png++/image.hpp>
#include <png++/rgba_pixel.hpp>
#include <string>
#include <vector>

namespace r_engine {
/*
 * ====================
 * Construct & destruct
 * ====================
 */

scene::scene() : scene_name("Unnamed") {
  focused_cam = nullptr;
  objects = new std::vector<object::object *>();
  std::cout << "Scene: Initialized as 'Unnamed'." << std::endl;
}
scene::scene(const std::string &name) : scene_name(name) {
  focused_cam = nullptr;
  objects = new std::vector<object::object *>();
  std::cout << "Scene: Initialized as '" << scene_name << "'" << std::endl;
}

scene::~scene() {
  // clear object vector
  for (const object::object *a : *objects) {
    delete a;
  }
  delete objects;
}

/*
 * ==========
 * Scene info
 * ==========
 */

/**
 * sets scene name
 */
void scene::name(const std::string &name) {
  scene_name = name;
}
/**
 * Returns scene name
 */
std::string &scene::name() {
  return scene_name;
}

/**
 * ===============
 * Object handling
 * ===============
 */
object::object &scene::object_new(std::string name, object::object_type type) {
  object::object *new_obj = new object::object(name, type);
  objects->push_back(new_obj);
  return *new_obj;
}
object::object scene::object_delete(object::object &obj) {
  return obj;
}
/*
 * =========
 * Rendering
 * =========
 */

void scene::render_resolution(int x, int y) {
  rendering.res(x, y);
}

// renders current scene and returns it
png::image<png::rgba_pixel> &scene::render() {
  // render current image
  rendering.cast(*objects, *focused_cam);
  return rendering.image();
}

} // namespace r_engine
