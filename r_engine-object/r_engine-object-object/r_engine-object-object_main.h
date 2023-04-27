#ifndef R_ENGINE_OBJECT_OBJECT_OBJECT_MAIN
#define R_ENGINE_OBJECT_OBJECT_OBJECT_MAIN
/**
 * A Object in the scene; Contains mesh, material and infos
 */
#include "../r_engine-object-material/r_engine-object-material_main.h"
#include "../r_engine-object-mesh/r_engine-object-mesh_main.h"
#include <string>

namespace r_engine {
namespace object {
enum object_type {
  t_Camera,
  t_Mesh,
  t_Light
};

class object {
  object_type type;
  std::string name;
  std::string path_to_obj_file;
  std::string path_to_mtl_file;
  // obj substance
  Mesh own_mesh;
  Material own_materials;

public:
  object(const std::string &name, object_type); // create new object
  ~object();
  // obj info
  const object_type &get_type();
  const std::string &get_name();
  // obj mod
  object &set_obj(const std::string &obj_file_path); // sets the mesh and material of the obj from .obj file; asserts if obj of non mesh type
  // object(int a); // with file
};
} // namespace object
} // namespace r_engine

#endif