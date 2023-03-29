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

  vector<ll> a(n), b(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];
  for (ll i = 0; i < n; ++i) cin >> b[i];

  ll x = a[n - 1], y = b[n - 1];

  bool ok = true;
  for (ll i = 0; i < n - 1; ++i) {
    if (a[i] <= x && b[i] <= y) {
    } else if (a[i] <= y && b[i] <= x) {
    } else {
      ok = false;
    }
  }
  if (!ok) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
