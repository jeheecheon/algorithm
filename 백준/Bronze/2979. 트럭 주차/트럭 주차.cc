// baekjoon 2979

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    int A, B, C;
    cin >> A >> B >> C;
    B += B;
    C += C + C;
    
    vector<int> parked(101, 0);
    for (int i = 0; i < 3; ++i) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < b; ++j)
            ++parked[j];
    }

    int ans = 0;
    for (auto e : parked) {
        // cout << e << ' ';
        switch (e) {
        case 1:
            ans += A;
            break;
        case 2:
            ans += B ;
            break;
        case 3:
            ans += C;
            break;
        default:
            break;
        }
    }
    cout << ans;
}