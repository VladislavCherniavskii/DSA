#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

static std::vector<std::vector<int> > calculate(int count,
                                                std::vector<std::vector<std::pair<int, int> > > &connect) {
    std::vector matrix(count + 1, std::vector(count + 1, 0));

    for (int i = 1; i <= count; i++) {
        std::queue<int> q;
        q.push(i);

        std::vector<bool> visit(count + 1, false);
        visit[i] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (size_t j = 0; j < connect[cur].size(); j++) {
                int neighbor = connect[cur][j].first;
                int length = connect[cur][j].second;

                if (!visit[neighbor]) {
                    visit[neighbor] = true;
                    matrix[i][neighbor] = matrix[i][cur] + length;
                    q.push(neighbor);
                }
            }
        }
    }

    return matrix;
}

static std::pair<std::vector<double>, std::vector<int> > find(int count,
                                                              std::vector<std::vector<std::pair<int, double> > > &
                                                              graph) {
    double large = 1e18;

    std::vector dist(count + 1, large);

    std::vector prev(count + 1, -1);
    dist[1] = 0;

    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int> >, std::greater<std::pair<double,
        int> > > pq;
    pq.push(std::make_pair(0.0, 1));

    while (!pq.empty()) {
        double curdist = pq.top().first;
        int curcity = pq.top().second;
        pq.pop();

        if (curdist > dist[curcity]) continue;

        for (size_t j = 0; j < graph[curcity].size(); j++) {
            int neighbor = graph[curcity][j].first;
            double weight = graph[curcity][j].second;
            if (dist[neighbor] > curdist + weight) {
                dist[neighbor] = curdist + weight;
                prev[neighbor] = curcity;
                pq.push(std::make_pair(dist[neighbor], neighbor));
            }
        }
    }

    return std::make_pair(dist, prev);
}

static int findlast(int count,
                    std::vector<int> &time,
                    std::vector<double> &dist) {
    double maxtime = 0;
    int lastcity = 1;

    for (int i = 1; i <= count; i++) {
        double totaltime = time[i] + dist[i];
        if (totaltime > maxtime) {
            maxtime = totaltime;
            lastcity = i;
        }
    }

    return lastcity;
}

void by_sled() {
    int count;
    std::cin >> count;

    std::vector<int> time(count + 1);
    std::vector<int> speed(count + 1);
    for (int i = 1; i <= count; i++) {
        std::cin >> time[i] >> speed[i];
    }
    time[1] = 0;

    std::vector<std::vector<std::pair<int, int> > > connect(count + 1);

    for (int i = 0; i < count - 1; i++) {
        int a, b, length;
        std::cin >> a >> b >> length;
        connect[a].push_back(std::make_pair(b, length));
        connect[b].push_back(std::make_pair(a, length));
    }

    std::vector<std::vector<int> > matrix = calculate(count, connect);

    std::vector<std::vector<std::pair<int, double> > > graph(count + 1);
    for (int i = 1; i <= count; i++) {
        for (int k = 1; k <= count; k++) {
            if (i == k) continue;
            double travel = static_cast<double>(matrix[i][k]) / speed[i] + time[k];
            graph[k].push_back(std::make_pair(i, travel));
        }
    }

    std::pair<std::vector<double>, std::vector<int> > result = find(count, graph);
    std::vector<double> dist = result.first;
    std::vector<int> prev = result.second;

    int last = findlast(count, time, dist);
    double maxtime = time[last] + dist[last];

    std::vector<int> path;
    int cur = last;
    while (cur != -1) {
        path.push_back(cur);
        cur = prev[cur];
    }

    std::cout << std::fixed << std::setprecision(10) << maxtime << std::endl;

    for (size_t i = 0; i < path.size(); i++) {
        if (i > 0) std::cout << " ";
        std::cout << path[i];
    }

    std::cout << std::endl;
}
