// baekjoon 9934

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using point = pair<int, int>;
using ll = long long;

vector<pair<int, int>> dirs = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

vector<int> tree[11];

int n;

void solve(int k) {
    if (k == n)
        return;

    solve(k + 1);
    int a;
    cin >> a;
    tree[k].push_back(a);
    solve(k + 1);
}

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    cin >> n;

    solve(0);
    for (int i = 0; i < n; ++i) {
        for (auto e : tree[i])
            cout << e << ' ';
        cout << endl;
    }
}