// baekjoon 10709

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

    int H, W;
    cin >> H >> W;

    string board[H];
    for (int i = 0; i < H; ++i)
        cin >> board[i];

    for (auto& str : board) {
        bool flag = false;
        int cnt = 0;
        for (auto ch : str) {
            if (ch == 'c') {
                cout << "0 ";
                flag = true;
                cnt = 1;
            }
            else {
                if (flag) {
                    cout << cnt++ << ' ';
                } else {
                    cout << "-1 ";
                }
            }
        }
        cout << endl;
    }
}