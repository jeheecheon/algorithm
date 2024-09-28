// baekjoon 2178

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

vector<pair<int, int>> dirs = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    string board[n + 1];
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, -1));

    for (int i = 1; i <= n; ++i) {
        cin >> board[i];
        board[i] = " " + board[i];
    }

    queue<pair<int, int>> Q;

    Q.push({ 1, 1 });
    vis[1][1] = 1;

    while (!Q.empty()) {
        auto [cx, cy] = Q.front();
        Q.pop();

        if (cx == n && cy == m) {
            cout << vis[cx][cy];
            return 0;
        }

        for (auto [dx, dy] : dirs) {
            auto [nx, ny] = make_pair(cx + dx, cy + dy);
            if (nx <= 0 || nx > n || ny <= 0 || ny > m
                || vis[nx][ny] >= 0 || board[nx][ny] == '0')
                continue;

            vis[nx][ny] = vis[cx][cy] + 1;
            Q.push({ nx, ny });
        }
    }
}