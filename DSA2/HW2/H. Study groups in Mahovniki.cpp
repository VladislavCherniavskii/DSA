#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int study_groups() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int> > reverse_edges(N + 1);
    std::vector<int> in_degree(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; ++j) {
            int dep;
            std::cin >> dep;
            reverse_edges[i].push_back(dep);
            in_degree[dep]++;
        }
    }

    std::priority_queue<int> heap;

    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] == 0) {
            heap.push(i);
        }
    }

    std::vector<int> result;

    while (!heap.empty()) {
        int u = heap.top();
        heap.pop();
        result.push_back(u);
        for (int v: reverse_edges[u]) {
            if (--in_degree[v] == 0) {
                heap.push(v);
            }
        }
    }

    std::reverse(result.begin(), result.end());

    for (size_t i = 0; i < result.size(); ++i) {
        if (i != 0) {
            std::cout << ' ';
        }
        std::cout << result[i];
    }

    return 0;
}
