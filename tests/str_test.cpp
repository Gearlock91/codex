#include <gtest/gtest.h>
#include <codex/str.hpp>

TEST(StrTrim, RemovesLeadingSpaces) {
    EXPECT_EQ(codex::str::trim("   hello"), "hello");
}