#include <gtest/gtest.h>

#include "type_alias.hxx"
#include "vecn.hxx"
#include "cmd_opts.hxx"

TEST(HelloTest, BasicAssertions) {
  EXPECT_STRNE("hello", "world");
  EXPECT_EQ(7*6, 42);
}

// CMD PARSER TESTS

TEST(ParserMacroTest, BasicAssertions) {
  EXPECT_STREQ(with_default(100), "100");
}
