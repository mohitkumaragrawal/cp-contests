#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

void solve() {
  ll x[3], y[3];
  for (ll i = 0; i < 3; ++i) cin >> x[i] >> y[i];

  bool vert = false, horz = false;

  for (ll i = 0; i < 3; ++i) {
    for (ll j = 0; j < 3; ++j) {
      if (i == j) continue;

      if (x[i] == x[j]) vert = true;
      if (y[i] == y[j]) horz = true;
    }
  }

  if (vert && horz) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  ll T;
  cin >> T;
  while (T--) solve();
}
