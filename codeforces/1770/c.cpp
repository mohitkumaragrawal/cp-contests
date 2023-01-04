#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using lld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

ll n;
vector<ll> a;

bool is_removable(ll p) {
  ll mp[p];
  memset(mp, 0, sizeof(mp));

  for (ll i = 0; i < n; ++i) {
    ll x = a[i] % p;
    mp[x]++;
  }

  for (ll i = 0; i < p; ++i) {
    if (mp[i] < 2) return true;
  }

  return false;
}

void solve() {
  cin >> n;
  a.resize(n);

  for (ll i = 0; i < n; ++i) cin >> a[i];

  map<ll, ll> mp;
  for (ll i = 0; i < n; ++i) {
    mp[a[i]]++;
  }

  for (auto [el, freq] : mp) {
    if (freq > 1) {
      cout << "NO\n";
      return;
    }
  }

  for (ll i = 2; i <= 100; ++i) {
    if (!is_removable(i)) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
