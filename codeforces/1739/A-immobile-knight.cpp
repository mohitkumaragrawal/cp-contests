#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> steps = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> mat(n + 1, vector<bool>(m + 1, false));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (auto step : steps) {
        int x = i + step.first;
        int y = j + step.second;

        if (x < 1 || y < 1 || x > n || y > m) continue;

        mat[x][y] = mat[i][j] = true;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!mat[i][j]) {
        cout << i << " " << j << endl;
        return;
      }
    }
  }

  cout << 1 << " " << 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}