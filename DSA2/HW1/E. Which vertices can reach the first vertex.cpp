#include <iostream>
#include <vector>

static void dfs(size_t now, std::vector<std::vector<size_t>>& g, std::vector<bool>& v) {
    v[now] = true;
    for (size_t neig : g[now]) {
        if (!v[neig]) {
            dfs(neig, g, v);
        }
    }
}

int reachable_vertices() {
    size_t N, M;
    std::cin >> N >> M;
    size_t u1, u2;
    std::vector<std::vector<size_t>> g(N + 1);
    std::vector<bool> v(N + 1);
    std::vector<size_t> comp;

    for (size_t i = 0; i < M; ++i) {
        std::cin >> u1 >> u2;
        g[u2].push_back(u1);
    }

    dfs(1, g, v);

    for (size_t i = 1; i <= N; ++i) {
        if (v[i]) {
            comp.push_back(i);
        }
    }

    for (size_t i : comp) {
        std::cout << i << " ";
    }

    return 0;
}