// baekjoon 16234

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
    int N, L, R;
    cin >> N >> L >> R;
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    bool pos = true;

    while (pos) {
        pos = false;
        vector<vector<bool>> vis(N, vector<bool>(N, false));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (vis[i][j])
                    continue;

                queue<point> Q;
                Q.push({ i, j });
                vis[i][j] = true;

                vector<point> paths;
                int sum = 0;

                while (!Q.empty()) {
                    auto [cx, cy] = Q.front();
                    Q.pop();

                    paths.push_back({ cx, cy });
                    sum += board[cx][cy];

                    for (auto [dx, dy] : dirs) {
                        int nx = cx + dx;
                        int ny = cy + dy;

                        if (nx < 0 || nx >= N || ny < 0 || ny >= N || vis[nx][ny])
                            continue;

                        int diff = abs(board[cx][cy] - board[nx][ny]);

                        if (diff >= L && diff <= R) {
                            Q.push({ nx, ny });
                            vis[nx][ny] = true;
                        }
                    }
                }

                if (paths.size() > 1) {
                    pos = true;
                    int average = sum / paths.size();
                    for (auto [x, y] : paths) {
                        board[x][y] = average;
                    }
                }
            }
        }

        if (pos)
            ++ans;
    }

    cout << ans;
}