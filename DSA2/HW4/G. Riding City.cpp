#include <iostream>
#include <vector>
#include <set>

static void dijkstraFast(std::vector<std::vector<std::vector<int> > > &g,
                         int start, int current_time, std::vector<int> &dist) {
    dist[start] = current_time;

    std::set<std::pair<int, int> > q;
    q.insert({dist[start], start});

    while (!q.empty()) {
        std::pair<int, int> now = *q.begin();
        int time = now.first;
        int u = now.second;
        q.erase(q.begin());

        for (auto edge: g[u]) {
            int v = edge[0];
            int C = edge[1];
            int D = edge[2];

            int t_dep;
            if (time % C != 0) {
                t_dep = C - time % C + time;
            } else {
                t_dep = time;
            }

            if (t_dep + D < dist[v]) {
                q.erase({dist[v], v});
                dist[v] = t_dep + D;
                q.insert({dist[v], v});
            }
        }
    }
}

void riding_city() {
    int N, K, M;
    std::cin >> N >> K;

    std::vector<std::vector<std::vector<int> > > g(N + 1);

    for (int i = 0; i < K; ++i) {
        int A, B, C, D;
        std::cin >> A >> B >> C >> D;
        g[A].push_back({B, C, D});
    }

    std::cin >> M;
    std::vector<int> plan(M);

    for (int i = 0; i < M; ++i) {
        std::cin >> plan[i];
    }

    int time = 0;

    for (int i = 0; i < M - 1; ++i) {
        std::vector<int> dist(N + 1, 1e9);

        int u1 = plan[i];
        int u2 = plan[i + 1];

        dijkstraFast(g, u1, time, dist);

        if (dist[u2] == 1e9) {
            std::cout << -1;
            break;
        }

        time = dist[u2];
    }

    std::cout << time;
}
