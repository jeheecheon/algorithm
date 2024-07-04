#include <iostream>
#include <algorithm>

using namespace std;

char arr[2187][2187];

void solve(int x, int y, int n) {
    if (n == 1) {
        arr[x][y] = '*';
        return;
    }

    int nxt = n / 3;
    for (int i = x; i < x + n; i += nxt) {
        for (int j = y; j < y + n; j += nxt) {
            if (i == x + nxt && j == y + nxt)
                continue;
            solve(i, j, nxt);
        }
    }
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    fill(&arr[0][0], &arr[2186][2186], ' ');

    int n;
    cin >> n;

    solve(0, 0, n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << arr[i][j];
        cout << '\n';
    }
}