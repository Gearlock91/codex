// Copyright (c) 2026 Andreas Roghe
// SPDX-License-Identifier: MIT
#include <gtest/gtest.h>
#include <codex/env.hpp>

TEST(EnvStr, GetEnvString) {
    codex::env::load("test");
    EXPECT_EQ(codex::env::get<std::string>("TEST"), std::optional<std::string>("123"));
}

TEST(EnvStr, GetUnknown) {
    EXPECT_EQ(codex::env::get<std::string>("UNKNOWN"), std::nullopt);
    EXPECT_EQ(codex::env::get<std::string>("UNKNOWN").value_or("13"), "13");
}