// Copyright (c) 2026 Andreas Roghe
// SPDX-License-Identifier: MIT
#include <gtest/gtest.h>
#include <codex/str.hpp>

TEST(Str, RemovesLeadingSpaces) {
    EXPECT_EQ(codex::str::trim("   hello"), "hello");
    EXPECT_EQ(codex::str::trim("    hel llo  "), "hel llo");
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

TEST(Str, FindSubstr) {
    EXPECT_EQ(codex::str::contains_mult("Hello World", "World").value(), 1);
    EXPECT_EQ(codex::str::contains_mult("Hello World", "Hello").value(), 1);
    EXPECT_EQ(codex::str::contains_mult("Hello World", "Goodbye").value(), 0);
    EXPECT_EQ(codex::str::contains_mult("Hello World", "").error(), codex::StatusCode::INVALID_INPUT);
    EXPECT_EQ(
        codex::str::contains_mult("Another one of Hello World To Be sure it's a Hello, with a Heartily hello", "hello").
        value(),
        3);
    EXPECT_EQ(codex::str::contains_mult("", "Goodbye").error(), codex::StatusCode::NOTHING_TO_DO);
}

TEST(Str, ReplaceAll) {
    EXPECT_EQ(codex::str::replace_all("Hello World", "World", "Earth").value(), "Hello Earth");
    EXPECT_EQ(codex::str::replace_all("Hello World", "Hello", "Goodbye").value(), "Goodbye World");
    EXPECT_EQ(codex::str::replace_all("", "Goodbye", "Hello").value(), "");
    EXPECT_EQ(
        codex::str::replace_all("Another one bites to dust with a super string so that all A are replaced", "a", "s"),
        "Another one bites to dust with s super string so thst sll A sre replsced");
    EXPECT_EQ(codex::str::replace_all("Hello World", "", "Goodbye").error(), codex::StatusCode::INVALID_INPUT);
    EXPECT_EQ(codex::str::replace_all("aa", "aa", "a"),"a");
}

TEST(Str, DoubleToStringPositive) {
    constexpr float d = 1.23456789;
    const std::string result = codex::str::to_string(d, 2).value();
    EXPECT_EQ(result, "1.23");
    EXPECT_EQ(codex::str::to_string(d, 10).error(), codex::StatusCode::INVALID_INPUT);
    EXPECT_EQ(codex::str::to_string(d, -1).error(), codex::StatusCode::INVALID_INPUT);
    EXPECT_EQ(codex::str::to_string(d, 0).error(), codex::StatusCode::INVALID_INPUT);
    EXPECT_EQ(codex::str::to_string(d, 1).value(), "1.2");
    EXPECT_EQ(codex::str::to_string(d, 5).value(), "1.23457");
}

TEST(Str, DoubleToStringNegative) {
    constexpr float d = -1.23456789;
    const std::string result = codex::str::to_string(d, 2).value();
    EXPECT_EQ(result, "-1.23");
}