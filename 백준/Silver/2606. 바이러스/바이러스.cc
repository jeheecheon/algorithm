// baekjoon 2606

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>());

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> Q;
    Q.push(1);
    vector<int> dist(N + 1, -1);
    dist[1] = 0;

    int cnt = -1;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        ++cnt;
        for (int nxt : graph[cur]) {
            if (dist[nxt] >= 0)
                continue;
            
            Q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }

    cout << cnt;
}
