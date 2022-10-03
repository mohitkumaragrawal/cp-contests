#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;

    vector<int> p(n, -1);
    vector<vector<int>> tree(n);

    for (int i = 1; i < n; ++i) {
      cin >> p[i];
      p[i] -= 1;

      tree[p[i]].push_back(i);
    }

    vector<int> d(n);

    function<void(int)> dfs = [&](int u) {
      for (int v : tree[u]) {
        d[v] = d[u] + 1;
        dfs(v);
      }
    };
    dfs(0);

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int u, int v) { return d[u] > d[v]; });

    int l = 1, r = n, ans = -1;
    while (l <= r) {
      int m = (l + r) / 2;
      vector<bool> taken(n);
      int cnt = 0;

      function<void(int)> dfs2 = [&](int n) {
        if (taken[n]) return;
        taken[n] = true;
        for (int child : tree[n]) dfs2(child);
      };

      for (int i : order) {
        if (d[i] <= m) break;

        if (taken[i]) continue;

        for (int j = 0; j + 1 < m; ++j) {
          i = p[i];
        }
        dfs2(i);
        cnt += 1;
      }

      if (cnt <= k) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    cout << ans << endl;
  }
}