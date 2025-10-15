#include <iostream>
#include <vector>
#include <queue>

static void bfs(int start,
                std::vector<std::vector<int> > &g,
                std::vector<std::vector<int> > &dist,
                std::queue<std::pair<int, int> > &q) {
    dist[start][0] = 0;
    q.emplace(start, 0);

    while (!q.empty()) {
        auto [v, par] = q.front();
        q.pop();

        for (auto i: g[v]) {
            if (dist[v][par] + 1 < dist[i][1 - par]) {
                q.emplace(i, 1 - par);
                dist[i][1 - par] = dist[v][par] + 1;
            }
        }
    }
}

static int minTimeVertex(std::vector<std::vector<std::vector<int> > > &dist_v,
                         int N, int M) {
    int min_time = 1e9;

    for (auto i = 0; i < N; ++i) {
        int max_1 = 0;
        int max_2 = 0;
        int has_1 = true;
        int has_2 = true;

        for (auto j = 0; j < M; ++j) {
            if (dist_v[j][i][0] != 1e9) {
                max_1 = std::max(max_1, dist_v[j][i][0]);
            } else {
                has_1 = false;
            }

            if (dist_v[j][i][1] != 1e9) {
                max_2 = std::max(max_2, dist_v[j][i][1]);
            } else {
                has_2 = false;
            }
        }

        if (has_1) {
            min_time = std::min(min_time, 2 * max_1);
        }

        if (has_2) {
            min_time = std::min(min_time, 2 * max_2);
        }
    }

    return min_time;
}

static int minTimeEdge(std::vector<std::vector<std::vector<int> > > &dist_v,
                       std::vector<std::pair<int, int> > &edges, int M) {
    int min_time;
    int min_d;
    bool valid;
    int now_mx;

    min_time = 1e9;

    for (auto &[u, v]: edges) {
        valid = true;
        now_mx = 0;

        for (auto i = 0; i < M; ++i) {
            min_d = 1e9;

            if (dist_v[i][u][0] != 1e9) {
                min_d = std::min(min_d, 2 * dist_v[i][u][0] + 1);
            }

            if (dist_v[i][u][1] != 1e9) {
                min_d = std::min(min_d, 2 * dist_v[i][u][1] + 1);
            }

            if (dist_v[i][v][0] != 1e9) {
                min_d = std::min(min_d, 2 * dist_v[i][v][0] + 1);
            }

            if (dist_v[i][v][1] != 1e9) {
                min_d = std::min(min_d, 2 * dist_v[i][v][1] + 1);
            }

            if (min_d == 1e9) {
                valid = false;
                break;
            }

            now_mx = std::max(now_mx, min_d);
        }
        if (valid) min_time = std::min(min_time, now_mx);
    }

    return min_time;
}

void robots() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int> > edges;
    std::vector<std::vector<int> > g(N);
    std::vector<int> robots;
    std::queue<std::pair<int, int> > q;

    for (auto i = 0; i < K; ++i) {
        int x, y;
        std::cin >> x >> y;
        edges.emplace_back(x - 1, y - 1);
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    int M;
    std::cin >> M;

    robots.resize(M);

    for (auto &i: robots) {
        std::cin >> i;
        i--;
    }

    std::vector dist_v(M, std::vector(N, std::vector<int>(2, 1e9)));

    for (auto i = 0; i < M; ++i) {
        bfs(robots[i], g, dist_v[i], q);
    }

    int v_time = minTimeVertex(dist_v, N, M);
    int e_time = minTimeEdge(dist_v, edges, M);
    int min_time = std::min(v_time, e_time);

    if (min_time == 1e9) {
        std::cout << -1;
    } else if (min_time % 2 == 0) {
        std::cout << min_time / 2;
    } else {
        std::cout << min_time / 2 << ".5";
    }
}
