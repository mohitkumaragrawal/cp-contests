#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define OUT(T) cout << "Case #" << T << ": "
using ll = long long;
using ull = unsigned long long;

bool xset(ll num, ll idx) { return (num >> idx) & 1; }

void solve() {
  ll cnt = 0;
  for (ll i = 0; i < 16; ++i) {
    if (xset(i, 1) != xset(i, 2) && xset(i, 2) != xset(i, 3)) ++cnt;
  }
  cout << cnt << endl;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  // ll T;
  // cin >> T;
  // while (T--) solve();

  solve();
}
