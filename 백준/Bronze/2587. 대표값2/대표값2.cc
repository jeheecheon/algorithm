#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    int arr[5];
    int a;
    for(int i = 0;i < 5;i++) {
        cin >> arr[i];
    }
    sort(&arr[0], &arr[5]);
    for(int i = 0; i < 5; i++) {
        a +=arr[i];
    }
    a = a/5;
    cout << a << endl << arr[2];
}