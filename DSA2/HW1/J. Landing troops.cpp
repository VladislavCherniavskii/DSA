#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Cell {
    int height;
    int x;
    int y;

    Cell(int h, int i, int j) : height(h), x(i), y(j) {
    }
};

bool compare_cells(const Cell &a, const Cell &b) {
    return a.height < b.height;
}

int landing_troops() {
    size_t n;
    size_t m;
    std::cin >> n >> m;
    std::vector height(n, std::vector<int>(m));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cin >> height[i][j];
        }
    }

    std::vector<Cell> cells;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cells.emplace_back(height[i][j], i, j);
        }
    }

    std::sort(cells.begin(), cells.end(), compare_cells);

    std::vector v(n, std::vector<bool>(m));

    size_t traps = 0;
    const int ways_to_neig[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (auto &cell: cells) {
        size_t x = cell.x;
        size_t y = cell.y;

        if (!v[x][y]) {
            traps++;
            std::queue<std::pair<size_t, size_t> > q;
            q.push({x, y});
            v[x][y] = true;

            while (!q.empty()) {
                auto [now_x, now_y] = q.front();
                q.pop();

                for (const auto &neig: ways_to_neig) {
                    int x = now_x + neig[0];
                    int y = now_y + neig[1];

                    if (x >= 0 && x < n && y >= 0 && y < m) {
                        if (!v[x][y] && height[x][y] >= height[now_x][now_y]) {
                            v[x][y] = true;
                            q.push({x, y});
                        }
                    }
                }
            }
        }
    }

    std::cout << traps;

    return 0;
}
