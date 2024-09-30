// baekjoon 14497

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

pair<int, int> dirs[] = {
    {0, 1}, {1, 0}, {-1, 0}, {0, -1}
};

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1, --x2, --y1, --y2;

    string board[N];
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    int cnt = 0;
    while (1) {
        ++cnt;
        queue<pair<int, int>> Q;
        Q.push({ x1, y1 });
        vector<vector<bool>> vis(N, vector<bool>(M, false));
        vis[x1][y1] = true;

        while (!Q.empty()) {
            auto [cx, cy] = Q.front();
            Q.pop();

            for (auto [dx, dy] : dirs) {
                auto [nx, ny] = make_pair(cx + dx, cy + dy);

                if (nx < 0 || nx >= N || ny < 0 || ny >= M
                    || vis[nx][ny])
                    continue;
                
                vis[nx][ny] = true;
                if (board[nx][ny] == '1') {
                    board[nx][ny] = '0';
                    continue;
                }
                if (board[nx][ny] == '#') {
                    cout << cnt;
                    return 0;
                }
                Q.push({nx, ny});
            }
        }
    }
}
