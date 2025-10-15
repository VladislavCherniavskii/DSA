#include <iostream>
#include <vector>
#include <set>

static void dfs(int now,
         std::vector<std::vector<size_t> > &g,
         std::vector<bool> &v, std::vector<size_t> &tin,
         std::vector<size_t> &up, std::set<size_t> &art_point,
         int par, size_t timer, bool is_root) {
    v[now] = true;
    tin[now] = up[now] = timer++;
    int children = 0;

    for (size_t i = 0; i < g[now].size(); ++i) {
        size_t neig = g[now][i];

        if (neig == par) {
            continue;
        }

        if (v[neig]) {
            up[now] = std::min(up[now], tin[neig]);
        } else {
            dfs(neig, g, v, tin, up, art_point, now, timer, false);

            up[now] = std::min(up[now], up[neig]);
            children++;

            if (!is_root && up[neig] >= tin[now]) {
                art_point.insert(now);
            }
        }
    }

    if (is_root && children > 1) {
        art_point.insert(now);
    }
}

int articulation_points() {
    size_t N, M;
    std::cin >> N >> M;

    std::vector<std::vector<size_t> > g(N + 1);

    for (auto i = 1; i <= M; ++i) {
        size_t u1, u2;
        std::cin >> u1 >> u2;
        g[u1].push_back(u2);
        g[u2].push_back(u1);
    }

    std::vector<size_t> tin(N + 1);
    std::vector<size_t> up(N + 1);
    std::vector<bool> v(N + 1);
    std::set<size_t> art_point;

    for (auto i = 1; i <= N; ++i) {
        if (!v[i]) {
            dfs(i, g, v, tin, up, art_point, -1, 0, true);
        }
    }

    std::cout << art_point.size() << '\n';
    for (auto i: art_point) {
        std::cout << i << '\n';
    }

    return 0;
}
