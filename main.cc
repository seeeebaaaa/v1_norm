/**
 * A project thingy to hanlde 3d objects and render them via perspective projection
 */

#include "compiled_assets/obj_cube.h"
#include "r_engine-object/r_engine-object-object/r_engine-object-object_main.h"
#include "r_engine-scene/scene_main.h"
#include <iostream>
#include <png++/image.hpp>
#include <png++/rgba_pixel.hpp>

/**
 * Debug incldue:
 */
#include <chrono>

int main(int argc, char **argv) {
  // create a new scene
  r_engine::scene main_scene("Nice Scene");

  r_engine::object::object &cuby = main_scene.object_new("Cuby", r_engine::object::t_Mesh);

  cuby.set_obj("cube.obj");
  std::cout << "Obj name is: " << cuby.get_name() << std::endl;

  // set render reso
  main_scene.render_resolution(200, 200);
  // render img + measure how long it takes to render
  auto t1 = std::chrono::high_resolution_clock::now();
  png::image<png::rgba_pixel> &pic = main_scene.render();
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "The image render took " << ((std::chrono::duration<double, std::milli>)(t2 - t1)).count()
            << "ms!" << std::endl;
  // write rendered image to file
  pic.write("out_pic.png");

  // exit
  return 0;
}