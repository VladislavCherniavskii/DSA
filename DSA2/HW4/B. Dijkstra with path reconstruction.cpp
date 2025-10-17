#include <iostream>
#include <vector>

static void dijkstraBFS(std::vector<std::vector<int> > &g,
                        std::vector<int> &dist,
                        std::vector<int> &parent,
                        int N, int S) {
    dist[S] = 0;
    std::vector v(N + 1, false);
    int nearest;

    for (int i = 1; i <= N; ++i) {
        nearest = -1;

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
                    parent[i] = nearest;
                }
            }
        }
    }
}


void dijkstra_with_path_reconstruction() {
    int N;
    std::cin >> N;

    int S, F;
    std::cin >> S >> F;

    std::vector g(N + 1, std::vector<int>(N + 1));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            std::cin >> g[i][j];
        }
    }

    std::vector<int> dist(N + 1, 1e9);
    std::vector<int> parent(N + 1, -1);

    dijkstraBFS(g, dist, parent, N, S);

    std::vector<int> path;

    if (dist[F] == 1e9) {
        std::cout << -1;
    } else {
        for (int i = F; i != -1; i = parent[i]) {
            path.push_back(i);
        }

        for (int i = path.size() - 1; i >= 0; --i) {
            std::cout << path[i] << ' ';
        }
    }
}
