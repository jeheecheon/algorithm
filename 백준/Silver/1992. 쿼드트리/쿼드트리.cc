#include <iostream>

using namespace std;

int n;
int arr[64][64];

bool check(int x, int y, int s)
{
    int c = arr[x][y];
    for (int i = x; i < x + s; ++i)
        for (int j = y; j < y + s; ++j)
            if (arr[i][j] != c)
                return false;
    return true;
}

void solve(int x, int y, int s)
{
    if (check(x, y, s)) {
        cout << arr[x][y];
        return;
    }

    int t = s / 2;
    if (t < 1)
        return;

    cout << '(';
    for (int i = x; i < x + s; i += t) {
        for (int j = y; j < y + s; j += t) {
            solve(i, j, t);
        }
    }
    cout << ')';
}

int main(void)
{
    cin >> n;
    string tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        for (int j = 0; j < n; ++j) {
            arr[i][j] = tmp[j] - '0';
        }
    }

    solve(0, 0, n);
}