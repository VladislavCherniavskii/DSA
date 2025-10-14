#include <iostream>
#include <vector>

static bool dfs(size_t now, std::vector<std::vector<size_t> > &g,
         std::vector<size_t> &parent, size_t par,
         std::vector<size_t> &color, size_t &start, size_t &end) {
    color[now] = 1;

    for (size_t neig = 1; neig < g.size(); ++neig) {
        if (g[now][neig] && neig != par) {
            if (color[neig] == 0) {
                parent[neig] = now;

                if (dfs(neig, g, parent, now, color, start, end)) {
                    return true;
                }
            } else if (color[neig] == 1) {
                start = neig;
                end = now;

                return true;
            }
        }
    }

    color[now] = 2;

    return false;
}

int cycle_detection() {
    size_t n;
    std::cin >> n;
    std::vector g(n + 1, std::vector<size_t>(n + 1, 0));
    std::vector<size_t> parent(n + 1, 0);
    std::vector<size_t> color(n + 1, 0);
    size_t start = 0;
    size_t end = 0;

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            std::cin >> g[i][j];
        }
    }

    for (size_t v = 1; v <= n; ++v) {
        if (color[v] == 0 && dfs(v, g, parent, 0, color, start, end)) {
            break;
        }
    }

    if (start == 0) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;

        std::vector<size_t> cycle;
        cycle.push_back(start);

        for (size_t v = end; v != start; v = parent[v]) {
            cycle.push_back(v);
        }

        std::cout << cycle.size() << std::endl;
        for (auto v: cycle) {
            std::cout << v << " ";
        }
    }

    return 0;
}
