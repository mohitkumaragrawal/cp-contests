#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

void solve() {
  ll n, k;
  cin >> n >> k;

  ll L = 1, R = 50;

  for (ll i = 0; i < n; ++i) {
    ll l, r;
    cin >> l >> r;

    if (l <= k && r >= k) {
      L = max(L, l);
      R = min(R, r);
    }
  }

  if (L == R) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
