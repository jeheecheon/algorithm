// baekjoon 2097

#include <cmath>
#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    if (n <= 4) {
        cout << 4;
        return 0;
    }

    int w = sqrt(n) > floor(sqrt(n)) ? floor(sqrt(n)) + 1 : floor(sqrt(n));
    int h = round(sqrt(n));
    cout << ((w - 1) + (h - 1)) * 2;

    return 0;
}