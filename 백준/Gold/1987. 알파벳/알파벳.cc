// baekjoon 1987

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

pair<int, int> dirs[] = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

bool alpha[26];
bool vis[21][21];
int N, M;
string board[21];

int ans;

void dfs(int x, int y, int len)
{
    ans = max(ans, len);

    for (auto [dx, dy] : dirs) {
        auto [nx, ny] = make_pair(x + dx, y + dy);

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

        int idx = board[nx][ny] - 'A';

        if (vis[nx][ny] || alpha[idx])
            continue;

        vis[nx][ny] = true;
        alpha[idx] = true;
        dfs(nx, ny, len + 1);
        alpha[idx] = false;
        vis[nx][ny] = false;
    }
}

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    vis[0][0] = true;
    alpha[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << ans;
}
