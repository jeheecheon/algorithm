#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dirs[7] = { 1, 2, 3, 4, 5, 6 };
int N, M;

int main(void)
{
    cin >> N >> M;

    int arr[101] = { 0 };
    for (int i = 0; i < N + M; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        arr[tmp1] = tmp2;
    }

    vector<int> dist(101, -1);
    dist[1] = 0;
    queue<int> Q;
    Q.push(1);

    while (!Q.empty()) {
        int curPos = Q.front();
        Q.pop();
        
        if (curPos == 100) {
            cout << dist[100];
            return 0;
        }

        for (int offset : dirs) {
            int nextPos = offset + curPos;
            if (nextPos > 100 || dist[nextPos] != -1 || dist[arr[nextPos]] != -1) 
                continue;
            
            if (arr[nextPos] != 0)
                nextPos = arr[nextPos];
            
            dist[nextPos] = dist[curPos] + 1;
            Q.push(nextPos);
        }
    }
}