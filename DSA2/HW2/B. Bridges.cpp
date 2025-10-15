#include <iostream>
#include <vector>
#include <set>

static void dfs(int now,
         std::vector<std::vector<size_t> > &g_vertex,
         std::vector<std::vector<int> > &g_edge,
         std::vector<bool> &visited, std::vector<size_t> &tin,
         std::vector<size_t> &low, std::set<size_t> &bridges,
         int parent_edge, size_t timer) {
    visited[now] = true;
    tin[now] = low[now] = timer;

    for (size_t i = 0; i < g_vertex[now].size(); ++i) {
        size_t neig = g_vertex[now][i];
        int edge_bridge = g_edge[now][i];

        if (edge_bridge == parent_edge) {
            continue;
        }

        if (visited[neig]) {
            low[now] = std::min(low[now], tin[neig]);
        } else {
            timer++;
            dfs(neig, g_vertex, g_edge, visited, tin, low, bridges, edge_bridge, timer);
            timer--;

            low[now] = std::min(low[now], low[neig]);

            if (low[neig] > tin[now]) {
                bridges.insert(edge_bridge);
            }
        }
    }
}

void find_bridges() {
    size_t N, M;
    size_t u1, u2;
    std::cin >> N >> M;

    std::vector<std::vector<size_t> > g_vertex(N + 1);
    std::vector<std::vector<int> > g_edge(N + 1);

    std::vector<size_t> tin(N + 1);
    std::vector<size_t> low(N + 1);
    std::vector<bool> visited(N + 1, false);
    std::set<size_t> bridges;

    for (auto i = 1; i <= M; ++i) {
        std::cin >> u1 >> u2;
        g_vertex[u1].push_back(u2);
        g_edge[u1].push_back(i);
        g_vertex[u2].push_back(u1);
        g_edge[u2].push_back(i);
    }

    for (auto i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i, g_vertex, g_edge, visited, tin, low, bridges, -1, 0);
        }
    }

    std::cout << bridges.size() << '\n';
    for (auto edge: bridges) {
        std::cout << edge << ' ';
    }
}
