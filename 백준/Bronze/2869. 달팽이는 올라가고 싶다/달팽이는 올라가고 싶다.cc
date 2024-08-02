#include <iostream>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int a, b, v;
    cin >> a >> b >> v;

    int aa = a - b;
    int vv = v - b;
    cout << vv / aa + (vv % aa > 0 ? 1 : 0);
}