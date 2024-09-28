// baekjoon 14502

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using point = pair<int, int>;
using ll = long long;

vector<pair<int, int>> dirs = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

int N, M;
int ans;
vector<point> emptySpaces;
vector<point> viruses;
int board[9][9];

int solve() {
    vector<vector<bool>> vis(N, vector<bool>(M, false));
    queue<point> Q;
    
    for (auto v : viruses) {
        Q.push(v);
        vis[v.first][v.second] = true;
    }

    while (!Q.empty()) {
        auto [cx, cy] = Q.front();
        Q.pop();

        for (auto [dx, dy] : dirs) {
            auto [nx, ny] = point { cx + dx, cy + dy};

            if (nx < 0 || nx >= N || ny < 0 || ny >= M
                || vis[nx][ny]
                || board[nx][ny] != 0)
                continue;
            
            Q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 0 && vis[i][j] == false)
                ++cnt;
        }
    }
    return cnt;
}

void combi(int start, int r) {
    if (r == 3) {
        ans = max(ans, solve());
    } else {
        for (int i = start; i < emptySpaces.size(); ++i) {
            auto [x, y] = emptySpaces[i];

            board[x][y] = 1;
            combi(i + 1, r + 1);
            board[x][y] = 0;
        }
    }
}

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 0)
                emptySpaces.push_back({i, j});
            else if (board[i][j] == 2)
                viruses.push_back({i, j});
        }
    }

    combi(0, 0);

    cout << ans;
}