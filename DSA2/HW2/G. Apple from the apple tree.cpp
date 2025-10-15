#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

int apple_tree() {
    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n), z(n), r(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i] >> z[i] >> r[i];
    }

    std::vector<bool> f(n, false);
    std::queue<int> q;
    q.push(0);
    f[0] = true;

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        int cz = z[c] - 2 * r[c];

        for (int j = 0; j < n; ++j) {
            if (!f[j]) {
                int dx = x[c] - x[j];
                int dy = y[c] - y[j];

                int d = dx * dx + dy * dy;

                int rs = r[c] + r[j];

                if (d > rs * rs) {
                    continue;
                }
                int jz = z[j] - 2 * r[j];

                if (cz >= jz) {
                    f[j] = true;
                    q.push(j);
                }
            }
        }
    }

    std::vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (f[i]) res.push_back(i + 1);
    }

    std::cout << res.size() << '\n';
    for (size_t i = 0; i < res.size(); ++i) {
        if (i > 0) std::cout << ' ';
        std::cout << res[i];
    }
    std::cout << '\n';

    return 0;
}
