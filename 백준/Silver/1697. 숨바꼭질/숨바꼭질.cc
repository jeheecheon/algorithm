// baekjoon 1697

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> arr(100001, -1);
    arr[N] = 0;
    
    queue<int> Q;
    Q.push(N);

    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();

        if (current == K)
            break;

        for (int nextPos : { current - 1, current + 1, current * 2 }) {
            if (nextPos < 0 || nextPos > 100000
                || arr[nextPos] >= 0)
                continue;

            arr[nextPos] = arr[current] + 1;
            Q.push(nextPos);
        }
    }

    cout << arr[K];
}