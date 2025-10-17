#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

static void dijkstraFast(std::vector<std::vector<std::vector<int> > > &g,
                         int start, int t_now, int max_weight,
                         std::vector<int> &dist) {
    std::pair<int, int> now;
    std::set<std::pair<int, int> > q;

    dist[start] = t_now;
    q.insert({dist[start], start});

    while (!q.empty()) {
        now = *q.begin();
        int time = now.first;
        int u = now.second;
        q.erase(q.begin());

        for (auto edge: g[u]) {
            int v = edge[0];
            int t_edge = edge[1];
            int load = edge[2];

            if (max_weight <= load) {
                int t_new = time + t_edge;
                if (t_new < dist[v]) {
                    q.erase({dist[v], v});
                    dist[v] = t_new;
                    q.insert({dist[v], v});
                }
            }
        }
    }
}

void conveyance() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::vector<int> > > g(n + 1);

    for (int i = 0; i < m; ++i) {
        int u1, u2;
        int time, load;
        std::cin >> u1 >> u2 >> time >> load;
        g[u1].push_back({u2, time, load});
        g[u2].push_back({u1, time, load});
    }

    int l = 0;
    int r = 1e7;
    int mugs = 0;

    while (l < r) {
        int mid = (l + r) / 2;
        int weight = 3 * 1e6 + mid * 100;
        std::vector<int> dist(n + 1, 1e9);

        dijkstraFast(g, 1, 0, weight, dist);

        if (dist[n] <= 1440) {
            l = mid + 1;
            mugs = mid;
        } else {
            r = mid;
        }
    }

    if (mugs == 1e8 - 1) {
        std::cout << 1e7;
    } else {
        std::cout << std::min(mugs, 10000000);
    }
}
