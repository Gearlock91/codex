#include <gtest/gtest.h>
#include <codex/str.hpp>

TEST(StrTrim, RemovesLeadingSpaces) {
    EXPECT_EQ(codex::str::trim("   hello"), "hello");
}

TEST(StrTrim, RemovesTrailingSpaces) {
    EXPECT_EQ(codex::str::trim("hello   "), "hello");
}

TEST(StrTrim, RemovesBothTrailingAndLeadingSpaces) {
    EXPECT_EQ(codex::str::trim("   hello   "), "hello");
}

TEST(StrTrim, RemoveLeadingWithLeftTrim) {
    EXPECT_EQ(codex::str::left_trim("   hello    "), "hello    ");
}

TEST(StrTrim, RemoveTrailingWithRightTrim) {
    EXPECT_EQ(codex::str::right_trim("   hello    "), "   hello");
}