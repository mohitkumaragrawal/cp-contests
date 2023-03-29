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

  ll ans = 0;

  ll singles = 0;
  ll paired = 0, unpaired = 0;

  for (ll i = 0; i < n; ++i) {
    if (a[i] == 1) {
      unpaired++;
    } else {
      ll x = (unpaired / 2);
      ll y = (unpaired + 1) / 2;

      if (x % 2 == 1) {
        singles++;
        x--;
      }

      if (y % 2 == 1) {
        singles++;
        y--;
      }

      paired += (x / 2) + (y / 2);
      if (singles > 2) {
        ll ns = 0;
        x = (singles / 2);
        y = (singles + 1) / 2;

        if (x % 2 == 1) {
          ns++;
          x--;
        }

        if (y % 2 == 1) {
          ns++;
          y--;
        }

        paired += (x / 2) + (y / 2);
        singles = ns;
      }

      unpaired = 0;
    }

    ans = max(ans, paired + unpaired + singles);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
