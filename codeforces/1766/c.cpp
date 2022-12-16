#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll m;
string grid[2];

bool solve1() {
  vector<vector<bool>> vis(2, vector<bool>(m, false));

  int col = 0;
  int row = 0;
  if (grid[row][col] == 'W') row++;

  vis[row][col] = true;

  while (col < m - 1) {
    int opposite_row = 1 - row;
    bool can_go_verticle = false;

    if (grid[opposite_row][col] == 'B' && !vis[opposite_row][col])
      can_go_verticle = true;

    if (can_go_verticle) {
      vis[opposite_row][col] = true;
      row = opposite_row;

      continue;
    }

    if (grid[row][col + 1] == 'B') {
      vis[row][col + 1] = true;
      col++;
      continue;
    }

    return false;
  }

  return true;
}

bool solve2() {
  vector<vector<bool>> vis(2, vector<bool>(m, false));

  int col = 0;
  int row = 1;
  if (grid[row][col] == 'W') row--;

  vis[row][col] = true;

  while (col < m - 1) {
    int opposite_row = 1 - row;
    bool can_go_verticle = false;

    if (grid[opposite_row][col] == 'B' && !vis[opposite_row][col])
      can_go_verticle = true;

    if (can_go_verticle) {
      vis[opposite_row][col] = true;
      row = opposite_row;

      continue;
    }

    if (grid[row][col + 1] == 'B') {
      vis[row][col + 1] = true;
      col++;
      continue;
    }

    return false;
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) {
    cin >> m;
    cin >> grid[0] >> grid[1];

    bool res = solve1();
    res |= solve2();

    if (res) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
