// baekjoon 3986

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    int ans = 0;
    while (n--) {
        string str;
        cin >> str;

        if (str.length() & 1)
            continue;

        stack<char> S;
        for (char ch : str) {
            if (S.empty()) {
                S.push(ch);
            } else {
                if (S.top() == ch) {
                    S.pop();
                } else {
                    S.push(ch);
                }
            }
        }

        if (S.empty())
            ++ans;
    }

    cout << ans;
}