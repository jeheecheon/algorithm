// baekjoon 1268

#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    int table[n + 1][5];
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> table[i][j];

    pair<int, int> inssa = { -1, -1 };
    for (int i = 1; i <= n; ++i) {
        bool is_friends[n + 1] = { false };
        int friends_num = 0;

        for (int j = 0; j < 5; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (k == i)
                    continue;

                if (table[i][j] == table[k][j] && !is_friends[k]) {
                    is_friends[k] = true;
                    ++friends_num;
                }
            }
        }

        if (friends_num > inssa.second)
            inssa = pair { i, friends_num };
    }

    cout << inssa.first;
}