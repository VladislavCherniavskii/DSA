#include <iostream>
#include <vector>
#include <queue>

static void FB(int n,
               std::vector<int> &from,
               std::vector<int> &to,
               std::vector<int> &w,
               std::vector<long long> &dist,
               std::vector<char> &bad) {
    dist.assign(n + 1, -1e9);
    dist[1] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int e = 0; e < from.size(); ++e) {
            int u = from[e];
            int v = to[e];
            int wt = w[e];

            if (dist[u] != -1e9 && dist[u] + wt > dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    bad.assign(n + 1, 0);
    for (int i = 0; i < from.size(); ++i) {
        int u = from[i];
        int v = to[i];
        int wt = w[i];

        if (dist[u] != -1e9 && dist[u] + wt > dist[v]) {
            bad[v] = 1;
            bad[u] = 1;
        }
    }
}

static void propagate(int n, std::vector<std::vector<int>> &adj, std::vector<char> &bad) {
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (bad[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];

            if (!bad[v]) {
                bad[v] = 1;
                q.push(v);
            }
        }
    }
}

void labyrinth_of_knowledge() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> from;
    std::vector<int> to;
    std::vector<int> w;

    from.reserve(m);
    to.reserve(m);
    w.reserve(m);

    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, wt;
        std::cin >> u >> v >> wt;

        from.push_back(u);
        to.push_back(v);
        w.push_back(wt);
        adj[u].push_back(v);
    }

    std::vector<long long> dist;
    std::vector<char> bad;

    FB(n, from, to, w, dist, bad);
    propagate(n, adj, bad);

    if (bad[n]) {
        std::cout << ":)\n";
    } else if (dist[n] == -1e9) {
        std::cout << ":(\n";
    } else {
        std::cout << dist[n] << "\n";
    }
}
