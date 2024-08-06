// baekjoon 13549

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({ 0, N });
    vector<int> dist(100001, 0x7fffffff);
    dist[N] = 0;

    while (!PQ.empty()) {
        auto [w, p] = PQ.top();
        PQ.pop();

        if (w > dist[p] || p == K)
            continue;

        pair<int, int> nextPos[] = { { 1, p + 1 }, { 1, p - 1 }, { 0, p * 2 } };

        for (auto [dirW, dirP] : nextPos) {
            auto [nxtW, nxtP] = pair { w + dirW, dirP };
            if (nxtP > 100000 || nxtP < 0 || nxtW >= dist[nxtP])
                continue;
            
            dist[nxtP] = nxtW;
            PQ.push({nxtW, nxtP});
        }
    }

    cout << dist[K];
}