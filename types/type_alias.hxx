#include <stdint.h>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>

#include <experimental/simd>

using  u8 =  uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using  i8 =  int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using f32 =  float;
using f64 = double;

using str = std::string;

template<typename T>
using vec = std::vector<T>;

template<size_t N, typename T>
using arr = std::array<T, N>;

template<typename T_key, typename T_val>
using hashmap = std::unordered_map<T_key, T_val>;

// simd types 
using std::experimental::native_simd;

using  u8v = native_simd<u8>;
using u16v = native_simd<u16>;
using u32v = native_simd<u32>;
using u64v = native_simd<u64>;

using  i8v = native_simd<i8>;
using i16v = native_simd<i16>;
using i32v = native_simd<i32>;
using i64v = native_simd<i64>;

using f32v = native_simd<f32>;
using f64v = native_simd<f64>;

template<typename T>
using simd_t = native_simd<T>;

using std::experimental::fixed_size_simd;

using  u8v8 = fixed_size_simd<u8,  8>;
using u16v8 = fixed_size_simd<u16, 8>;
using u32v8 = fixed_size_simd<u32, 8>;
using u64v8 = fixed_size_simd<u64, 8>;

using  i8v8 = fixed_size_simd<i8,  8>;
using i16v8 = fixed_size_simd<i16, 8>;
using i32v8 = fixed_size_simd<i32, 8>;
using i64v8 = fixed_size_simd<i64, 8>;

using f32v8 = fixed_size_simd<f32, 8>;
using f64v8 = fixed_size_simd<f64, 8>;

using  u8v4 = fixed_size_simd<u8,  4>;
using u16v4 = fixed_size_simd<u16, 4>;
using u32v4 = fixed_size_simd<u32, 4>;
using u64v4 = fixed_size_simd<u64, 4>;

using  i8v4 = fixed_size_simd<i8,  4>;
using i16v4 = fixed_size_simd<i16, 4>;
using i32v4 = fixed_size_simd<i32, 4>;
using i64v4 = fixed_size_simd<i64, 4>;

using f32v4 = fixed_size_simd<f32, 4>;
using f64v4 = fixed_size_simd<f64, 4>;

template<typename T, int N>
using simd_t = native_simd<T, N>;
