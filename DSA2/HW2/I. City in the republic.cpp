#include <iostream>
#include <vector>


static void dfs(int u, int p,
         std::vector<std::vector<int> > &g,
         std::vector<int> &par,
         std::vector<int> &subtree) {
    subtree[u] = 1;
    par[u] = p;

    for (auto i: g[u]) {
        if (i != par[u]) {
            dfs(i, u, g, par, subtree);
            subtree[u] += subtree[i];
        }
    }
}

static int central(int N,
            std::vector<std::vector<int> > &g,
            std::vector<int> &par,
            std::vector<int> &subtree) {
    bool flag;
    for (auto i = 1; i <= N; ++i) {
        if (g[i].size() < 2 || (N - 1) % g[i].size() != 0)
            continue;

        flag = true;

        for (auto j: g[i]) {
            if (((j == par[i]) ? (N - subtree[i]) : subtree[j]) != (N - 1) / g[i].size()) {
                flag = false;
                break;
            }
        }

        if (flag)
            return i;
    }

    return -1;
}

int city_republic() {
    int N;
    int u1, u2;
    std::cin >> N;
    std::vector<std::vector<int> > g(N + 1);

    for (auto i = 0; i < N - 1; ++i) {
        std::cin >> u1 >> u2;
        g[u1].push_back(u2);
        g[u2].push_back(u1);
    }

    std::vector<int> par(N + 1);
    std::vector<int> subtree(N + 1);

    dfs(1, 0, g, par, subtree);

    if (N == 1) {
        std::cout << -1;
    } else {
        std::cout << central(N, g, par, subtree);
    }

    return 0;
}
