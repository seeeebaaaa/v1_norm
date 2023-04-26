#ifndef R_ENGINE_OBJECT_MESH_MAIN
#define R_ENGINE_OBJECT_MESH_MAIN
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
  int vertex_id;
  int vertexTexture_id;
  int vertexNormal_id;
};

class Mesh {
  std::vector<Vertex> vertecies;
  std::vector<VertexTexture> vertex_textures;
  std::vector<VertexNormal> vertex_normals;
  std::vector<Face> faces;

public:
  Mesh();
  void add_vertex(Vertex &vex);
};
} // namespace object
} // namespace r_engine

#endif