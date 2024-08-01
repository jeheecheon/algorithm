#include <iostream>

using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    
    int N, M;
    cin >> N >> M;
    int arr[N + 1];
    int acc[N + 1];
    arr[0] = 0;
    acc[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        acc[i] = arr[i] + acc[i - 1];
    }

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        cout << acc[b] - acc[a - 1] << '\n';
    }
}