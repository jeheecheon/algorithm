// baekjoon 24445

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using point = pair<int, int>;
using ll = long long;

#define X first
#define Y second

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> graph(N + 1, vector<int>());
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i)
        sort(graph[i].begin(), graph[i].end(), greater<int>());

    vector<int> vis(N + 1, 0);
    queue<int> Q;
    Q.push(R);
    vis[R] = true;
    int cnt = 1;
    vis[R] = 1;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        for (int i : graph[cur]) {
            if (vis[i])
                continue;

            vis[i] = ++cnt;
            Q.push(i);
        }
    }

    for (int i = 1; i <= N; ++i)
        cout << vis[i] << '\n';
}