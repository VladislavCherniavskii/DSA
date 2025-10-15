#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

static int bfs(int N,
               const std::vector<std::vector<int> > &g,
               std::vector<int> &from,
               int start,
               int end) {
    std::vector<int> dist(N + 1, 1e9);
    std::queue<int> q;

    dist[start] = 0;
    q.push(start);

    if (start == end) {
        return 0;
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto neig = 1; neig <= N; ++neig) {
            if (g[now][neig] == 1 && dist[neig] == 1e9) {
                dist[neig] = dist[now] + 1;

                from[neig] = now;
                q.push(neig);

                if (neig == end) {
                    return dist[neig];
                }
            }
        }
    }

    return -1;
}

static void getPath(std::vector<int> &path,
                    const std::vector<int> &from,
                    int end) {
    for (auto now = end; now != -1; now = from[now]) {
        path.push_back(now);
    }
    std::reverse(path.begin(), path.end());
}

void redundant_edges() {
    int N;
    std::cin >> N;

    std::vector g(N + 1, std::vector<int>(N + 1));

    for (auto i = 1; i <= N; ++i) {
        for (auto j = 1; j <= N; ++j) {
            std::cin >> g[i][j];
        }
    }

    int start, end;
    std::cin >> start >> end;

    std::vector<int> from(N + 1, -1);
    std::vector<int> path;

    int length = bfs(N, g, from, start, end);

    if (length > 0) {
        std::cout << length << std::endl;

        getPath(path, from, end);

        for (auto i = 0; i <= length; ++i) {
            std::cout << path[i] << ' ';
        }
    } else {
        std::cout << length;
    }
}
