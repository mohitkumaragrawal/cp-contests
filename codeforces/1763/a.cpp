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
  ll cnt[15];
  fill(cnt, cnt + 15, 0);

  for (ll i = 0; i < n; ++i) {
    cin >> a[i];

    for (ll j = 0; j < 15; ++j) {
      if ((a[i] >> j) & 1) {
        cnt[j]++;
      }
    }
  }

  ll M = 0, m = 0;
  for (ll j = 0; j < 15; ++j) {
    if (cnt[j] > 0) {
      M |= (1 << j);
    }

    if (cnt[j] >= n) {
      m |= (1 << j);
    }
  }
  cout << (M - m) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
