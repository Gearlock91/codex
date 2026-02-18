#ifndef CODEX_STR_HPP
#define CODEX_STR_HPP

namespace codex::str {
    /**
     * Trims leading and trailing whitespace from a string.
     * @param str The input string to trim.
     * @return The trimmed string.
     */
    inline auto trim(const std::string& str) {
        std::string tmp = str;
        tmp.erase(remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());
        return tmp;
    }

    /**
     * Trims leading whitespace from a string.
     * @param str the input string to trim.
     * @return The trimmed string.
     */
    inline auto left_trim(const std::string&str) {
        std::string tmp = str;
        tmp.erase(tmp.begin(), std::ranges::find_if_not(tmp, ::isspace));
        return tmp;
    }

    /**
     * Trims trailing whitespace from a string.
     * @param str the input string to trim.
     * @return The trimmed string.
     */
    inline auto right_trim(const std::string&str) {
        std::string tmp = str;
        tmp.erase(std::ranges::find_if_not(tmp.rbegin(), tmp.rend(), ::isspace).base(), tmp.end());
        return tmp;
    }
    /**
     * Convert str to lowercase.
     * @param str The input string to convert.
     * @return The lowercase string.
     */
    inline auto to_lower(const std::string& str) {
        return "to be implemented";
    }
    /**
     * Convert str to uppercase.
     * @param str The input string to convert.
     * @return The uppercase string.
     */
    inline auto to_upper(const std::string& str) {
        return "to be implemented";
    }
    /**
     * Remove all whitespace characters from a string.
     * @param str The input string to process.
     * @return The string with whitespace removed.
     */
    inline auto remove_whitespace(const std::string& str) {
        return "to be implemented";
    }
    /**
     * Split a string into substrings based on a delimiter.
     * @param str The input string to split.
     * @param delimiter The character used as a delimiter.
     * @return A vector of substrings.
     */
    inline auto split(const std::string& str, char delimiter) {
        return "to be implemented";
    }
    /**
     * Join a vector of strings into a single string with a delimiter.
     * @param strs The vector of strings to join.
     * @param delimiter The character used as a delimiter.
     * @return The joined string.
     */
    inline auto join(const std::vector<std::string>& strs, char delimiter) {
        return "to be implemented";
    }
    /**
     * Check if a string contains a substring.
     * @param str The input string to search.
     * @param substr The substring to search for.
     * @return True if the substring is found, false otherwise.
     */
    inline auto contains(const std::string& str, const std::string& substr) {
        return "to be implemented";
    }
    /**
     * Replace all occurrences of a substring with another substring in a string.
     * @param str The input string to modify.
     * @param from The substring to replace.
     * @param to The substring to replace with.
     * @return The modified string with replacements made.
     */
    inline auto replace_all(const std::string& str, const std::string& from, const std::string& to) {
        return "to be implemented";
    }
    /**
     * Convert float to string.
     * @param f The float to convert.
     * @return The string representation of the float.
     */
    inline auto ftoa(float f) {
        return "to be implemented";
    }

}
#endif //CODEX_STR_HPP