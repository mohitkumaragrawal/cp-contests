#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;

ll X[1000006], G[1000006], dp[1000006];
ll n;
ll a[1000006];

void solve() {
  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  X[1] = a[1];
  for (ll i = 2; i <= n; ++i) {
    X[i] = (i * a[i] + X[i - 1]) % MOD;
  }

  G[1] = a[1];
  for (ll i = 1; i < n; ++i) {
    ll f = (((i + 1) * (i + 2)) / 2) % MOD;
    G[i + 1] = (f * a[i + 1]) % MOD + X[i] + G[i];
    G[i + 1] %= MOD;
  }

  dp[1] = a[1];
  ll dp_sum = dp[1] % MOD;
  for (ll i = 2; i <= n; ++i) {
    dp[i] = (dp_sum + G[i]) % MOD;

    dp_sum += dp[i];
    dp_sum %= MOD;
  }

  for (ll i = 1; i <= n; ++i) {
    cout << dp[i] << " ";
  }
  cout << endl;

  ll ans = dp[n];
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
