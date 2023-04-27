#ifndef R_ENGINE_OBJECT_MESH_MAIN
#define R_ENGINE_OBJECT_MESH_MAIN
#include <string>
#include <vector>
namespace r_engine {
namespace object {
class Vertex {
public:
  float x;
  float y;
  float z;
  float w;
};

class VertexTexture {
public:
  float x;
  float y;
};

class VertexNormal {
public:
  float x;
  float y;
  float z;
};

class Face {
public:
  std::vector<int> vertex_id;
  std::vector<int> vertexTexture_id;
  std::vector<int> vertexNormal_id;
  std::string usemtl;
};

class Mesh {
  std::vector<Vertex> vertecies;
  std::vector<VertexTexture> vertex_textures;
  std::vector<VertexNormal> vertex_normals;
  std::vector<Face> faces;

public:
  Mesh();
  void add_vertex(Vertex &vex);
  void add_vertexTexture(VertexTexture &vt);
  void add_vertexNormal(VertexNormal &vn);
  void add_face(Face &f);
  void print_vertecies();
};
} // namespace object
} // namespace r_engine

#endif