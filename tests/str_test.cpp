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

TEST(StrManip, ToLower) {
    EXPECT_EQ(codex::str::to_lower("HELLO"), "hello");
    EXPECT_EQ(codex::str::to_lower("HeLlO"), "hello");
}

TEST(StrManip, ToUpper) {
    EXPECT_EQ(codex::str::to_upper("hello"), "HELLO");
    EXPECT_EQ(codex::str::to_upper("HeLlO"), "HELLO");
}