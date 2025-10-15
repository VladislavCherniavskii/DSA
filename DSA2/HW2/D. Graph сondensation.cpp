#include <iostream>
#include <vector>
#include <algorithm>

static void dfs1(size_t now,
          std::vector<std::vector<size_t> > &g,
          std::vector<bool> &v,
          std::vector<size_t> &t_sort) {
    v[now] = true;

    for (auto u: g[now]) {
        if (!v[u]) {
            dfs1(u, g, v, t_sort);
        }
    }

    t_sort.push_back(now);
}

static void dfs2(size_t now,
          std::vector<std::vector<size_t> > &g_exp,
          std::vector<bool> &v,
          std::vector<size_t> &comp) {
    v[now] = true;
    comp.push_back(now);

    for (auto u: g_exp[now]) {
        if (!v[u]) {
            dfs2(u, g_exp, v, comp);
        }
    }
}

int graph_condensation() {
    size_t N, M;
    std::cin >> N >> M;

    std::vector<std::vector<size_t> > g(N + 1);
    std::vector<std::vector<size_t> > g_exp(N + 1);

    for (size_t i = 0; i < M; ++i) {
        size_t u1, u2;
        std::cin >> u1 >> u2;
        g[u1].push_back(u2);
        g_exp[u2].push_back(u1);
    }

    std::vector<bool> visited(N + 1, false);
    std::vector<size_t> t_sort;

    for (size_t i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs1(i, g, visited, t_sort);
        }
    }

    std::reverse(t_sort.begin(), t_sort.end());
    std::fill(visited.begin(), visited.end(), false);

    std::vector<std::vector<size_t> > comps;
    std::vector<size_t> comp_id(N + 1);

    for (auto i: t_sort) {
        if (!visited[i]) {
            std::vector<size_t> comp;
            dfs2(i, g_exp, visited, comp);
            comps.push_back(comp);
        }
    }

    size_t num = 1;
    for (const auto &comp: comps) {
        for (auto vertex: comp) {
            comp_id[vertex] = num;
        }
        ++num;
    }

    std::cout << comps.size() << '\n';
    for (size_t i = 1; i <= N; ++i) {
        std::cout << comp_id[i] << ' ';
    }

    return 0;
}
