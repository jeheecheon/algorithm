#define MAX 1000000007

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;
vector<int> G[100001];
int table[100001][17];
int level[100001];

void mydfs(int cur, int par, int lv) {
	level[cur] = lv;
	for (auto& node : G[cur]) {
		if (node == par) continue;
		mydfs(node, cur, lv + 1);
	}
}
void tableinit() {
	for (int k = 1; k < 17; k++) {
		for (int i = 1; i <= N; i++) {
			table[i][k] = table[table[i][k - 1]][k - 1];
		}
	}
}
int dist(int u, int v) {
	int ret = 0;
	if (level[u] < level[v]) swap(u, v);
	int tmp = level[u] - level[v];
	int idx = 0;
	while (tmp) {
		if (tmp & 1) {
			ret += (1 << idx);
			u = table[u][idx];
		}
		tmp >>= 1;
		idx++;
	}
	if (u == v) return ret;
	for (int k = 16; k > -1; k--) {
		if (table[u][k] == table[v][k]) continue;
		ret += (1 << k);
		ret += (1 << k);
		u = table[u][k], v = table[v][k];
	}
	return ret + 2;
}

bool visited[100001];
int childcnt[100001];
int centroidparent[100001];
int dfs2(int cur, int par) {
	int ret = 1;
	for (auto& node : G[cur]) {
		if (node == par || visited[node]) continue;
		ret += dfs2(node, cur);
	}
	return childcnt[cur] = ret;
}
int centroid(int cur, int par, int K) {
	for (auto& node : G[cur]) {
		if (node == par || visited[node]) continue;
		if (childcnt[node] > K) return centroid(node, cur, K);
	}
	return cur;
}
void centroid_decomposition(int cur, int par) {
	dfs2(cur, 0);
	cur = centroid(cur, -1, childcnt[cur] / 2);
	centroidparent[cur] = par;

	visited[cur] = 1;
	for (auto& node : G[cur]) {
		if (visited[node]) continue;
		centroid_decomposition(node, cur);
	}
}

int dp[100001];
void upd(int old) {
	int cur = old;
	while (cur) {
		dp[cur] = min(dp[cur], dist(cur, old));
		int par = centroidparent[cur];
		cur = par;
	}
}

void qry(int old) {
	int ret = MAX;
	int cur = old;
	while (cur) {
		ret = min(ret, dp[cur] + dist(old, cur));
		int par = centroidparent[cur];
		cur = par;
	}

	if (ret == MAX) cout << -1 << '\n';
	else cout << ret << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	for (int u = 2; u <= N; u++) {
		int v; cin >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
		table[u][0] = v;
	}
	tableinit();
	mydfs(1, 0, 1);

	centroid_decomposition(1, 0);

	for (int i = 1; i <= N; i++) dp[i] = MAX;

	while (Q--) {
		int q, x; cin >> q >> x;
		if (q == 1) upd(x);
		else qry(x);
	}
}