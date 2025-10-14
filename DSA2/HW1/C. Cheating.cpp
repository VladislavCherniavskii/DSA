#include <iostream>
#include <vector>

static bool dfs(size_t now, std::vector<std::vector<size_t> > &g,
         std::vector<bool> &v, std::vector<size_t> &colors, size_t color) {
    v[now] = true;
    colors[now] = color;

    for (auto neig: g[now]) {
        if (v[neig]) {
            if (colors[neig] == color) {
                return false;
            }
        } else {
            if (!dfs(neig, g, v, colors, 1 - color)) {
                return false;
            };
        }
    }

    return true;
}

int cheating() {
    size_t N, M;
    std::cin >> N >> M;
    size_t u1, u2;
    std::vector<std::vector<size_t> > g(N + 1);
    std::vector<bool> v(N + 1);
    std::vector<size_t> colors(N + 1);
    bool flag = true;

    for (size_t i = 0; i < M; ++i) {
        std::cin >> u1 >> u2;
        g[u1].push_back(u2);
        g[u2].push_back(u1);
    }

    for (size_t i = 1; i <= N; ++i) {
        if (!v[i]) {
            if (!dfs(i, g, v, colors, 0)) {
                flag = false;
            }
        }
    }

    std::cout << (flag ? "YES" : "NO");

    return 0;
}
