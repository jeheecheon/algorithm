// baekjoon 2644

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    vector<vector<int>> graph(N + 1, vector<int>());

    int a, b;
    cin >> a >> b;
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    queue<int> Q;
    Q.push(a);
    vector<int> dist(N + 1, -1);
    dist[a] = 0;

    int ans = -1;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        if (cur == b) {
            ans = dist[cur];
            break;
        }

        for (int nxt : graph[cur]) {
            if (dist[nxt] >= 0)
                continue;

            Q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }

    cout << ans;
}
