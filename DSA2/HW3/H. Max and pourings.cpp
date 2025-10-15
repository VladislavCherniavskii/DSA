#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_set>
#include <array>
#include <algorithm>

static size_t tuple_hash(const std::tuple<size_t, size_t, size_t> &t) {
    auto [a, b, c] = t;
    return a ^ b ^ c;
}

static void bfs_recursive(std::vector<std::tuple<size_t, size_t, size_t> > &now_lvl,
                   size_t now_steps,
                   std::array<size_t, 3> &cap,
                   size_t target,
                   std::unordered_set<std::tuple<size_t, size_t, size_t>, decltype(&tuple_hash), std::equal_to<> > &v,
                   size_t &min_steps) {
    for (auto &state: now_lvl) {
        auto [a, b, c] = state;
        if (a == target || b == target || c == target) {
            if (min_steps == static_cast<size_t>(-1) || now_steps < min_steps) {
                min_steps = now_steps;
            }

            return;
        }
    }

    std::vector<std::tuple<size_t, size_t, size_t> > next_level;

    for (auto &state: now_lvl) {
        auto [a, b, c] = state;

        for (size_t i = 0; i < 3; ++i) {
            auto filled = state;
            if (i == 0) {
                std::get<0>(filled) = std::get<0>(cap);
            } else if (i == 1) {
                std::get<1>(filled) = std::get<1>(cap);
            } else {
                std::get<2>(filled) = std::get<2>(cap);
            }

            if (v.find(filled) == v.end()) {
                v.insert(filled);
                next_level.push_back(filled);
            }

            auto emp = state;
            if (i == 0) {
                std::get<0>(emp) = 0;
            } else if (i == 1) {
                std::get<1>(emp) = 0;
            } else {
                std::get<2>(emp) = 0;
            }

            if (v.find(emp) == v.end()) {
                v.insert(emp);
                next_level.push_back(emp);
            }

            for (size_t j = 0; j < 3; ++j) {
                if (i == j) continue;

                auto poured = state;
                size_t &source = (i == 0) ? std::get<0>(poured) : (i == 1) ? std::get<1>(poured) : std::get<2>(poured);
                size_t &dest = (j == 0) ? std::get<0>(poured) : (j == 1) ? std::get<1>(poured) : std::get<2>(poured);

                size_t transfer = 0;
                switch (j) {
                    case 0: transfer = std::min(source, std::get<0>(cap) - dest);
                        break;
                    case 1: transfer = std::min(source, std::get<1>(cap) - dest);
                        break;
                    case 2: transfer = std::min(source, std::get<2>(cap) - dest);
                        break;
                }

                if (transfer == 0) {
                    continue;
                }

                source -= transfer;
                dest += transfer;

                if (v.find(poured) == v.end()) {
                    v.insert(poured);
                    next_level.push_back(poured);
                }
            }
        }
    }

    if (!next_level.empty()) {
        bfs_recursive(next_level, now_steps + 1, cap, target, v, min_steps);
    }
}

void max_pourings() {
    size_t a, b, c, V;
    size_t res = static_cast<size_t>(-1);
    std::cin >> a >> b >> c >> V;
    std::array<size_t, 3> cap = {a, b, c};
    std::unordered_set<std::tuple<size_t, size_t, size_t>, decltype(&tuple_hash), std::equal_to<> > visited(
        10, &tuple_hash);
    std::vector<std::tuple<size_t, size_t, size_t> > start_level = {{0, 0, 0}};

    visited.insert({0, 0, 0});

    bfs_recursive(start_level, 0, cap, V, visited, res);

    std::cout << (res == static_cast<size_t>(-1) ? -1 : static_cast<int>(res));
}
