#include <iostream>
#include <vector>

static void dfs(size_t now, std::vector<std::vector<size_t> > &g, std::vector<bool> &v) {
    v[now] = true;
    for (size_t neig: g[now]) {
        if (!v[neig]) {
            dfs(neig, g, v);
        }
    }
}

int depth_first_search() {
    size_t N;
    size_t M;
    std::cin >> N >> M;
    size_t u1, u2;
    std::vector<std::vector<size_t> > g(N + 1);
    std::vector<bool> v(N + 1);

    for (size_t i = 0; i < M; ++i) {
        std::cin >> u1 >> u2;
        g[u1].push_back(u2);
        g[u2].push_back(u1);
    }

    dfs(1, g, v);

    std::vector<size_t> comp;
    for (size_t i = 1; i <= N; ++i) {
        if (v[i]) {
            comp.push_back(i);
        }
    }

    std::cout << comp.size() << std::endl;
    for (size_t i: comp) {
        std::cout << i << " ";
    }

    return 0;
}
