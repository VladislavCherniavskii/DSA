#include <iostream>
#include <vector>

static bool dfs(size_t now, std::vector<std::vector<size_t> > &g,
         std::vector<bool> &v, std::vector<size_t> &colors, size_t color) {
    v[now] = true;
    colors[now] = color;

    for (auto neig: g[now]) {
        if (v[neig]) {
            if (colors[neig] == color) {
                return false;
            }
        } else {
            if (!dfs(neig, g, v, colors, 1 - color)) {
                return false;
            };
        }
    }

    return true;
}

bool check_bipartite(size_t N, std::vector<std::vector<size_t> > &g,
                     std::vector<bool> &v, std::vector<size_t> &colors) {
    for (size_t i = 1; i <= N; ++i) {
        if (!v[i]) {
            if (!dfs(i, g, v, colors, 0)) {
                return false;
            }
        }
    }

    return true;
}

void graph(double power, std::vector<std::pair<int, int> > &points,
           size_t N, std::vector<std::vector<size_t> > &g) {
    for (size_t i = 1; i <= N; ++i) {
        for (size_t j = i + 1; j <= N; ++j) {
            double dist_x = points[i].first - points[j].first;
            double dist_y = points[i].second - points[j].second;

            if (dist_x * dist_x + dist_y * dist_y <= 4 * power * power) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
}

int byte_radio() {
    size_t N;
    std::cin >> N;
    std::vector<std::pair<int, int> > points(N + 1);

    for (size_t i = 1; i < N + 1; i++) {
        std::cin >> points[i].first >> points[i].second;
    }

    double low = 0.0;
    double high = 1e9;
    double power = 0.0;

    std::vector<size_t> answer;

    while (high - low > 1e-9) {
        power = (low + high) / 2;

        std::vector<std::vector<size_t> > g(N + 1);
        std::vector<bool> v(N + 1);
        std::vector<size_t> colors(N + 1);

        graph(power, points, N, g);

        if (check_bipartite(N, g, v, colors)) {
            answer = colors;
            low = power;
        } else {
            high = power;
        }
    }

    std::cout.precision(15);
    std::cout << power << std::endl;

    for (size_t i = 1; i <= N; ++i) {
        std::cout << (answer[i] + 1) << ' ';
    }

    return 0;
}
