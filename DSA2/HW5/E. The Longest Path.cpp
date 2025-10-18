#include <iostream>
#include <vector>

static void FloydWarshall(std::vector<std::vector<int> > &dist, int n) {
    for (auto k = 0; k < n; ++k) {
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (dist[i][k] < 1e9) {
                    if (dist[k][j] < 1e9) {
                        dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
}

void the_longest_path() {
    int n;
    std::cin >> n;

    std::vector dist(n, std::vector<int>(n));

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < n; ++j) {
            std::cin >> dist[i][j];
            if (i != j) {
                if (dist[i][j] == 0) {
                    dist[i][j] = 1e9;
                }
            }
        }
    }

    FloydWarshall(dist, n);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (dist[i][j] != 1e9) {
                    if (dist[i][j] > ans) {
                        ans = dist[i][j];
                    }
                }
            }
        }
    }

    std::cout << ans;
}
