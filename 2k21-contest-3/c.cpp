#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

vector<vector<bool>> vis;
vector<string> grid;
ll n;

bool valid(int x, int y) {
  if (x >= 0 && y >= 0 && x < n && y < n) {
    return grid[x][y] == '1';
  }
  return false;
}

void dfs(ll row, ll col) {
  if (vis[row][col]) return;
  vis[row][col] = true;

  if (valid(row - 1, col)) {
    dfs(row - 1, col);
  }

  if (valid(row, col - 1)) {
    dfs(row, col - 1);
  }
}

void solve() {
  vis.clear();
  grid.clear();

  cin >> n;

  grid.resize(n);
  vis.assign(n, vector<bool>(n, false));

  for (ll i = 0; i < n; ++i) cin >> grid[i];

  for (ll i = 0; i < n; ++i) {
    if (valid(n - 1, i)) dfs(n - 1, i);
    if (valid(i, n - 1)) dfs(i, n - 1);
  }

  bool pos = true;

  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < n; ++j) {
      if (grid[i][j] == '1' && !vis[i][j]) {
        pos = false;
        goto negative;
      }
    }
  }

negative:

  if (pos) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
