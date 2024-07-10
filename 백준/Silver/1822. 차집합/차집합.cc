#include <algorithm>
#include <iostream>

using namespace std;

int A[500000], B[500000], C[500000];
int ai, bi;

bool solve(int valToFind)
{
    int st = 0;
    int en = bi - 1;

    while (st <= en) {
        int mid = (st + en) / 2;

        if (B[mid] == valToFind)
            return true;

        else if (B[mid] < valToFind) {
            st = mid + 1;
        } else {
            en = mid - 1;
        }
    }

    return false;
}

int main(void)
{
    cin >> ai >> bi;

    for (int i = 0; i < ai; ++i)
        cin >> A[i];

    for (int i = 0; i < bi; ++i)
        cin >> B[i];

    sort(&B[0], &B[bi]);

    int cnt = 0;
    for (int i = 0; i < ai; ++i)
        if (!solve(A[i]))
            C[cnt++] = A[i];

    cout << cnt << '\n';
    sort(&C[0], &C[cnt]);
    for (int i = 0; i < cnt; ++i)
        cout << C[i] << ' ';
}