// baekjoon 2309

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

vector<int> v(9);

int r = 7;
int n = 9;
bool printed = false;

void combi(int start, vector<int> b)
{
    if (b.size() == r) {
        if (printed)
            return;

        int sum = 0;
        for (auto i : b)
            sum += v[i];

        if (sum != 100)
            return;

        printed = true;
        for (auto i : b)
            cout << v[i] << endl;
    } else {
        for (int i = start + 1; i < n; ++i) {
            b.push_back(i);
            combi(i, b);
            b.pop_back();
        }
    }
}

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    for (int i = 0; i < 9; ++i)
        cin >> v[i];
        
    sort(v.begin(), v.end());
    combi(-1, vector<int>());

    return 0;
}
