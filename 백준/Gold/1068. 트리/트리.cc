// baekjoon 1068

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using point = pair<int, int>;
using ll = long long;

vector<pair<int, int>> dirs = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> adjs[n];
    unordered_map<int, int> parents;

    int root_node_idx;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        parents[i] = tmp;    
        if (tmp == -1) {
            root_node_idx = i;
            continue;
        }
        
        adjs[tmp].push_back(i);
    }

    int del;
    cin >> del;
    if (del == root_node_idx) {
        cout << 0;
        return 0;
    }
    int parent = parents[del];
    for (auto it = adjs[parent].begin(); it != adjs[parent].end(); ++it) {
        if (*it == del) {
            adjs[parent].erase(it);
            break;
        }
    }
    
    int ans = 0;

    queue<int> Q;
    Q.push(root_node_idx);
    vector<int> vis(n, 0);
    vis[root_node_idx] = true;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        if (adjs[cur].size() == 0)
            ++ans;
        for (int next : adjs[cur]) {
            if (vis[next])
                continue;
            
            Q.push(next);
            vis[next] = true;
        }
    }

    cout << ans;

}