#include <type_alias.hxx>

template<typename T>
concept VecFriendly = requires(T a, T b) {
  { a += b } -> std::same_as<T&>;
  { a +  b } -> std::convertible_to<T>;
};

template<size_t N, VecFriendly T>
struct vecn {
  vecn(arr<N, T> l) : _e(l) {}
  vecn() : _e({}) {}

  const T operator[](size_t i) const {
    return _e[i];
  }

  T& operator[](size_t i) {
    return _e[i];
  }

private:
  arr<N, T> _e;
};

template<size_t N, VecFriendly T>
T length2(vecn<N, T> v) {
  T sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += v[i]*v[i];
  }

  return sum;
}

template<size_t N, VecFriendly T>
T length(vecn<N, T> v) {
  return sqrt(length2(v));
}

template<size_t N, VecFriendly T>
vecn<N, T> operator+(const vecn<N, T>& lhs, const vecn<N, T>& rhs) {
  vecn<N, T> result {};
  for (int i = 0; i < N; ++i) {
    result[i] = lhs[i] + rhs[i];
  }
  return result;
}

template<size_t N, VecFriendly T>
vecn<N, T> operator-(const vecn<N, T>& lhs, const vecn<N, T>& rhs) {
  vecn<N, T> result {};
  for (int i = 0; i < N; ++i) {
    result[i] = lhs[i] - rhs[i];
  }
  return result;
}

template<size_t N, VecFriendly T>
vecn<N, T>& operator+=(vecn<N, T>& lhs, const vecn<N, T>& rhs) {
  for (int i = 0; i < N; ++i) {
    lhs[i] += rhs[i];
  }
  return lhs;
}

template<size_t N, VecFriendly T>
vecn<N, T>& operator-=(vecn<N, T>& lhs, const vecn<N, T>& rhs) {
  for (int i = 0; i < N; ++i) {
    lhs[i] -= rhs[i];
  }
  return lhs;
}

using vec3f32 = vecn<3, f32>;
using vec3f64 = vecn<3, f64>;

template<VecFriendly T>
vecn<3, T> vec3t(T x, T y, T z) {
  return vecn<3, T>{{x, y, z}};
}
