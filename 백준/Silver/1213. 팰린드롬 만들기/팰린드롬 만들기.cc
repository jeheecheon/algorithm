// baekjoon 1213

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    string str;
    cin >> str;

    vector<int> cnts(26, 0);
    for (char ch : str)
        ++cnts[ch - 'A'];

    char mid = 0;
    int flag = 0;
    string ans = "";
    
    for (int i = 25; i >= 0; --i) {
        if (cnts[i] & 1) {
            mid = char(i + 'A');
            ++flag;
            --cnts[i];
        }
        if (flag == 2)
            break;

        for (int j = 0; j < cnts[i]; j += 2) {
            ans = char(i + 'A') + ans;
            ans += char(i + 'A');
        }
    }

    if (flag == 2)
        cout << "I'm Sorry Hansoo";
    else {
        if (mid)
            ans.insert(ans.begin() + ans.length() / 2, mid);

        cout << ans;
    }
}