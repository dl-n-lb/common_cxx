#include <stdint.h>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>

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
