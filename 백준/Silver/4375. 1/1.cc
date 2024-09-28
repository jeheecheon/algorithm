// baekjoon 4375

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int n;
    while (cin >> n) {
        int cnt = 1;
        int base = 1;

        while (base % n != 0) {
            base = (base * 10 + 1) % n;
            ++cnt;
        }

        cout << cnt << endl;
    }
}