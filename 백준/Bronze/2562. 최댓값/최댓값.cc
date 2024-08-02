#include <iostream>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int maxi = 0;
    int tmp;
    int idx;
    for (int i = 0; i < 9; ++i) {
        cin >> tmp;
        if (tmp > maxi) {
            maxi = tmp;
            idx = i + 1;
        }
    }
    cout << maxi << '\n'
         << idx;
}
