#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, K, X;
vector<vector<int>> roads;
vector<int> dists;

void solve()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    dists[X] = 0;
    PQ.push({ 0, X });

    while (!PQ.empty()) {
        auto [d, r] = PQ.top();
        PQ.pop();

        if (d > dists[r])
            continue;

        int nxtDist = dists[r] + 1;
        for (auto nxtRoad : roads[r]) {
            if (nxtDist < dists[nxtRoad]) {
                dists[nxtRoad] = nxtDist;
                PQ.push({ dists[nxtRoad], nxtRoad });
            }
        }
    }
}

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K >> X;

    roads.resize(N + 1);
    dists.assign(N + 1, 0x7fffff);

    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        roads[tmp1].emplace_back(tmp2);
    }

    solve();

    bool found = false;
    for (int i = 1; i <= N; ++i) {
        if (dists[i] == K) {
            found = true;
            cout << i << '\n';
        }
    }
    if (!found)
        cout << -1;
}