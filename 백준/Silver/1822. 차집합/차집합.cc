#include <algorithm>
#include <iostream>

using namespace std;

int A[500000], B[500000], C[500000];
int ai, bi;

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
        if (!binary_search(&B[0], &B[bi], A[i]))
            C[cnt++] = A[i];

    cout << cnt << '\n';
    sort(&C[0], &C[cnt]);
    for (int i = 0; i < cnt; ++i)
        cout << C[i] << ' ';
}