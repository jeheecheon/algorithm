#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    long long arr[n] = { 0 };
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    sort(&arr[0], &arr[n]);

    long long maxCnt = 0, curCnt = 0, curCompVal = arr[0], maxOccurencNum = arr[0];
    for (int i = 0; i < n; ++i) {
        if (curCompVal == arr[i]) {
            ++curCnt;
            if (curCnt > maxCnt) {
                maxCnt = curCnt;
                maxOccurencNum = curCompVal;
            }
        } else {
            if (i + 1 < n) {
                curCnt = 1;
                curCompVal = arr[i];
            }
        }
    }

    cout << maxOccurencNum;
}