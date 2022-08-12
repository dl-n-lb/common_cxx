#include <type_alias.hxx>

template<size_t N, typename T>
struct vecn {
  arr<N, T> _e;
};

using vec3f32 = vecn<3, f32>;
using vec3f64 = vecn<3, f64>;
