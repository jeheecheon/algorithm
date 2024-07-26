#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    sort(&arr[0], &arr[N]);

    int sum = 0;
    for (int i = 0; i < N; ++i)
        sum += arr[i];

    for (int i = 0; i < N && sum % 2 == 1; ++i) {
        if (arr[i] % 2 == 1)
            sum -= arr[i];
    }

    cout << sum;
}