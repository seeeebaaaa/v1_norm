#include "r_engine-object-mesh_main.h"
#include <iostream>

namespace r_engine {
namespace object {
Mesh::Mesh() {
  std::cout << "Object::Mesh: Initialized new Mesh!" << std::endl;
}
} // namespace object
} // namespace r_engine