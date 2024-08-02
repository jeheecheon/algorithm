#include <iostream>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int a;
    cin >> a;

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << '*';
        }
        cout << '\n';
    }
}
