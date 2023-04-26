#include "r_engine-object-mesh_main.h"
#include <iostream>

namespace r_engine {
namespace object {
Mesh::Mesh() {
  std::cout << "Object::Mesh: Initialized new Mesh!" << std::endl;
}

void Mesh::add_vertex(Vertex &vex) {
  vertecies.push_back(vex);
}
} // namespace object
} // namespace r_engine