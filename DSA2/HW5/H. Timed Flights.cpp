#include <iostream>
#include <vector>

static auto FB(int N, int source,
               std::vector<std::vector<std::pair<int, int> > > &g,
               std::vector<std::vector<std::pair<int, int> > > &departures) {
    bool flag;

    std::vector ans(N + 1, 1e9);
    ans[source] = 0;

    flag = true;

    while (flag) {
        flag = false;

        for (auto u = 1; u <= N; ++u) {
            if (ans[u] == 1e9) {
                continue;
            }

            for (size_t i = 0; i < departures[u].size(); ++i) {
                auto [v, arr] = g[u][i];
                int dep = departures[u][i].second;

                if (dep >= ans[u] && arr < ans[v]) {
                    ans[v] = arr;
                    flag = true;
                }
            }
        }
    }

    return ans;
}

void timed_flights() {
    int N;
    std::cin >> N;

    int A, B;
    std::cin >> A >> B;

    int K;
    std::cin >> K;

    std::vector<std::vector<std::pair<int, int> > > g(N + 1);
    std::vector<std::vector<std::pair<int, int> > > departures(N + 1);

    for (auto i = 0; i < K; ++i) {
        int from, dep, to, arr;
        std::cin >> from >> dep >> to >> arr;

        g[from].emplace_back(to, arr);
        departures[from].emplace_back(to, dep);
    }

    std::vector<int> ans(N + 1, 1e9);
    ans[A] = 0;

    bool flag = true;

    while (flag) {
        flag = false;

        for (int u = 1; u <= N; ++u) {
            if (ans[u] == 1e9) {
                continue;
            }

            for (size_t i = 0; i < g[u].size(); ++i) {
                auto [v, arr] = g[u][i];
                int dep = departures[u][i].second;

                if (dep >= ans[u] && arr < ans[v]) {
                    ans[v] = arr;
                    flag = true;
                }
            }
        }
    }

    std::cout << ans[B];
}
