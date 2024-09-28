// baekjoon 1436

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string ans;
    for (int i = 666; n > 0;) {
        string str = to_string(i);
        if (str.find("666") != string::npos) {
            n--;
            ans = str;
        }
        ++i;
    }

    cout << ans;
}