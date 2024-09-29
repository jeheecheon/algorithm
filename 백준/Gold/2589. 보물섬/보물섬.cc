// baekjoon 2589

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
    int n, m;
    cin >> n >> m;
    string board[n];
    vector<point> ddang;
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'L') {
                ddang.push_back({ i, j });
            }
        }
    }

    int ans = 0;
    for (auto [lx, ly] : ddang) {
        vector<vector<int>> dist(n, vector<int>(m, -1));

        queue<point> Q;
        Q.push({ lx, ly });
        dist[lx][ly] = 0;

        int cnt = 0;
        while (!Q.empty()) {
            auto [cx, cy] = Q.front();
            Q.pop();

            for (auto [dx, dy] : dirs) {
                auto [nx, ny] = point { cx + dx, cy + dy };

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if (dist[nx][ny] >= 0 || board[nx][ny] == 'W')
                    continue;

                Q.push({ nx, ny });
                dist[nx][ny] = dist[cx][cy] + 1;
                cnt = max(cnt, dist[nx][ny]);
            }
        }
        ans = max(ans, cnt);

    }

    cout << ans;
}