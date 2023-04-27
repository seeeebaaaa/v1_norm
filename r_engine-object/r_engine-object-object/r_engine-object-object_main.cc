#include "r_engine-object-object_main.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

namespace r_engine {
namespace object {
object::object(const std::string &in_name, object_type in_type) : type(in_type), name(in_name) {
}
object::~object() {}

// obj info
const std::string &object::get_name() {
  own_mesh.print_vertecies();
  return name;
}

// obj mod
/**
 * Sets the mesh and material of an object from a obj file [obv doesnt support everything; e.g.: all faces get assigned the last listed material rn]; FACES need to be in v/vt/vn format!!!
 */
object &object::set_obj(const std::string &obj_file_path) {
  assert(this->type == t_Mesh && "Error: Cant set Mesh of this Object, cause it is not from type t_Mesh!");
  assert(std::filesystem::exists("./assets/" + obj_file_path) && "Error: the obj does not exit!");
  path_to_obj_file = obj_file_path;
  own_mesh = Mesh();
  // read from .obj file:
  std::ifstream obj_file("./assets/" + obj_file_path);
  std::string line;
  std::string current_mat = "";
  while (getline(obj_file, line)) {
    // snip line
    std::stringstream line_stream(line);
    std::vector<std::string> line_snippets;
    std::string snippet;
    while (getline(line_stream, snippet, ' ')) {
      line_snippets.push_back(snippet);
    }
    if (line_snippets.size() == 0)
      continue; // blank line
    // interpret line
    if (line_snippets[0] == "v") {
      // vertex
      assert(line_snippets.size() >= 4 && "Error: Mistake in obj file! [not enought vertex coords]");
      Vertex vex;
      vex.x = std::stof(line_snippets[1]);
      vex.y = std::stof(line_snippets[2]);
      vex.z = std::stof(line_snippets[3]);
      vex.w = line_snippets.size() == 5 ? std::stof(line_snippets[4]) : 1.0;
      own_mesh.add_vertex(vex);
    } else if (line_snippets[0] == "vt") {
      // vertex texture coord
      assert(line_snippets.size() >= 3 && "Error: Mistake in obj file! [not enough vertext texture coords]");
      VertexTexture vt;
      vt.x = std::stof(line_snippets[1]);
      vt.y = std::stof(line_snippets[2]);
      own_mesh.add_vertexTexture(vt);
    } else if (line_snippets[0] == "vn") {
      // vertex normal
      assert(line_snippets.size() >= 4 && "Error: Mistake in obj file! [not enough vertext normal coords]");
      VertexNormal vn;
      vn.x = std::stof(line_snippets[1]);
      vn.y = std::stof(line_snippets[2]);
      vn.z = std::stof(line_snippets[3]);
      own_mesh.add_vertexNormal(vn);
    } else if (line_snippets[0] == "f") {
      // face
      assert(line_snippets.size() >= 4 && "Error: Mistake in obj file! [not enough face coords]");
      Face f;
      // split each point into segments
      for (std::string el : line_snippets) {
        if (el == "f")
          continue;
        std::stringstream s(el);
        std::string point;
        std::vector<int> point_value;
        while (getline(s, point, '/')) {
          point_value.push_back(std::stoi(point));
        }
        f.vertex_id.push_back(point_value[0]);
        f.vertexTexture_id.push_back(point_value[1]);
        f.vertexNormal_id.push_back(point_value[2]);
      }
      f.usemtl = current_mat;
      own_mesh.add_face(f);
    } else if (line_snippets[0] == "mtllib") {
      // matlib def
      assert(line_snippets.size() >= 2 && "Error: Mistake in obj file! [no mtllib specified]");
      path_to_mtl_file = line_snippets[1];
    } else if (line_snippets[0] == "usemtl") {
      // use material x for following faces
      assert(line_snippets.size() >= 2 && "Error: Mistake in obj file! [no usemtl specified]");
      current_mat = line_snippets[1];
    } else {
      // discard; e.g. comments
      continue;
    }
  }
  /**
   * Bake materials for all faces [get from respective .mtl file]
   */
  return *this;
}

} // namespace object
} // namespace r_engine