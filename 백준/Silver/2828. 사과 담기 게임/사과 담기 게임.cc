// baekjoon 2828

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using point = pair<int, int>;

vector<pair<int, int>> dirs = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    int T;
    cin >> T;

    int lp = 1;
    int ans = 0;
    while (T--) {
        int app;
        cin >> app;

        int rp = lp + M - 1;
        int tmp = lp;
        if (app < lp) {
            lp = app;
        } else if (app > rp) {
            rp = app;
            lp = rp - M + 1;
        }

        ans += abs(lp - tmp);
    }

    cout << ans;
}