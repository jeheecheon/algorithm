// baekjoon 1325

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using point = pair<int, int>;
using ll = long long;

vector<pair<int, int>> dirs = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    vector<int> adjs[N + 1];

    while (M--) {
        int a, b;
        cin >> a >> b;
        adjs[b].push_back(a);
    }

    vector<int> cnts(N + 1, 0);
    int maxiCnt = 0;
    for (int i = 1; i <= N; ++i) {
        vector<bool> vis(N + 1, false);
        int cnt = 0;

        queue<int> Q;
        Q.push(i);
        vis[i] = true;
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();

            for (int next : adjs[cur]) {
                if (vis[next])
                    continue;
                vis[next] = true;
                Q.push(next);
                vis[next] = true;
                ++cnt;
            }
        }
        cnts[i] = cnt;
        maxiCnt = max(maxiCnt, cnt);
    }

    for (int i = 1; i <= N; ++i) {
        if (maxiCnt == cnts[i]) {
            cout << i << ' ';
        }
    }
}