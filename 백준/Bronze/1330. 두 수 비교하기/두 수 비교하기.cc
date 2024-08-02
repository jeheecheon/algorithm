#include <iostream>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int a, b;
    cin >> a >> b;

    if (a > b)
        cout << '>';
    else if (a < b)
        cout << '<';
    else {
        cout << "==";
    }
}
