#include <iostream>
#include <vector>

static void dfs(size_t now, std::vector<std::vector<size_t> > &g,
         std::vector<bool> &v, std::vector<size_t> &comp) {
    v[now] = true;
    comp.push_back(now);
    for (size_t neig: g[now]) {
        if (!v[neig]) {
            dfs(neig, g, v, comp);
        }
    }
}

int connected_components() {
    size_t N, M;
    std::cin >> N >> M;
    size_t u1, u2;
    std::vector<std::vector<size_t> > g(N + 1);
    std::vector<size_t> comp;
    std::vector<std::vector<size_t> > comps;
    std::vector<bool> v(N + 1);

    for (size_t i = 0; i < M; ++i) {
        std::cin >> u1 >> u2;
        g[u1].push_back(u2);
        g[u2].push_back(u1);
    }

    for (size_t i = 1; i <= N; ++i) {
        if (!v[i]) {
            comp.clear();
            dfs(i, g, v, comp);
            comps.push_back(comp);
        }
    }

    std::cout << comps.size() << std::endl;
    for (auto i: comps) {
        std::cout << i.size() << std::endl;
        for (auto j: i) {
            std::cout << j << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
