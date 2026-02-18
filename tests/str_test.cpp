#include <gtest/gtest.h>
#include <codex/str.hpp>

TEST(Str, RemovesLeadingSpaces) {
    EXPECT_EQ(codex::str::trim("   hello"), "hello");
}

TEST(Str, RemovesTrailingSpaces) {
    EXPECT_EQ(codex::str::trim("hello   "), "hello");
}

TEST(Str, RemoveSpaces) {
    EXPECT_EQ(codex::str::trim("      "), "");
}

TEST(Str, RemovesBothTrailingAndLeadingSpaces) {
    EXPECT_EQ(codex::str::trim("   hello   "), "hello");
}

TEST(Str, RemoveLeadingWithLeftTrim) {
    EXPECT_EQ(codex::str::left_trim("   hello    "), "hello    ");
}

TEST(Str, RemoveTrailingWithRightTrim) {
    EXPECT_EQ(codex::str::right_trim("   hello    "), "   hello");
}

TEST(Str, ToLower) {
    EXPECT_EQ(codex::str::to_lower("HELLO"), "hello");
    EXPECT_EQ(codex::str::to_lower("HeLlO"), "hello");
}

TEST(Str, ToUpper) {
    EXPECT_EQ(codex::str::to_upper("hello"), "HELLO");
    EXPECT_EQ(codex::str::to_upper("HeLlO"), "HELLO");
}

TEST(Str, RemoveWhitespace) {
    EXPECT_EQ(codex::str::remove_whitespace(" h  el lo wor ld"), "helloworld");
}

TEST(Str, SplitString) {
    EXPECT_EQ(codex::str::split("hello,world", ',').value().size(), 2);
    EXPECT_EQ(codex::str::split("hello,world,again", ',').value().size(), 3);
    EXPECT_EQ(codex::str::split("nothingtosplit", ',').error(), codex::StatusCode::NOTHING_TO_DO);
    EXPECT_EQ(codex::str::split("nothing;to;split", ',').error(), codex::StatusCode::NOTHING_TO_DO);
}

TEST(Str, JoinString) {
    EXPECT_EQ(codex::str::join({"hello", "world"}, ',').value(), "hello,world");
    EXPECT_EQ(codex::str::join({"hello", "world", "again"}, ',').value(), "hello,world,again");
    EXPECT_EQ(codex::str::join({}, ',').error(), codex::StatusCode::NOTHING_TO_DO);
}