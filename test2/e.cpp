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

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  ll sum = accumulate(all(a), 0LL);
  ll mean = (sum + n / 2) / n;

  auto f = [&](ll d) {
    ll res = 0;

    ll x = mean + d;
    ll y = mean - d;

    for (ll i = 0; i < n; ++i) {
      ll val1 = (x - a[i]) * (x - a[i]);
      ll val2 = (y - a[i]) * (y - a[i]);
      res += min(val1, val2);
    }
    return res;
  };

  ll low = 0, high = 200001;
  ll ans = 0;

  while (high >= low) {
    ll mid = (low + high) / 2;
    if (f(mid) < f(mid + 1)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << f(ans) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
