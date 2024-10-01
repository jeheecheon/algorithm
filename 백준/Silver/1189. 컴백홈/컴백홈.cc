// baekjoon 1189

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using point = pair<int, int>;
using ll = long long;

vector<point> dirs = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

string board[5];
bool vis[5][5];
int R, C, K;
int ans;

void solve(int x, int y, int k)
{
    if (k == K) {
        if (x == 0 && y == C - 1)
            ++ans;
        return;
    }

    for (auto [dx, dy] : dirs) {
        auto [nx, ny] = point { x + dx, y + dy };

        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            continue;
        
        if (vis[nx][ny] || board[nx][ny] == 'T')
            continue;
        
        vis[nx][ny] = true;
        solve(nx, ny, k + 1);
        vis[nx][ny] = false;
    }
}

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    cin >> R >> C >> K;
    for (int i = 0; i < R; ++i)
        cin >> board[i];

    vis[R - 1][0] = true;
    solve(R - 1, 0, 1);
    cout << ans;
}