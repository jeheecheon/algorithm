// baekjoon 12869

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

    vector<int> scvs(3, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> scvs[i];

    queue<tuple<int, int, int, int>> Q;
    Q.push({ scvs[0], scvs[1], scvs[2], 0 });
    vector<vector<vector<bool>>> vis(61, vector<vector<bool>>(61, vector<bool>(61, false)));
    vis[scvs[0]][scvs[1]][scvs[2]] = true;

    while (!Q.empty()) {
        auto [a, b, c, cnt] = Q.front();
        Q.pop();

        if (!a && !b && !c) {
            cout << cnt;
            return 0;
        }

        vector<int> dams = { 1, 3, 9 };
        do {
            auto [na, nb, nc] = make_tuple(a - dams[0], b - dams[1], c - dams[2]);
            na = max(na, 0);
            nb = max(nb, 0);
            nc = max(nc, 0);

            if (vis[na][nb][nc])
                continue;
            vis[na][nb][nc] = true;
            
            Q.push({ na, nb, nc, cnt + 1 });
        } while (next_permutation(dams.begin(), dams.end()));
    }
}