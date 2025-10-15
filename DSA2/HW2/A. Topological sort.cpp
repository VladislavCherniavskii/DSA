#include <iostream>
#include <vector>
#include <algorithm>

static bool dfs(size_t now,
         std::vector<std::vector<size_t> > &g,
         std::vector<size_t> &color,
         std::vector<size_t> &top_sort) {
    color[now] = 1;

    for (size_t neig: g[now]) {
        if (color[neig] == 1) {
            return true;
        }

        if (color[neig] == 0 && dfs(neig, g, color, top_sort)) {
            return true;
        }
    }

    color[now] = 2;
    top_sort.push_back(now);

    return false;
}

int topological_sort() {
    size_t N, M;
    std::cin >> N >> M;
    size_t u1, u2;

    std::vector<std::vector<size_t> > g(N + 1);
    std::vector<size_t> color(N + 1, 0);
    std::vector<size_t> top_sort;

    bool has_cycle = false;

    for (auto i = 0; i < M; ++i) {
        std::cin >> u1 >> u2;
        g[u1].push_back(u2);
    }

    for (auto i = 1; i <= N; ++i) {
        if (color[i] == 0 && dfs(i, g, color, top_sort)) {
            has_cycle = true;
            break;
        }
    }

    if (has_cycle) {
        std::cout << -1;
    } else {
        std::reverse(top_sort.begin(), top_sort.end());
        for (size_t i: top_sort) {
            std::cout << i << " ";
        }
    }

    return 0;
}
