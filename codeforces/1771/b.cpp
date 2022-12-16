#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

ll dp[100005];

void solve() {
  ll n, m;
  cin >> n >> m;

  map<ll, ll> mp;
  for (ll i = 0; i < m; ++i) {
    ll x, y;
    cin >> x >> y;

    if (x > y) swap(x, y);
    mp[y] = max(mp[y], x);
  }

  ll ans = 1;
  ll mx = 0;
  for (ll i = 2; i <= n; ++i) {
    ll k = mp[i];
    mx = max(mx, k);

    ans += (i - mx);
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
