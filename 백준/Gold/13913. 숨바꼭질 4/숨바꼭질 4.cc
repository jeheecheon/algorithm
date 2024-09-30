// baekjoon 13913

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    if (N == M) {
        cout << 0 << endl
             << N;
        return 0;
    }

    vector<int> dist(100001, -1), parents(100001, -1);
    dist[N] = 0;

    queue<int> Q;
    Q.push(N);

    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();

        for (int nx : { x + 1, x - 1, x * 2 }) {
            if (nx < 0 || nx > 100000)
                continue;

            if (dist[nx] >= 0)
                continue;

            dist[nx] = dist[x] + 1;
            Q.push(nx);
            parents[nx] = x;

            if (nx == M) {
                cout << dist[nx] << endl;

                stack<int> paths;
                for (int i = nx; i != -1; i = parents[i])
                    paths.push(i);

                while (!paths.empty()) {
                    cout << paths.top() << ' ';
                    paths.pop();
                }

                return 0;
            }
        }
    }
}
