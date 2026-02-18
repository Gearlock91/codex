#ifndef CODEX_STR_HPP
#define CODEX_STR_HPP
#include <algorithm>
#include <expected>

#include "core.hpp"

namespace codex::str {
    /**
     * Trims leading and trailing whitespace from a string.
     * @param str The input string to trim.
     * @return The trimmed string.
     */
    inline auto trim(const std::string &str) {
        std::string tmp = str;
        tmp.erase(std::ranges::remove_if(tmp, ::isspace).begin(), tmp.end());
        return tmp;
    }

    /**
     * Trims leading whitespace from a string.
     * @param str the input string to trim.
     * @return The trimmed string.
     */
    inline auto left_trim(const std::string &str) {
        std::string tmp = str;
        tmp.erase(tmp.begin(), std::ranges::find_if_not(tmp, ::isspace));
        return tmp;
    }

    /**
     * Trims trailing whitespace from a string.
     * @param str the input string to trim.
     * @return The trimmed string.
     */
    inline auto right_trim(const std::string &str) {
        std::string tmp = str;
        tmp.erase(std::ranges::find_if_not(tmp.rbegin(), tmp.rend(), ::isspace).base(), tmp.end());
        return tmp;
    }

    /**
     * Convert str to lowercase.
     * @param str The input string to convert.
     * @return The lowercase string.
     */
    inline auto to_lower(const std::string &str) {
        std::string tmp;
        std::ranges::transform(str, std::back_inserter(tmp), ::tolower);
        return tmp;
    }

    /**
     * Convert str to uppercase.
     * @param str The input string to convert.
     * @return The uppercase string.
     */
    inline auto to_upper(const std::string &str) {
        std::string tmp;
        std::ranges::transform(str, back_inserter(tmp), ::toupper);
        return tmp;
    }

    /**
     * Remove all whitespace characters from a string.
     * @param str The input string to process.
     * @return The string with whitespace removed.
     */
    inline auto remove_whitespace(const std::string &str) {
        std::string tmp = str;
        tmp.erase(remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());
        return tmp;
    }

    /**
     * Split a string into substrings based on a delimiter.
     * @param str The input string to split.
     * @param delimiter The character used as a delimiter.
     * @return A vector of substrings, return StatusCode::NOTHING_TO_DO if no split could be made.
     */
    inline std::expected<std::vector<std::string>, StatusCode> split(const std::string &str, const char delimiter) {
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
    inline std::expected<std::string, StatusCode> join(const std::vector<std::string> &strs, const char delimiter) {
        std::string result;
        for (const std::string &s: strs) {
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
    inline std::expected<int, StatusCode> contains_mult(const std::string &str, const std::string &substr) {
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
     * @param str The input string to modify.
     * @param from The substring to replace.
     * @param to The substring to replace with.
     * @return The modified string with replacements made.
     */
    inline auto replace_all(const std::string &str, const std::string &from, const std::string &to) {
        return "to be implemented";
    }

    /**
     * Convert float to string with specified precision.
     * @param f The float to convert.
     * @param precision The number of decimal places to include.
     * @return The expected string representation of the float or an error code.
     */
    inline std::expected<std::string, codex::StatusCode> to_string(float f, const int precision) {
        return std::unexpected(codex::StatusCode::NOT_IMPLEMENTED);
    }
}
#endif //CODEX_STR_HPP
