// baekjoon 9996

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    string str;
    cin >> str;

    int cur = str.find("*");
    string pre = str.substr(0, cur);
    string suf = str.substr(cur + 1);

    while (n--) {
        cin >> str;
        if (pre.length() + suf.length() > str.length()) {
            cout << "NE" << endl;
        } else {
            if (pre == str.substr(0, pre.size()) && suf == str.substr(str.size() - suf.size()))
                cout << "DA" << endl;
            else {
                cout << "NE" << endl;
            }
        }
    }
}