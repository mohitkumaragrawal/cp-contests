#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;

  ll a[m];
  for (ll i = 0; i < m; ++i) cin >> a[i];

  ll seg = n / k;
  ll last_seg = n - (k * seg);
  bool has_last = (last_seg != 0);
  ll cnt = 0;

  sort(a, a + m, greater<ll>());

  for (ll i = 0; i < m; ++i) {
    if (a[i] <= seg) {
      a[i] = 0;
    } else {
      if (has_last && a[i] == seg + 1) {
        cnt++;
      } else {
        cout << "NO\n";
        return;
      }
    }
  }

  if (cnt <= last_seg) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
