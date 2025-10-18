#include <iostream>
#include <vector>


static auto TransClosure(std::vector<std::vector<bool>> &g, int n) {
    std::vector<std::vector<bool>> transclos = g;

    for (auto k = 1; k <= n; ++k) {
        for (auto i = 1; i <= n; ++i) {
            if (transclos[i][k]) {
                for (auto j = 1; j <= n; ++j) {
                    if (transclos[k][j]) {
                        transclos[i][j] = true;
                    }
                }
            }
        }
    }

    return transclos;
}


void transitive_closure() {
    int n;
    std::cin >> n;

    std::vector g(n + 1, std::vector (n + 1, false));

    for (auto i = 1; i <= n; ++i) {
        for (auto j = 1; j <= n; ++j) {
            int edge;
            std::cin >> edge;
            g[i][j] = edge;
        }
    }

    auto ans = TransClosure(g, n);

    for (auto i = 1; i <= n; ++i) {
        for (auto j = 1; j <= n; ++j) {
            std::cout << ans[i][j] << " ";
        }

        std::cout << std::endl;
    }
}
