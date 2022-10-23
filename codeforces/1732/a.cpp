
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n+1);
  for (ll i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  ll g = a[1];
  for (ll i = 2; i <= n; ++i) g = __gcd(g, a[i]);

  if (g == 1) {
    cout << 0 << endl;
    return;
  }

  ll ans = n;
  for (ll i = n; i >= 0; --i) {
    if (__gcd(i, g) == 1) {
      ans = min(ans, n - i + 1);
    }
  }

  if (ans > 3) ans = 3;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) solve();
}
