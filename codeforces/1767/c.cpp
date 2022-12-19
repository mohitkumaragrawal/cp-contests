#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll n;
ll rist[105][105];
vector<pair<ll, ll>> vpr;

// vector<ll> a(n);

void solve() {
  cin >> n;

  vector<ll> b(n + 5), a(n + 5);
  ll tmp = 0;
  bool valid = true;

  for (ll i = 1; i <= n; ++i) {
    for (ll j = i; j <= n; ++j) {
      cin >> rist[i][j];
      if (rist[i][j] == 0) continue;

      if (rist[i][j] == 1) {
        if (b[i] == 0 && b[j] == 0) {
          ++tmp;
          for (ll x = i; x <= j; ++x) b[x] = tmp;
        } else {
          ll y = b[i];
          if (y == 0) y = b[j];

          for (ll x = i; x <= j; ++x) b[x] = y;
        }
      } else {
        if (j == i) valid = false;

        if (b[i] != 0 && b[j] != 0 && b[i] == b[j]) {
          valid = false;
        }

        vpr.push_back({i, j});
      }
    }
  }

  if (!valid) {
    cout << "0\n";
    return;
  }

  a[1] = 1;
  for (ll i = 2; i <= n; ++i) {
    if (b[i] != b[i - 1])
      a[i] = 1 + a[i - 1];
    else
      a[i] = a[i - 1];
  }

  ll sz = a[n];
  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= n; ++j) rist[i][j] = 0;
  }

  for (auto& pr : vpr) {
    pr.first = a[pr.first];
    pr.second = a[pr.second];

    rist[pr.first][pr.second] = 2;

    if (pr.second == pr.first) {
      valid = false;
    }
  }
  if (!valid) {
    cout << "0\n";
    return;
  }

  vector<ll> dp(sz + 1);
  dp[1] = 2;

  for (ll i = 1; i <= sz; ++i) {
    for (ll j = i + 1; j <= sz; ++j) {
      if (rist[i][j] != 2) {
        dp[j] += dp[i];
      }
    }
  }

  ll ans = 0;

  for (ll i = 1; i <= sz; ++i) ans += dp[i];
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
