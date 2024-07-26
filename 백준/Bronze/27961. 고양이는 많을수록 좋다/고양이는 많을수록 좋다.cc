#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    long long n;
    long long cur = 0;
    int count = 0;
    cin >> n;
    if(n == 0) {
        cout << count;
        return 0;
    }
    if( n == 1) {
        count = 1;
        cout << count;
        return 0;
    }
    if(n > 1) {
        cur = 1;
        count = 1;
        while(cur < n) {
            cur *= 2;
            count += 1;
        }
        
        cout << count;

    }
}