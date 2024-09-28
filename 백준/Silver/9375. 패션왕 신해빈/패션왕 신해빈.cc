// baekjoon 9375

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        map<string, int> M;
        string str;

        for (int i = 0; i < N; ++i) {
            cin >> str >> str;
            ++M[str];
        }

        int ans = 1;
        for (auto [k, v] : M) 
            ans *= v + 1;
        
        cout << ans - 1 << endl;
    }
}