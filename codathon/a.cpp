#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n;
  cin >> n;
  ll a[n];
  for (ll i = 0; i < n; ++i) cin >> a[i];

  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < n; ++j) {
      ll g = __gcd(a[i], a[j]);
      if (g <= 2) {
        cout << "YES\n";
        return;
      }
    }
  }

  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
