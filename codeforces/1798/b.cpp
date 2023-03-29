#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll m;
  cin >> m;

  vector<vector<ll>> a(m);
  for (ll i = 0; i < m; ++i) {
    ll n;
    cin >> n;

    a[i].resize(n);
    for (ll j = 0; j < n; ++j) cin >> a[i][j];
  }

  vector<ll> ans(m);
  map<ll, bool> vis;

  for (ll i = m - 1; i >= 0; --i) {
    bool flag = false;

    for (ll j = 0; j < a[i].size(); ++j) {
      if (!vis[a[i][j]]) {
        if (!flag) {
          flag = true;
          ans[i] = a[i][j];
        }

        vis[a[i][j]] = true;
      }
    }

    if (!flag) {
      cout << -1 << endl;
      return;
    }
  }

  for (ll i = 0; i < m; ++i) cout << ans[i] << " ";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
