// baekjoon 9012

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using point = pair<int, int>;
using ll = long long;

vector<pair<int, int>> dirs = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        stack<char> S;
        bool pos = true;
        for (char ch : str) {
            if (ch == '(') {
                S.push(ch);
            } else {
                if (S.empty()) {
                    pos = false;
                    break;
                } else {
                    S.pop();
                }
            }
        }

        if (S.size())
            pos = false;
        
        cout << (pos ? "YES" : "NO") << endl;
    }
}