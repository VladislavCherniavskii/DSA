#include <iostream>
#include <vector>
#include <deque>

void tsar_leonid_tractor() {
    int H, W;
    std::cin >> H >> W;
    std::vector grid(H + 2, std::vector<char>(W + 2, 'X'));
    
    for (int i = H; i >= 1; --i) {
        for (int j = 1; j <= W; ++j) {
            std::cin >> grid[i][j];
        }
    }

    int start_x, start_y;
    std::cin >> start_x >> start_y;

    int end_x, end_y;
    std::cin >> end_x >> end_y;

    std::vector visited(H + 2, std::vector(W + 2, std::vector(8, false)));
    std::deque<std::tuple<int, int, std::string, int>> dq;
    dq.push_back({start_y, start_x, "up", 0});

    while (!dq.empty()) {
        auto [y, x, dir, steps] = dq.front();
        dq.pop_front();

        int dir_index = -1;
        if      (dir == "E") {
            dir_index = 0;
        } else if (dir == "W") {
            dir_index = 1;
        } else if (dir == "N") {
            dir_index = 2;
        } else if (dir == "S") {
            dir_index = 3;
        } else if (dir == "NE") {
            dir_index = 4;
        } else if (dir == "NW") {
            dir_index = 5;
        } else if (dir == "SE") {
            dir_index = 6;
        } else if (dir == "SW") {
            dir_index = 7;
        } else if (dir == "up") {
            dir_index = 8;
        }

        if (dir_index < 8 && visited[y][x][dir_index]) {
            continue;
        }

        if (dir_index < 8) {
            visited[y][x][dir_index] = true;
        }

        if (x == end_x && y == end_y) {
            std::cout << steps;
            break;
        }
        
        if (grid[y + 1][x] == '.') {
            if (dir == "E") dq.push_front({y + 1, x, "E", steps});
            else dq.push_back({y + 1, x, "E", steps + 1});
        }

        if (grid[y - 1][x] == '.') {
            if (dir == "W") dq.push_front({y - 1, x, "W", steps});
            else dq.push_back({y - 1, x, "W", steps + 1});
        }

        if (grid[y][x + 1] == '.') {
            if (dir == "N") dq.push_front({y, x + 1, "N", steps});
            else dq.push_back({y, x + 1, "N", steps + 1});
        }

        if (grid[y][x - 1] == '.') {
            if (dir == "S") dq.push_front({y, x - 1, "S", steps});
            else dq.push_back({y, x - 1, "S", steps + 1});
        }

        if (grid[y + 1][x + 1] == '.') {
            if (dir == "NE") dq.push_front({y + 1, x + 1, "NE", steps});
            else dq.push_back({y + 1, x + 1, "NE", steps + 1});
        }

        if (grid[y - 1][x + 1] == '.') {
            if (dir == "NW") dq.push_front({y - 1, x + 1, "NW", steps});
            else dq.push_back({y - 1, x + 1, "NW", steps + 1});
        }

        if (grid[y + 1][x - 1] == '.') {
            if (dir == "SE") dq.push_front({y + 1, x - 1, "SE", steps});
            else dq.push_back({y + 1, x - 1, "SE", steps + 1});
        }

        if (grid[y - 1][x - 1] == '.') {
            if (dir == "SW") dq.push_front({y - 1, x - 1, "SW", steps});
            else dq.push_back({y - 1, x - 1, "SW", steps + 1});
        }
    }

    std::cout << -1;
}
