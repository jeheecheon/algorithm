#include <iostream>

using namespace std;

int n;
int arr[128][128];
int ans[2];

bool check(int x, int y, int s) {
  int c = arr[x][y];
  for (int i = x; i < x + s; ++i)
    for (int j = y; j < y + s; ++j)
      if (arr[i][j] != c) return false;
  return true;
}

void solve(int x, int y, int s) {
  if (check(x, y, s)) {
    ++ans[arr[x][y]];
    return;
  }

  int t = s / 2;
  if (t < 1) return;

  for (int i = x; i < x + s; i += t) 
    for (int j = y; j < y + s; j += t) 
      solve(i, j, t);
}

int main(void) {
  cin >> n;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> arr[i][j];
  
  solve(0, 0, n);
  cout << ans[0] << '\n' << ans[1];
}