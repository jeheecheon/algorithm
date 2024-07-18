#include <iostream>
#include <algorithm>

#define SQ(a) ((a) * (a))

using namespace std;

int main(void)
{
    while (1) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        if (!a[0] && !a[1] && !a[2])
            break;

        sort(&a[0], &a[3]);
        cout << (SQ(a[2]) == SQ(a[0]) + SQ(a[1]) ? "right" : "wrong") << '\n';
    }
}