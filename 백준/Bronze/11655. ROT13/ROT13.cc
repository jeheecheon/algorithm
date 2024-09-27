// baekjoon 11655

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int isAlpha(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return 1;
    else if (ch >= 'A' && ch <= 'Z')
        return 2;
    return 0;
}

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    string str;
    getline(cin, str);

    for (int ch : str) {
        int res = isAlpha(ch);

        if (res) {
            ch += 13;
            if (res == 1) {
                if (ch > 'z') {
                    ch = ch % 'z' + 'a' - 1;
                }
            } else {
                if (ch > 'Z') {
                    ch = ch % 'Z' + 'A' - 1;
                }
            }
        }
        cout << (char)ch;
    }
}