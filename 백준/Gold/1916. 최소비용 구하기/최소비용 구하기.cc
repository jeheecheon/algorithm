#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int N, M; // 도시 개수, 버스 개수
    cin >> N >> M;

    vector<vector<pair<int, int>>> busses(N + 1);
    for (int i = 0; i < M; ++i) {
        int st, end, val; // 출발 도시, 도착 도시, 비용
        cin >> st >> end >> val;
        busses[st].emplace_back(end, val);
    }

    int st, dest;
    cin >> st >> dest;
    vector<int> dist(N + 1, 0x3f3f3f3f);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({0, st});
    dist[st] = 0;
    while (!PQ.empty()) {
        auto [accWeight, curBus] = PQ.top();
        PQ.pop();

        if (accWeight > dist[curBus])
            continue;

        for (auto [nxtBus, weight] : busses[curBus]) {
            if (weight + dist[curBus] < dist[nxtBus]) {
                dist[nxtBus] = weight + dist[curBus];
                PQ.push({dist[nxtBus], nxtBus});
            }
        }
    }

    cout << dist[dest];
}