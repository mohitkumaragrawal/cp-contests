#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(all(a));

  if (a[n - 1] == a[0]) {
    // all same;
    cout << n / 2 << endl;
    return;
  }

  map<ll, ll> left, right;
  ll total_left = 0, total_right = 0;

  for (ll i = 0; i < n; ++i) {
    ll el = a[i];
    ll l = lower_bound(all(a), el) - a.begin();
    ll r = n - (upper_bound(all(a), el) - a.begin());

    if (l >= r) {
      left[a[i]]++;
      total_left++;
    } else {
      right[a[i]]++;
      total_right++;
    }
  }

  ll ans = total_left * total_right;

  for (auto [x, y] : left) {
    ans -= y * right[x];
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
