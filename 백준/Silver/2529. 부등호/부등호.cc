// baekjoon 2529

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using point = pair<int, int>;
using ll = long long;

vector<pair<int, int>> dirs = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

bool vis[10];
vector<int> paths;
vector<char> operators;
int N;

ll maxi = 0;
ll mini = 0x7fffffffffffffff;
string maxiStr;
string miniStr;

void solve(int l)
{
    if (l == N + 1) {
        string str = "";
        for (auto e : paths)
            str += to_string(e);

        ll converted = stoll(str);
        if (converted > maxi) {
            maxi = converted;
            maxiStr = str;
        }
        if (converted < mini) {
            mini = converted;
            miniStr = str;
        }
        return;
    }

    for (int i = 0; i < 10; ++i) {
        if (vis[i])
            continue;

        if (l != 0) {
            if (operators[l - 1] == '>') {
                if (paths.back() <= i)
                    continue;
            } else {
                if (paths.back() >= i)
                    continue;
            }
        }

        vis[i] = true;
        paths.push_back(i);
        solve(l + 1);
        paths.pop_back();
        vis[i] = false;
    }
}

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> N;
    char ch;
    while (cin >> ch)
        operators.push_back(ch);

    solve(0);
    cout << maxiStr << endl << miniStr;
}