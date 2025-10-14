#include <iostream>
#include <vector>

static void dfs(size_t now, std::vector<std::vector<size_t> > &g,
         std::vector<bool> &v, std::vector<size_t> &degs) {
    v[now] = true;
    for (size_t neig: g[now]) {
        if (!v[neig]) {
            dfs(neig, g, v, degs);
            degs[now] += degs[neig];
        }
    }
}

int subtree_sizes() {
    size_t N;
    std::cin >> N;
    size_t u1, u2;
    std::vector<std::vector<size_t> > g(N + 1);
    std::vector<bool> v(N + 1);
    std::vector<size_t> degs(N + 1, 1);

    for (size_t i = 0; i < N - 1; ++i) {
        std::cin >> u1 >> u2;
        g[u1].push_back(u2);
        g[u2].push_back(u1);
    }

    dfs(1, g, v, degs);

    for (size_t i = 1; i <= N; ++i) {
        std::cout << degs[i] << " ";
    }

    return 0;
}
