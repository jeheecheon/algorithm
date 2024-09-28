// baekjoon 3474

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    while (cin >> n) {
        int five = 0, two = 0;

        for (int i = 2; i <= n; i *= 2)
            two += n / i;

        for (int i = 5; i <= n; i *= 5)
            five += n / i;

        cout << min(five, two) << endl;
    }
}