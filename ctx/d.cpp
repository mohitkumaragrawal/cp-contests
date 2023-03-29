#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;

ll pow2[1000006];
void init_pow2() {
  pow2[0] = 1;
  for (ll i = 1; i < 1000006; ++i) pow2[i] = (pow2[i - 1] * 2) % MOD;
}

ll a[1000006];

void solve() {
  ll n;
  cin >> n;

  for (ll i = 0; i < n; ++i) cin >> a[i];

  ll ans = 0;

  for (ll i = 0; i < n; ++i) {
    ll f = (pow2[i + 1] + pow2[i] - 1) % MOD;
    f = (f * pow2[n - 1 - i]) % MOD;
    f = (f + MOD - pow2[i]) % MOD;

    ans += (f * a[i]) % MOD;
    ans %= MOD;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  init_pow2();

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
