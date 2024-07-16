#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int N, M;

unordered_set<int> rel[101];

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rel[a].insert(b);
        rel[b].insert(a);
    }

    int mini = 0x7fffff;
    int bacon = -1;
    for (int i = 1; i <= N; ++i) {
        int dist[N + 1] = { 0 };
        fill(dist, dist + N + 1, -1);

        queue<int> Q;
        Q.push(i);
        dist[i] = 0;

        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();

            for (auto nxt : rel[cur]) {
                if (dist[nxt] != -1)
                    continue;
                
                Q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }
        
        int sum = 0;
        for (int j = 1; j <= N; ++j)
            sum += dist[j];
        if (sum < mini) {
            mini = sum;
            bacon = i;
        }
    }

    cout << bacon;
}
