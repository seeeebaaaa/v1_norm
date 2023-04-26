#ifndef R_ENGINE_RENDER_RENDER_RESOLUTION
#define R_ENGINE_RENDER_RENDER_RESOLUTION
/**
 * Resolutiuon holding class
 */
namespace r_engine {
namespace render {
class resolution {
  int width;  // width
  int height; // height
public:
  resolution();
  resolution(int x, int y);
  int res_x();
  int res_y();
  void res_x(int x);
  void res_y(int y);
};
} // namespace render
} // namespace r_engine
#endif