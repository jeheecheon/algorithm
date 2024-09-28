// baekjoon 2870

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using point = pair<int, int>;
using ll = long long;

vector<pair<int, int>> dirs = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

bool is_alpha(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<string> v;
    while (n--) {
        string str;
        cin >> str;

        while (str.length()) {
            if (is_alpha(str[0])) {
                str.erase(str.begin());
                continue;
            }

            auto it = str.begin();
            while (it != str.end() && !is_alpha(*it)) {
                ++it;
            }

            string tmp = str.substr(0, it - str.begin());
            while (tmp.length() >= 2) {
                if (tmp[0] != '0')
                    break;

                tmp.erase(tmp.begin());
            }
            v.push_back(tmp);
            str.erase(str.begin(), it);
        }
    }

    sort(v.begin(), v.end(), [](string& a, string& b) {
        if (a.length() == b.length()) {
            return a < b;
        }
        return a.length() < b.length();
    });

    for (auto e : v)
        cout << e << endl;
}