#include <iostream>
#include <vector>

static auto FB(int n) {
    std::vector<int> dist(n, 1e9);
    dist[0] = 0;

    bool flag;
    for (auto k = 0; k < n; ++k) {
        flag = false;

        for (auto i = 0; i < n; ++i) {
            if (dist[i] == 1e9) {
                continue;
            }

            for (int j = i + 1; j < n; ++j) {
                if (dist[j] > dist[i] + (179 * (i + 1) + 719 * (j + 1)) % 1000 - 500) {
                    dist[j] = dist[i] + (179 * (i + 1) + 719 * (j + 1)) % 1000 - 500;
                    flag = true;
                }
            }
        }

        if (!flag) {
            break;
        }
    }

    return dist[n - 1];
}

void FordBellman() {
    int n;
    std::cin >> n;

    std::cout << FB(n);
}
