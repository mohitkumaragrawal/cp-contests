#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n;
  cin >> n;

  ll odd_count = 0;

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] & 1) {
      odd_count++;
    }
  }
  if (odd_count % 2 == 0) {
    cout << "0\n";
    return;
  }

  ll ans = 99999999;
  for (ll i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      if (a[i] != 0) {
        ll m = 0;
        while (a[i] % 2 == 0) {
          a[i] /= 2;
          m++;
        }
        ans = min(ans, m);
      }
    } else {
      ll m = 0;
      while (a[i] % 2 != 0) {
        a[i] /= 2;
        m++;
      }
      ans = min(ans, m);
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
