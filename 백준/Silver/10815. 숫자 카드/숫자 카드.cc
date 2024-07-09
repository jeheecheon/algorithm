#include <iostream>
#include <algorithm>

using namespace std;

int n, m, num;
int arr[500000];

bool solve()
{
    int st = 0;
    int en = n - 1;

    while (st <= en)
    {
        int mid = (en + st) / 2;

        if (arr[mid] == num)
            return true;
        else if (arr[mid] < num)
            st = mid + 1;
        else
            en = mid - 1;
    }
    return false;
}

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(&arr[0], &arr[n]);

    cin >> m;
    while (m--)
    {
        cin >> num;
        cout << solve() << ' ';
    }
}