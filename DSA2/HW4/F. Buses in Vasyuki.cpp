#include <iostream>
#include <vector>
#include <set>

static void dijkstra(std::vector<std::vector<std::vector<int64_t> > > &g,
                     int64_t start, std::vector<int64_t> &dist) {
    dist[start] = 0;

    std::set<std::pair<int64_t, int64_t> > q;
    q.insert({dist[start], start});

    while (!q.empty()) {
        auto [dist_u, u] = *q.begin();
        q.erase(q.begin());

        for (auto edge: g[u]) {
            int64_t v = edge[0];
            int64_t t_dep = edge[1];
            int64_t t_arr = edge[2];

            if (dist_u <= t_dep && t_arr < dist[v]) {
                q.erase({dist[v], v});

                dist[v] = t_arr;
                q.insert({dist[v], v});
            }
        }
    }
}

void buses_in_vasyuki() {
    int64_t N;
    std::cin >> N;

    int64_t d, v;
    std::cin >> d >> v;

    int64_t R;
    std::cin >> R;

    std::vector<std::vector<std::vector<int64_t> > > g(N + 1);
    std::vector<int64_t> dist(N + 1, 1e9);

    for (int i = 0; i < R; ++i) {
        int64_t u1, u2;
        int64_t t_dep, t_arr;
        std::cin >> u1 >> t_dep >> u2 >> t_arr;
        g[u1].push_back({u2, t_dep, t_arr});
    }

    dijkstra(g, d, dist);

    if (dist[v] == 1e9) {
        std::cout << -1;
    } else {
        std::cout << dist[v];
    }
}
