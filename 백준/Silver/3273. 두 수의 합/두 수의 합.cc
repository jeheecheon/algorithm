#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int num;
    cin >> num;

    sort(&arr[0], &arr[n]);

    int end = n - 1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= num) {
            end = i;
            break;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= end; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] + arr[j] == num)
                ++cnt;
            else if (arr[i] + arr[j] > num)
                break;
        }
    }

    cout << cnt;
}