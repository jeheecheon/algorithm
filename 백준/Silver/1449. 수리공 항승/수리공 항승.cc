// baekjoon 1449

#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;

    int repairs[N];
    for (int i = 0; i < N; ++i)
        cin >> repairs[i];
    sort(repairs, repairs + N);

    int tapeCnt = 0;
    bool arr[1001] = { 0 };

    for (int i = 0; i < N; ++i) {
        if (!arr[repairs[i]]) {
            ++tapeCnt;
            for (int j = repairs[i]; j < repairs[i] + L && j <= 1000; ++j) {
                if (!arr[j])
                    arr[j] = true;
            }
        }
    }

    cout << tapeCnt;
}