#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int N;
int arr1[1000001];
int arr2[1000001];
unordered_map<int, int> mymap;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr1[i];

    copy(&arr1[0], &arr1[N], &arr2[0]);
    sort(&arr2[0], &arr2[N]);

    int prev = 1000000003;
    int num = 0;
    for (int i = 0; i < N; ++i) {
        if (prev != arr2[i])
            mymap.insert({ arr2[i], num++ });
        prev = arr2[i];
    }

    for (int i = 0; i < N; ++i) {
        auto it = mymap.find(arr1[i]);
        cout << it->second << ' ';
    }
}
