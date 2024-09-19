// baekjoon 1706

#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <stdio.h>
#include <unordered_set>
#include <vector>

using namespace std;
using point = pair<int, int>;
using ll = long long;

#define X first
#define Y second

point dirs[4] {
    { 0, 1 },
    { 1, 0 },
    { -1, 0 },
    { 0, -1 }
};

int main()
{
    int R, C;
    cin >> R >> C;

    string board[R];
    for (int i = 0; i < R; ++i)
        cin >> board[i];

    string ans = "~";
    for (int i = 0; i < R; ++i) {
        string& row = board[i];
        stringstream ss(row);
        string str;

        while (getline(ss, str, '#')) {
            if (str.length() >= 2)
                ans = str < ans ? str : ans;
        }
    }

    for (int i = 0; i < C; ++i) {
        string col = "";
        for (int j = 0; j < R; ++j) {
            col += board[j][i];
        }

        stringstream ss(col);
        string str;

        while (getline(ss, str, '#')) {
            if (str.length() >= 2)
                ans = str < ans ? str : ans;
        }
    }

    cout << ans;
}