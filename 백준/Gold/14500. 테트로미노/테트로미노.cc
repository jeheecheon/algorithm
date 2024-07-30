#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> tet1 = {
    { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } },
    { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } }
};
vector<vector<pair<int, int>>> tet2 = {
    { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } }
};
vector<vector<pair<int, int>>> tet3 = {
    { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 2, 1 } },
    { { 0, 0 }, { 0, 1 }, { 0, 2 }, { -1, 2 } },
    { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 } },
    { { 0, 0 }, { 1, 0 }, { 0, 1 }, { 0, 2 } },

    { { 0, -0 }, { 1, -0 }, { 2, -0 }, { 2, -1 } },
    { { 0, -0 }, { 0, -1 }, { 0, -2 }, { -1, -2 } },
    { { 0, -0 }, { 0, -1 }, { 1, -1 }, { 2, -1 } },
    { { 0, -0 }, { 1, -0 }, { 0, -1 }, { 0, -2 } },
};
vector<vector<pair<int, int>>> tet4 = {
    { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 1 } },
    { { 0, 0 }, { 0, 1 }, { -1, 1 }, { -1, 2 } },

    { { 0, -0 }, { 1, -0 }, { 1, -1 }, { 2, -1 } },
    { { 0, -0 }, { 0, -1 }, { -1, -1 }, { -1, -2 } },
};
vector<vector<pair<int, int>>> tet5 = {
    { { 0, 0 }, { 0, 1 }, { 0, 2 }, { -1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 0 } },
    { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, -1 }, { 2, 0 } },
};

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    int N, M;

    cin >> N >> M;
    int board[N][M];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    vector<vector<vector<pair<int, int>>>> tets = { tet1, tet2, tet3, tet4, tet5 };
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (auto& tet : tets) {
                for (auto& nextTet : tet) {
                    vector<pair<int, int>> tetPos(4);

                    bool placeable = true;
                    for (int k = 0; k < 4; ++k) {
                        tetPos[k].first = nextTet[k].first + i;
                        tetPos[k].second = nextTet[k].second + j;

                        if (tetPos[k].first < 0 || tetPos[k].first >= N
                            || tetPos[k].second < 0 || tetPos[k].second >= M) {
                            placeable = false;
                            break;
                        }
                    }
                    if (!placeable)
                        continue;

                    int sum = 0;
                    for (auto pos : tetPos)
                        sum += board[pos.first][pos.second];
                    ans = max(ans, sum);
                }
            }
        }
    }
    
    cout << ans;
}