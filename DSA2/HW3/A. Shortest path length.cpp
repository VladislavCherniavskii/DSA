#include <iostream>
#include <vector>
#include <queue>

static int bfs(size_t N,
               std::vector<std::vector<size_t> > &g,
               size_t start,
               size_t end) {
    std::vector<size_t> dist(N + 1, 1e9);
    std::queue<size_t> q;

    dist[start] = 0;
    q.push(start);

    if (start == end) {
        return 0;
    }

    while (!q.empty()) {
        size_t now = q.front();
        q.pop();

        for (auto neig = 1; neig <= N; ++neig) {
            if (g[now][neig] == 1 && dist[neig] == 1e9) {
                dist[neig] = dist[now] + 1;
                q.push(neig);

                if (neig == end) {
                    return dist[neig];
                }
            }
        }
    }

    return -1;
}

void shortest_path_length() {
    size_t N;
    std::cin >> N;
    std::vector g(N + 1, std::vector<size_t>(N + 1));

    for (auto i = 1; i <= N; ++i) {
        for (auto j = 1; j <= N; ++j) {
            std::cin >> g[i][j];
        }
    }

    size_t start, end;
    std::cin >> start >> end;

    std::cout << bfs(N, g, start, end);
}
