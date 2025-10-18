#include <iostream>
#include <vector>

static auto TransClosure(std::vector<std::vector<bool> > &g, int n) {
    std::vector<std::vector<bool> > transclos = g;

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (transclos[i][k]) {
                for (int j = 1; j <= n; ++j) {
                    if (transclos[k][j]) {
                        transclos[i][j] = true;
                    }
                }
            }
        }
    }

    return transclos;
}


void is_there_a_cycle() {
    int n;
    std::cin >> n;

    std::vector g(n + 1, std::vector(n + 1, false));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int edge;
            std::cin >> edge;
            g[i][j] = edge;
        }
    }

    auto transclos = TransClosure(g, n);

    for (int i = 1; i <= n; ++i) {
        if (transclos[i][i]) {
            std::cout << 1;

            return;
        }
    }

    std::cout << 0;
}
