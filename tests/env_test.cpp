// Copyright (c) 2026 Andreas Roghe
// SPDX-License-Identifier: MIT
#include <gtest/gtest.h>
#include <codex/env.hpp>

TEST(EnvStr, GetEnvString) {
    codex::env::load("test");
    EXPECT_EQ(codex::env::get<std::string>("TEST"), std::optional<std::string>("123"));
}
