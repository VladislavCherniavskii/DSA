#include <iostream>
#include <vector>
#include <queue>

void fleas() {
    int N, M;
    std::cin >> N >> M;

    int S, T;
    std::cin >> S >> T;

    S--;
    T--;

    int Q;
    std::cin >> Q;

    std::vector grid(N, std::vector<int>(M, 0));
    for (auto i = 0; i < Q; ++i) {
        int x, y;
        std::cin >> x >> y;
        grid[x - 1][y - 1] = 1;
    }

    std::vector dist(N, std::vector<int>(M, 1e9));
    std::queue<std::pair<int, int> > q;

    dist[S][T] = 0;
    q.push({S, T});

    int c = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (grid[x][y] == 1) {
            c += dist[x][y];
            Q--;
            if (Q == 0) {
                break;
            }
        }

        if (x + 2 < N) {
            if (y + 1 < M && dist[x + 2][y + 1] == 1e9) {
                dist[x + 2][y + 1] = dist[x][y] + 1;
                q.push({x + 2, y + 1});
            }
            if (y - 1 >= 0 && dist[x + 2][y - 1] == 1e9) {
                dist[x + 2][y - 1] = dist[x][y] + 1;
                q.push({x + 2, y - 1});
            }
        }

        if (x - 2 >= 0) {
            if (y + 1 < M && dist[x - 2][y + 1] == 1e9) {
                dist[x - 2][y + 1] = dist[x][y] + 1;
                q.push({x - 2, y + 1});
            }
            if (y - 1 >= 0 && dist[x - 2][y - 1] == 1e9) {
                dist[x - 2][y - 1] = dist[x][y] + 1;
                q.push({x - 2, y - 1});
            }
        }

        if (x + 1 < N) {
            if (y + 2 < M && dist[x + 1][y + 2] == 1e9) {
                dist[x + 1][y + 2] = dist[x][y] + 1;
                q.push({x + 1, y + 2});
            }
            if (y - 2 >= 0 && dist[x + 1][y - 2] == 1e9) {
                dist[x + 1][y - 2] = dist[x][y] + 1;
                q.push({x + 1, y - 2});
            }
        }

        if (x - 1 >= 0) {
            if (y + 2 < M && dist[x - 1][y + 2] == 1e9) {
                dist[x - 1][y + 2] = dist[x][y] + 1;
                q.push({x - 1, y + 2});
            }
            if (y - 2 >= 0 && dist[x - 1][y - 2] == 1e9) {
                dist[x - 1][y - 2] = dist[x][y] + 1;
                q.push({x - 1, y - 2});
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 1 && dist[i][j] == 1e9) {
                std::cout << -1 << std::endl;
            }
        }
    }

    std::cout << c << std::endl;
}
