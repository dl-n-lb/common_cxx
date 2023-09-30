#include <gtest/gtest.h>

#include "type_alias.hxx"
#include "vecn.hxx"
#include "cmd_opts.hxx"

// CMD PARSER TESTS
TEST(CmdParserTest, MacroTest) {
  EXPECT_STREQ(with_default(100), "100");
}

// VECTOR TESTS
TEST(VectorTest, VectorConstructionTest) {
  vec3f32 v = {{1, 2, 3}};
  ASSERT_FLOAT_EQ(v[0], 1);
  ASSERT_FLOAT_EQ(v[1], 2);
  ASSERT_FLOAT_EQ(v[2], 3);
  auto v2 = vec3t(4, 5, 6);
  ASSERT_FLOAT_EQ(v2[0], 4);
  ASSERT_FLOAT_EQ(v2[1], 5);
  ASSERT_FLOAT_EQ(v2[2], 6);
}

TEST(VectorTest, VectorLengthTest) {
  vec3f32 v{{3, 4, 5}};
  ASSERT_FLOAT_EQ(length2(v), 50);
  ASSERT_FLOAT_EQ(length(v), 5 * sqrt(2));
}

TEST(VectorTest, VectorAdditionTest) {
  auto v = vec3t(12, 0, 13);
  auto v2 = vec3t(13, 25, 12);
  
  auto v3 = v + v2;
  ASSERT_FLOAT_EQ(v3[0], 25);
  ASSERT_FLOAT_EQ(v3[1], 25);
  ASSERT_FLOAT_EQ(v3[2], 25);

  v += v2;
  ASSERT_FLOAT_EQ(v[0], 25);
  ASSERT_FLOAT_EQ(v[1], 25);
  ASSERT_FLOAT_EQ(v[2], 25);
}

TEST(VectorTest, VectorSubtractionTest) {
  auto v = vec3t(-1.0, 12.5, 100.123);
  auto v2 = vec3t(-5.0, 8.0, 100.0);
 
  auto v3 = v - v2;
  ASSERT_FLOAT_EQ(v3[0], 4);
  ASSERT_FLOAT_EQ(v3[1], 4.5);
  ASSERT_FLOAT_EQ(v3[2], 0.123);
}
