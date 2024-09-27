// baekjoon 10808

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    vector<int> cnts(26, 0);
    string word;
    cin >> word;
    for (auto ch : word) {
        ++cnts[ch - 'a'];
    }

    for (auto e : cnts)
        cout << e << ' ';
}
