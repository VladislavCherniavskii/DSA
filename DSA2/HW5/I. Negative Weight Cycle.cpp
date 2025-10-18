#include <iostream>
#include <vector>
#include <algorithm>

static int FB(int n,
              std::vector<int> &from,
              std::vector<int> &to,
              std::vector<long long> &w,
              std::vector<int> &parent) {
    std::vector<long long> dist(n, 0);
    parent.assign(n, -1);
    int x = -1;

    for (int iter = 0; iter < n; ++iter) {
        for (int e = 0; e < from.size(); ++e) {
            int u = from[e];
            int v = to[e];

            if (dist[from[e]] + w[e] < dist[to[e]]) {
                dist[to[e]] = dist[from[e]] + w[e];
                parent[to[e]] = from[e];
                x = to[e];
            }
        }
    }

    return x;
}

static std::vector<int> cycle(int x, std::vector<int> &parent, int n) {
    std::vector<int> res;
    if (x == -1) {
        return res;
    }

    int y = x;
    for (int i = 0; i < n; ++i) {
        y = parent[y];
    }

    int cur = y;
    do {
        res.push_back(cur);
        cur = parent[cur];
    } while (cur != y && cur != -1);
    std::reverse(res.begin(), res.end());
    if (!res.empty()) {
        res.push_back(res.front());
    }

    return res;
}

void negative_weight_cycle() {
    int n;
    std::cin >> n;

    std::vector<int> from;
    std::vector<int> to;
    std::vector<long long> w;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long weight;
            std::cin >> weight;

            if (weight != 1e5) {
                from.push_back(i);
                to.push_back(j);
                w.push_back(weight);
            }
        }
    }

    std::vector<int> parent;
    std::vector<int> cyc = cycle(FB(n, from, to, w, parent), parent, n);

    if (cyc.empty()) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        std::cout << cyc.size() << "\n";
        for (size_t i = 0; i < cyc.size(); ++i) {
            if (i) {
                std::cout << ' ';
            }

            std::cout << (cyc[i] + 1);
        }

        std::cout << "\n";
    }
}
