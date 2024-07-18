#include <iostream>

using namespace std;

long long arr[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };
int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int T, N;
    cin >> T;
    for (int i = 6; i <= 100; ++i)
        arr[i] = arr[i - 5] + arr[i - 1];

    while (T--) {
        cin >> N;
        cout << arr[N] << '\n';
    }
}