#include <iostream>
#include <vector>

static void dfs(std::pair<size_t, size_t> now,
         std::vector<std::vector<std::vector<std::pair<size_t, size_t> > > > &graph,
         std::vector<std::vector<bool> > &v, size_t &counter) {
    v[now.first][now.second] = true;
    counter++;

    for (auto &neig: graph[now.first][now.second]) {
        if (!v[neig.first][neig.second]) {
            dfs(neig, graph, v, counter);
        }
    }
}

int room_area() {
    size_t N;
    std::cin >> N;
    std::vector lab(N, std::vector<char>(N));
    std::vector g(N, std::vector<std::vector<std::pair<size_t, size_t> > >(N));
    std::vector v(N, std::vector<bool>(N, false));
    size_t counter = 0;

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            std::cin >> lab[i][j];
        }
    }

    size_t x, y;
    std::cin >> x >> y;

    for (size_t i = 1; i < N - 1; ++i) {
        for (size_t j = 1; j < N - 1; ++j) {
            if (lab[i][j] == '.') {
                if (lab[i + 1][j] == '.') {
                    g[i][j].emplace_back(i + 1, j);
                    g[i + 1][j].emplace_back(i, j);
                }

                if (lab[i][j + 1] == '.') {
                    g[i][j].emplace_back(i, j + 1);
                    g[i][j + 1].emplace_back(i, j);
                }
            }
        }
    }

    dfs({x - 1, y - 1}, g, v, counter);

    std::cout << counter;

    return 0;
}
