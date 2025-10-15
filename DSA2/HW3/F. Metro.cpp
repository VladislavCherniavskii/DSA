#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

static auto st_lines(int M,
                     std::vector<std::vector<int> > const &lines,
                     std::vector<std::vector<int> > st_to_line) {
    for (auto i = 0; i < M; ++i) {
        for (auto j: lines[i]) {
            st_to_line[j].push_back(i);
        }
    }

    return st_to_line;
}


static bool st_neig(std::vector<int> &line, int B) {
    return std::ranges::any_of(line, std::bind_front(std::equal_to{}, B));
}


static int bfs(std::vector<std::vector<int> > &lines,
               std::vector<std::vector<int> > const &st_to_lines,
               int A, int B,
               std::vector<bool> v_lines,
               std::queue<std::pair<int, int> > q) {
    for (auto i: st_to_lines[A]) {
        v_lines[i] = true;
        q.emplace(i, 0);
    }

    while (!q.empty()) {
        auto [now, neigs] = q.front();
        q.pop();

        if (st_neig(lines[now], B)) {
            return neigs;
        }

        for (auto i: lines[now]) {
            for (auto j: st_to_lines[i]) {
                if (!v_lines[j]) {
                    q.emplace(j, neigs + 1);
                    v_lines[j] = true;
                }
            }
        }
    }

    return -1;
}

int metro() {
    int N, M;
    int P_i;
    int station;
    int A, B;
    std::cin >> N >> M;
    std::vector<std::vector<int> > lines(M);

    for (auto &i: lines) {
        std::cin >> P_i;
        i.clear();
        for (auto j = 0; j < P_i; ++j) {
            std::cin >> station;
            i.emplace_back(station);
        }
    }

    std::cin >> A >> B;

    std::vector v_lines(M, false);
    std::queue<std::pair<int, int> > q;
    std::vector<std::vector<int> > st_to_line(N + 1);

    auto st_to_lines = st_lines(M, lines, st_to_line);

    std::cout << bfs(lines, st_to_lines, A, B, v_lines, q);

    return 0;
}
