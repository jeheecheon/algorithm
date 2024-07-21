#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int N, D;
    cin >> N >> D;

    vector<int> dist(10001, 0x7fffff);
    vector<vector<pair<int, int>>> roads(10001);

    for (int i = 0; i < D; ++i)
        roads[i].emplace_back(i + 1, 1);

    for (int i = 0; i < N; ++i) {
        int st, end, len;
        cin >> st >> end >> len;
        roads[st].emplace_back(end, len);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> PQ;
    PQ.push({ 0, 0 });
    dist[0] = 0;

    while (!PQ.empty()) {
        auto [st, curLength] = PQ.top();
        PQ.pop();

        if (curLength > dist[st])
            continue;

        for (auto [nxtDest, weight] : roads[st]) {
            if (nxtDest <= D && weight + dist[st] < dist[nxtDest]) {
                dist[nxtDest] = dist[st] + weight;
                PQ.push({ nxtDest, dist[nxtDest] });
            }
        }
    }

    cout << dist[D];
}