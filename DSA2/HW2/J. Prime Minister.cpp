#include <iostream>
#include <vector>
#include <algorithm>

static void dfs(int v, int p,
         std::vector<std::vector<int> > &adj,
         std::vector<int> &tin,
         std::vector<int> &low,
         std::vector<char> &visited,
         std::vector<char> &containsE,
         int &timer, int E,
         std::vector<char> &isRes) {
    visited[v] = 1;
    tin[v] = low[v] = ++timer;
    if (v == E) {
        containsE[v] = 1;
    }

    for (int to: adj[v]) {
        if (to == p) {
            continue;
        }

        if (visited[to]) {
            if (tin[to] < low[v]) {
                low[v] = tin[to];
            }
        } else {
            dfs(to, v, adj, tin, low, visited, containsE, timer, E, isRes);
            if (low[to] < low[v]) {
                low[v] = low[to];
            }
            if (p != -1) {
                if (containsE[to] && low[to] >= tin[v]) {
                    isRes[v] = 1;
                }
            }
            if (containsE[v] || containsE[to]) {
                containsE[v] = 1;
            }
        }
    }
}

int prime_minister() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    if (!(std::cin >> N >> M)) {
        return 0;
    }

    std::vector<std::vector<int> > adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int S, E;
    std::cin >> S >> E;

    std::vector<int> tin(N + 1, 0);
    std::vector<int> low(N + 1, 0);
    std::vector<char> visited(N + 1, 0);
    std::vector<char> containsE(N + 1, 0);
    std::vector<char> isRes(N + 1, 0);
    int timer = 0;

    dfs(S, -1, adj, tin, low, visited, containsE, timer, E, isRes);

    if (!visited[E]) {
        std::cout << 0 << '\n';
        return 0;
    }

    std::vector<int> answer;
    for (int i = 1; i <= N; ++i) {
        if (isRes[i] && i != S && i != E) {
            answer.push_back(i);
        }
    }

    std::sort(answer.begin(), answer.end());

    std::cout << answer.size() << '\n';
    for (int x: answer) {
        std::cout << x << '\n';
    }

    return 0;
}
