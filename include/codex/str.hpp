// Copyright (c) 2026 Andreas Roghe
// SPDX-License-Identifier: MIT
#pragma once
#include <algorithm>
#include <expected>
#include <cmath>
#include <iomanip>

#include "core.hpp"

namespace codex::str {
    /**
     * Trims leading whitespace from a string.
     * @param str the input string to trim.
     * @return The trimmed string.
     */
    [[nodiscard]] inline auto left_trim(const std::string& str) {
        std::string tmp = str;
        tmp.erase(tmp.begin(), std::ranges::find_if_not(tmp, ::isspace));
        return tmp;
    }

    /**
     * Trims trailing whitespace from a string.
     * @param str the input string to trim.
     * @return The trimmed string.
     */
    [[nodiscard]] inline auto right_trim(const std::string& str) {
        std::string tmp = str;
        tmp.erase(std::ranges::find_if_not(tmp.rbegin(), tmp.rend(), ::isspace).base(), tmp.end());
        return tmp;
    }

    /**
     * Trims leading and trailing whitespace from a string.
     * @param str The input string to trim.
     * @return The trimmed string.
     */
    [[nodiscard]] inline auto trim(const std::string& str) {
        std::string tmp = str;
        tmp = str::right_trim(str::left_trim(tmp));
        return tmp;
    }

    /**
     * Convert str to lowercase.
     * @param str The input string to convert.
     * @return The lowercase string.
     */
    [[nodiscard]] inline auto to_lower(const std::string& str) {
        std::string tmp;
        std::ranges::transform(str, std::back_inserter(tmp), ::tolower);
        return tmp;
    }

    /**
     * Convert str to uppercase.
     * @param str The input string to convert.
     * @return The uppercase string.
     */
    [[nodiscard]] inline auto to_upper(const std::string& str) {
        std::string tmp;
        std::ranges::transform(str, back_inserter(tmp), ::toupper);
        return tmp;
    }

    /**
     * Remove all whitespace characters from a string.
     * @param str The input string to process.
     * @return The string with whitespace removed.
     */
    [[nodiscard]] inline auto remove_whitespace(const std::string& str) {
        std::string tmp = str;
        tmp.erase(std::ranges::remove_if(tmp, ::isspace).begin(), tmp.end());
        return tmp;
    }

    /**
     * Split a string into substrings based on a delimiter.
     * @param str The input string to split.
     * @param delimiter The character used as a delimiter.
     * @return A vector of substrings, return StatusCode::NOTHING_TO_DO if no split could be made.
     */
    [[nodiscard]] inline std::expected<std::vector<std::string>, StatusCode> split(
        const std::string& str, const char delimiter) {
        std::vector<std::string> result;
        std::stringstream ss(str);
        while (ss.good()) {
            std::string substr;
            std::getline(ss, substr, delimiter);
            if (substr != str && !substr.empty()) {
                result.push_back(substr);
            }
        }
        if (result.empty())
            return std::unexpected(StatusCode::NOTHING_TO_DO);
        return result;
    }

    /**
     * Join a vector of strings into a single string with a delimiter.
     * @param strs The vector of strings to join.
     * @param delimiter The character used as a delimiter.
     * @return The joined string, if no join is performed, returns StatusCode::NOTHING_TO_DO.
     */
    [[nodiscard]] inline std::expected<std::string, StatusCode> join(const std::vector<std::string>& strs,
                                                                     const char delimiter) {
        std::string result;
        for (const std::string& s : strs) {
            result += s != strs.back() ? s + delimiter : s;
        }
        if (result.empty())
            return std::unexpected(StatusCode::NOTHING_TO_DO);
        return result;
    }

    /**
     * Check if a string contains a substring multiple times.
     * @param str The input string to search.
     * @param substr The substring to search for.
     * @return Number of times the substring is found, if string is empty it returns StatusCode::NOTHING_TO_DO. If the substring is empty, it returns StatusCode::INVALID_INPUT.
     */
    [[nodiscard]] inline std::expected<int, StatusCode>
    contains_mult(const std::string& str, const std::string& substr) {
        if (str.empty())
            return std::unexpected(StatusCode::NOTHING_TO_DO);
        if (substr.empty())
            return std::unexpected(StatusCode::INVALID_INPUT);
        size_t count = 0;
        const std::string haystack = str::to_lower(str);
        const std::string needle = str::to_lower(substr);
        for (size_t i = 0; (i = haystack.find(needle, i)) != std::string::npos; ++i) {
            ++count;
        }
        return count;
    }

    /**
     * Replace all occurrences of a substring with another substring in a string.
     * This function is case-insensitive and replaces all occurrences of 'from' with 'to' in 'str'.
     * @param str The input string to modify.
     * @param from The substring to replace.
     * @param to The substring to replace with.
     * @return The modified string with replacements made.
     */
    [[nodiscard]] inline auto replace_all(const std::string& str, const std::string& from, const std::string& to) {
        std::string tmp = str;
        while (tmp.find(from) != std::string::npos) {
            tmp.replace(tmp.find(from), from.length(), to);
        }
        return tmp;
    }

    /**
     * Convert float to string with specified precision without a carry manipulation.
     * @param d The float to convert.
     * @param precision The number of decimal places to include.
     * @return The expected string representation of the float or an error code if unsuccessful.
     */
    [[nodiscard]] inline std::expected<std::string, codex::StatusCode> to_string(const float d, const int precision) {
        if (precision <= 0 || precision > std::numeric_limits<float>::max_digits10) {
            return std::unexpected(codex::StatusCode::INVALID_INPUT);
        }
        const int whole = d > 0 ? std::floor(d) : std::ceil(d);
        int decimal = static_cast<int>(std::roundf((d - static_cast<float>(whole)) * std::pow(10.0f, precision)));
        if (d < 0)
            decimal = std::abs(decimal);
        std::stringstream ss;
        ss << whole << "." << std::setfill('0') << std::setw(precision) << decimal;
        return std::string(ss.str());
    }
}
