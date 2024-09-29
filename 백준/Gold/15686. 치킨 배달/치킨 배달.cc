// baekjoon 15686

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
    vector<point> stores, houses;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;

            if (tmp == 2) {
                stores.push_back({ i, j });
            } else if (tmp == 1) {
                houses.push_back({ i, j });
            }
        }
    }

    vector<int> comb(stores.size(), 1);
    fill(comb.begin(), comb.end() - m, 0);

    int ans = 0x7fffffff;

    do {
        int total = 0;
        for (auto [hx, hy] : houses) {
            int minDist = 0x7fffffff;
            for (int i = 0; i < stores.size(); ++i) {
                if (!comb[i])
                    continue;

                auto [sx, sy] = stores[i];
                int distance = abs(hx - sx) + abs(hy - sy);
                minDist = min(distance, minDist);
            }
            total += minDist;
        }
        ans = min(ans, total);
    } while (next_permutation(comb.begin(), comb.end()));
    cout << ans;
}