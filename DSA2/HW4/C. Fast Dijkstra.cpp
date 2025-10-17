#include <iostream>
#include <vector>
#include <set>

static void dijkstraFast(std::vector<std::vector<std::pair<int64_t, int64_t> > > &graph,
                     int64_t start, std::vector<int64_t> &dist) {
    dist[start] = 0;

    std::set<std::pair<int64_t, int64_t> > q;
    q.insert({dist[start], start});

    std::pair<int64_t, int64_t> p;
    int64_t nearest;

    while (!q.empty()) {
        p = *q.begin();
        nearest = p.second;
        q.erase(q.begin());

        for (auto [neig, weight]: graph[nearest]) {
            if (dist[neig] > dist[nearest] + weight) {
                q.erase({dist[neig], neig});

                dist[neig] = dist[nearest] + weight;

                q.insert({dist[neig], neig});
            }
        }
    }
}


void fast_dijkstra() {
    int64_t N, K;
    int64_t A, B;

    std::cin >> N >> K;
    std::vector<std::vector<std::pair<int64_t, int64_t> > > g(N + 1);
    std::vector<int64_t> dist(N + 1, 1e12);

    for (int64_t i = 0; i < K; i++) {
        int64_t a, b, weight;
        std::cin >> a >> b >> weight;
        g[a].emplace_back(b, weight);
        g[b].emplace_back(a, weight);
    }

    std::cin >> A >> B;

    dijkstraFast(g, A, dist);

    if (dist[B] == 1e12) {
        std::cout << -1;
    } else {
        std::cout << dist[B];
    }
}
