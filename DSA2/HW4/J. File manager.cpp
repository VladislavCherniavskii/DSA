#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <array>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <utility>
#include <functional>

static struct TrieNode {
    std::array<int, 26> nxt;
    int parent;
    char pchar;
    int depth;
    std::vector<int> idx;

    TrieNode(int parent_ = -1, char pchar_ = 0, int depth_ = 0) {
        parent = parent_;
        pchar = pchar_;
        depth = depth_;
        nxt.fill(-1);
    }
};

static struct State {
    int type;
    int u;
    int node;

    State() : type(0), u(0), node(0) {
    }

    State(int t, int uu, int n) : type(t), u(uu), node(n) {
    }

    bool operator==(State const &o) const {
        return type == o.type && u == o.u && node == o.node;
    }
};

static struct StateHash {
    std::size_t operator()(State const &s) const noexcept {
        std::uint64_t v = (std::uint64_t)(s.type & 0xFF);
        v = (v << 20) ^ (std::uint64_t)(s.u & 0xFFFFF);
        v = (v << 24) ^ (std::uint64_t)(s.node & 0xFFFFFF);
        return std::hash<std::uint64_t>()(v);
    }
};

static struct StateEq {
    bool operator()(State const &a, State const &b) const noexcept {
        return a == b;
    }
};

static struct PQComparator {
    bool operator()(const std::pair<int, State> &a, const std::pair<int, State> &b) const {
        return a.first > b.first;
    }
};

static bool starts(std::vector<TrieNode> &trie, int node, int file_index, std::vector<std::string> &names) {
    int d = trie[node].depth;
    if (d == 0) {
        return true;
    }

    const std::string &s = names[file_index];
    if ((int)s.size() < d) {
        return false;
    }
    int cur = 0;
    for (int i = 0; i < d; ++i) {
        int c = s[i] - 'a';
        if (trie[cur].nxt[c] == -1) {
            return false;
        }

        cur = trie[cur].nxt[c];
    }

    return cur == node;
}

static void relax(std::unordered_map<State, int, StateHash, StateEq> &dist,
                  std::unordered_map<State, std::pair<State, std::string>, StateHash, StateEq> &prev,
                  std::priority_queue<std::pair<int, State>, std::vector<std::pair<int, State>>, PQComparator> &pq,
                  State &to, int newcost, State &from, const std::string &action) {
    auto it = dist.find(to);
    if (it == dist.end() || newcost < it->second) {
        dist[to] = newcost;
        prev[to] = std::make_pair(from, action);
        pq.push(std::make_pair(newcost, to));
    }
}

void file_manager() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    if (!(std::cin >> N)) {
        return;
    }

    std::vector<std::string> names(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> names[i];
    }

    int k;
    std::cin >> k;

    std::vector<int> a(k);

    for (int i = 0; i < k; ++i) {
        std::cin >> a[i];
        --a[i];
    }

    std::vector<TrieNode> trie;
    trie.emplace_back(-1, 0, 0);

    for (int i = 0; i < N; ++i) {
        int cur = 0;
        trie[cur].idx.push_back(i);

        for (char ch : names[i]) {
            int c = ch - 'a';
            if (trie[cur].nxt[c] == -1) {
                trie[cur].nxt[c] = (int)trie.size();
                trie.emplace_back(cur, ch, trie[cur].depth + 1);
            }

            cur = trie[cur].nxt[c];
            trie[cur].idx.push_back(i);
        }
    }

    int cur_file = 0;
    for (int step = 0; step < k; ++step) {
        int target = a[step];

        State start{0, cur_file, 0};
        State goal{0, target, 0};

        std::unordered_map<State, int, StateHash, StateEq> dist;
        std::unordered_map<State, std::pair<State, std::string>, StateHash, StateEq> prev;

        std::priority_queue<std::pair<int, State>, std::vector<std::pair<int, State>>, PQComparator> pq;

        dist[start] = 0;
        prev[start] = std::make_pair(State{-1, -1, -1}, std::string());

        pq.push(std::make_pair(0, start));

        while (!pq.empty()) {
            std::pair<int, State> pr = pq.top();
            pq.pop();

            int dcur = pr.first;
            State s = pr.second;

            auto itd = dist.find(s);
            if (itd == dist.end()) {
                continue;
            }

            if (dcur != itd->second) {
                continue;
            }

            if (s.type == goal.type && s.u == goal.u && s.node == goal.node) {
                break;
            }

            if (s.type == 0) {
                int u = s.u;

                State downst{0, (u + 1) % N, 0};
                relax(dist, prev, pq, downst, dcur + 1, s, "down");

                State upst{0, (u - 1 + N) % N, 0};
                relax(dist, prev, pq, upst, dcur + 1, s, "up");

                State altst{1, u, 0};
                relax(dist, prev, pq, altst, dcur + 1, s, "Alt");
            } else {
                int u = s.u;
                int node = s.node;

                for (int c = 0; c < 26; ++c) {
                    int nxt = trie[node].nxt[c];
                    if (nxt != -1) {
                        State s2{1, u, nxt};
                        std::string action(1, char('a' + c));

                        relax(dist, prev, pq, s2, dcur + 1, s, action);
                    }
                }
                int land;
                if (trie[node].idx.empty()) {
                    land = u;
                } else {
                    if (starts(trie, node, u, names)) {
                        land = u;
                    } else {
                        auto &lst = trie[node].idx;
                        auto it = std::upper_bound(lst.begin(), lst.end(), u);

                        if (it != lst.end()) {
                            land = *it;
                        } else {
                            land = lst[0];
                        }
                    }
                }

                State fstate{0, land, 0};
                relax(dist, prev, pq, fstate, dcur, s, "");
            }
        }

        std::vector<std::string> actions;
        State curst = goal;

        if (prev.find(curst) != prev.end()) {
            while (true) {
                auto pr = prev[curst];

                State from = pr.first;
                std::string action = pr.second;

                if (from.type == -1) {
                    break;
                }

                if (!action.empty()) {
                    actions.push_back(action);
                }

                curst = from;
            }

            std::reverse(actions.begin(), actions.end());
        }

        std::cout << actions.size() << '\n';
        for (std::size_t i = 0; i < actions.size(); ++i) {
            std::cout << actions[i] << '\n';
        }

        cur_file = target;
    }
}
