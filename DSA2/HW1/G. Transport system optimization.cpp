#include <iostream>
#include <vector>

static void dfs(size_t now, std::vector<std::vector<size_t> > &g,
         std::vector<bool> &v, size_t &depth, size_t &max_depth, size_t &end) {
    v[now] = true;

    if (depth > max_depth) {
        max_depth = depth;
        end = now;
    }

    depth++;
    for (auto neig: g[now]) {
        if (!v[neig]) {
            dfs(neig, g, v, depth, max_depth, end);
        }
    }

    depth--;
}

int transport_optimization() {
    size_t N;
    std::cin >> N;
    size_t u1, u2;
    std::vector<std::vector<size_t> > g(N + 1);
    std::vector<bool> v(N + 1);
    size_t end;
    size_t depth = 0;
    size_t max_depth = 0;

    for (size_t i = 0; i < N - 1; ++i) {
        std::cin >> u1 >> u2;
        g[u1].push_back(u2);
        g[u2].push_back(u1);
    }

    dfs(1, g, v, depth, max_depth, end);

    v = std::vector<bool>(v.size(), false);
    depth = 0;
    max_depth = 0;

    dfs(end, g, v, depth, max_depth, end);

    std::cout << max_depth;

    return 0;
}
