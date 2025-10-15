#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

static void bfs(
    std::queue<std::tuple<size_t, size_t, size_t>> &q,
    std::vector<std::vector<int>> &grid,
    std::vector<std::vector<int>> &v,
    size_t N,
    size_t M)
{
    if (q.empty()) {
        return;
    }

    auto [x, y, steps] = q.front();
    q.pop();

    if (grid[x][y] == 2) {
        std::cout << steps << std::endl;
        exit(0);
    }

    auto nx = x;
    auto ny = y;

    while (true) {
        auto next_y = ny - 1;
        if (next_y < M && grid[nx][next_y] != 1) {
            ny = next_y;
        } else {
            break;
        }
        if (grid[nx][ny] == 2) {
            break;
        }
    }

    if (v[nx][ny] == -1 || steps + 1 < v[nx][ny]) {
        v[nx][ny] = steps + 1;
        q.push({nx, ny, steps + 1});
    }

    nx = x;
    ny = y;

    while (true) {
        auto next_y = ny + 1;
        if (next_y < M && grid[nx][next_y] != 1) {
            ny = next_y;
        } else {
            break;
        }
        if (grid[nx][ny] == 2) {
            break;
        }
    }

    if (v[nx][ny] == -1 || steps + 1 < v[nx][ny]) {
        v[nx][ny] = steps + 1;
        q.push({nx, ny, steps + 1});
    }

    nx = x;
    ny = y;

    while (true) {
        auto next_x = nx - 1;
        if (next_x < N && grid[next_x][ny] != 1) {
            nx = next_x;
        } else {
            break;
        }
        if (grid[nx][ny] == 2) {
            break;
        }
    }

    if (v[nx][ny] == -1 || steps + 1 < v[nx][ny]) {
        v[nx][ny] = steps + 1;
        q.push({nx, ny, steps + 1});
    }

    nx = x;
    ny = y;

    while (true) {
        auto next_x = nx + 1;
        if (next_x < N && grid[next_x][ny] != 1) {
            nx = next_x;
        } else {
            break;
        }
        if (grid[nx][ny] == 2) {
            break;
        }
    }

    if (v[nx][ny] == -1 || steps + 1 < v[nx][ny]) {
        v[nx][ny] = steps + 1;
        q.push({nx, ny, steps + 1});
    }

    bfs(q, grid, v, N, M);
}

void toy_maze() {
    size_t N, M;

    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> v;

    std::cin >> N >> M;
    grid.resize(N, std::vector<int>(M));
    v.resize(N, std::vector<int>(M, -1));

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            std::cin >> grid[i][j];
        }
    }

    std::queue<std::tuple<size_t, size_t, size_t>> q;

    q.push({0, 0, 0});
    v[0][0] = 0;

    bfs(q, grid, v, N, M);

    std::cout << -1;
}