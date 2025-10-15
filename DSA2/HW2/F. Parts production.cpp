#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

static void dfs(size_t now,
         std::vector<std::vector<size_t> > &g,
         std::vector<bool> &v,
         std::stack<size_t> &top_sort) {
    v[now] = true;

    for (auto neig: g[now]) {
        if (!v[neig]) {
            dfs(neig, g, v, top_sort);
        }
    }

    top_sort.push(now);
}

int parts_production() {
    size_t N;
    std::cin >> N;
    std::vector<long long> p(N + 1);

    for (auto i = 1; i <= N; ++i) {
        std::cin >> p[i];
    }

    std::vector<std::vector<size_t> > g(N + 1);
    std::vector<std::vector<size_t> > g_exp(N + 1);

    size_t k;
    size_t num;
    for (auto i = 1; i <= N; ++i) {
        std::cin >> k;
        while (k--) {
            std::cin >> num;
            g[num].push_back(i);
            g_exp[i].push_back(num);
        }
    }

    std::vector<bool> needed(N + 1, false);
    std::stack<size_t> st;

    st.push(1);
    while (!st.empty()) {
        size_t u = st.top();
        st.pop();

        if (needed[u]) {
            continue;
        }

        needed[u] = true;
        for (auto dep: g_exp[u]) {
            if (!needed[dep]) {
                st.push(dep);
            }
        }
    }

    long long total = 0;
    for (size_t i = 1; i <= N; ++i) {
        if (needed[i]) {
            total += p[i];
        }
    }

    std::stack<size_t> top_sort;
    std::vector<bool> v(N + 1, false);

    for (auto i = 1; i <= N; ++i) {
        if (!v[i]) dfs(i, g, v, top_sort);
    }

    std::vector<size_t> order;
    while (!top_sort.empty()) {
        size_t u = top_sort.top();
        top_sort.pop();

        if (needed[u]) {
            order.push_back(u);
        }
    }

    std::cout << total << ' ' << order.size() << "\n";
    for (size_t i = 0; i < order.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << order[i];
    }

    std::cout << "\n";

    return 0;
}
