#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int a, b;
    cin >> a >> b;
    cout << fixed << setprecision(9) << (a / (double)b) << endl;
}
