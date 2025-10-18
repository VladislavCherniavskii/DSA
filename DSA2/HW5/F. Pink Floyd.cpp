#include <iostream>
#include <vector>

static void FloydWarshall(std::vector<std::vector<double> > &dist,
                          std::vector<std::vector<int> > &next,
                          int n) {
    for (auto k = 0; k < n; ++k) {
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (dist[i][k] != -1e9) {
                    if (dist[k][j] != -1e9) {
                        if (dist[i][j] < dist[i][k] + dist[k][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                            next[i][j] = next[i][k];
                        }
                    }
                }
            }
        }
    }
}

static void rePath(int u, int v,
                   std::vector<std::vector<int> > &next,
                   std::vector<std::vector<int> > &flights,
                   std::vector<int> &path) {
    if (next[u][v] == -1 || u == v) {
        return;
    } else {
        if (next[u][v] == v) {
            if (flights[u][v] != -1) {
                path.push_back(flights[u][v]);
            }

            return;
        } else {
            rePath(u, next[u][v], next, flights, path);
            rePath(next[u][v], v, next, flights, path);
        }
    }
}

static bool сycle(std::vector<std::vector<double> > &dist,
                  std::vector<int> &concerts,
                  int n, int k) {
    int u, v;
    for (auto i = 0; i < n; ++i) {
        if (dist[i][i] > 0) {
            for (auto j = 0; j < k - 1; ++j) {
                u = concerts[j];
                v = concerts[j + 1];

                if (dist[u][i] != -1e9 && dist[i][v] != -1e9) {
                    return true;
                }
            }
        }
    }

    return false;
}

void pink_floyd() {
    int n;
    std::cin >> n;

    int m, k;
    std::cin >> m >> k;

    std::vector<int> concerts(k);

    std::vector dist(n, std::vector(n, -1e9));
    std::vector next(n, std::vector(n, -1));

    for (auto i = 0; i < n; ++i) {
        dist[i][i] = 0;
        next[i][i] = i;
    }

    std::vector flights(n, std::vector(n, -1));

    for (auto i = 0; i < m; ++i) {
        int b, e, w;
        std::cin >> b >> e >> w;
        if (w > dist[b - 1][e - 1]) {
            dist[b - 1][e - 1] = w;
            next[b - 1][e - 1] = e - 1;
            flights[b - 1][e - 1] = i + 1;
        }
    }

    FloydWarshall(dist, next, n);


    for (auto i = 0; i < k; ++i) {
        std::cin >> concerts[i];
        concerts[i]--;
    }

    if (сycle(dist, concerts, n, k)) {
        std::cout << "infinitely kind";
        return;
    }

    std::vector<int> ans;

    for (auto i = 0; i < k - 1; ++i) {
        std::vector<int> path;

        rePath(concerts[i], concerts[i + 1], next, flights, path);
        ans.insert(ans.end(), path.begin(), path.end());
    }

    std::cout << ans.size() << std::endl;

    for (auto i: ans) {
        std::cout << i << " ";
    }
}
