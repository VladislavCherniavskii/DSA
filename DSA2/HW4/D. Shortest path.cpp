#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

static void dijkstraFast(std::vector<std::vector<std::pair<long long, long long>>> &graph,
                         long long start,
                         std::vector<long long> &dist,
                         std::vector<long long> &parent) {
    dist[start] = 0;

    std::set<std::pair<long long, long long>> q;
    q.insert({dist[start], start});

    while (!q.empty()) {
        auto p = *q.begin();
        long long nearest = p.second;
        q.erase(q.begin());

        for (auto [neig, weight] : graph[nearest]) {
            if (dist[neig] > dist[nearest] + weight) {
                q.erase({dist[neig], neig});
                dist[neig] = dist[nearest] + weight;

                parent[neig] = nearest;
                q.insert({dist[neig], neig});
            }
        }
    }
}

void shortest_path() {
    long long N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<long long, long long>>> graph(N + 1);
    std::vector<long long> dist(N + 1, 1e12);
    std::vector<long long> parent(N + 1, -1);

    for (long long i = 0; i < M; i++) {
        long long a, b, weight;
        std::cin >> a >> b >> weight;
        graph[a].emplace_back(b, weight);
        graph[b].emplace_back(a, weight);
    }

    long long S, T;
    std::cin >> S >> T;

    dijkstraFast(graph, S, dist, parent);

    if (dist[T] == 1e12) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << dist[T] << std::endl;

        std::vector<long long> path;
        for (long long v = T; v != -1; v = parent[v]) {
            path.push_back(v);
        }

        std::reverse(path.begin(), path.end());
        
        std::cout << path.size() << std::endl;
        for (size_t i = 0; i < path.size(); i++) {
            std::cout << path[i];
            if (i != path.size() - 1) std::cout << " ";
        }

        std::cout << std::endl;
    }
}
