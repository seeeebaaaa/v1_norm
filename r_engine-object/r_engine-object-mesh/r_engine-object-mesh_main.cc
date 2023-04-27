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
void Mesh::add_vertexTexture(VertexTexture &vt) { vertex_textures.push_back(vt); }
void Mesh::add_vertexNormal(VertexNormal &vn) { vertex_normals.push_back(vn); }
void Mesh::add_face(Face &f) { faces.push_back(f); }
void Mesh::print_vertecies() {
  for (Vertex vex : vertecies) {
    std::cout << "v: [" << vex.x << "," << vex.y << "," << vex.z << "," << vex.z << "]" << std::endl;
  }
}
} // namespace object
} // namespace r_engine