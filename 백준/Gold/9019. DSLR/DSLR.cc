#include <iostream>
#include <queue>

using namespace std;
int N, initVal, target;

void solve()
{
    cin >> initVal >> target;
    queue<pair<int, string>> Q;
    Q.push({initVal, ""});
    bool vis[10000] = {false};
    vis[initVal] = true;
    while (!Q.empty())
    {
        auto [curVal, ans] = Q.front();
        Q.pop();

        if (curVal == target) {
            cout << ans << '\n';
            break;
        }

        int d = curVal * 2 % 10000;
        int s = (curVal > 0 ? curVal - 1 : 9999);
        int l = (curVal % 1000) * 10 + (curVal / 1000);
        int r = (curVal % 10) * 1000 + (curVal / 10);

        if (!vis[d])
        {
            vis[d] = true;
            Q.push({d, ans + 'D'});
        }
        if (!vis[s])
        {
            vis[s] = true;
            Q.push({s, ans + 'S'});
        }
        if (!vis[l])
        {
            vis[l] = true;
            Q.push({l, ans + 'L'});
        }
        if (!vis[r])
        {
            vis[r] = true;
            Q.push({r, ans + 'R'});
        }
    }
}

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    cin >> N;
    while (N--)
        solve();
}