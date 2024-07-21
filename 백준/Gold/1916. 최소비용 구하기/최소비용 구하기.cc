#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> busses(N + 1);
    for (int i = 0; i < M; ++i) {
        int st, end, val;
        cin >> st >> end >> val;
        busses[st].emplace_back(end, val);
    }

    int st, dest;
    cin >> st >> dest;
    vector<int> dist(N + 1, 0x3f3f3f3f);

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> PQ;
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