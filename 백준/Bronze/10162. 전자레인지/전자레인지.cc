#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    cin >> n;
    if(n % 10 != 0) {
        cout << -1;
        return 0;
    }
    while(n >= 300) {
        n -= 300;
        count1 += 1;
    }
    while(n >= 60) {
        n -= 60;
        count2 += 1;
    }
    while(n >= 10) {
        n -= 10;
        count3 += 1;
    }
    cout << count1 << " " << count2 << " " << count3;
}