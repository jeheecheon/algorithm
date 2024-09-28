// baekjoon 3986

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

ll A, B, C;

ll func(ll b) {
    if (b == 1)
        return A % C;
    
    ll tmp = func(b / 2) % C;
    tmp = (tmp * tmp) % C;

    if (b & 1)
        tmp = (tmp * A) % C;

    return tmp;
}

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> A >> B >> C;

    cout << func(B);
}