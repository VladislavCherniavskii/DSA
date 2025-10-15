#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

static void find_bridges(int u, int parent, int &timer, std::vector<int> &disc,
                  std::vector<int> &low, std::vector<bool> &visited,
                  const std::vector<std::vector<std::pair<int, int> > > &graph,
                  std::vector<bool> &is_bridge) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;

    for (const auto &edge: graph[u]) {
        int v = edge.first;
        int id = edge.second;

        if (v == parent) continue;

        if (!visited[v]) {
            find_bridges(v, u, timer, disc, low, visited, graph, is_bridge);
            low[u] = std::min(low[u], low[v]);

            if (low[v] > disc[u]) {
                is_bridge[id] = true;
            }
        } else {
            low[u] = std::min(low[u], disc[v]);
        }
    }
}

static void dfs(int u, std::vector<bool> &visited,
         const std::vector<std::vector<std::pair<int, int> > > &graph,
         const std::vector<std::pair<int, int> > &edges,
         std::vector<int> &direction) {
    visited[u] = true;

    for (const auto &edge: graph[u]) {
        int v = edge.first;
        int id = edge.second;

        if (direction[id] == 0) {
            if (edges[id].first == u) {
                direction[id] = 1;
            } else {
                direction[id] = 2;
            }
        }

        if (!visited[v]) {
            dfs(v, visited, graph, edges, direction);
        }
    }
}

int one_way_traffic() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int> > > graph(n + 1);
    std::vector<std::pair<int, int> > edges(m);
    std::map<std::pair<int, int>, int> edge_count;

    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        edges[i] = {u, v};

        graph[u].push_back({v, i});
        graph[v].push_back({u, i});

        auto min_max = std::minmax(u, v);
        edge_count[{min_max.first, min_max.second}]++;
    }

    std::vector<int> disc(n + 1, 0);
    std::vector<int> low(n + 1, 0);
    std::vector<bool> visited(n + 1, false);
    std::vector<bool> is_bridge(m, false);

    int timer = 0;
    find_bridges(1, -1, timer, disc, low, visited, graph, is_bridge);

    for (int i = 0; i < m; i++) {
        if (is_bridge[i]) {
            auto edge = edges[i];
            auto min_max = std::minmax(edge.first, edge.second);
            if (edge_count[{min_max.first, min_max.second}] == 1) {
                std::cout << 0 << std::endl;
                return 0;
            }
        }
    }

    std::vector<int> direction(m, 0);
    std::fill(visited.begin(), visited.end(), false);
    dfs(1, visited, graph, edges, direction);

    for (int i = 0; i < m; i++) {
        if (direction[i] == 1) {
            std::cout << edges[i].first << " " << edges[i].second << "\n";
        } else {
            std::cout << edges[i].second << " " << edges[i].first << "\n";
        }
    }

    return 0;
}
