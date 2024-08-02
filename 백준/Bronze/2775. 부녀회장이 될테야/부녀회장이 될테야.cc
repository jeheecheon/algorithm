#include <iostream>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int arr[15][15];
    for (int i = 0; i <= 14; ++i) 
        arr[0][i] = i;
    
    for (int i = 1; i <= 14; ++i) {
        int sum = 0;
        for (int j = 0; j <= 14; ++j) {
            sum += arr[i - 1][j];
            arr[i][j] = sum;
        }
    }

    int T, k, c;
    cin >> T;
    while (T--) {
        cin >> k >> c;
        cout << arr[k][c] << '\n';
    }
}