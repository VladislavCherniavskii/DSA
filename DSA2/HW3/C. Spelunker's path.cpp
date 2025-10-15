#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

void spelunker_path() {
    int N;
    std::cin >> N;
    std::vector cave(N, std::vector (N, std::vector<char>(N)));
    int startx, starty, startz;

    for (int z = 0; z < N; ++z) {
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                std::cin >> cave[x][y][z];
                if (cave[x][y][z] == 'S') {
                    startx = x;
                    starty = y;
                    startz = z;
                }
            }
        }
    }

    std::vector dist(N, std::vector (N, std::vector<long long>(N, -1)));
    std::queue<std::tuple<int, int, int>> q;

    dist[startx][starty][startz] = 0;
    q.push({startx, starty, startz});

    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();

        if (z == 0) {
            std::cout << dist[x][y][z];
            break;
        }

        if (z > 0 && cave[x][y][z-1] != '#' && dist[x][y][z-1] == -1) {
            dist[x][y][z-1] = dist[x][y][z] + 1;
            q.push({x, y, z-1});
        }

        if (z < N-1 && cave[x][y][z+1] != '#' && dist[x][y][z+1] == -1) {
            dist[x][y][z+1] = dist[x][y][z] + 1;
            q.push({x, y, z+1});
        }

        if (y > 0 && cave[x][y-1][z] != '#' && dist[x][y-1][z] == -1) {
            dist[x][y-1][z] = dist[x][y][z] + 1;
            q.push({x, y-1, z});
        }

        if (y < N-1 && cave[x][y+1][z] != '#' && dist[x][y+1][z] == -1) {
            dist[x][y+1][z] = dist[x][y][z] + 1;
            q.push({x, y+1, z});
        }

        if (x > 0 && cave[x-1][y][z] != '#' && dist[x-1][y][z] == -1) {
            dist[x-1][y][z] = dist[x][y][z] + 1;
            q.push({x-1, y, z});
        }

        if (x < N-1 && cave[x+1][y][z] != '#' && dist[x+1][y][z] == -1) {
            dist[x+1][y][z] = dist[x][y][z] + 1;
            q.push({x+1, y, z});
        }
    }
}
