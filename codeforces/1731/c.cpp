#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

unordered_map<ll, bool> is_sq;
vector<ll> squares;
ll a[200005], pre[200005];

void solve() {
  ll n;
  cin >> n;

  for (ll i = 0; i < n; ++i) cin >> a[i];

  pre[0] = a[0];
  for (ll i = 1; i < n; ++i) pre[i] = pre[i - 1] ^ a[i];

  // unordered_map<ll, ll> mp;
  //
  int mp[300005];
  memset(mp, 0, sizeof(mp));

  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    ll xr = pre[i];
    if (is_sq[xr]) ans++;

    for (auto sq : squares) {
      ll req = sq ^ xr;
      if (req > 300000) continue;
      ans += mp[req];
    }

    mp[pre[i]]++;
  }

  ans = ((long long)(n * (n + 1)) / 2) - ans;

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  for (ll i = 0; i * i <= 200000; ++i) {
    squares.push_back(i * i);
    is_sq[i * i] = true;
  }

  ll T;
  cin >> T;
  while (T--) solve();
}
