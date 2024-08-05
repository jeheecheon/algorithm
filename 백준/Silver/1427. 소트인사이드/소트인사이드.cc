// boj 1427

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    string str;
    cin >> str;
    sort(str.begin(), str.end(), greater<>());
    cout << str;
}