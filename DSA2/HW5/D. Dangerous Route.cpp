#include <iostream>
#include <vector>
#include <iomanip>

static void FloydWarshall(std::vector<std::vector<double> > &p, int n) {
    for (auto k = 1; k <= n; ++k) {
        for (auto i = 1; i <= n; ++i) {
            for (auto j = 1; j <= n; ++j) {
                if (p[i][k] > 1e-9) {
                    if (p[k][j] > 1e-9) {
                        if (p[i][k] * p[k][j] > p[i][j]) {
                            p[i][j] = p[i][k] * p[k][j];
                        }
                    }
                }
            }
        }
    }
}

void dangerous_route() {
    int N;
    std::cin >> N;

    std::vector p(N + 1, std::vector(N + 1, 0.0));

    int M, S, E;
    std::cin >> M >> S >> E;

    for (auto i = 1; i <= N; ++i) {
        for (auto j = 1; j <= N; ++j) {
            if (i == j) {
                p[i][j] = 1.0;
            } else {
                p[i][j] = 0.0;
            }
        }
    }

    for (auto i = 0; i < M; ++i) {
        int si, ei, pi;
        std::cin >> si >> ei >> pi;
        p[si][ei] = std::max(p[si][ei], 1.0 - pi / 100.0);
        p[ei][si] = std::max(p[ei][si], 1.0 - pi / 100.0);
    }

    FloydWarshall(p, N);

    std::cout << (1.0 - p[S][E]);
}
