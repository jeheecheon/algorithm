// baekjoon 12851

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

    int N, M;
    cin >> N >> M;
    if (N == M) {
        cout << 0 << endl
             << 1;
        return 0;
    }
    vector<int> vis(100001, -1);
    vector<int> cnts(100001, 0);
    queue<int> Q;

    Q.push(N);
    vis[N] = 0;
    cnts[N] = 1;

    while (!Q.empty()) {
        auto here = Q.front();
        Q.pop();

        for (int there : { here - 1, here + 1, here * 2 }) {
            if (there < 0 || there > 100000)
                continue;

            if (vis[there] == -1) {
                vis[there] = vis[here] + 1;
                cnts[there] = cnts[here];
                Q.push(there);
            } else if (vis[there] == vis[here] + 1) {
                cnts[there] += cnts[here];
            }
        }
    }

    cout << vis[M] << endl << cnts[M];
}