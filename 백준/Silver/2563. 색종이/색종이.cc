#include <iostream>

using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    bool isUsed[101][101] = {false};
    for (int i = 0; i < N; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        for (int j = tmp1; j < tmp1 + 10; ++j) 
            for (int k = tmp2; k < tmp2 + 10; ++k) 
                isUsed[j][k] = true;
    }

    int ans = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (isUsed[i][j])
                ++ans;
        }
    }
    cout << ans;
}