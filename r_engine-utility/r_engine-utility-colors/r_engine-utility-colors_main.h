#ifndef R_ENGINE_UTILITY_COLORS_MAIN
#define R_ENGINE_UTILITY_COLORS_MAIN
#include <vector>
namespace r_engine {
namespace utility {
class rgba {
  double r;
  double g;
  double b;
  double a;

public:
  rgba();
  rgba(double r, double g, double b);
  rgba(double r, double g, double b, double a);

  void color(double r, double g, double b, double a);
  void color(double r, double g, double b);

  std::vector<double> color();
  double color_r();
  double color_g();
  double color_b();
  double color_a();
};
} // namespace utility
} // namespace r_engine

#endif