#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

static void dijkstraFast(std::vector<std::vector<std::pair<int64_t, int64_t> > > &g,
                         int64_t start, std::vector<int64_t> &dist) {
    dist[start] = 0;

    std::set<std::pair<int64_t, int64_t> > q;
    q.insert({dist[start], start});

    while (!q.empty()) {
        std::pair<int64_t, int64_t> p = *q.begin();
        int64_t nearest = p.second;
        q.erase(q.begin());

        for (auto [neig, weight]: g[nearest]) {
            if (dist[neig] > dist[nearest] + weight) {
                q.erase({dist[neig], neig});

                dist[neig] = dist[nearest] + weight;
                q.insert({dist[neig], neig});
            }
        }
    }
}


void alchemy_olympiad() {
    int64_t N, M, K;
    std::cin >> N >> M >> K;

    int64_t C;
    std::cin >> C;

    std::vector<int64_t> towns(K);

    for (int64_t i = 0; i < K; ++i) {
        std::cin >> towns[i];
    }

    std::vector<std::vector<std::pair<int64_t, int64_t> > > g(N + 1);

    for (int i = 0; i < M; ++i) {
        int64_t S, E, T;
        std::cin >> S >> E >> T;

        g[S].emplace_back(E, T);
        g[E].emplace_back(S, T);
    }

    std::vector<int64_t> dist(N + 1, 1e12);

    dijkstraFast(g, C, dist);

    std::vector<std::pair<int64_t, int64_t> > ans;

    for (int64_t i: towns) {
        ans.emplace_back(i, dist[i]);
    }

    std::sort(ans.begin(), ans.end(), [](auto a, auto b) { return a.second < b.second; });

    for (auto [town, time]: ans) {
        std::cout << town << ' ' << time << std::endl;
    }
}
