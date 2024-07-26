#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int a, b, c;
    int i = 0;

    while (1) {
        i++;
        int sum = 0;
        cin >> a >> b >> c;
        if (a + b + c == 0)
            break;

        while (b < c) {
            c -= b;
            sum++;
        }
        sum *= a;

        if (c > a) {
            sum += a;
        } else {
            sum += c;
        }
        cout << "Case " << i << ": " << sum << endl;
    }
}