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

  map<ll, ll> mp;
  for (auto x : a) mp[x]++;

  ll singles = 0, doubles = 0;

  for (auto [el, f] : mp) {
    if (f % 2 == 1)
      singles++;
    else
      doubles++;
  }

  ll pairs = doubles / 2;
  singles += 2 * pairs;

  cout << singles << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
