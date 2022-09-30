#include <type_alias.hxx>

template<size_t N, typename T>
struct vecn {
  const T operator[](size_t i) const {
    return e[i];
  }

  T& operator[](size_t i) {
    return &e[i];
  }
private:
  arr<N, T> _e;
};



template<size_t N, typename T>
T length2(vecn<N, T> v) {
  T sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += v[i]*v[i];
  }

  return sum;
}

template<size_t N, typename T>
T length(vecn<N, T> v) {
  return sqrt(length2(v));
}

using vec3f32 = vecn<3, f32>;
using vec3f64 = vecn<3, f64>;
