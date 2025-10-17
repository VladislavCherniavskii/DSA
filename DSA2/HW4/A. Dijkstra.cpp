#include <iostream>
#include <vector>

static std::vector<int> dijkstraBFS(std::vector<std::vector<int> > &g, int N, int S) {
    std::vector<int> dist(N + 1, 1e9);
    dist[S] = 0;

    std::vector v(N + 1, false);

    for (int i = 1; i <= N; ++i) {
        int nearest = -1;
        for (int j = 1; j <= N; ++j) {
            if (!v[j] && (nearest == -1 || dist[j] < dist[nearest])) {
                nearest = j;
            }
        }

        v[nearest] = true;

        for (int i = 1; i <= N; ++i) {
            if (nearest != i && g[nearest][i] != -1 && !v[i]) {
                if (dist[i] > dist[nearest] + g[nearest][i]) {
                    dist[i] = dist[nearest] + g[nearest][i];
                }
            }
        }
    }

    return dist;
}


void dijkstra() {
    int N;
    int S, F;
    std::cin >> N;
    std::cin >> S >> F;

    std::vector g(N + 1, std::vector<int>(N + 1));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            std::cin >> g[i][j];
        }
    }

    auto ans = dijkstraBFS(g, N, S)[F];

    if (ans == 1e9) {
        std::cout << -1;
    } else {
        std::cout << ans;
    }
}
