#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const ll INF = 1e18;

void solve() {
  ll n, k;
  cin >> n >> k;

  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INF));

  dp[0][0] = 0;

  vector<ll> a(n + 1);
  for (ll i = 1; i <= n; ++i) cin >> a[i];

  vector<ll> hot(k + 1), cold(k + 1);
  for (ll i = 1; i <= k; ++i) cin >> cold[i];
  for (ll i = 1; i <= k; ++i) cin >> hot[i];

  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < n; ++j) {
      if (dp[i][j] == INF) continue;

      ll mx = max(i, j);

      if (a[mx + 1] == a[i]) {
        dp[mx + 1][j] = min(dp[mx + 1][j], dp[i][j] + hot[a[mx + 1]]);
      } else {
        dp[mx + 1][j] = min(dp[mx + 1][j], dp[i][j] + cold[a[mx + 1]]);
      }
      if (a[mx + 1] == a[j]) {
        dp[i][mx + 1] = min(dp[i][mx + 1], dp[i][j] + hot[a[mx + 1]]);
      } else {
        dp[i][mx + 1] = min(dp[i][mx + 1], dp[i][j] + cold[a[mx + 1]]);
      }
    }
  }

  ll ans = INF;
  for (ll i = 0; i < n; ++i) {
    ans = min({ans, dp[i][n], dp[n][i]});
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
