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
  return name;
}

// obj mod
object &object::set_obj(const std::string &obj_file_path) {
  assert(this->type == t_Mesh && "Fatal Error: Cant set Mesh of this Object, cause it is not from type t_Mesh!");
  path_to_obj_file = obj_file_path;
  own_mesh = Mesh();
  // read from .obj file:
  std::ifstream obj_file("./assets/" + obj_file_path);
  std::string line;
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
    } else if (line_snippets[0] == "vt") {
      // vertex texture coord
    } else if (line_snippets[0] == "vn") {
      // vertex normal
    } else if (line_snippets[0] == "f") {
      // face
    } else if (line_snippets[0] == "mtllib") {
      // matlib def
    } else if (line_snippets[0] == "usemtl") {
      // use material x for following faces
    } else {
      // discard
      continue;
    }
  }
  return *this;
}

} // namespace object
} // namespace r_engine