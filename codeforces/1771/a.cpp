#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;

  map<ll, ll> mp;
  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  sort(all(a));

  ll diff = a.back() - a.front();

  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    ans += mp[a[i] - diff];

    mp[a[i]]++;
  }
  cout << ans * 2 << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
