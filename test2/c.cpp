#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll count_inv(vector<ll>& v) {
  if (v.empty()) return 0;

  ll ans = 0;
  ll ones = 0;

  for (auto x : v) {
    if (x == 1) {
      ones++;
    } else {
      ans += ones;
    }
  }
  return ans;
}

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<string> grid(n);
  for (ll i = 0; i < n; ++i) cin >> grid[i];

  ll ans = 0;

  for (ll i = 0; i < n; ++i) {
    vector<ll> a;
    for (ll j = 0; j < m; ++j) {
      if (grid[i][j] == 'U' || grid[i][j] == 'D') {
        ans += count_inv(a);
        a.clear();
      } else {
        a.push_back((grid[i][j] == 'R') ? 1 : 0);
      }
    }

    ans += count_inv(a);
  }

  for (ll j = 0; j < m; ++j) {
    vector<ll> a;
    for (ll i = 0; i < n; ++i) {
      if (grid[i][j] == 'L' || grid[i][j] == 'R') {
        ans += count_inv(a);
        a.clear();
      } else {
        a.push_back((grid[i][j] == 'D') ? 1 : 0);
      }
    }
    ans += count_inv(a);
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
