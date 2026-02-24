
#pragma once
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>

namespace codex {
    namespace _internal {
        template <typename T>
        static std::optional<T> get(const std::unordered_map<std::string, std::string>& env_map,
                                    const std::string& key) = delete;

        template <>
        inline std::optional<std::string> get(const std::unordered_map<std::string, std::string>& env_map,
                                              const std::string& key) {
            if (const auto it = env_map.find(key); it != env_map.end()) {
                return it->second.c_str();
            }
            return std::nullopt;
        }
    }

    class env {
    public:
        static void load(std::string_view path) {
            env_map = {{"TEST", "123"}};
        }

        template <typename T>
        static std::optional<std::string> get(const std::string& key) {
            return _internal::get<T>(env_map, key);
        }

    private:
        static inline std::unordered_map<std::string, std::string> env_map;
    };
}
