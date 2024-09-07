// baekjoon 2210

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;
using point = pair<int, int>;
using ll = long long;

#define X first
#define Y second

point dirs[4] {
    { 0, 1 },
    { 1, 0 },
    { -1, 0 },
    { 0, -1 }
};

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    char arr[5][5];
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> arr[i][j];

    unordered_set<string> s;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            queue<pair<point, string>> Q;
            Q.push({ { i, j }, string { arr[i][j] } });

            while (!Q.empty()) {
                auto [cur, word] = Q.front();
                Q.pop();

                if (word.length() == 6) {
                    s.insert(word);
                    continue;
                }

                for (auto [dx, dy] : dirs) {
                    auto [nx, ny] = pair { cur.X + dx, cur.Y + dy };

                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                        continue;
                    
                    Q.push({{nx, ny}, word + arr[nx][ny]});
                }
            }
        }
    }

    cout << s.size();
}