#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(&arr[0], &arr[n]);
    for(int j = 0; j < n; j++) {
        cout << arr[j] << endl;
    }
}